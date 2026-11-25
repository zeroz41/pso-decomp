#ifndef PSO_WEAPON_TITEMWEAPONTECHNICALCROZIER_H
#define PSO_WEAPON_TITEMWEAPONTECHNICALCROZIER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponTechnicalCrozier : public TItemWeapon {
public:
    virtual ~TItemWeaponTechnicalCrozier();
    virtual void emit_marker_effects();
    TItemWeaponTechnicalCrozier(TObject *parent, u8 *item);
};

#endif
