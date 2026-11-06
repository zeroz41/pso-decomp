#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025B050_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025B050_H

#include "types.h"

extern "C" {
void *TWindowSubStatusDisp__sub_8025B2DC(void *arg0, s16 arg1);
u8 *init_part_scaled__20TWindowSubStatusDispFPvPvi(u8 *arg0, u8 *arg1, s32 arg2);
}
void set_sprite_dimensions(void *p, f32 a, f32 b);
extern "C" {
void set_sprite_uv_bounds(void *p, f32 a, f32 b, f32 c, f32 d);
}
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);
void swap_sprite_u_edges(u8 *arg0);
void swap_sprite_v_edges(u8 *arg0);

#endif
