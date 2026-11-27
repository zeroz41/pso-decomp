#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_ScrollBar.h"
#include "pso/render/TextureState.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/unk/WindowLayoutRecord.h"

#pragma readonly_strings on


// Screen positions and scales of the word-select quad sets (word_select_quad_points), set up by
// load_word_select_data. Names from that use.
extern const NJS_POINT2 window_dd_quad_positions[7] = {
    {72.0f, 199.0f}, {122.0f, 199.0f}, {72.0f, 219.0f}, {122.0f, 219.0f},
    {172.0f, 199.0f}, {172.0f, 219.0f}, {222.0f, 199.0f},
};
extern const f32 window_dd_quad_scales[8] = {16.0f, 16.0f, 16.0f, 16.0f, 20.0f, 20.0f, 16.0f, 0.0f};

const char *TWindowDD_WS_ScrollBar::class_name = "TWindowDD_WS_ScrollBar";

f32 scroll_track_cap_offset;
f32 scroll_track_inset;
f32 scroll_texel_scale;
f32 scroll_arrow_v0;
f32 scroll_arrow_v1;
f32 scroll_up_arrow_u0;
f32 scroll_up_arrow_u1;
f32 scroll_down_arrow_u0;
f32 scroll_down_arrow_u1;
f32 scroll_track_u0;
f32 scroll_track_u1;
f32 scroll_track_top_v0;
f32 scroll_track_top_v1;
f32 scroll_track_bottom_v0;
f32 scroll_track_bottom_v1;
f32 scroll_thumb_v0;
f32 scroll_thumb_v1;

// Filled in by the static initialiser from the scroll_bar_* layout constants.
__declspec(section ".data") NJS_POINT2 scroll_bar_position = {0.0f, 0.0f};
WindowDescriptor scroll_bar_descriptor = {{0.0f, 0.0f}, 0.0f, 0, 3};

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
// Edges of a span around its centre.
// span_start/span_end: the original computes the bar's x edges through
// an inline helper, whose return value schedules differently from a plain `c - t`.
static inline f32 span_start(f32 center, f32 half_extent) { return center - half_extent; }
static inline f32 span_end(f32 center, f32 half_extent) { return center + half_extent; }
void TWindowDD_WS_ScrollBar::render() {
    WindowDrawContext *rect = this->draw_default_entry();
    WindowVertex verts[8];
    f32 quad[8];
    s32 tex;
    s32 i;
    NJS_POINT2 *uv;
    WindowVertex *v;
    f32 z;
    f32 s;
    f32 half;
    f32 t;
    f32 c;
    f32 lo;
    f32 hi;
    f32 d;
    f32 x0;
    f32 step;
    f32 top;
    f32 bot;
    f32 range;
    f32 len;

    this->calc_inner_rect(rect);
    tex = TWindowDD::get_draw_count(hud_texlist);
    reset_window_vertices(verts, word_select_inverse_depth(this->draw_depth, 0.0f), -1);
    uv = word_select_quad_points[6];
    s = rect->scale[1];
    v = verts;
    for (i = 0; i < 8; i++) {
        v->u = uv->x;
        v->v = uv->y;
        uv++;
        v++;
    }

    half = 0.5f * this->frame_size[1];
    t = half * s;
    c = this->frame_position[1] + half;
    lo = c - t;
    hi = c + t;
    if (t < scroll_bar_tile_height) {
        d = (hi - lo) / 3.0f;
    } else {
        d = 16.0f;
    }
    verts[0].y = verts[1].y = lo;
    verts[2].y = verts[3].y = lo + d;
    verts[4].y = verts[5].y = hi - d;
    verts[6].y = verts[7].y = hi;

    half = 0.5f * this->frame_size[0];
    c = this->frame_position[0] + half;
    step = scroll_bar_tile_width * rect->scale[0];
    t = half * rect->scale[0];
    x0 = span_start(c, t);
    v = verts;
    for (i = 0; i < 4; i++) {
        v[0].x = x0;
        v[1].x = x0 + step;
        v += 2;
    }
    half = 0.5f * scroll_arrow_size * rect->scale[0];
    quad[0] = span_start(c, half);
    quad[2] = span_end(c, half);
    draw_window_vertices(verts, 8, tex, 1);

    z = word_select_inverse_depth(this->draw_depth, 0.1f);
    set_texture_list(hud_texlist);
    begin_screen_draw(1);
    set_draw_texture_and_color(0, -1);

    quad[5] = scroll_arrow_v0;
    quad[7] = scroll_arrow_v1;
    quad[4] = scroll_up_arrow_u0;
    quad[6] = scroll_up_arrow_u1;
    quad[1] = scroll_arrow_margin * s + lo;
    quad[3] = s * (scroll_arrow_margin + scroll_arrow_size) + lo;
    draw_textured_quad_at_depth(quad, z);

    quad[4] = scroll_down_arrow_u0;
    quad[6] = scroll_down_arrow_u1;
    quad[1] = hi - s * (scroll_arrow_margin + scroll_arrow_size);
    quad[3] = hi - scroll_arrow_margin * s;
    draw_textured_quad_at_depth(quad, z);

    quad[4] = scroll_track_u0;
    quad[6] = scroll_track_u1;
    quad[5] = scroll_track_top_v0;
    quad[7] = scroll_track_top_v1;
    quad[1] = scroll_track_cap_offset * s + lo;
    quad[3] = s * (14.0f + scroll_track_cap_offset) + lo;
    draw_textured_quad_at_depth(quad, z);

    quad[5] = scroll_track_bottom_v0;
    quad[7] = scroll_track_bottom_v1;
    quad[1] = hi - s * (14.0f + scroll_track_cap_offset);
    quad[3] = hi - scroll_track_cap_offset * s;
    draw_textured_quad_at_depth(quad, z);

    top = lo + scroll_track_inset * s;
    bot = hi - scroll_track_inset * s;
    quad[5] = scroll_thumb_v0;
    quad[7] = scroll_thumb_v1;
    if (this->count <= this->visible_count) {
        quad[1] = top;
        quad[3] = bot;
    } else {
        range = this->inverse_count * (bot - top);
        len = range * this->visible_count;
        if (len < 2.0f) {
            len = 2.0f;
        }
        quad[1] = range * this->first_index + top;
        quad[3] = quad[1] + len;
    }
    draw_textured_quad_at_depth(quad, z);
    end_screen_draw();
}
#pragma pop

