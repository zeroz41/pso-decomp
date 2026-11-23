#ifndef PSO_UNK_TEXT_800F7DAC_H
#define PSO_UNK_TEXT_800F7DAC_H

#include "types.h"

extern "C" {
void run_task__13TColorOverlayFadeFv(u8 *arg0);
void render__13TDeathTintFadeFv(void);
void run_task__13TScreenFadeInFv(u8 *arg0);
void run_task__13TScreenFadeOutFv(u8 *arg0);
u8 *__dt__13TColorOverlayFadeFv(u8 *arg0, s16 arg1);
void *__dt__13TDeathTintFadeFv(void *arg0, s16 arg1);
void *__dt__13TScreenFadeInFv(void *arg0, s16 arg1);
void *__dt__13TScreenFadeOutFv(void *arg0, s16 arg1);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
}
void step_fade_opacity_increase(u8 *arg0);

#endif
