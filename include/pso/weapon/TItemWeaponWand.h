#ifndef PSO_WEAPON_TITEMWEAPONWAND_H
#define PSO_WEAPON_TITEMWEAPONWAND_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponWand : public TItemWeapon {
public:
    virtual ~TItemWeaponWand();
    virtual void emit_marker_effects();
    TItemWeaponWand(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
