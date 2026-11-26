#include "pso/render/GinjaTexture.h"
#include "pso/math/FloatRound.h"
#include "pso/render/GinjaTextureHeader.h"
#include "pso/render/ColorLineList.h"
#include <stdlib.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/TLanguage.h"
#include "pso/unk/text_803DAFA8.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/GinjaTexture.h"
#include "pso/ui/window/WindowTextEntry.h"


struct UV_8024503C { f32 u, v; };

struct UVPair_8024503C { UV_8024503C e[2]; };

const char *TWindowBase::class_name = "TWindowBase";
static const UVPair_8024503C selection_bar_texture_coordinates = {{{151.0f, 57.0f}, {151.0f, 76.0f}}};

void reset_line_width(void);
void set_line_width(int a0);
void draw_window_scanline(TWindowBase *window, s32 row, WindowDrawContext *r, f32 len);
extern "C" {






extern int area_total;


int get_area_total(void) {  return area_total; }

char *WindowTextEntry::get_text() { return this->text; }

f32 TWindowBase::get_transition_progress() {
    f32 v = get_close_progress();
    if (v < 1.0f) {
        return v;
    }
    return get_normalized_progress();
}

f32 TWindowBase::get_close_progress() {
    s16 close_ticks;

    close_ticks = closing_tick;
    if (close_ticks != 0) {
        return 1.0f - ((f32) close_ticks / 4.5f);
    }
    return 1.0f;
}

#pragma push
#pragma opt_common_subs off
f32 TWindowBase::get_normalized_progress() {
    s32 progress_ticks;
    if (window_flags & 0x2000) {
        return 1.0f;
    }
    progress_ticks = open_tick;
    if ((f32) progress_ticks >= 7.5f) {
        return 1.0f;
    }
    return (f32) progress_ticks / 7.5f;
}
#pragma pop

void TWindowBase::reparent_to_main_ctrl() {
    set_parent(reinterpret_cast<TObject *>(get_main_window_root()));
}

void TWindowBase::save_position() {
    frame_position[0] = target_position[0];
    frame_position[1] = target_position[1];
    frame_size[0] = target_size[0];
    frame_size[1] = target_size[1];
}

void TWindowBase::slide_to(f32 *pos) {
    copy_vec2(target_position, pos);
    tween_ticks = 3;
}

void TWindowBase::set_size(f32 *size) {
    copy_vec2(target_size, size);
    copy_vec2(frame_size, target_size);
}

void TWindowBase::snap_to(f32 *pos) {
    copy_vec2(target_position, pos);
    copy_vec2(frame_position, target_position);
}

#pragma push
#pragma fp_contract on
s32 TWindowBase::is_open_and_unblocked() {
    if (this->is_closed() != 0) {
        return 0;
    }
    return (s32) ((u32) __cntlzw(this->window_flags & 4) >> 5);
}
#pragma pop

}
void hide_window(u8 *object) {
    TWindowBase *window = (TWindowBase *)object;
    window->window_flags = (s32) (window->window_flags & 0xFFFFFFF8);
    window->closing_tick = 0;
    ((TObject *)object)->disallow_rendering();
}

void TWindowBase::close() {
    request_close();
    window_flags |= 0x10;
}

void TWindowBase::request_close() {
    s32 flags = window_flags;
    if (!(flags & 1)) {
        window_flags = flags & ~4;
        return;
    }
    if (flags & 2) {
        window_flags = flags | 4;
        return;
    }
    if (!(flags & 0x20)) {
        play_sound_effect(0x53704, 0, 0, 0);
    }
    window_flags &= ~1;
    window_flags |= 2;
}

s32 TWindowBase::is_window_reveal_complete() {
    return (f32) this->open_tick >= 7.5f;
}
NJS_TEXLIST *hud_texlist;
u16 window_ui_theme_index;
s16 window_scanline_timer;
void window_request_refresh(u8 *help) {
    TWindowBase *window = (TWindowBase *)help;
    if (!((f32) window->open_tick >= 7.5f)) {
        window->open_tick = 7;
    }
}

