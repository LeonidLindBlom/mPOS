#include "controlsys/event_channel.h"
#include "controlsys/log.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CTL_EVENT_BUFFER 512

static int event_fd = -1;
static char rx_buffer[CTL_EVENT_BUFFER];
static size_t rx_len = 0;

static const char* json_find_string(const char* line, const char* key);
static int json_find_int(const char* line, const char* key, int def);
static bool parse_line(const char* line, CtlEvent* evt);

void ctl_event_channel_init(void) {
    const char* env_path = getenv("CTL_EVENT_TTY");
    const char* candidates[] = {
        env_path && *env_path ? env_path : NULL,
        "/dev/ttyAMA1",
        "/dev/ttyS1",
        "/dev/ttyAMA0",
        "/dev/ttyS0",
        NULL
    };

    for (size_t i = 0; i < sizeof(candidates) / sizeof(candidates[0]); ++i) {
        const char* path = candidates[i];
        if (!path || !*path) {
            continue;
        }
        event_fd = open(path, O_RDWR | O_NONBLOCK);
        if (event_fd >= 0) {
            log_ts("EventChannel: читаю события из '%s'", path);
            rx_len = 0;
            return;
        }
        log_ts("EventChannel: не удалось открыть '%s' (errno=%d)", path, errno);
    }

    event_fd = STDIN_FILENO;
    rx_len = 0;
    log_ts("EventChannel: читаю события из stdin");
}

bool ctl_event_channel_available(void) {
    return event_fd >= 0;
}

static bool read_line(char* out, size_t out_sz) {
    if (event_fd < 0) {
        return false;
    }

    for (size_t i = 0; i < rx_len; ++i) {
        if (rx_buffer[i] == '\n') {
            size_t line_len = (i < out_sz - 1) ? i : (out_sz - 1);
            memcpy(out, rx_buffer, line_len);
            out[line_len] = '\0';

            size_t remaining = rx_len - (i + 1);
            memmove(rx_buffer, rx_buffer + i + 1, remaining);
            rx_len = remaining;
            return true;
        }
    }

    if (rx_len >= sizeof(rx_buffer) - 1) {
        log_ts("EventChannel: входная строка слишком длинная, сбрасываю буфер");
        rx_len = 0;
    }

    ssize_t n = read(event_fd, rx_buffer + rx_len, sizeof(rx_buffer) - rx_len - 1);
    if (n > 0) {
        rx_len += (size_t)n;
        return read_line(out, out_sz);
    }
    if (n == 0) {
        return false;
    }
    if (errno != EAGAIN && errno != EWOULDBLOCK && errno != EINTR) {
        log_ts("EventChannel: read() failed (errno=%d)", errno);
    }
    return false;
}

bool ctl_event_channel_next(CtlEvent* evt) {
    if (!evt || event_fd < 0) {
        return false;
    }

    char line[256];
    if (!read_line(line, sizeof(line))) {
        return false;
    }

    if (parse_line(line, evt)) {
        return true;
    }

    log_ts("EventChannel: не удалось распарсить событие '%s'", line);
    return false;
}

static const char* json_find_string(const char* line, const char* key) {
    enum { SLOT_COUNT = 4, SLOT_SIZE = 128 };
    static char slots[SLOT_COUNT][SLOT_SIZE];
    static size_t next_slot = 0;
    char* buffer = slots[next_slot++ % SLOT_COUNT];
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
    evt->network_ok = true;
    evt->ping_ok = true;
    evt->power_ok = true;
    evt->network_signal = 80;
    evt->power_mv = 3800;
    evt->power_soc = 80;
    evt->power_rate = 1;
    if (strcmp(type, "SetAmount") == 0) {
        evt->type = CTL_EVENT_SET_AMOUNT;
        evt->amount_cents = json_find_int(line, "amount", 0);
        evt->currency = json_find_string(line, "currency");
    } else if (strcmp(type, "CardData") == 0) {
        evt->type = CTL_EVENT_CARD_DATA;
        evt->emv_ok = json_find_int(line, "emvOk", 1) != 0;
        evt->pan = json_find_string(line, "pan");
        evt->expiry = json_find_string(line, "expiry");
        evt->cardholder = json_find_string(line, "holder");
    } else if (strcmp(type, "PinEntered") == 0) {
        evt->type = CTL_EVENT_PIN_ENTERED;
    } else if (strcmp(type, "BankResponse") == 0) {
        evt->type = CTL_EVENT_BANK_RESPONSE;
        evt->approved = json_find_int(line, "approved", 1) != 0;
        evt->bank_seq = (unsigned)json_find_int(line, "seq", 0);
        evt->bank_latency_ms = json_find_int(line, "latency", 0);
    } else if (strcmp(type, "Cancel") == 0) {
        evt->type = CTL_EVENT_CANCEL;
    } else if (strcmp(type, "Heartbeat") == 0) {
        evt->type = CTL_EVENT_HEARTBEAT;
        evt->network_ok = json_find_int(line, "network", 1) != 0;
        evt->power_ok = json_find_int(line, "power", 1) != 0;
        evt->ping_ok = json_find_int(line, "ping", evt->network_ok ? 1 : 0) != 0;
        evt->heartbeat_seq = (unsigned)json_find_int(line, "seq", 0);
        evt->network_signal = json_find_int(line, "signal", 80);
        evt->power_mv = json_find_int(line, "mv", 3800);
        evt->power_soc = json_find_int(line, "soc", evt->power_ok ? 80 : 5);
        evt->power_rate = json_find_int(line, "droop", 1);
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
    } else if (strcmp(type, "LogExportRequest") == 0) {
        evt->type = CTL_EVENT_LOG_EXPORT_REQUEST;
        evt->role = json_find_string(line, "role");
    } else if (strcmp(type, "LogExportData") == 0) {
        evt->type = CTL_EVENT_LOG_EXPORT_DATA;
        evt->note = json_find_string(line, "note");
    } else if (strcmp(type, "LogExportComplete") == 0) {
        evt->type = CTL_EVENT_LOG_EXPORT_COMPLETE;
        evt->note = json_find_string(line, "note");
    } else {
        log_ts("EventChannel: unknown type '%s'", type);
        return false;
    }
    return true;
}
