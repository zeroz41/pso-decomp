#ifndef PSO_WEAPON_TUNK_804A4D70_H
#define PSO_WEAPON_TUNK_804A4D70_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The partisan weapon class (vtable 0x804A4D70, partisan_weapon_vtable
// before; written as TItemWeaponPartisan): item index 6 spends meseta for
// its special and spins rotation with the owner's meseta, index 5 slides
// and scales its model nodes. Made by create_partisan_weapon.
class TUnk_804A4D70 : public TItemWeapon {
public:
    virtual ~TUnk_804A4D70();
    virtual void emit_marker_effects();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    TUnk_804A4D70(TObject *parent, u8 *item);
    void apply_scale_if_active(f32);
    s32 rotation;                    // rotate_matrix_z angle (index 6)
    WeaponVector scale;              // node 3 (index 5)
    WeaponVector first_translation;  // node 1 (index 5)
    WeaponVector second_translation; // node 2 (index 5)
};

u8 *create_partisan_weapon(u8 *item);

#endif
