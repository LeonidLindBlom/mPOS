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

#ifndef __controlsys_UpdateLoaderInterface__Bool__TYPEDEF__
#define __controlsys_UpdateLoaderInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_UpdateLoaderInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoaderInterface_Bool controlsys_UpdateLoaderInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateLoaderInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_UpdateLoaderInterface__VersionLen__CONST__
#define __controlsys_UpdateLoaderInterface__VersionLen__CONST__
#define controlsys_UpdateLoaderInterface_VersionLen ((nk_uint8_t)(NK_UINT8_C(16)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoaderInterface_VersionLen controlsys_UpdateLoaderInterface_VersionLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateLoaderInterface__VersionLen__CONST__ */

#ifndef __controlsys__UpdateLoaderInterface__INTERFACE__
#define __controlsys__UpdateLoaderInterface__INTERFACE__
enum {
    controlsys_UpdateLoaderInterface_Begin_mid,
    controlsys_UpdateLoaderInterface_PushChunk_mid,
    controlsys_UpdateLoaderInterface_Finalize_mid,
    controlsys_UpdateLoaderInterface_mid_max,
};
enum {
    controlsys_UpdateLoaderInterface_Begin_req_requester_size =
    17,
    controlsys_UpdateLoaderInterface_Begin_req_arena_size =
    17,
    controlsys_UpdateLoaderInterface_Begin_res_arena_size =
    0,
    controlsys_UpdateLoaderInterface_Begin_req_handles =
    0,
    controlsys_UpdateLoaderInterface_Begin_res_handles =
    0,
    controlsys_UpdateLoaderInterface_Begin_err_handles =
    0,
    controlsys_UpdateLoaderInterface_PushChunk_req_version_size =
    17,
    controlsys_UpdateLoaderInterface_PushChunk_req_arena_size =
    17,
    controlsys_UpdateLoaderInterface_PushChunk_res_arena_size =
    0,
    controlsys_UpdateLoaderInterface_PushChunk_req_handles =
    0,
    controlsys_UpdateLoaderInterface_PushChunk_res_handles =
    0,
    controlsys_UpdateLoaderInterface_PushChunk_err_handles =
    0,
    controlsys_UpdateLoaderInterface_Finalize_req_arena_size =
    0,
    controlsys_UpdateLoaderInterface_Finalize_res_arena_size =
    0,
    controlsys_UpdateLoaderInterface_Finalize_req_handles =
    0,
    controlsys_UpdateLoaderInterface_Finalize_res_handles =
    0,
    controlsys_UpdateLoaderInterface_Finalize_err_handles =
    0,
    controlsys_UpdateLoaderInterface_req_arena_size =
    17,
    controlsys_UpdateLoaderInterface_res_arena_size =
    0,
    controlsys_UpdateLoaderInterface_arena_size =
    17,
    controlsys_UpdateLoaderInterface_req_handles =
    0,
    controlsys_UpdateLoaderInterface_res_handles =
    0,
    controlsys_UpdateLoaderInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_UpdateLoaderInterface_Begin_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t requester;
        }
controlsys_UpdateLoaderInterface_Begin_req;
#pragma pack(push, 8) /* controlsys_UpdateLoaderInterface_Begin_res */
typedef struct controlsys_UpdateLoaderInterface_Begin_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateLoaderInterface_Begin_err;
typedef struct controlsys_UpdateLoaderInterface_Begin_res {
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
                struct controlsys_UpdateLoaderInterface_Begin_err err_;
            };
        }
controlsys_UpdateLoaderInterface_Begin_res;
#pragma pack(pop) /* controlsys_UpdateLoaderInterface_Begin_res */
typedef struct __nk_packed controlsys_UpdateLoaderInterface_PushChunk_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t version;
            __nk_alignas(4)
            nk_uint32_t chunkIndex;
            __nk_alignas(4)
            nk_uint32_t chunkTotal;
            __nk_alignas(4) nk_uint32_t chunkSize;
            __nk_alignas(1)
            nk_uint8_t signatureHint;
        }
