#include "controlsys/services/status_verifier.h"
#include "controlsys/tx.h"
#include "controlsys/log.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    char last_tx[48];
    unsigned last_seq;
} StatusState;

static StatusState g_status;

void status_verifier_reset(void) {
    memset(&g_status, 0, sizeof(g_status));
}

bool status_verifier_validate(const StatusPacket* packet,
                              char* detail,
                              size_t detail_sz) {
    if (!packet || !packet->ctx || !detail || detail_sz == 0) {
        return false;
    }

    const TxContext* ctx = packet->ctx;
    if (ctx->state != CTL_STATE_AWAIT_BANK_RESP) {
        snprintf(detail, detail_sz, "unexpected state=%s", ctl_state_name(ctx->state));
        log_box("StatusVerifier", "%s", detail);
        return false;
    }

    if (strncmp(ctx->tx_id, g_status.last_tx, sizeof(g_status.last_tx)) == 0 &&
        packet->response_seq <= g_status.last_seq) {
        snprintf(detail, detail_sz, "replayed response seq=%u", packet->response_seq);
        log_box("StatusVerifier", "%s", detail);
        return false;
    }

    strncpy(g_status.last_tx, ctx->tx_id, sizeof(g_status.last_tx) - 1);
    g_status.last_tx[sizeof(g_status.last_tx) - 1] = '\0';
    g_status.last_seq = packet->response_seq;

    snprintf(detail, detail_sz, "bank reply %s (seq=%u, latency=%dms)",
             packet->approved ? "APPROVED" : "DECLINED",
             packet->response_seq,
             packet->latency_ms);
    log_box("StatusVerifier", "%s", detail);
    return true;
}
