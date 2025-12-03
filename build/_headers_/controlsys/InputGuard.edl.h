#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef ____UInt16__RAWTYPE__
#define ____UInt16__RAWTYPE__
nk_static_assert(sizeof(nk_uint16_t) == 2, bad_nk_uint16_t_size);
nk_static_assert(nk_alignof(nk_uint16_t) == 2, bad_nk_uint16_t_align);

#endif /* ____UInt16__RAWTYPE__ */

#ifndef ____UInt32__RAWTYPE__
#define ____UInt32__RAWTYPE__
nk_static_assert(sizeof(nk_uint32_t) == 4, bad_nk_uint32_t_size);
nk_static_assert(nk_alignof(nk_uint32_t) == 4, bad_nk_uint32_t_align);

#endif /* ____UInt32__RAWTYPE__ */

#ifndef ____UInt8__RAWTYPE__
#define ____UInt8__RAWTYPE__
nk_static_assert(sizeof(nk_uint8_t) == 1, bad_nk_uint8_t_size);
nk_static_assert(nk_alignof(nk_uint8_t) == 1, bad_nk_uint8_t_align);

#endif /* ____UInt8__RAWTYPE__ */

#ifndef __controlsys__InputGuardInterface__INTERFACE__
#define __controlsys__InputGuardInterface__INTERFACE__
enum {
    controlsys_InputGuardInterface_Heartbeat_mid,
    controlsys_InputGuardInterface_BeginTransaction_mid,
    controlsys_InputGuardInterface_mid_max,
};
enum {
    controlsys_InputGuardInterface_Heartbeat_req_arena_size =
    0,
    controlsys_InputGuardInterface_Heartbeat_res_arena_size =
    0,
    controlsys_InputGuardInterface_Heartbeat_req_handles =
    0,
    controlsys_InputGuardInterface_Heartbeat_res_handles =
    0,
    controlsys_InputGuardInterface_Heartbeat_err_handles =
    0,
    controlsys_InputGuardInterface_BeginTransaction_req_currency_size =
    9,
    controlsys_InputGuardInterface_BeginTransaction_req_arena_size =
    9,
    controlsys_InputGuardInterface_BeginTransaction_res_arena_size =
    0,
    controlsys_InputGuardInterface_BeginTransaction_req_handles =
    0,
    controlsys_InputGuardInterface_BeginTransaction_res_handles =
    0,
    controlsys_InputGuardInterface_BeginTransaction_err_handles =
    0,
    controlsys_InputGuardInterface_req_arena_size =
    9,
    controlsys_InputGuardInterface_res_arena_size =
    0,
    controlsys_InputGuardInterface_arena_size = 9,
    controlsys_InputGuardInterface_req_handles =
    0,
    controlsys_InputGuardInterface_res_handles =
    0,
    controlsys_InputGuardInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_InputGuardInterface_Heartbeat_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(1) nk_uint8_t networkOk;
            __nk_alignas(1) nk_uint8_t pingOk;
            __nk_alignas(1) nk_uint8_t powerOk;
            __nk_alignas(2)
            nk_uint16_t signalStrength;
            __nk_alignas(2) nk_uint16_t soc;
        }
controlsys_InputGuardInterface_Heartbeat_req;
#pragma pack(push, 8) /* controlsys_InputGuardInterface_Heartbeat_res */
typedef struct controlsys_InputGuardInterface_Heartbeat_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_InputGuardInterface_Heartbeat_err;
typedef struct controlsys_InputGuardInterface_Heartbeat_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t powerReady;
                    __nk_alignas(1)
                    nk_uint8_t networkReady;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t powerReady;
                    __nk_alignas(1)
                    nk_uint8_t networkReady;
                } res_;
                struct controlsys_InputGuardInterface_Heartbeat_err err_;
            };
        }
controlsys_InputGuardInterface_Heartbeat_res;
#pragma pack(pop) /* controlsys_InputGuardInterface_Heartbeat_res */
typedef struct __nk_packed controlsys_InputGuardInterface_BeginTransaction_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4)
            nk_uint32_t amountCents;
            __nk_alignas(4) nk_ptr_t currency;
        }
