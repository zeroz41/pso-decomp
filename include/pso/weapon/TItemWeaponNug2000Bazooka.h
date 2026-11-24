#ifndef PSO_WEAPON_TITEMWEAPONNUG2000BAZOOKA_H
#define PSO_WEAPON_TITEMWEAPONNUG2000BAZOOKA_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The NUG2000-Bazooka (weapon group 0x8D): one shot from joint 1 that explodes where it hits.
class TItemWeaponNug2000Bazooka : public TItemWeapon {
public:
    virtual ~TItemWeaponNug2000Bazooka();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    TItemWeaponNug2000Bazooka(TObject *parent, u8 *item);
};

TItem *create_nug2000_bazooka(u8 *item);

#endif
