#ifndef PSO_WEAPON_TITEMWEAPONSPREADNEEDLE_H
#define PSO_WEAPON_TITEMWEAPONSPREADNEEDLE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Needle-shooting weapon class (old ctor name init_state_2): fires five
// needles from joint 1. Made by TItemWeaponSpreadNeedle::create.
class TItemWeaponSpreadNeedle : public TItemWeapon {
public:
    virtual ~TItemWeaponSpreadNeedle();
    virtual void emit_marker_effects();
    TItemWeaponSpreadNeedle(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

extern const s32 five_joint_shot_angle_table[5];

#endif
