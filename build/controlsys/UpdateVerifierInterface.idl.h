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

#ifndef __controlsys_UpdateVerifierInterface__Bool__TYPEDEF__
#define __controlsys_UpdateVerifierInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_UpdateVerifierInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifierInterface_Bool controlsys_UpdateVerifierInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateVerifierInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_UpdateVerifierInterface__VersionLen__CONST__
#define __controlsys_UpdateVerifierInterface__VersionLen__CONST__
#define controlsys_UpdateVerifierInterface_VersionLen ((nk_uint8_t)(NK_UINT8_C(16)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifierInterface_VersionLen controlsys_UpdateVerifierInterface_VersionLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateVerifierInterface__VersionLen__CONST__ */

#ifndef __controlsys__UpdateVerifierInterface__INTERFACE__
#define __controlsys__UpdateVerifierInterface__INTERFACE__
enum {
    controlsys_UpdateVerifierInterface_Verify_mid,
    controlsys_UpdateVerifierInterface_mid_max,
};
enum {
    controlsys_UpdateVerifierInterface_Verify_req_version_size =
    17,
    controlsys_UpdateVerifierInterface_Verify_req_arena_size =
    17,
    controlsys_UpdateVerifierInterface_Verify_res_arena_size =
    0,
    controlsys_UpdateVerifierInterface_Verify_req_handles =
    0,
    controlsys_UpdateVerifierInterface_Verify_res_handles =
    0,
    controlsys_UpdateVerifierInterface_Verify_err_handles =
    0,
    controlsys_UpdateVerifierInterface_req_arena_size =
    17,
    controlsys_UpdateVerifierInterface_res_arena_size =
    0,
    controlsys_UpdateVerifierInterface_arena_size =
    17,
    controlsys_UpdateVerifierInterface_req_handles =
    0,
    controlsys_UpdateVerifierInterface_res_handles =
    0,
    controlsys_UpdateVerifierInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_UpdateVerifierInterface_Verify_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t version;
            __nk_alignas(4) nk_uint32_t totalSize;
            __nk_alignas(1)
            nk_uint8_t signatureOk;
        }
controlsys_UpdateVerifierInterface_Verify_req;
#pragma pack(push, 8) /* controlsys_UpdateVerifierInterface_Verify_res */
typedef struct controlsys_UpdateVerifierInterface_Verify_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateVerifierInterface_Verify_err;
typedef struct controlsys_UpdateVerifierInterface_Verify_res {
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
                struct controlsys_UpdateVerifierInterface_Verify_err err_;
            };
        }
controlsys_UpdateVerifierInterface_Verify_res;
#pragma pack(pop) /* controlsys_UpdateVerifierInterface_Verify_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifierInterface_Verify_mid controlsys_UpdateVerifierInterface_Verify_mid
#define UpdateVerifierInterface_mid_max controlsys_UpdateVerifierInterface_mid_max
#define UpdateVerifierInterface_Verify_req_version_size controlsys_UpdateVerifierInterface_Verify_req_version_size
#define UpdateVerifierInterface_Verify_req_arena_size controlsys_UpdateVerifierInterface_Verify_req_arena_size
#define UpdateVerifierInterface_Verify_res_arena_size controlsys_UpdateVerifierInterface_Verify_res_arena_size
#define UpdateVerifierInterface_Verify_req_handles controlsys_UpdateVerifierInterface_Verify_req_handles
#define UpdateVerifierInterface_Verify_res_handles controlsys_UpdateVerifierInterface_Verify_res_handles
#define UpdateVerifierInterface_Verify_err_handles controlsys_UpdateVerifierInterface_Verify_err_handles
#define UpdateVerifierInterface_req_arena_size controlsys_UpdateVerifierInterface_req_arena_size
#define UpdateVerifierInterface_res_arena_size controlsys_UpdateVerifierInterface_res_arena_size
#define UpdateVerifierInterface_arena_size controlsys_UpdateVerifierInterface_arena_size
#define UpdateVerifierInterface_req_handles controlsys_UpdateVerifierInterface_req_handles
#define UpdateVerifierInterface_res_handles controlsys_UpdateVerifierInterface_res_handles
#define UpdateVerifierInterface_err_handles controlsys_UpdateVerifierInterface_err_handles
#define UpdateVerifierInterface_Verify_req controlsys_UpdateVerifierInterface_Verify_req
#define UpdateVerifierInterface_Verify_res controlsys_UpdateVerifierInterface_Verify_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifierInterface__INTERFACE__ */

#ifndef __controlsys__UpdateVerifierInterface__VTABLE__
#define __controlsys__UpdateVerifierInterface__VTABLE__
typedef struct controlsys_UpdateVerifierInterface {
            const
            struct controlsys_UpdateVerifierInterface_ops *ops;
        } controlsys_UpdateVerifierInterface;
typedef nk_err_t
controlsys_UpdateVerifierInterface_Verify_fn(struct controlsys_UpdateVerifierInterface *,
                                             const
                                             struct controlsys_UpdateVerifierInterface_Verify_req *,
                                             const
                                             struct nk_arena *,
                                             struct controlsys_UpdateVerifierInterface_Verify_res *,
                                             struct nk_arena *);
