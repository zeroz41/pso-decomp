#include "types.h"
#include "pso/misc/TechniqueBoost.h"

void TechniqueBoostTable::set(s32 index, TechniqueBoost *boost) {
    if (index < 6) {
        boosts[index].copy_from(boost);
    }
}

void TechniqueBoost::copy_from(TechniqueBoost *src) {
    technique = src->technique;
    flags = src->flags;
    amount = src->amount;
}

void TechniqueBoostTable::clear() {
    int i;
    for (i = 0; i < 6; i++) {
        boosts[i].clear();
    }
}
