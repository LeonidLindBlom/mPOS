#include "controlsys/services/update_storage.h"
#include "controlsys/ipc_transport.h"
#include "controlsys/nk_utils.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/UpdateStorageInterface.idl.h>
#include <controlsys/UpdateStorage.edl.h>

static UpdateStorageInterface iface;

nk_err_t ResetImpl(struct UpdateStorageInterface *self,
                   const UpdateStorageInterface_Reset_req *req,
                   const struct nk_arena *reqArena,
                   UpdateStorageInterface_Reset_res *res,
                   struct nk_arena *resArena) {
    (void)self; (void)req; (void)reqArena; (void)res; (void)resArena;
    update_storage_reset();
    return NK_EOK;
}

nk_err_t AppendImpl(struct UpdateStorageInterface *self,
                    const UpdateStorageInterface_Append_req *req,
                    const struct nk_arena *reqArena,
                    UpdateStorageInterface_Append_res *res,
                    struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    const char* version = nk_str_read(&req->version, reqArena);
    res->accepted = update_storage_append(version,
                                          (size_t)req->chunkSize,
                                          (size_t)req->chunkIndex,
                                          (size_t)req->chunkTotal);
    return NK_EOK;
}

nk_err_t SnapshotImpl(struct UpdateStorageInterface *self,
                      const UpdateStorageInterface_Snapshot_req *req,
                      const struct nk_arena *reqArena,
                      UpdateStorageInterface_Snapshot_res *res,
                      struct nk_arena *resArena) {
    (void)self; (void)req; (void)reqArena;
    UpdateSlot slot;
    bool ok = update_storage_snapshot(&slot);
    nk_arena_reset(resArena);
    nk_str_set(&res->version, slot.version ? slot.version : "", resArena);
    res->totalSize = slot.total_size;
    res->complete = ok;
    return NK_EOK;
}

int main(void) {
    UpdateStorageInterface_ops ops = {
        .Reset = ResetImpl,
        .Append = AppendImpl,
        .Snapshot = SnapshotImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_UPDATE_STORAGE, &transport);

    UpdateStorage_entity entity;
    UpdateStorage_entity_init(&entity, &iface);

    UpdateStorage_entity_req req;
    UpdateStorage_entity_res res;
    char req_buf[UpdateStorage_entity_req_arena_size];
    char res_buf[UpdateStorage_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            UpdateStorage_entity_dispatch(&entity, &req.base_, &reqArena,
                                          &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
