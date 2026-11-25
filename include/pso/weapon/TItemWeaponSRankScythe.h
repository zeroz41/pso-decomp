#ifndef PSO_WEAPON_TITEMWEAPONSRANKSCYTHE_H
#define PSO_WEAPON_TITEMWEAPONSRANKSCYTHE_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankScythe : public TUnk_804A4948 {
public:
    TItemWeaponSRankScythe(TObject *parent, u8 *item);
    virtual ~TItemWeaponSRankScythe();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    s32 rotation;  // rotate_matrix_z angle in transform_model_node, swung by update_attack
};

#endif
