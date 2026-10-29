#include "types.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowFukidasi.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/TObject.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803E2D70.h"


struct UV_8024503C { f32 u, v; };

struct UVPair_8024503C { UV_8024503C e[2]; };

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
  s32 f34;
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

extern "C" {
void reset_line_width(void);
void set_line_width(int a0);
struct Vec2_80245A10 { f32 x, y; };
struct Lines_80245A10 { Vec2_80245A10 *verts; u32 *colors; s32 f8; s32 count; };
void TWindowSubComCard__sub_80245A10(u8 *arg0, s32 arg1, TWindowKeyBoardSoft *r, f32 len);
void draw_color_lines(Lines_80245A10 *l, s32 n, s32 flags, f32 scale);
void begin_screen_draw(s32);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32, s32);
struct VOff_8024491C_arg0_card_1 { char pad_0[0x38]; char f_38[1]; };

struct VOff_80244958_arg0_card_1 { char pad_0[0x30]; char f_30[1]; };

struct Win_80244DFC { u8 pad[0xC]; Win_80244DFC *next; };

struct Quad_802455CC { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Rect_802455CC { f32 x, y, w, h; u8 pad10[0x20 - 0x10]; f32 px, py, sx, sy; u8 pad30[0x38 - 0x30]; f32 depth; };

void queue_destruction__7TObjectFv(void *);
void allow_rendering__7TObjectFv(TObject *arg0);
void disallow_rendering__7TObjectFv(TObject *);
int copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void*);
s32 play_sound_effect(s32, s32, s32, s32);
int TWindowSubComCard__sub_80244774(void);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *arg0);
void save_position__13TUnk_804CE018Fv(void* p);
void TWindowSubTradeMain__sub_802448E4(void *arg0);
void fn_8024491C(void *arg0);
void fn_80244958(void *arg0);
void fn_802449E0(u8 *arg0);
void TWindow__close(u8 *arg0);
Win_80244DFC * find_overlapping_balloon__15TWindowFukidasiFPvPvPvPv(Win_80244DFC *self, void *a, void *b, Win_80244DFC *p);
s32 sub_80246948__13TUnk_804CE018Fv();
int TWindowFukidasi__sub_8024695C(void *p);
s32 TWindowCtrlMain__sub_8024CE24();
s32 animate_scale__19TWindowKeyBoardSoftFv();
s32 open_singleton__19TWindowKeyBoardSoftFiiii(void *, void *, void *, int, f32);
s32 init_window_layout_entries(void *, int, int);
s32 sub_8026CC28__13TUnk_804CE018Fv();
s32 resort_window_order__13TUnk_804CE018Fv(void *);

extern int lbl_805D3614;
extern s32 lbl_805D3888;

extern "C" {
s32 try_open__19TWindowKeyBoardSoftFii(void *, Quad_802455CC *);
}

int TWindowSubComCard__sub_80244774(void) {  return lbl_805D3614; }

s32 TWindowSubComCard::get_field_20() { return this->m_20; }

f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *window_sub_com_card) {
    f32 v = window_sub_com_card->calc_offset();
    if (v < 1.0f) {
        return v;
    }
    return window_sub_com_card->get_normalized_progress();
}

f32 TWindowSubComCard::calc_offset() {
    s16 temp_r3;

    temp_r3 = *(s16 *)((s8 *)this + 0x22);
    if (temp_r3 != 0) {
        return 1.0f - ((f32) temp_r3 / 4.5f);
    }
    return 1.0f;
}

#pragma push
#pragma opt_common_subs off
f32 TWindowSubComCard::get_normalized_progress() {
    s32 temp_r3;
    if (this->m_2c & 0x2000) {
        return 1.0f;
    }
    temp_r3 = this->m_5c;
    if ((f32) temp_r3 >= 7.5f) {
        return 1.0f;
    }
    return (f32) temp_r3 / 7.5f;
}
#pragma pop

void TWindowSubComCard::reparent_to_main_ctrl() {
    s32 arg0 = (s32)this;
    ((TObject *)arg0)->set_parent((TObject *)(TWindowCtrlMain__sub_8024CE24()));
}

