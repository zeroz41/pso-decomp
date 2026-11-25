#ifndef PSO_WEAPON_TITEMWEAPONSRANKWAND_H
#define PSO_WEAPON_TITEMWEAPONSRANKWAND_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankWand : public TUnk_804A4948 {
public:
    TItemWeaponSRankWand(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankWand();
    virtual void vfunc_62();
};

#endif
