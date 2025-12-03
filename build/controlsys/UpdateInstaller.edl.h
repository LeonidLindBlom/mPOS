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

#ifndef __controlsys__UpdateInstallerInterface__INTERFACE__
#define __controlsys__UpdateInstallerInterface__INTERFACE__
enum {
    controlsys_UpdateInstallerInterface_Install_mid,
    controlsys_UpdateInstallerInterface_mid_max,
};
enum {
    controlsys_UpdateInstallerInterface_Install_req_version_size =
    17,
    controlsys_UpdateInstallerInterface_Install_req_arena_size =
    17,
    controlsys_UpdateInstallerInterface_Install_res_arena_size =
    0,
    controlsys_UpdateInstallerInterface_Install_req_handles =
    0,
    controlsys_UpdateInstallerInterface_Install_res_handles =
    0,
    controlsys_UpdateInstallerInterface_Install_err_handles =
    0,
    controlsys_UpdateInstallerInterface_req_arena_size =
    17,
    controlsys_UpdateInstallerInterface_res_arena_size =
    0,
    controlsys_UpdateInstallerInterface_arena_size =
    17,
    controlsys_UpdateInstallerInterface_req_handles =
    0,
    controlsys_UpdateInstallerInterface_res_handles =
    0,
    controlsys_UpdateInstallerInterface_err_handles =
    0,
};
typedef struct __nk_packed controlsys_UpdateInstallerInterface_Install_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t version;
            __nk_alignas(4) nk_uint32_t totalSize;
            __nk_alignas(1) nk_uint8_t allow;
        }
controlsys_UpdateInstallerInterface_Install_req;
#pragma pack(push, 8) /* controlsys_UpdateInstallerInterface_Install_res */
typedef struct controlsys_UpdateInstallerInterface_Install_err {
            __nk_alignas(8)
            struct nk_message base_;
        }
controlsys_UpdateInstallerInterface_Install_err;
typedef struct controlsys_UpdateInstallerInterface_Install_res {
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
                struct controlsys_UpdateInstallerInterface_Install_err err_;
            };
        }
controlsys_UpdateInstallerInterface_Install_res;
#pragma pack(pop) /* controlsys_UpdateInstallerInterface_Install_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateInstallerInterface_Install_mid controlsys_UpdateInstallerInterface_Install_mid
#define UpdateInstallerInterface_mid_max controlsys_UpdateInstallerInterface_mid_max
#define UpdateInstallerInterface_Install_req_version_size controlsys_UpdateInstallerInterface_Install_req_version_size
#define UpdateInstallerInterface_Install_req_arena_size controlsys_UpdateInstallerInterface_Install_req_arena_size
#define UpdateInstallerInterface_Install_res_arena_size controlsys_UpdateInstallerInterface_Install_res_arena_size
#define UpdateInstallerInterface_Install_req_handles controlsys_UpdateInstallerInterface_Install_req_handles
#define UpdateInstallerInterface_Install_res_handles controlsys_UpdateInstallerInterface_Install_res_handles
#define UpdateInstallerInterface_Install_err_handles controlsys_UpdateInstallerInterface_Install_err_handles
#define UpdateInstallerInterface_req_arena_size controlsys_UpdateInstallerInterface_req_arena_size
#define UpdateInstallerInterface_res_arena_size controlsys_UpdateInstallerInterface_res_arena_size
#define UpdateInstallerInterface_arena_size controlsys_UpdateInstallerInterface_arena_size
#define UpdateInstallerInterface_req_handles controlsys_UpdateInstallerInterface_req_handles
#define UpdateInstallerInterface_res_handles controlsys_UpdateInstallerInterface_res_handles
#define UpdateInstallerInterface_err_handles controlsys_UpdateInstallerInterface_err_handles
#define UpdateInstallerInterface_Install_req controlsys_UpdateInstallerInterface_Install_req
#define UpdateInstallerInterface_Install_res controlsys_UpdateInstallerInterface_Install_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstallerInterface__INTERFACE__ */