void window_request_show(void *object) {
    TWindowBase *window = (TWindowBase *)object;
    s32 state_flags;

    state_flags = window->window_flags;
    if (state_flags & 1) {
        window->window_flags = (s32) (state_flags & 0xFFFFFFFB);
        return;
    }
    if (state_flags & 2) {
        window->window_flags = (s32) (state_flags | 4);
        return;
    }
    if (TWindowSubStatusDisp::get_card_window_scale(window->client_index) > 0.0f) {
        window->open_tick = 0;
    }
    window->window_flags = (s32) (window->window_flags | 3);
    if (!(window->window_flags & 0x20)) {
        play_sound_effect(0x53703, 0, 0, 0);
    }
    ((TObject *)object)->allow_rendering();
}

WindowDrawContext *TWindowBase::setup_window_draw_context(f32 *scale) {
    WindowDrawContext *context;
    s32 tick;
    context = WindowDrawContext::open_singleton(frame_position, frame_size, scale, draw_depth, window_flags);
    if (window_flags & 0x40) {
        context->animate_scale();
    }
    if (window_flags & 0x80) {
        context->shrink_clip_right();
    }
    if (window_flags & 8) {
        context->set_bounds(0.0f, 0.0f, 640.0f, 480.0f);
    }
    tick = open_tick;
    if (!(window_flags & 0x2000)) {
        tick = (s32) ((f32) tick - 7.5f);
    }
    context->set_open_tick(tick);
    context->apply_closing_stretch(closing_tick);
    return context;
}

WindowDrawContext *TWindowBase::draw_default_entry() {
    return setup_window_draw_context((f32 *)get_one_vec2());
}

void TWindowBase::set_depth(f32 depth) {
    TWindowBase::bring_to_front();
    this->sort_depth = depth;
    resort_window_order();
}

s32 is_balloon_overlapping(const TWindowFukidasi *balloon, const f32 *position, const f32 *size) {
    f32 y;
    f32 top;
    f32 x = position[0];
    if (x >= balloon->target_position[0] + balloon->target_size[0]) {
        return 0;
    }
    if (x + size[0] <= balloon->frame_position[0]) {
        return 0;
    }
    top = balloon->target_position[1];
    y = position[1];
    if (y >= top + balloon->target_size[1]) {
        return 0;
    }
    if (y + size[1] <= top) {
        return 0;
    }
    return 1;
}

TWindowFukidasi *TWindowFukidasi::find_overlapping_balloon(const f32 *position, const f32 *size, TWindowFukidasi *first) {
    if (TWindowFukidasi__sub_8024695C(this) == 0) {
        return NULL;
    }
    if (is_bit10_set() != 0) {
        return NULL;
    }
    if (this->is_open_and_unblocked() == 0) {
        return NULL;
    }
    for (TWindowFukidasi *p = first; p != NULL; p = static_cast<TWindowFukidasi *>(p->m_next)) {
        if (TWindowFukidasi__sub_8024695C(p) != 0 && p->is_bit10_set() == 0 &&
            p->is_open_and_unblocked() != 0 && p != this &&
            (get_visible_flag() == 0 || p->get_visible_flag() == 0) &&
            is_balloon_overlapping(p, position, size)) {
            return p;
        }
    }
    return NULL;
}

TWindowFukidasi *TWindowFukidasi::find_balloon_overlap_for(TWindowFukidasi *first) {
    return find_overlapping_balloon(target_position, target_size, first);
}

void TWindowBase::init_window(u8 *descriptor, u8 *parent, s16 client) {
    m_name = class_name;
    copy_vec2(target_position, parent);
    copy_vec2(target_size, descriptor);
    save_position();
    sort_depth = ((WindowDescriptor *)descriptor)->sort_depth;
    draw_depth = -10000.0f;
    window_flags = ((WindowDescriptor *)descriptor)->flags;
    resort_window_order();
    tween_ticks = 0;
    client_index = client;
    init_window_layout_entries(&entry_list, ((WindowDescriptor *)descriptor)->layout, (client_index));
    open_tick = 0;
    closing_tick = 0;
    if (!(window_flags & 1) && !(window_flags & 2)) {
        disallow_rendering();
    }
    if ((window_flags & 1) && (window_flags & 2) && !(window_flags & 0x20)) {
        ((s32 (*)(int, int, int, int))play_sound_effect)(0x53703, 0, 0, 0);
    }
    if (TWindowSubStatusDisp::get_card_window_scale((int) (client_index)) <= 0.0f) {
        open_tick = 0x01000000;
    }
}

