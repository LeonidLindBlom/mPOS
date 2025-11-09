#include "controlsys/tx.h"
#include "controlsys/log.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

const char* ctl_state_name(CtlState state) {
    switch (state) {
        case CTL_STATE_IDLE: return "Idle";
        case CTL_STATE_AWAIT_CARD: return "AwaitCard";
        case CTL_STATE_AWAIT_PIN: return "AwaitPIN";
        case CTL_STATE_AWAIT_BANK_RESP: return "AwaitBankResp";
        case CTL_STATE_APPROVED: return "Approved";
        case CTL_STATE_DECLINED: return "Declined";
        case CTL_STATE_PRINTED: return "Printed";
        default: return "Unknown";
    }
}

static void gen_tx_id(char* buf, size_t buf_sz) {
    static unsigned counter = 0;
    time_t now = time(NULL);
    struct tm tm_buf;
    struct tm* tm_ptr = gmtime_r(&now, &tm_buf);
    if (!tm_ptr) {
        snprintf(buf, buf_sz, "00000000T000000Z-%04u", ++counter & 0xFFFF);
        return;
    }
    unsigned id = ++counter;
    snprintf(buf, buf_sz, "%04d%02d%02dT%02d%02d%02dZ-%04u",
             tm_ptr->tm_year + 1900,
             tm_ptr->tm_mon + 1,
             tm_ptr->tm_mday,
             tm_ptr->tm_hour,
             tm_ptr->tm_min,
             tm_ptr->tm_sec,
             id & 0xFFFF);
}

void tx_init(TxContext* ctx) {
    memset(ctx, 0, sizeof(*ctx));
    ctx->state = CTL_STATE_IDLE;
    strcpy(ctx->currency, "RUB");
}

void tx_start(TxContext* ctx, int amount_cents, const char* currency) {
    ctx->state = CTL_STATE_IDLE;
    ctx->seq = 0;
    ctx->amount_cents = amount_cents;
    if (currency && currency[0] != '\0') {
        strncpy(ctx->currency, currency, sizeof(ctx->currency) - 1);
        ctx->currency[sizeof(ctx->currency) - 1] = '\0';
    } else {
        strcpy(ctx->currency, "RUB");
    }
    gen_tx_id(ctx->tx_id, sizeof(ctx->tx_id));
    log_ts("ControlSys: start tx=%s amount=%d.%02d %s",
           ctx->tx_id,
           amount_cents / 100,
           amount_cents % 100,
           ctx->currency);
}

void tx_step(TxContext* ctx, CtlState next) {
    ctx->state = next;
    ctx->seq++;
    log_ts("ControlSys: tx=%s seq=%u state=%s",
           ctx->tx_id,
           ctx->seq,
           ctl_state_name(next));
}
