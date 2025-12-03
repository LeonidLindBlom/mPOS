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

#ifndef __controlsys_JournalInterface__Bool__TYPEDEF__
#define __controlsys_JournalInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_JournalInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_Bool controlsys_JournalInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_JournalInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_JournalInterface__CurrencyLen__CONST__
#define __controlsys_JournalInterface__CurrencyLen__CONST__
#define controlsys_JournalInterface_CurrencyLen ((nk_uint8_t)(NK_UINT8_C(8)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_CurrencyLen controlsys_JournalInterface_CurrencyLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_JournalInterface__CurrencyLen__CONST__ */

#ifndef __controlsys_JournalInterface__RecordLen__CONST__
#define __controlsys_JournalInterface__RecordLen__CONST__
#define controlsys_JournalInterface_RecordLen ((nk_uint8_t)(NK_UINT8_C(128)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_RecordLen controlsys_JournalInterface_RecordLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_JournalInterface__RecordLen__CONST__ */

#ifndef __controlsys__JournalInterface__INTERFACE__
#define __controlsys__JournalInterface__INTERFACE__
enum {
    controlsys_JournalInterface_Append_mid,
    controlsys_JournalInterface_Export_mid,
    controlsys_JournalInterface_mid_max,
};
enum {
    controlsys_JournalInterface_Append_req_txId_size =
    49,
    controlsys_JournalInterface_Append_req_currency_size =
    9,
    controlsys_JournalInterface_Append_req_arena_size =
    58,
    controlsys_JournalInterface_Append_res_arena_size =
    0,
    controlsys_JournalInterface_Append_req_handles =
    0,
    controlsys_JournalInterface_Append_res_handles =
    0,
    controlsys_JournalInterface_Append_err_handles =
    0,
    controlsys_JournalInterface_Export_res_record_size =
    129,
    controlsys_JournalInterface_Export_req_arena_size =
    0,
    controlsys_JournalInterface_Export_res_arena_size =
    129,
    controlsys_JournalInterface_Export_req_handles =
    0,
    controlsys_JournalInterface_Export_res_handles =
    0,
    controlsys_JournalInterface_Export_err_handles =
    0,
    controlsys_JournalInterface_req_arena_size =
    58,
    controlsys_JournalInterface_res_arena_size =
    129,
    controlsys_JournalInterface_arena_size = 129,
    controlsys_JournalInterface_req_handles = 0,
    controlsys_JournalInterface_res_handles = 0,
    controlsys_JournalInterface_err_handles = 0,
};
typedef struct __nk_packed controlsys_JournalInterface_Append_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t txId;
            __nk_alignas(4)
            nk_uint32_t amountCents;
            __nk_alignas(4) nk_ptr_t currency;
            __nk_alignas(1) nk_uint8_t approved;
        } controlsys_JournalInterface_Append_req;
#pragma pack(push, 8) /* controlsys_JournalInterface_Append_res */
typedef struct controlsys_JournalInterface_Append_err {
            __nk_alignas(8)
            struct nk_message base_;
        } controlsys_JournalInterface_Append_err;
typedef struct controlsys_JournalInterface_Append_res {
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
                struct controlsys_JournalInterface_Append_err err_;
            };
        } controlsys_JournalInterface_Append_res;
#pragma pack(pop) /* controlsys_JournalInterface_Append_res */
typedef struct __nk_packed controlsys_JournalInterface_Export_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(2)
            nk_uint16_t maxRecords;
        } controlsys_JournalInterface_Export_req;
#pragma pack(push, 8) /* controlsys_JournalInterface_Export_res */
typedef struct controlsys_JournalInterface_Export_err {
            __nk_alignas(8)
            struct nk_message base_;
        } controlsys_JournalInterface_Export_err;
typedef struct controlsys_JournalInterface_Export_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t record;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t record;
                } res_;
                struct controlsys_JournalInterface_Export_err err_;
            };
        } controlsys_JournalInterface_Export_res;
