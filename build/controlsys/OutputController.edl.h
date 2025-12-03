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

#ifndef __controlsys__OutputControllerInterface__INTERFACE__
#define __controlsys__OutputControllerInterface__INTERFACE__
enum {
    controlsys_OutputControllerInterface_InviteCard_mid,
    controlsys_OutputControllerInterface_RequestPIN_mid,
    controlsys_OutputControllerInterface_ShowStatus_mid,
    controlsys_OutputControllerInterface_ShowError_mid,
    controlsys_OutputControllerInterface_PrintReceipt_mid,
    controlsys_OutputControllerInterface_mid_max,
};
enum {
    controlsys_OutputControllerInterface_InviteCard_req_txId_size =
    49,
    controlsys_OutputControllerInterface_InviteCard_req_currency_size =
    9,
    controlsys_OutputControllerInterface_InviteCard_req_arena_size =
    58,
    controlsys_OutputControllerInterface_InviteCard_res_arena_size =
    0,
    controlsys_OutputControllerInterface_InviteCard_req_handles =
    0,
    controlsys_OutputControllerInterface_InviteCard_res_handles =
    0,
    controlsys_OutputControllerInterface_InviteCard_err_handles =
    0,
    controlsys_OutputControllerInterface_RequestPIN_req_txId_size =
    49,
    controlsys_OutputControllerInterface_RequestPIN_req_arena_size =
    49,
    controlsys_OutputControllerInterface_RequestPIN_res_arena_size =
    0,
    controlsys_OutputControllerInterface_RequestPIN_req_handles =
    0,
    controlsys_OutputControllerInterface_RequestPIN_res_handles =
    0,
    controlsys_OutputControllerInterface_RequestPIN_err_handles =
    0,
    controlsys_OutputControllerInterface_ShowStatus_req_message_size =
    65,
    controlsys_OutputControllerInterface_ShowStatus_req_arena_size =
    65,
    controlsys_OutputControllerInterface_ShowStatus_res_arena_size =
    0,
    controlsys_OutputControllerInterface_ShowStatus_req_handles =
    0,
    controlsys_OutputControllerInterface_ShowStatus_res_handles =
    0,
    controlsys_OutputControllerInterface_ShowStatus_err_handles =
    0,
    controlsys_OutputControllerInterface_ShowError_req_message_size =
    65,
    controlsys_OutputControllerInterface_ShowError_req_arena_size =
    65,
    controlsys_OutputControllerInterface_ShowError_res_arena_size =
    0,
    controlsys_OutputControllerInterface_ShowError_req_handles =
    0,
    controlsys_OutputControllerInterface_ShowError_res_handles =
    0,
    controlsys_OutputControllerInterface_ShowError_err_handles =
    0,
    controlsys_OutputControllerInterface_PrintReceipt_req_txId_size =
    49,
    controlsys_OutputControllerInterface_PrintReceipt_req_currency_size =
    9,
    controlsys_OutputControllerInterface_PrintReceipt_req_arena_size =
    58,
    controlsys_OutputControllerInterface_PrintReceipt_res_arena_size =
    0,
    controlsys_OutputControllerInterface_PrintReceipt_req_handles =
    0,
    controlsys_OutputControllerInterface_PrintReceipt_res_handles =
    0,
    controlsys_OutputControllerInterface_PrintReceipt_err_handles =
    0,
    controlsys_OutputControllerInterface_req_arena_size =
    65,
    controlsys_OutputControllerInterface_res_arena_size =
    0,
    controlsys_OutputControllerInterface_arena_size =
    65,
    controlsys_OutputControllerInterface_req_handles =
    0,
    controlsys_OutputControllerInterface_res_handles =
    0,
    controlsys_OutputControllerInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_OutputControllerInterface_InviteCard_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
            __nk_alignas(4)
            nk_uint32_t amountCents;
            __nk_alignas(4) nk_ptr_t currency;
        }
controlsys_OutputControllerInterface_InviteCard_req;
#pragma pack(push, 8) /* controlsys_OutputControllerInterface_InviteCard_res */
typedef struct controlsys_OutputControllerInterface_InviteCard_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_OutputControllerInterface_InviteCard_err;
typedef struct controlsys_OutputControllerInterface_InviteCard_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_OutputControllerInterface_InviteCard_err err_;
            };
        }
controlsys_OutputControllerInterface_InviteCard_res;
#pragma pack(pop) /* controlsys_OutputControllerInterface_InviteCard_res */
typedef struct __nk_packed controlsys_OutputControllerInterface_RequestPIN_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
        }
