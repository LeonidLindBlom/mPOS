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

#ifndef __controlsys__UpdateStorageInterface__INTERFACE__
#define __controlsys__UpdateStorageInterface__INTERFACE__
enum {
    controlsys_UpdateStorageInterface_Snapshot_mid,
    controlsys_UpdateStorageInterface_mid_max,
};
enum {
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
    0,
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
#define UpdateStorageInterface_Snapshot_mid controlsys_UpdateStorageInterface_Snapshot_mid
#define UpdateStorageInterface_mid_max controlsys_UpdateStorageInterface_mid_max
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
#define UpdateStorageInterface_Snapshot_req controlsys_UpdateStorageInterface_Snapshot_req
#define UpdateStorageInterface_Snapshot_res controlsys_UpdateStorageInterface_Snapshot_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__INTERFACE__ */

#ifndef __controlsys__UpdateStorage__COMPONENT_ENDPOINTS__
#define __controlsys__UpdateStorage__COMPONENT_ENDPOINTS__
enum {
    controlsys_UpdateStorage_interface_iid,
    controlsys_UpdateStorage_iidMax,
};
enum {
    controlsys_UpdateStorage_iidOffset = 0,
};
enum {
    controlsys_UpdateStorage_securityIidMax,
};
enum {
    controlsys_UpdateStorage_component_req_arena_size =
    0,
    controlsys_UpdateStorage_component_res_arena_size =
    17,
    controlsys_UpdateStorage_component_arena_size =
    17,
    controlsys_UpdateStorage_component_req_handles =
    0,
    controlsys_UpdateStorage_component_res_handles =
    0,
    controlsys_UpdateStorage_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorage_interface_iid controlsys_UpdateStorage_interface_iid
#define UpdateStorage_iidMax controlsys_UpdateStorage_iidMax
#define UpdateStorage_iidOffset controlsys_UpdateStorage_iidOffset
#define UpdateStorage_securityIidMax controlsys_UpdateStorage_securityIidMax
#define UpdateStorage_component_req_arena_size controlsys_UpdateStorage_component_req_arena_size
#define UpdateStorage_component_res_arena_size controlsys_UpdateStorage_component_res_arena_size
#define UpdateStorage_component_arena_size controlsys_UpdateStorage_component_arena_size
#define UpdateStorage_component_req_handles controlsys_UpdateStorage_component_req_handles
#define UpdateStorage_component_res_handles controlsys_UpdateStorage_component_res_handles
#define UpdateStorage_component_err_handles controlsys_UpdateStorage_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorage__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__UpdateStorage__TASK_ENDPOINTS__
#define __controlsys__UpdateStorage__TASK_ENDPOINTS__
enum {
    controlsys_UpdateStorage_entity_req_arena_size =
    controlsys_UpdateStorage_component_req_arena_size,
    controlsys_UpdateStorage_entity_res_arena_size =
    controlsys_UpdateStorage_component_res_arena_size,
    controlsys_UpdateStorage_entity_arena_size =
    controlsys_UpdateStorage_component_arena_size,
    controlsys_UpdateStorage_entity_req_handles =
    controlsys_UpdateStorage_component_req_handles,
    controlsys_UpdateStorage_entity_res_handles =
    controlsys_UpdateStorage_component_res_handles,
    controlsys_UpdateStorage_entity_err_handles =
    controlsys_UpdateStorage_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorage_entity_req_arena_size controlsys_UpdateStorage_entity_req_arena_size
#define UpdateStorage_entity_res_arena_size controlsys_UpdateStorage_entity_res_arena_size
#define UpdateStorage_entity_arena_size controlsys_UpdateStorage_entity_arena_size
#define UpdateStorage_entity_req_handles controlsys_UpdateStorage_entity_req_handles
#define UpdateStorage_entity_res_handles controlsys_UpdateStorage_entity_res_handles
#define UpdateStorage_entity_err_handles controlsys_UpdateStorage_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorage__TASK_ENDPOINTS__ */

#ifndef __controlsys__UpdateStorageInterface__VTABLE__
#define __controlsys__UpdateStorageInterface__VTABLE__
typedef struct controlsys_UpdateStorageInterface {
            const
            struct controlsys_UpdateStorageInterface_ops *ops;
        } controlsys_UpdateStorageInterface;
typedef nk_err_t
controlsys_UpdateStorageInterface_Snapshot_fn(struct controlsys_UpdateStorageInterface *,
                                              const
                                              struct controlsys_UpdateStorageInterface_Snapshot_req *,
                                              const
                                              struct nk_arena *,
                                              struct controlsys_UpdateStorageInterface_Snapshot_res *,
                                              struct nk_arena *);
typedef struct controlsys_UpdateStorageInterface_ops {
            controlsys_UpdateStorageInterface_Snapshot_fn *Snapshot;
        } controlsys_UpdateStorageInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorageInterface_Snapshot_fn controlsys_UpdateStorageInterface_Snapshot_fn
#define UpdateStorageInterface_ops controlsys_UpdateStorageInterface_ops
#define UpdateStorageInterface controlsys_UpdateStorageInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorageInterface__VTABLE__ */

#ifndef __controlsys__UpdateStorageInterface__SERVER__
#define __controlsys__UpdateStorageInterface__SERVER__
typedef union controlsys_UpdateStorageInterface_req {
            struct nk_message base_;
            struct controlsys_UpdateStorageInterface_Snapshot_req Snapshot;
        } controlsys_UpdateStorageInterface_req;
typedef union controlsys_UpdateStorageInterface_res {
            struct nk_message base_;
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

#ifndef __controlsys__UpdateStorage__COMPONENT_SERVER_TYPES__
#define __controlsys__UpdateStorage__COMPONENT_SERVER_TYPES__
typedef struct controlsys_UpdateStorage_component {
            struct controlsys_UpdateStorageInterface *interface;
        } controlsys_UpdateStorage_component;

#endif /* __controlsys__UpdateStorage__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__UpdateStorage__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__UpdateStorage__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_UpdateStorage_component_init(struct controlsys_UpdateStorage_component *self,
                                             struct controlsys_UpdateStorageInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_UpdateStorage_component_req {
            struct nk_message base_;
            controlsys_UpdateStorageInterface_req interface;
        } controlsys_UpdateStorage_component_req;
typedef union controlsys_UpdateStorage_component_res {
            struct nk_message base_;
            controlsys_UpdateStorageInterface_res interface;
        } controlsys_UpdateStorage_component_res;
static inline
nk_err_t controlsys_UpdateStorage_component_dispatch(struct controlsys_UpdateStorage_component *self,
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
        
      case controlsys_UpdateStorage_interface_iid:
        return controlsys_UpdateStorageInterface_interface_dispatch(self->interface,
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
#define UpdateStorage_component controlsys_UpdateStorage_component
#define UpdateStorage_component_init controlsys_UpdateStorage_component_init
#define UpdateStorage_component_req controlsys_UpdateStorage_component_req
#define UpdateStorage_component_res controlsys_UpdateStorage_component_res
#define UpdateStorage_component_dispatch controlsys_UpdateStorage_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorage__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__UpdateStorage__ENTITY_SERVER__
#define __controlsys__UpdateStorage__ENTITY_SERVER__
#define controlsys_UpdateStorage_entity_res controlsys_UpdateStorage_component_res
#define controlsys_UpdateStorage_entity_req controlsys_UpdateStorage_component_req
#define controlsys_UpdateStorage_entity controlsys_UpdateStorage_component
static inline
void controlsys_UpdateStorage_entity_init(struct controlsys_UpdateStorage_entity *self,
                                          struct controlsys_UpdateStorageInterface *interface)
{
    controlsys_UpdateStorage_component_init(self,
                                            interface);
}
static inline
nk_err_t controlsys_UpdateStorage_entity_dispatch(struct controlsys_UpdateStorage_entity *self,
                                                  const
                                                  struct nk_message *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct nk_message *res,
                                                  struct nk_arena *res_arena)
{
    return controlsys_UpdateStorage_component_dispatch(self,
                                                       0,
                                                       req,
                                                       req_arena,
                                                       res,
                                                       res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateStorage_entity controlsys_UpdateStorage_entity
#define UpdateStorage_entity_init controlsys_UpdateStorage_entity_init
#define UpdateStorage_entity_req controlsys_UpdateStorage_entity_req
#define UpdateStorage_entity_res controlsys_UpdateStorage_entity_res
#define UpdateStorage_entity_dispatch controlsys_UpdateStorage_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateStorage__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

