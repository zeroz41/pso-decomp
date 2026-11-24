#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowStatus.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_80271400.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/player/PlayerSlots.h"


const char *TWindowStatus__name = "TWindowStatus";

struct Quad_802710C4 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {

s32 TWindowSubComCard__sub_802452DC(int);
s32 TWindowSubComCard__sub_80245320(void *, void *);
s32 TWindowSubComCard__sub_802454E4(int);
void draw_photon_blast_gauge_ring(s32, void *, const f32 *, f32, f32);
void begin_screen_draw(s32 mode);
s32 draw_textured_quad_at_depth(void *, f32);
void set_draw_texture_and_color(s32 idx, s32 color);

s32 draw_right_aligned_number(void *);
void update_hp_tp_values__20TWindowSubStatusDispFPv(u8 *window_sub_status_disp);



saddr get_window_layout_position(s32);

}
void update_status_help_item(saddr arg0);
void set_status_entry_target(void *arg0, s32 arg1);
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
    {6, {27.0f, 16.0f}, {34.0f, 29.0f}, 112.0f, 84.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {124.0f, 67.0f}, 0.5f, 0xFFFFFFFF, 4, NULL},
    {4, {82.0f, 59.0f}, 0.5f, 0xFFFFFFFF, 4, 1},
    {{2, {90.0f, 24.0f}, 0.5f, 0xFF00FF15, 0x20, 120.0f, 0, 0}, 0xFF00CA9E, 0xFFFF2924},
    {{2, {90.0f, 48.0f}, 0.5f, 0xFF008CFC, 0x20, 120.0f, 0, 0}, 0xFF008DEE, 0xFFFF2924},
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


void update_hp_tp_values__20TWindowSubStatusDispFPv(u8 *window_sub_status_disp) {
    u8 *pl;
    u8 *e;
    u8 *a;
    u8 *b;
    u8 *c;
    u8 *d;
    s32 v;
    pl = (u8 *)get_player_by_client_id(((TWindowSimpleStatus *)window_sub_status_disp)->get_width());
    if (pl != NULL) {
        a = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(7);
        b = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(9);
        c = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(6);
        d = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(8);
        *(s32 *)((s8 *)b + 0x20) = ((TObjChara *)pl)->get_hpmax();
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
        a = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(0xB);
        b = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(0xD);
        c = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(0xA);
        d = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(0xC);
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
        e = (u8 *)((TWindowBase *)window_sub_status_disp)->get_array_entry(0xE);
        set_status_entry_target(e, ((TObjPlayer *)pl)->get_photon_blast_charge());
    }
}

void TWindowStatus::draw_background(u8 *ctx) {
    static const f32 pos[2] = {44.0f, 30.5f};
    Quad_802710C4 q;
    f32 w;
    f32 s;

    {
        u8 *e = (u8 *)get_array_entry(0xE);
        draw_photon_blast_gauge_ring((saddr)this, ctx, pos, *(s32 *)((s8 *)e + 0x20), 26.0f);
    }
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xB, *(s32 *)((s8 *)ctx + 0x34));
    { f32 r = get_transition_progress();
    s = -1.0f / (0.0598f + this->draw_depth);
    q.x0 = -(69.0f * (w = 1.0f - r)); }
    q.y0 = -(80.0f * w);
    q.x1 = 69.0f + q.x0;
    q.y1 = 80.0f + q.y0;
    q.u0 = 0.4609375f;
    q.v0 = 0.3125f;
    q.u1 = 0.73046875f;
    q.v1 = 0.625f;
    draw_textured_quad_at_depth(&q, s);
    q.x0 = *(f32 *)((s8 *)ctx + 0);
    q.y0 = *(f32 *)((s8 *)ctx + 4);
    q.x1 = 228.0f + q.x0;
    q.y1 = 76.0f + q.y0;
    q.u0 = 0.0f;
    q.v0 = 0.0f;
    q.u1 = 0.890625f;
    q.v1 = 0.296875f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&q);
    draw_textured_quad_at_depth(&q, s);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, ctx + 0x10, ctx + 0x18) != 0) {
        TWindowSubComCard__sub_802454E4(0xB);
        TWindowSubComCard__sub_80245320(&q, ctx);
        TWindowSubComCard__sub_802452DC(0xB);
    }
}

#pragma fp_contract on
void TWindowStatus::render() {
    saddr entry = reinterpret_cast<saddr>(get_array_entry(0xE));
    saddr ctx;
    draw_right_aligned_number((void *)entry);
    *(f32 *)((s8 *)entry + 8) = 0.5f * *(f32 *)((s8 *)entry + 0x10) + 68.0f;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_background((u8 *)ctx);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(&entry_list),
        reinterpret_cast<WindowDrawContext *>(ctx));
}

void TWindowStatus::run_task() {
    saddr arg0 = (saddr)this;
    ((s32 (*)(void))update_hp_tp_values__20TWindowSubStatusDispFPv)();
    update_lockon_window((u8 *)arg0);
    update_status_help_item(arg0);
    ((TWindowSimpleStatus *)arg0)->update_status_icons((void *)(get_window_layout_position(0x1D)));
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((void *)(arg0 + 0x24)));
}


TWindowStatus::~TWindowStatus() {

}



TWindowStatus::TWindowStatus(void *position, s32 client, u8 *descriptor)
    : TWindowSimpleStatus(position, client, descriptor) {
    m_name = TWindowStatus__name;
}

TWindowSimpleStatus *create_status_window(saddr client) {
    void *position = (void *)get_window_layout_position(0x1C);
    if (is_split_screen() != 0) {
        return TWindowSimpleStatus::create(position, (s32)client);
    }
    return new TWindowStatus(position, (s32)client, (u8 *)&status_window_settings);
}
