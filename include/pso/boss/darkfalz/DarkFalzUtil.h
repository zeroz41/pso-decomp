#ifndef PSO_BOSS_DARKFALZ_DARKFALZUTIL_H
#define PSO_BOSS_DARKFALZ_DARKFALZUTIL_H

#include "types.h"

// Takes up to `damage` HP from a player in Dark Falz's arena; returns what was taken.
u32 drain_player_hp(u16 client, u32 damage);
// 1 - (1 - t)^6.
f32 ease_out_pow6(f32 t);
// 1 when the player is in area 14 (Dark Falz's arena) and has no 0x2000800 actor flag.
s32 is_player_in_boss_area(u16 id);
// (1 - cos(wave * half a turn)) / 2.
f32 compute_wave_offset(f32 wave);

#endif
