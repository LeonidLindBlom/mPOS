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

#ifndef __controlsys_UpdateStorageInterface__Bool__TYPEDEF__
#define __controlsys_UpdateStorageInterface__Bool__TYPEDEF__
typedef nk_uint8_t
controlsys_UpdateStorageInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_Bool controlsys_UpdateStorageInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateStorageInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_UpdateStorageInterface__VersionLen__CONST__
#define __controlsys_UpdateStorageInterface__VersionLen__CONST__
#define controlsys_UpdateStorageInterface_VersionLen ((nk_uint8_t)(NK_UINT8_C(16)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_VersionLen controlsys_UpdateStorageInterface_VersionLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_UpdateStorageInterface__VersionLen__CONST__ */

#ifndef __controlsys__UpdateStorageInterface__INTERFACE__
#define __controlsys__UpdateStorageInterface__INTERFACE__
enum {
    controlsys_UpdateStorageInterface_Reset_mid,
    controlsys_UpdateStorageInterface_Append_mid,
    controlsys_UpdateStorageInterface_Snapshot_mid,
    controlsys_UpdateStorageInterface_mid_max,
};
enum {
    controlsys_UpdateStorageInterface_Reset_req_arena_size =
    0,
    controlsys_UpdateStorageInterface_Reset_res_arena_size =
    0,
    controlsys_UpdateStorageInterface_Reset_req_handles =
    0,
    controlsys_UpdateStorageInterface_Reset_res_handles =
    0,
    controlsys_UpdateStorageInterface_Reset_err_handles =
    0,
    controlsys_UpdateStorageInterface_Append_req_version_size =
    17,
    controlsys_UpdateStorageInterface_Append_req_arena_size =
    17,
    controlsys_UpdateStorageInterface_Append_res_arena_size =
    0,
    controlsys_UpdateStorageInterface_Append_req_handles =
    0,
    controlsys_UpdateStorageInterface_Append_res_handles =
    0,
    controlsys_UpdateStorageInterface_Append_err_handles =
    0,
    controlsys_UpdateStorageInterface_Snapshot_res_version_size =
    17,
    controlsys_UpdateStorageInterface_Snapshot_req_arena_size =
    0,
    controlsys_UpdateStorageInterface_Snapshot_res_arena_size =
    17,
    controlsys_UpdateStorageInterface_Snapshot_req_handles =
    0,
    controlsys_UpdateStorageInterface_Snapshot_res_handles =
    0,
    controlsys_UpdateStorageInterface_Snapshot_err_handles =
    0,
    controlsys_UpdateStorageInterface_req_arena_size =
    17,
    controlsys_UpdateStorageInterface_res_arena_size =
    17,
    controlsys_UpdateStorageInterface_arena_size =
    17,
    controlsys_UpdateStorageInterface_req_handles =
    0,
    controlsys_UpdateStorageInterface_res_handles =
    0,
    controlsys_UpdateStorageInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_UpdateStorageInterface_Reset_req {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateStorageInterface_Reset_req;
#pragma pack(push, 8) /* controlsys_UpdateStorageInterface_Reset_res */
typedef struct controlsys_UpdateStorageInterface_Reset_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateStorageInterface_Reset_err;
typedef struct controlsys_UpdateStorageInterface_Reset_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                } res_;
                struct controlsys_UpdateStorageInterface_Reset_err err_;
            };
        }
controlsys_UpdateStorageInterface_Reset_res;
#pragma pack(pop) /* controlsys_UpdateStorageInterface_Reset_res */
typedef struct __nk_packed controlsys_UpdateStorageInterface_Append_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4)
            nk_uint32_t chunkIndex;
            __nk_alignas(4)
            nk_uint32_t chunkTotal;
            __nk_alignas(4) nk_uint32_t chunkSize;
            __nk_alignas(4) nk_ptr_t version;
        }