controlsys_OutputControllerInterface_RequestPIN_req;
#pragma pack(push, 8) /* controlsys_OutputControllerInterface_RequestPIN_res */
typedef struct controlsys_OutputControllerInterface_RequestPIN_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_OutputControllerInterface_RequestPIN_err;
typedef struct controlsys_OutputControllerInterface_RequestPIN_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_OutputControllerInterface_RequestPIN_err err_;
            };
        }
controlsys_OutputControllerInterface_RequestPIN_res;
#pragma pack(pop) /* controlsys_OutputControllerInterface_RequestPIN_res */
typedef struct __nk_packed controlsys_OutputControllerInterface_ShowStatus_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t message;
        }
controlsys_OutputControllerInterface_ShowStatus_req;
#pragma pack(push, 8) /* controlsys_OutputControllerInterface_ShowStatus_res */
typedef struct controlsys_OutputControllerInterface_ShowStatus_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_OutputControllerInterface_ShowStatus_err;
typedef struct controlsys_OutputControllerInterface_ShowStatus_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_OutputControllerInterface_ShowStatus_err err_;
            };
        }
controlsys_OutputControllerInterface_ShowStatus_res;
#pragma pack(pop) /* controlsys_OutputControllerInterface_ShowStatus_res */
typedef struct __nk_packed controlsys_OutputControllerInterface_ShowError_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t message;
        }
controlsys_OutputControllerInterface_ShowError_req;
#pragma pack(push, 8) /* controlsys_OutputControllerInterface_ShowError_res */
typedef struct controlsys_OutputControllerInterface_ShowError_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_OutputControllerInterface_ShowError_err;
typedef struct controlsys_OutputControllerInterface_ShowError_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_OutputControllerInterface_ShowError_err err_;
            };
        }
controlsys_OutputControllerInterface_ShowError_res;
#pragma pack(pop) /* controlsys_OutputControllerInterface_ShowError_res */
typedef struct __nk_packed controlsys_OutputControllerInterface_PrintReceipt_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
            __nk_alignas(4)
            nk_uint32_t amountCents;
            __nk_alignas(4) nk_ptr_t currency;
            __nk_alignas(1) nk_uint8_t approved;
        }
controlsys_OutputControllerInterface_PrintReceipt_req;
#pragma pack(push, 8) /* controlsys_OutputControllerInterface_PrintReceipt_res */
typedef struct controlsys_OutputControllerInterface_PrintReceipt_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_OutputControllerInterface_PrintReceipt_err;
typedef struct controlsys_OutputControllerInterface_PrintReceipt_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_OutputControllerInterface_PrintReceipt_err err_;
            };
        }