controlsys_InputGuardInterface_BeginTransaction_req;
#pragma pack(push, 8) /* controlsys_InputGuardInterface_BeginTransaction_res */
typedef struct controlsys_InputGuardInterface_BeginTransaction_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_InputGuardInterface_BeginTransaction_err;
typedef struct controlsys_InputGuardInterface_BeginTransaction_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t allowed;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1)
                    nk_uint8_t allowed;
                } res_;
                struct controlsys_InputGuardInterface_BeginTransaction_err err_;
            };
        }
controlsys_InputGuardInterface_BeginTransaction_res;
#pragma pack(pop) /* controlsys_InputGuardInterface_BeginTransaction_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuardInterface_Heartbeat_mid controlsys_InputGuardInterface_Heartbeat_mid
#define InputGuardInterface_BeginTransaction_mid controlsys_InputGuardInterface_BeginTransaction_mid
#define InputGuardInterface_mid_max controlsys_InputGuardInterface_mid_max
#define InputGuardInterface_Heartbeat_req_arena_size controlsys_InputGuardInterface_Heartbeat_req_arena_size
#define InputGuardInterface_Heartbeat_res_arena_size controlsys_InputGuardInterface_Heartbeat_res_arena_size
#define InputGuardInterface_Heartbeat_req_handles controlsys_InputGuardInterface_Heartbeat_req_handles
#define InputGuardInterface_Heartbeat_res_handles controlsys_InputGuardInterface_Heartbeat_res_handles
#define InputGuardInterface_Heartbeat_err_handles controlsys_InputGuardInterface_Heartbeat_err_handles
#define InputGuardInterface_BeginTransaction_req_currency_size controlsys_InputGuardInterface_BeginTransaction_req_currency_size
#define InputGuardInterface_BeginTransaction_req_arena_size controlsys_InputGuardInterface_BeginTransaction_req_arena_size
#define InputGuardInterface_BeginTransaction_res_arena_size controlsys_InputGuardInterface_BeginTransaction_res_arena_size
#define InputGuardInterface_BeginTransaction_req_handles controlsys_InputGuardInterface_BeginTransaction_req_handles
#define InputGuardInterface_BeginTransaction_res_handles controlsys_InputGuardInterface_BeginTransaction_res_handles
#define InputGuardInterface_BeginTransaction_err_handles controlsys_InputGuardInterface_BeginTransaction_err_handles
#define InputGuardInterface_req_arena_size controlsys_InputGuardInterface_req_arena_size
#define InputGuardInterface_res_arena_size controlsys_InputGuardInterface_res_arena_size
#define InputGuardInterface_arena_size controlsys_InputGuardInterface_arena_size
#define InputGuardInterface_req_handles controlsys_InputGuardInterface_req_handles
#define InputGuardInterface_res_handles controlsys_InputGuardInterface_res_handles
#define InputGuardInterface_err_handles controlsys_InputGuardInterface_err_handles
#define InputGuardInterface_Heartbeat_req controlsys_InputGuardInterface_Heartbeat_req
#define InputGuardInterface_Heartbeat_res controlsys_InputGuardInterface_Heartbeat_res
#define InputGuardInterface_BeginTransaction_req controlsys_InputGuardInterface_BeginTransaction_req
#define InputGuardInterface_BeginTransaction_res controlsys_InputGuardInterface_BeginTransaction_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuardInterface__INTERFACE__ */

