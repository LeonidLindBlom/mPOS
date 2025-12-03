#include "controlsys/services/update_installer.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/UpdateInstallerInterface.idl.h>
#include <controlsys/UpdateInstaller.edl.h>

static UpdateInstallerInterface iface;

nk_err_t InstallImpl(struct UpdateInstallerInterface *self,
                     const UpdateInstallerInterface_Install_req *req,
                     const struct nk_arena *reqArena,
                     UpdateInstallerInterface_Install_res *res,
                     struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    UpdateSlot slot = {
        .version = nk_str_read(&req->version, reqArena),
        .total_size = req->totalSize,
        .complete = true,
    };
    update_installer_apply(&slot, req->allow != 0);
    res->ok = req->allow ? 1 : 0;
    return NK_EOK;
}

int main(void) {
    UpdateInstallerInterface_ops ops = {
        .Install = InstallImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_UPDATE_INSTALLER, &transport);

    UpdateInstaller_entity entity;
    UpdateInstaller_entity_init(&entity, &iface);

    UpdateInstaller_entity_req req;
    UpdateInstaller_entity_res res;
    char req_buf[UpdateInstaller_entity_req_arena_size];
    char res_buf[UpdateInstaller_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            UpdateInstaller_entity_dispatch(&entity, &req.base_, &reqArena,
                                            &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
