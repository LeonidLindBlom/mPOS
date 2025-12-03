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

#ifndef __controlsys__UpdateLoader__COMPONENT_ENDPOINTS__
#define __controlsys__UpdateLoader__COMPONENT_ENDPOINTS__
enum {
    controlsys_UpdateLoader_interface_iid,
    controlsys_UpdateLoader_iidMax,
};
enum {
    controlsys_UpdateLoader_iidOffset = 0,
};
enum {
    controlsys_UpdateLoader_securityIidMax,
};
enum {
    controlsys_UpdateLoader_component_req_arena_size =
    17,
    controlsys_UpdateLoader_component_res_arena_size =
    0,
    controlsys_UpdateLoader_component_arena_size =
    17,
    controlsys_UpdateLoader_component_req_handles =
    0,
    controlsys_UpdateLoader_component_res_handles =
    0,
    controlsys_UpdateLoader_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoader_interface_iid controlsys_UpdateLoader_interface_iid
#define UpdateLoader_iidMax controlsys_UpdateLoader_iidMax
#define UpdateLoader_iidOffset controlsys_UpdateLoader_iidOffset
#define UpdateLoader_securityIidMax controlsys_UpdateLoader_securityIidMax
#define UpdateLoader_component_req_arena_size controlsys_UpdateLoader_component_req_arena_size
#define UpdateLoader_component_res_arena_size controlsys_UpdateLoader_component_res_arena_size
#define UpdateLoader_component_arena_size controlsys_UpdateLoader_component_arena_size
#define UpdateLoader_component_req_handles controlsys_UpdateLoader_component_req_handles
#define UpdateLoader_component_res_handles controlsys_UpdateLoader_component_res_handles
#define UpdateLoader_component_err_handles controlsys_UpdateLoader_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoader__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__UpdateLoader__TASK_ENDPOINTS__
#define __controlsys__UpdateLoader__TASK_ENDPOINTS__
enum {
    controlsys_UpdateLoader_entity_req_arena_size =
    controlsys_UpdateLoader_component_req_arena_size,
    controlsys_UpdateLoader_entity_res_arena_size =
    controlsys_UpdateLoader_component_res_arena_size,
    controlsys_UpdateLoader_entity_arena_size =
    controlsys_UpdateLoader_component_arena_size,
    controlsys_UpdateLoader_entity_req_handles =
    controlsys_UpdateLoader_component_req_handles,
    controlsys_UpdateLoader_entity_res_handles =
    controlsys_UpdateLoader_component_res_handles,
    controlsys_UpdateLoader_entity_err_handles =
    controlsys_UpdateLoader_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoader_entity_req_arena_size controlsys_UpdateLoader_entity_req_arena_size
#define UpdateLoader_entity_res_arena_size controlsys_UpdateLoader_entity_res_arena_size
#define UpdateLoader_entity_arena_size controlsys_UpdateLoader_entity_arena_size
#define UpdateLoader_entity_req_handles controlsys_UpdateLoader_entity_req_handles
#define UpdateLoader_entity_res_handles controlsys_UpdateLoader_entity_res_handles
#define UpdateLoader_entity_err_handles controlsys_UpdateLoader_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoader__TASK_ENDPOINTS__ */

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

#ifndef __controlsys__UpdateLoader__COMPONENT_SERVER_TYPES__
#define __controlsys__UpdateLoader__COMPONENT_SERVER_TYPES__
typedef struct controlsys_UpdateLoader_component {
            struct controlsys_UpdateLoaderInterface *interface;
        } controlsys_UpdateLoader_component;

#endif /* __controlsys__UpdateLoader__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__UpdateLoader__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__UpdateLoader__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_UpdateLoader_component_init(struct controlsys_UpdateLoader_component *self,
                                            struct controlsys_UpdateLoaderInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_UpdateLoader_component_req {
            struct nk_message base_;
            controlsys_UpdateLoaderInterface_req interface;
        } controlsys_UpdateLoader_component_req;
typedef union controlsys_UpdateLoader_component_res {
            struct nk_message base_;
            controlsys_UpdateLoaderInterface_res interface;
        } controlsys_UpdateLoader_component_res;
static inline
nk_err_t controlsys_UpdateLoader_component_dispatch(struct controlsys_UpdateLoader_component *self,
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
        
      case controlsys_UpdateLoader_interface_iid:
        return controlsys_UpdateLoaderInterface_interface_dispatch(self->interface,
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
#define UpdateLoader_component controlsys_UpdateLoader_component
#define UpdateLoader_component_init controlsys_UpdateLoader_component_init
#define UpdateLoader_component_req controlsys_UpdateLoader_component_req
#define UpdateLoader_component_res controlsys_UpdateLoader_component_res
#define UpdateLoader_component_dispatch controlsys_UpdateLoader_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoader__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__UpdateLoader__ENTITY_SERVER__
#define __controlsys__UpdateLoader__ENTITY_SERVER__
#define controlsys_UpdateLoader_entity_res controlsys_UpdateLoader_component_res
#define controlsys_UpdateLoader_entity_req controlsys_UpdateLoader_component_req
#define controlsys_UpdateLoader_entity controlsys_UpdateLoader_component
static inline
void controlsys_UpdateLoader_entity_init(struct controlsys_UpdateLoader_entity *self,
                                         struct controlsys_UpdateLoaderInterface *interface)
{
    controlsys_UpdateLoader_component_init(self,
                                           interface);
}
static inline
nk_err_t controlsys_UpdateLoader_entity_dispatch(struct controlsys_UpdateLoader_entity *self,
                                                 const
                                                 struct nk_message *req,
                                                 const
                                                 struct nk_arena *req_arena,
                                                 struct nk_message *res,
                                                 struct nk_arena *res_arena)
{
    return controlsys_UpdateLoader_component_dispatch(self,
                                                      0,
                                                      req,
                                                      req_arena,
                                                      res,
                                                      res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateLoader_entity controlsys_UpdateLoader_entity
#define UpdateLoader_entity_init controlsys_UpdateLoader_entity_init
#define UpdateLoader_entity_req controlsys_UpdateLoader_entity_req
#define UpdateLoader_entity_res controlsys_UpdateLoader_entity_res
#define UpdateLoader_entity_dispatch controlsys_UpdateLoader_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateLoader__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

