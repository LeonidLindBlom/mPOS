#ifndef CONTROLSYS_IPC_TRANSPORT_H
#define CONTROLSYS_IPC_TRANSPORT_H

#include <coresrv/nk/transport-kos.h>
#include <nk/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    NkKosTransport transport;
    nk_iid_t riid;
} ControlSysChannel;

#define CTRL_CONN_INPUTGUARD "controlsys.inputguard"
#define CTRL_EP_INPUTGUARD   "controlsys.InputGuard.interface"
#define CTRL_CONN_OUTPUT     "controlsys.output"
#define CTRL_EP_OUTPUT       "controlsys.OutputController.interface"
#define CTRL_CONN_CARDVERIF  "controlsys.cardverif"
#define CTRL_EP_CARDVERIF    "controlsys.CardVerifier.interface"
#define CTRL_CONN_TXN        "controlsys.txn"
#define CTRL_EP_TXN          "controlsys.TransactionGenerator.interface"
#define CTRL_CONN_STATUS     "controlsys.statusverif"
#define CTRL_EP_STATUS       "controlsys.StatusVerifier.interface"
#define CTRL_CONN_AUTH       "controlsys.auth"
#define CTRL_EP_AUTH         "controlsys.AuthModule.interface"
#define CTRL_CONN_JOURNAL    "controlsys.journal"
#define CTRL_EP_JOURNAL      "controlsys.Journal.interface"
#define CTRL_CONN_UPDATE_LOADER    "controlsys.update_loader"
#define CTRL_EP_UPDATE_LOADER      "controlsys.UpdateLoader.interface"
#define CTRL_CONN_UPDATE_STORAGE   "controlsys.update_storage"
#define CTRL_EP_UPDATE_STORAGE     "controlsys.UpdateStorage.interface"
#define CTRL_CONN_UPDATE_VERIFIER  "controlsys.update_verifier"
#define CTRL_EP_UPDATE_VERIFIER    "controlsys.UpdateVerifier.interface"
#define CTRL_CONN_UPDATE_INSTALLER "controlsys.update_installer"
#define CTRL_EP_UPDATE_INSTALLER   "controlsys.UpdateInstaller.interface"

void controlsys_connect(const char* connection, const char* endpoint, ControlSysChannel* channel);
void controlsys_listen(const char* connection, NkKosTransport* transport);

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_IPC_TRANSPORT_H */
