#include "controlsys/log.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

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
