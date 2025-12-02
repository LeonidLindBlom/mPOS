#include "controlsys/services/update_verifier.h"
#include "controlsys/log.h"

static const char* kBankPublicKey = "BANK_PUBKEY_STUB";

bool update_verifier_check(const UpdateSlot* slot, bool signature_ok_hint) {
    if (!slot || !slot->complete) {
        log_box("UpdateVerifier", "slot incomplete");
        return false;
    }
    log_box("UpdateVerifier",
            "verifying %s\nsize=%zu\nkey=%s",
            slot->version,
            slot->total_size,
            kBankPublicKey);
    if (!signature_ok_hint) {
        log_box("UpdateVerifier", "signature mismatch");
        return false;
    }
    return true;
}
