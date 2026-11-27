#ifndef PSO_UI_FRONTEND_TITLEBACKGROUND_H
#define PSO_UI_FRONTEND_TITLEBACKGROUND_H

#include "types.h"

struct NJS_TEXLIST;

void draw_title_background_quads(NJS_TEXLIST *texture_list, s32 tex_base, s32 color, s32 mode, f32 depth);

void draw_title_background_layer(NJS_TEXLIST *texture_list, int tex_base, int color, f32 depth);
void render_logo_with_default(NJS_TEXLIST *texture_list, int tex_base, int color, f32 depth);

struct TitleBackgroundTile {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
    s32 tex;
};

#endif