typedef struct controlsys_UpdateVerifierInterface_ops {
            controlsys_UpdateVerifierInterface_Verify_fn *Verify;
        } controlsys_UpdateVerifierInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifierInterface_Verify_fn controlsys_UpdateVerifierInterface_Verify_fn
#define UpdateVerifierInterface_ops controlsys_UpdateVerifierInterface_ops
#define UpdateVerifierInterface controlsys_UpdateVerifierInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifierInterface__VTABLE__ */

#ifndef __controlsys__UpdateVerifierInterface__CLIENT__
#define __controlsys__UpdateVerifierInterface__CLIENT__
typedef struct controlsys_UpdateVerifierInterface_proxy {
            struct controlsys_UpdateVerifierInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        }
controlsys_UpdateVerifierInterface_proxy;
static inline
nk_err_t controlsys_UpdateVerifierInterface_Verify_proxy(struct controlsys_UpdateVerifierInterface_proxy *self,
                                                         struct controlsys_UpdateVerifierInterface_Verify_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_UpdateVerifierInterface_Verify_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateVerifierInterface_Verify_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateVerifierInterface_Verify_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateVerifierInterface_Verify_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateVerifierInterface_Verify_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_UpdateVerifierInterface_proxy_init(struct controlsys_UpdateVerifierInterface_proxy *self,
                                                   struct nk_transport *transport,
                                                   nk_iid_t iid)
{
    static const
    struct controlsys_UpdateVerifierInterface_ops
    ops =
    {(controlsys_UpdateVerifierInterface_Verify_fn *) &controlsys_UpdateVerifierInterface_Verify_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_UpdateVerifierInterface_Verify(struct controlsys_UpdateVerifierInterface *self,
                                                   struct controlsys_UpdateVerifierInterface_Verify_req *req,
                                                   const
                                                   struct nk_arena *req_arena,
                                                   struct controlsys_UpdateVerifierInterface_Verify_res *res,
                                                   struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Verify != NK_NULL);
    return self->ops->Verify(self, req, req_arena,
                             res, res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifierInterface_Verify_proxy controlsys_UpdateVerifierInterface_Verify_proxy
#define UpdateVerifierInterface_Verify controlsys_UpdateVerifierInterface_Verify
#define UpdateVerifierInterface_proxy controlsys_UpdateVerifierInterface_proxy
#define UpdateVerifierInterface_proxy_init controlsys_UpdateVerifierInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifierInterface__CLIENT__ */

#ifndef __controlsys__UpdateVerifierInterface__SERVER__
#define __controlsys__UpdateVerifierInterface__SERVER__
typedef union controlsys_UpdateVerifierInterface_req {
            struct nk_message base_;
            struct controlsys_UpdateVerifierInterface_Verify_req Verify;
        } controlsys_UpdateVerifierInterface_req;
typedef union controlsys_UpdateVerifierInterface_res {
            struct nk_message base_;
            struct controlsys_UpdateVerifierInterface_Verify_res Verify;
        } controlsys_UpdateVerifierInterface_res;
static inline
nk_err_t controlsys_UpdateVerifierInterface_interface_dispatch(struct controlsys_UpdateVerifierInterface *impl,
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
            
          case controlsys_UpdateVerifierInterface_Verify_mid:
            {
                struct controlsys_UpdateVerifierInterface_Verify_res
                *res_ =
                (struct controlsys_UpdateVerifierInterface_Verify_res *) res;
                
                rc = impl->ops->Verify(impl,
                                       (const
                                        struct controlsys_UpdateVerifierInterface_Verify_req *) req,
                                       req_arena,
                                       res_,
                                       res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateVerifierInterface_Verify_res_handles);
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
#define UpdateVerifierInterface_req controlsys_UpdateVerifierInterface_req
#define UpdateVerifierInterface_res controlsys_UpdateVerifierInterface_res
#define UpdateVerifierInterface_interface_dispatch controlsys_UpdateVerifierInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifierInterface__SERVER__ */

#ifndef __controlsys__UpdateVerifierInterface__TESTS__
#define __controlsys__UpdateVerifierInterface__TESTS__
static inline
nk_err_t controlsys_UpdateVerifierInterface_Verify_test_req(struct controlsys_UpdateVerifierInterface_Verify_req *msg,
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
                (nk_size_t) (should_fail[0].fail ? 18 : rand() %
                             18);
            if (len1 > 17)
                *failure = NK_TRUE;
            string2 = nk_arena_alloc(nk_uint8_t,
                                     arena,
                                     &msg->version,
                                     len1);
            if (string2 == NK_NULL)
                return NK_EINVAL;
            for (i0 = 0; i0 < len1; i0++)
                string2[i0] = (nk_uint8_t) rand();
        }
        msg->totalSize = (nk_uint32_t) rand();
        msg->signatureOk = (nk_uint8_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_UpdateVerifierInterface_Verify_test_res(struct controlsys_UpdateVerifierInterface_Verify_res *msg,
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
nk_err_t controlsys_UpdateVerifierInterface_Verify_test_err(struct controlsys_UpdateVerifierInterface_Verify_err *msg,
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

#endif /* __controlsys__UpdateVerifierInterface__TESTS__ */

#pragma GCC diagnostic pop