#pragma pack(pop) /* controlsys_JournalInterface_Export_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_Append_mid controlsys_JournalInterface_Append_mid
#define JournalInterface_Export_mid controlsys_JournalInterface_Export_mid
#define JournalInterface_mid_max controlsys_JournalInterface_mid_max
#define JournalInterface_Append_req_txId_size controlsys_JournalInterface_Append_req_txId_size
#define JournalInterface_Append_req_currency_size controlsys_JournalInterface_Append_req_currency_size
#define JournalInterface_Append_req_arena_size controlsys_JournalInterface_Append_req_arena_size
#define JournalInterface_Append_res_arena_size controlsys_JournalInterface_Append_res_arena_size
#define JournalInterface_Append_req_handles controlsys_JournalInterface_Append_req_handles
#define JournalInterface_Append_res_handles controlsys_JournalInterface_Append_res_handles
#define JournalInterface_Append_err_handles controlsys_JournalInterface_Append_err_handles
#define JournalInterface_Export_res_record_size controlsys_JournalInterface_Export_res_record_size
#define JournalInterface_Export_req_arena_size controlsys_JournalInterface_Export_req_arena_size
#define JournalInterface_Export_res_arena_size controlsys_JournalInterface_Export_res_arena_size
#define JournalInterface_Export_req_handles controlsys_JournalInterface_Export_req_handles
#define JournalInterface_Export_res_handles controlsys_JournalInterface_Export_res_handles
#define JournalInterface_Export_err_handles controlsys_JournalInterface_Export_err_handles
#define JournalInterface_req_arena_size controlsys_JournalInterface_req_arena_size
#define JournalInterface_res_arena_size controlsys_JournalInterface_res_arena_size
#define JournalInterface_arena_size controlsys_JournalInterface_arena_size
#define JournalInterface_req_handles controlsys_JournalInterface_req_handles
#define JournalInterface_res_handles controlsys_JournalInterface_res_handles
#define JournalInterface_err_handles controlsys_JournalInterface_err_handles
#define JournalInterface_Append_req controlsys_JournalInterface_Append_req
#define JournalInterface_Append_res controlsys_JournalInterface_Append_res
#define JournalInterface_Export_req controlsys_JournalInterface_Export_req
#define JournalInterface_Export_res controlsys_JournalInterface_Export_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__JournalInterface__INTERFACE__ */

#ifndef __controlsys__JournalInterface__VTABLE__
#define __controlsys__JournalInterface__VTABLE__
typedef struct controlsys_JournalInterface {
            const
            struct controlsys_JournalInterface_ops *ops;
        } controlsys_JournalInterface;
typedef nk_err_t
controlsys_JournalInterface_Append_fn(struct controlsys_JournalInterface *,
                                      const
                                      struct controlsys_JournalInterface_Append_req *,
                                      const
                                      struct nk_arena *,
                                      struct controlsys_JournalInterface_Append_res *,
                                      struct nk_arena *);
typedef nk_err_t
controlsys_JournalInterface_Export_fn(struct controlsys_JournalInterface *,
                                      const
                                      struct controlsys_JournalInterface_Export_req *,
                                      const
                                      struct nk_arena *,
                                      struct controlsys_JournalInterface_Export_res *,
                                      struct nk_arena *);
typedef struct controlsys_JournalInterface_ops {
            controlsys_JournalInterface_Append_fn *Append;
            controlsys_JournalInterface_Export_fn *Export;
        } controlsys_JournalInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_Append_fn controlsys_JournalInterface_Append_fn
#define JournalInterface_Export_fn controlsys_JournalInterface_Export_fn
#define JournalInterface_ops controlsys_JournalInterface_ops
#define JournalInterface controlsys_JournalInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__JournalInterface__VTABLE__ */

