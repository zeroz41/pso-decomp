#ifndef PSO_WEAPON_TITEMWEAPONHOLYRAY_H
#define PSO_WEAPON_TITEMWEAPONHOLYRAY_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponHolyRay : public TItemWeapon {
public:
    virtual ~TItemWeaponHolyRay();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponHolyRay(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 rotation_x;  // rotate_matrix_x in transform_model_node
    s32 rotation_z;  // rotate_matrix_z in transform_model_node
};

#endif