void TUnk_804CE018::save_position() { *(f32*)((char*)this + 0x40) = *(f32*)((char*)this + 0x30); *(f32*)((char*)this + 0x44) = *(f32*)((char*)this + 0x34); *(f32*)((char*)this + 0x48) = *(f32*)((char*)this + 0x38); *(f32*)((char*)this + 0x4c) = *(f32*)((char*)this + 0x3c); }

void TWindowSubTradeMain__sub_802448E4(void *arg0) {
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv((void*)((void *)((char *)arg0 + 48)));
    *(u32 *)((s8 *)arg0 + 0x50) = 3;
}

void fn_8024491C(void *arg0) {
    struct VOff_8024491C_arg0_card_1 *self = (struct VOff_8024491C_arg0_card_1 *)arg0;
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv(self->f_38);
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 72), self->f_38);
}

void fn_80244958(void *arg0) {
    struct VOff_80244958_arg0_card_1 *self = (struct VOff_80244958_arg0_card_1 *)arg0;
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv(self->f_30);
    ((void (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *)((char *)arg0 + 64), self->f_30);
}

#pragma push
#pragma fp_contract on
s32 TUnk_804CE018::sub_80244994() {
    if (sub_80246948__13TUnk_804CE018Fv() != 0) {
        return 0;
    }
    return (s32) ((u32) __cntlzw(*(s32 *)((s8 *)this + 0x2C) & 4) >> 5);
}
#pragma pop

void fn_802449E0(u8 *object) {
    *(s32 *)((s8 *)object + 0x2C) = (s32) (*(s32 *)((s8 *)object + 0x2C) & 0xFFFFFFF8);
    *(s16 *)((s8 *)object + 0x22) = 0;
    disallow_rendering__7TObjectFv((TObject *)object);
}

void TWindow__close(u8 *window_lock_on) {
    ((TWindowLockOn *)window_lock_on)->request_close();
    ((TWindowLockOn *)window_lock_on)->m_2c = (s32) (((TWindowLockOn *)window_lock_on)->m_2c | 0x10);
}

void TWindowLockOn::request_close() {
    s32 temp_r3;
    temp_r3 = *(s32 *)&(this->m_2c);
    if (!(temp_r3 & 1)) {
        *(s32 *)&(this->m_2c) = (s32) (temp_r3 & 0xFFFFFFFB);
        return;
    }
    if (temp_r3 & 2) {
        *(s32 *)&(this->m_2c) = (s32) (temp_r3 | 4);
        return;
    }
    if (!(temp_r3 & 0x20)) {
        ((s32)play_sound_effect(0x53704, 0, 0, 0));
    }
    *(s32 *)&(this->m_2c) = (s32) (*(s32 *)&(this->m_2c) & 0xFFFFFFFE);
    *(s32 *)&(this->m_2c) = (s32) (*(s32 *)&(this->m_2c) | 2);
}

s32 TUnk_804CE018::is_window_reveal_complete() {
    return (f32) *(s32 *)((s8 *)((u8 *)this) + 0x5C) >= 7.5f;
}
}
extern u16 window_ui_theme_index;
extern s16 lbl_805D63F6;
void draw_window_scanlines(u8 *arg0, u8 *arg1);
extern UVPair_8024503C selection_bar_texture_coordinates;
extern s32 lbl_805D63F0;
void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
void window_request_refresh(u8 *arg0);
void window_request_show(void *arg0);
bool is_balloon_overlapping(u8 *arg0, u8 *arg1, u8 *arg2);
void apply_window_closing_stretch(u8 *arg0, int arg1);
void window_request_refresh(u8 *arg0) {
    if (!((f32) *(s32 *)((s8 *)arg0 + 0x5C) >= 7.5f)) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
}

void window_request_show(void *object) {
    s32 temp_r3;

    temp_r3 = *(s32 *)((s8 *)object + 0x2C);
    if (temp_r3 & 1) {
        *(s32 *)((s8 *)object + 0x2C) = (s32) (temp_r3 & 0xFFFFFFFB);
        return;
    }
    if (temp_r3 & 2) {
        *(s32 *)((s8 *)object + 0x2C) = (s32) (temp_r3 | 4);
        return;
    }
    if (TWindowSubStatusDisp::get_card_window_scale(*(s16 *)((s8 *)object + 0x20)) > 0.0f) {
        *(s32 *)((s8 *)object + 0x5C) = 0;
    }
    *(s32 *)((s8 *)object + 0x2C) = (s32) (*(s32 *)((s8 *)object + 0x2C) | 3);
    if (!(*(s32 *)((s8 *)object + 0x2C) & 0x20)) {
        play_sound_effect(0x53703, 0, 0, 0);
    }
    allow_rendering__7TObjectFv((TObject *)object);
}

