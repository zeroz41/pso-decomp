#ifndef PSO_PLAYER_TUNK_804A5F18_H
#define PSO_PLAYER_TUNK_804A5F18_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The S-Red's Blade weapon class (vtable 0x804A5F18; old names
// TObjPlayer::cast_shifta_deband, s_red_blade_equip_rolls,
// s_red_blade_turn_node, TObjPlayer::init_variant_a): emit_marker_effects
// casts Deband or Shifta on the owner, update_idle/update_attack swing
// rotation_x, the model hook (slot 60) turns model node 1 by it. Made by
// TObjPlayer::create_state_variant_a.
class TUnk_804A5F18 : public TItemWeapon {
public:
    virtual void emit_marker_effects();
    virtual void update_idle();
    virtual void update_attack();
    virtual void vfunc_57();
    virtual void vfunc_60();
    TUnk_804A5F18(TObject *parent, u8 *item);
    virtual ~TUnk_804A5F18();
    s32 rotation_x;  // rotate_matrix_x angle of the model hook
};

#endif
