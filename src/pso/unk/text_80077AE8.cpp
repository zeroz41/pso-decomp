#include "types.h"
#include "pso/unk/text_80077AE8.h"
#include "pso/unk/text_80077B34.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern u32 lbl_805D4E58;

void TAdSinglePlyChrSelectGC__sub_80077AE8(s32 src) {
    if ((u32) lbl_805D4E58 == 0U) {
        lbl_805D4E58 = (int)::operator new(0x704);
    }
    fn_80077B34((u32 *)lbl_805D4E58, (u32 *)src);
}
