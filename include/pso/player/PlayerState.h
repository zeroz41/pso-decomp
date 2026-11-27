#ifndef PSO_PLAYER_PLAYERSTATE_H
#define PSO_PLAYER_PLAYERSTATE_H

#include "types.h"
#include "dolphin/mtx/GeoTypes.h"

// TObjPlayer::marker_position: the point above the head (calc_marker_position) where the
// lobby marker is drawn; starts at the origin.
struct PlayerMarkerPosition : Vec {
    PlayerMarkerPosition();
};

// TObjPlayer::equipped_items: the item held in each of the 13 equip slots.
struct EquippedItems {
    void *items[13];

    EquippedItems();
    // Empties the 13 equip slots.
    void clear();
};

void set_equip_slot_entry(void **slots, s32 slot, void *item);

Vec *get_marker_position(Vec *position);
s32 is_count_positive(s32 *count);

#endif
