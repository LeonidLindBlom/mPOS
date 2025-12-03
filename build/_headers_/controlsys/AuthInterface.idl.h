#pragma GCC diagnostic push
#include <nk/transport.h>
#include <nk/types.h>
#ifndef ____UInt8__RAWTYPE__
#define ____UInt8__RAWTYPE__
nk_static_assert(sizeof(nk_uint8_t) == 1, bad_nk_uint8_t_size);
nk_static_assert(nk_alignof(nk_uint8_t) == 1, bad_nk_uint8_t_align);

#endif /* ____UInt8__RAWTYPE__ */

#ifndef __controlsys_AuthInterface__Bool__TYPEDEF__
#define __controlsys_AuthInterface__Bool__TYPEDEF__
typedef nk_uint8_t controlsys_AuthInterface_Bool;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_Bool controlsys_AuthInterface_Bool
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_AuthInterface__Bool__TYPEDEF__ */

#ifndef __controlsys_AuthInterface__RoleLen__CONST__
#define __controlsys_AuthInterface__RoleLen__CONST__
#define controlsys_AuthInterface_RoleLen ((nk_uint8_t)(NK_UINT8_C(16)))
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_RoleLen controlsys_AuthInterface_RoleLen
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys_AuthInterface__RoleLen__CONST__ */

#ifndef __controlsys__AuthInterface__INTERFACE__
#define __controlsys__AuthInterface__INTERFACE__
enum {
    controlsys_AuthInterface_CheckRole_mid,
    controlsys_AuthInterface_mid_max,
};
enum {
    controlsys_AuthInterface_CheckRole_req_role_size =
    17,
    controlsys_AuthInterface_CheckRole_req_arena_size =
    17,
    controlsys_AuthInterface_CheckRole_res_arena_size =
    0,
    controlsys_AuthInterface_CheckRole_req_handles =
    0,
    controlsys_AuthInterface_CheckRole_res_handles =
    0,
    controlsys_AuthInterface_CheckRole_err_handles =
    0,
    controlsys_AuthInterface_req_arena_size = 17,
    controlsys_AuthInterface_res_arena_size = 0,
    controlsys_AuthInterface_arena_size = 17,
    controlsys_AuthInterface_req_handles = 0,
    controlsys_AuthInterface_res_handles = 0,
    controlsys_AuthInterface_err_handles = 0,
};
typedef struct __nk_packed controlsys_AuthInterface_CheckRole_req {
            __nk_alignas(8)
            struct nk_message base_;
            __nk_alignas(4) nk_ptr_t role;
        } controlsys_AuthInterface_CheckRole_req;
#pragma pack(push, 8) /* controlsys_AuthInterface_CheckRole_res */
typedef struct controlsys_AuthInterface_CheckRole_err {
            __nk_alignas(8)
            struct nk_message base_;
        } controlsys_AuthInterface_CheckRole_err;
typedef struct controlsys_AuthInterface_CheckRole_res {
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
                struct controlsys_AuthInterface_CheckRole_err err_;
            };
        } controlsys_AuthInterface_CheckRole_res;
#pragma pack(pop) /* controlsys_AuthInterface_CheckRole_res */
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_CheckRole_mid controlsys_AuthInterface_CheckRole_mid
#define AuthInterface_mid_max controlsys_AuthInterface_mid_max
#define AuthInterface_CheckRole_req_role_size controlsys_AuthInterface_CheckRole_req_role_size
#define AuthInterface_CheckRole_req_arena_size controlsys_AuthInterface_CheckRole_req_arena_size
#define AuthInterface_CheckRole_res_arena_size controlsys_AuthInterface_CheckRole_res_arena_size
#define AuthInterface_CheckRole_req_handles controlsys_AuthInterface_CheckRole_req_handles
#define AuthInterface_CheckRole_res_handles controlsys_AuthInterface_CheckRole_res_handles
#define AuthInterface_CheckRole_err_handles controlsys_AuthInterface_CheckRole_err_handles
#define AuthInterface_req_arena_size controlsys_AuthInterface_req_arena_size
#define AuthInterface_res_arena_size controlsys_AuthInterface_res_arena_size
#define AuthInterface_arena_size controlsys_AuthInterface_arena_size
#define AuthInterface_req_handles controlsys_AuthInterface_req_handles
#define AuthInterface_res_handles controlsys_AuthInterface_res_handles
#define AuthInterface_err_handles controlsys_AuthInterface_err_handles
#define AuthInterface_CheckRole_req controlsys_AuthInterface_CheckRole_req
#define AuthInterface_CheckRole_res controlsys_AuthInterface_CheckRole_res
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__INTERFACE__ */

#ifndef __controlsys__AuthInterface__VTABLE__
#define __controlsys__AuthInterface__VTABLE__
typedef struct controlsys_AuthInterface {
            const
            struct controlsys_AuthInterface_ops *ops;
        } controlsys_AuthInterface;
typedef nk_err_t
controlsys_AuthInterface_CheckRole_fn(struct controlsys_AuthInterface *,
                                      const
                                      struct controlsys_AuthInterface_CheckRole_req *,
                                      const
                                      struct nk_arena *,
                                      struct controlsys_AuthInterface_CheckRole_res *,
                                      struct nk_arena *);
typedef struct controlsys_AuthInterface_ops {
            controlsys_AuthInterface_CheckRole_fn *CheckRole;
        } controlsys_AuthInterface_ops;
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_CheckRole_fn controlsys_AuthInterface_CheckRole_fn
#define AuthInterface_ops controlsys_AuthInterface_ops
#define AuthInterface controlsys_AuthInterface
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__VTABLE__ */

