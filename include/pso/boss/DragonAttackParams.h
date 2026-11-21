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
typedef char DragonAttackParamsSize[sizeof(DragonAttackParams) == 20 ? 1 : -1];
typedef char DragonAttackParamsFloat4[offsetof(DragonAttackParams, field_4) == 4 ? 1 : -1];
typedef char DragonAttackParamsRadius[offsetof(DragonAttackParams, field_8) == 8 ? 1 : -1];
extern "C" void TBoss1Dragon__sub_80027A80(DragonAttackParams *destination, const DragonAttackParams *source);

#endif
