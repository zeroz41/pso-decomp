#ifndef PSO_BOSS_DRAGON_ATTACK_PARAMS_H
#define PSO_BOSS_DRAGON_ATTACK_PARAMS_H

#include "types.h"
#include <stddef.h>

struct DragonAttackParams {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    s32 field_10;
};
LAYOUT_ASSERT(DragonAttackParamsSize, sizeof(DragonAttackParams) == 20);
LAYOUT_ASSERT(DragonAttackParamsFloat4, offsetof(DragonAttackParams, field_4) == 4);
LAYOUT_ASSERT(DragonAttackParamsRadius, offsetof(DragonAttackParams, field_8) == 8);
extern "C" void TBoss1Dragon__sub_80027A80(DragonAttackParams *destination, const DragonAttackParams *source);

#endif
