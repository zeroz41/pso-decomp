#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"

extern "C" {


extern u32 lbl_805D6E78;

u32 TAdMultiPlyChrSelectGC::get_move_effect(saddr ad_chr_move_effect_gc) {
    u32 var_r0;

    if ((u32) lbl_805D6E78 == 0U) {
        var_r0 = (uaddr)new TAdChrMoveEffectGC((TObject *)ad_chr_move_effect_gc);
        lbl_805D6E78 = var_r0;
    }
    return lbl_805D6E78;
}

}
