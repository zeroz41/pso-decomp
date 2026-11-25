#ifndef PSO_WEAPON_TITEMWEAPONSRANKBLADE_H
#define PSO_WEAPON_TITEMWEAPONSRANKBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankBlade : public TItemWeaponSRank {
public:
    TItemWeaponSRankBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankBlade();
};

#endif
