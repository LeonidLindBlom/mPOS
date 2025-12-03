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

#ifndef __controlsys_InputGuardInterface__Bool__TYPEDEF__
#define __controlsys_InputGuardInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_InputGuardInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuardInterface_Bool controlsys_InputGuardInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_InputGuardInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_InputGuardInterface__CurrencyLen__CONST__
#define __controlsys_InputGuardInterface__CurrencyLen__CONST__
#define controlsys_InputGuardInterface_CurrencyLen ((nk_uint8_t)(NK_UINT8_C(8)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuardInterface_CurrencyLen controlsys_InputGuardInterface_CurrencyLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_InputGuardInterface__CurrencyLen__CONST__ */

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

#ifndef __controlsys__InputGuardInterface__CLIENT__
#define __controlsys__InputGuardInterface__CLIENT__
typedef struct controlsys_InputGuardInterface_proxy {
            struct controlsys_InputGuardInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_InputGuardInterface_proxy;
static inline
nk_err_t controlsys_InputGuardInterface_Heartbeat_proxy(struct controlsys_InputGuardInterface_proxy *self,
                                                        struct controlsys_InputGuardInterface_Heartbeat_req *req,
                                                        const
                                                        struct nk_arena *req_arena,
                                                        struct controlsys_InputGuardInterface_Heartbeat_res *res,
                                                        struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_InputGuardInterface_Heartbeat_mid);
    nk_msg_set_ncaps(req,
                     controlsys_InputGuardInterface_Heartbeat_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_InputGuardInterface_Heartbeat_mid);
    nk_msg_set_ncaps(res,
                     controlsys_InputGuardInterface_Heartbeat_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_InputGuardInterface_BeginTransaction_proxy(struct controlsys_InputGuardInterface_proxy *self,
                                                               struct controlsys_InputGuardInterface_BeginTransaction_req *req,
                                                               const
                                                               struct nk_arena *req_arena,
                                                               struct controlsys_InputGuardInterface_BeginTransaction_res *res,
                                                               struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_InputGuardInterface_BeginTransaction_mid);
    nk_msg_set_ncaps(req,
                     controlsys_InputGuardInterface_BeginTransaction_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_InputGuardInterface_BeginTransaction_mid);
    nk_msg_set_ncaps(res,
                     controlsys_InputGuardInterface_BeginTransaction_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_InputGuardInterface_proxy_init(struct controlsys_InputGuardInterface_proxy *self,
                                               struct nk_transport *transport,
                                               nk_iid_t iid)
{
    static const
    struct controlsys_InputGuardInterface_ops ops
                                              =
                                              {(controlsys_InputGuardInterface_Heartbeat_fn *) &controlsys_InputGuardInterface_Heartbeat_proxy,
                                               (controlsys_InputGuardInterface_BeginTransaction_fn *) &controlsys_InputGuardInterface_BeginTransaction_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_InputGuardInterface_Heartbeat(struct controlsys_InputGuardInterface *self,
                                                  struct controlsys_InputGuardInterface_Heartbeat_req *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct controlsys_InputGuardInterface_Heartbeat_res *res,
                                                  struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Heartbeat != NK_NULL);
    return self->ops->Heartbeat(self, req,
                                req_arena, res,
                                res_arena);
}
static inline
nk_err_t controlsys_InputGuardInterface_BeginTransaction(struct controlsys_InputGuardInterface *self,
                                                         struct controlsys_InputGuardInterface_BeginTransaction_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_InputGuardInterface_BeginTransaction_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->BeginTransaction !=
        NK_NULL);
    return self->ops->BeginTransaction(self, req,
                                       req_arena,
                                       res,
                                       res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define InputGuardInterface_Heartbeat_proxy controlsys_InputGuardInterface_Heartbeat_proxy
#define InputGuardInterface_BeginTransaction_proxy controlsys_InputGuardInterface_BeginTransaction_proxy
#define InputGuardInterface_Heartbeat controlsys_InputGuardInterface_Heartbeat
#define InputGuardInterface_BeginTransaction controlsys_InputGuardInterface_BeginTransaction
#define InputGuardInterface_proxy controlsys_InputGuardInterface_proxy
#define InputGuardInterface_proxy_init controlsys_InputGuardInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__InputGuardInterface__CLIENT__ */

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

#ifndef __controlsys__InputGuardInterface__TESTS__
#define __controlsys__InputGuardInterface__TESTS__
static inline
nk_err_t controlsys_InputGuardInterface_Heartbeat_test_req(struct controlsys_InputGuardInterface_Heartbeat_req *msg,
                                                           struct nk_arena *arena,
                                                           int (*rand)(void),
                                                           nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->networkOk = (nk_uint8_t) rand();
    msg->pingOk = (nk_uint8_t) rand();
    msg->powerOk = (nk_uint8_t) rand();
    msg->signalStrength = (nk_uint16_t) rand();
    msg->soc = (nk_uint16_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_InputGuardInterface_Heartbeat_test_res(struct controlsys_InputGuardInterface_Heartbeat_res *msg,
                                                           struct nk_arena *arena,
                                                           int (*rand)(void),
                                                           nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->powerReady = (nk_uint8_t) rand();
    msg->networkReady = (nk_uint8_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_InputGuardInterface_Heartbeat_test_err(struct controlsys_InputGuardInterface_Heartbeat_err *msg,
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
nk_err_t controlsys_InputGuardInterface_BeginTransaction_test_req(struct controlsys_InputGuardInterface_BeginTransaction_req *msg,
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
        msg->amountCents = (nk_uint32_t) rand();
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[0].fail ? 10 : rand() %
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
nk_err_t controlsys_InputGuardInterface_BeginTransaction_test_res(struct controlsys_InputGuardInterface_BeginTransaction_res *msg,
                                                                  struct nk_arena *arena,
                                                                  int (*rand)(void),
                                                                  nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->allowed = (nk_uint8_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_InputGuardInterface_BeginTransaction_test_err(struct controlsys_InputGuardInterface_BeginTransaction_err *msg,
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

#endif /* __controlsys__InputGuardInterface__TESTS__ */

#pragma GCC diagnostic pop

