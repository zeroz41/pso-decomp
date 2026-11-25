#ifndef PSO_WEAPON_TITEMWEAPONBRANCHOFPAKUPAKU_H
#define PSO_WEAPON_TITEMWEAPONBRANCHOFPAKUPAKU_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponBranchOfPakupaku : public TItemWeapon {
public:
    virtual ~TItemWeaponBranchOfPakupaku();
    virtual void emit_marker_effects();
    TItemWeaponBranchOfPakupaku(TObject *parent, u8 *item);
};

#endif