controlsys_UpdateStorageInterface_Append_req;
#pragma pack(push, 8) /* controlsys_UpdateStorageInterface_Append_res */
typedef struct controlsys_UpdateStorageInterface_Append_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateStorageInterface_Append_err;
typedef struct controlsys_UpdateStorageInterface_Append_res {
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
                struct controlsys_UpdateStorageInterface_Append_err err_;
            };
        }
controlsys_UpdateStorageInterface_Append_res;
#pragma pack(pop) /* controlsys_UpdateStorageInterface_Append_res */
typedef struct __nk_packed controlsys_UpdateStorageInterface_Snapshot_req {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateStorageInterface_Snapshot_req;
#pragma pack(push, 8) /* controlsys_UpdateStorageInterface_Snapshot_res */
typedef struct controlsys_UpdateStorageInterface_Snapshot_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateStorageInterface_Snapshot_err;
typedef struct controlsys_UpdateStorageInterface_Snapshot_res {
            union {
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t version;
                    __nk_alignas(4)
                    nk_uint32_t totalSize;
                    __nk_alignas(1)
                    nk_uint8_t complete;
                };
                struct {
                    __nk_alignas(8)
                    struct nk_message base_;
                    __nk_alignas(4)
                    nk_ptr_t version;
                    __nk_alignas(4)
                    nk_uint32_t totalSize;
                    __nk_alignas(1)
                    nk_uint8_t complete;
                } res_;
                struct controlsys_UpdateStorageInterface_Snapshot_err err_;
            };
        }
controlsys_UpdateStorageInterface_Snapshot_res;
#pragma pack(pop) /* controlsys_UpdateStorageInterface_Snapshot_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_Reset_mid controlsys_UpdateStorageInterface_Reset_mid
#define UpdateStorageInterface_Append_mid controlsys_UpdateStorageInterface_Append_mid
#define UpdateStorageInterface_Snapshot_mid controlsys_UpdateStorageInterface_Snapshot_mid
#define UpdateStorageInterface_mid_max controlsys_UpdateStorageInterface_mid_max
#define UpdateStorageInterface_Reset_req_arena_size controlsys_UpdateStorageInterface_Reset_req_arena_size
#define UpdateStorageInterface_Reset_res_arena_size controlsys_UpdateStorageInterface_Reset_res_arena_size
#define UpdateStorageInterface_Reset_req_handles controlsys_UpdateStorageInterface_Reset_req_handles
#define UpdateStorageInterface_Reset_res_handles controlsys_UpdateStorageInterface_Reset_res_handles
#define UpdateStorageInterface_Reset_err_handles controlsys_UpdateStorageInterface_Reset_err_handles
#define UpdateStorageInterface_Append_req_version_size controlsys_UpdateStorageInterface_Append_req_version_size
#define UpdateStorageInterface_Append_req_arena_size controlsys_UpdateStorageInterface_Append_req_arena_size
#define UpdateStorageInterface_Append_res_arena_size controlsys_UpdateStorageInterface_Append_res_arena_size
#define UpdateStorageInterface_Append_req_handles controlsys_UpdateStorageInterface_Append_req_handles
#define UpdateStorageInterface_Append_res_handles controlsys_UpdateStorageInterface_Append_res_handles
#define UpdateStorageInterface_Append_err_handles controlsys_UpdateStorageInterface_Append_err_handles
#define UpdateStorageInterface_Snapshot_res_version_size controlsys_UpdateStorageInterface_Snapshot_res_version_size
#define UpdateStorageInterface_Snapshot_req_arena_size controlsys_UpdateStorageInterface_Snapshot_req_arena_size
#define UpdateStorageInterface_Snapshot_res_arena_size controlsys_UpdateStorageInterface_Snapshot_res_arena_size
#define UpdateStorageInterface_Snapshot_req_handles controlsys_UpdateStorageInterface_Snapshot_req_handles
#define UpdateStorageInterface_Snapshot_res_handles controlsys_UpdateStorageInterface_Snapshot_res_handles
#define UpdateStorageInterface_Snapshot_err_handles controlsys_UpdateStorageInterface_Snapshot_err_handles
#define UpdateStorageInterface_req_arena_size controlsys_UpdateStorageInterface_req_arena_size
#define UpdateStorageInterface_res_arena_size controlsys_UpdateStorageInterface_res_arena_size
#define UpdateStorageInterface_arena_size controlsys_UpdateStorageInterface_arena_size
#define UpdateStorageInterface_req_handles controlsys_UpdateStorageInterface_req_handles
#define UpdateStorageInterface_res_handles controlsys_UpdateStorageInterface_res_handles
#define UpdateStorageInterface_err_handles controlsys_UpdateStorageInterface_err_handles
#define UpdateStorageInterface_Reset_req controlsys_UpdateStorageInterface_Reset_req
#define UpdateStorageInterface_Reset_res controlsys_UpdateStorageInterface_Reset_res
#define UpdateStorageInterface_Append_req controlsys_UpdateStorageInterface_Append_req
#define UpdateStorageInterface_Append_res controlsys_UpdateStorageInterface_Append_res
#define UpdateStorageInterface_Snapshot_req controlsys_UpdateStorageInterface_Snapshot_req
#define UpdateStorageInterface_Snapshot_res controlsys_UpdateStorageInterface_Snapshot_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__INTERFACE__ */

