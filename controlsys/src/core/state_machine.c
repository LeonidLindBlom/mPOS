#include "controlsys/state_machine.h"
#include "controlsys/tx.h"
#include "controlsys/events.h"
#include "controlsys/event_channel.h"
#include "controlsys/log.h"
#include "controlsys/nk_utils.h"
#include "clients.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/InputGuardInterface.idl.h>
#include <controlsys/InputGuard.edl.h>
#include <controlsys/OutputControllerInterface.idl.h>
#include <controlsys/OutputController.edl.h>
#include <controlsys/CardVerifierInterface.idl.h>
#include <controlsys/CardVerifier.edl.h>
#include <controlsys/TransactionGeneratorInterface.idl.h>
#include <controlsys/TransactionGenerator.edl.h>
#include <controlsys/StatusVerifierInterface.idl.h>
#include <controlsys/StatusVerifier.edl.h>
#include <controlsys/AuthInterface.idl.h>
#include <controlsys/AuthModule.edl.h>
#include <controlsys/JournalInterface.idl.h>
#include <controlsys/Journal.edl.h>
#include <controlsys/UpdateLoaderInterface.idl.h>
#include <controlsys/UpdateLoader.edl.h>
#include <controlsys/UpdateStorageInterface.idl.h>
#include <controlsys/UpdateStorage.edl.h>
#include <controlsys/UpdateVerifierInterface.idl.h>
#include <controlsys/UpdateVerifier.edl.h>
#include <controlsys/UpdateInstallerInterface.idl.h>
#include <controlsys/UpdateInstaller.edl.h>

#include <nk/arena.h>
#include <string.h>
#include <unistd.h>

static ControlSysClients g_clients;

static InputGuardInterface_proxy make_inputguard_proxy(void) {
    InputGuardInterface_proxy proxy;
    InputGuardInterface_proxy_init(&proxy, &g_clients.inputguard.transport.base, g_clients.inputguard.riid);
    return proxy;
}

static OutputControllerInterface_proxy make_output_proxy(void) {
    OutputControllerInterface_proxy proxy;
    OutputControllerInterface_proxy_init(&proxy, &g_clients.output.transport.base, g_clients.output.riid);
    return proxy;
}

static CardVerifierInterface_proxy make_card_proxy(void) {
    CardVerifierInterface_proxy proxy;
    CardVerifierInterface_proxy_init(&proxy, &g_clients.cardverif.transport.base, g_clients.cardverif.riid);
    return proxy;
}

static TransactionGeneratorInterface_proxy make_txn_proxy(void) {
    TransactionGeneratorInterface_proxy proxy;
    TransactionGeneratorInterface_proxy_init(&proxy, &g_clients.txn.transport.base, g_clients.txn.riid);
    return proxy;
}

static StatusVerifierInterface_proxy make_status_proxy(void) {
    StatusVerifierInterface_proxy proxy;
    StatusVerifierInterface_proxy_init(&proxy, &g_clients.statusverif.transport.base, g_clients.statusverif.riid);
    return proxy;
}

static AuthInterface_proxy make_auth_proxy(void) {
    AuthInterface_proxy proxy;
    AuthInterface_proxy_init(&proxy, &g_clients.auth.transport.base, g_clients.auth.riid);
    return proxy;
}

static JournalInterface_proxy make_journal_proxy(void) {
    JournalInterface_proxy proxy;
    JournalInterface_proxy_init(&proxy, &g_clients.journal.transport.base, g_clients.journal.riid);
    return proxy;
}

static UpdateLoaderInterface_proxy make_loader_proxy(void) {
    UpdateLoaderInterface_proxy proxy;
    UpdateLoaderInterface_proxy_init(&proxy, &g_clients.update_loader.transport.base, g_clients.update_loader.riid);
    return proxy;
}

static UpdateStorageInterface_proxy make_storage_proxy(void) {
    UpdateStorageInterface_proxy proxy;
    UpdateStorageInterface_proxy_init(&proxy, &g_clients.update_storage.transport.base, g_clients.update_storage.riid);
    return proxy;
}

static UpdateVerifierInterface_proxy make_verifier_proxy(void) {
    UpdateVerifierInterface_proxy proxy;
    UpdateVerifierInterface_proxy_init(&proxy, &g_clients.update_verifier.transport.base, g_clients.update_verifier.riid);
    return proxy;
}

