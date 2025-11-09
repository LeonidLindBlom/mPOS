#ifndef CONTROLSYS_SERVICES_UPDATE_STORAGE_H
#define CONTROLSYS_SERVICES_UPDATE_STORAGE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    const char* version;
    size_t total_size;
    bool complete;
} UpdateSlot;

void update_storage_reset(void);
bool update_storage_append(const char* version,
                           size_t chunk_size,
                           size_t chunk_index,
                           size_t chunk_total);
bool update_storage_snapshot(UpdateSlot* slot);

#endif /* CONTROLSYS_SERVICES_UPDATE_STORAGE_H */