// Defer the remaining functions to preserve the original vtable and constructor layout.
#pragma defer_codegen on

// Fills in the bar's texture coordinates and layout, spelled out because the original's static initializer precedes
// this file's deferred functions.
void __sinit_TWindowDD_WS_ScrollBar_cpp() {
    scroll_track_cap_offset = 17.0f + scroll_arrow_margin;
    scroll_track_inset = 14.0f + (17.0f + scroll_arrow_margin);
    scroll_texel_scale = window_dd_texel_scale;
    scroll_arrow_v0 = scroll_arrow_v * scroll_texel_scale;
    scroll_arrow_v1 = scroll_texel_scale * (scroll_arrow_v + scroll_arrow_texture_height);
    scroll_up_arrow_u0 = scroll_arrow_up_u * scroll_texel_scale;
    scroll_up_arrow_u1 = scroll_texel_scale * (scroll_arrow_up_u + scroll_arrow_size);
    scroll_down_arrow_u0 = scroll_arrow_down_u * scroll_texel_scale;
    scroll_down_arrow_u1 = scroll_texel_scale * (scroll_arrow_down_u + scroll_arrow_size);
    scroll_track_u0 = 224.0f * scroll_texel_scale;
    scroll_track_u1 = 238.0f * scroll_texel_scale;
    scroll_track_top_v0 = 58.0f * scroll_texel_scale;
    scroll_track_top_v1 = 72.0f * scroll_texel_scale;
    scroll_track_bottom_v0 = 86.0f * scroll_texel_scale;
    scroll_track_bottom_v1 = 100.0f * scroll_texel_scale;
    scroll_thumb_v0 = 72.0f * scroll_texel_scale;
    scroll_thumb_v1 = 86.0f * scroll_texel_scale;
    scroll_bar_position.x = scroll_bar_x;
    scroll_bar_position.y = scroll_bar_y;
    scroll_bar_descriptor.size[0] = scroll_bar_width;
    scroll_bar_descriptor.size[1] = scroll_bar_height;
    scroll_bar_descriptor.sort_depth = scroll_bar_depth;
}

__declspec(section ".ctors") static void *const scroll_bar_global_initializer = (void *)__sinit_TWindowDD_WS_ScrollBar_cpp;

TWindowDD_WS_ScrollBar *TWindowDD_WS_ScrollBar::create() { return new TWindowDD_WS_ScrollBar; }

TWindowDD_WS_ScrollBar::TWindowDD_WS_ScrollBar()
    : TWindowBase((u8 *)&scroll_bar_descriptor, 4, (u8 *)&scroll_bar_position) {
    m_name = TWindowDD_WS_ScrollBar::class_name;
    count = 6.0f;
    visible_count = 6.0f;
    first_index = 0.0f;
    open_tick = 0x01000000;
}

TWindowDD_WS_ScrollBar::~TWindowDD_WS_ScrollBar() {}

void TWindowDD_WS_ScrollBar::set_range(s32 total, s32 visible) {
    count = total;
    visible_count = visible;
    inverse_count = 1.0f / count;
}

void TWindowDD_WS_ScrollBar::set_first_index(s32 index) {
    first_index = index;
}

void TWindowDD_WS_ScrollBar::run_task() {
    update_window();
    update_fade();
}