void draw_selection_bar(WindowDrawContext *context, TWindowLayoutRect *entry, s32 active) {
    UVPair_8024503C uv = selection_bar_texture_coordinates;
    UV_8024503C *p;
    TexturedQuad q;
    f32 x1;
    f32 x;
    f32 y;
    f32 z;
    f32 t;
    f32 u;
    if (context->open_tick < 0) {
        return;
    }
    p = &uv.e[0];
    if (active != 0) {
        p = &uv.e[1];
    }
    y = context->inner_y + entry->y;
    x = context->inner_x;
    z = -1.0f / (0.22424999f + context->depth);
    set_additive_blend();
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(2, -1);
    q.x0 = x - 2.0f;
    q.y0 = y;
    q.x1 = x1 = (16.0f + x) - 2.0f;
    q.y1 = y + entry->height;
    q.u0 = p->u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + p->u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth(&q.x0, z);
    }
    t = x + context->inner_w;
    q.x0 = 2.0f + (t - 16.0f);
    q.y0 = y;
    q.x1 = 2.0f + t;
    q.y1 = y + entry->height;
    u = 32.0f + p->u;
    q.u0 = u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth(&q.x0, z);
    }
    q.x0 = x1;
    q.y0 = y;
    q.x1 = 2.0f + ((x + context->inner_w) - 16.0f);
    q.y1 = y + entry->height;
    q.u0 = (16.0f + p->u) / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + (16.0f + p->u)) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth(&q.x0, z);
    }
    end_screen_draw();
    set_default_alpha_blend();
}

void end_window_sweep_draw(s32 texture) {
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    end_screen_textured_draw();
    set_default_alpha_blend();
    init_tev_swap();
}


