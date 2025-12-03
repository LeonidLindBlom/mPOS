#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
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

#ifndef __controlsys__StatusVerifierInterface__INTERFACE__
#define __controlsys__StatusVerifierInterface__INTERFACE__
enum {
    controlsys_StatusVerifierInterface_Validate_mid,
    controlsys_StatusVerifierInterface_mid_max,
};
enum {
    controlsys_StatusVerifierInterface_Validate_req_txId_size =
    49,
    controlsys_StatusVerifierInterface_Validate_req_arena_size =
    49,
    controlsys_StatusVerifierInterface_Validate_res_arena_size =
    0,
    controlsys_StatusVerifierInterface_Validate_req_handles =
    0,
    controlsys_StatusVerifierInterface_Validate_res_handles =
    0,
    controlsys_StatusVerifierInterface_Validate_err_handles =
    0,
    controlsys_StatusVerifierInterface_req_arena_size =
    49,
    controlsys_StatusVerifierInterface_res_arena_size =
    0,
    controlsys_StatusVerifierInterface_arena_size =
    49,
    controlsys_StatusVerifierInterface_req_handles =
    0,
    controlsys_StatusVerifierInterface_res_handles =
    0,
    controlsys_StatusVerifierInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_StatusVerifierInterface_Validate_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
            __nk_alignas(4) nk_uint32_t seqNumber;
            __nk_alignas(1) nk_uint8_t approved;
            __nk_alignas(4) nk_uint32_t latencyMs;
        }
controlsys_StatusVerifierInterface_Validate_req;
#pragma pack(push, 8) /* controlsys_StatusVerifierInterface_Validate_res */
typedef struct controlsys_StatusVerifierInterface_Validate_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_StatusVerifierInterface_Validate_err;
typedef struct controlsys_StatusVerifierInterface_Validate_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1) nk_uint8_t ok;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(1) nk_uint8_t ok;
                } res_;
                struct controlsys_StatusVerifierInterface_Validate_err err_;
            };
        }
controlsys_StatusVerifierInterface_Validate_res;
#pragma pack(pop) /* controlsys_StatusVerifierInterface_Validate_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifierInterface_Validate_mid controlsys_StatusVerifierInterface_Validate_mid
#define StatusVerifierInterface_mid_max controlsys_StatusVerifierInterface_mid_max
#define StatusVerifierInterface_Validate_req_txId_size controlsys_StatusVerifierInterface_Validate_req_txId_size
#define StatusVerifierInterface_Validate_req_arena_size controlsys_StatusVerifierInterface_Validate_req_arena_size
#define StatusVerifierInterface_Validate_res_arena_size controlsys_StatusVerifierInterface_Validate_res_arena_size
#define StatusVerifierInterface_Validate_req_handles controlsys_StatusVerifierInterface_Validate_req_handles
#define StatusVerifierInterface_Validate_res_handles controlsys_StatusVerifierInterface_Validate_res_handles
#define StatusVerifierInterface_Validate_err_handles controlsys_StatusVerifierInterface_Validate_err_handles
#define StatusVerifierInterface_req_arena_size controlsys_StatusVerifierInterface_req_arena_size
#define StatusVerifierInterface_res_arena_size controlsys_StatusVerifierInterface_res_arena_size
#define StatusVerifierInterface_arena_size controlsys_StatusVerifierInterface_arena_size
#define StatusVerifierInterface_req_handles controlsys_StatusVerifierInterface_req_handles
#define StatusVerifierInterface_res_handles controlsys_StatusVerifierInterface_res_handles
#define StatusVerifierInterface_err_handles controlsys_StatusVerifierInterface_err_handles
#define StatusVerifierInterface_Validate_req controlsys_StatusVerifierInterface_Validate_req
#define StatusVerifierInterface_Validate_res controlsys_StatusVerifierInterface_Validate_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifierInterface__INTERFACE__ */

