#include "types.h"
#include "pso/ui/window/TWindowStatus.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowStatus.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_80271400.h"

struct Quad_802710C4 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {

u8 *get_array_entry__11TWindowBaseFi(void *, s32);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *);
s32 TWindowSubComCard__sub_802452DC(int);
s32 TWindowSubComCard__sub_80245320(void *, void *);
s32 TWindowSubComCard__sub_802454E4(int);
s32 TWindowSubComCard__sub_80245558(void *, void *, void *);
s32 apply_context_transform_to_rect(void *, void *);
void draw_photon_blast_gauge_ring(s32, void *, const f32 *, f32, f32);
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern const f32 lbl_8044F650[];
extern s32 lbl_805D63F0;

s16 obj_getS16_2BA(u8 *p);
u8 *get_player_by_client_id();
s32 get_width__19TWindowSimpleStatusFv();
s32 draw_right_aligned_number(void *);
}
void set_status_entry_target(void *arg0, s32 arg1);
extern "C" {
void update_hp_tp_values__20TWindowSubStatusDispFPv(u8 *arg0);

s32 draw_default_entry__9TWindowDDFl(void *, f32, f32);
s32 draw_visible_window_entries(void *, void *, int);


void *TWindowStatus__ct(void *arg0, s32 layout_pos, void *arg2, const WindowDescriptor *desc);
void *__dt__13TWindowStatusFv(void *arg0, s16 arg1);
void TWindowSimpleStatus__ct(void *, s32, void *, const WindowDescriptor *);
s32 get_window_layout_position(s32);

void __dl__7TObjectFPv(void *);
void __dt__19TWindowSimpleStatusFv(void *, int);
void update_lockon_window(u8 *arg0);
void update_status_help_item(s32 arg0);
extern const f32 lbl_805DD470;
extern const f32 lbl_805DD474;

s32 is_split_screen();
s32 create__19TWindowSimpleStatusFPv(int, void *);
}

#pragma readonly_strings on

struct StatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    LayoutEntryCopyRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    ValueLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    ValueLayoutRecord rec_9;
    TextLayoutRecord rec_10;
    ValueLayoutRecord rec_11;
    TextLayoutRecord rec_12;
    ValueLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
};

StatusWindowLayout lbl_804D0D98 = {
    15, 1,
    {6, {27.0f, 16.0f}, {34.0f, 29.0f}, 112.0f, 84.0f, 0.5f, -1, &lbl_805D63F0, 0, 4},
    {3, {124.0f, 67.0f}, 0.5f, 0xFFFFFFFF, 4, NULL},
    {4, {82.0f, 59.0f}, 0.5f, 0xFFFFFFFF, 4, 1},
    {2, {90.0f, 24.0f}, 0.5f, 0xFF00FF15, 0x20, 120.0f, 0, 0, 0xFF00CA9E, 0xFFFF2924},
    {2, {90.0f, 48.0f}, 0.5f, 0xFF008CFC, 0x20, 120.0f, 0, 0, 0xFF008DEE, 0xFFFF2924},
    {3, {30.0f, 59.0f}, 0.5f, 0xFFFFFFFF, 4, "Lv"},
    {3, {90.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, "HP"},
    {4, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, "/"},
    {4, {210.0f, 9.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {90.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, "TP"},
    {4, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {3, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, "/"},
    {4, {210.0f, 33.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {5, {68.0f, 13.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
};

WindowDescriptor status_window_settings = {
    {228.0f, 76.0f}, 70050.0f, &lbl_804D0D98, 0xB28,
};

extern "C" {

void update_hp_tp_values__20TWindowSubStatusDispFPv(u8 *window_sub_status_disp) {
    u8 *pl;
    u8 *e;
    u8 *a;
    u8 *b;
    u8 *c;
    u8 *d;
    s32 v;
    get_width__19TWindowSimpleStatusFv();
    pl = get_player_by_client_id();
    if (pl != NULL) {
        a = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 7);
        b = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 9);
        c = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 6);
        d = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 8);
        *(s32 *)((s8 *)b + 0x20) = ((TItemProShield *)pl)->get_field_2b8();
        *(s32 *)((s8 *)a + 0x20) = *(s16 *)((s8 *)pl + 0x32C);
        v = ((TWindowSubStatusDisp *)window_sub_status_disp)->update_hp_entry();
        *(s32 *)((s8 *)a + 0x1C) = v;
        *(s32 *)((s8 *)c + 0x24) = v;
        *(s32 *)((s8 *)b + 0x1C) = v;
        *(s32 *)((s8 *)d + 0x24) = v;
        draw_right_aligned_number(b);
        draw_right_aligned_number(a);
        *(f32 *)((s8 *)a + 8) = *(f32 *)((s8 *)b + 8) - *(f32 *)((s8 *)b + 0x10) - 12.0f;
        *(f32 *)((s8 *)d + 8) = *(f32 *)((s8 *)a + 8);
        a = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 0xB);
        b = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 0xD);
        c = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 0xA);
        d = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 0xC);
        *(s32 *)((s8 *)b + 0x20) = obj_getS16_2BA(pl);
        *(s32 *)((s8 *)a + 0x20) = *(s16 *)((s8 *)pl + 0x32E);
        v = ((TWindowSubStatusDisp *)window_sub_status_disp)->update_hp_gauge();
        *(s32 *)((s8 *)a + 0x1C) = v;
        *(s32 *)((s8 *)c + 0x24) = v;
        *(s32 *)((s8 *)b + 0x1C) = v;
        *(s32 *)((s8 *)d + 0x24) = v;
        draw_right_aligned_number(b);
        draw_right_aligned_number(a);
        *(f32 *)((s8 *)a + 8) = *(f32 *)((s8 *)b + 8) - *(f32 *)((s8 *)b + 0x10) - 12.0f;
        *(f32 *)((s8 *)d + 8) = *(f32 *)((s8 *)a + 8);
        ((TWindowSubStatusDisp *)window_sub_status_disp)->update_status_entry();
        e = get_array_entry__11TWindowBaseFi(window_sub_status_disp, 0xE);
        set_status_entry_target(e, ((TObjPlayer *)pl)->get_photon_blast_charge());
    }
}

void TWindowStatus::draw_background(u8 *arg1) {
    Quad_802710C4 q;
    f32 w;
    f32 s;

    {
        u8 *e = get_array_entry__11TWindowBaseFi(this, 0xE);
        draw_photon_blast_gauge_ring((s32)this, arg1, lbl_8044F650, *(s32 *)((s8 *)e + 0x20), 26.0f);
    }
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0xB, *(s32 *)((s8 *)arg1 + 0x34));
    { f32 r = TWindowSubComCard__sub_80244784((TWindowSubComCard *)this);
    s = -1.0f / (0.0598f + this->m_54);
    q.x0 = -(69.0f * (w = 1.0f - r)); }
    q.y0 = -(80.0f * w);
    q.x1 = 69.0f + q.x0;
    q.y1 = 80.0f + q.y0;
    q.u0 = 0.4609375f;
    q.v0 = 0.3125f;
    q.u1 = 0.73046875f;
    q.v1 = 0.625f;
    draw_textured_quad_at_depth(&q, s);
    q.x0 = *(f32 *)((s8 *)arg1 + 0);
    q.y0 = *(f32 *)((s8 *)arg1 + 4);
    q.x1 = 228.0f + q.x0;
    q.y1 = 76.0f + q.y0;
    q.u0 = 0.0f;
    q.v0 = 0.0f;
    q.u1 = 0.890625f;
    q.v1 = 0.296875f;
    apply_context_transform_to_rect(arg1, &q);
    draw_textured_quad_at_depth(&q, s);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(arg1, arg1 + 0x10, arg1 + 0x18) != 0) {
        TWindowSubComCard__sub_802454E4(0xB);
        TWindowSubComCard__sub_80245320(&q, arg1);
        TWindowSubComCard__sub_802452DC(0xB);
    }
}

