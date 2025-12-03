#include "controlsys/services/net_verifier.h"
#include "controlsys/services/power_verifier.h"
#include "controlsys/services/init_module.h"
#include "controlsys/log.h"
#include "controlsys/ipc_transport.h"

#define NK_USE_UNQUALIFIED_NAMES
#include <controlsys/InputGuardInterface.idl.h>
#include <controlsys/InputGuard.edl.h>

static InputGuardInterface Heartbeat_iface;

nk_err_t HeartbeatImpl(struct InputGuardInterface *self,
                       const InputGuardInterface_Heartbeat_req *req,
                       const struct nk_arena *reqArena,
                       InputGuardInterface_Heartbeat_res *res,
                       struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;

    NetSample net = {
        .link_up = req->networkOk,
        .ping_ok = req->pingOk,
        .signal_strength = req->signalStrength,
        .heartbeat_seq = 0,
    };
    bool net_ok = net_verifier_submit(&net);

    PowerSample power = {
        .sensor_ok = req->powerOk,
        .millivolts = 3800,
        .state_of_charge = req->soc,
        .discharge_rate = 1,
    };
    bool power_ok = power_verifier_submit(&power);

    init_module_update(power_ok, power_verifier_status(),
                       net_ok, net_verifier_status());
    res->powerReady = power_ok;
    res->networkReady = net_ok;
    return NK_EOK;
}

nk_err_t BeginTransactionImpl(struct InputGuardInterface *self,
                              const InputGuardInterface_BeginTransaction_req *req,
                              const struct nk_arena *reqArena,
                              InputGuardInterface_BeginTransaction_res *res,
                              struct nk_arena *resArena) {
    (void)self; (void)reqArena; (void)resArena;
    InitDecision decision;
    bool allowed = init_module_can_start(&decision);
    res->allowed = allowed;
    if (allowed) {
        init_module_mark_start("remote");
    }
    return NK_EOK;
}

int main(void) {
    net_verifier_reset();
    power_verifier_reset();
    init_module_reset();

    InputGuardInterface_ops ops = {
        .Heartbeat = HeartbeatImpl,
        .BeginTransaction = BeginTransactionImpl,
    };
    Heartbeat_iface.ops = &ops;

    NkKosTransport transport;
    controlsys_listen(CTRL_CONN_INPUTGUARD, &transport);

    InputGuard_entity entity;
    InputGuard_entity_init(&entity, &Heartbeat_iface);

    InputGuard_entity_req req;
    InputGuard_entity_res res;
    char req_buf[InputGuard_entity_req_arena_size];
    char res_buf[InputGuard_entity_res_arena_size];
    struct nk_arena reqArena = NK_ARENA_INITIALIZER(req_buf, req_buf + sizeof(req_buf));
    struct nk_arena resArena = NK_ARENA_INITIALIZER(res_buf, res_buf + sizeof(res_buf));

    log_box("InputGuard", "started");
    while (1) {
        nk_req_reset(&req);
        nk_arena_reset(&reqArena);
        nk_arena_reset(&resArena);
        if (nk_transport_recv(&transport.base, &req.base_, &reqArena) == NK_EOK) {
            InputGuard_entity_dispatch(&entity, &req.base_, &reqArena,
                                       &res.base_, &resArena);
            nk_transport_reply(&transport.base, &res.base_, &resArena);
        }
    }
    return 0;
}
