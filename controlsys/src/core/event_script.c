#include "controlsys/events.h"

#include <stddef.h>

static const CtlEvent kScript[] = {
    {CTL_EVENT_HEARTBEAT, .network_ok = true, .power_ok = true},
    {CTL_EVENT_SET_AMOUNT, .amount_cents = 12345, .currency = "RUB"},
    {CTL_EVENT_CARD_DATA, .amount_cents = 0, .emv_ok = true},
    {CTL_EVENT_PIN_ENTERED, .amount_cents = 0},
    {CTL_EVENT_BANK_RESPONSE, .amount_cents = 0, .approved = true},
    {CTL_EVENT_UPDATE_REQUEST, .role = "operator"},
    {CTL_EVENT_UPDATE_PAYLOAD, .update_version = "1.0.1", .update_size = 1024 * 1024, .chunk_index = 1, .chunk_total = 2, .signature_ok = true},
    {CTL_EVENT_UPDATE_PAYLOAD, .update_version = "1.0.1", .update_size = 1024 * 1024, .chunk_index = 2, .chunk_total = 2, .signature_ok = true},
    {CTL_EVENT_UPDATE_VERIFY, .signature_ok = true},
    {CTL_EVENT_UPDATE_INSTALL, .install_ok = true},
    {CTL_EVENT_CANCEL, .amount_cents = 0},
};

bool ctl_event_script_next(CtlEvent* out) {
    static size_t index = 0;
    if (!out) {
        return false;
    }
    if (index >= sizeof(kScript)/sizeof(kScript[0])) {
        return false;
    }
    *out = kScript[index++];
    return true;
}
