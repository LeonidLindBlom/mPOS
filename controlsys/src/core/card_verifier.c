#include "controlsys/services/card_verifier.h"
#include "controlsys/log.h"

bool card_verify(const CardData* data) {
    if (!data) {
        log_box("CardVerifier", "no data");
        return false;
    }
    log_box("CardVerifier",
            "PAN=%s\nExpiry=%s\nHolder=%s\nEMV=%s",
            data->pan_masked ? data->pan_masked : "(null)",
            data->expiry ? data->expiry : "(null)",
            data->cardholder ? data->cardholder : "(unknown)",
            data->emv_ok ? "OK" : "FAIL");
    return data->emv_ok;
}
