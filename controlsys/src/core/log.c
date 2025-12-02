#include "controlsys/log.h"

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

void log_ts(const char* fmt, ...) {
    char ts_buf[64];
    time_t now = time(NULL);
    struct tm tm_buf;
    struct tm* tm_ptr = gmtime_r(&now, &tm_buf);
    if (!tm_ptr) {
        memset(ts_buf, 0, sizeof(ts_buf));
    } else {
        strftime(ts_buf, sizeof(ts_buf), "%Y-%m-%dT%H:%M:%SZ", tm_ptr);
    }

    va_list ap;
    va_start(ap, fmt);
    char msg_buf[256];
    vsnprintf(msg_buf, sizeof(msg_buf), fmt, ap);
    va_end(ap);

    fprintf(stderr, "[%s] %s\n", ts_buf, msg_buf);
    fflush(stderr);
}

void log_box(const char* module, const char* fmt, ...) {
    char payload[512];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(payload, sizeof(payload), fmt, ap);
    va_end(ap);

    const char* mod = (module && *module) ? module : "ControlSys";
    char title[96];
    snprintf(title, sizeof(title), "[%s]", mod);
    size_t title_len = strlen(title);

    const size_t MIN_INNER = 32;
    const size_t MAX_INNER = 78;

    size_t longest = 0;
    size_t current = 0;
    for (const char* p = payload;; ++p) {
        if (*p == '\n' || *p == '\0') {
            if (current > longest) {
                longest = current;
            }
            current = 0;
            if (*p == '\0') {
                break;
            }
        } else {
            current++;
        }
    }

    size_t inner = longest;
    if (inner < MIN_INNER) {
        inner = MIN_INNER;
    }
    if (inner < title_len) {
        inner = title_len;
    }
    if (inner > MAX_INNER) {
        inner = MAX_INNER;
    }

    size_t banner_width = inner + 2;
    if (banner_width < title_len) {
        banner_width = title_len;
    }
    size_t left = (banner_width > title_len) ? (banner_width - title_len) / 2 : 0;
    size_t right = banner_width - title_len - left;

    char top[128];
    size_t idx = 0;
    top[idx++] = '+';
    for (size_t i = 0; i < left; ++i) {
        top[idx++] = '=';
    }
    memcpy(top + idx, title, title_len);
    idx += title_len;
    for (size_t i = 0; i < right; ++i) {
        top[idx++] = '=';
    }
    top[idx++] = '+';
    top[idx] = '\0';
    log_ts("%s", top);

    if (payload[0] == '\0') {
        log_ts("| %-*s |", (int)inner, "");
    } else {
        const char* ptr = payload;
        while (*ptr) {
            const char* line_start = ptr;
            size_t len = 0;
            while (*ptr && *ptr != '\n') {
                ++ptr;
                ++len;
            }
            if (*ptr == '\n') {
                ++ptr;
            }
            if (len == 0) {
                log_ts("| %-*s |", (int)inner, "");
                continue;
            }
            size_t offset = 0;
            while (offset < len) {
                size_t chunk = len - offset;
                if (chunk > inner) {
                    chunk = inner;
                }
                log_ts("| %-*.*s |", (int)inner, (int)chunk, line_start + offset);
                offset += chunk;
            }
        }
    }

    char bottom[128];
    idx = 0;
    bottom[idx++] = '+';
    for (size_t i = 0; i < inner + 2; ++i) {
        bottom[idx++] = '-';
    }
    bottom[idx++] = '+';
    bottom[idx] = '\0';
    log_ts("%s", bottom);
}
