#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

typedef enum {
    ST_IDLE = 0,
    ST_AWAIT_CARD,
    ST_AWAIT_PIN,
    ST_AWAIT_BANK_RESP,
    ST_APPROVED,
    ST_DECLINED,
    ST_PRINTED
} State;

static const char* state_name(State s) {
    switch (s) {
        case ST_IDLE: return "Idle";
        case ST_AWAIT_CARD: return "AwaitCard";
        case ST_AWAIT_PIN: return "AwaitPIN";
        case ST_AWAIT_BANK_RESP: return "AwaitBankResp";
        case ST_APPROVED: return "Approved";
        case ST_DECLINED: return "Declined";
        case ST_PRINTED: return "Printed";
        default: return "Unknown";
    }
}

static void log_ts(const char* fmt, ...) {
    char ts_buf[64];
    time_t now = time(NULL);
    struct tm tm_buf;
    struct tm* tm_ptr = gmtime_r(&now, &tm_buf);
    if (!tm_ptr) {
        memset(ts_buf, 0, sizeof(ts_buf));
    } else {
        strftime(ts_buf, sizeof(ts_buf), "%Y-%m-%dT%H:%M:%SZ", tm_ptr);
    }

    va_list ap;
    va_start(ap, fmt);
    char msg_buf[256];
    vsnprintf(msg_buf, sizeof(msg_buf), fmt, ap);
    va_end(ap);

    fprintf(stderr, "[%s] %s\n", ts_buf, msg_buf);
    fflush(stderr);
}

typedef struct {
    State state;
    char tx_id[48];
    unsigned seq;
    int amount_cents;
    char currency[8];
} TxContext;

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

static void tx_start(TxContext* ctx, int amount_cents, const char* currency) {
    ctx->state = ST_IDLE;
    ctx->seq = 0;
    ctx->amount_cents = amount_cents;
    strncpy(ctx->currency, currency, sizeof(ctx->currency) - 1);
    ctx->currency[sizeof(ctx->currency) - 1] = '\0';
    gen_tx_id(ctx->tx_id, sizeof(ctx->tx_id));
    log_ts("ControlSys: start tx=%s amount=%d.%02d %s",
           ctx->tx_id,
           amount_cents / 100,
           amount_cents % 100,
           ctx->currency);
}

static void tx_transition(TxContext* ctx, State next) {
    ctx->state = next;
    ctx->seq++;
    log_ts("ControlSys: tx=%s seq=%u state=%s",
           ctx->tx_id,
           ctx->seq,
           state_name(next));
}

int main(void) {
    log_ts("ControlSys: boot");

    TxContext tx;
    tx_start(&tx, 12345, "RUB");

    tx_transition(&tx, ST_IDLE);
    sleep(1);
    tx_transition(&tx, ST_AWAIT_CARD);
    sleep(1);
    tx_transition(&tx, ST_AWAIT_PIN);
    sleep(1);
    tx_transition(&tx, ST_AWAIT_BANK_RESP);
    sleep(1);
    tx_transition(&tx, ST_APPROVED);
    sleep(1);
    tx_transition(&tx, ST_PRINTED);

    log_ts("ControlSys: halt (tx=%s)", tx.tx_id);
    return 0;
}
