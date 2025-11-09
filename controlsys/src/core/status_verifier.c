#include "controlsys/services/status_verifier.h"
#include "controlsys/log.h"

static bool g_network_ok = true;
static bool g_power_ok = true;

bool status_can_start_tx(void) {
    if (!g_network_ok) {
        log_ts("Status: network unhealthy, blocking tx start");
        return false;
    }
    if (!g_power_ok) {
        log_ts("Status: power insufficient, blocking tx start");
        return false;
    }
    return true;
}

void status_update_network(bool ok) {
    g_network_ok = ok;
    log_ts("Status: network %s", ok ? "OK" : "FAIL");
}

void status_update_power(bool ok) {
    g_power_ok = ok;
    log_ts("Status: power %s", ok ? "OK" : "LOW");
}
