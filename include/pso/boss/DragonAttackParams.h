#ifndef PSO_BOSS_DRAGON_ATTACK_PARAMS_H
#define PSO_BOSS_DRAGON_ATTACK_PARAMS_H

#include "types.h"
#include "pso/enemy/AreaAttackContact.h"
#include "pso/object/base/TObjChara.h"
#include <stddef.h>

// The area attack block TObjEneDD::setup_instance delivers. radius sizes the hit body (above 100 the attack goes
// straight to area_attack_deliver_direct); contact is that call's first argument: area_attack_receive_direct hands
// the block's attack head to receive_direct_attack and the contact's recoil to area_attack_apply_recoil.
struct DragonAttackParams {
    DirectAttackPayload attack;
    f32 radius;
    AreaAttackContact contact;
};
LAYOUT_ASSERT(DragonAttackParamsSize, sizeof(DragonAttackParams) == 20);
LAYOUT_ASSERT(DragonAttackParamsRadius, offsetof(DragonAttackParams, radius) == 8);
LAYOUT_ASSERT(DragonAttackParamsContact, offsetof(DragonAttackParams, contact) == 12);
void copy_dragon_attack_params(DragonAttackParams *destination, const DragonAttackParams *source);

#endif
