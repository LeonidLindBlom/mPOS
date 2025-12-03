#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef ____UInt8__RAWTYPE__
#define ____UInt8__RAWTYPE__
nk_static_assert(sizeof(nk_uint8_t) == 1, bad_nk_uint8_t_size);
nk_static_assert(nk_alignof(nk_uint8_t) == 1, bad_nk_uint8_t_align);

#endif /* ____UInt8__RAWTYPE__ */

#ifndef __controlsys__AuthInterface__INTERFACE__
#define __controlsys__AuthInterface__INTERFACE__
enum {
    controlsys_AuthInterface_CheckRole_mid,
    controlsys_AuthInterface_mid_max,
};
enum {
    controlsys_AuthInterface_CheckRole_req_role_size =
    17,
    controlsys_AuthInterface_CheckRole_req_arena_size =
    17,
    controlsys_AuthInterface_CheckRole_res_arena_size =
    0,
    controlsys_AuthInterface_CheckRole_req_handles =
    0,
    controlsys_AuthInterface_CheckRole_res_handles =
    0,
    controlsys_AuthInterface_CheckRole_err_handles =
    0,
    controlsys_AuthInterface_req_arena_size = 17,
    controlsys_AuthInterface_res_arena_size = 0,
    controlsys_AuthInterface_arena_size = 17,
    controlsys_AuthInterface_req_handles = 0,
    controlsys_AuthInterface_res_handles = 0,
    controlsys_AuthInterface_err_handles = 0,
};
typedef struct __nk_packed controlsys_AuthInterface_CheckRole_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t role;
        } controlsys_AuthInterface_CheckRole_req;
#pragma pack(push, 8) /* controlsys_AuthInterface_CheckRole_res */
typedef struct controlsys_AuthInterface_CheckRole_err {
            __nk_alignas(8)
            struct nk_message base_;
        } controlsys_AuthInterface_CheckRole_err;
typedef struct controlsys_AuthInterface_CheckRole_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t accepted;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t accepted;
                } res_;
                struct controlsys_AuthInterface_CheckRole_err err_;
            };
        } controlsys_AuthInterface_CheckRole_res;
#pragma pack(pop) /* controlsys_AuthInterface_CheckRole_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_CheckRole_mid controlsys_AuthInterface_CheckRole_mid
#define AuthInterface_mid_max controlsys_AuthInterface_mid_max
#define AuthInterface_CheckRole_req_role_size controlsys_AuthInterface_CheckRole_req_role_size
#define AuthInterface_CheckRole_req_arena_size controlsys_AuthInterface_CheckRole_req_arena_size
#define AuthInterface_CheckRole_res_arena_size controlsys_AuthInterface_CheckRole_res_arena_size
#define AuthInterface_CheckRole_req_handles controlsys_AuthInterface_CheckRole_req_handles
#define AuthInterface_CheckRole_res_handles controlsys_AuthInterface_CheckRole_res_handles
#define AuthInterface_CheckRole_err_handles controlsys_AuthInterface_CheckRole_err_handles
#define AuthInterface_req_arena_size controlsys_AuthInterface_req_arena_size
#define AuthInterface_res_arena_size controlsys_AuthInterface_res_arena_size
#define AuthInterface_arena_size controlsys_AuthInterface_arena_size
#define AuthInterface_req_handles controlsys_AuthInterface_req_handles
#define AuthInterface_res_handles controlsys_AuthInterface_res_handles
#define AuthInterface_err_handles controlsys_AuthInterface_err_handles
#define AuthInterface_CheckRole_req controlsys_AuthInterface_CheckRole_req
#define AuthInterface_CheckRole_res controlsys_AuthInterface_CheckRole_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__INTERFACE__ */

