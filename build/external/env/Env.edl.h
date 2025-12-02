#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef __env__Env__COMPONENT_ENDPOINTS__
#define __env__Env__COMPONENT_ENDPOINTS__
enum {
    env_Env_iidMax,
};
enum {
    env_Env_iidOffset = 0,
};
enum {
    env_Env_securityIidMax,
};
enum {
    env_Env_component_req_arena_size = 0,
    env_Env_component_res_arena_size = 0,
    env_Env_component_arena_size = 0,
    env_Env_component_req_handles = 0,
    env_Env_component_res_handles = 0,
    env_Env_component_err_handles = 0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define Env_iidMax env_Env_iidMax
#define Env_iidOffset env_Env_iidOffset
#define Env_securityIidMax env_Env_securityIidMax
#define Env_component_req_arena_size env_Env_component_req_arena_size
#define Env_component_res_arena_size env_Env_component_res_arena_size
#define Env_component_arena_size env_Env_component_arena_size
#define Env_component_req_handles env_Env_component_req_handles
#define Env_component_res_handles env_Env_component_res_handles
#define Env_component_err_handles env_Env_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __env__Env__COMPONENT_ENDPOINTS__ */

#ifndef __env__Env__TASK_ENDPOINTS__
#define __env__Env__TASK_ENDPOINTS__
enum {
    env_Env_entity_req_arena_size =
    env_Env_component_req_arena_size,
    env_Env_entity_res_arena_size =
    env_Env_component_res_arena_size,
    env_Env_entity_arena_size =
    env_Env_component_arena_size,
    env_Env_entity_req_handles =
    env_Env_component_req_handles,
    env_Env_entity_res_handles =
    env_Env_component_res_handles,
    env_Env_entity_err_handles =
    env_Env_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define Env_entity_req_arena_size env_Env_entity_req_arena_size
#define Env_entity_res_arena_size env_Env_entity_res_arena_size
#define Env_entity_arena_size env_Env_entity_arena_size
#define Env_entity_req_handles env_Env_entity_req_handles
#define Env_entity_res_handles env_Env_entity_res_handles
#define Env_entity_err_handles env_Env_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __env__Env__TASK_ENDPOINTS__ */

#pragma GCC diagnostic pop

