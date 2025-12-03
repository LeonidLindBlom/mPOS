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

#ifndef __controlsys__UpdateVerifier__COMPONENT_ENDPOINTS__
#define __controlsys__UpdateVerifier__COMPONENT_ENDPOINTS__
enum {
    controlsys_UpdateVerifier_interface_iid,
    controlsys_UpdateVerifier_iidMax,
};
enum {
    controlsys_UpdateVerifier_iidOffset = 0,
};
enum {
    controlsys_UpdateVerifier_securityIidMax,
};
enum {
    controlsys_UpdateVerifier_component_req_arena_size =
    17,
    controlsys_UpdateVerifier_component_res_arena_size =
    0,
    controlsys_UpdateVerifier_component_arena_size =
    17,
    controlsys_UpdateVerifier_component_req_handles =
    0,
    controlsys_UpdateVerifier_component_res_handles =
    0,
    controlsys_UpdateVerifier_component_err_handles =
    0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifier_interface_iid controlsys_UpdateVerifier_interface_iid
#define UpdateVerifier_iidMax controlsys_UpdateVerifier_iidMax
#define UpdateVerifier_iidOffset controlsys_UpdateVerifier_iidOffset
#define UpdateVerifier_securityIidMax controlsys_UpdateVerifier_securityIidMax
#define UpdateVerifier_component_req_arena_size controlsys_UpdateVerifier_component_req_arena_size
#define UpdateVerifier_component_res_arena_size controlsys_UpdateVerifier_component_res_arena_size
#define UpdateVerifier_component_arena_size controlsys_UpdateVerifier_component_arena_size
#define UpdateVerifier_component_req_handles controlsys_UpdateVerifier_component_req_handles
#define UpdateVerifier_component_res_handles controlsys_UpdateVerifier_component_res_handles
#define UpdateVerifier_component_err_handles controlsys_UpdateVerifier_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifier__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__UpdateVerifier__TASK_ENDPOINTS__
#define __controlsys__UpdateVerifier__TASK_ENDPOINTS__
enum {
    controlsys_UpdateVerifier_entity_req_arena_size =
    controlsys_UpdateVerifier_component_req_arena_size,
    controlsys_UpdateVerifier_entity_res_arena_size =
    controlsys_UpdateVerifier_component_res_arena_size,
    controlsys_UpdateVerifier_entity_arena_size =
    controlsys_UpdateVerifier_component_arena_size,
    controlsys_UpdateVerifier_entity_req_handles =
    controlsys_UpdateVerifier_component_req_handles,
    controlsys_UpdateVerifier_entity_res_handles =
    controlsys_UpdateVerifier_component_res_handles,
    controlsys_UpdateVerifier_entity_err_handles =
    controlsys_UpdateVerifier_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifier_entity_req_arena_size controlsys_UpdateVerifier_entity_req_arena_size
#define UpdateVerifier_entity_res_arena_size controlsys_UpdateVerifier_entity_res_arena_size
#define UpdateVerifier_entity_arena_size controlsys_UpdateVerifier_entity_arena_size
#define UpdateVerifier_entity_req_handles controlsys_UpdateVerifier_entity_req_handles
#define UpdateVerifier_entity_res_handles controlsys_UpdateVerifier_entity_res_handles
#define UpdateVerifier_entity_err_handles controlsys_UpdateVerifier_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifier__TASK_ENDPOINTS__ */

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

#ifndef __controlsys__UpdateVerifier__COMPONENT_SERVER_TYPES__
#define __controlsys__UpdateVerifier__COMPONENT_SERVER_TYPES__
typedef struct controlsys_UpdateVerifier_component {
            struct controlsys_UpdateVerifierInterface *interface;
        } controlsys_UpdateVerifier_component;

#endif /* __controlsys__UpdateVerifier__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__UpdateVerifier__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__UpdateVerifier__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_UpdateVerifier_component_init(struct controlsys_UpdateVerifier_component *self,
                                              struct controlsys_UpdateVerifierInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_UpdateVerifier_component_req {
            struct nk_message base_;
            controlsys_UpdateVerifierInterface_req interface;
        } controlsys_UpdateVerifier_component_req;
typedef union controlsys_UpdateVerifier_component_res {
            struct nk_message base_;
            controlsys_UpdateVerifierInterface_res interface;
        } controlsys_UpdateVerifier_component_res;
static inline
nk_err_t controlsys_UpdateVerifier_component_dispatch(struct controlsys_UpdateVerifier_component *self,
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
        
      case controlsys_UpdateVerifier_interface_iid:
        return controlsys_UpdateVerifierInterface_interface_dispatch(self->interface,
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
#define UpdateVerifier_component controlsys_UpdateVerifier_component
#define UpdateVerifier_component_init controlsys_UpdateVerifier_component_init
#define UpdateVerifier_component_req controlsys_UpdateVerifier_component_req
#define UpdateVerifier_component_res controlsys_UpdateVerifier_component_res
#define UpdateVerifier_component_dispatch controlsys_UpdateVerifier_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifier__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__UpdateVerifier__ENTITY_SERVER__
#define __controlsys__UpdateVerifier__ENTITY_SERVER__
#define controlsys_UpdateVerifier_entity_res controlsys_UpdateVerifier_component_res
#define controlsys_UpdateVerifier_entity_req controlsys_UpdateVerifier_component_req
#define controlsys_UpdateVerifier_entity controlsys_UpdateVerifier_component
static inline
void controlsys_UpdateVerifier_entity_init(struct controlsys_UpdateVerifier_entity *self,
                                           struct controlsys_UpdateVerifierInterface *interface)
{
    controlsys_UpdateVerifier_component_init(self,
                                             interface);
}
static inline
nk_err_t controlsys_UpdateVerifier_entity_dispatch(struct controlsys_UpdateVerifier_entity *self,
                                                   const
                                                   struct nk_message *req,
                                                   const
                                                   struct nk_arena *req_arena,
                                                   struct nk_message *res,
                                                   struct nk_arena *res_arena)
{
    return controlsys_UpdateVerifier_component_dispatch(self,
                                                        0,
                                                        req,
                                                        req_arena,
                                                        res,
                                                        res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define UpdateVerifier_entity controlsys_UpdateVerifier_entity
#define UpdateVerifier_entity_init controlsys_UpdateVerifier_entity_init
#define UpdateVerifier_entity_req controlsys_UpdateVerifier_entity_req
#define UpdateVerifier_entity_res controlsys_UpdateVerifier_entity_res
#define UpdateVerifier_entity_dispatch controlsys_UpdateVerifier_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__UpdateVerifier__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

