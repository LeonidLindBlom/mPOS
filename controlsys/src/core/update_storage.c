#include "controlsys/services/update_storage.h"
#include "controlsys/log.h"

static UpdateSlot g_slot;

void update_storage_reset(void) {
    g_slot.version = NULL;
    g_slot.total_size = 0;
    g_slot.complete = false;
}

bool update_storage_append(const char* version,
                           size_t chunk_size,
                           size_t chunk_index,
                           size_t chunk_total) {
    if (!version || chunk_total == 0) {
        return false;
    }
    if (!g_slot.version) {
        g_slot.version = version;
    }
    g_slot.total_size += chunk_size;
    if (chunk_index == chunk_total) {
        g_slot.complete = true;
        log_box("UpdateStorage",
                "version %s\ntotal=%zu bytes",
                g_slot.version,
                g_slot.total_size);
    }
    return true;
}

bool update_storage_snapshot(UpdateSlot* slot) {
    if (!slot) {
        return false;
    }
    *slot = g_slot;
    return g_slot.complete;
}
