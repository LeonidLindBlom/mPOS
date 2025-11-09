#include "controlsys/services/update_installer.h"
#include "controlsys/log.h"

void update_installer_apply(const UpdateSlot* slot, bool install_ok) {
    if (!slot || !slot->complete) {
        log_ts("UpdateInstaller: slot not ready");
        return;
    }
    if (install_ok) {
        log_ts("UpdateInstaller: version %s installed (size=%zu)", slot->version, slot->total_size);
    } else {
        log_ts("UpdateInstaller: version %s install aborted", slot->version);
    }
}
