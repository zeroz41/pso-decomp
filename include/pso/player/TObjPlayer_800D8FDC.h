#ifndef PSO_PLAYER_TOBJPLAYER_800D8FDC_H
#define PSO_PLAYER_TOBJPLAYER_800D8FDC_H

#include "types.h"

extern "C" {
void TObjPlayer__sub_800D9290(s32 point, s32 delay);
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
void TObjPlayer__sub_800D93C4(s32 point, s32 delay);
void TObjPlayer__sub_800D93F0(s32 point, s32 selector, s32 delay, f32 farg0);
void *__dt__17MaterialColorFadeFv(void *arg0, s16 arg1);
void create_dead_spot__10TObjPlayerFiiif(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
}
void load_corpse_mark_resource(void);
extern "C" {
void spawn_dead_spot__10TObjPlayerFlllf(s32 point, s32 selector, s32 delay, f32 farg0);
void spawn_dead_spot_scale15(s32 point, s32 delay);
}
void spawn_landing_dead_spot(s32 point, s32 delay);
// Dead-stripped (no code in the DOL); names inferred, see TBoss3Volopt_800D8ACC.cpp.
void spawn_corner_dead_spot_scale2_5(s32 point, s32 delay);
void spawn_corner_dead_spot_scale25(s32 point, s32 delay);

#include <dolphin/mtx.h>
extern "C" void fn_800D911C(Vec *position);

#endif
