#include "controlsys/services/update_loader.h"
#include "controlsys/services/update_storage.h"
#include "controlsys/services/auth_module.h"
#include "controlsys/log.h"

static bool g_loader_active = false;

bool update_loader_begin(const char* requester_role) {
    if (!auth_check_operator(requester_role)) {
        log_ts("UpdateLoader: requester '%s' rejected", requester_role ? requester_role : "unknown");
        return false;
    }
    g_loader_active = true;
    update_storage_reset();
    log_ts("UpdateLoader: begin session by %s", requester_role);
    return true;
}

bool update_loader_push_chunk(const char* version,
                              size_t chunk_index,
                              size_t chunk_total,
                              size_t chunk_size,
                              bool signature_hint_ok) {
    if (!g_loader_active) {
        log_ts("UpdateLoader: chunk ignored (inactive)");
        return false;
    }
    if (!version || chunk_total == 0) {
        log_ts("UpdateLoader: invalid chunk metadata");
        return false;
    }
    log_ts("UpdateLoader: chunk %zu/%zu size=%zu from bank (sig=%s)",
           chunk_index, chunk_total, chunk_size, signature_hint_ok ? "ok" : "warn");
    return update_storage_append(version, chunk_size, chunk_index, chunk_total);
}

bool update_loader_finalize(void) {
    if (!g_loader_active) {
        log_ts("UpdateLoader: finalize ignored (inactive)");
        return false;
    }
    g_loader_active = false;
    log_ts("UpdateLoader: session closed");
    return true;
}
