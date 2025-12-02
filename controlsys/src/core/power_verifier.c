#include "controlsys/services/power_verifier.h"
#include "controlsys/log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    bool ok;
    char reason[96];
    int last_soc;
    int last_mv;
} PowerVerifierState;

static PowerVerifierState g_state;

void power_verifier_reset(void) {
    memset(&g_state, 0, sizeof(g_state));
    g_state.ok = false;
    strcpy(g_state.reason, "await heartbeat");
}

static void set_status(bool ok, const char* fmt, ...) {
    g_state.ok = ok;
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(g_state.reason, sizeof(g_state.reason), fmt, ap);
    va_end(ap);
    log_box("PowerVerifier", "%s", g_state.reason);
}

bool power_verifier_submit(const PowerSample* sample) {
    if (!sample) {
        set_status(false, "no sample");
        return false;
    }

    if (!sample->sensor_ok) {
        set_status(false, "sensor fault");
        return false;
    }

    if (sample->millivolts < 3000 || sample->millivolts > 4300) {
        set_status(false, "voltage=%dmV out of bounds", sample->millivolts);
        return false;
    }

    if (sample->state_of_charge < 5) {
        set_status(false, "soc too low=%d%%", sample->state_of_charge);
        return false;
    }

    if (sample->state_of_charge > 100) {
        set_status(false, "soc invalid=%d%%", sample->state_of_charge);
        return false;
    }

    if (g_state.last_soc != 0 &&
        (sample->state_of_charge - g_state.last_soc) > 20) {
        set_status(false, "soc jump detected (%d→%d)", g_state.last_soc, sample->state_of_charge);
        return false;
    }

    if (sample->discharge_rate > 15) {
        set_status(false, "discharge too fast=%d%%/min", sample->discharge_rate);
        return false;
    }

    g_state.last_soc = sample->state_of_charge;
    g_state.last_mv = sample->millivolts;
    set_status(true, "power stable (soc=%d%% mv=%d)", sample->state_of_charge, sample->millivolts);
    return true;
}

bool power_verifier_ready(void) {
    return g_state.ok;
}

const char* power_verifier_status(void) {
    return g_state.reason;
}
