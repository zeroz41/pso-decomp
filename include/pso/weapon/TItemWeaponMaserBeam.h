#ifndef PSO_WEAPON_TITEMWEAPONMASERBEAM_H
#define PSO_WEAPON_TITEMWEAPONMASERBEAM_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponMaserBeam : public TItemWeapon {
public:
    TItemWeaponMaserBeam(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponMaserBeam();
    virtual void emit_marker_effects();
};

#endif
