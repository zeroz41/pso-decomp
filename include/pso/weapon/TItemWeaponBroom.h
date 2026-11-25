#ifndef PSO_WEAPON_TITEMWEAPONBROOM_H
#define PSO_WEAPON_TITEMWEAPONBROOM_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponBroom : public TItemWeapon {
public:
    virtual ~TItemWeaponBroom();
    TItemWeaponBroom(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
};

#endif
