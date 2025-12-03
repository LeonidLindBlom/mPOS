#include "controlsys/ipc_transport.h"

#include <coresrv/sl/sl_api.h>
#include <assert.h>
#include <stddef.h>

void controlsys_connect(const char* connection,
                        const char* endpoint,
                        ControlSysChannel* channel) {
    Handle handle = ServiceLocatorConnect(connection);
    assert(handle != INVALID_HANDLE);
    NkKosTransport_Init(&channel->transport, handle, NK_NULL, 0);
    channel->riid = ServiceLocatorGetRiid(handle, endpoint);
    assert(channel->riid != INVALID_RIID);
}

void controlsys_listen(const char* connection, NkKosTransport* transport) {
    ServiceId id;
    Handle handle = ServiceLocatorRegister(connection, NULL, 0, &id);
    assert(handle != INVALID_HANDLE);
    NkKosTransport_Init(transport, handle, NK_NULL, 0);
}
