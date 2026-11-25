#ifndef PSO_WEAPON_TITEMWEAPONRIFLE_H
#define PSO_WEAPON_TITEMWEAPONRIFLE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TItemWeaponRifle::create.
class TItemWeaponRifle : public TItemWeapon {
public:
    TItemWeaponRifle(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponRifle();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    f32 barrel_scale;
};

#endif
