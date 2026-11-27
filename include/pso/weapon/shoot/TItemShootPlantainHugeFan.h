#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTPLANTAINHUGEFAN_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTPLANTAINHUGEFAN_H
#include "types.h"
#include "pso/weapon/shoot/TItemShootModel.h"

class TItemShootPlantainHugeFan : public TItemShootModel {
public:
    virtual ~TItemShootPlantainHugeFan();
    TItemShootPlantainHugeFan(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life);
    virtual void hook();
    virtual void render();
};
LAYOUT_ASSERT(TItemShootPlantainHugeFan_size, sizeof(TItemShootPlantainHugeFan) == 0x6C);

#endif
