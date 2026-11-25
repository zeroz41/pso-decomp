#ifndef PSO_WEAPON_TITEMWEAPONELYSION_H
#define PSO_WEAPON_TITEMWEAPONELYSION_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose emit_marker_effects launches TTecFoie at joint 1
// Made by TObjPlayer::create_vtable_804A3548.
class TItemWeaponElysion : public TItemWeapon {
public:
    virtual ~TItemWeaponElysion();
    virtual void emit_marker_effects();
    TItemWeaponElysion(TObject *parent, u8 *item);
};

#endif
