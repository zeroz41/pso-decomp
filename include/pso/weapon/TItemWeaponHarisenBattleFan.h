#ifndef PSO_WEAPON_TITEMWEAPONHARISENBATTLEFAN_H
#define PSO_WEAPON_TITEMWEAPONHARISENBATTLEFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Harisen Battle Fan weapon class: emit_marker_effects
// flattens the model, update_weapon grows it back. Made by
// TObjPlayer::create_shot_effect_state.
class TItemWeaponHarisenBattleFan : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual ~TItemWeaponHarisenBattleFan();
    TItemWeaponHarisenBattleFan(TObject *parent, u8 *item);
    WeaponVector scale;  // model scale (scale_current_matrix); y is animated
};

#endif
