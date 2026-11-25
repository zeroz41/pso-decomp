#ifndef PSO_WEAPON_TITEMWEAPONDOUBLECANNON_H
#define PSO_WEAPON_TITEMWEAPONDOUBLECANNON_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDoubleCannon : public TItemWeapon {
public:
    TItemWeaponDoubleCannon(TObject *parent, u8 *item);
    virtual ~TItemWeaponDoubleCannon();
    virtual void transform_model_node();
    void sub_80124C90();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    s32 rotation_z; // rotate_matrix_z angle, advanced by update_weapon
};

#endif
