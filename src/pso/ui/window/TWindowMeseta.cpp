#include "pso/ui/window/WindowDrawContext.h"
#include "pso/player/PlayerSlots.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#pragma readonly_strings on

extern "C" {


s32 TWindowMeseta::get_meseta_value() {
    TObjPlayer *player = get_player_by_client_id(this->m_64);
    player_stats *stats;

    if (player == NULL) {
        return 0;
    }
    stats = reinterpret_cast<player_stats *>(player->get_stats());
    if (stats == NULL) {
        return 0;
    }
    return stats->meseta;
}
void TWindowMeseta::draw_value(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, 3, m_60);
}
void TWindowMeseta::render() {
    WindowDrawContext *context = setup_window_draw_context(m_6c);
    draw_value(context);
    draw_visible_window_entries(this, &entry_list, context);
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

extern "C" {


void TWindowMeseta::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 meseta_value;

    meseta_value = this->get_meseta_value();
    if (meseta_value != (s32) this->meseta) {
        this->meseta = meseta_value;
        ((TWindowSubStatusDisp *)(((TWindowBase *)arg0)->get_array_entry(1)))->set_animated_target(this->meseta, 9.0f);
    }
    ((TWindowDD *)this)->initialize_subwindow();
    update_window_entry_list(&entry_list);
}

TWindowMeseta::~TWindowMeseta() {}
TWindowMeseta::TWindowMeseta(void *position, s32 arg2, s32 str)
    : TWindowBase((u8 *)&TWindowMeseta__window_descriptor, (s16)arg2, (u8 *)position) {
    Sub_80269244 *a;
    Sub_80269244 *b;
    m_name = TWindowMeseta__class_name;
    m_64 = arg2;
    meseta = this->get_meseta_value();
    a = (Sub_80269244 *)get_array_entry(0);
    b = (Sub_80269244 *)get_array_entry(1);
    set_text_entry_string((u8 *)a, str, 0);
    ((TWindowSubStatusDisp *)b)->set_all_values(meseta);
    target_size[0] = 10.0f + b->x8;
    save_position();
    m_60 = TWindowSubStatusDisp__sub_802877A4(frame_size[0] - 16.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        m_6c[0] = 0.75f;
        m_6c[1] = 0.75f;
    } else {
        m_6c[0] = 1.0f;
        m_6c[1] = 1.0f;
    }
}

}
