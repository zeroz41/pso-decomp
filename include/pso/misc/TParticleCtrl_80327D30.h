#ifndef PSO_MISC_TPARTICLECTRL_80327D30_H
#define PSO_MISC_TPARTICLECTRL_80327D30_H

#include "types.h"

extern "C" {
void *__dt__13TUnk_804ED598Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804ED5B0Fv(void *arg0, s16 arg1);
}
u8 *create_telepipe_marker(u8 *arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, f32 farg0, f32 farg1);
void play_indirect_effect_recipe(u8 arg0, u16 sampler, s32 second);
// Makes sure an indirect (TEV distortion) effect controller of this kind exists.
void request_indirect_effect(s32 kind);
// Turns the indirect stage off again (stage 1 when second_stage, else 0).
void reset_indirect_tev(s32 second_stage);

#endif
