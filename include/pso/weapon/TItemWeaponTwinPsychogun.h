#ifndef PSO_WEAPON_TITEMWEAPONTWINPSYCHOGUN_H
#define PSO_WEAPON_TITEMWEAPONTWINPSYCHOGUN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponTwinPsychogun : public TItemWeapon {
public:
    virtual ~TItemWeaponTwinPsychogun();
    virtual void emit_marker_effects();
    virtual void draw_held_model();
    TItemWeaponTwinPsychogun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec gun_point;         // first gun's shot origin (as TItemWeaponGuldMilla)
    Vec second_gun_point;  // second gun's
};

#endif
