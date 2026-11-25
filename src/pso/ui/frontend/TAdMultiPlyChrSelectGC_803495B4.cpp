#include "types.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"

TAdChrMoveEffectGC *TAdMultiPlyChrSelectGC::get_move_effect(saddr ad_chr_move_effect_gc) {
    if (chr_move_effect_instance == NULL) {
        chr_move_effect_instance = new TAdChrMoveEffectGC((TObject *)ad_chr_move_effect_gc);
    }
    return chr_move_effect_instance;
}