controlsys_UpdateLoaderInterface_PushChunk_req;
#pragma pack(push, 8) /* controlsys_UpdateLoaderInterface_PushChunk_res */
typedef struct controlsys_UpdateLoaderInterface_PushChunk_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateLoaderInterface_PushChunk_err;
typedef struct controlsys_UpdateLoaderInterface_PushChunk_res {
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
                struct controlsys_UpdateLoaderInterface_PushChunk_err err_;
            };
        }
controlsys_UpdateLoaderInterface_PushChunk_res;
#pragma pack(pop) /* controlsys_UpdateLoaderInterface_PushChunk_res */
typedef struct __nk_packed controlsys_UpdateLoaderInterface_Finalize_req {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateLoaderInterface_Finalize_req;
#pragma pack(push, 8) /* controlsys_UpdateLoaderInterface_Finalize_res */
typedef struct controlsys_UpdateLoaderInterface_Finalize_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateLoaderInterface_Finalize_err;
typedef struct controlsys_UpdateLoaderInterface_Finalize_res {
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
                struct controlsys_UpdateLoaderInterface_Finalize_err err_;
            };
        }
controlsys_UpdateLoaderInterface_Finalize_res;
#pragma pack(pop) /* controlsys_UpdateLoaderInterface_Finalize_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoaderInterface_Begin_mid controlsys_UpdateLoaderInterface_Begin_mid
#define UpdateLoaderInterface_PushChunk_mid controlsys_UpdateLoaderInterface_PushChunk_mid
#define UpdateLoaderInterface_Finalize_mid controlsys_UpdateLoaderInterface_Finalize_mid
#define UpdateLoaderInterface_mid_max controlsys_UpdateLoaderInterface_mid_max
#define UpdateLoaderInterface_Begin_req_requester_size controlsys_UpdateLoaderInterface_Begin_req_requester_size
#define UpdateLoaderInterface_Begin_req_arena_size controlsys_UpdateLoaderInterface_Begin_req_arena_size
#define UpdateLoaderInterface_Begin_res_arena_size controlsys_UpdateLoaderInterface_Begin_res_arena_size
#define UpdateLoaderInterface_Begin_req_handles controlsys_UpdateLoaderInterface_Begin_req_handles
#define UpdateLoaderInterface_Begin_res_handles controlsys_UpdateLoaderInterface_Begin_res_handles
#define UpdateLoaderInterface_Begin_err_handles controlsys_UpdateLoaderInterface_Begin_err_handles
#define UpdateLoaderInterface_PushChunk_req_version_size controlsys_UpdateLoaderInterface_PushChunk_req_version_size
#define UpdateLoaderInterface_PushChunk_req_arena_size controlsys_UpdateLoaderInterface_PushChunk_req_arena_size
#define UpdateLoaderInterface_PushChunk_res_arena_size controlsys_UpdateLoaderInterface_PushChunk_res_arena_size
#define UpdateLoaderInterface_PushChunk_req_handles controlsys_UpdateLoaderInterface_PushChunk_req_handles
#define UpdateLoaderInterface_PushChunk_res_handles controlsys_UpdateLoaderInterface_PushChunk_res_handles
#define UpdateLoaderInterface_PushChunk_err_handles controlsys_UpdateLoaderInterface_PushChunk_err_handles
#define UpdateLoaderInterface_Finalize_req_arena_size controlsys_UpdateLoaderInterface_Finalize_req_arena_size
#define UpdateLoaderInterface_Finalize_res_arena_size controlsys_UpdateLoaderInterface_Finalize_res_arena_size
#define UpdateLoaderInterface_Finalize_req_handles controlsys_UpdateLoaderInterface_Finalize_req_handles
#define UpdateLoaderInterface_Finalize_res_handles controlsys_UpdateLoaderInterface_Finalize_res_handles
#define UpdateLoaderInterface_Finalize_err_handles controlsys_UpdateLoaderInterface_Finalize_err_handles
#define UpdateLoaderInterface_req_arena_size controlsys_UpdateLoaderInterface_req_arena_size
#define UpdateLoaderInterface_res_arena_size controlsys_UpdateLoaderInterface_res_arena_size
#define UpdateLoaderInterface_arena_size controlsys_UpdateLoaderInterface_arena_size
#define UpdateLoaderInterface_req_handles controlsys_UpdateLoaderInterface_req_handles
#define UpdateLoaderInterface_res_handles controlsys_UpdateLoaderInterface_res_handles
#define UpdateLoaderInterface_err_handles controlsys_UpdateLoaderInterface_err_handles
#define UpdateLoaderInterface_Begin_req controlsys_UpdateLoaderInterface_Begin_req
#define UpdateLoaderInterface_Begin_res controlsys_UpdateLoaderInterface_Begin_res
#define UpdateLoaderInterface_PushChunk_req controlsys_UpdateLoaderInterface_PushChunk_req
#define UpdateLoaderInterface_PushChunk_res controlsys_UpdateLoaderInterface_PushChunk_res
#define UpdateLoaderInterface_Finalize_req controlsys_UpdateLoaderInterface_Finalize_req
#define UpdateLoaderInterface_Finalize_res controlsys_UpdateLoaderInterface_Finalize_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoaderInterface__INTERFACE__ */

