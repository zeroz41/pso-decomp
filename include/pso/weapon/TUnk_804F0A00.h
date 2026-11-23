#ifndef PSO_WEAPON_TUNK_804F0A00_H
#define PSO_WEAPON_TUNK_804F0A00_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0A00 : public TItemWeapon {
public:
    virtual ~TUnk_804F0A00();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    TUnk_804F0A00(TObject *parent, u8 *item);
    s32 spin_angle;  // each turned toward a target angle by update_idle/update_attack
    s32 second_spin_angle;
    s32 third_spin_angle;
};

#endif
