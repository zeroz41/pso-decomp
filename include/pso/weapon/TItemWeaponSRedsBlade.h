#ifndef PSO_WEAPON_TITEMWEAPONSREDSBLADE_H
#define PSO_WEAPON_TITEMWEAPONSREDSBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The S-Red's Blade weapon class (old names
// TObjPlayer::cast_shifta_deband, s_red_blade_equip_rolls,
// s_red_blade_turn_node, TObjPlayer::init_variant_a): emit_marker_effects
// casts Deband or Shifta on the owner, update_idle/update_attack swing
// rotation_x, the model hook (slot 60) turns model node 1 by it. Made by
// TItemWeaponSRedsBlade::create.
class TItemWeaponSRedsBlade : public TItemWeapon {
public:
    virtual void emit_marker_effects();
    virtual void update_idle();
    virtual void update_attack();
    virtual void on_equipped();
    virtual void transform_model_node();
    TItemWeaponSRedsBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRedsBlade();
    s32 rotation_x;  // rotate_matrix_x angle of the model hook
};

#endif
