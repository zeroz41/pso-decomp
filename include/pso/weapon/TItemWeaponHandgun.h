#ifndef PSO_WEAPON_TITEMWEAPONHANDGUN_H
#define PSO_WEAPON_TITEMWEAPONHANDGUN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TItemWeaponHandgun::create.
class TItemWeaponHandgun : public TItemWeapon {
public:
    virtual ~TItemWeaponHandgun();
    virtual void update_weapon();
    TItemWeaponHandgun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

// Made by TItemWeaponSuppressedGun::create. No destructor of its own: the
// compiler's comes last in the TU.
class TItemWeaponSuppressedGun : public TItemWeapon {
public:
    TItemWeaponSuppressedGun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
