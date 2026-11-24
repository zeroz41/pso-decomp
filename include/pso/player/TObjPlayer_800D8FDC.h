#ifndef PSO_PLAYER_TOBJPLAYER_800D8FDC_H
#define PSO_PLAYER_TOBJPLAYER_800D8FDC_H

#include "types.h"
#include <dolphin/mtx.h>

extern "C" {
void TObjPlayer__sub_800D9290(const Vec *point, s32 delay);
void TObjPlayer__sub_800D92BC(const Vec *point, s32 delay);
void TObjPlayer__sub_800D93C4(const Vec *point, s32 delay);
void TObjPlayer__sub_800D93F0(const Vec *point, s32 selector, s32 delay, f32 maxScale);
void *__dt__17MaterialColorFadeFv(void *arg0, s16 arg1);
}
void load_corpse_mark_resource(void);
extern "C" {
void spawn_dead_spot_scale15(const Vec *point, s32 delay);
}
void spawn_landing_dead_spot(const Vec *point, s32 delay);
// Dead-stripped (no code in the DOL); names inferred, see TBoss3Volopt_800D8ACC.cpp.
void spawn_corner_dead_spot_scale2_5(const Vec *point, s32 delay);
void spawn_corner_dead_spot_scale25(const Vec *point, s32 delay);

extern "C" void fn_800D911C(Vec *position);

// Particle 0xF8 at pos for duration frames, with a TUnk_804949F4 of radius on it.
void create_dead_spot(Vec *pos, s32 duration, f32 radius);
// Particle 0xF8 at pos for duration frames.
void spawn_effect_f8(Vec *pos, s32 duration);
// create_dead_spot with particle 0xE4.
void create_dead_spot_e4(Vec *pos, s32 duration, f32 radius);
// Particle `particle` at pos for duration frames, with a TUnk_804949D8 of radius on it.
void create_dead_spot(Vec *pos, s32 particle, s32 duration, f32 radius);

#endif
