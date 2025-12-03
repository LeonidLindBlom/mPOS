#include "controlsys/services/update_loader.h"
#include "controlsys/log.h"

static bool g_loader_active = false;

bool update_loader_begin(const char* requester_role) {
    g_loader_active = true;
    log_box("UpdateLoader", "begin session by %s",
            requester_role ? requester_role : "unknown");
    return true;
}

bool update_loader_push_chunk(const char* version,
                              size_t chunk_index,
                              size_t chunk_total,
                              size_t chunk_size,
                              bool signature_hint_ok) {
    if (!g_loader_active) {
        log_box("UpdateLoader", "chunk ignored (inactive)");
        return false;
    }
    if (!version || chunk_total == 0) {
        log_box("UpdateLoader", "invalid chunk metadata");
        return false;
    }
    log_box("UpdateLoader",
            "chunk %zu/%zu\nsize=%zu\nsignature=%s\nversion=%s",
            chunk_index, chunk_total, chunk_size,
            signature_hint_ok ? "ok" : "warn",
            version);
    return true;
}

bool update_loader_finalize(void) {
    if (!g_loader_active) {
        log_box("UpdateLoader", "finalize ignored (inactive)");
        return false;
    }
    g_loader_active = false;
    log_box("UpdateLoader", "session closed");
    return true;
}
