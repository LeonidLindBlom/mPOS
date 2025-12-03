#ifndef CONTROLSYS_CLIENTS_H
#define CONTROLSYS_CLIENTS_H

#include "controlsys/ipc_transport.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ControlSysClients {
    ControlSysChannel inputguard;
    ControlSysChannel output;
    ControlSysChannel cardverif;
    ControlSysChannel txn;
    ControlSysChannel statusverif;
    ControlSysChannel auth;
    ControlSysChannel journal;
    ControlSysChannel update_loader;
    ControlSysChannel update_storage;
    ControlSysChannel update_verifier;
    ControlSysChannel update_installer;
} ControlSysClients;

void controlsys_clients_init(ControlSysClients* c);

#ifdef __cplusplus
}
#endif

#endif
