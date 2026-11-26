#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TJudgmentSequence.h"
#include "pso/ui/window/MesetaWindowCreate.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/city/TShopSequence.h"

#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/WindowLayout.h"

s32 TJudgmentSequence::slot_flags[4];
TJudgmentSequence *judgment_sequence_instance;

#pragma readonly_strings on
void TJudgmentSequence::on_judgment_closed(TShopWindowBase *window) {
    if (window != NULL) {
        window->set_state(4);
    }
}

void on_judgment_item_window_state_8(TShopWindowBase *window) {
    if (window != NULL) {
        window->set_state(4);
    }
}

void TJudgmentSequence::on_judgment_cancelled(TShopWindowBase *window) {
    if (window != NULL) {
        window->send_message(0xD, 1);
        window->set_state(4);
    }
}

void TJudgmentSequence::handle_close_input() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        TShopSequence::close_window();
        queue_destruction();
    }
}

void TJudgmentSequence::open_judgment_window() {
    TShopJudgmentItemWindow *o = new TShopJudgmentItemWindow(tl_05, this, player);
    o->m_16c = on_judgment_item_window_state_8;
    o->on_close = on_judgment_closed;
    o->on_cancel = on_judgment_cancelled;
    set_state(5);
}

void TJudgmentSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        set_state(3);
    }
}

void TJudgmentSequence::setup_counter_camera() {
    NJS_POINT2 pos;
    f32 x;
    pos.x = 332.0f;
    pos.y = 80.0f;
    x = 332.0f;
    create_message_window(get_window_layout_position(0x2C), &pos);
    send_message(1, 1);
    meseta_window = (TWindowBase *)create_meseta_window(((s32)get_player_entity_id()) & 0xFFFF);
    set_state(2);
    counter_camera = set_service_counter_camera(this, 2);
}

void TJudgmentSequence::restore_player_state() { TShopSequence::restore_player_state(); set_state(1); }

void TJudgmentSequence::update_state() {
    switch (state) {
    case 0:
        restore_player_state();
        break;
    case 1:
        setup_counter_camera();
        break;
    case 2:
        handle_confirm();
        break;
    case 3:
        open_judgment_window();
        break;
    case 4:
        handle_close_input();
        break;
    case 5:
        break;
    }
}
TJudgmentSequence::~TJudgmentSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    judgment_sequence_instance = NULL;
    TJudgmentSequence::slot_flags[get_split_screen_slot()] = 0;
}

const char *TJudgmentSequence::class_name = "TJudgmentSequence";

TJudgmentSequence::TJudgmentSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = class_name;
    this->player = player;
    meseta_window = 0;
    counter_camera = NULL;
    judgment_sequence_instance = this;
    set_state(0);
    TJudgmentSequence::slot_flags[get_split_screen_slot()] = 1;
}


void TJudgmentSequence::release_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TJudgmentSequence::slot_flags[i] = 0;
    }
}

void TJudgmentSequence::init_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TJudgmentSequence::slot_flags[i] = 0;
    }
}

void TShopWindowBase::send_message(s32 id, s32 flags) {  }