#pragma push
#pragma fp_contract on
void draw_window_sweep_strip(TexturedQuad *quad, WindowDrawContext *context) {
    ProjectedStripVertex v[6];
    f32 z;
    f32 t;
    f32 mx;
    f32 mu;
    s32 alpha;
    u32 color;
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    z = -1.0f / context->depth;
    t = ((5.0f * window_scanline_timer - 100.0f) - context->x) / context->w;
    mx = t * (quad->x1 - quad->x0) + quad->x0;
    mu = t * (quad->u1 - quad->u0) + quad->u0;
    if (t > 0.5f) {
        alpha = 2.0f * (160.0f * (1.0f - t));
    } else {
        alpha = 160.0f * (2.0f * t);
    }
    color = ((u8)alpha << 24) | 0xFFFFFF;
    v[0].x = quad->x0;
    v[0].y = quad->y0;
    v[0].w = z;
    v[0].u = quad->u0;
    v[0].v = quad->v0;
    v[0].color = 0xFFFFFF;
    v[1].x = quad->x0;
    v[1].y = quad->y1;
    v[1].w = z;
    v[1].u = quad->u0;
    v[1].v = quad->v1;
    v[1].color = 0xFFFFFF;
    v[2].x = mx;
    v[2].y = quad->y0;
    v[2].w = z;
    v[2].u = mu;
    v[2].v = quad->v0;
    v[2].color = color;
    v[3].x = mx;
    v[3].y = quad->y1;
    v[3].w = z;
    v[3].u = mu;
    v[3].v = quad->v1;
    v[3].color = color;
    v[4].x = quad->x1;
    v[4].y = quad->y0;
    v[4].w = z;
    v[4].u = quad->u1;
    v[4].v = quad->v0;
    v[4].color = 0xFFFFFF;
    v[5].x = quad->x1;
    v[5].y = quad->y1;
    v[5].w = z;
    v[5].u = quad->u1;
    v[5].v = quad->v1;
    v[5].color = 0xFFFFFF;
    draw_projected_textured_strip(v, 6);
}
#pragma pop
void begin_window_sweep_draw(s32 texture) {
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    set_additive_blend();
    set_tev_swap_channels(3, 3, 3, 3);
    set_texture_list(hud_texlist);
    set_texture_num(texture);
    begin_screen_textured_draw(1);
}
#pragma push
#pragma fp_contract on
BOOL scanline_crosses_window(void *ctx, void *position, void *size) {
    f32 limit_x;
    f32 start_x;

    start_x = *(f32 *)position;
    limit_x = (5.0f * (f32) window_scanline_timer) - 100.0f;
    if (limit_x <= start_x) {
        return FALSE;
    }
    if (limit_x >= (start_x + *(f32 *)size)) {
        return FALSE;
    }
    return TRUE;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowBase::draw_message_frame_row(TexturedQuad *quad, WindowDrawContext *context) {
    f32 rem;
    f32 t;
    f32 z;
    f32 w;
    if (this->frame_size[0] < 64.0f) {
        w = 0.5f * this->frame_size[0];
    } else {
        w = 32.0f;
    }
    z = -1.0f / context->depth;
    quad->x0 = context->x;
    quad->x1 = context->x + w;
    quad->u0 = 0.3828125f;
    quad->u1 = 0.5078125f;
    quad->x0 = context->scale[0] * (quad->x0 - context->pivot[0]) + context->pivot[0];
    quad->x1 = context->scale[0] * (quad->x1 - context->pivot[0]) + context->pivot[0];
    draw_textured_quad_at_depth(&quad->x0, z);
    quad->x0 = (context->x + this->frame_size[0]) - w;
    quad->x1 = context->x + this->frame_size[0];
    quad->u0 = 0.6328125f;
    quad->u1 = 0.7578125f;
    quad->x0 = context->scale[0] * (quad->x0 - context->pivot[0]) + context->pivot[0];
    quad->x1 = context->scale[0] * (quad->x1 - context->pivot[0]) + context->pivot[0];
    draw_textured_quad_at_depth(&quad->x0, z);
    quad->x0 = 32.0f + context->x;
    quad->u0 = 0.5078125f;
    quad->u1 = 0.6328125f;
    rem = context->scale[0] * (this->frame_size[0] - 64.0f);
    quad->x0 = context->scale[0] * (quad->x0 - context->pivot[0]) + context->pivot[0];
    while (rem >= 0.0f) {
        if (rem < 32.0f) {
            quad->x1 = quad->x0 + rem;
            t = 130.0f + rem;
            quad->u1 = t / 256.0f;
        } else {
            quad->x1 = 32.0f + quad->x0;
        }
        draw_textured_quad_at_depth(&quad->x0, z);
        rem -= 32.0f;
        quad->x0 += 32.0f;
    }
}
#pragma pop

#pragma fp_contract on
void TWindowBase::draw_quest_message_frame(void *context) {
  WindowDrawContext *c = (WindowDrawContext *)context;
  TexturedQuad q;
  f32 step;
  f32 rem;
  f32 half;
  begin_screen_draw(1);
  set_texture_list(hud_texlist);
  set_draw_texture_and_color(1, -1);
  if (frame_size[1] < 64.0f)
  {
    half = 0.5f * frame_size[1];
  }
  else
  {
    half = 32.0f;
  }
  q.y0 = c->y;
  q.y1 = c->y + half;
  q.v0 = 0.0f;
  q.v1 = 0.125f;
  q.y0 = (c->scale[1] * (q.y0 - c->pivot[1])) + c->pivot[1];
  q.y1 = (c->scale[1] * (q.y1 - c->pivot[1])) + c->pivot[1];
  draw_message_frame_row(&q, c);
  q.y1 = c->y + frame_size[1];
  q.y0 = q.y1 - half;
  q.v0 = 0.25f;
  q.v1 = 0.375f;
  q.y0 = (c->scale[1] * (q.y0 - c->pivot[1])) + c->pivot[1];
  q.y1 = (c->scale[1] * (q.y1 - c->pivot[1])) + c->pivot[1];
  draw_message_frame_row(&q, c);
  q.y0 = 32.0f + c->y;
  q.v0 = 0.125f;
  q.v1 = 0.25f;
  step = 32.0f * c->scale[1];
  rem = frame_size[1] - 64.0f;
  q.y0 = (c->scale[1] * (q.y0 - c->pivot[1])) + c->pivot[1];
  step = 32.0f * c->scale[1];
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      step = rem * c->scale[1];
      q.v1 = (32.0f + rem) / 256.0f;
    }
    q.y1 = q.y0 + step;
    draw_message_frame_row(&q, c);
    rem -= 32.0f;
    q.y0 += step;
  }
  end_screen_draw();
}