#ifndef __controlsys__StatusVerifier__COMPONENT_ENDPOINTS__
#define __controlsys__StatusVerifier__COMPONENT_ENDPOINTS__
enum {
    controlsys_StatusVerifier_interface_iid,
    controlsys_StatusVerifier_iidMax,
};
enum {
    controlsys_StatusVerifier_iidOffset = 0,
};
enum {
    controlsys_StatusVerifier_securityIidMax,
};
enum {
    controlsys_StatusVerifier_component_req_arena_size =
    49,
    controlsys_StatusVerifier_component_res_arena_size =
    0,
    controlsys_StatusVerifier_component_arena_size =
    49,
    controlsys_StatusVerifier_component_req_handles =
    0,
    controlsys_StatusVerifier_component_res_handles =
    0,
    controlsys_StatusVerifier_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifier_interface_iid controlsys_StatusVerifier_interface_iid
#define StatusVerifier_iidMax controlsys_StatusVerifier_iidMax
#define StatusVerifier_iidOffset controlsys_StatusVerifier_iidOffset
#define StatusVerifier_securityIidMax controlsys_StatusVerifier_securityIidMax
#define StatusVerifier_component_req_arena_size controlsys_StatusVerifier_component_req_arena_size
#define StatusVerifier_component_res_arena_size controlsys_StatusVerifier_component_res_arena_size
#define StatusVerifier_component_arena_size controlsys_StatusVerifier_component_arena_size
#define StatusVerifier_component_req_handles controlsys_StatusVerifier_component_req_handles
#define StatusVerifier_component_res_handles controlsys_StatusVerifier_component_res_handles
#define StatusVerifier_component_err_handles controlsys_StatusVerifier_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifier__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__StatusVerifier__TASK_ENDPOINTS__
#define __controlsys__StatusVerifier__TASK_ENDPOINTS__
enum {
    controlsys_StatusVerifier_entity_req_arena_size =
    controlsys_StatusVerifier_component_req_arena_size,
    controlsys_StatusVerifier_entity_res_arena_size =
    controlsys_StatusVerifier_component_res_arena_size,
    controlsys_StatusVerifier_entity_arena_size =
    controlsys_StatusVerifier_component_arena_size,
    controlsys_StatusVerifier_entity_req_handles =
    controlsys_StatusVerifier_component_req_handles,
    controlsys_StatusVerifier_entity_res_handles =
    controlsys_StatusVerifier_component_res_handles,
    controlsys_StatusVerifier_entity_err_handles =
    controlsys_StatusVerifier_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifier_entity_req_arena_size controlsys_StatusVerifier_entity_req_arena_size
#define StatusVerifier_entity_res_arena_size controlsys_StatusVerifier_entity_res_arena_size
#define StatusVerifier_entity_arena_size controlsys_StatusVerifier_entity_arena_size
#define StatusVerifier_entity_req_handles controlsys_StatusVerifier_entity_req_handles
#define StatusVerifier_entity_res_handles controlsys_StatusVerifier_entity_res_handles
#define StatusVerifier_entity_err_handles controlsys_StatusVerifier_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifier__TASK_ENDPOINTS__ */

#ifndef __controlsys__StatusVerifierInterface__VTABLE__
#define __controlsys__StatusVerifierInterface__VTABLE__
typedef struct controlsys_StatusVerifierInterface {
            const
            struct controlsys_StatusVerifierInterface_ops *ops;
        } controlsys_StatusVerifierInterface;
typedef nk_err_t
controlsys_StatusVerifierInterface_Validate_fn(struct controlsys_StatusVerifierInterface *,
                                               const
                                               struct controlsys_StatusVerifierInterface_Validate_req *,
                                               const
                                               struct nk_arena *,
                                               struct controlsys_StatusVerifierInterface_Validate_res *,
                                               struct nk_arena *);
typedef struct controlsys_StatusVerifierInterface_ops {
            controlsys_StatusVerifierInterface_Validate_fn *Validate;
        } controlsys_StatusVerifierInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifierInterface_Validate_fn controlsys_StatusVerifierInterface_Validate_fn
#define StatusVerifierInterface_ops controlsys_StatusVerifierInterface_ops
#define StatusVerifierInterface controlsys_StatusVerifierInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifierInterface__VTABLE__ */

#ifndef __controlsys__StatusVerifierInterface__SERVER__
#define __controlsys__StatusVerifierInterface__SERVER__
typedef union controlsys_StatusVerifierInterface_req {
            struct nk_message base_;
            struct controlsys_StatusVerifierInterface_Validate_req Validate;
        } controlsys_StatusVerifierInterface_req;
typedef union controlsys_StatusVerifierInterface_res {
            struct nk_message base_;
            struct controlsys_StatusVerifierInterface_Validate_res Validate;
        } controlsys_StatusVerifierInterface_res;
static inline
nk_err_t controlsys_StatusVerifierInterface_interface_dispatch(struct controlsys_StatusVerifierInterface *impl,
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
            
          case controlsys_StatusVerifierInterface_Validate_mid:
            {
                struct controlsys_StatusVerifierInterface_Validate_res
                *res_ =
                (struct controlsys_StatusVerifierInterface_Validate_res *) res;
                
                rc = impl->ops->Validate(impl,
                                         (const
                                          struct controlsys_StatusVerifierInterface_Validate_req *) req,
                                         req_arena,
                                         res_,
                                         res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_StatusVerifierInterface_Validate_res_handles);
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
#define StatusVerifierInterface_req controlsys_StatusVerifierInterface_req
#define StatusVerifierInterface_res controlsys_StatusVerifierInterface_res
#define StatusVerifierInterface_interface_dispatch controlsys_StatusVerifierInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifierInterface__SERVER__ */

#ifndef __controlsys__StatusVerifier__COMPONENT_SERVER_TYPES__
#define __controlsys__StatusVerifier__COMPONENT_SERVER_TYPES__
typedef struct controlsys_StatusVerifier_component {
            struct controlsys_StatusVerifierInterface *interface;
        } controlsys_StatusVerifier_component;

#endif /* __controlsys__StatusVerifier__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__StatusVerifier__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__StatusVerifier__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_StatusVerifier_component_init(struct controlsys_StatusVerifier_component *self,
                                              struct controlsys_StatusVerifierInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_StatusVerifier_component_req {
            struct nk_message base_;
            controlsys_StatusVerifierInterface_req interface;
        } controlsys_StatusVerifier_component_req;
typedef union controlsys_StatusVerifier_component_res {
            struct nk_message base_;
            controlsys_StatusVerifierInterface_res interface;
        } controlsys_StatusVerifier_component_res;
static inline
nk_err_t controlsys_StatusVerifier_component_dispatch(struct controlsys_StatusVerifier_component *self,
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
        
      case controlsys_StatusVerifier_interface_iid:
        return controlsys_StatusVerifierInterface_interface_dispatch(self->interface,
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
#define StatusVerifier_component controlsys_StatusVerifier_component
#define StatusVerifier_component_init controlsys_StatusVerifier_component_init
#define StatusVerifier_component_req controlsys_StatusVerifier_component_req
#define StatusVerifier_component_res controlsys_StatusVerifier_component_res
#define StatusVerifier_component_dispatch controlsys_StatusVerifier_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifier__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__StatusVerifier__ENTITY_SERVER__
#define __controlsys__StatusVerifier__ENTITY_SERVER__
#define controlsys_StatusVerifier_entity_res controlsys_StatusVerifier_component_res
#define controlsys_StatusVerifier_entity_req controlsys_StatusVerifier_component_req
#define controlsys_StatusVerifier_entity controlsys_StatusVerifier_component
static inline
void controlsys_StatusVerifier_entity_init(struct controlsys_StatusVerifier_entity *self,
                                           struct controlsys_StatusVerifierInterface *interface)
{
    controlsys_StatusVerifier_component_init(self,
                                             interface);
}
static inline
nk_err_t controlsys_StatusVerifier_entity_dispatch(struct controlsys_StatusVerifier_entity *self,
                                                   const
                                                   struct nk_message *req,
                                                   const
                                                   struct nk_arena *req_arena,
                                                   struct nk_message *res,
                                                   struct nk_arena *res_arena)
{
    return controlsys_StatusVerifier_component_dispatch(self,
                                                        0,
                                                        req,
                                                        req_arena,
                                                        res,
                                                        res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifier_entity controlsys_StatusVerifier_entity
#define StatusVerifier_entity_init controlsys_StatusVerifier_entity_init
#define StatusVerifier_entity_req controlsys_StatusVerifier_entity_req
#define StatusVerifier_entity_res controlsys_StatusVerifier_entity_res
#define StatusVerifier_entity_dispatch controlsys_StatusVerifier_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifier__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

