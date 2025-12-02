#ifndef CONTROLSYS_SERVICES_CARD_VERIFIER_H
#define CONTROLSYS_SERVICES_CARD_VERIFIER_H

#include <stdbool.h>

typedef struct {
    const char* pan_masked;
    const char* expiry;
    bool emv_ok;
    const char* cardholder;
} CardData;

bool card_verify(const CardData* data);

#endif /* CONTROLSYS_SERVICES_CARD_VERIFIER_H */
