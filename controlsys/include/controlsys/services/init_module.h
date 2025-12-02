#ifndef CONTROLSYS_SERVICES_INIT_MODULE_H
#define CONTROLSYS_SERVICES_INIT_MODULE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    bool power_ready;
    bool network_ready;
    char detail[128];
} InitDecision;

void init_module_reset(void);
void init_module_update(bool power_ready, const char* power_detail,
                        bool network_ready, const char* network_detail);
bool init_module_can_start(InitDecision* decision);
void init_module_mark_start(const char* tx_id);

#endif /* CONTROLSYS_SERVICES_INIT_MODULE_H */
