#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"

TAdChrMoveEffectGC *TAdMultiPlyChrSelectGC::get_move_effect(saddr ad_chr_move_effect_gc) {
    if (lbl_805D6E78 == NULL) {
        lbl_805D6E78 = new TAdChrMoveEffectGC((TObject *)ad_chr_move_effect_gc);
    }
    return lbl_805D6E78;
}
