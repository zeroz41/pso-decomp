#ifndef PSO_WEAPON_TITEMWEAPONGUARDIANNA_H
#define PSO_WEAPON_TITEMWEAPONGUARDIANNA_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The guardianna weapon class, made by create_guardianna.
class TItemWeaponGuardianna : public TItemWeapon {
public:
    TItemWeaponGuardianna(TObject *parent, u8 *item);
    virtual ~TItemWeaponGuardianna();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

TItem *create_guardianna(u8 *item);

#endif
