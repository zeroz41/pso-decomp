#ifndef PSO_WEAPON_TITEMWEAPONMECHGUN_H
#define PSO_WEAPON_TITEMWEAPONMECHGUN_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponMechgun : public TItemWeapon {
public:
    TItemWeaponMechgun(TObject *parent, u8 *item);
    virtual ~TItemWeaponMechgun();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    Vec muzzle[2];
    s32 effectJoint;
    s32 effectAngle;
    s32 effectScaleJoint;
    s32 effectFrame;
};

TItem *create_mechgun_weapon(u8 *item);

#endif