#pragma push
#pragma fp_contract on
void draw_window_scanline(TWindowBase *window, s32 row, WindowDrawContext *r, f32 len) {
    ColorLineList lines;
    u32 colors[3];
    ColorLineVertex pts[3];
    f32 depth;
    f32 t;
    u8 alpha;
    f32 y;

    if (len <= 0.0f) {
        return;
    }
    if (len >= window->frame_size[0] - 24.0f) {
        return;
    }
    lines.verts = pts;
    lines.colors = colors;
    lines.tex = NULL;
    lines.count = 3;
    t = len / (r->w - 24.0f);
    depth = r->depth;
    lines.colors[0] = 0x282828;
    lines.colors[1] = 0x282828;
    lines.colors[2] = 0x282828;
    if (t > 0.5f) {
        alpha = 2.0f * (255.0f * (1.0f - t));
    } else {
        alpha = 255.0f * (2.0f * t);
    }
    lines.colors[1] |= alpha << 24;
    pts[0].x = 12.0f + r->x;
    pts[2].x = (r->x + r->w) - 12.0f;
    pts[1].x = pts[0].x + len;
    y = 4.0f * (f32)row + (12.0f + r->y);
    pts[0].y = y;
    pts[1].y = y;
    pts[2].y = y;
    r->scale_point_about_pivot(&pts[0].x);
    r->scale_point_about_pivot(&pts[1].x);
    r->scale_point_about_pivot(&pts[2].x);
    draw_color_lines(&lines, 3, 0x14, depth);
}
#pragma pop

#pragma push
#pragma fp_contract on
void draw_window_scanlines(TWindowBase *window, WindowDrawContext *context) {
    s32 n1;
    s32 i;
    s32 n2;
    f32 step;
    f32 y;
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    n1 = trunc_float((12.0f + window->frame_position[1]) / 4.0f);
    n2 = trunc_float((window->frame_size[1] - 24.0f) / 4.0f);
    y = ((5.0f * ((f32)window_scanline_timer - 0.2f * (f32)n1) - 100.0f) - 12.0f) - window->frame_position[0];
    if (y <= 0.0f) {
        return;
    }
    if (y - (f32)n2 >= window->frame_size[0] - 24.0f) {
        return;
    }
    set_line_width(12.0f * context->scale[1]);
    set_additive_blend();
    step = 1.0f;
    for (i = 0; i < n2; i++) {
        draw_window_scanline(window, i, context, y);
        y -= step;
    }
    set_default_alpha_blend();
    reset_line_width();
}
#pragma pop

#pragma push
#pragma fp_contract on

void TWindowBase::draw_window_frame_strips(TexturedQuad *quad, WindowDrawContext *context) {
  f32 rem;
  f32 t;
  f32 z;
  f32 w;
  z = -1.0f / context->depth;
  w = 0.5f * frame_size[0];
  if (w > 32.0f)
  {
    w = 32.0f;
  }
  quad->x0 = context->x;
  quad->x1 = context->x + w;
  quad->u0 = 0.0f;
  quad->u1 = w / 256.0f;
  quad->x0 = (context->scale[0] * (quad->x0 - context->pivot[0])) + context->pivot[0];
  quad->x1 = (context->scale[0] * (quad->x1 - context->pivot[0])) + context->pivot[0];
  draw_textured_quad_at_depth(&quad->x0, z);
  quad->x0 = (context->x + frame_size[0]) - w;
  quad->x1 = context->x + frame_size[0];
  quad->u0 = (96.0f - w) / 256.0f;
  quad->u1 = 0.375f;
  quad->x0 = (context->scale[0] * (quad->x0 - context->pivot[0])) + context->pivot[0];
  quad->x1 = (context->scale[0] * (quad->x1 - context->pivot[0])) + context->pivot[0];
  draw_textured_quad_at_depth(&quad->x0, z);
  quad->x0 = 32.0f + context->x;
  quad->u0 = 0.125f;
  quad->u1 = 0.25f;
  rem = context->scale[0] * (frame_size[0] - 64.0f);
  quad->x0 = (context->scale[0] * (quad->x0 - context->pivot[0])) + context->pivot[0];
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      quad->x1 = quad->x0 + rem;
      t = 32.0f + rem;
      quad->u1 = t / 256.0f;
    }
    else
    {
      quad->x1 = 32.0f + quad->x0;
    }
    draw_textured_quad_at_depth(&quad->x0, z);
    rem -= 32.0f;
    quad->x0 += 32.0f;
  }

}
#pragma pop

