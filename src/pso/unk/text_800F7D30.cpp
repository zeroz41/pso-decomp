#include "types.h"
#include "pso/unk/text_800F7D30.h"
#include "pso/system/memory.h"
#include "pso/system/prs.h"

s32 prs_decompress_alloc(const void *src, void *dst, s32 size_limit) {
    s32 size;
    PrsDecoder *prs = new PrsDecoder;
    if (prs != NULL) {
        size = prs->prs_decompress((u8 *)dst, (u8 *)src, 0);
    }
    if (prs != NULL) {
        delete prs;
    }
    return size;
}
