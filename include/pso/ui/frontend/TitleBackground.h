#ifndef PSO_UI_FRONTEND_TITLEBACKGROUND_H
#define PSO_UI_FRONTEND_TITLEBACKGROUND_H

#include "types.h"

extern "C" {
void draw_title_background_quads(void *texture_list, s32 tex_base, s32 color, s32 mode, f32 depth);
}

void draw_title_background_layer(void *texture_list, int tex_base, int color, f32 depth);
void render_logo_with_default(void *texture_list, int tex_base, int color, f32 depth);

#endif
