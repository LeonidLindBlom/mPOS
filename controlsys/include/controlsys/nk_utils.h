#ifndef CONTROLSYS_NK_UTILS_H
#define CONTROLSYS_NK_UTILS_H

#include <nk/arena.h>
#include <services/rtl/nk_cstr.h>

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void nk_str_set(nk_ptr_t* dest,
                              const char* value,
                              struct nk_arena* arena) {
    if (!dest || !arena) {
        return;
    }
    const char* text = value ? value : "";
    if (nk_arena_store(char, arena, dest, text, strlen(text) + 1) != 0) {
        dest->offset = 0;
        dest->size = 0;
    }
}

static inline const char* nk_str_read(const nk_ptr_t* src,
                                      const struct nk_arena* arena) {
    static const char empty[] = "";
    if (!src || !arena) {
        return empty;
    }
    const nk_char_t* out = empty;
    if (RtlArenaGetCStr(arena, src, &out) != rcOk || !out) {
        return empty;
    }
    return (const char*)out;
}

#ifdef __cplusplus
}
#endif

#endif /* CONTROLSYS_NK_UTILS_H */
