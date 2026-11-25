#ifndef PSO_WEAPON_TITEMWEAPONDRAGONSCLAW_H
#define PSO_WEAPON_TITEMWEAPONDRAGONSCLAW_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDragonsClaw : public TItemWeapon {
public:
    TItemWeaponDragonsClaw(TObject *parent, u8 *item);
    virtual ~TItemWeaponDragonsClaw();
    virtual void on_equipped();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
};

#endif
