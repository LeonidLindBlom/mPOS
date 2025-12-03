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

#ifndef __controlsys__TransactionGeneratorInterface__INTERFACE__
#define __controlsys__TransactionGeneratorInterface__INTERFACE__
enum {
    controlsys_TransactionGeneratorInterface_Build_mid,
    controlsys_TransactionGeneratorInterface_mid_max,
};
enum {
    controlsys_TransactionGeneratorInterface_Build_req_txId_size =
    49,
    controlsys_TransactionGeneratorInterface_Build_req_currency_size =
    9,
    controlsys_TransactionGeneratorInterface_Build_res_payload_size =
    65,
    controlsys_TransactionGeneratorInterface_Build_req_arena_size =
    58,
    controlsys_TransactionGeneratorInterface_Build_res_arena_size =
    65,
    controlsys_TransactionGeneratorInterface_Build_req_handles =
    0,
    controlsys_TransactionGeneratorInterface_Build_res_handles =
    0,
    controlsys_TransactionGeneratorInterface_Build_err_handles =
    0,
    controlsys_TransactionGeneratorInterface_req_arena_size =
    58,
    controlsys_TransactionGeneratorInterface_res_arena_size =
    65,
    controlsys_TransactionGeneratorInterface_arena_size =
    65,
    controlsys_TransactionGeneratorInterface_req_handles =
    0,
    controlsys_TransactionGeneratorInterface_res_handles =
    0,
    controlsys_TransactionGeneratorInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_TransactionGeneratorInterface_Build_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
            __nk_alignas(4)
            nk_uint32_t amountCents;
            __nk_alignas(4) nk_ptr_t currency;
            __nk_alignas(1) nk_uint8_t approved;
        }
controlsys_TransactionGeneratorInterface_Build_req;
#pragma pack(push, 8) /* controlsys_TransactionGeneratorInterface_Build_res */
typedef struct controlsys_TransactionGeneratorInterface_Build_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_TransactionGeneratorInterface_Build_err;
typedef struct controlsys_TransactionGeneratorInterface_Build_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t payload;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t payload;
                } res_;
                struct controlsys_TransactionGeneratorInterface_Build_err err_;
            };
        }
controlsys_TransactionGeneratorInterface_Build_res;
#pragma pack(pop) /* controlsys_TransactionGeneratorInterface_Build_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_Build_mid controlsys_TransactionGeneratorInterface_Build_mid
#define TransactionGeneratorInterface_mid_max controlsys_TransactionGeneratorInterface_mid_max
#define TransactionGeneratorInterface_Build_req_txId_size controlsys_TransactionGeneratorInterface_Build_req_txId_size
#define TransactionGeneratorInterface_Build_req_currency_size controlsys_TransactionGeneratorInterface_Build_req_currency_size
#define TransactionGeneratorInterface_Build_res_payload_size controlsys_TransactionGeneratorInterface_Build_res_payload_size
#define TransactionGeneratorInterface_Build_req_arena_size controlsys_TransactionGeneratorInterface_Build_req_arena_size
#define TransactionGeneratorInterface_Build_res_arena_size controlsys_TransactionGeneratorInterface_Build_res_arena_size
#define TransactionGeneratorInterface_Build_req_handles controlsys_TransactionGeneratorInterface_Build_req_handles
#define TransactionGeneratorInterface_Build_res_handles controlsys_TransactionGeneratorInterface_Build_res_handles
#define TransactionGeneratorInterface_Build_err_handles controlsys_TransactionGeneratorInterface_Build_err_handles
#define TransactionGeneratorInterface_req_arena_size controlsys_TransactionGeneratorInterface_req_arena_size
#define TransactionGeneratorInterface_res_arena_size controlsys_TransactionGeneratorInterface_res_arena_size
#define TransactionGeneratorInterface_arena_size controlsys_TransactionGeneratorInterface_arena_size
#define TransactionGeneratorInterface_req_handles controlsys_TransactionGeneratorInterface_req_handles
#define TransactionGeneratorInterface_res_handles controlsys_TransactionGeneratorInterface_res_handles
#define TransactionGeneratorInterface_err_handles controlsys_TransactionGeneratorInterface_err_handles
#define TransactionGeneratorInterface_Build_req controlsys_TransactionGeneratorInterface_Build_req
#define TransactionGeneratorInterface_Build_res controlsys_TransactionGeneratorInterface_Build_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGeneratorInterface__INTERFACE__ */