#ifndef __controlsys__UpdateLoaderInterface__VTABLE__
#define __controlsys__UpdateLoaderInterface__VTABLE__
typedef struct controlsys_UpdateLoaderInterface {
            const
            struct controlsys_UpdateLoaderInterface_ops *ops;
        } controlsys_UpdateLoaderInterface;
typedef nk_err_t
controlsys_UpdateLoaderInterface_Begin_fn(struct controlsys_UpdateLoaderInterface *,
                                          const
                                          struct controlsys_UpdateLoaderInterface_Begin_req *,
                                          const
                                          struct nk_arena *,
                                          struct controlsys_UpdateLoaderInterface_Begin_res *,
                                          struct nk_arena *);
typedef nk_err_t
controlsys_UpdateLoaderInterface_PushChunk_fn(struct controlsys_UpdateLoaderInterface *,
                                              const
                                              struct controlsys_UpdateLoaderInterface_PushChunk_req *,
                                              const
                                              struct nk_arena *,
                                              struct controlsys_UpdateLoaderInterface_PushChunk_res *,
                                              struct nk_arena *);
typedef nk_err_t
controlsys_UpdateLoaderInterface_Finalize_fn(struct controlsys_UpdateLoaderInterface *,
                                             const
                                             struct controlsys_UpdateLoaderInterface_Finalize_req *,
                                             const
                                             struct nk_arena *,
                                             struct controlsys_UpdateLoaderInterface_Finalize_res *,
                                             struct nk_arena *);
typedef struct controlsys_UpdateLoaderInterface_ops {
            controlsys_UpdateLoaderInterface_Begin_fn *Begin;
            controlsys_UpdateLoaderInterface_PushChunk_fn *PushChunk;
            controlsys_UpdateLoaderInterface_Finalize_fn *Finalize;
        } controlsys_UpdateLoaderInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoaderInterface_Begin_fn controlsys_UpdateLoaderInterface_Begin_fn
#define UpdateLoaderInterface_PushChunk_fn controlsys_UpdateLoaderInterface_PushChunk_fn
#define UpdateLoaderInterface_Finalize_fn controlsys_UpdateLoaderInterface_Finalize_fn
#define UpdateLoaderInterface_ops controlsys_UpdateLoaderInterface_ops
#define UpdateLoaderInterface controlsys_UpdateLoaderInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoaderInterface__VTABLE__ */

