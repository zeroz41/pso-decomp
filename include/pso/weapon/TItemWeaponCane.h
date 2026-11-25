#ifndef PSO_WEAPON_TITEMWEAPONCANE_H
#define PSO_WEAPON_TITEMWEAPONCANE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponCane : public TItemWeapon {
public:
    TItemWeaponCane(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponCane();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    f32 scale;          // uniform model scale of item index 5, eased per state
    s32 attack_spawned; // set once update_attack has spawned its cane effect
};

#endif
