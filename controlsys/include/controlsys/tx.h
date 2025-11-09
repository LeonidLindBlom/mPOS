#ifndef CONTROLSYS_TX_H
#define CONTROLSYS_TX_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CTL_STATE_IDLE = 0,
    CTL_STATE_AWAIT_CARD,
    CTL_STATE_AWAIT_PIN,
    CTL_STATE_AWAIT_BANK_RESP,
    CTL_STATE_APPROVED,
    CTL_STATE_DECLINED,
    CTL_STATE_PRINTED
} CtlState;

const char* ctl_state_name(CtlState state);

typedef struct {
    CtlState state;
    char tx_id[48];
    unsigned seq;
    int amount_cents;
    char currency[8];
} TxContext;

void tx_init(TxContext* ctx);
void tx_start(TxContext* ctx, int amount_cents, const char* currency);
void tx_step(TxContext* ctx, CtlState next);

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_TX_H */
