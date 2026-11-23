#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTROCKETPUNCH_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTROCKETPUNCH_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TItemWeaponRocketPunch;

// The rocket punch's shot (rocket_punch_create_shot).
class TItemShootRocketPunch : public TItemShootModel {
public:
    TItemShootRocketPunch(TItemWeaponRocketPunch *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemShootRocketPunch();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TItemShootRocketPunch_size, sizeof(TItemShootRocketPunch) == 0x6C);

#endif
