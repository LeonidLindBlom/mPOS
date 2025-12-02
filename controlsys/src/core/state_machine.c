#include "controlsys/state_machine.h"
#include "controlsys/tx.h"
#include "controlsys/events.h"
#include "controlsys/log.h"
#include "controlsys/services/card_verifier.h"
#include "controlsys/services/status_verifier.h"
#include "controlsys/services/net_verifier.h"
#include "controlsys/services/power_verifier.h"
#include "controlsys/services/init_module.h"
#include "controlsys/services/output_controller.h"
#include "controlsys/services/auth_module.h"
#include "controlsys/services/journal.h"
#include "controlsys/services/txn_builder.h"
#include "controlsys/services/update_loader.h"
#include "controlsys/services/update_storage.h"
#include "controlsys/services/update_verifier.h"
#include "controlsys/services/update_installer.h"

#include <unistd.h>

static void handle_event(TxContext* ctx, const CtlEvent* evt) {
    switch (evt->type) {
    case CTL_EVENT_HEARTBEAT: {
        NetSample net = {
            .link_up = evt->network_ok,
            .ping_ok = evt->ping_ok,
            .signal_strength = evt->network_signal,
            .heartbeat_seq = evt->heartbeat_seq,
        };
        bool net_ready = net_verifier_submit(&net);

        PowerSample power = {
            .sensor_ok = evt->power_ok,
            .millivolts = evt->power_mv,
            .state_of_charge = evt->power_soc,
            .discharge_rate = evt->power_rate,
        };
        bool power_ready = power_verifier_submit(&power);
        init_module_update(power_ready, power_verifier_status(),
                           net_ready, net_verifier_status());
        break;
    }
    case CTL_EVENT_SET_AMOUNT: {
        InitDecision decision;
        if (!init_module_can_start(&decision)) {
            output_controller_show_error(decision.detail);
            break;
        }
        tx_start(ctx, evt->amount_cents, evt->currency ? evt->currency : "RUB");
        init_module_mark_start(ctx->tx_id);
        tx_step(ctx, CTL_STATE_IDLE);
        tx_step(ctx, CTL_STATE_AWAIT_CARD);
        output_controller_invite_card(ctx);
        break;
    }
    case CTL_EVENT_CARD_DATA: {
        CardData data = {
            .pan_masked = evt->pan ? evt->pan : "4256********9310",
            .expiry = evt->expiry ? evt->expiry : "2712",
            .emv_ok = evt->emv_ok,
            .cardholder = evt->cardholder,
        };
        if (ctx->state == CTL_STATE_AWAIT_CARD && card_verify(&data)) {
            tx_step(ctx, CTL_STATE_AWAIT_PIN);
            output_controller_request_pin(ctx);
        } else {
            log_ts("ControlSys: CardData rejected at state=%s", ctl_state_name(ctx->state));
            output_controller_show_error("Карта отклонена");
        }
        break;
    }
    case CTL_EVENT_PIN_ENTERED:
        if (ctx->state == CTL_STATE_AWAIT_PIN) {
            tx_step(ctx, CTL_STATE_AWAIT_BANK_RESP);
            output_controller_show_status(ctx, "PIN принят");
        } else {
            log_ts("ControlSys: unexpected PIN at state=%s", ctl_state_name(ctx->state));
        }
        break;
    case CTL_EVENT_BANK_RESPONSE:
        if (ctx->state == CTL_STATE_AWAIT_BANK_RESP) {
            StatusPacket packet = {
                .ctx = ctx,
                .approved = evt->approved,
                .response_seq = evt->bank_seq,
                .latency_ms = evt->bank_latency_ms,
            };
            char audit[96];
            if (!status_verifier_validate(&packet, audit, sizeof(audit))) {
                output_controller_show_error(audit);
                break;
            }
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
            output_controller_show_status(ctx, approved ? "Операция подтверждена" : "Операция отклонена");
            output_controller_print_receipt(ctx, approved);
            tx_step(ctx, CTL_STATE_PRINTED);
        } else {
            log_ts("ControlSys: unexpected BankResponse at state=%s", ctl_state_name(ctx->state));
        }
        break;
    case CTL_EVENT_CANCEL:
        log_ts("ControlSys: received cancel");
        ctx->state = CTL_STATE_IDLE;
        output_controller_show_error("Операция отменена");
        break;
    case CTL_EVENT_UPDATE_REQUEST:
        if (update_loader_begin(evt->role ? evt->role : "unknown")) {
            output_controller_show_status(NULL, "Начато обновление");
        }
        break;
    case CTL_EVENT_UPDATE_PAYLOAD: {
        if (update_loader_push_chunk(evt->update_version ? evt->update_version : "unknown",
                                     evt->chunk_index, evt->chunk_total,
                                     evt->update_size, evt->signature_ok)) {
            output_controller_show_status(NULL, "Чанк обновления принят");
        }
        break;
    }
    case CTL_EVENT_UPDATE_VERIFY: {
        UpdateSlot slot;
        bool loader_ok = update_loader_finalize();
        if (loader_ok && update_storage_snapshot(&slot)) {
            if (update_verifier_check(&slot, evt->signature_ok)) {
                log_ts("Update: verifier approved %s", slot.version);
                output_controller_show_status(NULL, "Обновление проверено");
            } else {
                log_ts("Update: verifier rejected %s", slot.version);
                output_controller_show_error("Ошибка проверки обновления");
            }
        }
        break;
    }
    case CTL_EVENT_UPDATE_INSTALL: {
        UpdateSlot slot;
        if (update_storage_snapshot(&slot)) {
            update_installer_apply(&slot, evt->install_ok);
            output_controller_show_status(NULL, evt->install_ok ? "Обновление установлено" : "Установка отклонена");
        }
        break;
    }
    case CTL_EVENT_LOG_EXPORT_REQUEST:
        if (auth_check_operator(evt->role ? evt->role : "unknown")) {
            output_controller_show_status(NULL, "Журнал: доступ разрешён");
        } else {
            output_controller_show_error("Журнал: доступ отклонён");
        }
        break;
    case CTL_EVENT_LOG_EXPORT_DATA:
        output_controller_show_status(NULL, evt->note ? evt->note : "Журнал: запись передана");
        break;
    case CTL_EVENT_LOG_EXPORT_COMPLETE:
        output_controller_show_status(NULL, evt->note ? evt->note : "Журнал: выгрузка завершена");
        break;
    default:
        log_ts("ControlSys: unknown event type=%d", evt->type);
        break;
    }
}

static void replay_script(const char* name, TxContext* ctx,
                          const CtlEvent* script, size_t count) {
    if (!script || count == 0) {
        return;
    }
    log_box("Scenario", "Старт: %s", name);
    for (size_t i = 0; i < count; ++i) {
        handle_event(ctx, &script[i]);
    }
    log_box("Scenario", "Завершение: %s", name);
}

void sm_run_demo(void) {
    TxContext ctx;
    tx_init(&ctx);
    net_verifier_reset();
    power_verifier_reset();
    init_module_reset();
    output_controller_reset();
    status_verifier_reset();

    size_t count = 0;
    const CtlEvent* script = ctl_event_script_transaction(&count);
    replay_script("Транзакция", &ctx, script, count);

    script = ctl_event_script_update(&count);
    replay_script("Обновление", &ctx, script, count);

    script = ctl_event_script_log_export(&count);
    replay_script("Выгрузка журнала", &ctx, script, count);

    log_box("ControlSys", "Демо завершено. Внешние команды отключены.");
    while (1) {
        sleep(1);
    }
}
