#ifndef PSO_WEAPON_TITEMWEAPONRAPPYSFAN_H
#define PSO_WEAPON_TITEMWEAPONRAPPYSFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponRappysFan : public TItemWeapon {
public:
    virtual ~TItemWeaponRappysFan();
    virtual void emit_marker_effects();
    TItemWeaponRappysFan(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
