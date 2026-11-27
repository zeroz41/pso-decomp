#include "pso/ui/window/WindowDrawContext.h"
#include "pso/player/PlayerSlots.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowLayoutNumber.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/WindowLayoutRecord.h"
void TWindowMeseta::set_value(s32 value) {
    meseta = value;
    static_cast<TWindowLayoutCountingNumber *>(get_array_entry(1))->set_all_values((int)meseta);
}

#pragma readonly_strings on



s32 TWindowMeseta::get_meseta_value() {
    TObjPlayer *player = get_player_by_client_id(this->client);
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
    draw_window_tab(context, &context->inner_x, width, 3);
}
void TWindowMeseta::render() {
    WindowDrawContext *context = setup_window_draw_context(draw_scale);
    draw_value(context);
    draw_visible_window_entries(this, &entry_list, context);
}



const char *TWindowMeseta::class_name = "TWindowMeseta";

MesetaWindowLayout window_meseta_layout_entries = {
    2, 1,
    {3, {10.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
    {5, {152.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 8, 0},
};
WindowDescriptor TWindowMeseta::window_descriptor = {
    {226.0f, 27.0f}, 50100.0f, &window_meseta_layout_entries, 0x82B,
};





void TWindowMeseta::run_task() {
    s32 meseta_value;

    meseta_value = this->get_meseta_value();
    if (meseta_value != (s32) this->meseta) {
        this->meseta = meseta_value;
        static_cast<TWindowLayoutCountingNumber *>(this->get_array_entry(1))->set_animated_target(this->meseta, 9.0f);
    }
    update_window();
    update_window_entry_list(&entry_list);
}

TWindowMeseta::~TWindowMeseta() {}
TWindowMeseta::TWindowMeseta(const NJS_POINT2 *position, s32 client, const char *str)
    : TWindowBase((u8 *)&TWindowMeseta::window_descriptor, (s16)client, (u8 *)position) {
    WindowTextEntry *a;
    TWindowLayoutCountingNumber *b;
    m_name = TWindowMeseta::class_name;
    this->client = client;
    meseta = this->get_meseta_value();
    a = (WindowTextEntry *)get_array_entry(0);
    b = static_cast<TWindowLayoutCountingNumber *>(get_array_entry(1));
    set_text_entry_string(a, str, 0);
    b->set_all_values(meseta);
    target_size[0] = 10.0f + b->x;
    save_position();
    width = calc_title_overflow_width(frame_size[0] - 16.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        draw_scale[0] = 0.75f;
        draw_scale[1] = 0.75f;
    } else {
        draw_scale[0] = 1.0f;
        draw_scale[1] = 1.0f;
    }
}

