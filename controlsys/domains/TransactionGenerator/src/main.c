#include "controlsys/services/txn_builder.h"
#include "controlsys/tx.h"
#include "controlsys/nk_utils.h"
#include "controlsys/ipc_transport.h"
#include "controlsys/nk_utils.h"

#include <string.h>

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/TransactionGeneratorInterface.idl.h>
#include <controlsys/TransactionGenerator.edl.h>

static TransactionGeneratorInterface iface;

nk_err_t BuildImpl(struct TransactionGeneratorInterface *self,
                   const TransactionGeneratorInterface_Build_req *req,
                   const struct nk_arena *reqArena,
                   TransactionGeneratorInterface_Build_res *res,
                   struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    TxContext ctx;
    tx_init(&ctx);
    const char* tx_id = nk_str_read(&req->txId, reqArena);
    const char* currency = nk_str_read(&req->currency, reqArena);
    strncpy(ctx.tx_id, tx_id, sizeof(ctx.tx_id)-1);
    ctx.tx_id[sizeof(ctx.tx_id)-1] = '\0';
    strncpy(ctx.currency, currency, sizeof(ctx.currency)-1);
    ctx.currency[sizeof(ctx.currency)-1] = '\0';
    ctx.amount_cents = (int)req->amountCents;
    txn_builder_build(&ctx, req->approved);
    nk_arena_reset(resArena);
    nk_str_set(&res->payload, "ARQC", resArena);
    return NK_EOK;
}

int main(void) {
    TransactionGeneratorInterface_ops ops = {
        .Build = BuildImpl,
    };
    iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_TXN, &transport);

    TransactionGenerator_entity entity;
    TransactionGenerator_entity_init(&entity, &iface);

    TransactionGenerator_entity_req req;
    TransactionGenerator_entity_res res;
    char req_buf[TransactionGenerator_entity_req_arena_size];
    char res_buf[TransactionGenerator_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            TransactionGenerator_entity_dispatch(&entity, &req.base_, &reqArena,
                                                 &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
