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

#ifndef __controlsys__Journal__COMPONENT_ENDPOINTS__
#define __controlsys__Journal__COMPONENT_ENDPOINTS__
enum {
    controlsys_Journal_interface_iid,
    controlsys_Journal_iidMax,
};
enum {
    controlsys_Journal_iidOffset = 0,
};
enum {
    controlsys_Journal_securityIidMax,
};
enum {
    controlsys_Journal_component_req_arena_size =
    58,
    controlsys_Journal_component_res_arena_size =
    129,
    controlsys_Journal_component_arena_size = 129,
    controlsys_Journal_component_req_handles = 0,
    controlsys_Journal_component_res_handles = 0,
    controlsys_Journal_component_err_handles = 0,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define Journal_interface_iid controlsys_Journal_interface_iid
#define Journal_iidMax controlsys_Journal_iidMax
#define Journal_iidOffset controlsys_Journal_iidOffset
#define Journal_securityIidMax controlsys_Journal_securityIidMax
#define Journal_component_req_arena_size controlsys_Journal_component_req_arena_size
#define Journal_component_res_arena_size controlsys_Journal_component_res_arena_size
#define Journal_component_arena_size controlsys_Journal_component_arena_size
#define Journal_component_req_handles controlsys_Journal_component_req_handles
#define Journal_component_res_handles controlsys_Journal_component_res_handles
#define Journal_component_err_handles controlsys_Journal_component_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__Journal__COMPONENT_ENDPOINTS__ */

#ifndef __controlsys__Journal__TASK_ENDPOINTS__
#define __controlsys__Journal__TASK_ENDPOINTS__
enum {
    controlsys_Journal_entity_req_arena_size =
    controlsys_Journal_component_req_arena_size,
    controlsys_Journal_entity_res_arena_size =
    controlsys_Journal_component_res_arena_size,
    controlsys_Journal_entity_arena_size =
    controlsys_Journal_component_arena_size,
    controlsys_Journal_entity_req_handles =
    controlsys_Journal_component_req_handles,
    controlsys_Journal_entity_res_handles =
    controlsys_Journal_component_res_handles,
    controlsys_Journal_entity_err_handles =
    controlsys_Journal_component_err_handles,
};
#ifdef NK_USE_UNQUALIFIED_NAMES
#define Journal_entity_req_arena_size controlsys_Journal_entity_req_arena_size
#define Journal_entity_res_arena_size controlsys_Journal_entity_res_arena_size
#define Journal_entity_arena_size controlsys_Journal_entity_arena_size
#define Journal_entity_req_handles controlsys_Journal_entity_req_handles
#define Journal_entity_res_handles controlsys_Journal_entity_res_handles
#define Journal_entity_err_handles controlsys_Journal_entity_err_handles
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__Journal__TASK_ENDPOINTS__ */

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

#ifndef __controlsys__Journal__COMPONENT_SERVER_TYPES__
#define __controlsys__Journal__COMPONENT_SERVER_TYPES__
typedef struct controlsys_Journal_component {
            struct controlsys_JournalInterface *interface;
        } controlsys_Journal_component;

#endif /* __controlsys__Journal__COMPONENT_SERVER_TYPES__ */

#ifndef __controlsys__Journal__COMPONENT_SERVER_DISPATCHER__
#define __controlsys__Journal__COMPONENT_SERVER_DISPATCHER__
static inline
void controlsys_Journal_component_init(struct controlsys_Journal_component *self,
                                       struct controlsys_JournalInterface *interface)
{
    nk_assert(self != NK_NULL);
    nk_unused(self);
    self->interface = interface;
}
typedef union controlsys_Journal_component_req {
            struct nk_message base_;
            controlsys_JournalInterface_req interface;
        } controlsys_Journal_component_req;
typedef union controlsys_Journal_component_res {
            struct nk_message base_;
            controlsys_JournalInterface_res interface;
        } controlsys_Journal_component_res;
static inline
nk_err_t controlsys_Journal_component_dispatch(struct controlsys_Journal_component *self,
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
        
      case controlsys_Journal_interface_iid:
        return controlsys_JournalInterface_interface_dispatch(self->interface,
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
#define Journal_component controlsys_Journal_component
#define Journal_component_init controlsys_Journal_component_init
#define Journal_component_req controlsys_Journal_component_req
#define Journal_component_res controlsys_Journal_component_res
#define Journal_component_dispatch controlsys_Journal_component_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__Journal__COMPONENT_SERVER_DISPATCHER__ */

#ifndef __controlsys__Journal__ENTITY_SERVER__
#define __controlsys__Journal__ENTITY_SERVER__
#define controlsys_Journal_entity_res controlsys_Journal_component_res
#define controlsys_Journal_entity_req controlsys_Journal_component_req
#define controlsys_Journal_entity controlsys_Journal_component
static inline
void controlsys_Journal_entity_init(struct controlsys_Journal_entity *self,
                                    struct controlsys_JournalInterface *interface)
{
    controlsys_Journal_component_init(self,
                                      interface);
}
static inline
nk_err_t controlsys_Journal_entity_dispatch(struct controlsys_Journal_entity *self,
                                            const
                                            struct nk_message *req,
                                            const
                                            struct nk_arena *req_arena,
                                            struct nk_message *res,
                                            struct nk_arena *res_arena)
{
    return controlsys_Journal_component_dispatch(self,
                                                 0,
                                                 req,
                                                 req_arena,
                                                 res,
                                                 res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define Journal_entity controlsys_Journal_entity
#define Journal_entity_init controlsys_Journal_entity_init
#define Journal_entity_req controlsys_Journal_entity_req
#define Journal_entity_res controlsys_Journal_entity_res
#define Journal_entity_dispatch controlsys_Journal_entity_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__Journal__ENTITY_SERVER__ */

#pragma GCC diagnostic pop

