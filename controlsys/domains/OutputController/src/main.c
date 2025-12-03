#include "controlsys/services/output_controller.h"
#include "controlsys/tx.h"
#include "controlsys/log.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#include <string.h>

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/OutputControllerInterface.idl.h>
#include <controlsys/OutputController.edl.h>

static OutputControllerInterface iface;

nk_err_t InviteCardImpl(struct OutputControllerInterface *self,
                        const OutputControllerInterface_InviteCard_req *req,
                        const struct nk_arena *reqArena,
                        OutputControllerInterface_InviteCard_res *res,
                        struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena; (void)res;
    const char* tx_id = nk_str_read(&req->txId, reqArena);
    const char* currency = nk_str_read(&req->currency, reqArena);
    TxContext ctx = {.amount_cents = (int)req->amountCents};
    strncpy(ctx.tx_id, tx_id, sizeof(ctx.tx_id)-1);
    ctx.tx_id[sizeof(ctx.tx_id)-1] = '\0';
    strncpy(ctx.currency, currency, sizeof(ctx.currency)-1);
    ctx.currency[sizeof(ctx.currency)-1] = '\0';
    output_controller_invite_card(&ctx);
    return NK_EOK;
}

nk_err_t RequestPINImpl(struct OutputControllerInterface *self,
                        const OutputControllerInterface_RequestPIN_req *req,
                        const struct nk_arena *reqArena,
                        OutputControllerInterface_RequestPIN_res *res,
                        struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)res;
    const char* tx_id = nk_str_read(&req->txId, reqArena);
    TxContext ctx = {.amount_cents = 0};
    strncpy(ctx.tx_id, tx_id, sizeof(ctx.tx_id)-1);
    ctx.tx_id[sizeof(ctx.tx_id)-1] = '\0';
    output_controller_request_pin(&ctx);
    return NK_EOK;
}

nk_err_t ShowStatusImpl(struct OutputControllerInterface *self,
                        const OutputControllerInterface_ShowStatus_req *req,
                        const struct nk_arena *reqArena,
                        OutputControllerInterface_ShowStatus_res *res,
                        struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)res;
    const char* msg = nk_str_read(&req->message, reqArena);
    output_controller_show_status(NULL, msg);
    return NK_EOK;
}

nk_err_t ShowErrorImpl(struct OutputControllerInterface *self,
                       const OutputControllerInterface_ShowError_req *req,
                       const struct nk_arena *reqArena,
                       OutputControllerInterface_ShowError_res *res,
                       struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)res;
    const char* msg = nk_str_read(&req->message, reqArena);
    output_controller_show_error(msg);
    return NK_EOK;
}

nk_err_t PrintReceiptImpl(struct OutputControllerInterface *self,
                          const OutputControllerInterface_PrintReceipt_req *req,
                          const struct nk_arena *reqArena,
                          OutputControllerInterface_PrintReceipt_res *res,
                          struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)res;
    const char* tx_id = nk_str_read(&req->txId, reqArena);
    const char* currency = nk_str_read(&req->currency, reqArena);
    TxContext ctx = {.amount_cents = (int)req->amountCents};
    strncpy(ctx.tx_id, tx_id, sizeof(ctx.tx_id)-1);
    ctx.tx_id[sizeof(ctx.tx_id)-1] = '\0';
    strncpy(ctx.currency, currency, sizeof(ctx.currency)-1);
    ctx.currency[sizeof(ctx.currency)-1] = '\0';
    output_controller_print_receipt(&ctx, req->approved);
    return NK_EOK;
}

int main(void) {
    output_controller_reset();
    OutputControllerInterface_ops ops = {
        .InviteCard = InviteCardImpl,
        .RequestPIN = RequestPINImpl,
        .ShowStatus = ShowStatusImpl,
        .ShowError = ShowErrorImpl,
        .PrintReceipt = PrintReceiptImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_OUTPUT, &transport);

    OutputController_entity entity;
    OutputController_entity_init(&entity, &iface);

    OutputController_entity_req req;
    OutputController_entity_res res;
    char req_buf[OutputController_entity_req_arena_size];
    char res_buf[OutputController_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            OutputController_entity_dispatch(&entity, &req.base_, &reqArena,
                                             &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
