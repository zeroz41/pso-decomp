#ifndef PSO_RENDER_SCREENPRIMITIVEDRAW_H
#define PSO_RENDER_SCREENPRIMITIVEDRAW_H

#include "types.h"

// Vertices given in screen space with w: they are drawn at (x, y, 1) / -w
// through the matrix load_screen_space_matrix loads. color is 0xAARRGGBB.
struct ScreenColorVertex {
    f32 x;
    f32 y;
    f32 w;
    u32 color;
};

struct ScreenTexturedVertex {
    f32 x;
    f32 y;
    f32 w;
    f32 s;
    f32 t;
    u32 color;
};

// ScreenSpaceMatrix.cpp
void load_screen_space_matrix();
void load_camera_view_matrix();

// ScreenPrimitiveDraw.cpp: GX state for colour-only (position, colour) and
// textured (position, colour, texture coordinate) primitives, opaque or blended.
void setup_opaque_color_draw();
void setup_blended_color_draw();
void setup_opaque_textured_draw();
void setup_blended_textured_draw();
void end_primitive_draw();
// Loads the current render context's texture into GX texture map 0.
void load_context_texture_obj();
void setup_color_vertex_format();
void setup_textured_vertex_format();
void setup_color_channels(int count);
// GX blend off (opaque) or on with the current render context's blend factors.
void apply_opaque_blend_mode();
void apply_blended_blend_mode();
void set_tev_passclr();
// 1: modulate the texture by the colour; 2: also add the second colour channel.
void set_tev_stage_mode(s32 count);
void clear_tex_gens();
void setup_tex_gen();
// Draws count vertices as a triangle strip, blended when blended != 0.
void draw_screen_color_strip(ScreenColorVertex *vertices, s32 count, s32 blended);

// TexturedVertexDraw.cpp: the same with the current render context's texture.
void draw_screen_textured_strip(ScreenTexturedVertex *vertices, s32 count, s32 blended);

#endif
