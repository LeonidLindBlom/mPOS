#include "controlsys/services/update_loader.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"
#include "controlsys/log.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/UpdateLoaderInterface.idl.h>
#include <controlsys/UpdateLoader.edl.h>

static UpdateLoaderInterface iface;

nk_err_t BeginImpl(struct UpdateLoaderInterface *self,
                   const UpdateLoaderInterface_Begin_req *req,
                   const struct nk_arena *reqArena,
                   UpdateLoaderInterface_Begin_res *res,
                   struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    const char* requester = nk_str_read(&req->requester, reqArena);
    res->ok = update_loader_begin(requester);
    return NK_EOK;
}

nk_err_t PushChunkImpl(struct UpdateLoaderInterface *self,
                       const UpdateLoaderInterface_PushChunk_req *req,
                       const struct nk_arena *reqArena,
                       UpdateLoaderInterface_PushChunk_res *res,
                       struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    const char* version = nk_str_read(&req->version, reqArena);
    res->ok = update_loader_push_chunk(version,
                                       req->chunkIndex,
                                       req->chunkTotal,
                                       req->chunkSize,
                                       req->signatureHint);
    return NK_EOK;
}

nk_err_t FinalizeImpl(struct UpdateLoaderInterface *self,
                      const UpdateLoaderInterface_Finalize_req *req,
                      const struct nk_arena *reqArena,
                      UpdateLoaderInterface_Finalize_res *res,
                      struct nk_arena *resArena) {
    (void)self; (void)req; (void)reqArena; (void)resArena;
    res->ok = update_loader_finalize();
    return NK_EOK;
}

int main(void) {
    UpdateLoaderInterface_ops ops = {
        .Begin = BeginImpl,
        .PushChunk = PushChunkImpl,
        .Finalize = FinalizeImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_UPDATE_LOADER, &transport);

    UpdateLoader_entity entity;
    UpdateLoader_entity_init(&entity, &iface);

    UpdateLoader_entity_req req;
    UpdateLoader_entity_res res;
    char req_buf[UpdateLoader_entity_req_arena_size];
    char res_buf[UpdateLoader_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            UpdateLoader_entity_dispatch(&entity, &req.base_, &reqArena,
                                         &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
