#include "controlsys/services/auth_module.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/AuthInterface.idl.h>
#include <controlsys/AuthModule.edl.h>

static AuthInterface iface;

nk_err_t CheckRoleImpl(struct AuthInterface *self,
                       const AuthInterface_CheckRole_req *req,
                       const struct nk_arena *reqArena,
                       AuthInterface_CheckRole_res *res,
                       struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    const char* role = nk_str_read(&req->role, reqArena);
    res->accepted = auth_check_operator(role);
    return NK_EOK;
}

int main(void) {
    AuthInterface_ops ops = {
        .CheckRole = CheckRoleImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_AUTH, &transport);

    AuthModule_entity entity;
    AuthModule_entity_init(&entity, &iface);

    AuthModule_entity_req req;
    AuthModule_entity_res res;
    char req_buf[AuthModule_entity_req_arena_size];
    char res_buf[AuthModule_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            AuthModule_entity_dispatch(&entity, &req.base_, &reqArena,
                                       &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
