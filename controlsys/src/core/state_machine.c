#include "controlsys/state_machine.h"
#include "controlsys/tx.h"
#include "controlsys/events.h"
#include "controlsys/event_channel.h"
#include "controlsys/log.h"
#include "controlsys/services/card_verifier.h"
#include "controlsys/services/status_verifier.h"
#include "controlsys/services/auth_module.h"
#include "controlsys/services/journal.h"
#include "controlsys/services/txn_builder.h"
#include "controlsys/services/update_loader.h"
#include "controlsys/services/update_storage.h"
#include "controlsys/services/update_verifier.h"
#include "controlsys/services/update_installer.h"

static void handle_event(TxContext* ctx, const CtlEvent* evt) {
    switch (evt->type) {
    case CTL_EVENT_HEARTBEAT:
        status_update_network(evt->network_ok);
        status_update_power(evt->power_ok);
        break;
    case CTL_EVENT_SET_AMOUNT:
        if (!status_can_start_tx()) {
            break;
        }
        tx_start(ctx, evt->amount_cents, evt->currency ? evt->currency : "RUB");
        tx_step(ctx, CTL_STATE_IDLE);
        tx_step(ctx, CTL_STATE_AWAIT_CARD);
        break;
    case CTL_EVENT_CARD_DATA: {
        CardData data = {
            .pan_masked = "4256********9310",
            .expiry = "2712",
            .emv_ok = evt->emv_ok,
        };
        if (ctx->state == CTL_STATE_AWAIT_CARD && card_verify(&data)) {
            tx_step(ctx, CTL_STATE_AWAIT_PIN);
        } else {
            log_ts("ControlSys: CardData rejected at state=%s", ctl_state_name(ctx->state));
        }
        break;
    }
    case CTL_EVENT_PIN_ENTERED:
        if (ctx->state == CTL_STATE_AWAIT_PIN) {
            tx_step(ctx, CTL_STATE_AWAIT_BANK_RESP);
        } else {
            log_ts("ControlSys: unexpected PIN at state=%s", ctl_state_name(ctx->state));
        }
        break;
    case CTL_EVENT_BANK_RESPONSE:
        if (ctx->state == CTL_STATE_AWAIT_BANK_RESP) {
            bool approved = evt->approved;
            tx_step(ctx, approved ? CTL_STATE_APPROVED : CTL_STATE_DECLINED);
            txn_builder_build(ctx, approved);
            JournalRecord rec = {
                .tx_id = ctx->tx_id,
                .amount_cents = ctx->amount_cents,
                .currency = ctx->currency,
                .approved = approved,
            };
            journal_append(&rec);
            tx_step(ctx, CTL_STATE_PRINTED);
        } else {
            log_ts("ControlSys: unexpected BankResponse at state=%s", ctl_state_name(ctx->state));
        }
        break;
    case CTL_EVENT_CANCEL:
        log_ts("ControlSys: received cancel");
        ctx->state = CTL_STATE_IDLE;
        break;
    case CTL_EVENT_UPDATE_REQUEST:
        update_loader_begin(evt->role ? evt->role : "unknown");
        break;
    case CTL_EVENT_UPDATE_PAYLOAD: {
        update_loader_push_chunk(evt->update_version ? evt->update_version : "unknown",
                                 evt->chunk_index, evt->chunk_total,
                                 evt->update_size, evt->signature_ok);
        break;
    }
    case CTL_EVENT_UPDATE_VERIFY: {
        UpdateSlot slot;
        bool loader_ok = update_loader_finalize();
        if (loader_ok && update_storage_snapshot(&slot)) {
            if (update_verifier_check(&slot, evt->signature_ok)) {
                log_ts("Update: verifier approved %s", slot.version);
            } else {
                log_ts("Update: verifier rejected %s", slot.version);
            }
        }
        break;
    }
    case CTL_EVENT_UPDATE_INSTALL: {
        UpdateSlot slot;
        if (update_storage_snapshot(&slot)) {
            update_installer_apply(&slot, evt->install_ok);
        }
        break;
    }
    default:
        log_ts("ControlSys: unknown event type=%d", evt->type);
        break;
    }
}

void sm_run_demo(void) {
    TxContext ctx;
    tx_init(&ctx);
    ctl_event_channel_init();

    CtlEvent evt;
    while (ctl_event_channel_next(&evt) || ctl_event_script_next(&evt)) {
        handle_event(&ctx, &evt);
    }

    log_ts("ControlSys: halt (tx=%s)", ctx.tx_id);
}
