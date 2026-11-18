#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#pragma readonly_strings on

extern "C" {

s32 draw_visible_window_entries(s32, s32, s32);
void *get_player_by_client_id(s32 i);
s32 draw_window_tab(s32, s32, s32, f32);

s32 TWindowMeseta::get_meseta_value() {
    TObjPlayer *player = (TObjPlayer *)get_player_by_client_id(this->m_64);
    u8 *stats;

    if (player == NULL) {
        return 0;
    }
    stats = player->get_stats();
    if (stats == NULL) {
        return 0;
    }
    return *(s32 *)(stats + 0x20);
}
void TWindowMeseta::draw_value(s32 arg1) {
    draw_window_tab(arg1, arg1 + 0x10, 3, this->m_60);
}
void TWindowMeseta::render() {
    s32 ctx;
    s32 arg0 = (s32)this;

    ctx = ((TWindowBase *)arg0)->setup_window_draw_context(arg0 + 0x6C);
    ((TWindowMeseta *)arg0)->draw_value(ctx);
    draw_visible_window_entries(arg0, arg0 + 0x24, ctx);
}

}

const char *TWindowMeseta__class_name = "TWindowMeseta";

// inferred: window_meseta_layout_entries, the layout table TWindowMeseta__window_descriptor points at
// (a label and the meseta counter, then an all-zero record).
struct MesetaWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    ValueLayoutRecord rec_1;
    TextLayoutRecord rec_2;
};
MesetaWindowLayout window_meseta_layout_entries = {
    2, 1,
    {3, {10.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
    {5, {152.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 8, 0},
};
WindowDescriptor TWindowMeseta__window_descriptor = {
    {226.0f, 27.0f}, 50100.0f, &window_meseta_layout_entries, 0x82B,
};


struct Sub_80269244 { u8 pad0[8]; f32 x8; };

struct Meseta_80269244 {
    s32 name;
    u8 pad4[0x18 - 0x4];
    s32 *vt;
    u8 pad1c[0x38 - 0x1C];
    f32 x38;
    u8 pad3c[0x48 - 0x3C];
    f32 x48;
    u8 pad4c[0x60 - 0x4C];
    f32 x60;
    s32 x64;
    s32 meseta;
    f32 x6c;
    f32 x70;
};

extern "C" {
s32 get_meseta_value__13TWindowMesetaFv();
extern s32 __vt__13TWindowMeseta[];
extern const char *TWindowMeseta__class_name;
void *TWindowMeseta__ct(void *arg0, s32 arg1, s32 arg2, s32 arg3);


void TWindowMeseta::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = get_meseta_value__13TWindowMesetaFv();
    if (temp_r3 != (s32) this->m_68) {
        this->m_68 = temp_r3;
        ((TWindowSubStatusDisp *)(((TWindowBase *)arg0)->get_array_entry(1)))->set_animated_target(this->m_68, 9.0f);
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

TWindowMeseta::~TWindowMeseta() {}
#define self ((Meseta_80269244 *)arg0)
void *TWindowMeseta__ct(void *arg0, s32 arg1, s32 arg2, s32 str) {
    Sub_80269244 *a;
    Sub_80269244 *b;
    __ct__11TWindowBaseFPUcsPUc(arg0, (u8 *)&TWindowMeseta__window_descriptor, (s16)arg2, (u8 *)arg1);
    self->vt = __vt__13TWindowMeseta;
    self->name = ((s32)TWindowMeseta__class_name);
    self->x64 = arg2;
    self->meseta = ((s32 (*)(void *))get_meseta_value__13TWindowMesetaFv)(arg0);
    a = (Sub_80269244 *)((TWindowBase *)arg0)->get_array_entry(0);
    b = (Sub_80269244 *)((TWindowBase *)arg0)->get_array_entry(1);
    set_text_entry_string((u8 *)a, str, 0);
    ((TWindowSubStatusDisp *)b)->set_all_values(self->meseta);
    self->x38 = 10.0f + b->x8;
    ((TWindowBase *)arg0)->save_position();
    self->x60 = TWindowSubStatusDisp__sub_802877A4(self->x48 - 16.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        self->x6c = 0.75f;
        self->x70 = 0.75f;
    } else {
        self->x6c = 1.0f;
        self->x70 = 1.0f;
    }
    return arg0;
}
#undef self

}
