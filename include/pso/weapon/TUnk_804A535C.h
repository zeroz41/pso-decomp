#ifndef PSO_WEAPON_TUNK_804A535C_H
#define PSO_WEAPON_TUNK_804A535C_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/data/FlagWord.h"

// Made by TObjPlayer::create_trade_action_state; its shots are TUnk_804A5340
// (rocket_punch_create_shot).
class TUnk_804A535C : public TItemWeapon {
public:
    TUnk_804A535C(TObject *parent, u8 *item);
    virtual ~TUnk_804A535C();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    // The model a shot draws: second_model while punch_flags 4 is set.
    NJS_OBJECT *fn_8012C9D8();

    FlagWord punch_flags;     // 1 drawing the first fist, 2 a fist is out, 4 the second shot
    Vec shot_origins[2];      // the two fists' joint 1, where launch_shot starts
};

LAYOUT_ASSERT(TUnk_804A535C_size, sizeof(TUnk_804A535C) == 0x214);

// Clears punch_flags 2 when a fist comes back (TItemAttacker::spawn_item_timer).
void rocket_punch_return_timer(uaddr weapon);

#endif
