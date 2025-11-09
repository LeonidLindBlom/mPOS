#ifndef CONTROLSYS_SERVICES_UPDATE_LOADER_H
#define CONTROLSYS_SERVICES_UPDATE_LOADER_H

#include <stddef.h>
#include <stdbool.h>

bool update_loader_begin(const char* requester_role);
bool update_loader_push_chunk(const char* version,
                              size_t chunk_index,
                              size_t chunk_total,
                              size_t chunk_size,
                              bool signature_hint_ok);
bool update_loader_finalize(void);

#endif /* CONTROLSYS_SERVICES_UPDATE_LOADER_H */
