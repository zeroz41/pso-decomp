#ifndef PSO_WEAPON_TITEMWEAPONDARKMETEOR_H
#define PSO_WEAPON_TITEMWEAPONDARKMETEOR_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Dark Meteor (weapon group 0x9E): five shots from its barrels, or in mode 2 a TItemEffOrgaFlowShot
// volley when its special is ready.
class TItemWeaponDarkMeteor : public TItemWeapon {
public:
    TItemWeaponDarkMeteor(TObject *parent, u8 *item);
    virtual ~TItemWeaponDarkMeteor();
    virtual void emit_marker_effects();
    virtual void update_attack();
    virtual void update_idle();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_60();
    // Spun by update_idle and update_attack; vfunc_60 rotates the model about z by it.
    s32 rotation_z;
};

TItem *create_dark_meteor_weapon(u8 *item);

#endif
