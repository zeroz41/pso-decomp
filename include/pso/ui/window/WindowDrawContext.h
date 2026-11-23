#ifndef PSO_UI_WINDOW_WINDOWDRAWCONTEXT_H
#define PSO_UI_WINDOW_WINDOWDRAWCONTEXT_H

#include "types.h"
#include <stddef.h>
#include "pso/system/NinjaTypes.h"

// A screen rectangle with its texture coordinates, as the window draw code builds them before clipping.
struct TexturedQuad { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

// The rectangle, scale and depth a window is drawn with (TWindowBase::draw_default_entry returns one).
struct WindowDrawContext
{
    WindowDrawContext();
    ~WindowDrawContext();
    WindowDrawContext *init_layout(f32 *pos, f32 *size, f32 *scale, u32 flags, f32 depth);
    static const NJS_POINT2 *get_viewport_offset(s32 i);
    static WindowDrawContext *get_or_create_instance();
    void scale_point_about_pivot(f32 *q);
    void transform_quad(TexturedQuad *quad);
    void apply_closing_stretch(int ticks);
    void set_open_tick(s32 tick);
    void set_bounds(f32 a, f32 b, f32 c, f32 d);
    void shrink_clip_right();
    void animate_scale();
    s32 is_point_in_bounds(TexturedQuad *quad);
    s32 clip_textured_quad(TexturedQuad *quad);
    s32 clip_and_transform_quad(TexturedQuad *quad);
    static void adjust_pos_for_split_screen(NJS_POINT2 *pos, s32 view);
    static WindowDrawContext *open_singleton(f32 *pos, f32 *size, f32 *scale, f32 depth, u32 flags);
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 inner_x;
    f32 inner_y;
    f32 inner_w;
    f32 inner_h;
    f32 pivot[2];
    f32 scale[2];
    s32 open_tick;
    u32 color;
    f32 depth;
    f32 clip_x0;
    f32 clip_y0;
    f32 clip_x1;
    f32 clip_y1;
};

// The one context every window draws through (name inferred; TWindowCtrlMain creates and frees it).
extern WindowDrawContext *shared_window_draw_context;

LAYOUT_ASSERT(TexturedQuad_size, sizeof(TexturedQuad) == 0x20);
LAYOUT_ASSERT(TexturedQuad_uv_offset, offsetof(TexturedQuad, u0) == 0x10);
LAYOUT_ASSERT(WindowDrawContext_size, sizeof(WindowDrawContext) == 0x4C);
LAYOUT_ASSERT(WindowDrawContext_inner_height_offset, offsetof(WindowDrawContext, inner_h) == 0x1C);
LAYOUT_ASSERT(WindowDrawContext_color_offset, offsetof(WindowDrawContext, color) == 0x34);
LAYOUT_ASSERT(WindowDrawContext_depth_offset, offsetof(WindowDrawContext, depth) == 0x38);
LAYOUT_ASSERT(WindowDrawContext_clip_y1_offset, offsetof(WindowDrawContext, clip_y1) == 0x48);

#endif
