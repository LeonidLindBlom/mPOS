#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef ____UInt8__RAWTYPE__
#define ____UInt8__RAWTYPE__
nk_static_assert(sizeof(nk_uint8_t) == 1, bad_nk_uint8_t_size);
nk_static_assert(nk_alignof(nk_uint8_t) == 1, bad_nk_uint8_t_align);

#endif /* ____UInt8__RAWTYPE__ */

#ifndef __controlsys_CardVerifierInterface__Bool__TYPEDEF__
#define __controlsys_CardVerifierInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_CardVerifierInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_Bool controlsys_CardVerifierInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_CardVerifierInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_CardVerifierInterface__ExpiryLen__CONST__
#define __controlsys_CardVerifierInterface__ExpiryLen__CONST__
#define controlsys_CardVerifierInterface_ExpiryLen ((nk_uint8_t)(NK_UINT8_C(8)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_ExpiryLen controlsys_CardVerifierInterface_ExpiryLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_CardVerifierInterface__ExpiryLen__CONST__ */

#ifndef __controlsys_CardVerifierInterface__HolderLen__CONST__
#define __controlsys_CardVerifierInterface__HolderLen__CONST__
#define controlsys_CardVerifierInterface_HolderLen ((nk_uint8_t)(NK_UINT8_C(32)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_HolderLen controlsys_CardVerifierInterface_HolderLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_CardVerifierInterface__HolderLen__CONST__ */

#ifndef __controlsys_CardVerifierInterface__PanLen__CONST__
#define __controlsys_CardVerifierInterface__PanLen__CONST__
#define controlsys_CardVerifierInterface_PanLen ((nk_uint8_t)(NK_UINT8_C(32)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_PanLen controlsys_CardVerifierInterface_PanLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_CardVerifierInterface__PanLen__CONST__ */

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

#ifndef __controlsys__CardVerifierInterface__CLIENT__
#define __controlsys__CardVerifierInterface__CLIENT__
typedef struct controlsys_CardVerifierInterface_proxy {
            struct controlsys_CardVerifierInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_CardVerifierInterface_proxy;
static inline
nk_err_t controlsys_CardVerifierInterface_CheckCard_proxy(struct controlsys_CardVerifierInterface_proxy *self,
                                                          struct controlsys_CardVerifierInterface_CheckCard_req *req,
                                                          const
                                                          struct nk_arena *req_arena,
                                                          struct controlsys_CardVerifierInterface_CheckCard_res *res,
                                                          struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_CardVerifierInterface_CheckCard_mid);
    nk_msg_set_ncaps(req,
                     controlsys_CardVerifierInterface_CheckCard_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_CardVerifierInterface_CheckCard_mid);
    nk_msg_set_ncaps(res,
                     controlsys_CardVerifierInterface_CheckCard_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_CardVerifierInterface_proxy_init(struct controlsys_CardVerifierInterface_proxy *self,
                                                 struct nk_transport *transport,
                                                 nk_iid_t iid)
{
    static const
    struct controlsys_CardVerifierInterface_ops
    ops =
    {(controlsys_CardVerifierInterface_CheckCard_fn *) &controlsys_CardVerifierInterface_CheckCard_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_CardVerifierInterface_CheckCard(struct controlsys_CardVerifierInterface *self,
                                                    struct controlsys_CardVerifierInterface_CheckCard_req *req,
                                                    const
                                                    struct nk_arena *req_arena,
                                                    struct controlsys_CardVerifierInterface_CheckCard_res *res,
                                                    struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->CheckCard != NK_NULL);
    return self->ops->CheckCard(self, req,
                                req_arena, res,
                                res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define CardVerifierInterface_CheckCard_proxy controlsys_CardVerifierInterface_CheckCard_proxy
#define CardVerifierInterface_CheckCard controlsys_CardVerifierInterface_CheckCard
#define CardVerifierInterface_proxy controlsys_CardVerifierInterface_proxy
#define CardVerifierInterface_proxy_init controlsys_CardVerifierInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__CardVerifierInterface__CLIENT__ */

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

#ifndef __controlsys__CardVerifierInterface__TESTS__
#define __controlsys__CardVerifierInterface__TESTS__
static inline
nk_err_t controlsys_CardVerifierInterface_CheckCard_test_req(struct controlsys_CardVerifierInterface_CheckCard_req *msg,
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
                           {3, NK_FALSE}, {6,
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
                (nk_size_t) (should_fail[0].fail ? 34 : rand() %
                             34);
            if (len1 > 33)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->panMasked,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
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
                                     &msg->expiry,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        {
            nk_uint8_t *string2;
            nk_size_t len1;
            nk_size_t i0;
            
            nk_unused(string2);
            nk_unused(len1);
            nk_unused(i0);
            len1 =
                (nk_size_t) (should_fail[2].fail ? 34 : rand() %
                             34);
            if (len1 > 33)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->holder,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        msg->emvOk = (nk_uint8_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_CardVerifierInterface_CheckCard_test_res(struct controlsys_CardVerifierInterface_CheckCard_res *msg,
                                                             struct nk_arena *arena,
                                                             int (*rand)(void),
                                                             nk_bool_t *failure)
{
    nk_unused(msg);
    nk_unused(arena);
    nk_unused(rand);
    *failure = NK_FALSE;
    msg->accepted = (nk_uint8_t) rand();
    return NK_EOK;
}
static inline
nk_err_t controlsys_CardVerifierInterface_CheckCard_test_err(struct controlsys_CardVerifierInterface_CheckCard_err *msg,
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

#endif /* __controlsys__CardVerifierInterface__TESTS__ */

#pragma GCC diagnostic pop

