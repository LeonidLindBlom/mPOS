#include "controlsys/services/txn_builder.h"
#include "controlsys/log.h"

bool txn_builder_build(const TxContext* ctx, bool approved) {
    if (!ctx) {
        return false;
    }
    log_ts("TxnBuilder: tx=%s amount=%d.%02d %s result=%s",
           ctx->tx_id,
           ctx->amount_cents / 100,
           ctx->amount_cents % 100,
           ctx->currency,
           approved ? "APPROVED" : "DECLINED");
    return true;
}
