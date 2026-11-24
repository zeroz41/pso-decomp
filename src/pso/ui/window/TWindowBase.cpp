#include "pso/render/GinjaTexture.h"
#include "pso/render/ColorLineList.h"
#include <stdlib.h>
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/TWindowSubShortMail_80246CB8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"


struct UV_8024503C { f32 u, v; };

struct UVPair_8024503C { UV_8024503C e[2]; };

const char *TWindowBase::class_name = "TWindowBase";
static const UVPair_8024503C selection_bar_texture_coordinates = {{{151.0f, 57.0f}, {151.0f, 76.0f}}};

struct Quad_80245D64
{
  f32 x0;
  f32 y0;
  f32 x1;
  f32 y1;
  f32 u0;
  f32 v0;
  f32 u1;
  f32 v1;
};

struct Rect_80245D64
{
  f32 x;
  f32 y;
  f32 w;
  f32 h;
  u8 pad10[0x20 - 0x10];
  f32 px;
  f32 py;
  f32 sx;
  f32 sy;
  u8 pad30[0x38 - 0x30];
  f32 depth;
};

struct Quad_80245F98
{
  f32 x0;
  f32 y0;
  f32 x1;
  f32 y1;
  f32 u0;
  f32 v0;
  f32 u1;
  f32 v1;
};

struct Rect_80245F98
{
  f32 x;
  f32 y;
  f32 w;
  f32 h;
  u8 pad10[0x20 - 0x10];
  f32 px;
  f32 py;
  f32 sx;
  f32 sy;
  s32 f30;
  s32 color;
  f32 depth;
};

struct Card_80245F98
{
  u8 pad0[0x4C];
  f32 f4C;
};

struct QFrameQuad_80245808
{
  f32 x;
  f32 y;
  f32 right;
  f32 bottom;
  f32 u;
  f32 v;
  f32 uRight;
  f32 vBottom;
};

struct QFrameWindow_80245808
{
  u8 pad[0x4c];
  f32 height;
};

struct QFrameCtx_80245808
{
  f32 x;
  f32 y;
  u8 pad[0x1c];
  f32 pivotY;
  u8 pad2[4];
  f32 scaleY;
};