#ifndef __controlsys__UpdateInstaller__COMPONENT_ENDPOINTS__
#define __controlsys__UpdateInstaller__COMPONENT_ENDPOINTS__
enum {
    controlsys_UpdateInstaller_interface_iid,
    controlsys_UpdateInstaller_iidMax,
};
enum {
    controlsys_UpdateInstaller_iidOffset = 0,
};
enum {
    controlsys_UpdateInstaller_securityIidMax,
};
enum {
    controlsys_UpdateInstaller_component_req_arena_size =
    17,
    controlsys_UpdateInstaller_component_res_arena_size =
    0,
    controlsys_UpdateInstaller_component_arena_size =
    17,
    controlsys_UpdateInstaller_component_req_handles =
    0,
    controlsys_UpdateInstaller_component_res_handles =
    0,
    controlsys_UpdateInstaller_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateInstaller_interface_iid controlsys_UpdateInstaller_interface_iid
#define UpdateInstaller_iidMax controlsys_UpdateInstaller_iidMax
#define UpdateInstaller_iidOffset controlsys_UpdateInstaller_iidOffset
#define UpdateInstaller_securityIidMax controlsys_UpdateInstaller_securityIidMax
#define UpdateInstaller_component_req_arena_size controlsys_UpdateInstaller_component_req_arena_size
#define UpdateInstaller_component_res_arena_size controlsys_UpdateInstaller_component_res_arena_size
#define UpdateInstaller_component_arena_size controlsys_UpdateInstaller_component_arena_size
#define UpdateInstaller_component_req_handles controlsys_UpdateInstaller_component_req_handles
#define UpdateInstaller_component_res_handles controlsys_UpdateInstaller_component_res_handles
#define UpdateInstaller_component_err_handles controlsys_UpdateInstaller_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstaller__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__UpdateInstaller__TASK_ENDPOINTS__
#define __controlsys__UpdateInstaller__TASK_ENDPOINTS__
enum {
    controlsys_UpdateInstaller_entity_req_arena_size =
    controlsys_UpdateInstaller_component_req_arena_size,
    controlsys_UpdateInstaller_entity_res_arena_size =
    controlsys_UpdateInstaller_component_res_arena_size,
    controlsys_UpdateInstaller_entity_arena_size =
    controlsys_UpdateInstaller_component_arena_size,
    controlsys_UpdateInstaller_entity_req_handles =
    controlsys_UpdateInstaller_component_req_handles,
    controlsys_UpdateInstaller_entity_res_handles =
    controlsys_UpdateInstaller_component_res_handles,
    controlsys_UpdateInstaller_entity_err_handles =
    controlsys_UpdateInstaller_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateInstaller_entity_req_arena_size controlsys_UpdateInstaller_entity_req_arena_size
#define UpdateInstaller_entity_res_arena_size controlsys_UpdateInstaller_entity_res_arena_size
#define UpdateInstaller_entity_arena_size controlsys_UpdateInstaller_entity_arena_size
#define UpdateInstaller_entity_req_handles controlsys_UpdateInstaller_entity_req_handles
#define UpdateInstaller_entity_res_handles controlsys_UpdateInstaller_entity_res_handles
#define UpdateInstaller_entity_err_handles controlsys_UpdateInstaller_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstaller__TASK_ENDPOINTS__ */

#ifndef __controlsys__UpdateInstallerInterface__VTABLE__
#define __controlsys__UpdateInstallerInterface__VTABLE__
typedef struct controlsys_UpdateInstallerInterface {
            const
            struct controlsys_UpdateInstallerInterface_ops *ops;
        } controlsys_UpdateInstallerInterface;
typedef nk_err_t
controlsys_UpdateInstallerInterface_Install_fn(struct controlsys_UpdateInstallerInterface *,
                                               const
                                               struct controlsys_UpdateInstallerInterface_Install_req *,
                                               const
                                               struct nk_arena *,
                                               struct controlsys_UpdateInstallerInterface_Install_res *,
                                               struct nk_arena *);
typedef struct controlsys_UpdateInstallerInterface_ops {
            controlsys_UpdateInstallerInterface_Install_fn *Install;
        } controlsys_UpdateInstallerInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateInstallerInterface_Install_fn controlsys_UpdateInstallerInterface_Install_fn
#define UpdateInstallerInterface_ops controlsys_UpdateInstallerInterface_ops
#define UpdateInstallerInterface controlsys_UpdateInstallerInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstallerInterface__VTABLE__ */

#ifndef __controlsys__UpdateInstallerInterface__SERVER__
#define __controlsys__UpdateInstallerInterface__SERVER__
typedef union controlsys_UpdateInstallerInterface_req {
            struct nk_message base_;
            struct controlsys_UpdateInstallerInterface_Install_req Install;
        } controlsys_UpdateInstallerInterface_req;
typedef union controlsys_UpdateInstallerInterface_res {
            struct nk_message base_;
            struct controlsys_UpdateInstallerInterface_Install_res Install;
        } controlsys_UpdateInstallerInterface_res;
static inline
nk_err_t controlsys_UpdateInstallerInterface_interface_dispatch(struct controlsys_UpdateInstallerInterface *impl,
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
            
          case controlsys_UpdateInstallerInterface_Install_mid:
            {
                struct controlsys_UpdateInstallerInterface_Install_res
                *res_ =
                (struct controlsys_UpdateInstallerInterface_Install_res *) res;
                
                rc = impl->ops->Install(impl,
                                        (const
                                         struct controlsys_UpdateInstallerInterface_Install_req *) req,
                                        req_arena,
                                        res_,
                                        res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_UpdateInstallerInterface_Install_res_handles);
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
#define UpdateInstallerInterface_req controlsys_UpdateInstallerInterface_req
#define UpdateInstallerInterface_res controlsys_UpdateInstallerInterface_res
#define UpdateInstallerInterface_interface_dispatch controlsys_UpdateInstallerInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstallerInterface__SERVER__ */

#ifndef __controlsys__UpdateInstaller__COMPONENT_SERVER_TYPES__
#define __controlsys__UpdateInstaller__COMPONENT_SERVER_TYPES__
typedef struct controlsys_UpdateInstaller_component {
            struct controlsys_UpdateInstallerInterface *interface;
        } controlsys_UpdateInstaller_component;

#endif /* __controlsys__UpdateInstaller__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__UpdateInstaller__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__UpdateInstaller__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_UpdateInstaller_component_init(struct controlsys_UpdateInstaller_component *self,
                                               struct controlsys_UpdateInstallerInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_UpdateInstaller_component_req {
            struct nk_message base_;
            controlsys_UpdateInstallerInterface_req interface;
        }
controlsys_UpdateInstaller_component_req;
typedef union controlsys_UpdateInstaller_component_res {
            struct nk_message base_;
            controlsys_UpdateInstallerInterface_res interface;
        }
controlsys_UpdateInstaller_component_res;
static inline
nk_err_t controlsys_UpdateInstaller_component_dispatch(struct controlsys_UpdateInstaller_component *self,
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
        
      case controlsys_UpdateInstaller_interface_iid:
        return controlsys_UpdateInstallerInterface_interface_dispatch(self->interface,
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
#define UpdateInstaller_component controlsys_UpdateInstaller_component
#define UpdateInstaller_component_init controlsys_UpdateInstaller_component_init
#define UpdateInstaller_component_req controlsys_UpdateInstaller_component_req
#define UpdateInstaller_component_res controlsys_UpdateInstaller_component_res
#define UpdateInstaller_component_dispatch controlsys_UpdateInstaller_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstaller__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__UpdateInstaller__ENTITY_SERVER__
#define __controlsys__UpdateInstaller__ENTITY_SERVER__
#define controlsys_UpdateInstaller_entity_res controlsys_UpdateInstaller_component_res
#define controlsys_UpdateInstaller_entity_req controlsys_UpdateInstaller_component_req
#define controlsys_UpdateInstaller_entity controlsys_UpdateInstaller_component
static inline
void controlsys_UpdateInstaller_entity_init(struct controlsys_UpdateInstaller_entity *self,
                                            struct controlsys_UpdateInstallerInterface *interface)
{
    controlsys_UpdateInstaller_component_init(self,
                                              interface);
}
static inline
nk_err_t controlsys_UpdateInstaller_entity_dispatch(struct controlsys_UpdateInstaller_entity *self,
                                                    const
                                                    struct nk_message *req,
                                                    const
                                                    struct nk_arena *req_arena,
                                                    struct nk_message *res,
                                                    struct nk_arena *res_arena)
{
    return controlsys_UpdateInstaller_component_dispatch(self,
                                                         0,
                                                         req,
                                                         req_arena,
                                                         res,
                                                         res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateInstaller_entity controlsys_UpdateInstaller_entity
#define UpdateInstaller_entity_init controlsys_UpdateInstaller_entity_init
#define UpdateInstaller_entity_req controlsys_UpdateInstaller_entity_req
#define UpdateInstaller_entity_res controlsys_UpdateInstaller_entity_res
#define UpdateInstaller_entity_dispatch controlsys_UpdateInstaller_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateInstaller__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

