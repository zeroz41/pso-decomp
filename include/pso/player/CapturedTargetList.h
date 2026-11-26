#ifndef PSO_PLAYER_CAPTUREDTARGETLIST_H
#define PSO_PLAYER_CAPTUREDTARGETLIST_H

#include "types.h"
#include "pso/network/protocol/protocol_types.h"

struct G_AttackFinished_Header_6x46;

// One captured lock-on target: the target's entity id and the collider it is locked on.
struct CapturedTarget {
    u16 uid;
    s16 collider_index;

    void clear();
    void set_uid(u16 id);
    void set_collider_index(s16 index);
    s16 get_captured_target_collider_index();
    u16 get_uid();
    void bswap();
};

// The lock-on target list a player's attack state keeps at +0x30 and the Heaven Punisher copies.
struct CapturedTargetList {
    s32 count;
    CapturedTarget entries[10];

    void clear_lockon_list();
    void set_count(s32 n);
    CapturedTarget *get_captured_target_entry(s32 i);
    s32 get_captured_target_count();
    // For a list just received (the count first, then the entries by the swapped count).
    void bswap_received();
    // For a list about to be sent (the entries by the native count, then the count).
    void bswap_for_send();
};

// 6x46: a player's attack finished on up to ten captured targets.
struct G_AttackFinished_6x46 {
    G_AttackFinished_6x46();
    G_AttackFinished_6x46 &operator=(const G_AttackFinished_Header_6x46 &src);

    G_ClientIDHeader header;
    CapturedTargetList targets;

    u8 get_size();
    void bswap_received();
    void bswap_for_send();
    void send();
};

extern "C" {
// The list's and the entry's constructors. They stay flat until the objects that build a list in place
// (PlayerAttackController::init at +0x30, TObjPlayer::build_packet_header at +0x4) have real constructors.
CapturedTargetList *TObjPlayer__sub_8012AF00(CapturedTargetList *self);
CapturedTarget *TObjPlayer__sub_8012AF50(CapturedTarget *self);
}

#endif
