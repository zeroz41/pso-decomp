#ifndef PSO_WEAPON_TITEMWEAPONDRILLLAUNCHER_H
#define PSO_WEAPON_TITEMWEAPONDRILLLAUNCHER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by TItemWeaponDrillLauncher::create.
class TItemWeaponDrillLauncher : public TItemWeapon {
public:
    TItemWeaponDrillLauncher(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponDrillLauncher();
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    s32 projectile_visible;   // drill_launcher_return_timer sets it back
    s32 projectile_spin;
    s32 recoil_angle;         // rotate_matrix_z in transform_model_node
    s32 recoil_phase;
};

s32 get_burst_counter(void *p);
void increment_burst_counter(u8 *counter);

#endif
