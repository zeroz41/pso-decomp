#ifndef PSO_PLAYER_TUNK_8012AF00_H
#define PSO_PLAYER_TUNK_8012AF00_H

#include "types.h"

// One captured lock-on target: the target's entity id and the collider it is locked on.
struct TUnk_8012AF50 {
    u16 uid;
    s16 collider_index;

    void fn_8012AF80();
    s16 get_captured_target_collider_index();
    u16 get_uid();
};

// The lock-on target list a player's attack state keeps at +0x30 and the Heaven Punisher copies.
struct TUnk_8012AF00 {
    s32 count;
    TUnk_8012AF50 entries[10];

    void clear_lockon_list();
    TUnk_8012AF50 *get_captured_target_entry(s32 i);
    s32 get_captured_target_count();
};

extern "C" {
// The list's and the entry's constructors. They stay flat until the objects that build a list in place
// (TObjPlayer::init at +0x30, TObjPlayer::build_packet_header at +0x4) have real constructors.
TUnk_8012AF00 *TObjPlayer__sub_8012AF00(TUnk_8012AF00 *self);
TUnk_8012AF50 *TObjPlayer__sub_8012AF50(TUnk_8012AF50 *self);
}

#endif
