#include "controlsys/services/card_verifier.h"
#include "controlsys/log.h"

bool card_verify(const CardData* data) {
    if (!data) {
        log_ts("CardVerifier: no data");
        return false;
    }
    log_ts("CardVerifier: PAN=%s expiry=%s emv=%s",
           data->pan_masked ? data->pan_masked : "(null)",
           data->expiry ? data->expiry : "(null)",
           data->emv_ok ? "OK" : "FAIL");
    return data->emv_ok;
}
