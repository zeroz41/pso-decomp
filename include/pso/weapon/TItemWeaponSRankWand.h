#ifndef PSO_WEAPON_TITEMWEAPONSRANKWAND_H
#define PSO_WEAPON_TITEMWEAPONSRANKWAND_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankWand : public TItemWeaponSRank {
public:
    TItemWeaponSRankWand(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankWand();
    virtual void vfunc_62();
};

#endif
