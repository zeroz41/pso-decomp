#ifndef PSO_WEAPON_TITEMWEAPONSRANKKNUCKLE_H
#define PSO_WEAPON_TITEMWEAPONSRANKKNUCKLE_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankKnuckle : public TItemWeaponSRank {
public:
    TItemWeaponSRankKnuckle(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankKnuckle();
    virtual void on_equipped();  // equip hook: sets the owner's EVP
    virtual void on_unequipped();
    virtual void vfunc_62();  // marker effect at the owner's knuckle joint
};

#endif
