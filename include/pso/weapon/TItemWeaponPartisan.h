#ifndef PSO_WEAPON_TITEMWEAPONPARTISAN_H
#define PSO_WEAPON_TITEMWEAPONPARTISAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The partisan weapon class (partisan_weapon_vtable
// before; written as TItemWeaponPartisan): item index 6 spends meseta for
// its special and spins rotation with the owner's meseta, index 5 slides
// and scales its model nodes. Made by TItemWeaponPartisan::create.
class TItemWeaponPartisan : public TItemWeapon {
public:
    virtual ~TItemWeaponPartisan();
    virtual void emit_marker_effects();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    TItemWeaponPartisan(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    void apply_scale_if_active(f32);
    s32 rotation;                    // rotate_matrix_z angle (index 6)
    WeaponVector scale;              // node 3 (index 5)
    WeaponVector first_translation;  // node 1 (index 5)
    WeaponVector second_translation; // node 2 (index 5)
};

#endif
