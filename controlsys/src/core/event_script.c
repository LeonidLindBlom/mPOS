#include "controlsys/events.h"

#include <stddef.h>

static const CtlEvent kTransactionScript[] = {
    {CTL_EVENT_HEARTBEAT, .network_ok = true, .ping_ok = true, .power_ok = true,
        .heartbeat_seq = 1, .network_signal = 90, .power_mv = 3950, .power_soc = 85, .power_rate = 1},
    {CTL_EVENT_SET_AMOUNT, .amount_cents = 12345, .currency = "RUB"},
    {CTL_EVENT_CARD_DATA, .amount_cents = 0, .emv_ok = true,
        .pan = "4256********9310", .expiry = "2712", .cardholder = "CARDHOLDER"},
    {CTL_EVENT_PIN_ENTERED, .amount_cents = 0},
    {CTL_EVENT_BANK_RESPONSE, .amount_cents = 0, .approved = true, .bank_seq = 1, .bank_latency_ms = 120},
};

static const CtlEvent kUpdateScript[] = {
    {CTL_EVENT_UPDATE_REQUEST, .role = "operator"},
    {CTL_EVENT_UPDATE_PAYLOAD, .update_version = "1.0.1", .update_size = 1024 * 1024,
        .chunk_index = 1, .chunk_total = 2, .signature_ok = true},
    {CTL_EVENT_UPDATE_PAYLOAD, .update_version = "1.0.1", .update_size = 1024 * 1024,
        .chunk_index = 2, .chunk_total = 2, .signature_ok = true},
    {CTL_EVENT_UPDATE_VERIFY, .signature_ok = true},
    {CTL_EVENT_UPDATE_INSTALL, .install_ok = true},
};

static const CtlEvent kLogExportScript[] = {
    {CTL_EVENT_LOG_EXPORT_REQUEST, .role = "engineer"},
    {CTL_EVENT_LOG_EXPORT_DATA, .note = "Журнал: запись #1 tx=20251202T120000Z-0001"},
    {CTL_EVENT_LOG_EXPORT_DATA, .note = "Журнал: запись #2 tx=20251202T120501Z-0002"},
    {CTL_EVENT_LOG_EXPORT_COMPLETE, .note = "Выгрузка завершена успешно"},
};

const CtlEvent* ctl_event_script_transaction(size_t* count) {
    if (count) {
        *count = sizeof(kTransactionScript) / sizeof(kTransactionScript[0]);
    }
    return kTransactionScript;
}

const CtlEvent* ctl_event_script_update(size_t* count) {
    if (count) {
        *count = sizeof(kUpdateScript) / sizeof(kUpdateScript[0]);
    }
    return kUpdateScript;
}

const CtlEvent* ctl_event_script_log_export(size_t* count) {
    if (count) {
        *count = sizeof(kLogExportScript) / sizeof(kLogExportScript[0]);
    }
    return kLogExportScript;
}