void reset_line_width(void);
void set_line_width(int a0);
extern "C" {
void TWindowSubComCard__sub_80245A10(u8 *card, s32 row, WindowDrawContext *r, f32 len);




struct Rect_802455CC { f32 x, y, w, h; u8 pad10[0x20 - 0x10]; f32 px, py, sx, sy; u8 pad30[0x38 - 0x30]; f32 depth; };

s32 play_sound_effect(s32, s32, s32, s32);
int TWindowSubComCard__sub_80244774(void);
void fn_802449E0(u8 *object);
int TWindowFukidasi__sub_8024695C(void *p);

extern int lbl_805D3614;


int TWindowSubComCard__sub_80244774(void) {  return lbl_805D3614; }

uaddr TWindowSubComCard::get_field_20() { return this->m_20; }

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
    set_parent(reinterpret_cast<TObject *>(TWindowCtrlMain__sub_8024CE24()));
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
s32 TWindowBase::sub_80244994() {
    if (this->is_closed() != 0) {
        return 0;
    }
    return (s32) ((u32) __cntlzw(this->window_flags & 4) >> 5);
}
#pragma pop

void fn_802449E0(u8 *object) {
    *(s32 *)((s8 *)object + 0x2C) = (s32) (*(s32 *)((s8 *)object + 0x2C) & 0xFFFFFFF8);
    *(s16 *)((s8 *)object + 0x22) = 0;
    ((TObject *)object)->disallow_rendering();
}
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
s16 lbl_805D63F6;
void draw_window_scanlines(u8 *arg0, u8 *arg1);
void window_request_refresh(u8 *help);
void window_request_show(void *object);
bool is_balloon_overlapping(u8 *balloon, u8 *position, u8 *size);
void window_request_refresh(u8 *help) {
    if (!((f32) *(s32 *)((s8 *)help + 0x5C) >= 7.5f)) {
        *(s32 *)((s8 *)help + 0x5C) = 7;
    }
}

void window_request_show(void *object) {
    s32 state_flags;

    state_flags = *(s32 *)((s8 *)object + 0x2C);
    if (state_flags & 1) {
        *(s32 *)((s8 *)object + 0x2C) = (s32) (state_flags & 0xFFFFFFFB);
        return;
    }
    if (state_flags & 2) {
        *(s32 *)((s8 *)object + 0x2C) = (s32) (state_flags | 4);
        return;
    }
    if (TWindowSubStatusDisp::get_card_window_scale(*(s16 *)((s8 *)object + 0x20)) > 0.0f) {
        *(s32 *)((s8 *)object + 0x5C) = 0;
    }
    *(s32 *)((s8 *)object + 0x2C) = (s32) (*(s32 *)((s8 *)object + 0x2C) | 3);
    if (!(*(s32 *)((s8 *)object + 0x2C) & 0x20)) {
        play_sound_effect(0x53703, 0, 0, 0);
    }
    ((TObject *)object)->allow_rendering();
}

WindowDrawContext *TWindowBase::setup_window_draw_context(f32 *scale) {
    WindowDrawContext *context;
    s32 var_r4;
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
    var_r4 = open_tick;
    if (!(window_flags & 0x2000)) {
        var_r4 = (s32) ((f32) var_r4 - 7.5f);
    }
    context->set_open_tick(var_r4);
    context->apply_closing_stretch(closing_tick);
    return context;
}

WindowDrawContext *TWindowBase::draw_default_entry() {
    return setup_window_draw_context((f32 *)fn_8026CB68());
}

void TWindowBase::set_depth(f32 depth) {
    TWindowBase::sub_8026CC28();
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
    if (((TWindowBase *)this)->sub_80244994() == 0) {
        return NULL;
    }
    for (TWindowFukidasi *p = first; p != NULL; p = static_cast<TWindowFukidasi *>(p->m_next)) {
        if (TWindowFukidasi__sub_8024695C(p) != 0 && p->is_bit10_set() == 0 &&
            ((TWindowBase *)p)->sub_80244994() != 0 && p != this &&
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

void TWindowBase::sub_80244F2C(u8 *descriptor, u8 *parent, s16 client) {
    m_name = class_name;
    copy_vec2(target_position, parent);
    copy_vec2(target_size, descriptor);
    save_position();
    sort_depth = *(f32 *)((s8 *)descriptor + 8);
    draw_depth = -10000.0f;
    window_flags = (s32) *(s32 *)((s8 *)descriptor + 0x10);
    resort_window_order();
    tween_ticks = 0;
    client_index = client;
    init_window_layout_entries(&entry_list, *(const void **)((s8 *)descriptor + 0xC), (int) (client_index));
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

void draw_selection_bar(WindowDrawContext *context, u8 *entry, s32 active) {
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
    y = context->inner_y + *(f32 *)((s8 *)entry + 0xC);
    x = context->inner_x;
    z = -1.0f / (0.22424999f + context->depth);
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(2, -1);
    q.x0 = x - 2.0f;
    q.y0 = y;
    q.x1 = x1 = (16.0f + x) - 2.0f;
    q.y1 = y + *(f32 *)((s8 *)entry + 0x14);
    q.u0 = p->u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + p->u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, z);
    }
    t = x + context->inner_w;
    q.x0 = 2.0f + (t - 16.0f);
    q.y0 = y;
    q.x1 = 2.0f + t;
    q.y1 = y + *(f32 *)((s8 *)entry + 0x14);
    u = 32.0f + p->u;
    q.u0 = u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, z);
    }
    q.x0 = x1;
    q.y0 = y;
    q.x1 = 2.0f + ((x + context->inner_w) - 16.0f);
    q.y1 = y + *(f32 *)((s8 *)entry + 0x14);
    q.u0 = (16.0f + p->u) / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + (16.0f + p->u)) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, z);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

extern "C" {
void TWindowSubComCard__sub_802452DC(s32 texture) {
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    TLobby::reset_player_state();
    set_default_alpha_blend();
    init_tev_swap();
}

}

