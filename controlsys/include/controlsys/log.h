#ifndef CONTROLSYS_LOG_H
#define CONTROLSYS_LOG_H

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

void log_ts(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
void log_box(const char* module, const char* fmt, ...) __attribute__((format(printf, 2, 3)));

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_LOG_H */
