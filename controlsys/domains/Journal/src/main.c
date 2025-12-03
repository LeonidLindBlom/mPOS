#include "controlsys/services/journal.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"
#include "controlsys/nk_utils.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/JournalInterface.idl.h>
#include <controlsys/Journal.edl.h>

static JournalInterface iface;

nk_err_t AppendImpl(struct JournalInterface *self,
                    const JournalInterface_Append_req *req,
                    const struct nk_arena *reqArena,
                    JournalInterface_Append_res *res,
                    struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    JournalRecord rec = {
        .tx_id = nk_str_read(&req->txId, reqArena),
        .amount_cents = (int)req->amountCents,
        .currency = nk_str_read(&req->currency, reqArena),
        .approved = req->approved,
    };
    res->ok = journal_append(&rec);
    return NK_EOK;
}

nk_err_t ExportImpl(struct JournalInterface *self,
                    const JournalInterface_Export_req *req,
                    const struct nk_arena *reqArena,
                    JournalInterface_Export_res *res,
                    struct nk_arena *resArena) {
    (void)self; (void)reqArena;
    nk_arena_reset(resArena);
    nk_str_set(&res->record, "tx=demo-001", resArena);
    return NK_EOK;
}

int main(void) {
    JournalInterface_ops ops = {
        .Append = AppendImpl,
        .Export = ExportImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_JOURNAL, &transport);

    Journal_entity entity;
    Journal_entity_init(&entity, &iface);

    Journal_entity_req req;
    Journal_entity_res res;
    char req_buf[Journal_entity_req_arena_size];
    char res_buf[Journal_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            Journal_entity_dispatch(&entity, &req.base_, &reqArena,
                                    &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
