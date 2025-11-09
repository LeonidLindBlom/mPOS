#include "controlsys/event_channel.h"
#include "controlsys/log.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

static bool input_eof = false;

void ctl_event_channel_init(void) {
    input_eof = false;
}

static const char* json_find_string(const char* line, const char* key) {
    static char buffer[64];
    buffer[0] = '\0';
    char pattern[32];
    snprintf(pattern, sizeof(pattern), "\"%s\"", key);
    const char* pos = strstr(line, pattern);
    if (!pos) return NULL;
    pos = strchr(pos + strlen(pattern), ':');
    if (!pos) return NULL;
    pos++;
    while (isspace((unsigned char)*pos)) pos++;
    if (*pos != '"') return NULL;
    pos++;
    size_t i = 0;
    while (*pos && *pos != '"' && i + 1 < sizeof(buffer)) {
        buffer[i++] = *pos++;
    }
    buffer[i] = '\0';
    return buffer;
}

static int json_find_int(const char* line, const char* key, int def) {
    char pattern[32];
    snprintf(pattern, sizeof(pattern), "\"%s\"", key);
    const char* pos = strstr(line, pattern);
    if (!pos) return def;
    pos = strchr(pos + strlen(pattern), ':');
    if (!pos) return def;
    pos++;
    while (isspace((unsigned char)*pos)) pos++;
    return (int)strtol(pos, NULL, 10);
}

static bool parse_line(const char* line, CtlEvent* evt) {
    const char* type = json_find_string(line, "type");
    if (!type) {
        return false;
    }
    memset(evt, 0, sizeof(*evt));
    if (strcmp(type, "SetAmount") == 0) {
        evt->type = CTL_EVENT_SET_AMOUNT;
        evt->amount_cents = json_find_int(line, "amount", 0);
        evt->currency = json_find_string(line, "currency");
    } else if (strcmp(type, "CardData") == 0) {
        evt->type = CTL_EVENT_CARD_DATA;
        evt->emv_ok = json_find_int(line, "emvOk", 1) != 0;
    } else if (strcmp(type, "PinEntered") == 0) {
        evt->type = CTL_EVENT_PIN_ENTERED;
    } else if (strcmp(type, "BankResponse") == 0) {
        evt->type = CTL_EVENT_BANK_RESPONSE;
        evt->approved = json_find_int(line, "approved", 1) != 0;
    } else if (strcmp(type, "Cancel") == 0) {
        evt->type = CTL_EVENT_CANCEL;
    } else if (strcmp(type, "Heartbeat") == 0) {
        evt->type = CTL_EVENT_HEARTBEAT;
        evt->network_ok = json_find_int(line, "network", 1) != 0;
        evt->power_ok = json_find_int(line, "power", 1) != 0;
    } else if (strcmp(type, "UpdateRequest") == 0) {
        evt->type = CTL_EVENT_UPDATE_REQUEST;
        evt->role = json_find_string(line, "role");
    } else if (strcmp(type, "UpdatePayload") == 0) {
        evt->type = CTL_EVENT_UPDATE_PAYLOAD;
        evt->update_version = json_find_string(line, "version");
        evt->update_size = (size_t)json_find_int(line, "size", 0);
        evt->chunk_index = (size_t)json_find_int(line, "chunk", 1);
        evt->chunk_total = (size_t)json_find_int(line, "chunks", 1);
        evt->signature_ok = json_find_int(line, "sig", 1) != 0;
    } else if (strcmp(type, "UpdateVerify") == 0) {
        evt->type = CTL_EVENT_UPDATE_VERIFY;
        evt->signature_ok = json_find_int(line, "sig", 1) != 0;
    } else if (strcmp(type, "UpdateInstall") == 0) {
        evt->type = CTL_EVENT_UPDATE_INSTALL;
        evt->install_ok = json_find_int(line, "ok", 1) != 0;
    } else {
        log_ts("EventChannel: unknown type '%s'", type);
        return false;
    }
    return true;
}

bool ctl_event_channel_next(CtlEvent* evt) {
    if (input_eof || !evt) {
        return false;
    }
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        if (parse_line(line, evt)) {
            return true;
        }
    }
    input_eof = true;
    return false;
}
