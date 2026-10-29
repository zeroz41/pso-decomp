#ifndef PSO_UI_TOBJDFJISIN_H
#define PSO_UI_TOBJDFJISIN_H

#include "types.h"

extern "C" {
void *TObjDFBeamCursor__ct(void *arg0, void *arg1, void *arg2);
u8 *TObjDFHorming__ct(u8 *arg0, s32 parent, s32 arg2, u16 arg3);
u8 *TObjDFJisin__ct(u8 *arg0, u8 *arg1, s32 arg2);
u8 *TObjDFRecBall__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
u8 *TObjDFTenchuFuru__ct(u8 *arg0, u8 *arg1, u8 *arg2);
void TObjDFTenchuFuru__sub_80051A7C(void);
void *__dt__13TObjDFRecoverFv(void *arg0, s16 arg1);
void *create__13TObjDFRecBallFPvPvPv(void *arg0, void *arg1, void *arg2);
void *create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1);
void fn_spawn_particle_f3_with_flags(s32 arg0, s32 arg1);
int queue_destruction__13TObjDFHormingFPv(void *p);
void run_task__13TObjDFHormingFv(u8 *arg0);
void run_task__16TObjDFBeamCursorFv(u8 *arg0);
}

#endif