controlsys_OutputControllerInterface_PrintReceipt_res;
#pragma pack(pop) /* controlsys_OutputControllerInterface_PrintReceipt_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputControllerInterface_InviteCard_mid controlsys_OutputControllerInterface_InviteCard_mid
#define OutputControllerInterface_RequestPIN_mid controlsys_OutputControllerInterface_RequestPIN_mid
#define OutputControllerInterface_ShowStatus_mid controlsys_OutputControllerInterface_ShowStatus_mid
#define OutputControllerInterface_ShowError_mid controlsys_OutputControllerInterface_ShowError_mid
#define OutputControllerInterface_PrintReceipt_mid controlsys_OutputControllerInterface_PrintReceipt_mid
#define OutputControllerInterface_mid_max controlsys_OutputControllerInterface_mid_max
#define OutputControllerInterface_InviteCard_req_txId_size controlsys_OutputControllerInterface_InviteCard_req_txId_size
#define OutputControllerInterface_InviteCard_req_currency_size controlsys_OutputControllerInterface_InviteCard_req_currency_size
#define OutputControllerInterface_InviteCard_req_arena_size controlsys_OutputControllerInterface_InviteCard_req_arena_size
#define OutputControllerInterface_InviteCard_res_arena_size controlsys_OutputControllerInterface_InviteCard_res_arena_size
#define OutputControllerInterface_InviteCard_req_handles controlsys_OutputControllerInterface_InviteCard_req_handles
#define OutputControllerInterface_InviteCard_res_handles controlsys_OutputControllerInterface_InviteCard_res_handles
#define OutputControllerInterface_InviteCard_err_handles controlsys_OutputControllerInterface_InviteCard_err_handles
#define OutputControllerInterface_RequestPIN_req_txId_size controlsys_OutputControllerInterface_RequestPIN_req_txId_size
#define OutputControllerInterface_RequestPIN_req_arena_size controlsys_OutputControllerInterface_RequestPIN_req_arena_size
#define OutputControllerInterface_RequestPIN_res_arena_size controlsys_OutputControllerInterface_RequestPIN_res_arena_size
#define OutputControllerInterface_RequestPIN_req_handles controlsys_OutputControllerInterface_RequestPIN_req_handles
#define OutputControllerInterface_RequestPIN_res_handles controlsys_OutputControllerInterface_RequestPIN_res_handles
#define OutputControllerInterface_RequestPIN_err_handles controlsys_OutputControllerInterface_RequestPIN_err_handles
#define OutputControllerInterface_ShowStatus_req_message_size controlsys_OutputControllerInterface_ShowStatus_req_message_size
#define OutputControllerInterface_ShowStatus_req_arena_size controlsys_OutputControllerInterface_ShowStatus_req_arena_size
#define OutputControllerInterface_ShowStatus_res_arena_size controlsys_OutputControllerInterface_ShowStatus_res_arena_size
#define OutputControllerInterface_ShowStatus_req_handles controlsys_OutputControllerInterface_ShowStatus_req_handles
#define OutputControllerInterface_ShowStatus_res_handles controlsys_OutputControllerInterface_ShowStatus_res_handles
#define OutputControllerInterface_ShowStatus_err_handles controlsys_OutputControllerInterface_ShowStatus_err_handles
#define OutputControllerInterface_ShowError_req_message_size controlsys_OutputControllerInterface_ShowError_req_message_size
#define OutputControllerInterface_ShowError_req_arena_size controlsys_OutputControllerInterface_ShowError_req_arena_size
#define OutputControllerInterface_ShowError_res_arena_size controlsys_OutputControllerInterface_ShowError_res_arena_size
#define OutputControllerInterface_ShowError_req_handles controlsys_OutputControllerInterface_ShowError_req_handles
#define OutputControllerInterface_ShowError_res_handles controlsys_OutputControllerInterface_ShowError_res_handles
#define OutputControllerInterface_ShowError_err_handles controlsys_OutputControllerInterface_ShowError_err_handles
#define OutputControllerInterface_PrintReceipt_req_txId_size controlsys_OutputControllerInterface_PrintReceipt_req_txId_size
#define OutputControllerInterface_PrintReceipt_req_currency_size controlsys_OutputControllerInterface_PrintReceipt_req_currency_size
#define OutputControllerInterface_PrintReceipt_req_arena_size controlsys_OutputControllerInterface_PrintReceipt_req_arena_size
#define OutputControllerInterface_PrintReceipt_res_arena_size controlsys_OutputControllerInterface_PrintReceipt_res_arena_size
#define OutputControllerInterface_PrintReceipt_req_handles controlsys_OutputControllerInterface_PrintReceipt_req_handles
#define OutputControllerInterface_PrintReceipt_res_handles controlsys_OutputControllerInterface_PrintReceipt_res_handles
#define OutputControllerInterface_PrintReceipt_err_handles controlsys_OutputControllerInterface_PrintReceipt_err_handles
#define OutputControllerInterface_req_arena_size controlsys_OutputControllerInterface_req_arena_size
#define OutputControllerInterface_res_arena_size controlsys_OutputControllerInterface_res_arena_size
#define OutputControllerInterface_arena_size controlsys_OutputControllerInterface_arena_size
#define OutputControllerInterface_req_handles controlsys_OutputControllerInterface_req_handles
#define OutputControllerInterface_res_handles controlsys_OutputControllerInterface_res_handles
#define OutputControllerInterface_err_handles controlsys_OutputControllerInterface_err_handles
#define OutputControllerInterface_InviteCard_req controlsys_OutputControllerInterface_InviteCard_req
#define OutputControllerInterface_InviteCard_res controlsys_OutputControllerInterface_InviteCard_res
#define OutputControllerInterface_RequestPIN_req controlsys_OutputControllerInterface_RequestPIN_req
#define OutputControllerInterface_RequestPIN_res controlsys_OutputControllerInterface_RequestPIN_res
#define OutputControllerInterface_ShowStatus_req controlsys_OutputControllerInterface_ShowStatus_req
#define OutputControllerInterface_ShowStatus_res controlsys_OutputControllerInterface_ShowStatus_res
#define OutputControllerInterface_ShowError_req controlsys_OutputControllerInterface_ShowError_req
#define OutputControllerInterface_ShowError_res controlsys_OutputControllerInterface_ShowError_res
#define OutputControllerInterface_PrintReceipt_req controlsys_OutputControllerInterface_PrintReceipt_req
#define OutputControllerInterface_PrintReceipt_res controlsys_OutputControllerInterface_PrintReceipt_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputControllerInterface__INTERFACE__ */

