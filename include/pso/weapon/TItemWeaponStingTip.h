#ifndef PSO_WEAPON_TITEMWEAPONSTINGTIP_H
#define PSO_WEAPON_TITEMWEAPONSTINGTIP_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name init_effect_state): update_weapon
// spins rotation_z; the model hook (slot 60) turns model 1 by it and model 2 the
// other way. Made by TItemWeaponStingTip::create.
class TItemWeaponStingTip : public TItemWeapon {
public:
    virtual ~TItemWeaponStingTip();
    virtual void transform_model_node();
    TItemWeaponStingTip(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void update_weapon();
    s32 rotation_z;  // rotate_matrix_z angle of the model hook
};


#endif
