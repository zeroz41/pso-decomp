#ifndef PSO_WEAPON_TITEMWEAPONSPECIALGUN_H
#define PSO_WEAPON_TITEMWEAPONSPECIALGUN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponSpecialGun : public TItemWeapon {
public:
    virtual ~TItemWeaponSpecialGun();
    TItemWeaponSpecialGun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