#ifndef __controlsys__TransactionGenerator__COMPONENT_ENDPOINTS__
#define __controlsys__TransactionGenerator__COMPONENT_ENDPOINTS__
enum {
    controlsys_TransactionGenerator_interface_iid,
    controlsys_TransactionGenerator_iidMax,
};
enum {
    controlsys_TransactionGenerator_iidOffset = 0,
};
enum {
    controlsys_TransactionGenerator_securityIidMax,
};
enum {
    controlsys_TransactionGenerator_component_req_arena_size =
    58,
    controlsys_TransactionGenerator_component_res_arena_size =
    65,
    controlsys_TransactionGenerator_component_arena_size =
    65,
    controlsys_TransactionGenerator_component_req_handles =
    0,
    controlsys_TransactionGenerator_component_res_handles =
    0,
    controlsys_TransactionGenerator_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGenerator_interface_iid controlsys_TransactionGenerator_interface_iid
#define TransactionGenerator_iidMax controlsys_TransactionGenerator_iidMax
#define TransactionGenerator_iidOffset controlsys_TransactionGenerator_iidOffset
#define TransactionGenerator_securityIidMax controlsys_TransactionGenerator_securityIidMax
#define TransactionGenerator_component_req_arena_size controlsys_TransactionGenerator_component_req_arena_size
#define TransactionGenerator_component_res_arena_size controlsys_TransactionGenerator_component_res_arena_size
#define TransactionGenerator_component_arena_size controlsys_TransactionGenerator_component_arena_size
#define TransactionGenerator_component_req_handles controlsys_TransactionGenerator_component_req_handles
#define TransactionGenerator_component_res_handles controlsys_TransactionGenerator_component_res_handles
#define TransactionGenerator_component_err_handles controlsys_TransactionGenerator_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGenerator__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__TransactionGenerator__TASK_ENDPOINTS__
#define __controlsys__TransactionGenerator__TASK_ENDPOINTS__
enum {
    controlsys_TransactionGenerator_entity_req_arena_size =
    controlsys_TransactionGenerator_component_req_arena_size,
    controlsys_TransactionGenerator_entity_res_arena_size =
    controlsys_TransactionGenerator_component_res_arena_size,
    controlsys_TransactionGenerator_entity_arena_size =
    controlsys_TransactionGenerator_component_arena_size,
    controlsys_TransactionGenerator_entity_req_handles =
    controlsys_TransactionGenerator_component_req_handles,
    controlsys_TransactionGenerator_entity_res_handles =
    controlsys_TransactionGenerator_component_res_handles,
    controlsys_TransactionGenerator_entity_err_handles =
    controlsys_TransactionGenerator_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGenerator_entity_req_arena_size controlsys_TransactionGenerator_entity_req_arena_size
#define TransactionGenerator_entity_res_arena_size controlsys_TransactionGenerator_entity_res_arena_size
#define TransactionGenerator_entity_arena_size controlsys_TransactionGenerator_entity_arena_size
#define TransactionGenerator_entity_req_handles controlsys_TransactionGenerator_entity_req_handles
#define TransactionGenerator_entity_res_handles controlsys_TransactionGenerator_entity_res_handles
#define TransactionGenerator_entity_err_handles controlsys_TransactionGenerator_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGenerator__TASK_ENDPOINTS__ */

#ifndef __controlsys__TransactionGeneratorInterface__VTABLE__
#define __controlsys__TransactionGeneratorInterface__VTABLE__
typedef struct controlsys_TransactionGeneratorInterface {
            const
            struct controlsys_TransactionGeneratorInterface_ops *ops;
        }
controlsys_TransactionGeneratorInterface;
typedef nk_err_t
controlsys_TransactionGeneratorInterface_Build_fn(struct controlsys_TransactionGeneratorInterface *,
                                                  const
                                                  struct controlsys_TransactionGeneratorInterface_Build_req *,
                                                  const
                                                  struct nk_arena *,
                                                  struct controlsys_TransactionGeneratorInterface_Build_res *,
                                                  struct nk_arena *);
typedef struct controlsys_TransactionGeneratorInterface_ops {
            controlsys_TransactionGeneratorInterface_Build_fn *Build;
        }
controlsys_TransactionGeneratorInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_Build_fn controlsys_TransactionGeneratorInterface_Build_fn
#define TransactionGeneratorInterface_ops controlsys_TransactionGeneratorInterface_ops
#define TransactionGeneratorInterface controlsys_TransactionGeneratorInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGeneratorInterface__VTABLE__ */

#ifndef __controlsys__TransactionGeneratorInterface__SERVER__
#define __controlsys__TransactionGeneratorInterface__SERVER__
typedef union controlsys_TransactionGeneratorInterface_req {
            struct nk_message base_;
            struct controlsys_TransactionGeneratorInterface_Build_req Build;
        }
controlsys_TransactionGeneratorInterface_req;
typedef union controlsys_TransactionGeneratorInterface_res {
            struct nk_message base_;
            struct controlsys_TransactionGeneratorInterface_Build_res Build;
        }
controlsys_TransactionGeneratorInterface_res;
static inline
nk_err_t controlsys_TransactionGeneratorInterface_interface_dispatch(struct controlsys_TransactionGeneratorInterface *impl,
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
            
          case controlsys_TransactionGeneratorInterface_Build_mid:
            {
                struct controlsys_TransactionGeneratorInterface_Build_res
                *res_ =
                (struct controlsys_TransactionGeneratorInterface_Build_res *) res;
                
                rc = impl->ops->Build(impl, (const
                                             struct controlsys_TransactionGeneratorInterface_Build_req *) req,
                                      req_arena,
                                      res_,
                                      res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_TransactionGeneratorInterface_Build_res_handles);
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
#define TransactionGeneratorInterface_req controlsys_TransactionGeneratorInterface_req
#define TransactionGeneratorInterface_res controlsys_TransactionGeneratorInterface_res
#define TransactionGeneratorInterface_interface_dispatch controlsys_TransactionGeneratorInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGeneratorInterface__SERVER__ */

#ifndef __controlsys__TransactionGenerator__COMPONENT_SERVER_TYPES__
#define __controlsys__TransactionGenerator__COMPONENT_SERVER_TYPES__
typedef struct controlsys_TransactionGenerator_component {
            struct controlsys_TransactionGeneratorInterface *interface;
        }
controlsys_TransactionGenerator_component;

#endif /* __controlsys__TransactionGenerator__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__TransactionGenerator__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__TransactionGenerator__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_TransactionGenerator_component_init(struct controlsys_TransactionGenerator_component *self,
                                                    struct controlsys_TransactionGeneratorInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_TransactionGenerator_component_req {
            struct nk_message base_;
            controlsys_TransactionGeneratorInterface_req interface;
        }
controlsys_TransactionGenerator_component_req;
typedef union controlsys_TransactionGenerator_component_res {
            struct nk_message base_;
            controlsys_TransactionGeneratorInterface_res interface;
        }
controlsys_TransactionGenerator_component_res;
static inline
nk_err_t controlsys_TransactionGenerator_component_dispatch(struct controlsys_TransactionGenerator_component *self,
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
        
      case controlsys_TransactionGenerator_interface_iid:
        return controlsys_TransactionGeneratorInterface_interface_dispatch(self->interface,
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
#define TransactionGenerator_component controlsys_TransactionGenerator_component
#define TransactionGenerator_component_init controlsys_TransactionGenerator_component_init
#define TransactionGenerator_component_req controlsys_TransactionGenerator_component_req
#define TransactionGenerator_component_res controlsys_TransactionGenerator_component_res
#define TransactionGenerator_component_dispatch controlsys_TransactionGenerator_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGenerator__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__TransactionGenerator__ENTITY_SERVER__
#define __controlsys__TransactionGenerator__ENTITY_SERVER__
#define controlsys_TransactionGenerator_entity_res controlsys_TransactionGenerator_component_res
#define controlsys_TransactionGenerator_entity_req controlsys_TransactionGenerator_component_req
#define controlsys_TransactionGenerator_entity controlsys_TransactionGenerator_component
static inline
void controlsys_TransactionGenerator_entity_init(struct controlsys_TransactionGenerator_entity *self,
                                                 struct controlsys_TransactionGeneratorInterface *interface)
{
    controlsys_TransactionGenerator_component_init(self,
                                                   interface);
}
static inline
nk_err_t controlsys_TransactionGenerator_entity_dispatch(struct controlsys_TransactionGenerator_entity *self,
                                                         const
                                                         struct nk_message *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct nk_message *res,
                                                         struct nk_arena *res_arena)
{
    return controlsys_TransactionGenerator_component_dispatch(self,
                                                              0,
                                                              req,
                                                              req_arena,
                                                              res,
                                                              res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGenerator_entity controlsys_TransactionGenerator_entity
#define TransactionGenerator_entity_init controlsys_TransactionGenerator_entity_init
#define TransactionGenerator_entity_req controlsys_TransactionGenerator_entity_req
#define TransactionGenerator_entity_res controlsys_TransactionGenerator_entity_res
#define TransactionGenerator_entity_dispatch controlsys_TransactionGenerator_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGenerator__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

