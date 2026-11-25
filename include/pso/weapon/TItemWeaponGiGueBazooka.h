#ifndef PSO_WEAPON_TITEMWEAPONGIGUEBAZOOKA_H
#define PSO_WEAPON_TITEMWEAPONGIGUEBAZOOKA_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponGiGueBazooka : public TItemWeapon {
public:
    virtual ~TItemWeaponGiGueBazooka();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    TItemWeaponGiGueBazooka(TObject *parent, u8 *item);
    s32 spin_angle;  // each turned toward a target angle by update_idle/update_attack
    s32 second_spin_angle;
    s32 third_spin_angle;
};

#endif
