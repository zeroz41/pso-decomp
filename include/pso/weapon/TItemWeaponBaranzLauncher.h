#ifndef PSO_WEAPON_TITEMWEAPONBARANZLAUNCHER_H
#define PSO_WEAPON_TITEMWEAPONBARANZLAUNCHER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponBaranzLauncher : public TItemWeapon {
public:
    TItemWeaponBaranzLauncher(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponBaranzLauncher();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void transform_model_node();
    s32 rotation_y; // rotate_matrix_y angle of the barrel, wound back by update_weapon
    s32 spin_speed; // barrel spin added per shot, decays in update_weapon
};

#endif