#ifndef __controlsys__AuthModule__COMPONENT_ENDPOINTS__
#define __controlsys__AuthModule__COMPONENT_ENDPOINTS__
enum {
    controlsys_AuthModule_interface_iid,
    controlsys_AuthModule_iidMax,
};
enum {
    controlsys_AuthModule_iidOffset = 0,
};
enum {
    controlsys_AuthModule_securityIidMax,
};
enum {
    controlsys_AuthModule_component_req_arena_size =
    17,
    controlsys_AuthModule_component_res_arena_size =
    0,
    controlsys_AuthModule_component_arena_size =
    17,
    controlsys_AuthModule_component_req_handles =
    0,
    controlsys_AuthModule_component_res_handles =
    0,
    controlsys_AuthModule_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthModule_interface_iid controlsys_AuthModule_interface_iid
#define AuthModule_iidMax controlsys_AuthModule_iidMax
#define AuthModule_iidOffset controlsys_AuthModule_iidOffset
#define AuthModule_securityIidMax controlsys_AuthModule_securityIidMax
#define AuthModule_component_req_arena_size controlsys_AuthModule_component_req_arena_size
#define AuthModule_component_res_arena_size controlsys_AuthModule_component_res_arena_size
#define AuthModule_component_arena_size controlsys_AuthModule_component_arena_size
#define AuthModule_component_req_handles controlsys_AuthModule_component_req_handles
#define AuthModule_component_res_handles controlsys_AuthModule_component_res_handles
#define AuthModule_component_err_handles controlsys_AuthModule_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthModule__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__AuthModule__TASK_ENDPOINTS__
#define __controlsys__AuthModule__TASK_ENDPOINTS__
enum {
    controlsys_AuthModule_entity_req_arena_size =
    controlsys_AuthModule_component_req_arena_size,
    controlsys_AuthModule_entity_res_arena_size =
    controlsys_AuthModule_component_res_arena_size,
    controlsys_AuthModule_entity_arena_size =
    controlsys_AuthModule_component_arena_size,
    controlsys_AuthModule_entity_req_handles =
    controlsys_AuthModule_component_req_handles,
    controlsys_AuthModule_entity_res_handles =
    controlsys_AuthModule_component_res_handles,
    controlsys_AuthModule_entity_err_handles =
    controlsys_AuthModule_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthModule_entity_req_arena_size controlsys_AuthModule_entity_req_arena_size
#define AuthModule_entity_res_arena_size controlsys_AuthModule_entity_res_arena_size
#define AuthModule_entity_arena_size controlsys_AuthModule_entity_arena_size
#define AuthModule_entity_req_handles controlsys_AuthModule_entity_req_handles
#define AuthModule_entity_res_handles controlsys_AuthModule_entity_res_handles
#define AuthModule_entity_err_handles controlsys_AuthModule_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthModule__TASK_ENDPOINTS__ */

#ifndef __controlsys__AuthInterface__VTABLE__
#define __controlsys__AuthInterface__VTABLE__
typedef struct controlsys_AuthInterface {
            const
            struct controlsys_AuthInterface_ops *ops;
        } controlsys_AuthInterface;
typedef nk_err_t
controlsys_AuthInterface_CheckRole_fn(struct controlsys_AuthInterface *,
                                      const
                                      struct controlsys_AuthInterface_CheckRole_req *,
                                      const
                                      struct nk_arena *,
                                      struct controlsys_AuthInterface_CheckRole_res *,
                                      struct nk_arena *);
typedef struct controlsys_AuthInterface_ops {
            controlsys_AuthInterface_CheckRole_fn *CheckRole;
        } controlsys_AuthInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_CheckRole_fn controlsys_AuthInterface_CheckRole_fn
#define AuthInterface_ops controlsys_AuthInterface_ops
#define AuthInterface controlsys_AuthInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__VTABLE__ */

#ifndef __controlsys__AuthInterface__SERVER__
#define __controlsys__AuthInterface__SERVER__
typedef union controlsys_AuthInterface_req {
            struct nk_message base_;
            struct controlsys_AuthInterface_CheckRole_req CheckRole;
        } controlsys_AuthInterface_req;
typedef union controlsys_AuthInterface_res {
            struct nk_message base_;
            struct controlsys_AuthInterface_CheckRole_res CheckRole;
        } controlsys_AuthInterface_res;
static inline
nk_err_t controlsys_AuthInterface_interface_dispatch(struct controlsys_AuthInterface *impl,
                                                     nk_iid_t iid,
                                                     const
                                                     struct nk_message *req,
                                                     const
                                                     struct nk_arena *req_arena,
                                                     struct nk_message *res,
                                                     struct nk_arena *res_arena)
{
    nk_err_t rc = NK_ENOENT;
    nk_iid_t req_iid;
    nk_mid_t req_mid;
    
