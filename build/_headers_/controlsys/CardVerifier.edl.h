#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef ____UInt8__RAWTYPE__
#define ____UInt8__RAWTYPE__
nk_static_assert(sizeof(nk_uint8_t) == 1, bad_nk_uint8_t_size);
nk_static_assert(nk_alignof(nk_uint8_t) == 1, bad_nk_uint8_t_align);

#endif /* ____UInt8__RAWTYPE__ */

#ifndef __controlsys__CardVerifierInterface__INTERFACE__
#define __controlsys__CardVerifierInterface__INTERFACE__
enum {
    controlsys_CardVerifierInterface_CheckCard_mid,
    controlsys_CardVerifierInterface_mid_max,
};
enum {
    controlsys_CardVerifierInterface_CheckCard_req_panMasked_size =
    33,
    controlsys_CardVerifierInterface_CheckCard_req_expiry_size =
    9,
    controlsys_CardVerifierInterface_CheckCard_req_holder_size =
    33,
    controlsys_CardVerifierInterface_CheckCard_req_arena_size =
    75,
    controlsys_CardVerifierInterface_CheckCard_res_arena_size =
    0,
    controlsys_CardVerifierInterface_CheckCard_req_handles =
    0,
    controlsys_CardVerifierInterface_CheckCard_res_handles =
    0,
    controlsys_CardVerifierInterface_CheckCard_err_handles =
    0,
    controlsys_CardVerifierInterface_req_arena_size =
    75,
    controlsys_CardVerifierInterface_res_arena_size =
    0,
    controlsys_CardVerifierInterface_arena_size =
    75,
    controlsys_CardVerifierInterface_req_handles =
    0,
    controlsys_CardVerifierInterface_res_handles =
    0,
    controlsys_CardVerifierInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_CardVerifierInterface_CheckCard_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t panMasked;
            __nk_alignas(4) nk_ptr_t expiry;
            __nk_alignas(4) nk_ptr_t holder;
            __nk_alignas(1) nk_uint8_t emvOk;
        }
controlsys_CardVerifierInterface_CheckCard_req;
#pragma pack(push, 8) /* controlsys_CardVerifierInterface_CheckCard_res */
typedef struct controlsys_CardVerifierInterface_CheckCard_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_CardVerifierInterface_CheckCard_err;
typedef struct controlsys_CardVerifierInterface_CheckCard_res {
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
                struct controlsys_CardVerifierInterface_CheckCard_err err_;
            };
        }
controlsys_CardVerifierInterface_CheckCard_res;
#pragma pack(pop) /* controlsys_CardVerifierInterface_CheckCard_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_CheckCard_mid controlsys_CardVerifierInterface_CheckCard_mid
#define CardVerifierInterface_mid_max controlsys_CardVerifierInterface_mid_max
#define CardVerifierInterface_CheckCard_req_panMasked_size controlsys_CardVerifierInterface_CheckCard_req_panMasked_size
#define CardVerifierInterface_CheckCard_req_expiry_size controlsys_CardVerifierInterface_CheckCard_req_expiry_size
#define CardVerifierInterface_CheckCard_req_holder_size controlsys_CardVerifierInterface_CheckCard_req_holder_size
#define CardVerifierInterface_CheckCard_req_arena_size controlsys_CardVerifierInterface_CheckCard_req_arena_size
#define CardVerifierInterface_CheckCard_res_arena_size controlsys_CardVerifierInterface_CheckCard_res_arena_size
#define CardVerifierInterface_CheckCard_req_handles controlsys_CardVerifierInterface_CheckCard_req_handles
#define CardVerifierInterface_CheckCard_res_handles controlsys_CardVerifierInterface_CheckCard_res_handles
#define CardVerifierInterface_CheckCard_err_handles controlsys_CardVerifierInterface_CheckCard_err_handles
#define CardVerifierInterface_req_arena_size controlsys_CardVerifierInterface_req_arena_size
#define CardVerifierInterface_res_arena_size controlsys_CardVerifierInterface_res_arena_size
#define CardVerifierInterface_arena_size controlsys_CardVerifierInterface_arena_size
#define CardVerifierInterface_req_handles controlsys_CardVerifierInterface_req_handles
#define CardVerifierInterface_res_handles controlsys_CardVerifierInterface_res_handles
#define CardVerifierInterface_err_handles controlsys_CardVerifierInterface_err_handles
#define CardVerifierInterface_CheckCard_req controlsys_CardVerifierInterface_CheckCard_req
#define CardVerifierInterface_CheckCard_res controlsys_CardVerifierInterface_CheckCard_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifierInterface__INTERFACE__ */

