#ifndef PSO_WEAPON_TITEMWEAPONNEISCLAW_H
#define PSO_WEAPON_TITEMWEAPONNEISCLAW_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponNeisClaw : public TItemWeapon {
public:
    virtual ~TItemWeaponNeisClaw();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void draw_held_model();
    virtual void update_attack();
    TItemWeaponNeisClaw(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    s32 spin_angle;  // each turned toward a target angle by update_idle/update_attack
    s32 second_spin_angle;
};

void spawn_fire_explosion_for_item(s32 id, const Vec *position);

#endif