#ifndef __controlsys__JournalInterface__CLIENT__
#define __controlsys__JournalInterface__CLIENT__
typedef struct controlsys_JournalInterface_proxy {
            struct controlsys_JournalInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_JournalInterface_proxy;
static inline
nk_err_t controlsys_JournalInterface_Append_proxy(struct controlsys_JournalInterface_proxy *self,
                                                  struct controlsys_JournalInterface_Append_req *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct controlsys_JournalInterface_Append_res *res,
                                                  struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_JournalInterface_Append_mid);
    nk_msg_set_ncaps(req,
                     controlsys_JournalInterface_Append_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_JournalInterface_Append_mid);
    nk_msg_set_ncaps(res,
                     controlsys_JournalInterface_Append_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_JournalInterface_Export_proxy(struct controlsys_JournalInterface_proxy *self,
                                                  struct controlsys_JournalInterface_Export_req *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct controlsys_JournalInterface_Export_res *res,
                                                  struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_JournalInterface_Export_mid);
    nk_msg_set_ncaps(req,
                     controlsys_JournalInterface_Export_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_JournalInterface_Export_mid);
    nk_msg_set_ncaps(res,
                     controlsys_JournalInterface_Export_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_JournalInterface_proxy_init(struct controlsys_JournalInterface_proxy *self,
                                            struct nk_transport *transport,
                                            nk_iid_t iid)
{
    static const
    struct controlsys_JournalInterface_ops ops =
                                           {(controlsys_JournalInterface_Append_fn *) &controlsys_JournalInterface_Append_proxy,
                                            (controlsys_JournalInterface_Export_fn *) &controlsys_JournalInterface_Export_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_JournalInterface_Append(struct controlsys_JournalInterface *self,
                                            struct controlsys_JournalInterface_Append_req *req,
                                            const
                                            struct nk_arena *req_arena,
                                            struct controlsys_JournalInterface_Append_res *res,
                                            struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Append != NK_NULL);
    return self->ops->Append(self, req, req_arena,
                             res, res_arena);
}
static inline
nk_err_t controlsys_JournalInterface_Export(struct controlsys_JournalInterface *self,
                                            struct controlsys_JournalInterface_Export_req *req,
                                            const
                                            struct nk_arena *req_arena,
                                            struct controlsys_JournalInterface_Export_res *res,
                                            struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Export != NK_NULL);
    return self->ops->Export(self, req, req_arena,
                             res, res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define JournalInterface_Append_proxy controlsys_JournalInterface_Append_proxy
#define JournalInterface_Export_proxy controlsys_JournalInterface_Export_proxy
#define JournalInterface_Append controlsys_JournalInterface_Append
#define JournalInterface_Export controlsys_JournalInterface_Export
#define JournalInterface_proxy controlsys_JournalInterface_proxy
#define JournalInterface_proxy_init controlsys_JournalInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__JournalInterface__CLIENT__ */

#ifndef __controlsys__JournalInterface__SERVER__
#define __controlsys__JournalInterface__SERVER__
typedef union controlsys_JournalInterface_req {
            struct nk_message base_;
            struct controlsys_JournalInterface_Append_req Append;
            struct controlsys_JournalInterface_Export_req Export;
        } controlsys_JournalInterface_req;
typedef union controlsys_JournalInterface_res {
            struct nk_message base_;
            struct controlsys_JournalInterface_Append_res Append;
            struct controlsys_JournalInterface_Export_res Export;
        } controlsys_JournalInterface_res;
static inline
nk_err_t controlsys_JournalInterface_interface_dispatch(struct controlsys_JournalInterface *impl,
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
            
          case controlsys_JournalInterface_Append_mid:
            {
                struct controlsys_JournalInterface_Append_res
                *res_ =
                (struct controlsys_JournalInterface_Append_res *) res;
                
                rc = impl->ops->Append(impl,
                                       (const
                                        struct controlsys_JournalInterface_Append_req *) req,
                                       req_arena,
                                       res_,
                                       res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_JournalInterface_Append_res_handles);
                }
                break;
            }
            
          case controlsys_JournalInterface_Export_mid:
            {
                struct controlsys_JournalInterface_Export_res
                *res_ =
                (struct controlsys_JournalInterface_Export_res *) res;
                
                rc = impl->ops->Export(impl,
                                       (const
                                        struct controlsys_JournalInterface_Export_req *) req,
                                       req_arena,
                                       res_,
                                       res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_JournalInterface_Export_res_handles);
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
#define JournalInterface_req controlsys_JournalInterface_req
#define JournalInterface_res controlsys_JournalInterface_res
#define JournalInterface_interface_dispatch controlsys_JournalInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__JournalInterface__SERVER__ */

#ifndef __controlsys__JournalInterface__TESTS__
#define __controlsys__JournalInterface__TESTS__
static inline
nk_err_t controlsys_JournalInterface_Append_test_req(struct controlsys_JournalInterface_Append_req *msg,
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
nk_err_t controlsys_JournalInterface_Append_test_res(struct controlsys_JournalInterface_Append_res *msg,
                                                     struct nk_arena *arena,
                                                     int (*rand)(void),
                                                     nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->ok = (nk_uint8_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_JournalInterface_Append_test_err(struct controlsys_JournalInterface_Append_err *msg,
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
nk_err_t controlsys_JournalInterface_Export_test_req(struct controlsys_JournalInterface_Export_req *msg,
                                                     struct nk_arena *arena,
                                                     int (*rand)(void),
                                                     nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->maxRecords = (nk_uint16_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_JournalInterface_Export_test_res(struct controlsys_JournalInterface_Export_res *msg,
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
                (nk_size_t) (should_fail[0].fail ? 130 : rand() %
                             130);
            if (len1 > 129)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->record,
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
nk_err_t controlsys_JournalInterface_Export_test_err(struct controlsys_JournalInterface_Export_err *msg,
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

#endif /* __controlsys__JournalInterface__TESTS__ */

#pragma GCC diagnostic pop

