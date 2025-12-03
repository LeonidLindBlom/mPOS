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

#ifndef __controlsys_OutputControllerInterface__Bool__TYPEDEF__
#define __controlsys_OutputControllerInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_OutputControllerInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputControllerInterface_Bool controlsys_OutputControllerInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_OutputControllerInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_OutputControllerInterface__CurrencyLen__CONST__
#define __controlsys_OutputControllerInterface__CurrencyLen__CONST__
#define controlsys_OutputControllerInterface_CurrencyLen ((nk_uint8_t)(NK_UINT8_C(8)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputControllerInterface_CurrencyLen controlsys_OutputControllerInterface_CurrencyLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_OutputControllerInterface__CurrencyLen__CONST__ */

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

#ifndef __controlsys__OutputControllerInterface__CLIENT__
#define __controlsys__OutputControllerInterface__CLIENT__
typedef struct controlsys_OutputControllerInterface_proxy {
            struct controlsys_OutputControllerInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        }
controlsys_OutputControllerInterface_proxy;
static inline
nk_err_t controlsys_OutputControllerInterface_InviteCard_proxy(struct controlsys_OutputControllerInterface_proxy *self,
                                                               struct controlsys_OutputControllerInterface_InviteCard_req *req,
                                                               const
                                                               struct nk_arena *req_arena,
                                                               struct controlsys_OutputControllerInterface_InviteCard_res *res,
                                                               struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_OutputControllerInterface_InviteCard_mid);
    nk_msg_set_ncaps(req,
                     controlsys_OutputControllerInterface_InviteCard_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_OutputControllerInterface_InviteCard_mid);
    nk_msg_set_ncaps(res,
                     controlsys_OutputControllerInterface_InviteCard_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_OutputControllerInterface_RequestPIN_proxy(struct controlsys_OutputControllerInterface_proxy *self,
                                                               struct controlsys_OutputControllerInterface_RequestPIN_req *req,
                                                               const
                                                               struct nk_arena *req_arena,
                                                               struct controlsys_OutputControllerInterface_RequestPIN_res *res,
                                                               struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_OutputControllerInterface_RequestPIN_mid);
    nk_msg_set_ncaps(req,
                     controlsys_OutputControllerInterface_RequestPIN_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_OutputControllerInterface_RequestPIN_mid);
    nk_msg_set_ncaps(res,
                     controlsys_OutputControllerInterface_RequestPIN_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowStatus_proxy(struct controlsys_OutputControllerInterface_proxy *self,
                                                               struct controlsys_OutputControllerInterface_ShowStatus_req *req,
                                                               const
                                                               struct nk_arena *req_arena,
                                                               struct controlsys_OutputControllerInterface_ShowStatus_res *res,
                                                               struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_OutputControllerInterface_ShowStatus_mid);
    nk_msg_set_ncaps(req,
                     controlsys_OutputControllerInterface_ShowStatus_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_OutputControllerInterface_ShowStatus_mid);
    nk_msg_set_ncaps(res,
                     controlsys_OutputControllerInterface_ShowStatus_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowError_proxy(struct controlsys_OutputControllerInterface_proxy *self,
                                                              struct controlsys_OutputControllerInterface_ShowError_req *req,
                                                              const
                                                              struct nk_arena *req_arena,
                                                              struct controlsys_OutputControllerInterface_ShowError_res *res,
                                                              struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_OutputControllerInterface_ShowError_mid);
    nk_msg_set_ncaps(req,
                     controlsys_OutputControllerInterface_ShowError_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_OutputControllerInterface_ShowError_mid);
    nk_msg_set_ncaps(res,
                     controlsys_OutputControllerInterface_ShowError_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_OutputControllerInterface_PrintReceipt_proxy(struct controlsys_OutputControllerInterface_proxy *self,
                                                                 struct controlsys_OutputControllerInterface_PrintReceipt_req *req,
                                                                 const
                                                                 struct nk_arena *req_arena,
                                                                 struct controlsys_OutputControllerInterface_PrintReceipt_res *res,
                                                                 struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_OutputControllerInterface_PrintReceipt_mid);
    nk_msg_set_ncaps(req,
                     controlsys_OutputControllerInterface_PrintReceipt_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_OutputControllerInterface_PrintReceipt_mid);
    nk_msg_set_ncaps(res,
                     controlsys_OutputControllerInterface_PrintReceipt_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_OutputControllerInterface_proxy_init(struct controlsys_OutputControllerInterface_proxy *self,
                                                     struct nk_transport *transport,
                                                     nk_iid_t iid)
{
    static const
    struct controlsys_OutputControllerInterface_ops
    ops =
    {(controlsys_OutputControllerInterface_InviteCard_fn *) &controlsys_OutputControllerInterface_InviteCard_proxy,
     (controlsys_OutputControllerInterface_RequestPIN_fn *) &controlsys_OutputControllerInterface_RequestPIN_proxy,
     (controlsys_OutputControllerInterface_ShowStatus_fn *) &controlsys_OutputControllerInterface_ShowStatus_proxy,
     (controlsys_OutputControllerInterface_ShowError_fn *) &controlsys_OutputControllerInterface_ShowError_proxy,
     (controlsys_OutputControllerInterface_PrintReceipt_fn *) &controlsys_OutputControllerInterface_PrintReceipt_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_OutputControllerInterface_InviteCard(struct controlsys_OutputControllerInterface *self,
                                                         struct controlsys_OutputControllerInterface_InviteCard_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_OutputControllerInterface_InviteCard_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->InviteCard != NK_NULL);
    return self->ops->InviteCard(self, req,
                                 req_arena, res,
                                 res_arena);
}
static inline
nk_err_t controlsys_OutputControllerInterface_RequestPIN(struct controlsys_OutputControllerInterface *self,
                                                         struct controlsys_OutputControllerInterface_RequestPIN_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_OutputControllerInterface_RequestPIN_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->RequestPIN != NK_NULL);
    return self->ops->RequestPIN(self, req,
                                 req_arena, res,
                                 res_arena);
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowStatus(struct controlsys_OutputControllerInterface *self,
                                                         struct controlsys_OutputControllerInterface_ShowStatus_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_OutputControllerInterface_ShowStatus_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->ShowStatus != NK_NULL);
    return self->ops->ShowStatus(self, req,
                                 req_arena, res,
                                 res_arena);
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowError(struct controlsys_OutputControllerInterface *self,
                                                        struct controlsys_OutputControllerInterface_ShowError_req *req,
                                                        const
                                                        struct nk_arena *req_arena,
                                                        struct controlsys_OutputControllerInterface_ShowError_res *res,
                                                        struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->ShowError != NK_NULL);
    return self->ops->ShowError(self, req,
                                req_arena, res,
                                res_arena);
}
static inline
nk_err_t controlsys_OutputControllerInterface_PrintReceipt(struct controlsys_OutputControllerInterface *self,
                                                           struct controlsys_OutputControllerInterface_PrintReceipt_req *req,
                                                           const
                                                           struct nk_arena *req_arena,
                                                           struct controlsys_OutputControllerInterface_PrintReceipt_res *res,
                                                           struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->PrintReceipt != NK_NULL);
    return self->ops->PrintReceipt(self, req,
                                   req_arena, res,
                                   res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define OutputControllerInterface_InviteCard_proxy controlsys_OutputControllerInterface_InviteCard_proxy
#define OutputControllerInterface_RequestPIN_proxy controlsys_OutputControllerInterface_RequestPIN_proxy
#define OutputControllerInterface_ShowStatus_proxy controlsys_OutputControllerInterface_ShowStatus_proxy
#define OutputControllerInterface_ShowError_proxy controlsys_OutputControllerInterface_ShowError_proxy
#define OutputControllerInterface_PrintReceipt_proxy controlsys_OutputControllerInterface_PrintReceipt_proxy
#define OutputControllerInterface_InviteCard controlsys_OutputControllerInterface_InviteCard
#define OutputControllerInterface_RequestPIN controlsys_OutputControllerInterface_RequestPIN
#define OutputControllerInterface_ShowStatus controlsys_OutputControllerInterface_ShowStatus
#define OutputControllerInterface_ShowError controlsys_OutputControllerInterface_ShowError
#define OutputControllerInterface_PrintReceipt controlsys_OutputControllerInterface_PrintReceipt
#define OutputControllerInterface_proxy controlsys_OutputControllerInterface_proxy
#define OutputControllerInterface_proxy_init controlsys_OutputControllerInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__OutputControllerInterface__CLIENT__ */

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

#ifndef __controlsys__OutputControllerInterface__TESTS__
#define __controlsys__OutputControllerInterface__TESTS__
static inline
nk_err_t controlsys_OutputControllerInterface_InviteCard_test_req(struct controlsys_OutputControllerInterface_InviteCard_req *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    {
        struct {
            const int prob;
            nk_bool_t fail;
        } should_fail[] = {{1, NK_FALSE}, {2,
                                           NK_FALSE},
                           {4, NK_FALSE}};
        nk_size_t i;
        nk_size_t size =
                  nk_array_size(should_fail);
        int max = should_fail[size - 1].prob;
        int chosen = rand() % max;
        
        for (i = 0; i < size; i++) {
            if (should_fail[i].prob > chosen) {
                should_fail[i].fail = NK_TRUE;
                break;
            }
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 50 : rand() %
                             50);
            if (len1 > 49)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->txId,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        msg->amountCents = (nk_uint32_t) rand();
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[1].fail ? 10 : rand() %
                             10);
            if (len1 > 9)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->currency,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_InviteCard_test_res(struct controlsys_OutputControllerInterface_InviteCard_res *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_InviteCard_test_err(struct controlsys_OutputControllerInterface_InviteCard_err *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_RequestPIN_test_req(struct controlsys_OutputControllerInterface_RequestPIN_req *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    {
        struct {
            const int prob;
            nk_bool_t fail;
        } should_fail[] = {{1, NK_FALSE}, {2,
                                           NK_FALSE}};
        nk_size_t i;
        nk_size_t size =
                  nk_array_size(should_fail);
        int max = should_fail[size - 1].prob;
        int chosen = rand() % max;
        
        for (i = 0; i < size; i++) {
            if (should_fail[i].prob > chosen) {
                should_fail[i].fail = NK_TRUE;
                break;
            }
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 50 : rand() %
                             50);
            if (len1 > 49)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->txId,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_RequestPIN_test_res(struct controlsys_OutputControllerInterface_RequestPIN_res *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_RequestPIN_test_err(struct controlsys_OutputControllerInterface_RequestPIN_err *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowStatus_test_req(struct controlsys_OutputControllerInterface_ShowStatus_req *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    {
        struct {
            const int prob;
            nk_bool_t fail;
        } should_fail[] = {{1, NK_FALSE}, {2,
                                           NK_FALSE}};
        nk_size_t i;
        nk_size_t size =
                  nk_array_size(should_fail);
        int max = should_fail[size - 1].prob;
        int chosen = rand() % max;
        
        for (i = 0; i < size; i++) {
            if (should_fail[i].prob > chosen) {
                should_fail[i].fail = NK_TRUE;
                break;
            }
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 66 : rand() %
                             66);
            if (len1 > 65)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->message,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowStatus_test_res(struct controlsys_OutputControllerInterface_ShowStatus_res *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowStatus_test_err(struct controlsys_OutputControllerInterface_ShowStatus_err *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowError_test_req(struct controlsys_OutputControllerInterface_ShowError_req *msg,
                                                                 struct nk_arena *arena,
                                                                 int (*rand)(void),
                                                                 nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    {
        struct {
            const int prob;
            nk_bool_t fail;
        } should_fail[] = {{1, NK_FALSE}, {2,
                                           NK_FALSE}};
        nk_size_t i;
        nk_size_t size =
                  nk_array_size(should_fail);
        int max = should_fail[size - 1].prob;
        int chosen = rand() % max;
        
        for (i = 0; i < size; i++) {
            if (should_fail[i].prob > chosen) {
                should_fail[i].fail = NK_TRUE;
                break;
            }
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 66 : rand() %
                             66);
            if (len1 > 65)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->message,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowError_test_res(struct controlsys_OutputControllerInterface_ShowError_res *msg,
                                                                 struct nk_arena *arena,
                                                                 int (*rand)(void),
                                                                 nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_ShowError_test_err(struct controlsys_OutputControllerInterface_ShowError_err *msg,
                                                                 struct nk_arena *arena,
                                                                 int (*rand)(void),
                                                                 nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_PrintReceipt_test_req(struct controlsys_OutputControllerInterface_PrintReceipt_req *msg,
                                                                    struct nk_arena *arena,
                                                                    int (*rand)(void),
                                                                    nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    {
        struct {
            const int prob;
            nk_bool_t fail;
        } should_fail[] = {{1, NK_FALSE}, {2,
                                           NK_FALSE},
                           {4, NK_FALSE}};
        nk_size_t i;
        nk_size_t size =
                  nk_array_size(should_fail);
        int max = should_fail[size - 1].prob;
        int chosen = rand() % max;
        
        for (i = 0; i < size; i++) {
            if (should_fail[i].prob > chosen) {
                should_fail[i].fail = NK_TRUE;
                break;
            }
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 50 : rand() %
                             50);
            if (len1 > 49)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->txId,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        msg->amountCents = (nk_uint32_t) rand();
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[1].fail ? 10 : rand() %
                             10);
            if (len1 > 9)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->currency,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        msg->approved = (nk_uint8_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_PrintReceipt_test_res(struct controlsys_OutputControllerInterface_PrintReceipt_res *msg,
                                                                    struct nk_arena *arena,
                                                                    int (*rand)(void),
                                                                    nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}
static inline
nk_err_t controlsys_OutputControllerInterface_PrintReceipt_test_err(struct controlsys_OutputControllerInterface_PrintReceipt_err *msg,
                                                                    struct nk_arena *arena,
                                                                    int (*rand)(void),
                                                                    nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    return NK_EOK;
}

#endif /* __controlsys__OutputControllerInterface__TESTS__ */

#pragma GCC diagnostic pop