s32 TUnk_804CE018::setup_window_draw_context(s32 arg1) {
    s32 temp_r31;
    s32 var_r4;
    temp_r31 = ((s32 (*)(void *, void *, void *, f32, int))open_singleton__19TWindowKeyBoardSoftFiiii)((void *) (((u8 *)this) + 0x40), (void *) (((u8 *)this) + 0x48), (void *)arg1, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x54)), (int) (*(s32 *)((s8 *)((u8 *)this) + 0x2C)));
    if (*(s32 *)((s8 *)((u8 *)this) + 0x2C) & 0x40) {
        animate_scale__19TWindowKeyBoardSoftFv();
    }
    if (*(s32 *)((s8 *)((u8 *)this) + 0x2C) & 0x80) {
        ((TWindowKeyBoardSoft *)temp_r31)->shrink_clip_right();
    }
    if (*(s32 *)((s8 *)((u8 *)this) + 0x2C) & 8) {
        ((TWindowKeyBoardSoft *)temp_r31)->set_bounds(0.0f, 0.0f, 640.0f, 480.0f);
    }
    var_r4 = *(s32 *)((s8 *)((u8 *)this) + 0x5C);
    if (!(*(s32 *)((s8 *)((u8 *)this) + 0x2C) & 0x2000)) {
        var_r4 = (s32) ((f32) var_r4 - 7.5f);
    }
    ((TWindowKeyBoardSoft *)temp_r31)->set_open_tick(var_r4);
    apply_window_closing_stretch((u8 *)temp_r31, (*(s16 *)((s8 *)((u8 *)this) + 0x22)));
    return temp_r31;
}

s32 TWindowDD::draw_default_entry(s32 arg0) {
    return ((TUnk_804CE018 *)arg0)->setup_window_draw_context((s32)fn_8026CB68());
}

void TLobby::set_field_1c(f32 farg0) {
    sub_8026CC28__13TUnk_804CE018Fv();
    *(f32 *)((s8 *)this + 0x1C) = farg0;
    resort_window_order__13TUnk_804CE018Fv(this);
}

bool is_balloon_overlapping(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    temp_f2_2 = *(f32 *)((s8 *)arg1 + 0);
    if (temp_f2_2 >= (*(f32 *)((s8 *)arg0 + 0x30) + *(f32 *)((s8 *)arg0 + 0x38))) {
        return 0;
    }
    if ((temp_f2_2 + *(f32 *)((s8 *)arg2 + 0)) <= *(f32 *)((s8 *)arg0 + 0x40)) {
        return 0;
    }
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x34);
    temp_f1 = *(f32 *)((s8 *)arg1 + 4);
    if (temp_f1 >= (temp_f2 + *(f32 *)((s8 *)arg0 + 0x3C))) {
        return 0;
    }
    return ((temp_f1 + *(f32 *)((s8 *)arg2 + 4)) <= temp_f2) == 0;
}

Win_80244DFC *find_overlapping_balloon__15TWindowFukidasiFPvPvPvPv(Win_80244DFC *self, void *a, void *b, Win_80244DFC *p) {
    if (TWindowFukidasi__sub_8024695C(self) == 0) {
        return 0;
    }
    if (((TWindowFukidasi *)self)->is_bit10_set() != 0) {
        return 0;
    }
    if (((TUnk_804CE018 *)self)->sub_80244994() == 0) {
        return 0;
    }
    for (; p != 0; p = p->next) {
        if (TWindowFukidasi__sub_8024695C(p) != 0 && ((TWindowFukidasi *)p)->is_bit10_set() == 0 &&
            ((TUnk_804CE018 *)p)->sub_80244994() != 0 && p != self &&
            (((TWindowFukidasi *)self)->get_visible_flag() == 0 || ((TWindowFukidasi *)p)->get_visible_flag() == 0) &&
            ((s32 (*)(void *, void *, void *))is_balloon_overlapping)(p, a, b) != 0) {
            return p;
        }
    }
    return 0;
}

