#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE3_800524E8_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE3_800524E8_H

#include "types.h"

extern "C" {
// 1 - (1 - t)^6.
f32 ease_out_pow6(f32 t);
// 1 when the player is in area 14 (Dark Falz's arena) and has no 0x2000800 actor flag.
s32 is_player_in_boss_area(u16 id);
}

#endif
