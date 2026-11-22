#ifndef PSO_BOSS_DARKFALZ_TOBJDFJISIN_H
#define PSO_BOSS_DARKFALZ_TOBJDFJISIN_H

#include "types.h"

extern "C" {
void TObjDFTenchuFuru__sub_80051A7C(void);
void *create__13TObjDFRecBallFPvPvPv(void *parent, void *position, void *arg2);
void *create__16TObjDFBeamCursorFPvPv(void *parent, void *arg1);
void fn_spawn_particle_f3_with_flags(s32 arg0, saddr arg1);
int queue_destruction__13TObjDFHormingFPv(void *p);
void run_task__13TObjDFHormingFv(u8 *self);
}

// Draws a player-like model set (body, two attached parts, hair) at alpha; used by TBoss6Type2.
void boss6type2_draw_models(s32 arg0, s32 arg1, s32 arg2, uaddr arg3, uaddr arg4, u32 model, uaddr arg6, saddr appearance, f32 alpha);

#endif
