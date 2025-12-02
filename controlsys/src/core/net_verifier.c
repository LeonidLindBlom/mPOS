#include "controlsys/services/net_verifier.h"
#include "controlsys/log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    bool ok;
    char reason[96];
    unsigned last_seq;
    bool last_link;
    unsigned flap_count;
} NetVerifierState;

static NetVerifierState g_state;

void net_verifier_reset(void) {
    memset(&g_state, 0, sizeof(g_state));
    g_state.ok = false;
    strcpy(g_state.reason, "await heartbeat");
}

static void update_reason(bool ok, const char* fmt, ...) {
    g_state.ok = ok;
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(g_state.reason, sizeof(g_state.reason), fmt, ap);
    va_end(ap);
    log_box("NetVerifier", "%s", g_state.reason);
}

bool net_verifier_submit(const NetSample* sample) {
    if (!sample) {
        update_reason(false, "no sample");
        return false;
    }

    if (g_state.last_seq != 0 && sample->heartbeat_seq > g_state.last_seq + 1) {
        g_state.flap_count = 0;
    }
    if (sample->link_up != g_state.last_link) {
        if (sample->heartbeat_seq - g_state.last_seq <= 3) {
            if (g_state.flap_count < 10) {
                g_state.flap_count++;
            }
        } else {
            g_state.flap_count = 0;
        }
        g_state.last_link = sample->link_up;
    }

    g_state.last_seq = sample->heartbeat_seq;

    if (!sample->link_up) {
        update_reason(false, "link down (heartbeat=%u)", sample->heartbeat_seq);
        return false;
    }

    if (!sample->ping_ok) {
        update_reason(false, "ping timeout (seq=%u)", sample->heartbeat_seq);
        return false;
    }

    if (sample->signal_strength < 20 || sample->signal_strength > 100) {
        update_reason(false, "signal out of range=%d", sample->signal_strength);
        return false;
    }

    if (g_state.flap_count >= 3) {
        update_reason(false, "instability detected (flaps=%u)", g_state.flap_count);
        return false;
    }

    update_reason(true, "stable link (signal=%d, ping=ok)", sample->signal_strength);
    return true;
}

bool net_verifier_ready(void) {
    return g_state.ok;
}

const char* net_verifier_status(void) {
    return g_state.reason;
}
