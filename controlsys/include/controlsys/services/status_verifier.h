#ifndef CONTROLSYS_SERVICES_STATUS_VERIFIER_H
#define CONTROLSYS_SERVICES_STATUS_VERIFIER_H

#include <stdbool.h>

bool status_can_start_tx(void);
void status_update_network(bool ok);
void status_update_power(bool ok);

#endif /* CONTROLSYS_SERVICES_STATUS_VERIFIER_H */
