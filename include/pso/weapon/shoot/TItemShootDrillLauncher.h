#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTDRILLLAUNCHER_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTDRILLLAUNCHER_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

// The drill launcher's shot (drill_launcher_create_shot).
class TItemShootDrillLauncher : public TItemShootModel {
public:
    TItemShootDrillLauncher(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemShootDrillLauncher();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TItemShootDrillLauncher_size, sizeof(TItemShootDrillLauncher) == 0x6C);

#endif