static UpdateInstallerInterface_proxy make_installer_proxy(void) {
    UpdateInstallerInterface_proxy proxy;
    UpdateInstallerInterface_proxy_init(&proxy, &g_clients.update_installer.transport.base, g_clients.update_installer.riid);
    return proxy;
}

static bool rpc_inputguard_begin(const CtlEvent* evt) {
    InputGuardInterface_proxy proxy = make_inputguard_proxy();
    InputGuardInterface_BeginTransaction_req req;
    InputGuardInterface_BeginTransaction_res res;
    char req_buf[InputGuardInterface_BeginTransaction_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    req.amountCents = (nk_uint32_t)evt->amount_cents;
    nk_str_set(&req.currency, evt->currency ? evt->currency : "RUB", &reqArena);
    nk_err_t rc = InputGuardInterface_BeginTransaction(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.allowed;
}

static void rpc_inputguard_heartbeat(const CtlEvent* evt) {
    InputGuardInterface_proxy proxy = make_inputguard_proxy();
    InputGuardInterface_Heartbeat_req req = {0};
    InputGuardInterface_Heartbeat_res res;
    req.networkOk = evt->network_ok;
    req.pingOk = evt->ping_ok;
    req.powerOk = evt->power_ok;
    req.signalStrength = (nk_uint16_t)evt->network_signal;
    req.soc = (nk_uint16_t)evt->power_soc;
    InputGuardInterface_Heartbeat(&proxy.base, &req, NULL, &res, NULL);
}

static bool rpc_card_verify(const CtlEvent* evt) {
    CardVerifierInterface_proxy proxy = make_card_proxy();
    CardVerifierInterface_CheckCard_req req;
    CardVerifierInterface_CheckCard_res res;
    char req_buf[CardVerifierInterface_CheckCard_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.panMasked, evt->pan ? evt->pan : "4256********9310", &reqArena);
    nk_str_set(&req.expiry, evt->expiry ? evt->expiry : "2712", &reqArena);
    nk_str_set(&req.holder, evt->cardholder ? evt->cardholder : "CARDHOLDER", &reqArena);
    req.emvOk = evt->emv_ok;
    nk_err_t rc = CardVerifierInterface_CheckCard(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.accepted;
}

static void rpc_output_invite(const TxContext* ctx) {
    OutputControllerInterface_proxy proxy = make_output_proxy();
    OutputControllerInterface_InviteCard_req req;
    OutputControllerInterface_InviteCard_res res;
    char req_buf[OutputControllerInterface_InviteCard_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    req.amountCents = (nk_uint32_t)ctx->amount_cents;
    nk_str_set(&req.currency, ctx->currency, &reqArena);
    OutputControllerInterface_InviteCard(&proxy.base, &req, &reqArena, &res, NULL);
}

static void rpc_output_request_pin(const TxContext* ctx) {
    OutputControllerInterface_proxy proxy = make_output_proxy();
    OutputControllerInterface_RequestPIN_req req;
    OutputControllerInterface_RequestPIN_res res;
    char req_buf[OutputControllerInterface_RequestPIN_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    OutputControllerInterface_RequestPIN(&proxy.base, &req, &reqArena, &res, NULL);
}

static void rpc_output_status(const char* text) {
    OutputControllerInterface_proxy proxy = make_output_proxy();
    OutputControllerInterface_ShowStatus_req req;
    OutputControllerInterface_ShowStatus_res res;
    char req_buf[OutputControllerInterface_ShowStatus_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.message, text, &reqArena);
    OutputControllerInterface_ShowStatus(&proxy.base, &req, &reqArena, &res, NULL);
}

static void rpc_output_error(const char* text) {
    OutputControllerInterface_proxy proxy = make_output_proxy();
    OutputControllerInterface_ShowError_req req;
    OutputControllerInterface_ShowError_res res;
    char req_buf[OutputControllerInterface_ShowError_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.message, text, &reqArena);
    OutputControllerInterface_ShowError(&proxy.base, &req, &reqArena, &res, NULL);
}

static void rpc_output_receipt(const TxContext* ctx, bool approved) {
    OutputControllerInterface_proxy proxy = make_output_proxy();
    OutputControllerInterface_PrintReceipt_req req;
    OutputControllerInterface_PrintReceipt_res res;
    char req_buf[OutputControllerInterface_PrintReceipt_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    req.amountCents = (nk_uint32_t)ctx->amount_cents;
    nk_str_set(&req.currency, ctx->currency, &reqArena);
    req.approved = approved;
    OutputControllerInterface_PrintReceipt(&proxy.base, &req, &reqArena, &res, NULL);
}

static bool rpc_status_validate(const TxContext* ctx, const CtlEvent* evt) {
    StatusVerifierInterface_proxy proxy = make_status_proxy();
    StatusVerifierInterface_Validate_req req;
    StatusVerifierInterface_Validate_res res;
    char req_buf[StatusVerifierInterface_Validate_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    req.seqNumber = evt->bank_seq;
    req.approved = evt->approved;
    req.latencyMs = (nk_uint32_t)evt->bank_latency_ms;
    nk_err_t rc = StatusVerifierInterface_Validate(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.ok;
}

static void rpc_txn_build(const TxContext* ctx, bool approved) {
    TransactionGeneratorInterface_proxy proxy = make_txn_proxy();
    TransactionGeneratorInterface_Build_req req;
    TransactionGeneratorInterface_Build_res res;
    char req_buf[TransactionGeneratorInterface_Build_req_arena_size];
    char res_buf[TransactionGeneratorInterface_Build_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));
    nk_arena_reset(&reqArena);
    nk_arena_reset(&resArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    req.amountCents = (nk_uint32_t)ctx->amount_cents;
    nk_str_set(&req.currency, ctx->currency, &reqArena);
    req.approved = approved;
    TransactionGeneratorInterface_Build(&proxy.base, &req, &reqArena, &res, &resArena);
}

static void rpc_journal_append(const TxContext* ctx, bool approved) {
    JournalInterface_proxy proxy = make_journal_proxy();
    JournalInterface_Append_req req;
    JournalInterface_Append_res res;
    char req_buf[JournalInterface_Append_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.txId, ctx->tx_id, &reqArena);
    req.amountCents = (nk_uint32_t)ctx->amount_cents;
    nk_str_set(&req.currency, ctx->currency, &reqArena);
    req.approved = approved;
    JournalInterface_Append(&proxy.base, &req, &reqArena, &res, NULL);
}

static bool rpc_auth_check(const char* role) {
    AuthInterface_proxy proxy = make_auth_proxy();
    AuthInterface_CheckRole_req req;
    AuthInterface_CheckRole_res res;
    char req_buf[AuthInterface_CheckRole_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.role, role, &reqArena);
    nk_err_t rc = AuthInterface_CheckRole(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.accepted;
}

static bool rpc_update_begin(const char* requester) {
    UpdateLoaderInterface_proxy proxy = make_loader_proxy();
    UpdateLoaderInterface_Begin_req req;
    UpdateLoaderInterface_Begin_res res;
    char req_buf[UpdateLoaderInterface_Begin_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.requester, requester, &reqArena);
    nk_err_t rc = UpdateLoaderInterface_Begin(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.ok;
}

static bool rpc_update_push_chunk(const CtlEvent* evt) {
    UpdateLoaderInterface_proxy proxy = make_loader_proxy();
    UpdateLoaderInterface_PushChunk_req req;
    UpdateLoaderInterface_PushChunk_res res;
    char req_buf[UpdateLoaderInterface_PushChunk_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.version, evt->update_version ? evt->update_version : "unknown", &reqArena);
    req.chunkIndex = (nk_uint32_t)evt->chunk_index;
    req.chunkTotal = (nk_uint32_t)evt->chunk_total;
    req.chunkSize = (nk_uint32_t)evt->update_size;
    req.signatureHint = evt->signature_ok;
    nk_err_t rc = UpdateLoaderInterface_PushChunk(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.ok;
}

static void rpc_storage_reset(void) {
    UpdateStorageInterface_proxy proxy = make_storage_proxy();
    UpdateStorageInterface_Reset_req req = {0};
    UpdateStorageInterface_Reset_res res = {0};
    (void)UpdateStorageInterface_Reset(&proxy.base, &req, NULL, &res, NULL);
}

static bool rpc_storage_append(const CtlEvent* evt) {
    UpdateStorageInterface_proxy proxy = make_storage_proxy();
    UpdateStorageInterface_Append_req req;
    UpdateStorageInterface_Append_res res;
    char req_buf[UpdateStorageInterface_Append_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.version, evt->update_version ? evt->update_version : "unknown", &reqArena);
    req.chunkIndex = (nk_uint32_t)evt->chunk_index;
    req.chunkTotal = (nk_uint32_t)evt->chunk_total;
    req.chunkSize = (nk_uint32_t)evt->update_size;
    nk_err_t rc = UpdateStorageInterface_Append(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.accepted;
}

static bool rpc_update_finalize(void) {
    UpdateLoaderInterface_proxy proxy = make_loader_proxy();
    UpdateLoaderInterface_Finalize_req req;
    UpdateLoaderInterface_Finalize_res res;
    nk_err_t rc = UpdateLoaderInterface_Finalize(&proxy.base, &req, NULL, &res, NULL);
    return rc == NK_EOK && res.ok;
}

typedef struct {
    char version[17];
    uint32_t total;
    bool complete;
} UpdateSnapshot;

static bool rpc_update_snapshot(UpdateSnapshot* out) {
    UpdateStorageInterface_proxy proxy = make_storage_proxy();
    UpdateStorageInterface_Snapshot_req req;
    UpdateStorageInterface_Snapshot_res res;
    char res_buf[UpdateStorageInterface_Snapshot_res_arena_size];
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));
    nk_arena_reset(&resArena);
    nk_err_t rc = UpdateStorageInterface_Snapshot(&proxy.base, &req, NULL, &res, &resArena);
    if (rc != NK_EOK)
        return false;
    nk_uint32_t len = 0;
    nk_char_t* ver = nk_arena_get(nk_char_t, &resArena, &(res.version), &len);
    if (!ver || len >= sizeof(out->version))
        return false;
    memcpy(out->version, ver, len);
    out->version[len] = '\0';
    out->total = res.totalSize;
    out->complete = res.complete;
    return out->complete;
}

static bool rpc_update_verify(bool signature_ok) {
    UpdateSnapshot snap;
    if (!rpc_update_snapshot(&snap))
        return false;
    UpdateVerifierInterface_proxy proxy = make_verifier_proxy();
    UpdateVerifierInterface_Verify_req req;
    UpdateVerifierInterface_Verify_res res;
    char req_buf[UpdateVerifierInterface_Verify_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.version, snap.version, &reqArena);
    req.totalSize = snap.total;
    req.signatureOk = signature_ok;
    nk_err_t rc = UpdateVerifierInterface_Verify(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.ok;
}

static bool rpc_update_install(bool install_ok) {
    UpdateSnapshot snap;
    if (!rpc_update_snapshot(&snap))
        return false;
    UpdateInstallerInterface_proxy proxy = make_installer_proxy();
    UpdateInstallerInterface_Install_req req;
    UpdateInstallerInterface_Install_res res;
    char req_buf[UpdateInstallerInterface_Install_req_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    nk_arena_reset(&reqArena);
    nk_str_set(&req.version, snap.version, &reqArena);
    req.totalSize = snap.total;
    req.allow = install_ok ? 1 : 0;
    nk_err_t rc = UpdateInstallerInterface_Install(&proxy.base, &req, &reqArena, &res, NULL);
    return rc == NK_EOK && res.ok != 0;
}

static void handle_event(TxContext* ctx, const CtlEvent* evt) {
    switch (evt->type) {
    case CTL_EVENT_HEARTBEAT:
        rpc_inputguard_heartbeat(evt);
        break;
    case CTL_EVENT_SET_AMOUNT: {
        if (!rpc_inputguard_begin(evt)) {
            rpc_output_error("Запуск запрещён");
            break;
        }
        tx_start(ctx, evt->amount_cents, evt->currency ? evt->currency : "RUB");
        tx_step(ctx, CTL_STATE_IDLE);
        tx_step(ctx, CTL_STATE_AWAIT_CARD);
        rpc_output_invite(ctx);
        break;
    }
    case CTL_EVENT_CARD_DATA:
        if (ctx->state == CTL_STATE_AWAIT_CARD && rpc_card_verify(evt)) {
            tx_step(ctx, CTL_STATE_AWAIT_PIN);
            rpc_output_request_pin(ctx);
        } else {
            rpc_output_error("Карта отклонена");
        }
        break;
    case CTL_EVENT_PIN_ENTERED:
        if (ctx->state == CTL_STATE_AWAIT_PIN) {
            tx_step(ctx, CTL_STATE_AWAIT_BANK_RESP);
            rpc_output_status("PIN принят");
        }
        break;
    case CTL_EVENT_BANK_RESPONSE:
        if (ctx->state == CTL_STATE_AWAIT_BANK_RESP) {
            bool status_ok = rpc_status_validate(ctx, evt);
            if (!status_ok) {
                rpc_output_error("Ответ банка отклонён");
                break;
            }
            bool approved = evt->approved;
            tx_step(ctx, approved ? CTL_STATE_APPROVED : CTL_STATE_DECLINED);
            rpc_txn_build(ctx, approved);
            rpc_journal_append(ctx, approved);
            rpc_output_status(approved ? "Операция подтверждена" : "Операция отклонена");
            rpc_output_receipt(ctx, approved);
            tx_step(ctx, CTL_STATE_PRINTED);
        }
        break;
    case CTL_EVENT_CANCEL:
        ctx->state = CTL_STATE_IDLE;
        rpc_output_error("Операция отменена");
        break;
    case CTL_EVENT_UPDATE_REQUEST: {
        const char* role = evt->role ? evt->role : "unknown";
        if (!rpc_auth_check(role)) {
            rpc_output_error("Обновление запрещено");
            break;
        }
        rpc_storage_reset();
        if (rpc_update_begin(role)) {
            rpc_output_status("Начато обновление");
        }
        break;
    }
    case CTL_EVENT_UPDATE_PAYLOAD:
        if (rpc_update_push_chunk(evt) && rpc_storage_append(evt)) {
            rpc_output_status("Чанк обновления принят");
        } else {
            rpc_output_error("Чанк отклонён");
        }
        break;
    case CTL_EVENT_UPDATE_VERIFY:
        if (rpc_update_finalize() && rpc_update_verify(evt->signature_ok)) {
            rpc_output_status("Обновление проверено");
        } else {
            rpc_output_error("Ошибка проверки обновления");
        }
        break;
    case CTL_EVENT_UPDATE_INSTALL:
        if (rpc_update_install(evt->install_ok)) {
            rpc_output_status(evt->install_ok ? "Обновление установлено" : "Установка отклонена");
        } else {
            rpc_output_error("Не удалось установить обновление");
        }
        break;
    case CTL_EVENT_LOG_EXPORT_REQUEST:
        if (rpc_auth_check(evt->role ? evt->role : "engineer")) {
            rpc_output_status("Журнал: доступ разрешён");
        } else {
            rpc_output_error("Журнал: доступ запрещён");
        }
        break;
    case CTL_EVENT_LOG_EXPORT_DATA:
        rpc_output_status(evt->note ? evt->note : "Журнал: запись");
        break;
    case CTL_EVENT_LOG_EXPORT_COMPLETE:
        rpc_output_status(evt->note ? evt->note : "Журнал: выгрузка завершена");
        break;
    default:
        log_ts("ControlSys: unknown event type=%d", evt->type);
        break;
    }
}

void sm_run_demo(void) {
    controlsys_clients_init(&g_clients);

    TxContext ctx;
    tx_init(&ctx);

    size_t count = 0;
    const CtlEvent* script = ctl_event_script_transaction(&count);
    for (size_t i = 0; i < count; ++i) {
        handle_event(&ctx, &script[i]);
    }

    script = ctl_event_script_update(&count);
    for (size_t i = 0; i < count; ++i) {
        handle_event(&ctx, &script[i]);
    }

    script = ctl_event_script_log_export(&count);
    for (size_t i = 0; i < count; ++i) {
        handle_event(&ctx, &script[i]);
    }

    ctl_event_channel_init();
    log_box("ControlSys", "Демо завершено. Ожидаю внешние события.");

    CtlEvent evt;
    while (1) {
        if (ctl_event_channel_next(&evt)) {
            handle_event(&ctx, &evt);
        } else {
            usleep(50 * 1000);
        }
    }
}
