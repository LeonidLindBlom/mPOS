#include "controlsys/event_channel.h"
#include "controlsys/log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#ifndef CTL_EVENT_PORT
#define CTL_EVENT_PORT 28080
#endif

static int server_fd = -1;
static int client_fd = -1;

static int make_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) return -1;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void ctl_event_channel_init(void) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        log_ts("EventChannel: socket error %d", errno);
        return;
    }
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(CTL_EVENT_PORT);
    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        log_ts("EventChannel: bind error %d", errno);
        close(server_fd);
        server_fd = -1;
        return;
    }
    listen(server_fd, 2);
    make_nonblocking(server_fd);
    log_ts("EventChannel: listening on port %d", CTL_EVENT_PORT);
}

static ssize_t read_line(int fd, char* buf, size_t sz) {
    size_t i = 0;
    while (i + 1 < sz) {
        char c;
        ssize_t n = read(fd, &c, 1);
        if (n == 0) return 0;
        if (n < 0) {
            if (errno == EAGAIN || errno == EINTR) {
                return -2;
            }
            return -1;
        }
        if (c == '\n') break;
        buf[i++] = c;
    }
    buf[i] = '\0';
    return (ssize_t)i;
}

static const char* json_find_string(const char* line, const char* key);
static int json_find_int(const char* line, const char* key, int def);
static bool parse_line(const char* line, CtlEvent* evt);

bool ctl_event_channel_next(CtlEvent* evt) {
    if (!evt) return false;
    if (server_fd < 0) return false;

    if (client_fd < 0) {
        int fd = accept(server_fd, NULL, NULL);
        if (fd >= 0) {
            client_fd = fd;
            log_ts("EventChannel: client connected");
        } else {
            return false;
        }
    }

    char line[256];
    ssize_t n = read_line(client_fd, line, sizeof(line));
    if (n == 0) {
        close(client_fd);
        client_fd = -1;
        log_ts("EventChannel: client disconnected");
        return false;
    }
    if (n < 0) {
        return false;
    }
    if (parse_line(line, evt)) {
        return true;
    }
    return false;
}

// reuse parsing helpers from previous implementation

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
