#ifndef PSO_PLAYER_TOBJPLAYER_80117DD8_H
#define PSO_PLAYER_TOBJPLAYER_80117DD8_H

#include "types.h"

// --- C functions defined in TObjPlayer_80117DD8.cpp ---
extern "C" {
// 1 when a player of the other sex (class_flags bit 0 or 1) stands on the same floor
// within 20 units of client `idx`.
s32 is_opposite_sex_player_near(u16 idx);
}
// --- end of C functions

#endif
