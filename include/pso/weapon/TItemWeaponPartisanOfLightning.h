#ifndef PSO_WEAPON_TITEMWEAPONPARTISANOFLIGHTNING_H
#define PSO_WEAPON_TITEMWEAPONPARTISANOFLIGHTNING_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponPartisanOfLightning : public TItemWeapon {
public:
    TItemWeaponPartisanOfLightning(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponPartisanOfLightning();
    virtual void update_attack();
    virtual void update_idle();
    virtual void transform_model_node();
    f32 effect_thickness;  // scale_matrix y/z of the effect passes: shrinks to 0 idle, grows to 1 attacking
};

#endif
