#ifndef CONTROLSYS_EVENTS_H
#define CONTROLSYS_EVENTS_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    CTL_EVENT_SET_AMOUNT = 0,
    CTL_EVENT_CARD_DATA,
    CTL_EVENT_PIN_ENTERED,
    CTL_EVENT_BANK_RESPONSE,
    CTL_EVENT_CANCEL,
    CTL_EVENT_HEARTBEAT,
    CTL_EVENT_UPDATE_REQUEST,
    CTL_EVENT_UPDATE_PAYLOAD,
    CTL_EVENT_UPDATE_VERIFY,
    CTL_EVENT_UPDATE_INSTALL
} CtlEventType;

typedef struct {
    CtlEventType type;
    int amount_cents;
    const char* currency;
    bool approved;
    const char* note;
    const char* role;
    bool network_ok;
    bool power_ok;
    bool emv_ok;
    const char* update_version;
    size_t update_size;
    bool signature_ok;
    bool install_ok;
    size_t chunk_index;
    size_t chunk_total;
} CtlEvent;

bool ctl_event_script_next(CtlEvent* out);

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_EVENTS_H */