#pragma fp_contract on
void TWindowBase::draw_window_frame(WindowDrawContext *context) {
  TexturedQuad q;
  s32 n;
  f32 h;
  f32 dy;
  f32 rem;
  begin_screen_draw(1);
  set_texture_list(hud_texlist);
  set_draw_texture_and_color(1, context->color);
  n = (s32) frame_size[1];
  n += (4 - (n & 3)) & 3;
  if (((f32) n) < 64.0f)
  {
    h = 0.5f * n;
  }
  else
  {
    h = 32.0f;
  }
  q.y0 = context->y;
  q.y1 = context->y + h;
  q.v0 = 0.0f;
  q.v1 = h / 256.0f;
  q.y0 = (context->scale[1] * (q.y0 - context->pivot[1])) + context->pivot[1];
  q.y1 = (context->scale[1] * (q.y1 - context->pivot[1])) + context->pivot[1];
  draw_window_frame_strips(&q, context);
  q.y0 = (context->y + n) - h;
  q.y1 = context->y + n;
  q.v0 = (96.0f - h) / 256.0f;
  q.v1 = 0.375f;
  q.y0 = (context->scale[1] * (q.y0 - context->pivot[1])) + context->pivot[1];
  q.y1 = (context->scale[1] * (q.y1 - context->pivot[1])) + context->pivot[1];
  draw_window_frame_strips(&q, context);
  q.y0 = 32.0f + context->y;
  q.v0 = 0.125f;
  q.v1 = 0.25f;
  rem = n - 64.0f;
  q.y0 = (context->scale[1] * (q.y0 - context->pivot[1])) + context->pivot[1];
  dy = 32.0f * context->scale[1];
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      dy = rem * context->scale[1];
      q.v1 = (32.0f + rem) / 256.0f;
    }
    q.y1 = q.y0 + dy;
    draw_window_frame_strips(&q, context);
    rem -= 32.0f;
    q.y0 += dy;
  }
  end_screen_draw();
  draw_window_scanlines(this, context);
}

void TWindowBase::update_fade() {
    u32 ticks;

    ticks = this->tween_ticks;
    if (ticks == 0) {
        this->save_position();
        return;
    }
    this->frame_position[0] += (this->target_position[0] - this->frame_position[0]) / (f32) ticks;
    this->frame_position[1] += (this->target_position[1] - this->frame_position[1]) / (f32) this->tween_ticks;
    this->frame_size[0] += (this->target_size[0] - this->frame_size[0]) / (f32) this->tween_ticks;
    this->frame_size[1] += (this->target_size[1] - this->frame_size[1]) / (f32) this->tween_ticks;
    this->tween_ticks = (u32) (this->tween_ticks - 1);
}

void update_window_scanline(void) {
    switch (window_ui_theme_index) {
    case 0:
        window_scanline_timer = 60.0f * ((1.0f / 32768.0f) * rand()) + 60.0f;
        window_ui_theme_index = 1;
    case 1:
        if (window_scanline_timer-- < 0) {
            window_scanline_timer = 0;
            window_ui_theme_index = 2;
        }
        break;
    case 2:
        window_scanline_timer++;
        if (5.0f * ((f32)window_scanline_timer - 0.2f * trunc_float(120.0f)) >= 840.0f) {
            window_ui_theme_index = 0;
        }
        break;
    }
}