#pragma push
#pragma fp_contract on
extern "C" {
void TWindowSubComCard__sub_80245320(TexturedQuad *q, Rect_802455CC *r) {
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
    z = -1.0f / r->depth;
    t = ((5.0f * lbl_805D63F6 - 100.0f) - r->x) / r->w;
    mx = t * (q->x1 - q->x0) + q->x0;
    mu = t * (q->u1 - q->u0) + q->u0;
    if (t > 0.5f) {
        alpha = 2.0f * (160.0f * (1.0f - t));
    } else {
        alpha = 160.0f * (2.0f * t);
    }
    color = ((u8)alpha << 24) | 0xFFFFFF;
    v[0].x = q->x0;
    v[0].y = q->y0;
    v[0].w = z;
    v[0].u = q->u0;
    v[0].v = q->v0;
    v[0].color = 0xFFFFFF;
    v[1].x = q->x0;
    v[1].y = q->y1;
    v[1].w = z;
    v[1].u = q->u0;
    v[1].v = q->v1;
    v[1].color = 0xFFFFFF;
    v[2].x = mx;
    v[2].y = q->y0;
    v[2].w = z;
    v[2].u = mu;
    v[2].v = q->v0;
    v[2].color = color;
    v[3].x = mx;
    v[3].y = q->y1;
    v[3].w = z;
    v[3].u = mu;
    v[3].v = q->v1;
    v[3].color = color;
    v[4].x = q->x1;
    v[4].y = q->y0;
    v[4].w = z;
    v[4].u = q->u1;
    v[4].v = q->v0;
    v[4].color = 0xFFFFFF;
    v[5].x = q->x1;
    v[5].y = q->y1;
    v[5].w = z;
    v[5].u = q->u1;
    v[5].v = q->v1;
    v[5].color = 0xFFFFFF;
    draw_projected_textured_strip(v, 6);
}
#pragma pop
void TWindowSubComCard__sub_802454E4(s32 texture) {
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    set_additive_blend();
    set_tev_swap_channels(3, 3, 3, 3);
    TObjFish::set_global_param(hud_texlist);
    set_texture_num(texture);
    TLobby__sub_803E2EE4(1);
}
#pragma push
#pragma fp_contract on
BOOL TWindowSubComCard__sub_80245558(void *ctx, void *position, void *size) {
    f32 limit_x;
    f32 start_x;

    start_x = *(f32 *)position;
    limit_x = (5.0f * (f32) lbl_805D63F6) - 100.0f;
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
void TWindowBase::draw_message_frame_row(void *q, void *r) {
    f32 rem;
    f32 t;
    f32 z;
    f32 w;
    if (this->frame_size[0] < 64.0f) {
        w = 0.5f * this->frame_size[0];
    } else {
        w = 32.0f;
    }
    z = -1.0f / ((Rect_802455CC *)r)->depth;
    ((TexturedQuad *)q)->x0 = ((Rect_802455CC *)r)->x;
    ((TexturedQuad *)q)->x1 = ((Rect_802455CC *)r)->x + w;
    ((TexturedQuad *)q)->u0 = 0.3828125f;
    ((TexturedQuad *)q)->u1 = 0.5078125f;
    ((TexturedQuad *)q)->x0 = ((Rect_802455CC *)r)->sx * (((TexturedQuad *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    ((TexturedQuad *)q)->x1 = ((Rect_802455CC *)r)->sx * (((TexturedQuad *)q)->x1 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    draw_textured_quad_at_depth((f32 *)((TexturedQuad *)q), z);
    ((TexturedQuad *)q)->x0 = (((Rect_802455CC *)r)->x + this->frame_size[0]) - w;
    ((TexturedQuad *)q)->x1 = ((Rect_802455CC *)r)->x + this->frame_size[0];
    ((TexturedQuad *)q)->u0 = 0.6328125f;
    ((TexturedQuad *)q)->u1 = 0.7578125f;
    ((TexturedQuad *)q)->x0 = ((Rect_802455CC *)r)->sx * (((TexturedQuad *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    ((TexturedQuad *)q)->x1 = ((Rect_802455CC *)r)->sx * (((TexturedQuad *)q)->x1 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    draw_textured_quad_at_depth((f32 *)((TexturedQuad *)q), z);
    ((TexturedQuad *)q)->x0 = 32.0f + ((Rect_802455CC *)r)->x;
    ((TexturedQuad *)q)->u0 = 0.5078125f;
    ((TexturedQuad *)q)->u1 = 0.6328125f;
    rem = ((Rect_802455CC *)r)->sx * (this->frame_size[0] - 64.0f);
    ((TexturedQuad *)q)->x0 = ((Rect_802455CC *)r)->sx * (((TexturedQuad *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    while (rem >= 0.0f) {
        if (rem < 32.0f) {
            ((TexturedQuad *)q)->x1 = ((TexturedQuad *)q)->x0 + rem;
            t = 130.0f + rem;
            ((TexturedQuad *)q)->u1 = t / 256.0f;
        } else {
            ((TexturedQuad *)q)->x1 = 32.0f + ((TexturedQuad *)q)->x0;
        }
        draw_textured_quad_at_depth((f32 *)((TexturedQuad *)q), z);
        rem -= 32.0f;
        ((TexturedQuad *)q)->x0 += 32.0f;
    }
}
#pragma pop

typedef struct QFrameCtx_80245808 QFrameCtx_80245808;
typedef struct QFrameQuad_80245808 QFrameQuad_80245808;
typedef struct QFrameWindow_80245808 QFrameWindow_80245808;
#pragma fp_contract on
void TWindowBase::draw_quest_message_frame(void *c_arg) {
    struct QFrameCtx_80245808 *c = (struct QFrameCtx_80245808 *)c_arg;
  struct QFrameQuad_80245808 q;
  f32 step;
  f32 rem;
  f32 half;
  begin_screen_draw(1);
  TObjFish::set_global_param(hud_texlist);
  set_draw_texture_and_color(1, -1);
  if (((struct QFrameWindow_80245808 *)this)->height < 64.0f)
  {
    half = 0.5f * ((struct QFrameWindow_80245808 *)this)->height;
  }
  else
  {
    half = 32.0f;
  }
  q.y = c->y;
  q.bottom = c->y + half;
  q.v = 0.0f;
  q.vBottom = 0.125f;
  q.y = (c->scaleY * (q.y - c->pivotY)) + c->pivotY;
  q.bottom = (c->scaleY * (q.bottom - c->pivotY)) + c->pivotY;
  draw_message_frame_row((TexturedQuad *)(&q), (Rect_802455CC *)(c));
  q.bottom = c->y + ((struct QFrameWindow_80245808 *)this)->height;
  q.y = q.bottom - half;
  q.v = 0.25f;
  q.vBottom = 0.375f;
  q.y = (c->scaleY * (q.y - c->pivotY)) + c->pivotY;
  q.bottom = (c->scaleY * (q.bottom - c->pivotY)) + c->pivotY;
  draw_message_frame_row((TexturedQuad *)(&q), (Rect_802455CC *)(c));
  q.y = 32.0f + c->y;
  q.v = 0.125f;
  q.vBottom = 0.25f;
  step = 32.0f * c->scaleY;
  rem = ((struct QFrameWindow_80245808 *)this)->height - 64.0f;
  q.y = (c->scaleY * (q.y - c->pivotY)) + c->pivotY;
  step = 32.0f * c->scaleY;
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      step = rem * ((float) c->scaleY);
      q.vBottom = (32.0f + rem) / 256.0f;
    }
    q.bottom = q.y + step;
    draw_message_frame_row((TexturedQuad *)(&q), (Rect_802455CC *)(c));
    rem -= 32.0f;
    q.y += step;
  }
  TWindowSubStatusDisp::get_player();
}
}

#pragma push
#pragma fp_contract on
void TWindowSubComCard__sub_80245A10(u8 *card, s32 row, WindowDrawContext *r, f32 len) {
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
    if (len >= *(f32 *)(card + 0x48) - 24.0f) {
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
void draw_window_scanlines(u8 *card, u8 *arg1) {
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
    n1 = TWindowSubComCard::trunc_float((12.0f + *(f32 *)((s8 *)card + 0x44)) / 4.0f);
    n2 = TWindowSubComCard::trunc_float((*(f32 *)((s8 *)card + 0x4C) - 24.0f) / 4.0f);
    y = ((5.0f * ((f32)lbl_805D63F6 - 0.2f * (f32)n1) - 100.0f) - 12.0f) - *(f32 *)((s8 *)card + 0x40);
    if (y <= 0.0f) {
        return;
    }
    if (y - (f32)n2 >= *(f32 *)((s8 *)card + 0x48) - 24.0f) {
        return;
    }
    set_line_width(12.0f * *(f32 *)((s8 *)arg1 + 0x2C));
    set_additive_blend();
    step = 1.0f;
    for (i = 0; i < n2; i++) {
        TWindowSubComCard__sub_80245A10(card, i, (WindowDrawContext *)arg1, y);
        y -= step;
    }
    set_default_alpha_blend();
    reset_line_width();
}
#pragma pop

typedef struct Quad_80245D64 Quad_80245D64;
typedef struct Rect_80245D64 Rect_80245D64;
#pragma push
#pragma fp_contract on

void TWindowBase::draw_window_frame_strips(void *q, void *r) {
  f32 rem;
  f32 t;
  f32 z;
  f32 w;
  z = -1.0f / ((Rect_80245D64 *)r)->depth;
  w = 0.5f * (*((f32 *) (((s8 *) ((u8 *)this)) + 0x48)));
  if (w > 32.0f)
  {
    w = 32.0f;
  }
  ((Quad_80245D64 *)q)->x0 = ((Rect_80245D64 *)r)->x;
  ((Quad_80245D64 *)q)->x1 = ((Rect_80245D64 *)r)->x + w;
  ((Quad_80245D64 *)q)->u0 = 0.0f;
  ((Quad_80245D64 *)q)->u1 = w / 256.0f;
  ((Quad_80245D64 *)q)->x0 = (((Rect_80245D64 *)r)->sx * (((Quad_80245D64 *)q)->x0 - ((Rect_80245D64 *)r)->px)) + ((Rect_80245D64 *)r)->px;
  ((Quad_80245D64 *)q)->x1 = (((Rect_80245D64 *)r)->sx * (((Quad_80245D64 *)q)->x1 - ((Rect_80245D64 *)r)->px)) + ((Rect_80245D64 *)r)->px;
  draw_textured_quad_at_depth((f32 *)((Quad_80245D64 *)q), z);
  ((Quad_80245D64 *)q)->x0 = (((Rect_80245D64 *)r)->x + (*((f32 *) (((s8 *) ((u8 *)this)) + 0x48)))) - w;
  ((Quad_80245D64 *)q)->x1 = ((Rect_80245D64 *)r)->x + (*((f32 *) (((s8 *) ((u8 *)this)) + 0x48)));
  ((Quad_80245D64 *)q)->u0 = (96.0f - w) / 256.0f;
  ((Quad_80245D64 *)q)->u1 = 0.375f;
  ((Quad_80245D64 *)q)->x0 = (((Rect_80245D64 *)r)->sx * (((Quad_80245D64 *)q)->x0 - ((Rect_80245D64 *)r)->px)) + ((Rect_80245D64 *)r)->px;
  ((Quad_80245D64 *)q)->x1 = (((Rect_80245D64 *)r)->sx * (((Quad_80245D64 *)q)->x1 - ((Rect_80245D64 *)r)->px)) + ((Rect_80245D64 *)r)->px;
  draw_textured_quad_at_depth((f32 *)((Quad_80245D64 *)q), z);
  ((Quad_80245D64 *)q)->x0 = 32.0f + ((Rect_80245D64 *)r)->x;
  ((Quad_80245D64 *)q)->u0 = 0.125f;
  ((Quad_80245D64 *)q)->u1 = 0.25f;
  rem = ((Rect_80245D64 *)r)->sx * ((*((f32 *) (((s8 *) ((u8 *)this)) + 0x48))) - 64.0f);
  ((Quad_80245D64 *)q)->x0 = (((Rect_80245D64 *)r)->sx * (((Quad_80245D64 *)q)->x0 - ((Rect_80245D64 *)r)->px)) + ((Rect_80245D64 *)r)->px;
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      ((Quad_80245D64 *)q)->x1 = ((Quad_80245D64 *)q)->x0 + rem;
      t = 32.0f + rem;
      ((Quad_80245D64 *)q)->u1 = t / 256.0f;
    }
    else
    {
      ((Quad_80245D64 *)q)->x1 = 32.0f + ((Quad_80245D64 *)q)->x0;
    }
    draw_textured_quad_at_depth((f32 *)((Quad_80245D64 *)q), z);
    rem -= 32.0f;
    ((Quad_80245D64 *)q)->x0 += 32.0f;
  }

}
#pragma pop

typedef struct Card_80245F98 Card_80245F98;
typedef struct Quad_80245F98 Quad_80245F98;
typedef struct Rect_80245F98 Rect_80245F98;
#pragma fp_contract on
void TWindowBase::draw_window_frame(void *r) {
  Quad_80245F98 q;
  s32 n;
  f32 h;
  f32 dy;
  f32 rem;
  begin_screen_draw(1);
  TObjFish::set_global_param(hud_texlist);
  set_draw_texture_and_color(1, ((Rect_80245F98 *)r)->color);
  n = (s32) ((Card_80245F98 *)this)->f4C;
  n += (4 - (n & 3)) & 3;
  if (((f32) n) < 64.0f)
  {
    h = 0.5f * n;
  }
  else
  {
    h = 32.0f;
  }
  q.y0 = ((Rect_80245F98 *)r)->y;
  q.y1 = ((Rect_80245F98 *)r)->y + h;
  q.v0 = 0.0f;
  q.v1 = h / 256.0f;
  q.y0 = (((Rect_80245F98 *)r)->sy * (q.y0 - ((Rect_80245F98 *)r)->py)) + ((Rect_80245F98 *)r)->py;
  q.y1 = (((Rect_80245F98 *)r)->sy * (q.y1 - ((Rect_80245F98 *)r)->py)) + ((Rect_80245F98 *)r)->py;
  draw_window_frame_strips((Quad_80245D64 *)(&q), (Rect_80245D64 *)(((Rect_80245F98 *)r)));
  q.y0 = (((Rect_80245F98 *)r)->y + n) - h;
  q.y1 = ((Rect_80245F98 *)r)->y + n;
  q.v0 = (96.0f - h) / 256.0f;
  q.v1 = 0.375f;
  q.y0 = (((Rect_80245F98 *)r)->sy * (q.y0 - ((Rect_80245F98 *)r)->py)) + ((Rect_80245F98 *)r)->py;
  q.y1 = (((Rect_80245F98 *)r)->sy * (q.y1 - ((Rect_80245F98 *)r)->py)) + ((Rect_80245F98 *)r)->py;
  draw_window_frame_strips((Quad_80245D64 *)(&q), (Rect_80245D64 *)(((Rect_80245F98 *)r)));
  q.y0 = 32.0f + ((Rect_80245F98 *)r)->y;
  q.v0 = 0.125f;
  q.v1 = 0.25f;
  rem = n - 64.0f;
  q.y0 = (((Rect_80245F98 *)r)->sy * (q.y0 - ((Rect_80245F98 *)r)->py)) + ((Rect_80245F98 *)r)->py;
  dy = 32.0f * ((Rect_80245F98 *)r)->sy;
  while (rem >= 0.0f)
  {
    if (rem < 32.0f)
    {
      dy = rem * ((Rect_80245F98 *)r)->sy;
      q.v1 = (32.0f + rem) / 256.0f;
    }
    q.y1 = q.y0 + dy;
    draw_window_frame_strips((Quad_80245D64 *)(&q), (Rect_80245D64 *)(((Rect_80245F98 *)r)));
    rem -= 32.0f;
    q.y0 += dy;
  }
  TWindowSubStatusDisp::get_player();
  draw_window_scanlines((u8 *)this, (u8 *)((Rect_80245F98 *)r));
}

void TWindowBase::update_fade() {
    u32 ticks;

    ticks = this->tween_ticks;
    if (ticks == 0) {
        ((TWindowBase *)this)->save_position();
        return;
    }
    *(f32 *)&(*(s32 *)((u8 *)this + 0x40)) += (*(f32 *)&(*(void * *)((u8 *)this + 0x30)) - *(f32 *)&(*(s32 *)((u8 *)this + 0x40))) / (f32) ticks;
    this->frame_position[1] += (this->target_position[1] - this->frame_position[1]) / (f32) this->tween_ticks;
    this->frame_size[0] += (this->target_size[0] - this->frame_size[0]) / (f32) this->tween_ticks;
    this->frame_size[1] += (this->target_size[1] - this->frame_size[1]) / (f32) this->tween_ticks;
    this->tween_ticks = (u32) (this->tween_ticks - 1);
}

extern "C" {

void TWindowSubComCard__sub_8024634C(void) {
    switch (window_ui_theme_index) {
    case 0:
        lbl_805D63F6 = 60.0f * ((1.0f / 32768.0f) * rand()) + 60.0f;
        window_ui_theme_index = 1;
    case 1:
        if (lbl_805D63F6-- < 0) {
            lbl_805D63F6 = 0;
            window_ui_theme_index = 2;
        }
        break;
    case 2:
        lbl_805D63F6++;
        if (5.0f * ((f32)lbl_805D63F6 - 0.2f * TWindowSubComCard::trunc_float(120.0f)) >= 840.0f) {
            window_ui_theme_index = 0;
        }
        break;
    }
}
}

void TWindowSubComCard::update_open_close() {
    u8 *arg0 = (u8 *)this;
    s32 card_window_flags;
    s32 state_flags;

    if ((s32) *(s32 *)&this->m_5c < 0x01000000) {
        card_window_flags = TWindowSubStatusDisp::get_card_window_flags(*(s16 *)&this->m_20);
        card_window_flags += *(s32 *)&this->m_5c;
        *(s32 *)&this->m_5c = card_window_flags + 1;
    }
    state_flags = *(s32 *)&this->m_2c;
    if (!(state_flags & 2)) {
        if ((state_flags & 0x10) && (((TWindowBase *)arg0)->is_closed() != 0)) {
            ((TObject *)arg0)->queue_destruction();
        }
    } else if (state_flags & 1) {
        if ((f32) *(s32 *)&this->m_5c >= 7.5f) {
            if (state_flags & 4) {
                if (!(state_flags & 0x20)) {
                    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x53704, 0U, 0, 0);
                }
                *(s32 *)&this->m_2c = (s32) (*(s32 *)&this->m_2c & ~5);
                return;
            }
            *(s32 *)&this->m_2c = (s32) (state_flags & 0xFFFFFFFD);
        }
    } else {
        *(s16 *)((s8 *)arg0 + 0x22) = (s16) (*(s16 *)((s8 *)arg0 + 0x22) + 1);
        if ((f32) *(s16 *)((s8 *)arg0 + 0x22) >= 4.5f) {
            if (*(s32 *)&this->m_2c & 0x10) {
                ((TObject *)arg0)->disallow_rendering();
                ((TObject *)arg0)->queue_destruction();
            }
            *(s16 *)((s8 *)arg0 + 0x22) = 0;
            card_window_flags = *(s32 *)&this->m_2c;
            if (card_window_flags & 4) {
                if (!(card_window_flags & 0x20)) {
                    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x53703, 0U, 0, 0);
                }
                *(s32 *)&this->m_2c = (s32) (*(s32 *)&this->m_2c & 0xFFFFFFFB);
                *(s32 *)&this->m_2c = (s32) (*(s32 *)&this->m_2c | 1);
                *(s32 *)&this->m_5c = 0;
                return;
            }
            *(s32 *)&this->m_2c = (s32) (card_window_flags & 0xFFFFFFFD);
            ((TObject *)arg0)->disallow_rendering();
        }
    }
}

extern "C" {
TObject *TWindowCtrlMain__sub_8024CDB0(void *p);
int update_open_close__17TWindowSubComCardFv(void*);

void TWindowDD::update_com_card() { TWindowSubComCard__sub_8024634C(); }
int TWindowDD::initialize_subwindow() { return update_open_close__17TWindowSubComCardFv(this); }
void TWindowBase::render() {  }
void TWindowBase::run_task() {  }

TWindowBase::~TWindowBase() {
    entry_list.destroy_all_items();
    sub_8026CC28();
}
TWindowBase::TWindowBase(u8 *descriptor, s16 client, u8 *parent)
    : TObject(TWindowCtrlMain__sub_8024CDB0((void *)(saddr)client)) {
    sub_80244F2C(descriptor, parent, client);
}

}

extern const char lbl_8044E688[];
extern const char hud_palette_texture_filename[];
extern const char lbl_8044E6B0[];
extern const char lbl_8044E6C4[];
extern const char lbl_8044E6D8[];
extern const char lbl_8044E6F0[];
extern const char lbl_8044E708[];
extern const char lbl_8044E720[];
extern const char lbl_8044E734[];
extern const char lbl_8044E748[];
extern const char lbl_8044E758[];
extern "C" {

void TWindowCtrlMain::free_window() {
    if (hud_texlist != NULL) {
        release_texture_list(hud_texlist);
        hud_texlist = NULL;
    }
}
}

void load_hud_palette_textures(void) {
    s32 palette[3];
    palette[0] = (saddr)TLobby::tmp_buf_use_req("TWindowBase");
    TLanguage::draw_string((void *)lbl_8044E688, (void *)palette, 0x40);
    TLanguage::draw_string((void *)hud_palette_texture_filename, (void *)palette, 0x41);
    TLanguage::draw_string((void *)lbl_8044E6B0, (void *)palette, 0x42);
    TLanguage::draw_string((void *)lbl_8044E6C4, (void *)palette, 0x44);
    TLanguage::draw_string((void *)lbl_8044E6D8, (void *)palette, 0x45);
    TLanguage::draw_string((void *)lbl_8044E6F0, (void *)palette, 0x46);
    TLanguage::draw_string((void *)lbl_8044E708, (void *)palette, 0x47);
    TLanguage::draw_string((void *)lbl_8044E720, (void *)palette, 1);
    TLanguage::draw_string((void *)lbl_8044E734, (void *)palette, 0x4A);
    TLanguage::draw_string((void *)lbl_8044E748, (void *)palette, 0x43);
    TLobby::tmp_buf_release("TWindowBase");
    load_disc_prs_texture((saddr)lbl_8044E758, reinterpret_cast<saddr>(&f256_hyouji_texlist));
    hud_texlist = &f256_hyouji_texlist;
    TObjFish::set_global_param(&f256_hyouji_texlist);
    TLanguage::set_entry_index(0, 0x40);
    TLanguage::set_entry_index(1, 0x41);
    TLanguage::set_entry_index(2, 0x42);
    TLanguage::set_entry_index(3, 0x45);
    TLanguage::set_entry_index(4, 0x46);
    TLanguage::set_entry_index(5, 0x47);
    TLanguage::set_entry_index(0xB, 0x44);
    TLanguage::set_entry_index(0xC, 0x43);
    TLanguage::set_entry_index(6, 0x4A);
    TLanguage::set_entry_index(7, 1);
    TLanguage::set_entry_index(8, 1);
    TLanguage::set_entry_index(9, 1);
    TLanguage::set_entry_index(0xA, 1);
    window_ui_theme_index = 0;
}

// The HUD texture archives, defined after their use so load_hud_palette_textures
// addresses each one on its own.
__declspec(section ".rodata") const char lbl_8044E688[] = "f256_hyouji_a.gvp";
__declspec(section ".rodata") const char hud_palette_texture_filename[] = "f256_hyouji_b.gvp";
__declspec(section ".rodata") const char lbl_8044E6B0[] = "f256_hyouji_c.gvp";
__declspec(section ".rodata") const char lbl_8044E6C4[] = "b256_mainmenu.gvp";
__declspec(section ".rodata") const char lbl_8044E6D8[] = "f256_actionpallet_a.gvp";
__declspec(section ".rodata") const char lbl_8044E6F0[] = "f256_actionpallet_b.gvp";
__declspec(section ".rodata") const char lbl_8044E708[] = "f256_actionpallet_c.gvp";
__declspec(section ".rodata") const char lbl_8044E720[] = "r256_symparts.gvp";
__declspec(section ".rodata") const char lbl_8044E734[] = "f256_duelcount.gvp";
__declspec(section ".rodata") const char lbl_8044E748[] = "f256_carsol.gvp";
__declspec(section ".rodata") const char lbl_8044E758[] = "f256_hyouji";

s32 TWindowBase::is_closed() {
    return (u8)(!(window_flags & 1));
}

int TWindowFukidasi__sub_8024695C(void* p) { return (*(u32*)((char*)p + 0x2c) >> 8) & 0x1; }

int TWindowFukidasi::get_visible_flag() { return (*(u32*)((char*)this + 0x2c) >> 9) & 0x1; }

int TWindowFukidasi::is_bit10_set() { return (*(u32*)((char*)this + 0x2c) >> 10) & 0x1; }
void TWindowSubStatusDisp::update_entry_visibility() {
    uaddr entry7;
    uaddr entry6;
    uaddr entry5;
    uaddr entry4;
    uaddr entry3;
    uaddr entry2;
    uaddr entry1;
    uaddr entry0;
    saddr arg0 = (saddr)this;
    entry7 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(7));
    entry6 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(6));
    entry5 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(5));
    entry4 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(4));
    entry3 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(3));
    entry2 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(2));
    entry1 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(1));
    entry0 = reinterpret_cast<uaddr>(((TWindowBase *)arg0)->get_array_entry(0));
    if (is_guild_card_receive_active() != 0) {
        if (entry7 != 0U) {
            ((TWindowSubStatusDisp *)entry7)->clear_visible_flag();
        }
        if (entry6 != 0U) {
            ((TWindowSubStatusDisp *)entry6)->clear_visible_flag();
        }
    } else {
        if (entry7 != 0U) {
            ((TWindowHelpItem *)entry7)->set_flag0_bit2();
        }
        if (entry6 != 0U) {
            ((TWindowHelpItem *)entry6)->set_flag0_bit2();
        }
    }
    if (is_com_card_active() != 0) {
        if (entry5 != 0U) {
            ((TWindowSubStatusDisp *)entry5)->clear_visible_flag();
        }
        if (entry4 != 0U) {
            ((TWindowSubStatusDisp *)entry4)->clear_visible_flag();
        }
    } else {
        if (entry5 != 0U) {
            ((TWindowHelpItem *)entry5)->set_flag0_bit2();
        }
        if (entry4 != 0U) {
            ((TWindowHelpItem *)entry4)->set_flag0_bit2();
        }
    }
    if (TWindowSubShortMail::is_active() != 0) {
        if (entry3 != 0U) {
            ((TWindowSubStatusDisp *)entry3)->clear_visible_flag();
        }
        if (entry2 != 0U) {
            ((TWindowSubStatusDisp *)entry2)->clear_visible_flag();
        }
    } else {
        if (entry3 != 0U) {
            ((TWindowHelpItem *)entry3)->set_flag0_bit2();
        }
        if (entry2 != 0U) {
            ((TWindowHelpItem *)entry2)->set_flag0_bit2();
        }
    }
    if (is_trade_active() != 0) {
        if (entry1 != 0U) {
            ((TWindowSubStatusDisp *)entry1)->clear_visible_flag();
        }
        if (entry0 != 0U) {
            ((TWindowSubStatusDisp *)entry0)->clear_visible_flag();
        }
    } else {
        if (entry1 != 0U) {
            ((TWindowHelpItem *)entry1)->set_flag0_bit2();
        }
        if (entry0 != 0U) {
            ((TWindowHelpItem *)entry0)->set_flag0_bit2();
        }
    }
}
