#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

extern "C" {

u32 TAdChrMoveEffectGC__ct(u32, s32);
u32 __nw__7TObjectFUl(s32);

extern u32 lbl_805D6E78;

u32 TAdMultiPlyChrSelectGC::get_move_effect(s32 ad_chr_move_effect_gc) {
    u32 var_r0;

    if ((u32) lbl_805D6E78 == 0U) {
        var_r0 = __nw__7TObjectFUl(0x3A4);
        if (var_r0 != 0U) {
            var_r0 = TAdChrMoveEffectGC__ct(var_r0, ad_chr_move_effect_gc);
        }
        lbl_805D6E78 = var_r0;
    }
    return lbl_805D6E78;
}

}