#ifndef __controlsys__InputGuard__COMPONENT_ENDPOINTS__
#define __controlsys__InputGuard__COMPONENT_ENDPOINTS__
enum {
    controlsys_InputGuard_interface_iid,
    controlsys_InputGuard_iidMax,
};
enum {
    controlsys_InputGuard_iidOffset = 0,
};
enum {
    controlsys_InputGuard_securityIidMax,
};
enum {
    controlsys_InputGuard_component_req_arena_size =
    9,
    controlsys_InputGuard_component_res_arena_size =
    0,
    controlsys_InputGuard_component_arena_size =
    9,
    controlsys_InputGuard_component_req_handles =
    0,
    controlsys_InputGuard_component_res_handles =
    0,
    controlsys_InputGuard_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuard_interface_iid controlsys_InputGuard_interface_iid
#define InputGuard_iidMax controlsys_InputGuard_iidMax
#define InputGuard_iidOffset controlsys_InputGuard_iidOffset
#define InputGuard_securityIidMax controlsys_InputGuard_securityIidMax
#define InputGuard_component_req_arena_size controlsys_InputGuard_component_req_arena_size
#define InputGuard_component_res_arena_size controlsys_InputGuard_component_res_arena_size
#define InputGuard_component_arena_size controlsys_InputGuard_component_arena_size
#define InputGuard_component_req_handles controlsys_InputGuard_component_req_handles
#define InputGuard_component_res_handles controlsys_InputGuard_component_res_handles
#define InputGuard_component_err_handles controlsys_InputGuard_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuard__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__InputGuard__TASK_ENDPOINTS__
#define __controlsys__InputGuard__TASK_ENDPOINTS__
enum {
    controlsys_InputGuard_entity_req_arena_size =
    controlsys_InputGuard_component_req_arena_size,
    controlsys_InputGuard_entity_res_arena_size =
    controlsys_InputGuard_component_res_arena_size,
    controlsys_InputGuard_entity_arena_size =
    controlsys_InputGuard_component_arena_size,
    controlsys_InputGuard_entity_req_handles =
    controlsys_InputGuard_component_req_handles,
    controlsys_InputGuard_entity_res_handles =
    controlsys_InputGuard_component_res_handles,
    controlsys_InputGuard_entity_err_handles =
    controlsys_InputGuard_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuard_entity_req_arena_size controlsys_InputGuard_entity_req_arena_size
#define InputGuard_entity_res_arena_size controlsys_InputGuard_entity_res_arena_size
#define InputGuard_entity_arena_size controlsys_InputGuard_entity_arena_size
#define InputGuard_entity_req_handles controlsys_InputGuard_entity_req_handles
#define InputGuard_entity_res_handles controlsys_InputGuard_entity_res_handles
#define InputGuard_entity_err_handles controlsys_InputGuard_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuard__TASK_ENDPOINTS__ */

#ifndef __controlsys__InputGuardInterface__VTABLE__
#define __controlsys__InputGuardInterface__VTABLE__
typedef struct controlsys_InputGuardInterface {
            const
            struct controlsys_InputGuardInterface_ops *ops;
        } controlsys_InputGuardInterface;
typedef nk_err_t
controlsys_InputGuardInterface_Heartbeat_fn(struct controlsys_InputGuardInterface *,
                                            const
                                            struct controlsys_InputGuardInterface_Heartbeat_req *,
                                            const
                                            struct nk_arena *,
                                            struct controlsys_InputGuardInterface_Heartbeat_res *,
                                            struct nk_arena *);
typedef nk_err_t
controlsys_InputGuardInterface_BeginTransaction_fn(struct controlsys_InputGuardInterface *,
                                                   const
                                                   struct controlsys_InputGuardInterface_BeginTransaction_req *,
                                                   const
                                                   struct nk_arena *,
                                                   struct controlsys_InputGuardInterface_BeginTransaction_res *,
                                                   struct nk_arena *);
typedef struct controlsys_InputGuardInterface_ops {
            controlsys_InputGuardInterface_Heartbeat_fn *Heartbeat;
            controlsys_InputGuardInterface_BeginTransaction_fn *BeginTransaction;
        } controlsys_InputGuardInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuardInterface_Heartbeat_fn controlsys_InputGuardInterface_Heartbeat_fn
#define InputGuardInterface_BeginTransaction_fn controlsys_InputGuardInterface_BeginTransaction_fn
#define InputGuardInterface_ops controlsys_InputGuardInterface_ops
#define InputGuardInterface controlsys_InputGuardInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuardInterface__VTABLE__ */

#ifndef __controlsys__InputGuardInterface__SERVER__
#define __controlsys__InputGuardInterface__SERVER__
typedef union controlsys_InputGuardInterface_req {
            struct nk_message base_;
            struct controlsys_InputGuardInterface_Heartbeat_req Heartbeat;
            struct controlsys_InputGuardInterface_BeginTransaction_req BeginTransaction;
        } controlsys_InputGuardInterface_req;
typedef union controlsys_InputGuardInterface_res {
            struct nk_message base_;
            struct controlsys_InputGuardInterface_Heartbeat_res Heartbeat;
            struct controlsys_InputGuardInterface_BeginTransaction_res BeginTransaction;
        } controlsys_InputGuardInterface_res;
static inline
nk_err_t controlsys_InputGuardInterface_interface_dispatch(struct controlsys_InputGuardInterface *impl,
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
            
          case controlsys_InputGuardInterface_Heartbeat_mid:
            {
                struct controlsys_InputGuardInterface_Heartbeat_res
                *res_ =
                (struct controlsys_InputGuardInterface_Heartbeat_res *) res;
                
                rc = impl->ops->Heartbeat(impl,
                                          (const
                                           struct controlsys_InputGuardInterface_Heartbeat_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_InputGuardInterface_Heartbeat_res_handles);
                }
                break;
            }
            
          case controlsys_InputGuardInterface_BeginTransaction_mid:
            {
                struct controlsys_InputGuardInterface_BeginTransaction_res
                *res_ =
                (struct controlsys_InputGuardInterface_BeginTransaction_res *) res;
                
                rc =
                    impl->ops->BeginTransaction(impl,
                                                (const
                                                 struct controlsys_InputGuardInterface_BeginTransaction_req *) req,
                                                req_arena,
                                                res_,
                                                res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_InputGuardInterface_BeginTransaction_res_handles);
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
#define InputGuardInterface_req controlsys_InputGuardInterface_req
#define InputGuardInterface_res controlsys_InputGuardInterface_res
#define InputGuardInterface_interface_dispatch controlsys_InputGuardInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuardInterface__SERVER__ */

#ifndef __controlsys__InputGuard__COMPONENT_SERVER_TYPES__
#define __controlsys__InputGuard__COMPONENT_SERVER_TYPES__
typedef struct controlsys_InputGuard_component {
            struct controlsys_InputGuardInterface *interface;
        } controlsys_InputGuard_component;

#endif /* __controlsys__InputGuard__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__InputGuard__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__InputGuard__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_InputGuard_component_init(struct controlsys_InputGuard_component *self,
                                          struct controlsys_InputGuardInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_InputGuard_component_req {
            struct nk_message base_;
            controlsys_InputGuardInterface_req interface;
        } controlsys_InputGuard_component_req;
typedef union controlsys_InputGuard_component_res {
            struct nk_message base_;
            controlsys_InputGuardInterface_res interface;
        } controlsys_InputGuard_component_res;
static inline
nk_err_t controlsys_InputGuard_component_dispatch(struct controlsys_InputGuard_component *self,
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
        
      case controlsys_InputGuard_interface_iid:
        return controlsys_InputGuardInterface_interface_dispatch(self->interface,
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
#define InputGuard_component controlsys_InputGuard_component
#define InputGuard_component_init controlsys_InputGuard_component_init
#define InputGuard_component_req controlsys_InputGuard_component_req
#define InputGuard_component_res controlsys_InputGuard_component_res
#define InputGuard_component_dispatch controlsys_InputGuard_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuard__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__InputGuard__ENTITY_SERVER__
#define __controlsys__InputGuard__ENTITY_SERVER__
#define controlsys_InputGuard_entity_res controlsys_InputGuard_component_res
#define controlsys_InputGuard_entity_req controlsys_InputGuard_component_req
#define controlsys_InputGuard_entity controlsys_InputGuard_component
static inline
void controlsys_InputGuard_entity_init(struct controlsys_InputGuard_entity *self,
                                       struct controlsys_InputGuardInterface *interface)
{
    controlsys_InputGuard_component_init(self,
                                         interface);
}
static inline
nk_err_t controlsys_InputGuard_entity_dispatch(struct controlsys_InputGuard_entity *self,
                                               const
                                               struct nk_message *req,
                                               const
                                               struct nk_arena *req_arena,
                                               struct nk_message *res,
                                               struct nk_arena *res_arena)
{
    return controlsys_InputGuard_component_dispatch(self,
                                                    0,
                                                    req,
                                                    req_arena,
                                                    res,
                                                    res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuard_entity controlsys_InputGuard_entity
#define InputGuard_entity_init controlsys_InputGuard_entity_init
#define InputGuard_entity_req controlsys_InputGuard_entity_req
#define InputGuard_entity_res controlsys_InputGuard_entity_res
#define InputGuard_entity_dispatch controlsys_InputGuard_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuard__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