#ifndef __controlsys__OutputController__COMPONENT_ENDPOINTS__
#define __controlsys__OutputController__COMPONENT_ENDPOINTS__
enum {
    controlsys_OutputController_interface_iid,
    controlsys_OutputController_iidMax,
};
enum {
    controlsys_OutputController_iidOffset = 0,
};
enum {
    controlsys_OutputController_securityIidMax,
};
enum {
    controlsys_OutputController_component_req_arena_size =
    65,
    controlsys_OutputController_component_res_arena_size =
    0,
    controlsys_OutputController_component_arena_size =
    65,
    controlsys_OutputController_component_req_handles =
    0,
    controlsys_OutputController_component_res_handles =
    0,
    controlsys_OutputController_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputController_interface_iid controlsys_OutputController_interface_iid
#define OutputController_iidMax controlsys_OutputController_iidMax
#define OutputController_iidOffset controlsys_OutputController_iidOffset
#define OutputController_securityIidMax controlsys_OutputController_securityIidMax
#define OutputController_component_req_arena_size controlsys_OutputController_component_req_arena_size
#define OutputController_component_res_arena_size controlsys_OutputController_component_res_arena_size
#define OutputController_component_arena_size controlsys_OutputController_component_arena_size
#define OutputController_component_req_handles controlsys_OutputController_component_req_handles
#define OutputController_component_res_handles controlsys_OutputController_component_res_handles
#define OutputController_component_err_handles controlsys_OutputController_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputController__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__OutputController__TASK_ENDPOINTS__
#define __controlsys__OutputController__TASK_ENDPOINTS__
enum {
    controlsys_OutputController_entity_req_arena_size =
    controlsys_OutputController_component_req_arena_size,
    controlsys_OutputController_entity_res_arena_size =
    controlsys_OutputController_component_res_arena_size,
    controlsys_OutputController_entity_arena_size =
    controlsys_OutputController_component_arena_size,
    controlsys_OutputController_entity_req_handles =
    controlsys_OutputController_component_req_handles,
    controlsys_OutputController_entity_res_handles =
    controlsys_OutputController_component_res_handles,
    controlsys_OutputController_entity_err_handles =
    controlsys_OutputController_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputController_entity_req_arena_size controlsys_OutputController_entity_req_arena_size
#define OutputController_entity_res_arena_size controlsys_OutputController_entity_res_arena_size
#define OutputController_entity_arena_size controlsys_OutputController_entity_arena_size
#define OutputController_entity_req_handles controlsys_OutputController_entity_req_handles
#define OutputController_entity_res_handles controlsys_OutputController_entity_res_handles
#define OutputController_entity_err_handles controlsys_OutputController_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputController__TASK_ENDPOINTS__ */

#ifndef __controlsys__OutputControllerInterface__VTABLE__
#define __controlsys__OutputControllerInterface__VTABLE__
typedef struct controlsys_OutputControllerInterface {
            const
            struct controlsys_OutputControllerInterface_ops *ops;
        } controlsys_OutputControllerInterface;
typedef nk_err_t
controlsys_OutputControllerInterface_InviteCard_fn(struct controlsys_OutputControllerInterface *,
                                                   const
                                                   struct controlsys_OutputControllerInterface_InviteCard_req *,
                                                   const
                                                   struct nk_arena *,
                                                   struct controlsys_OutputControllerInterface_InviteCard_res *,
                                                   struct nk_arena *);
typedef nk_err_t
controlsys_OutputControllerInterface_RequestPIN_fn(struct controlsys_OutputControllerInterface *,
                                                   const
                                                   struct controlsys_OutputControllerInterface_RequestPIN_req *,
                                                   const
                                                   struct nk_arena *,
                                                   struct controlsys_OutputControllerInterface_RequestPIN_res *,
                                                   struct nk_arena *);
typedef nk_err_t
controlsys_OutputControllerInterface_ShowStatus_fn(struct controlsys_OutputControllerInterface *,
                                                   const
                                                   struct controlsys_OutputControllerInterface_ShowStatus_req *,
                                                   const
                                                   struct nk_arena *,
                                                   struct controlsys_OutputControllerInterface_ShowStatus_res *,
                                                   struct nk_arena *);
typedef nk_err_t
controlsys_OutputControllerInterface_ShowError_fn(struct controlsys_OutputControllerInterface *,
                                                  const
                                                  struct controlsys_OutputControllerInterface_ShowError_req *,
                                                  const
                                                  struct nk_arena *,
                                                  struct controlsys_OutputControllerInterface_ShowError_res *,
                                                  struct nk_arena *);
typedef nk_err_t
controlsys_OutputControllerInterface_PrintReceipt_fn(struct controlsys_OutputControllerInterface *,
                                                     const
                                                     struct controlsys_OutputControllerInterface_PrintReceipt_req *,
                                                     const
                                                     struct nk_arena *,
                                                     struct controlsys_OutputControllerInterface_PrintReceipt_res *,
                                                     struct nk_arena *);
typedef struct controlsys_OutputControllerInterface_ops {
            controlsys_OutputControllerInterface_InviteCard_fn *InviteCard;
            controlsys_OutputControllerInterface_RequestPIN_fn *RequestPIN;
            controlsys_OutputControllerInterface_ShowStatus_fn *ShowStatus;
            controlsys_OutputControllerInterface_ShowError_fn *ShowError;
            controlsys_OutputControllerInterface_PrintReceipt_fn *PrintReceipt;
        }
controlsys_OutputControllerInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputControllerInterface_InviteCard_fn controlsys_OutputControllerInterface_InviteCard_fn
#define OutputControllerInterface_RequestPIN_fn controlsys_OutputControllerInterface_RequestPIN_fn
#define OutputControllerInterface_ShowStatus_fn controlsys_OutputControllerInterface_ShowStatus_fn
#define OutputControllerInterface_ShowError_fn controlsys_OutputControllerInterface_ShowError_fn
#define OutputControllerInterface_PrintReceipt_fn controlsys_OutputControllerInterface_PrintReceipt_fn
#define OutputControllerInterface_ops controlsys_OutputControllerInterface_ops
#define OutputControllerInterface controlsys_OutputControllerInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputControllerInterface__VTABLE__ */

#ifndef __controlsys__OutputControllerInterface__SERVER__
#define __controlsys__OutputControllerInterface__SERVER__
typedef union controlsys_OutputControllerInterface_req {
            struct nk_message base_;
            struct controlsys_OutputControllerInterface_InviteCard_req InviteCard;
            struct controlsys_OutputControllerInterface_RequestPIN_req RequestPIN;
            struct controlsys_OutputControllerInterface_ShowStatus_req ShowStatus;
            struct controlsys_OutputControllerInterface_ShowError_req ShowError;
            struct controlsys_OutputControllerInterface_PrintReceipt_req PrintReceipt;
        }
controlsys_OutputControllerInterface_req;
typedef union controlsys_OutputControllerInterface_res {
            struct nk_message base_;
            struct controlsys_OutputControllerInterface_InviteCard_res InviteCard;
            struct controlsys_OutputControllerInterface_RequestPIN_res RequestPIN;
            struct controlsys_OutputControllerInterface_ShowStatus_res ShowStatus;
            struct controlsys_OutputControllerInterface_ShowError_res ShowError;
            struct controlsys_OutputControllerInterface_PrintReceipt_res PrintReceipt;
        }
controlsys_OutputControllerInterface_res;
static inline
nk_err_t controlsys_OutputControllerInterface_interface_dispatch(struct controlsys_OutputControllerInterface *impl,
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
            
          case controlsys_OutputControllerInterface_InviteCard_mid:
            {
                struct controlsys_OutputControllerInterface_InviteCard_res
                *res_ =
                (struct controlsys_OutputControllerInterface_InviteCard_res *) res;
                
                rc = impl->ops->InviteCard(impl,
                                           (const
                                            struct controlsys_OutputControllerInterface_InviteCard_req *) req,
                                           req_arena,
                                           res_,
                                           res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_OutputControllerInterface_InviteCard_res_handles);
                }
                break;
            }
            
