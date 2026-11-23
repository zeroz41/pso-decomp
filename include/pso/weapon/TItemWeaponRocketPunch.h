#ifndef PSO_WEAPON_TITEMWEAPONROCKETPUNCH_H
#define PSO_WEAPON_TITEMWEAPONROCKETPUNCH_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/data/FlagWord.h"

// The ROCKET PUNCH, weapon type 0x47 (weapon_factory_table: TObjPlayer::create_trade_action_state).
// Each attack fires both fists as TItemShootRocketPunch shots (rocket_punch_create_shot).
class TItemWeaponRocketPunch : public TItemWeapon {
public:
    TItemWeaponRocketPunch(TObject *parent, u8 *item);
    virtual ~TItemWeaponRocketPunch();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    // The model a shot draws: second_model while punch_flags 4 is set.
    NJS_OBJECT *get_shot_model();

    FlagWord punch_flags;     // 1 drawing the first fist, 2 a fist is out, 4 the second shot
    Vec shot_origins[2];      // the two fists' joint 1, where launch_shot starts
};

LAYOUT_ASSERT(TItemWeaponRocketPunch_size, sizeof(TItemWeaponRocketPunch) == 0x214);

// Clears punch_flags 2 when a fist comes back (TItemAttacker::spawn_item_timer).
void rocket_punch_return_timer(uaddr weapon);

#endif
