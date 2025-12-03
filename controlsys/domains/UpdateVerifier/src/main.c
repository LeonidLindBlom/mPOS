#include "controlsys/services/update_verifier.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/UpdateVerifierInterface.idl.h>
#include <controlsys/UpdateVerifier.edl.h>

static UpdateVerifierInterface iface;

nk_err_t VerifyImpl(struct UpdateVerifierInterface *self,
                    const UpdateVerifierInterface_Verify_req *req,
                    const struct nk_arena *reqArena,
                    UpdateVerifierInterface_Verify_res *res,
                    struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    UpdateSlot slot = {
        .version = nk_str_read(&req->version, reqArena),
        .total_size = req->totalSize,
        .complete = true,
    };
    res->ok = update_verifier_check(&slot, req->signatureOk);
    return NK_EOK;
}

int main(void) {
    UpdateVerifierInterface_ops ops = {
        .Verify = VerifyImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_UPDATE_VERIFIER, &transport);

    UpdateVerifier_entity entity;
    UpdateVerifier_entity_init(&entity, &iface);

    UpdateVerifier_entity_req req;
    UpdateVerifier_entity_res res;
    char req_buf[UpdateVerifier_entity_req_arena_size];
    char res_buf[UpdateVerifier_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            UpdateVerifier_entity_dispatch(&entity, &req.base_, &reqArena,
                                           &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
