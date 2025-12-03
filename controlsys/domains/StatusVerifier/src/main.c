#include "controlsys/services/status_verifier.h"
#include "controlsys/tx.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#include <string.h>

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/StatusVerifierInterface.idl.h>
#include <controlsys/StatusVerifier.edl.h>

static StatusVerifierInterface iface;

nk_err_t ValidateImpl(struct StatusVerifierInterface *self,
                      const StatusVerifierInterface_Validate_req *req,
                      const struct nk_arena *reqArena,
                      StatusVerifierInterface_Validate_res *res,
                      struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    TxContext ctx;
    tx_init(&ctx);
    const char* tx_id = nk_str_read(&req->txId, reqArena);
    strncpy(ctx.tx_id, tx_id, sizeof(ctx.tx_id)-1);
    ctx.tx_id[sizeof(ctx.tx_id)-1] = '\0';
    ctx.state = CTL_STATE_AWAIT_BANK_RESP;
    StatusPacket packet = {
        .ctx = &ctx,
        .approved = req->approved,
        .response_seq = req->seqNumber,
        .latency_ms = req->latencyMs,
    };
    char audit[96];
    res->ok = status_verifier_validate(&packet, audit, sizeof(audit));
    return NK_EOK;
}

int main(void) {
    status_verifier_reset();
    StatusVerifierInterface_ops ops = {
        .Validate = ValidateImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_STATUS, &transport);

    StatusVerifier_entity entity;
    StatusVerifier_entity_init(&entity, &iface);

    StatusVerifier_entity_req req;
    StatusVerifier_entity_res res;
    char req_buf[StatusVerifier_entity_req_arena_size];
    char res_buf[StatusVerifier_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            StatusVerifier_entity_dispatch(&entity, &req.base_, &reqArena,
                                           &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
