#ifndef PSO_WEAPON_TITEMWEAPONSRANKGUN_H
#define PSO_WEAPON_TITEMWEAPONSRANKGUN_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankGun : public TItemWeaponSRank {
public:
    TItemWeaponSRankGun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankGun();
};

#endif
