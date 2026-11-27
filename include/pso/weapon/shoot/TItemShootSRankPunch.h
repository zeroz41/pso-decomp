#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTSRANKPUNCH_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTSRANKPUNCH_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TItemWeaponSRankPunch;

// The shot model TObjPlayer::spawn_shot_effect news for TItemWeaponSRankPunch.
class TItemShootSRankPunch : public TItemShootModel {
public:
    TItemShootSRankPunch(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemShootSRankPunch();
    virtual void hook();
    virtual void render();
};

// Picks the model the owning weapon draws its shots with (0x188 while flag 4 is set, else 0x184).
NJS_OBJECT *get_punch_shot_model(TItemWeaponSRankPunch *punch);

LAYOUT_ASSERT(TItemShootSRankPunch_size, sizeof(TItemShootSRankPunch) == 0x6C);

#endif
