#ifndef CONTROLSYS_SERVICES_UPDATE_VERIFIER_H
#define CONTROLSYS_SERVICES_UPDATE_VERIFIER_H

#include <stdbool.h>
#include "controlsys/services/update_storage.h"

bool update_verifier_check(const UpdateSlot* slot, bool signature_ok_hint);

#endif /* CONTROLSYS_SERVICES_UPDATE_VERIFIER_H */