#ifndef __controlsys__UpdateLoaderInterface__CLIENT__
#define __controlsys__UpdateLoaderInterface__CLIENT__
typedef struct controlsys_UpdateLoaderInterface_proxy {
            struct controlsys_UpdateLoaderInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_UpdateLoaderInterface_proxy;
static inline
nk_err_t controlsys_UpdateLoaderInterface_Begin_proxy(struct controlsys_UpdateLoaderInterface_proxy *self,
                                                      struct controlsys_UpdateLoaderInterface_Begin_req *req,
                                                      const
                                                      struct nk_arena *req_arena,
                                                      struct controlsys_UpdateLoaderInterface_Begin_res *res,
                                                      struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateLoaderInterface_Begin_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateLoaderInterface_Begin_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateLoaderInterface_Begin_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateLoaderInterface_Begin_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_PushChunk_proxy(struct controlsys_UpdateLoaderInterface_proxy *self,
                                                          struct controlsys_UpdateLoaderInterface_PushChunk_req *req,
                                                          const
                                                          struct nk_arena *req_arena,
                                                          struct controlsys_UpdateLoaderInterface_PushChunk_res *res,
                                                          struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateLoaderInterface_PushChunk_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateLoaderInterface_PushChunk_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateLoaderInterface_PushChunk_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateLoaderInterface_PushChunk_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_Finalize_proxy(struct controlsys_UpdateLoaderInterface_proxy *self,
                                                         struct controlsys_UpdateLoaderInterface_Finalize_req *req,
                                                         const
                                                         struct nk_arena *req_arena,
                                                         struct controlsys_UpdateLoaderInterface_Finalize_res *res,
                                                         struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateLoaderInterface_Finalize_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateLoaderInterface_Finalize_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateLoaderInterface_Finalize_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateLoaderInterface_Finalize_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_UpdateLoaderInterface_proxy_init(struct controlsys_UpdateLoaderInterface_proxy *self,
                                                 struct nk_transport *transport,
                                                 nk_iid_t iid)
{
    static const
    struct controlsys_UpdateLoaderInterface_ops
    ops =
    {(controlsys_UpdateLoaderInterface_Begin_fn *) &controlsys_UpdateLoaderInterface_Begin_proxy,
     (controlsys_UpdateLoaderInterface_PushChunk_fn *) &controlsys_UpdateLoaderInterface_PushChunk_proxy,
     (controlsys_UpdateLoaderInterface_Finalize_fn *) &controlsys_UpdateLoaderInterface_Finalize_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_Begin(struct controlsys_UpdateLoaderInterface *self,
                                                struct controlsys_UpdateLoaderInterface_Begin_req *req,
                                                const
                                                struct nk_arena *req_arena,
                                                struct controlsys_UpdateLoaderInterface_Begin_res *res,
                                                struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Begin != NK_NULL);
    return self->ops->Begin(self, req, req_arena,
                            res, res_arena);
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_PushChunk(struct controlsys_UpdateLoaderInterface *self,
                                                    struct controlsys_UpdateLoaderInterface_PushChunk_req *req,
                                                    const
                                                    struct nk_arena *req_arena,
                                                    struct controlsys_UpdateLoaderInterface_PushChunk_res *res,
                                                    struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->PushChunk != NK_NULL);
    return self->ops->PushChunk(self, req,
                                req_arena, res,
                                res_arena);
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_Finalize(struct controlsys_UpdateLoaderInterface *self,
                                                   struct controlsys_UpdateLoaderInterface_Finalize_req *req,
                                                   const
                                                   struct nk_arena *req_arena,
                                                   struct controlsys_UpdateLoaderInterface_Finalize_res *res,
                                                   struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Finalize != NK_NULL);
    return self->ops->Finalize(self, req,
                               req_arena, res,
                               res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoaderInterface_Begin_proxy controlsys_UpdateLoaderInterface_Begin_proxy
#define UpdateLoaderInterface_PushChunk_proxy controlsys_UpdateLoaderInterface_PushChunk_proxy
#define UpdateLoaderInterface_Finalize_proxy controlsys_UpdateLoaderInterface_Finalize_proxy
#define UpdateLoaderInterface_Begin controlsys_UpdateLoaderInterface_Begin
#define UpdateLoaderInterface_PushChunk controlsys_UpdateLoaderInterface_PushChunk
#define UpdateLoaderInterface_Finalize controlsys_UpdateLoaderInterface_Finalize
#define UpdateLoaderInterface_proxy controlsys_UpdateLoaderInterface_proxy
#define UpdateLoaderInterface_proxy_init controlsys_UpdateLoaderInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoaderInterface__CLIENT__ */

#ifndef __controlsys__UpdateLoaderInterface__SERVER__
#define __controlsys__UpdateLoaderInterface__SERVER__
typedef union controlsys_UpdateLoaderInterface_req {
            struct nk_message base_;
            struct controlsys_UpdateLoaderInterface_Begin_req Begin;
            struct controlsys_UpdateLoaderInterface_PushChunk_req PushChunk;
            struct controlsys_UpdateLoaderInterface_Finalize_req Finalize;
        } controlsys_UpdateLoaderInterface_req;
typedef union controlsys_UpdateLoaderInterface_res {
            struct nk_message base_;
            struct controlsys_UpdateLoaderInterface_Begin_res Begin;
            struct controlsys_UpdateLoaderInterface_PushChunk_res PushChunk;
            struct controlsys_UpdateLoaderInterface_Finalize_res Finalize;
        } controlsys_UpdateLoaderInterface_res;
static inline
nk_err_t controlsys_UpdateLoaderInterface_interface_dispatch(struct controlsys_UpdateLoaderInterface *impl,
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
            
          case controlsys_UpdateLoaderInterface_Begin_mid:
            {
                struct controlsys_UpdateLoaderInterface_Begin_res
                *res_ =
                (struct controlsys_UpdateLoaderInterface_Begin_res *) res;
                
                rc = impl->ops->Begin(impl, (const
                                             struct controlsys_UpdateLoaderInterface_Begin_req *) req,
                                      req_arena,
                                      res_,
                                      res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateLoaderInterface_Begin_res_handles);
                }
                break;
            }
            
          case controlsys_UpdateLoaderInterface_PushChunk_mid:
            {
                struct controlsys_UpdateLoaderInterface_PushChunk_res
                *res_ =
                (struct controlsys_UpdateLoaderInterface_PushChunk_res *) res;
                
                rc = impl->ops->PushChunk(impl,
                                          (const
                                           struct controlsys_UpdateLoaderInterface_PushChunk_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateLoaderInterface_PushChunk_res_handles);
                }
                break;
            }
            
          case controlsys_UpdateLoaderInterface_Finalize_mid:
            {
                struct controlsys_UpdateLoaderInterface_Finalize_res
                *res_ =
                (struct controlsys_UpdateLoaderInterface_Finalize_res *) res;
                
                rc = impl->ops->Finalize(impl,
                                         (const
                                          struct controlsys_UpdateLoaderInterface_Finalize_req *) req,
                                         req_arena,
                                         res_,
                                         res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateLoaderInterface_Finalize_res_handles);
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
#define UpdateLoaderInterface_req controlsys_UpdateLoaderInterface_req
#define UpdateLoaderInterface_res controlsys_UpdateLoaderInterface_res
#define UpdateLoaderInterface_interface_dispatch controlsys_UpdateLoaderInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoaderInterface__SERVER__ */

#ifndef __controlsys__UpdateLoaderInterface__TESTS__
#define __controlsys__UpdateLoaderInterface__TESTS__
static inline
nk_err_t controlsys_UpdateLoaderInterface_Begin_test_req(struct controlsys_UpdateLoaderInterface_Begin_req *msg,
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
                                     &msg->requester,
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
nk_err_t controlsys_UpdateLoaderInterface_Begin_test_res(struct controlsys_UpdateLoaderInterface_Begin_res *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_Begin_test_err(struct controlsys_UpdateLoaderInterface_Begin_err *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_PushChunk_test_req(struct controlsys_UpdateLoaderInterface_PushChunk_req *msg,
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
        msg->chunkIndex = (nk_uint32_t) rand();
        msg->chunkTotal = (nk_uint32_t) rand();
        msg->chunkSize = (nk_uint32_t) rand();
        msg->signatureHint = (nk_uint8_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_UpdateLoaderInterface_PushChunk_test_res(struct controlsys_UpdateLoaderInterface_PushChunk_res *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_PushChunk_test_err(struct controlsys_UpdateLoaderInterface_PushChunk_err *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_Finalize_test_req(struct controlsys_UpdateLoaderInterface_Finalize_req *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_Finalize_test_res(struct controlsys_UpdateLoaderInterface_Finalize_res *msg,
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
nk_err_t controlsys_UpdateLoaderInterface_Finalize_test_err(struct controlsys_UpdateLoaderInterface_Finalize_err *msg,
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

#endif /* __controlsys__UpdateLoaderInterface__TESTS__ */

#pragma GCC diagnostic pop

