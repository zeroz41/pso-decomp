#ifndef PSO_WEAPON_TITEMWEAPONROD_H
#define PSO_WEAPON_TITEMWEAPONROD_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TItemWeaponRod::create (weapon_factory_table+0x2C).
class TItemWeaponRod : public TItemWeapon {
public:
    virtual ~TItemWeaponRod();
    TItemWeaponRod(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