    nk_assert(impl != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_unused(impl);
    nk_unused(req_arena);
    nk_unused(res_arena);
    if (req->iid == iid) {
        req_iid = req->iid;
        req_mid = req->mid;
        switch (req->mid) {
            
          case controlsys_AuthInterface_CheckRole_mid:
            {
                struct controlsys_AuthInterface_CheckRole_res
                *res_ =
                (struct controlsys_AuthInterface_CheckRole_res *) res;
                
                rc = impl->ops->CheckRole(impl,
                                          (const
                                           struct controlsys_AuthInterface_CheckRole_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_AuthInterface_CheckRole_res_handles);
                }
                break;
            }
            
          default:
            ;
        }
        res->iid = req_iid;
        res->mid = req_mid;
    }
    return rc;
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_req controlsys_AuthInterface_req
#define AuthInterface_res controlsys_AuthInterface_res
#define AuthInterface_interface_dispatch controlsys_AuthInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__SERVER__ */

#ifndef __controlsys__AuthModule__COMPONENT_SERVER_TYPES__
#define __controlsys__AuthModule__COMPONENT_SERVER_TYPES__
typedef struct controlsys_AuthModule_component {
            struct controlsys_AuthInterface *interface;
        } controlsys_AuthModule_component;

#endif /* __controlsys__AuthModule__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__AuthModule__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__AuthModule__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_AuthModule_component_init(struct controlsys_AuthModule_component *self,
                                          struct controlsys_AuthInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_AuthModule_component_req {
            struct nk_message base_;
            controlsys_AuthInterface_req interface;
        } controlsys_AuthModule_component_req;
typedef union controlsys_AuthModule_component_res {
            struct nk_message base_;
            controlsys_AuthInterface_res interface;
        } controlsys_AuthModule_component_res;
static inline
nk_err_t controlsys_AuthModule_component_dispatch(struct controlsys_AuthModule_component *self,
                                                  nk_iid_t iidOffset,
                                                  const
                                                  struct nk_message *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct nk_message *res,
                                                  struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_unused(self);
    nk_unused(req_arena);
    nk_unused(res);
    nk_unused(res_arena);
    if (req->iid < iidOffset)
        return NK_ENOENT;
    switch (req->iid - iidOffset) {
        
      case controlsys_AuthModule_interface_iid:
        return controlsys_AuthInterface_interface_dispatch(self->interface,
                                                           req->iid,
                                                           req,
                                                           req_arena,
                                                           res,
                                                           res_arena);
        
      default:
        ;
    }
    return NK_ENOENT;
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthModule_component controlsys_AuthModule_component
#define AuthModule_component_init controlsys_AuthModule_component_init
#define AuthModule_component_req controlsys_AuthModule_component_req
#define AuthModule_component_res controlsys_AuthModule_component_res
#define AuthModule_component_dispatch controlsys_AuthModule_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthModule__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__AuthModule__ENTITY_SERVER__
#define __controlsys__AuthModule__ENTITY_SERVER__
#define controlsys_AuthModule_entity_res controlsys_AuthModule_component_res
#define controlsys_AuthModule_entity_req controlsys_AuthModule_component_req
#define controlsys_AuthModule_entity controlsys_AuthModule_component
static inline
void controlsys_AuthModule_entity_init(struct controlsys_AuthModule_entity *self,
                                       struct controlsys_AuthInterface *interface)
{
    controlsys_AuthModule_component_init(self,
                                         interface);
}
static inline
nk_err_t controlsys_AuthModule_entity_dispatch(struct controlsys_AuthModule_entity *self,
                                               const
                                               struct nk_message *req,
                                               const
                                               struct nk_arena *req_arena,
                                               struct nk_message *res,
                                               struct nk_arena *res_arena)
{
    return controlsys_AuthModule_component_dispatch(self,
                                                    0,
                                                    req,
                                                    req_arena,
                                                    res,
                                                    res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthModule_entity controlsys_AuthModule_entity
#define AuthModule_entity_init controlsys_AuthModule_entity_init
#define AuthModule_entity_req controlsys_AuthModule_entity_req
#define AuthModule_entity_res controlsys_AuthModule_entity_res
#define AuthModule_entity_dispatch controlsys_AuthModule_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthModule__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

