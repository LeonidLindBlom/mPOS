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

#ifndef __controlsys_TransactionGeneratorInterface__Bool__TYPEDEF__
#define __controlsys_TransactionGeneratorInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_TransactionGeneratorInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_Bool controlsys_TransactionGeneratorInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_TransactionGeneratorInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_TransactionGeneratorInterface__CurrencyLen__CONST__
#define __controlsys_TransactionGeneratorInterface__CurrencyLen__CONST__
#define controlsys_TransactionGeneratorInterface_CurrencyLen ((nk_uint8_t)(NK_UINT8_C(8)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_CurrencyLen controlsys_TransactionGeneratorInterface_CurrencyLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_TransactionGeneratorInterface__CurrencyLen__CONST__ */

#ifndef __controlsys_TransactionGeneratorInterface__PayloadLen__CONST__
#define __controlsys_TransactionGeneratorInterface__PayloadLen__CONST__
#define controlsys_TransactionGeneratorInterface_PayloadLen ((nk_uint8_t)(NK_UINT8_C(64)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_PayloadLen controlsys_TransactionGeneratorInterface_PayloadLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_TransactionGeneratorInterface__PayloadLen__CONST__ */

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

#ifndef __controlsys__TransactionGeneratorInterface__CLIENT__
#define __controlsys__TransactionGeneratorInterface__CLIENT__
typedef struct controlsys_TransactionGeneratorInterface_proxy {
            struct controlsys_TransactionGeneratorInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        }
controlsys_TransactionGeneratorInterface_proxy;
static inline
nk_err_t controlsys_TransactionGeneratorInterface_Build_proxy(struct controlsys_TransactionGeneratorInterface_proxy *self,
                                                              struct controlsys_TransactionGeneratorInterface_Build_req *req,
                                                              const
                                                              struct nk_arena *req_arena,
                                                              struct controlsys_TransactionGeneratorInterface_Build_res *res,
                                                              struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_TransactionGeneratorInterface_Build_mid);
    nk_msg_set_ncaps(req,
                     controlsys_TransactionGeneratorInterface_Build_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_TransactionGeneratorInterface_Build_mid);
    nk_msg_set_ncaps(res,
                     controlsys_TransactionGeneratorInterface_Build_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_TransactionGeneratorInterface_proxy_init(struct controlsys_TransactionGeneratorInterface_proxy *self,
                                                         struct nk_transport *transport,
                                                         nk_iid_t iid)
{
    static const
    struct controlsys_TransactionGeneratorInterface_ops
    ops =
    {(controlsys_TransactionGeneratorInterface_Build_fn *) &controlsys_TransactionGeneratorInterface_Build_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_TransactionGeneratorInterface_Build(struct controlsys_TransactionGeneratorInterface *self,
                                                        struct controlsys_TransactionGeneratorInterface_Build_req *req,
                                                        const
                                                        struct nk_arena *req_arena,
                                                        struct controlsys_TransactionGeneratorInterface_Build_res *res,
                                                        struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Build != NK_NULL);
    return self->ops->Build(self, req, req_arena,
                            res, res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define TransactionGeneratorInterface_Build_proxy controlsys_TransactionGeneratorInterface_Build_proxy
#define TransactionGeneratorInterface_Build controlsys_TransactionGeneratorInterface_Build
#define TransactionGeneratorInterface_proxy controlsys_TransactionGeneratorInterface_proxy
#define TransactionGeneratorInterface_proxy_init controlsys_TransactionGeneratorInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__TransactionGeneratorInterface__CLIENT__ */

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

#ifndef __controlsys__TransactionGeneratorInterface__TESTS__
#define __controlsys__TransactionGeneratorInterface__TESTS__
static inline
nk_err_t controlsys_TransactionGeneratorInterface_Build_test_req(struct controlsys_TransactionGeneratorInterface_Build_req *msg,
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
nk_err_t controlsys_TransactionGeneratorInterface_Build_test_res(struct controlsys_TransactionGeneratorInterface_Build_res *msg,
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
                                     &msg->payload,
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
nk_err_t controlsys_TransactionGeneratorInterface_Build_test_err(struct controlsys_TransactionGeneratorInterface_Build_err *msg,
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

#endif /* __controlsys__TransactionGeneratorInterface__TESTS__ */

#pragma GCC diagnostic pop