void TWindowFukidasi::find_balloon_overlap_for(s32 arg1) {
    s32 arg0 = (s32)this;
    find_overlapping_balloon__15TWindowFukidasiFPvPvPvPv((Win_80244DFC *)(arg0), (void *)(arg0 + 0x30), (void *)(arg0 + 0x38), (Win_80244DFC *)(arg1));
}

void TUnk_804CE018::sub_80244F2C(u8 *arg1, u8 *arg2, s16 arg3) {
    f32 temp_f1;
    s32 temp_r3;
    s32 temp_r3_2;
    *(s32 *)((s8 *)((u8 *)this) + 0) = (s32) lbl_805D3888;
    ((s32 (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *) (((u8 *)this) + 0x30), arg2);
    ((s32 (*)(void *, void *))copy_vec2__28TWindowSubSymbolChatPartsSetFPv)((void *) (((u8 *)this) + 0x38), arg1);
    ((s32 (*)(void *))save_position__13TUnk_804CE018Fv)(this);
    temp_f1 = *(f32 *)((s8 *)arg1 + 8);
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = temp_f1;
    *(f32 *)((s8 *)((u8 *)this) + 0x54) = -10000.0f;
    *(s32 *)((s8 *)((u8 *)this) + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    ((s32 (*)(void *, f32))resort_window_order__13TUnk_804CE018Fv)(this, temp_f1);
    *(s32 *)((s8 *)((u8 *)this) + 0x50) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x20) = arg3;
    init_window_layout_entries((void *) (((u8 *)this) + 0x24), (int) (*(s32 *)((s8 *)arg1 + 0xC)), (int) (*(s16 *)((s8 *)((u8 *)this) + 0x20)));
    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0;
    *(s16 *)((s8 *)((u8 *)this) + 0x22) = 0;
    temp_r3 = *(s32 *)((s8 *)((u8 *)this) + 0x2C);
    if (!(temp_r3 & 1) && !(temp_r3 & 2)) {
        ((s32 (*)(void *))disallow_rendering__7TObjectFv)(this);
    }
    temp_r3_2 = *(s32 *)((s8 *)((u8 *)this) + 0x2C);
    if ((temp_r3_2 & 1) && (temp_r3_2 & 2) && !(temp_r3_2 & 0x20)) {
        ((s32 (*)(int, int, int, int))play_sound_effect)(0x53703, 0, 0, 0);
    }
    if (TWindowSubStatusDisp::get_card_window_scale((int) (*(s16 *)((s8 *)((u8 *)this) + 0x20))) <= 0.0f) {
        *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0x01000000;
    }
}

void draw_selection_bar(u8 *window_key_board_soft, u8 *arg1, s32 arg2) {
    UVPair_8024503C uv = selection_bar_texture_coordinates;
    UV_8024503C *p;
    Quad_802455CC q;
    f32 x1;
    f32 x;
    f32 y;
    f32 z;
    f32 t;
    f32 u;
    if (*(s32 *)((s8 *)window_key_board_soft + 0x30) < 0) {
        return;
    }
    p = &uv.e[0];
    if (arg2 != 0) {
        p = &uv.e[1];
    }
    y = *(f32 *)((s8 *)window_key_board_soft + 0x14) + *(f32 *)((s8 *)arg1 + 0xC);
    x = *(f32 *)((s8 *)window_key_board_soft + 0x10);
    z = -1.0f / (0.22424999f + *(f32 *)((s8 *)window_key_board_soft + 0x38));
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(2, -1);
    q.x0 = x - 2.0f;
    q.y0 = y;
    q.x1 = x1 = (16.0f + x) - 2.0f;
    q.y1 = y + *(f32 *)((s8 *)arg1 + 0x14);
    q.u0 = p->u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + p->u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (try_open__19TWindowKeyBoardSoftFii(window_key_board_soft, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, z);
    }
    t = x + *(f32 *)((s8 *)window_key_board_soft + 0x18);
    q.x0 = 2.0f + (t - 16.0f);
    q.y0 = y;
    q.x1 = 2.0f + t;
    q.y1 = y + *(f32 *)((s8 *)arg1 + 0x14);
    u = 32.0f + p->u;
    q.u0 = u / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + u) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (try_open__19TWindowKeyBoardSoftFii(window_key_board_soft, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, z);
    }
    q.x0 = x1;
    q.y0 = y;
    q.x1 = 2.0f + ((x + *(f32 *)((s8 *)window_key_board_soft + 0x18)) - 16.0f);
    q.y1 = y + *(f32 *)((s8 *)arg1 + 0x14);
    q.u0 = (16.0f + p->u) / 256.0f;
    q.v0 = p->v / 256.0f;
    q.u1 = (16.0f + (16.0f + p->u)) / 256.0f;
    q.v1 = (18.0f + p->v) / 256.0f;
    if (try_open__19TWindowKeyBoardSoftFii(window_key_board_soft, &q) != 0) {
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

struct ProjectedStripVertex { f32 x, y, z, u, v; u32 color; };
extern "C" void draw_projected_textured_strip(ProjectedStripVertex *v, s32 n);

#pragma push
#pragma fp_contract on
extern "C" {
void TWindowSubComCard__sub_80245320(Quad_802455CC *q, Rect_802455CC *r) {
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
    v[0].z = z;
    v[0].u = q->u0;
    v[0].v = q->v0;
    v[0].color = 0xFFFFFF;
    v[1].x = q->x0;
    v[1].y = q->y1;
    v[1].z = z;
    v[1].u = q->u0;
    v[1].v = q->v1;
    v[1].color = 0xFFFFFF;
    v[2].x = mx;
    v[2].y = q->y0;
    v[2].z = z;
    v[2].u = mu;
    v[2].v = q->v0;
    v[2].color = color;
    v[3].x = mx;
    v[3].y = q->y1;
    v[3].z = z;
    v[3].u = mu;
    v[3].v = q->v1;
    v[3].color = color;
    v[4].x = q->x1;
    v[4].y = q->y0;
    v[4].z = z;
    v[4].u = q->u1;
    v[4].v = q->v0;
    v[4].color = 0xFFFFFF;
    v[5].x = q->x1;
    v[5].y = q->y1;
    v[5].z = z;
    v[5].u = q->u1;
    v[5].v = q->v1;
    v[5].color = 0xFFFFFF;
    draw_projected_textured_strip(v, 6);
}
}
#pragma pop

extern "C" {
void TWindowSubComCard__sub_802454E4(s32 texture) {
    switch (window_ui_theme_index) {
    case 0:
    case 1:
        return;
    }
    set_additive_blend();
    set_tev_swap_channels(3, 3, 3, 3);
    TObjFish::set_global_param(lbl_805D63F0);
    set_texture_num(texture);
    TLobby__sub_803E2EE4(1);
}
#pragma push
#pragma fp_contract on
bool TWindowSubComCard__sub_80245558(s32 arg0, f32 *arg1, f32 *arg2) {
    f32 temp_f1;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg1 + 0);
    temp_f1 = (5.0f * (f32) lbl_805D63F6) - 100.0f;
    if (temp_f1 <= temp_f2) {
        return 0;
    }
    return !(temp_f1 >= (temp_f2 + *(f32 *)((s8 *)arg2 + 0)));
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804CE018::draw_message_frame_row(void *q, void *r) {
    f32 rem;
    f32 t;
    f32 z;
    f32 w;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x48) < 64.0f) {
        w = 0.5f * *(f32 *)((s8 *)((u8 *)this) + 0x48);
    } else {
        w = 32.0f;
    }
    z = -1.0f / ((Rect_802455CC *)r)->depth;
    ((Quad_802455CC *)q)->x0 = ((Rect_802455CC *)r)->x;
    ((Quad_802455CC *)q)->x1 = ((Rect_802455CC *)r)->x + w;
    ((Quad_802455CC *)q)->u0 = 0.3828125f;
    ((Quad_802455CC *)q)->u1 = 0.5078125f;
    ((Quad_802455CC *)q)->x0 = ((Rect_802455CC *)r)->sx * (((Quad_802455CC *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    ((Quad_802455CC *)q)->x1 = ((Rect_802455CC *)r)->sx * (((Quad_802455CC *)q)->x1 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    draw_textured_quad_at_depth((f32 *)((Quad_802455CC *)q), z);
    ((Quad_802455CC *)q)->x0 = (((Rect_802455CC *)r)->x + *(f32 *)((s8 *)((u8 *)this) + 0x48)) - w;
    ((Quad_802455CC *)q)->x1 = ((Rect_802455CC *)r)->x + *(f32 *)((s8 *)((u8 *)this) + 0x48);
    ((Quad_802455CC *)q)->u0 = 0.6328125f;
    ((Quad_802455CC *)q)->u1 = 0.7578125f;
    ((Quad_802455CC *)q)->x0 = ((Rect_802455CC *)r)->sx * (((Quad_802455CC *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    ((Quad_802455CC *)q)->x1 = ((Rect_802455CC *)r)->sx * (((Quad_802455CC *)q)->x1 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    draw_textured_quad_at_depth((f32 *)((Quad_802455CC *)q), z);
    ((Quad_802455CC *)q)->x0 = 32.0f + ((Rect_802455CC *)r)->x;
    ((Quad_802455CC *)q)->u0 = 0.5078125f;
    ((Quad_802455CC *)q)->u1 = 0.6328125f;
    rem = ((Rect_802455CC *)r)->sx * (*(f32 *)((s8 *)((u8 *)this) + 0x48) - 64.0f);
    ((Quad_802455CC *)q)->x0 = ((Rect_802455CC *)r)->sx * (((Quad_802455CC *)q)->x0 - ((Rect_802455CC *)r)->px) + ((Rect_802455CC *)r)->px;
    while (rem >= 0.0f) {
        if (rem < 32.0f) {
            ((Quad_802455CC *)q)->x1 = ((Quad_802455CC *)q)->x0 + rem;
            t = 130.0f + rem;
            ((Quad_802455CC *)q)->u1 = t / 256.0f;
        } else {
            ((Quad_802455CC *)q)->x1 = 32.0f + ((Quad_802455CC *)q)->x0;
        }
        draw_textured_quad_at_depth((f32 *)((Quad_802455CC *)q), z);
        rem -= 32.0f;
        ((Quad_802455CC *)q)->x0 += 32.0f;
    }
}
#pragma pop

typedef struct QFrameCtx_80245808 QFrameCtx_80245808;
typedef struct QFrameQuad_80245808 QFrameQuad_80245808;
typedef struct QFrameWindow_80245808 QFrameWindow_80245808;
#pragma fp_contract on
void TUnk_804CE018::draw_quest_message_frame(void *c_arg) {
    struct QFrameCtx_80245808 *c = (struct QFrameCtx_80245808 *)c_arg;
  struct QFrameQuad_80245808 q;
  f32 step;
  f32 rem;
  f32 half;
  begin_screen_draw(1);
  TObjFish::set_global_param((s32)((*(void * *)&lbl_805D63F0)));
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
  draw_message_frame_row((Quad_802455CC *)(&q), (Rect_802455CC *)(c));
  q.bottom = c->y + ((struct QFrameWindow_80245808 *)this)->height;
  q.y = q.bottom - half;
  q.v = 0.25f;
  q.vBottom = 0.375f;
  q.y = (c->scaleY * (q.y - c->pivotY)) + c->pivotY;
  q.bottom = (c->scaleY * (q.bottom - c->pivotY)) + c->pivotY;
  draw_message_frame_row((Quad_802455CC *)(&q), (Rect_802455CC *)(c));
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
    draw_message_frame_row((Quad_802455CC *)(&q), (Rect_802455CC *)(c));
    rem -= 32.0f;
    q.y += step;
  }
  TWindowSubStatusDisp::get_player();
}
}

#pragma push
#pragma fp_contract on
void TWindowSubComCard__sub_80245A10(u8 *card, s32 row, TWindowKeyBoardSoft *r, f32 len) {
    Lines_80245A10 lines;
    u32 colors[3];
    Vec2_80245A10 pts[3];
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
    lines.f8 = 0;
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
void draw_window_scanlines(u8 *arg0, u8 *arg1) {
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
    n1 = TWindowSubComCard::trunc_float((12.0f + *(f32 *)((s8 *)arg0 + 0x44)) / 4.0f);
    n2 = TWindowSubComCard::trunc_float((*(f32 *)((s8 *)arg0 + 0x4C) - 24.0f) / 4.0f);
    y = ((5.0f * ((f32)lbl_805D63F6 - 0.2f * (f32)n1) - 100.0f) - 12.0f) - *(f32 *)((s8 *)arg0 + 0x40);
    if (y <= 0.0f) {
        return;
    }
    if (y - (f32)n2 >= *(f32 *)((s8 *)arg0 + 0x48) - 24.0f) {
        return;
    }
    set_line_width(12.0f * *(f32 *)((s8 *)arg1 + 0x2C));
    set_additive_blend();
    step = 1.0f;
    for (i = 0; i < n2; i++) {
        TWindowSubComCard__sub_80245A10(arg0, i, (TWindowKeyBoardSoft *)arg1, y);
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

void TUnk_804CE018::draw_window_frame_strips(void *q, void *r) {
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
void TUnk_804CE018::draw_window_frame(void *r) {
  Quad_80245F98 q;
  s32 n;
  f32 h;
  f32 dy;
  f32 rem;
  begin_screen_draw(1);
  TObjFish::set_global_param((s32)((*(void * *)&lbl_805D63F0)));
  set_draw_texture_and_color(1, ((Rect_80245F98 *)r)->f34);
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

void TUnk_804CE018::update_fade() {
    u32 temp_r5;

    temp_r5 = (*(u32 *)((u8 *)this + 0x50));
    if (temp_r5 == 0) {
        ((s32 (*)(void))save_position__13TUnk_804CE018Fv)();
        return;
    }
    *(f32 *)&(*(s32 *)((u8 *)this + 0x40)) += (*(f32 *)&(*(void * *)((u8 *)this + 0x30)) - *(f32 *)&(*(s32 *)((u8 *)this + 0x40))) / (f32) temp_r5;
    *(f32 *)((s8 *)this + 0x44) += (*(f32 *)((s8 *)this + 0x34) - *(f32 *)((s8 *)this + 0x44)) / (f32) (*(u32 *)((u8 *)this + 0x50));
    (*(f32 *)((u8 *)this + 0x48)) += ((*(f32 *)((u8 *)this + 0x38)) - (*(f32 *)((u8 *)this + 0x48))) / (f32) (*(u32 *)((u8 *)this + 0x50));
    *(f32 *)((s8 *)this + 0x4C) += (*(f32 *)((s8 *)this + 0x3C) - *(f32 *)((s8 *)this + 0x4C)) / (f32) (*(u32 *)((u8 *)this + 0x50));
    (*(u32 *)((u8 *)this + 0x50)) = (u32) ((*(u32 *)((u8 *)this + 0x50)) - 1);
}

extern "C" {
s32 rand(void);

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
    s32 temp_r5;

    if ((s32) *(s32 *)&this->m_5c < 0x01000000) {
        card_window_flags = TWindowSubStatusDisp::get_card_window_flags(*(s16 *)&this->m_20);
        card_window_flags += *(s32 *)&this->m_5c;
        *(s32 *)&this->m_5c = card_window_flags + 1;
    }
    temp_r5 = *(s32 *)&this->m_2c;
    if (!(temp_r5 & 2)) {
        if ((temp_r5 & 0x10) && (((s32 (*)(void *))sub_80246948__13TUnk_804CE018Fv)(arg0) != 0)) {
            queue_destruction__7TObjectFv(arg0);
        }
    } else if (temp_r5 & 1) {
        if ((f32) *(s32 *)&this->m_5c >= 7.5f) {
            if (temp_r5 & 4) {
                if (!(temp_r5 & 0x20)) {
                    ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(0x53704, 0U, 0, 0);
                }
                *(s32 *)&this->m_2c = (s32) (*(s32 *)&this->m_2c & ~5);
                return;
            }
            *(s32 *)&this->m_2c = (s32) (temp_r5 & 0xFFFFFFFD);
        }
    } else {
        *(s16 *)((s8 *)arg0 + 0x22) = (s16) (*(s16 *)((s8 *)arg0 + 0x22) + 1);
        if ((f32) *(s16 *)((s8 *)arg0 + 0x22) >= 4.5f) {
            if (*(s32 *)&this->m_2c & 0x10) {
                disallow_rendering__7TObjectFv((TObject *)arg0);
                queue_destruction__7TObjectFv(arg0);
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
            disallow_rendering__7TObjectFv((TObject *)arg0);
        }
    }
}
