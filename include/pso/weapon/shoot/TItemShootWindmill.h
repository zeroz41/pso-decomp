#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTWINDMILL_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTWINDMILL_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TItemShootWindmill : public TItemShootModel {
public:
    TItemShootWindmill(void *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual ~TItemShootWindmill();
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TItemShootWindmill_size, sizeof(TItemShootWindmill) == 0x6C);

#endif
