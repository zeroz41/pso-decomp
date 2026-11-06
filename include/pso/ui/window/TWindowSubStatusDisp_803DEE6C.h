#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_803DEE6C_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_803DEE6C_H

#include "types.h"

extern "C" {
void DVDConvertEntrynumToPath(f32 *q);
u32 TLobby__sub_803DF1CC(void);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
}
void set_constant_material_color(u32 x);
extern "C" {
void set_draw_texture_and_color(s32 idx, s32 arg1);
}

#endif
