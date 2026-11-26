#ifndef PSO_PLAYER_CAPTUREDTARGETLIST_H
#define PSO_PLAYER_CAPTUREDTARGETLIST_H

#include "types.h"

// One captured lock-on target: the target's entity id and the collider it is locked on.
struct CapturedTarget {
    u16 uid;
    s16 collider_index;

    // Builds the entry cleared.
    CapturedTarget();
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

    // Builds the entries, then clears the list.
    CapturedTargetList();
    void clear_lockon_list();
    void set_count(s32 n);
    CapturedTarget *get_captured_target_entry(s32 i);
    s32 get_captured_target_count();
    // Receive-side swap: the count first, so the loop reads it native.
    void bswap_received();
    // Send-side swap: the entries while the count is native, then the count.
    void bswap_for_send();
};

#endif
