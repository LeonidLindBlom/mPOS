#include "clients.h"
#include "controlsys/ipc_transport.h"

#include <string.h>

void controlsys_clients_init(ControlSysClients* c) {
    memset(c, 0, sizeof(*c));
    controlsys_connect(CTRL_CONN_INPUTGUARD, CTRL_EP_INPUTGUARD, &c->inputguard);
    controlsys_connect(CTRL_CONN_OUTPUT, CTRL_EP_OUTPUT, &c->output);
    controlsys_connect(CTRL_CONN_CARDVERIF, CTRL_EP_CARDVERIF, &c->cardverif);
    controlsys_connect(CTRL_CONN_TXN, CTRL_EP_TXN, &c->txn);
    controlsys_connect(CTRL_CONN_STATUS, CTRL_EP_STATUS, &c->statusverif);
    controlsys_connect(CTRL_CONN_AUTH, CTRL_EP_AUTH, &c->auth);
    controlsys_connect(CTRL_CONN_JOURNAL, CTRL_EP_JOURNAL, &c->journal);
    controlsys_connect(CTRL_CONN_UPDATE_LOADER, CTRL_EP_UPDATE_LOADER, &c->update_loader);
    controlsys_connect(CTRL_CONN_UPDATE_STORAGE, CTRL_EP_UPDATE_STORAGE, &c->update_storage);
    controlsys_connect(CTRL_CONN_UPDATE_VERIFIER, CTRL_EP_UPDATE_VERIFIER, &c->update_verifier);
    controlsys_connect(CTRL_CONN_UPDATE_INSTALLER, CTRL_EP_UPDATE_INSTALLER, &c->update_installer);
}
