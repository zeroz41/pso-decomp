#ifndef PSO_ITEM_TUNK_804A2E80_H
#define PSO_ITEM_TUNK_804A2E80_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

// The Harisen Battle Fan weapon class (vtable 0x804A2E80): emit_marker_effects
// flattens the model, update_weapon grows it back. Made by
// TObjPlayer::create_shot_effect_state.
class TUnk_804A2E80 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual ~TUnk_804A2E80();
    TUnk_804A2E80(TObject *parent, u8 *item);
    WeaponVector scale;  // model scale (scale_current_matrix); y is animated
};

#endif
