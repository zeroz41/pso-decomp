#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025B050_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025B050_H

#include "types.h"

class WindowSpritePart;

extern "C" {
void *TWindowSubStatusDisp__sub_8025B2DC(void *arg0, s16 arg1);
}
void set_sprite_dimensions(WindowSpritePart *sprite, f32 a, f32 b);
void set_sprite_uv_bounds(WindowSpritePart *sprite, f32 a, f32 b, f32 c, f32 d);
void set_sprite_uv_from_pixels(WindowSpritePart *sprite, f32 x, f32 y);
void swap_sprite_u_edges(WindowSpritePart *sprite);
void swap_sprite_v_edges(WindowSpritePart *sprite);

#endif
