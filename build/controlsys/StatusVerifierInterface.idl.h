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

#ifndef __controlsys_StatusVerifierInterface__Bool__TYPEDEF__
#define __controlsys_StatusVerifierInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_StatusVerifierInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifierInterface_Bool controlsys_StatusVerifierInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_StatusVerifierInterface__Bool__TYPEDEF__ */

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

#ifndef __controlsys__StatusVerifierInterface__CLIENT__
#define __controlsys__StatusVerifierInterface__CLIENT__
typedef struct controlsys_StatusVerifierInterface_proxy {
            struct controlsys_StatusVerifierInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        }
controlsys_StatusVerifierInterface_proxy;
static inline
nk_err_t controlsys_StatusVerifierInterface_Validate_proxy(struct controlsys_StatusVerifierInterface_proxy *self,
                                                           struct controlsys_StatusVerifierInterface_Validate_req *req,
                                                           const
                                                           struct nk_arena *req_arena,
                                                           struct controlsys_StatusVerifierInterface_Validate_res *res,
                                                           struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_StatusVerifierInterface_Validate_mid);
    nk_msg_set_ncaps(req,
                     controlsys_StatusVerifierInterface_Validate_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_StatusVerifierInterface_Validate_mid);
    nk_msg_set_ncaps(res,
                     controlsys_StatusVerifierInterface_Validate_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_StatusVerifierInterface_proxy_init(struct controlsys_StatusVerifierInterface_proxy *self,
                                                   struct nk_transport *transport,
                                                   nk_iid_t iid)
{
    static const
    struct controlsys_StatusVerifierInterface_ops
    ops =
    {(controlsys_StatusVerifierInterface_Validate_fn *) &controlsys_StatusVerifierInterface_Validate_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_StatusVerifierInterface_Validate(struct controlsys_StatusVerifierInterface *self,
                                                     struct controlsys_StatusVerifierInterface_Validate_req *req,
                                                     const
                                                     struct nk_arena *req_arena,
                                                     struct controlsys_StatusVerifierInterface_Validate_res *res,
                                                     struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Validate != NK_NULL);
    return self->ops->Validate(self, req,
                               req_arena, res,
                               res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define StatusVerifierInterface_Validate_proxy controlsys_StatusVerifierInterface_Validate_proxy
#define StatusVerifierInterface_Validate controlsys_StatusVerifierInterface_Validate
#define StatusVerifierInterface_proxy controlsys_StatusVerifierInterface_proxy
#define StatusVerifierInterface_proxy_init controlsys_StatusVerifierInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__StatusVerifierInterface__CLIENT__ */

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

#ifndef __controlsys__StatusVerifierInterface__TESTS__
#define __controlsys__StatusVerifierInterface__TESTS__
static inline
nk_err_t controlsys_StatusVerifierInterface_Validate_test_req(struct controlsys_StatusVerifierInterface_Validate_req *msg,
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
        msg->seqNumber = (nk_uint32_t) rand();
        msg->approved = (nk_uint8_t) rand();
        msg->latencyMs = (nk_uint32_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_StatusVerifierInterface_Validate_test_res(struct controlsys_StatusVerifierInterface_Validate_res *msg,
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
nk_err_t controlsys_StatusVerifierInterface_Validate_test_err(struct controlsys_StatusVerifierInterface_Validate_err *msg,
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

#endif /* __controlsys__StatusVerifierInterface__TESTS__ */

#pragma GCC diagnostic pop

