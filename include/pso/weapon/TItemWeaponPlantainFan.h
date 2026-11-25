#ifndef PSO_WEAPON_TITEMWEAPONPLANTAINFAN_H
#define PSO_WEAPON_TITEMWEAPONPLANTAINFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponPlantainFan : public TItemWeapon {
public:
    virtual ~TItemWeaponPlantainFan();
    TItemWeaponPlantainFan(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void emit_marker_effects();
};

#endif