#ifndef __controlsys__CardVerifier__COMPONENT_ENDPOINTS__
#define __controlsys__CardVerifier__COMPONENT_ENDPOINTS__
enum {
    controlsys_CardVerifier_interface_iid,
    controlsys_CardVerifier_iidMax,
};
enum {
    controlsys_CardVerifier_iidOffset = 0,
};
enum {
    controlsys_CardVerifier_securityIidMax,
};
enum {
    controlsys_CardVerifier_component_req_arena_size =
    75,
    controlsys_CardVerifier_component_res_arena_size =
    0,
    controlsys_CardVerifier_component_arena_size =
    75,
    controlsys_CardVerifier_component_req_handles =
    0,
    controlsys_CardVerifier_component_res_handles =
    0,
    controlsys_CardVerifier_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifier_interface_iid controlsys_CardVerifier_interface_iid
#define CardVerifier_iidMax controlsys_CardVerifier_iidMax
#define CardVerifier_iidOffset controlsys_CardVerifier_iidOffset
#define CardVerifier_securityIidMax controlsys_CardVerifier_securityIidMax
#define CardVerifier_component_req_arena_size controlsys_CardVerifier_component_req_arena_size
#define CardVerifier_component_res_arena_size controlsys_CardVerifier_component_res_arena_size
#define CardVerifier_component_arena_size controlsys_CardVerifier_component_arena_size
#define CardVerifier_component_req_handles controlsys_CardVerifier_component_req_handles
#define CardVerifier_component_res_handles controlsys_CardVerifier_component_res_handles
#define CardVerifier_component_err_handles controlsys_CardVerifier_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifier__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__CardVerifier__TASK_ENDPOINTS__
#define __controlsys__CardVerifier__TASK_ENDPOINTS__
enum {
    controlsys_CardVerifier_entity_req_arena_size =
    controlsys_CardVerifier_component_req_arena_size,
    controlsys_CardVerifier_entity_res_arena_size =
    controlsys_CardVerifier_component_res_arena_size,
    controlsys_CardVerifier_entity_arena_size =
    controlsys_CardVerifier_component_arena_size,
    controlsys_CardVerifier_entity_req_handles =
    controlsys_CardVerifier_component_req_handles,
    controlsys_CardVerifier_entity_res_handles =
    controlsys_CardVerifier_component_res_handles,
    controlsys_CardVerifier_entity_err_handles =
    controlsys_CardVerifier_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifier_entity_req_arena_size controlsys_CardVerifier_entity_req_arena_size
#define CardVerifier_entity_res_arena_size controlsys_CardVerifier_entity_res_arena_size
#define CardVerifier_entity_arena_size controlsys_CardVerifier_entity_arena_size
#define CardVerifier_entity_req_handles controlsys_CardVerifier_entity_req_handles
#define CardVerifier_entity_res_handles controlsys_CardVerifier_entity_res_handles
#define CardVerifier_entity_err_handles controlsys_CardVerifier_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifier__TASK_ENDPOINTS__ */

#ifndef __controlsys__CardVerifierInterface__VTABLE__
#define __controlsys__CardVerifierInterface__VTABLE__
typedef struct controlsys_CardVerifierInterface {
            const
            struct controlsys_CardVerifierInterface_ops *ops;
        } controlsys_CardVerifierInterface;
typedef nk_err_t
controlsys_CardVerifierInterface_CheckCard_fn(struct controlsys_CardVerifierInterface *,
                                              const
                                              struct controlsys_CardVerifierInterface_CheckCard_req *,
                                              const
                                              struct nk_arena *,
                                              struct controlsys_CardVerifierInterface_CheckCard_res *,
                                              struct nk_arena *);
typedef struct controlsys_CardVerifierInterface_ops {
            controlsys_CardVerifierInterface_CheckCard_fn *CheckCard;
        } controlsys_CardVerifierInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_CheckCard_fn controlsys_CardVerifierInterface_CheckCard_fn
#define CardVerifierInterface_ops controlsys_CardVerifierInterface_ops
#define CardVerifierInterface controlsys_CardVerifierInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifierInterface__VTABLE__ */

#ifndef __controlsys__CardVerifierInterface__SERVER__
#define __controlsys__CardVerifierInterface__SERVER__
typedef union controlsys_CardVerifierInterface_req {
            struct nk_message base_;
            struct controlsys_CardVerifierInterface_CheckCard_req CheckCard;
        } controlsys_CardVerifierInterface_req;
typedef union controlsys_CardVerifierInterface_res {
            struct nk_message base_;
            struct controlsys_CardVerifierInterface_CheckCard_res CheckCard;
        } controlsys_CardVerifierInterface_res;
static inline
nk_err_t controlsys_CardVerifierInterface_interface_dispatch(struct controlsys_CardVerifierInterface *impl,
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
            
          case controlsys_CardVerifierInterface_CheckCard_mid:
            {
                struct controlsys_CardVerifierInterface_CheckCard_res
                *res_ =
                (struct controlsys_CardVerifierInterface_CheckCard_res *) res;
                
                rc = impl->ops->CheckCard(impl,
                                          (const
                                           struct controlsys_CardVerifierInterface_CheckCard_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_CardVerifierInterface_CheckCard_res_handles);
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
#define CardVerifierInterface_req controlsys_CardVerifierInterface_req
#define CardVerifierInterface_res controlsys_CardVerifierInterface_res
#define CardVerifierInterface_interface_dispatch controlsys_CardVerifierInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifierInterface__SERVER__ */

#ifndef __controlsys__CardVerifier__COMPONENT_SERVER_TYPES__
#define __controlsys__CardVerifier__COMPONENT_SERVER_TYPES__
typedef struct controlsys_CardVerifier_component {
            struct controlsys_CardVerifierInterface *interface;
        } controlsys_CardVerifier_component;

#endif /* __controlsys__CardVerifier__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__CardVerifier__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__CardVerifier__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_CardVerifier_component_init(struct controlsys_CardVerifier_component *self,
                                            struct controlsys_CardVerifierInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_CardVerifier_component_req {
            struct nk_message base_;
            controlsys_CardVerifierInterface_req interface;
        } controlsys_CardVerifier_component_req;
typedef union controlsys_CardVerifier_component_res {
            struct nk_message base_;
            controlsys_CardVerifierInterface_res interface;
        } controlsys_CardVerifier_component_res;
static inline
nk_err_t controlsys_CardVerifier_component_dispatch(struct controlsys_CardVerifier_component *self,
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
        
      case controlsys_CardVerifier_interface_iid:
        return controlsys_CardVerifierInterface_interface_dispatch(self->interface,
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
#define CardVerifier_component controlsys_CardVerifier_component
#define CardVerifier_component_init controlsys_CardVerifier_component_init
#define CardVerifier_component_req controlsys_CardVerifier_component_req
#define CardVerifier_component_res controlsys_CardVerifier_component_res
#define CardVerifier_component_dispatch controlsys_CardVerifier_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifier__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__CardVerifier__ENTITY_SERVER__
#define __controlsys__CardVerifier__ENTITY_SERVER__
#define controlsys_CardVerifier_entity_res controlsys_CardVerifier_component_res
#define controlsys_CardVerifier_entity_req controlsys_CardVerifier_component_req
#define controlsys_CardVerifier_entity controlsys_CardVerifier_component
static inline
void controlsys_CardVerifier_entity_init(struct controlsys_CardVerifier_entity *self,
                                         struct controlsys_CardVerifierInterface *interface)
{
    controlsys_CardVerifier_component_init(self,
                                           interface);
}
static inline
nk_err_t controlsys_CardVerifier_entity_dispatch(struct controlsys_CardVerifier_entity *self,
                                                 const
                                                 struct nk_message *req,
                                                 const
                                                 struct nk_arena *req_arena,
                                                 struct nk_message *res,
                                                 struct nk_arena *res_arena)
{
    return controlsys_CardVerifier_component_dispatch(self,
                                                      0,
                                                      req,
                                                      req_arena,
                                                      res,
                                                      res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifier_entity controlsys_CardVerifier_entity
#define CardVerifier_entity_init controlsys_CardVerifier_entity_init
#define CardVerifier_entity_req controlsys_CardVerifier_entity_req
#define CardVerifier_entity_res controlsys_CardVerifier_entity_res
#define CardVerifier_entity_dispatch controlsys_CardVerifier_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifier__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

