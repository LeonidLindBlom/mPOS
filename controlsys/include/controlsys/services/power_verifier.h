#ifndef CONTROLSYS_SERVICES_POWER_VERIFIER_H
#define CONTROLSYS_SERVICES_POWER_VERIFIER_H

#include <stdbool.h>

typedef struct {
    bool sensor_ok;
    int millivolts;
    int state_of_charge; /* 0..100 */
    int discharge_rate;  /* процент/минуту */
} PowerSample;

void power_verifier_reset(void);
bool power_verifier_submit(const PowerSample* sample);
bool power_verifier_ready(void);
const char* power_verifier_status(void);

#endif /* CONTROLSYS_SERVICES_POWER_VERIFIER_H */
