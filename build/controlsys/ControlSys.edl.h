#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef __controlsys__ControlSys__COMPONENT_ENDPOINTS__
#define __controlsys__ControlSys__COMPONENT_ENDPOINTS__
enum {
    controlsys_ControlSys_iidMax,
};
enum {
    controlsys_ControlSys_iidOffset = 0,
};
enum {
    controlsys_ControlSys_securityIidMax,
};
enum {
    controlsys_ControlSys_component_req_arena_size =
    0,
    controlsys_ControlSys_component_res_arena_size =
    0,
    controlsys_ControlSys_component_arena_size =
    0,
    controlsys_ControlSys_component_req_handles =
    0,
    controlsys_ControlSys_component_res_handles =
    0,
    controlsys_ControlSys_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define ControlSys_iidMax controlsys_ControlSys_iidMax
#define ControlSys_iidOffset controlsys_ControlSys_iidOffset
#define ControlSys_securityIidMax controlsys_ControlSys_securityIidMax
#define ControlSys_component_req_arena_size controlsys_ControlSys_component_req_arena_size
#define ControlSys_component_res_arena_size controlsys_ControlSys_component_res_arena_size
#define ControlSys_component_arena_size controlsys_ControlSys_component_arena_size
#define ControlSys_component_req_handles controlsys_ControlSys_component_req_handles
#define ControlSys_component_res_handles controlsys_ControlSys_component_res_handles
#define ControlSys_component_err_handles controlsys_ControlSys_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__ControlSys__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__ControlSys__TASK_ENDPOINTS__
#define __controlsys__ControlSys__TASK_ENDPOINTS__
enum {
    controlsys_ControlSys_entity_req_arena_size =
    controlsys_ControlSys_component_req_arena_size,
    controlsys_ControlSys_entity_res_arena_size =
    controlsys_ControlSys_component_res_arena_size,
    controlsys_ControlSys_entity_arena_size =
    controlsys_ControlSys_component_arena_size,
    controlsys_ControlSys_entity_req_handles =
    controlsys_ControlSys_component_req_handles,
    controlsys_ControlSys_entity_res_handles =
    controlsys_ControlSys_component_res_handles,
    controlsys_ControlSys_entity_err_handles =
    controlsys_ControlSys_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define ControlSys_entity_req_arena_size controlsys_ControlSys_entity_req_arena_size
#define ControlSys_entity_res_arena_size controlsys_ControlSys_entity_res_arena_size
#define ControlSys_entity_arena_size controlsys_ControlSys_entity_arena_size
#define ControlSys_entity_req_handles controlsys_ControlSys_entity_req_handles
#define ControlSys_entity_res_handles controlsys_ControlSys_entity_res_handles
#define ControlSys_entity_err_handles controlsys_ControlSys_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__ControlSys__TASK_ENDPOINTS__ */

#pragma GCC diagnostic pop