#ifndef __controlsys__UpdateStorageInterface__VTABLE__
#define __controlsys__UpdateStorageInterface__VTABLE__
typedef struct controlsys_UpdateStorageInterface {
            const
            struct controlsys_UpdateStorageInterface_ops *ops;
        } controlsys_UpdateStorageInterface;
typedef nk_err_t
controlsys_UpdateStorageInterface_Reset_fn(struct controlsys_UpdateStorageInterface *,
                                           const
                                           struct controlsys_UpdateStorageInterface_Reset_req *,
                                           const
                                           struct nk_arena *,
                                           struct controlsys_UpdateStorageInterface_Reset_res *,
                                           struct nk_arena *);
typedef nk_err_t
controlsys_UpdateStorageInterface_Append_fn(struct controlsys_UpdateStorageInterface *,
                                            const
                                            struct controlsys_UpdateStorageInterface_Append_req *,
                                            const
                                            struct nk_arena *,
                                            struct controlsys_UpdateStorageInterface_Append_res *,
                                            struct nk_arena *);
typedef nk_err_t
controlsys_UpdateStorageInterface_Snapshot_fn(struct controlsys_UpdateStorageInterface *,
                                              const
                                              struct controlsys_UpdateStorageInterface_Snapshot_req *,
                                              const
                                              struct nk_arena *,
                                              struct controlsys_UpdateStorageInterface_Snapshot_res *,
                                              struct nk_arena *);
typedef struct controlsys_UpdateStorageInterface_ops {
            controlsys_UpdateStorageInterface_Reset_fn *Reset;
            controlsys_UpdateStorageInterface_Append_fn *Append;
            controlsys_UpdateStorageInterface_Snapshot_fn *Snapshot;
        } controlsys_UpdateStorageInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_Reset_fn controlsys_UpdateStorageInterface_Reset_fn
#define UpdateStorageInterface_Append_fn controlsys_UpdateStorageInterface_Append_fn
#define UpdateStorageInterface_Snapshot_fn controlsys_UpdateStorageInterface_Snapshot_fn
#define UpdateStorageInterface_ops controlsys_UpdateStorageInterface_ops
#define UpdateStorageInterface controlsys_UpdateStorageInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__VTABLE__ */

