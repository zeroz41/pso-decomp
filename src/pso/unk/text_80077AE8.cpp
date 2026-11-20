#include "types.h"
#include "pso/unk/text_80077AE8.h"
#include "pso/unk/text_80077B34.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern u32 lbl_805D4E58;

void TAdSinglePlyChrSelectGC__sub_80077AE8(s32 src) {
    if ((u32) lbl_805D4E58 == 0U) {
        lbl_805D4E58 = (saddr)::operator new(0x704);
    }
    fn_80077B34((u32 *)lbl_805D4E58, (u32 *)src);
}

u32 *fn_80077B34(u32 *dst, u32 *src) {
    u32 *d = dst;
    u32 b;
    u32 a;
    s32 i;
    *dst = *src;
    for (i = 0; i < 0xe0; i++) {
        a = src[1];
        b = *(src += 2);
        d[1] = a;
        *(d += 2) = b;
    }
    return dst;
}
