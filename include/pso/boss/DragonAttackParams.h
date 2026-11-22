#ifndef PSO_BOSS_DRAGON_ATTACK_PARAMS_H
#define PSO_BOSS_DRAGON_ATTACK_PARAMS_H

#include "types.h"
#include <stddef.h>

// The area attack block TObjEneDD::setup_instance delivers. radius sizes the hit body (above 100 the attack goes
// straight to area_attack_deliver_direct); &recoil is that call's first argument: area_attack_receive_direct hands
// the block's {kind, power} head to receive_direct_attack and *recoil to area_attack_apply_recoil, and
// contact_flags picks the bodies it tests (bit 0 player bodies, bit 1 enemy bodies).
struct DragonAttackParams {
    s32 kind;
    f32 power;
    f32 radius;
    f32 recoil;
    s32 contact_flags;
};
LAYOUT_ASSERT(DragonAttackParamsSize, sizeof(DragonAttackParams) == 20);
LAYOUT_ASSERT(DragonAttackParamsPower, offsetof(DragonAttackParams, power) == 4);
LAYOUT_ASSERT(DragonAttackParamsRadius, offsetof(DragonAttackParams, radius) == 8);
extern "C" void TBoss1Dragon__sub_80027A80(DragonAttackParams *destination, const DragonAttackParams *source);

#endif
