#ifndef PSO_WEAPON_TITEMWEAPONDAGGER_H
#define PSO_WEAPON_TITEMWEAPONDAGGER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDagger : public TItemWeapon {
public:
    virtual ~TItemWeaponDagger();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponDagger(TObject *parent, u8 *item);
    f32 blade_scale;  // item index 5: eased to 1.0 on attack, 0.0 at idle (transform_model_node scale)
};

// Factory
TItem *create_dagger_weapon(u8 *item);

#endif
