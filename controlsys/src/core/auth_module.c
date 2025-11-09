#include "controlsys/services/auth_module.h"
#include "controlsys/log.h"
#include <string.h>

bool auth_check_operator(const char* role) {
    if (!role) {
        log_ts("Auth: missing role");
        return false;
    }
    bool ok = strcmp(role, "operator") == 0;
    log_ts("Auth: role=%s %s", role, ok ? "accepted" : "rejected");
    return ok;
}
