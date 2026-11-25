#ifndef PSO_WEAPON_TITEMWEAPONIMPERIALPICK_H
#define PSO_WEAPON_TITEMWEAPONIMPERIALPICK_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponImperialPick : public TItemWeapon {
public:
    virtual ~TItemWeaponImperialPick();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponImperialPick(TObject *parent, u8 *item);
    s32 rotation_z;  // rotate_matrix_z in transform_model_node
};

#endif