#ifndef __controlsys__UpdateStorageInterface__CLIENT__
#define __controlsys__UpdateStorageInterface__CLIENT__
typedef struct controlsys_UpdateStorageInterface_proxy {
            struct controlsys_UpdateStorageInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_UpdateStorageInterface_proxy;
static inline
nk_err_t controlsys_UpdateStorageInterface_Reset_proxy(struct controlsys_UpdateStorageInterface_proxy *self,
                                                       struct controlsys_UpdateStorageInterface_Reset_req *req,
                                                       const
                                                       struct nk_arena *req_arena,
                                                       struct controlsys_UpdateStorageInterface_Reset_res *res,
                                                       struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateStorageInterface_Reset_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateStorageInterface_Reset_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateStorageInterface_Reset_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateStorageInterface_Reset_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Append_proxy(struct controlsys_UpdateStorageInterface_proxy *self,
                                                        struct controlsys_UpdateStorageInterface_Append_req *req,
                                                        const
                                                        struct nk_arena *req_arena,
                                                        struct controlsys_UpdateStorageInterface_Append_res *res,
                                                        struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateStorageInterface_Append_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateStorageInterface_Append_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateStorageInterface_Append_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateStorageInterface_Append_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Snapshot_proxy(struct controlsys_UpdateStorageInterface_proxy *self,
                                                          struct controlsys_UpdateStorageInterface_Snapshot_req *req,
                                                          const
                                                          struct nk_arena *req_arena,
                                                          struct controlsys_UpdateStorageInterface_Snapshot_res *res,
                                                          struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_UpdateStorageInterface_Snapshot_mid);
    nk_msg_set_ncaps(req,
                     controlsys_UpdateStorageInterface_Snapshot_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_UpdateStorageInterface_Snapshot_mid);
    nk_msg_set_ncaps(res,
                     controlsys_UpdateStorageInterface_Snapshot_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_UpdateStorageInterface_proxy_init(struct controlsys_UpdateStorageInterface_proxy *self,
                                                  struct nk_transport *transport,
                                                  nk_iid_t iid)
{
    static const
    struct controlsys_UpdateStorageInterface_ops
    ops =
    {(controlsys_UpdateStorageInterface_Reset_fn *) &controlsys_UpdateStorageInterface_Reset_proxy,
     (controlsys_UpdateStorageInterface_Append_fn *) &controlsys_UpdateStorageInterface_Append_proxy,
     (controlsys_UpdateStorageInterface_Snapshot_fn *) &controlsys_UpdateStorageInterface_Snapshot_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Reset(struct controlsys_UpdateStorageInterface *self,
                                                 struct controlsys_UpdateStorageInterface_Reset_req *req,
                                                 const
                                                 struct nk_arena *req_arena,
                                                 struct controlsys_UpdateStorageInterface_Reset_res *res,
                                                 struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Reset != NK_NULL);
    return self->ops->Reset(self, req, req_arena,
                            res, res_arena);
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Append(struct controlsys_UpdateStorageInterface *self,
                                                  struct controlsys_UpdateStorageInterface_Append_req *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct controlsys_UpdateStorageInterface_Append_res *res,
                                                  struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Append != NK_NULL);
    return self->ops->Append(self, req, req_arena,
                             res, res_arena);
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Snapshot(struct controlsys_UpdateStorageInterface *self,
                                                    struct controlsys_UpdateStorageInterface_Snapshot_req *req,
                                                    const
                                                    struct nk_arena *req_arena,
                                                    struct controlsys_UpdateStorageInterface_Snapshot_res *res,
                                                    struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->Snapshot != NK_NULL);
    return self->ops->Snapshot(self, req,
                               req_arena, res,
                               res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_Reset_proxy controlsys_UpdateStorageInterface_Reset_proxy
#define UpdateStorageInterface_Append_proxy controlsys_UpdateStorageInterface_Append_proxy
#define UpdateStorageInterface_Snapshot_proxy controlsys_UpdateStorageInterface_Snapshot_proxy
#define UpdateStorageInterface_Reset controlsys_UpdateStorageInterface_Reset
#define UpdateStorageInterface_Append controlsys_UpdateStorageInterface_Append
#define UpdateStorageInterface_Snapshot controlsys_UpdateStorageInterface_Snapshot
#define UpdateStorageInterface_proxy controlsys_UpdateStorageInterface_proxy
#define UpdateStorageInterface_proxy_init controlsys_UpdateStorageInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__CLIENT__ */

#ifndef __controlsys__UpdateStorageInterface__SERVER__
#define __controlsys__UpdateStorageInterface__SERVER__
typedef union controlsys_UpdateStorageInterface_req {
            struct nk_message base_;
            struct controlsys_UpdateStorageInterface_Reset_req Reset;
            struct controlsys_UpdateStorageInterface_Append_req Append;
            struct controlsys_UpdateStorageInterface_Snapshot_req Snapshot;
        } controlsys_UpdateStorageInterface_req;
typedef union controlsys_UpdateStorageInterface_res {
            struct nk_message base_;
            struct controlsys_UpdateStorageInterface_Reset_res Reset;
            struct controlsys_UpdateStorageInterface_Append_res Append;
            struct controlsys_UpdateStorageInterface_Snapshot_res Snapshot;
        } controlsys_UpdateStorageInterface_res;
static inline
nk_err_t controlsys_UpdateStorageInterface_interface_dispatch(struct controlsys_UpdateStorageInterface *impl,
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
            
          case controlsys_UpdateStorageInterface_Reset_mid:
            {
                struct controlsys_UpdateStorageInterface_Reset_res
                *res_ =
                (struct controlsys_UpdateStorageInterface_Reset_res *) res;
                
                rc = impl->ops->Reset(impl, (const
                                             struct controlsys_UpdateStorageInterface_Reset_req *) req,
                                      req_arena,
                                      res_,
                                      res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateStorageInterface_Reset_res_handles);
                }
                break;
            }
            
          case controlsys_UpdateStorageInterface_Append_mid:
            {
                struct controlsys_UpdateStorageInterface_Append_res
                *res_ =
                (struct controlsys_UpdateStorageInterface_Append_res *) res;
                
                rc = impl->ops->Append(impl,
                                       (const
                                        struct controlsys_UpdateStorageInterface_Append_req *) req,
                                       req_arena,
                                       res_,
                                       res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateStorageInterface_Append_res_handles);
                }
                break;
            }
            
          case controlsys_UpdateStorageInterface_Snapshot_mid:
            {
                struct controlsys_UpdateStorageInterface_Snapshot_res
                *res_ =
                (struct controlsys_UpdateStorageInterface_Snapshot_res *) res;
                
                rc = impl->ops->Snapshot(impl,
                                         (const
                                          struct controlsys_UpdateStorageInterface_Snapshot_req *) req,
                                         req_arena,
                                         res_,
                                         res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateStorageInterface_Snapshot_res_handles);
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
#define UpdateStorageInterface_req controlsys_UpdateStorageInterface_req
#define UpdateStorageInterface_res controlsys_UpdateStorageInterface_res
#define UpdateStorageInterface_interface_dispatch controlsys_UpdateStorageInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__SERVER__ */

#ifndef __controlsys__UpdateStorageInterface__TESTS__
#define __controlsys__UpdateStorageInterface__TESTS__
static inline
nk_err_t controlsys_UpdateStorageInterface_Reset_test_req(struct controlsys_UpdateStorageInterface_Reset_req *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Reset_test_res(struct controlsys_UpdateStorageInterface_Reset_res *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Reset_test_err(struct controlsys_UpdateStorageInterface_Reset_err *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Append_test_req(struct controlsys_UpdateStorageInterface_Append_req *msg,
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
        msg->chunkIndex = (nk_uint32_t) rand();
        msg->chunkTotal = (nk_uint32_t) rand();
        msg->chunkSize = (nk_uint32_t) rand();
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
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Append_test_res(struct controlsys_UpdateStorageInterface_Append_res *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Append_test_err(struct controlsys_UpdateStorageInterface_Append_err *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Snapshot_test_req(struct controlsys_UpdateStorageInterface_Snapshot_req *msg,
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
nk_err_t controlsys_UpdateStorageInterface_Snapshot_test_res(struct controlsys_UpdateStorageInterface_Snapshot_res *msg,
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
        msg->complete = (nk_uint8_t) rand();
    }
    return NK_EOK;
}
static inline
nk_err_t controlsys_UpdateStorageInterface_Snapshot_test_err(struct controlsys_UpdateStorageInterface_Snapshot_err *msg,
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

#endif /* __controlsys__UpdateStorageInterface__TESTS__ */

#pragma GCC diagnostic pop

