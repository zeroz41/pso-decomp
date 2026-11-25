#ifndef PSO_WEAPON_TITEMWEAPONSRANKSCYTHE_H
#define PSO_WEAPON_TITEMWEAPONSRANKSCYTHE_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankScythe : public TItemWeaponSRank {
public:
    TItemWeaponSRankScythe(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankScythe();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    s32 rotation;  // rotate_matrix_z angle in transform_model_node, swung by update_attack
};

#endif