void TWindowBase::update_open_close() {
    s32 card_window_flags;
    s32 state_flags;

    if ((s32) open_tick < 0x01000000) {
        card_window_flags = TWindowSubStatusDisp::get_card_window_flags(client_index);
        card_window_flags += open_tick;
        open_tick = card_window_flags + 1;
    }
    state_flags = window_flags;
    if (!(state_flags & 2)) {
        if ((state_flags & 0x10) && (is_closed() != 0)) {
            this->queue_destruction();
        }
    } else if (state_flags & 1) {
        if ((f32) open_tick >= 7.5f) {
            if (state_flags & 4) {
                if (!(state_flags & 0x20)) {
                    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x53704, 0U, 0, 0);
                }
                window_flags = (s32) (window_flags & ~5);
                return;
            }
            window_flags = (s32) (state_flags & 0xFFFFFFFD);
        }
    } else {
        closing_tick = (s16) (closing_tick + 1);
        if ((f32) closing_tick >= 4.5f) {
            if (window_flags & 0x10) {
                this->disallow_rendering();
                this->queue_destruction();
            }
            closing_tick = 0;
            card_window_flags = window_flags;
            if (card_window_flags & 4) {
                if (!(card_window_flags & 0x20)) {
                    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x53703, 0U, 0, 0);
                }
                window_flags = (s32) (window_flags & 0xFFFFFFFB);
                window_flags = (s32) (window_flags | 1);
                open_tick = 0;
                return;
            }
            window_flags = (s32) (card_window_flags & 0xFFFFFFFD);
            this->disallow_rendering();
        }
    }
}


void TWindowDD::update_com_card() { update_window_scanline(); }
void TWindowBase::update_window() { update_open_close(); }
void TWindowBase::render() {  }
void TWindowBase::run_task() {  }

TWindowBase::~TWindowBase() {
    entry_list.destroy_all_items();
    bring_to_front();
}
TWindowBase::TWindowBase(u8 *descriptor, s16 client, u8 *parent)
    : TObject(TWindowCtrlMain__sub_8024CDB0((void *)(saddr)client)) {
    init_window(descriptor, parent, client);
}


extern const char f256_hyouji_a_palette_file[];
extern const char hud_palette_texture_filename[];
extern const char f256_hyouji_c_palette_file[];
extern const char b256_mainmenu_palette_file[];
extern const char f256_actionpallet_a_palette_file[];
extern const char f256_actionpallet_b_palette_file[];
extern const char f256_actionpallet_c_palette_file[];
extern const char r256_symparts_palette_file[];
extern const char f256_duelcount_palette_file[];
extern const char f256_carsol_palette_file[];
extern const char f256_hyouji_texture_file[];

void TWindowCtrlMain::free_window() {
    if (hud_texlist != NULL) {
        release_texture_list(hud_texlist);
        hud_texlist = NULL;
    }
}

void load_hud_palette_textures(void) {
    GvplPalette palette;
    palette.data = TLobby::tmp_buf_use_req("TWindowBase");
    TLanguage::load_palette_tlut(f256_hyouji_a_palette_file, &palette, 0x40);
    TLanguage::load_palette_tlut(hud_palette_texture_filename, &palette, 0x41);
    TLanguage::load_palette_tlut(f256_hyouji_c_palette_file, &palette, 0x42);
    TLanguage::load_palette_tlut(b256_mainmenu_palette_file, &palette, 0x44);
    TLanguage::load_palette_tlut(f256_actionpallet_a_palette_file, &palette, 0x45);
    TLanguage::load_palette_tlut(f256_actionpallet_b_palette_file, &palette, 0x46);
    TLanguage::load_palette_tlut(f256_actionpallet_c_palette_file, &palette, 0x47);
    TLanguage::load_palette_tlut(r256_symparts_palette_file, &palette, 1);
    TLanguage::load_palette_tlut(f256_duelcount_palette_file, &palette, 0x4A);
    TLanguage::load_palette_tlut(f256_carsol_palette_file, &palette, 0x43);
    TLobby::tmp_buf_release("TWindowBase");
    load_disc_prs_texture(f256_hyouji_texture_file, &f256_hyouji_texlist);
    hud_texlist = &f256_hyouji_texlist;
    set_texture_list(&f256_hyouji_texlist);
    set_context_texture_palette_bank(0, 0x40);
    set_context_texture_palette_bank(1, 0x41);
    set_context_texture_palette_bank(2, 0x42);
    set_context_texture_palette_bank(3, 0x45);
    set_context_texture_palette_bank(4, 0x46);
    set_context_texture_palette_bank(5, 0x47);
    set_context_texture_palette_bank(0xB, 0x44);
    set_context_texture_palette_bank(0xC, 0x43);
    set_context_texture_palette_bank(6, 0x4A);
    set_context_texture_palette_bank(7, 1);
    set_context_texture_palette_bank(8, 1);
    set_context_texture_palette_bank(9, 1);
    set_context_texture_palette_bank(0xA, 1);
    window_ui_theme_index = 0;
}

