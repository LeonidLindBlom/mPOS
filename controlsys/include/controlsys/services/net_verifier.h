#ifndef CONTROLSYS_SERVICES_NET_VERIFIER_H
#define CONTROLSYS_SERVICES_NET_VERIFIER_H

#include <stdbool.h>

typedef struct {
    bool link_up;
    bool ping_ok;
    int signal_strength; /* 0..100 */
    unsigned heartbeat_seq;
} NetSample;

void net_verifier_reset(void);
bool net_verifier_submit(const NetSample* sample);
bool net_verifier_ready(void);
const char* net_verifier_status(void);

#endif /* CONTROLSYS_SERVICES_NET_VERIFIER_H */
