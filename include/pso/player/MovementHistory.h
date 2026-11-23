#ifndef PSO_PLAYER_MOVEMENTHISTORY_H
#define PSO_PLAYER_MOVEMENTHISTORY_H

#include "types.h"

// TObjPlayer + 0x6AC: a ring of the player's last 16 ground positions. update_position_history
// steps index and stores position.x and position.z through set_position_history_entry.
struct MovementHistoryEntry {
    f32 x;
    f32 z;
};

struct MovementHistory {
    s32 index;
    MovementHistoryEntry entries[16];
};

extern "C" void clear_movement_history(MovementHistory *history);

#endif