// The HUD texture archives, defined after their use so load_hud_palette_textures
// addresses each one on its own.
__declspec(section ".rodata") const char f256_hyouji_a_palette_file[] = "f256_hyouji_a.gvp";
__declspec(section ".rodata") const char hud_palette_texture_filename[] = "f256_hyouji_b.gvp";
__declspec(section ".rodata") const char f256_hyouji_c_palette_file[] = "f256_hyouji_c.gvp";
__declspec(section ".rodata") const char b256_mainmenu_palette_file[] = "b256_mainmenu.gvp";
__declspec(section ".rodata") const char f256_actionpallet_a_palette_file[] = "f256_actionpallet_a.gvp";
__declspec(section ".rodata") const char f256_actionpallet_b_palette_file[] = "f256_actionpallet_b.gvp";
__declspec(section ".rodata") const char f256_actionpallet_c_palette_file[] = "f256_actionpallet_c.gvp";
__declspec(section ".rodata") const char r256_symparts_palette_file[] = "r256_symparts.gvp";
__declspec(section ".rodata") const char f256_duelcount_palette_file[] = "f256_duelcount.gvp";
__declspec(section ".rodata") const char f256_carsol_palette_file[] = "f256_carsol.gvp";
__declspec(section ".rodata") const char f256_hyouji_texture_file[] = "f256_hyouji";

s32 TWindowBase::is_closed() {
    return (u8)(!(window_flags & 1));
}

int TWindowFukidasi__sub_8024695C(void* p) { return (*(u32*)((char*)p + 0x2c) >> 8) & 0x1; }

int TWindowFukidasi::get_visible_flag() { return ((u32)window_flags >> 9) & 0x1; }

int TWindowFukidasi::is_bit10_set() { return ((u32)window_flags >> 10) & 0x1; }
void TWindowSubStatusDisp::update_entry_visibility() {
    TWindowLayoutEntry *entry7;
    TWindowLayoutEntry *entry6;
    TWindowLayoutEntry *entry5;
    TWindowLayoutEntry *entry4;
    TWindowLayoutEntry *entry3;
    TWindowLayoutEntry *entry2;
    TWindowLayoutEntry *entry1;
    TWindowLayoutEntry *entry0;
    entry7 = (TWindowLayoutEntry *)this->get_array_entry(7);
    entry6 = (TWindowLayoutEntry *)this->get_array_entry(6);
    entry5 = (TWindowLayoutEntry *)this->get_array_entry(5);
    entry4 = (TWindowLayoutEntry *)this->get_array_entry(4);
    entry3 = (TWindowLayoutEntry *)this->get_array_entry(3);
    entry2 = (TWindowLayoutEntry *)this->get_array_entry(2);
    entry1 = (TWindowLayoutEntry *)this->get_array_entry(1);
    entry0 = (TWindowLayoutEntry *)this->get_array_entry(0);
    if (is_guild_card_receive_active() != 0) {
        if (entry7 != NULL) {
            entry7->show();
        }
        if (entry6 != NULL) {
            entry6->show();
        }
    } else {
        if (entry7 != NULL) {
            entry7->hide();
        }
        if (entry6 != NULL) {
            entry6->hide();
        }
    }
    if (is_com_card_active() != 0) {
        if (entry5 != NULL) {
            entry5->show();
        }
        if (entry4 != NULL) {
            entry4->show();
        }
    } else {
        if (entry5 != NULL) {
            entry5->hide();
        }
        if (entry4 != NULL) {
            entry4->hide();
        }
    }
    if (TWindowSubShortMail::is_active() != 0) {
        if (entry3 != NULL) {
            entry3->show();
        }
        if (entry2 != NULL) {
            entry2->show();
        }
    } else {
        if (entry3 != NULL) {
            entry3->hide();
        }
        if (entry2 != NULL) {
            entry2->hide();
        }
    }
    if (is_trade_active() != 0) {
        if (entry1 != NULL) {
            entry1->show();
        }
        if (entry0 != NULL) {
            entry0->show();
        }
    } else {
        if (entry1 != NULL) {
            entry1->hide();
        }
        if (entry0 != NULL) {
            entry0->hide();
        }
    }
}
