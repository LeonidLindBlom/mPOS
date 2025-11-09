#ifndef CONTROLSYS_SERVICES_UPDATE_INSTALLER_H
#define CONTROLSYS_SERVICES_UPDATE_INSTALLER_H

#include <stdbool.h>
#include "controlsys/services/update_storage.h"

void update_installer_apply(const UpdateSlot* slot, bool install_ok);

#endif /* CONTROLSYS_SERVICES_UPDATE_INSTALLER_H */
