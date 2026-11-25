#ifndef PSO_WEAPON_TITEMWEAPONCADUCEUS_H
#define PSO_WEAPON_TITEMWEAPONCADUCEUS_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose emit_marker_effects launches TTecFoie.
class TItemWeaponCaduceus : public TItemWeapon {
public:
    virtual ~TItemWeaponCaduceus();
    TItemWeaponCaduceus(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
};

#endif
