#ifndef PSO_WEAPON_TUNK_804ECFB0_H
#define PSO_WEAPON_TUNK_804ECFB0_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Built by dark_bridge_create. While the owner's TP drops, half of the loss
// is taken from their HP and given back as TP (update_weapon).
class TUnk_804ECFB0 : public TItemWeapon {
public:
    TUnk_804ECFB0(TObject *parent, u8 *item);
    virtual ~TUnk_804ECFB0();
    virtual void update_weapon();
    virtual void vfunc_57();
    virtual void vfunc_58();
    s32 pad_1f8;
    s16 owner_tp;  // the owner's TP last frame (get_actor_tp)
    u8 pad_1fe[0x2];
};

u8 *dark_bridge_create(u8 *arg0);
// The paralysis TUnk_804A0568 timer's constructor (weak copy, first used by TUnk_804ECFB0::vfunc_57).
u8 *paralysis_curse_timer_ct(u8 *event, s32 effect_objects, u16 owner_client, s32 frames, f32 rate);

#endif
