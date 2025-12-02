#include "controlsys/services/txn_builder.h"
#include "controlsys/log.h"

bool txn_builder_build(const TxContext* ctx, bool approved) {
    if (!ctx) {
        return false;
    }
    log_box("TxnBuilder",
            "tx=%s\namount=%d.%02d %s\nresult=%s",
            ctx->tx_id,
            ctx->amount_cents / 100,
            ctx->amount_cents % 100,
            ctx->currency,
            approved ? "APPROVED" : "DECLINED");
    return true;
}
