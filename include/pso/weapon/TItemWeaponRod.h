#ifndef PSO_WEAPON_TITEMWEAPONROD_H
#define PSO_WEAPON_TITEMWEAPONROD_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by create_rod_weapon (weapon_factory_table+0x2C).
class TItemWeaponRod : public TItemWeapon {
public:
    virtual ~TItemWeaponRod();
    TItemWeaponRod(TObject *parent, u8 *item);
};

TItem *create_rod_weapon(u8 *item);

#endif