#pragma fp_contract on
void TWindowStatus::render() {
    u8 *arg0 = (u8 *)this;
  f32 temp_f1;
  u8 *new_var;
  s32 temp_r31;
  f32 new_var2;
  s32 ctx;
  temp_r31 = (s32)get_array_entry__11TWindowBaseFi(arg0, 0xE);
  ((s32 (*)(void))draw_right_aligned_number)();
  new_var2 = (f32) lbl_805DD474;
  new_var = arg0;
  temp_f1 = *((f32 *) (((s8 *) temp_r31) + 0x10));
  *((f32 *) (((s8 *) temp_r31) + 8)) = (f32) ((lbl_805DD474 * temp_f1) + lbl_805DD470);
  ctx = draw_default_entry__9TWindowDDFl((void *) arg0, (f32) temp_f1, new_var2);
  ((TWindowStatus *)arg0)->draw_background((u8 *)ctx);
  draw_visible_window_entries((void *) new_var, (u8 *)&this->m_24, (int) ctx);
}

void TWindowStatus::run_task() {
    s32 arg0 = (s32)this;
    ((s32 (*)(void))update_hp_tp_values__20TWindowSubStatusDispFPv)();
    update_lockon_window((u8 *)arg0);
    update_status_help_item(arg0);
    ((TWindowSimpleStatus *)arg0)->update_status_icons((void *)(get_window_layout_position(0x1D)));
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((void *)(arg0 + 0x24));
}

extern s32 __vt__13TWindowStatus[];

}
TWindowStatus::~TWindowStatus() {

}
extern "C" {

extern void *TWindowStatus__name;

void *TWindowStatus__ct(void *window_status, s32 layout_pos, void *arg2, const WindowDescriptor *desc) {
    TWindowSimpleStatus__ct(window_status, layout_pos, arg2, desc);
    *(s32 **)((s8 *)window_status + 0x18) = __vt__13TWindowStatus;
    *(void * *)&((TWindowStatus *)window_status)->m_name = TWindowStatus__name;
    return window_status;
}
}

s32 create_status_window(s32 arg0) {
    s32 window_layout_position;
    s32 temp_r3;
    s32 var_r0;
    window_layout_position = get_window_layout_position(0x1C);
    if (is_split_screen() != 0) {
        return create__19TWindowSimpleStatusFPv((int)window_layout_position, (void *)arg0);
    }
    temp_r3 = (s32)TObject::operator new(0x78);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (s32)TWindowStatus__ct((void *)temp_r3, window_layout_position, (void *)arg0, &status_window_settings);
    }
    return var_r0;
}
