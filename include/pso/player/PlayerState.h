#ifndef PSO_PLAYER_PLAYERSTATE_H
#define PSO_PLAYER_PLAYERSTATE_H

#include "types.h"

struct Vec;

extern "C" {
void set_equip_slot_entry(saddr slots, s32 slot, s32 item);
void *TObjPlayer__sub_801BFAD4(void *timer, s16 flags);
}

// Empties the 13 equip slots.
void clear_equip_slots(s32 *slots);
Vec *get_marker_position(Vec *position);
void clear_marker_position(Vec *position);
s32 is_count_positive(s32 *count);

#endif
