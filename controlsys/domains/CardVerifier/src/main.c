#include "controlsys/services/card_verifier.h"
#include "controlsys/log.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/CardVerifierInterface.idl.h>
#include <controlsys/CardVerifier.edl.h>

static CardVerifierInterface iface;

nk_err_t CheckCardImpl(struct CardVerifierInterface *self,
                       const CardVerifierInterface_CheckCard_req *req,
                       const struct nk_arena *reqArena,
                       CardVerifierInterface_CheckCard_res *res,
                       struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    CardData data = {
        .pan_masked = nk_str_read(&req->panMasked, reqArena),
        .expiry = nk_str_read(&req->expiry, reqArena),
        .cardholder = nk_str_read(&req->holder, reqArena),
        .emv_ok = req->emvOk,
    };
    res->accepted = card_verify(&data);
    return NK_EOK;
}

int main(void) {
    CardVerifierInterface_ops ops = {
        .CheckCard = CheckCardImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_CARDVERIF, &transport);

    CardVerifier_entity entity;
    CardVerifier_entity_init(&entity, &iface);

    CardVerifier_entity_req req;
    CardVerifier_entity_res res;
    char req_buf[CardVerifier_entity_req_arena_size];
    char res_buf[CardVerifier_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            CardVerifier_entity_dispatch(&entity, &req.base_, &reqArena,
                                         &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
