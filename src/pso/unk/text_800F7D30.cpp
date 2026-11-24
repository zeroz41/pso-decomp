#include "types.h"
#include "pso/unk/text_800F7D30.h"
#include "pso/system/memory.h"
#include "pso/system/prs.h"

extern "C" {

u32 prs_decompress_alloc(s32 src, s32 dst) {
    u32 size;
    PrsDecoder *prs = new PrsDecoder;
    if (prs != NULL) {
        size = prs->prs_decompress((u8 *)dst, (u8 *)src, 0);
    }
    if (prs != NULL) {
        delete prs;
    }
    return size;
}

}
