#include "controlsys/services/init_module.h"
#include "controlsys/log.h"

#include <stdio.h>
#include <string.h>

typedef struct {
    bool power_ready;
    bool network_ready;
    char power_detail[64];
    char network_detail[64];
} InitModuleState;

static InitModuleState g_state;

void init_module_reset(void) {
    memset(&g_state, 0, sizeof(g_state));
    strcpy(g_state.power_detail, "await heartbeat");
    strcpy(g_state.network_detail, "await heartbeat");
}

void init_module_update(bool power_ready, const char* power_detail,
                        bool network_ready, const char* network_detail) {
    g_state.power_ready = power_ready;
    g_state.network_ready = network_ready;
    if (power_detail) {
        strncpy(g_state.power_detail, power_detail, sizeof(g_state.power_detail) - 1);
        g_state.power_detail[sizeof(g_state.power_detail) - 1] = '\0';
    }
    if (network_detail) {
        strncpy(g_state.network_detail, network_detail, sizeof(g_state.network_detail) - 1);
        g_state.network_detail[sizeof(g_state.network_detail) - 1] = '\0';
    }
}

bool init_module_can_start(InitDecision* decision) {
    if (decision) {
        decision->power_ready = g_state.power_ready;
        decision->network_ready = g_state.network_ready;
        if (!g_state.power_ready) {
            snprintf(decision->detail, sizeof(decision->detail), "power: %s", g_state.power_detail);
        } else if (!g_state.network_ready) {
            snprintf(decision->detail, sizeof(decision->detail), "network: %s", g_state.network_detail);
        } else {
            snprintf(decision->detail, sizeof(decision->detail), "env stable");
        }
    }
    return g_state.power_ready && g_state.network_ready;
}

void init_module_mark_start(const char* tx_id) {
    log_box("InitModule",
            "tx=%s\npower=%s\nnetwork=%s",
            tx_id ? tx_id : "unknown",
            g_state.power_detail,
            g_state.network_detail);
}
