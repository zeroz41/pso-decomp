#ifndef PSO_WEAPON_TITEMWEAPONFLAMEVISIT_H
#define PSO_WEAPON_TITEMWEAPONFLAMEVISIT_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose effect descriptor carries spawn_flame_effect.
// Made by TItemWeaponFlameVisit::create (weapon_factory_table+0x54).
class TItemWeaponFlameVisit : public TItemWeapon {
public:
    TItemWeaponFlameVisit(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponFlameVisit();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);

    s32 hits; // 10 for item index 1, else 1; copied to the descriptor's +0x10
};


#endif