#ifndef __controlsys__AuthInterface__CLIENT__
#define __controlsys__AuthInterface__CLIENT__
typedef struct controlsys_AuthInterface_proxy {
            struct controlsys_AuthInterface base;
            struct nk_transport *transport;
            nk_iid_t iid;
        } controlsys_AuthInterface_proxy;
static inline
nk_err_t controlsys_AuthInterface_CheckRole_proxy(struct controlsys_AuthInterface_proxy *self,
                                                  struct controlsys_AuthInterface_CheckRole_req *req,
                                                  const
                                                  struct nk_arena *req_arena,
                                                  struct controlsys_AuthInterface_CheckRole_res *res,
                                                  struct nk_arena *res_arena)
{
    nk_err_t rc;
    
    nk_assert(self != NK_NULL);
    nk_assert(req != NK_NULL);
    nk_assert(res != NK_NULL);
    nk_req_reset(req);
    nk_msg_set_method_id(req, self->iid,
                         controlsys_AuthInterface_CheckRole_mid);
    nk_msg_set_ncaps(req,
                     controlsys_AuthInterface_CheckRole_req_handles);
    nk_req_reset(res);
    nk_msg_set_method_id(res, self->iid,
                         controlsys_AuthInterface_CheckRole_mid);
    nk_msg_set_ncaps(res,
                     controlsys_AuthInterface_CheckRole_res_handles);
    rc = nk_transport_call(self->transport,
                           &req->base_, req_arena,
                           &res->base_,
                           res_arena);
    return rc;
}
static inline
void controlsys_AuthInterface_proxy_init(struct controlsys_AuthInterface_proxy *self,
                                         struct nk_transport *transport,
                                         nk_iid_t iid)
{
    static const
    struct controlsys_AuthInterface_ops ops =
                                        {(controlsys_AuthInterface_CheckRole_fn *) &controlsys_AuthInterface_CheckRole_proxy};
    
    nk_assert(self != NK_NULL);
    self->base.ops = &ops;
    self->transport = transport;
    self->iid = iid;
}
static inline
nk_err_t controlsys_AuthInterface_CheckRole(struct controlsys_AuthInterface *self,
                                            struct controlsys_AuthInterface_CheckRole_req *req,
                                            const
                                            struct nk_arena *req_arena,
                                            struct controlsys_AuthInterface_CheckRole_res *res,
                                            struct nk_arena *res_arena)
{
    nk_assert(self != NK_NULL);
    nk_assert(self->ops != NK_NULL);
    nk_assert(self->ops->CheckRole != NK_NULL);
    return self->ops->CheckRole(self, req,
                                req_arena, res,
                                res_arena);
}
#ifdef NK_USE_UNQUALIFIED_NAMES
#define AuthInterface_CheckRole_proxy controlsys_AuthInterface_CheckRole_proxy
#define AuthInterface_CheckRole controlsys_AuthInterface_CheckRole
#define AuthInterface_proxy controlsys_AuthInterface_proxy
#define AuthInterface_proxy_init controlsys_AuthInterface_proxy_init
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__CLIENT__ */

#ifndef __controlsys__AuthInterface__SERVER__
#define __controlsys__AuthInterface__SERVER__
typedef union controlsys_AuthInterface_req {
            struct nk_message base_;
            struct controlsys_AuthInterface_CheckRole_req CheckRole;
        } controlsys_AuthInterface_req;
typedef union controlsys_AuthInterface_res {
            struct nk_message base_;
            struct controlsys_AuthInterface_CheckRole_res CheckRole;
        } controlsys_AuthInterface_res;
static inline
nk_err_t controlsys_AuthInterface_interface_dispatch(struct controlsys_AuthInterface *impl,
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
            
          case controlsys_AuthInterface_CheckRole_mid:
            {
                struct controlsys_AuthInterface_CheckRole_res
                *res_ =
                (struct controlsys_AuthInterface_CheckRole_res *) res;
                
                rc = impl->ops->CheckRole(impl,
                                          (const
                                           struct controlsys_AuthInterface_CheckRole_req *) req,
                                          req_arena,
                                          res_,
                                          res_arena);
                if (rc == NK_EOK) {
                    nk_req_reset(&res_->res_);
                    nk_msg_set_ncaps(res_,
                                     controlsys_AuthInterface_CheckRole_res_handles);
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
#define AuthInterface_req controlsys_AuthInterface_req
#define AuthInterface_res controlsys_AuthInterface_res
#define AuthInterface_interface_dispatch controlsys_AuthInterface_interface_dispatch
#endif /* NK_USE_UNQUALIFIED_NAMES */

#endif /* __controlsys__AuthInterface__SERVER__ */

#ifndef __controlsys__AuthInterface__TESTS__
#define __controlsys__AuthInterface__TESTS__
static inline
nk_err_t controlsys_AuthInterface_CheckRole_test_req(struct controlsys_AuthInterface_CheckRole_req *msg,
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
                                     &msg->role,
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
nk_err_t controlsys_AuthInterface_CheckRole_test_res(struct controlsys_AuthInterface_CheckRole_res *msg,
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
nk_err_t controlsys_AuthInterface_CheckRole_test_err(struct controlsys_AuthInterface_CheckRole_err *msg,
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

#endif /* __controlsys__AuthInterface__TESTS__ */

#pragma GCC diagnostic pop

