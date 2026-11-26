#ifndef PSO_WEAPON_TITEMWEAPONLAVISBLADE_H
#define PSO_WEAPON_TITEMWEAPONLAVISBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponLavisBlade : public TItemWeapon {
public:
    TItemWeaponLavisBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponLavisBlade();
    virtual void emit_marker_effects();
};


#endif
