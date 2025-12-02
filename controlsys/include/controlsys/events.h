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
    CTL_EVENT_UPDATE_INSTALL,
    CTL_EVENT_LOG_EXPORT_REQUEST,
    CTL_EVENT_LOG_EXPORT_DATA,
    CTL_EVENT_LOG_EXPORT_COMPLETE
} CtlEventType;

typedef struct {
    CtlEventType type;
    int amount_cents;
    const char* currency;
    bool approved;
    const char* note;
    const char* role;
    bool network_ok;
    bool ping_ok;
    bool power_ok;
    unsigned heartbeat_seq;
    int network_signal;
    int power_mv;
    int power_soc;
    int power_rate;
    bool emv_ok;
    const char* pan;
    const char* expiry;
    const char* cardholder;
    const char* update_version;
    size_t update_size;
    bool signature_ok;
    bool install_ok;
    size_t chunk_index;
    size_t chunk_total;
    unsigned bank_seq;
    int bank_latency_ms;
} CtlEvent;

const CtlEvent* ctl_event_script_transaction(size_t* count);
const CtlEvent* ctl_event_script_update(size_t* count);
const CtlEvent* ctl_event_script_log_export(size_t* count);

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_EVENTS_H */