          case controlsys_OutputControllerInterface_RequestPIN_mid:
            {
                struct controlsys_OutputControllerInterface_RequestPIN_res
                *res_ =
                (struct controlsys_OutputControllerInterface_RequestPIN_res *) res;
                
                rc = impl->ops->RequestPIN(impl,
                                           (const
                                            struct controlsys_OutputControllerInterface_RequestPIN_req *) req,
                                           req_arena,
                                           res_,
                                           res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_OutputControllerInterface_RequestPIN_res_handles);
                }
                break;
            }
            
          case controlsys_OutputControllerInterface_ShowStatus_mid:
            {
                struct controlsys_OutputControllerInterface_ShowStatus_res
                *res_ =
                (struct controlsys_OutputControllerInterface_ShowStatus_res *) res;
                
                rc = impl->ops->ShowStatus(impl,
                                           (const
                                            struct controlsys_OutputControllerInterface_ShowStatus_req *) req,
                                           req_arena,
                                           res_,
                                           res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_OutputControllerInterface_ShowStatus_res_handles);
                }
                break;
            }
            
          case controlsys_OutputControllerInterface_ShowError_mid:
            {
                struct controlsys_OutputControllerInterface_ShowError_res
                *res_ =
                (struct controlsys_OutputControllerInterface_ShowError_res *) res;
                
                rc = impl->ops->ShowError(impl,
                                          (const
                                           struct controlsys_OutputControllerInterface_ShowError_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_OutputControllerInterface_ShowError_res_handles);
                }
                break;
            }
            
          case controlsys_OutputControllerInterface_PrintReceipt_mid:
            {
                struct controlsys_OutputControllerInterface_PrintReceipt_res
                *res_ =
                (struct controlsys_OutputControllerInterface_PrintReceipt_res *) res;
                
                rc = impl->ops->PrintReceipt(impl,
                                             (const
                                              struct controlsys_OutputControllerInterface_PrintReceipt_req *) req,
                                             req_arena,
                                             res_,
                                             res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_OutputControllerInterface_PrintReceipt_res_handles);
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
#define OutputControllerInterface_req controlsys_OutputControllerInterface_req
#define OutputControllerInterface_res controlsys_OutputControllerInterface_res
#define OutputControllerInterface_interface_dispatch controlsys_OutputControllerInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputControllerInterface__SERVER__ */

#ifndef __controlsys__OutputController__COMPONENT_SERVER_TYPES__
#define __controlsys__OutputController__COMPONENT_SERVER_TYPES__
typedef struct controlsys_OutputController_component {
            struct controlsys_OutputControllerInterface *interface;
        } controlsys_OutputController_component;

#endif /* __controlsys__OutputController__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__OutputController__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__OutputController__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_OutputController_component_init(struct controlsys_OutputController_component *self,
                                                struct controlsys_OutputControllerInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_OutputController_component_req {
            struct nk_message base_;
            controlsys_OutputControllerInterface_req interface;
        }
controlsys_OutputController_component_req;
typedef union controlsys_OutputController_component_res {
            struct nk_message base_;
            controlsys_OutputControllerInterface_res interface;
        }
controlsys_OutputController_component_res;
static inline
nk_err_t controlsys_OutputController_component_dispatch(struct controlsys_OutputController_component *self,
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
        
      case controlsys_OutputController_interface_iid:
        return controlsys_OutputControllerInterface_interface_dispatch(self->interface,
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
#define OutputController_component controlsys_OutputController_component
#define OutputController_component_init controlsys_OutputController_component_init
#define OutputController_component_req controlsys_OutputController_component_req
#define OutputController_component_res controlsys_OutputController_component_res
#define OutputController_component_dispatch controlsys_OutputController_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputController__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__OutputController__ENTITY_SERVER__
#define __controlsys__OutputController__ENTITY_SERVER__
#define controlsys_OutputController_entity_res controlsys_OutputController_component_res
#define controlsys_OutputController_entity_req controlsys_OutputController_component_req
#define controlsys_OutputController_entity controlsys_OutputController_component
static inline
void controlsys_OutputController_entity_init(struct controlsys_OutputController_entity *self,
                                             struct controlsys_OutputControllerInterface *interface)
{
    controlsys_OutputController_component_init(self,
                                               interface);
}
static inline
nk_err_t controlsys_OutputController_entity_dispatch(struct controlsys_OutputController_entity *self,
                                                     const
                                                     struct nk_message *req,
                                                     const
                                                     struct nk_arena *req_arena,
                                                     struct nk_message *res,
                                                     struct nk_arena *res_arena)
{
    return controlsys_OutputController_component_dispatch(self,
                                                          0,
                                                          req,
                                                          req_arena,
                                                          res,
                                                          res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputController_entity controlsys_OutputController_entity
#define OutputController_entity_init controlsys_OutputController_entity_init
#define OutputController_entity_req controlsys_OutputController_entity_req
#define OutputController_entity_res controlsys_OutputController_entity_res
#define OutputController_entity_dispatch controlsys_OutputController_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputController__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

