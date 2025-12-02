#ifndef CONTROLSYS_SERVICES_STATUS_VERIFIER_H
#define CONTROLSYS_SERVICES_STATUS_VERIFIER_H

#include <stdbool.h>
#include <stddef.h>

struct TxContext;

typedef struct {
    const struct TxContext* ctx;
    bool approved;
    unsigned response_seq;
    int latency_ms;
} StatusPacket;

void status_verifier_reset(void);
bool status_verifier_validate(const StatusPacket* packet,
                              char* detail,
                              size_t detail_sz);

#endif /* CONTROLSYS_SERVICES_STATUS_VERIFIER_H */
