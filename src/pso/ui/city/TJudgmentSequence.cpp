#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TJudgmentSequence.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/city/TShopSequence.h"

#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_8022350C.h"

extern "C" {
saddr get_window_layout_position(int, f32);
s32 TJudgmentSequence__slot_flags[4];
TJudgmentSequence *judgment_sequence_instance;
}

#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
struct VBase_18_4a2792
{
  char pad[0x18];
};
struct Stack_80215DA0
{
  f32 sp8;
  f32 spC;
};
void TJudgmentSequence__sub_80215BA0(TShopWindowBase *window) {
    if (window != NULL) {
        window->set_state(4);
    }
}

void TJudgmentSequence__sub_80215BCC(TShopWindowBase *window) {
    if (window != NULL) {
        window->set_state(4);
    }
}

void TJudgmentSequence__sub_80215BF8(TShopWindowBase *window) {
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
    o->m_16c = TJudgmentSequence__sub_80215BCC;
    o->on_close = TJudgmentSequence__sub_80215BA0;
    o->on_cancel = TJudgmentSequence__sub_80215BF8;
    set_state(5);
}

void TJudgmentSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        set_state(3);
    }
}

typedef struct Stack_80215DA0 Stack_80215DA0;
typedef struct VBase_18_4a2792 VBase_18_4a2792;
void TJudgmentSequence::setup_counter_camera() {
    f32 pos[2];
    f32 x;
    pos[0] = 332.0f;
    pos[1] = 80.0f;
    x = 332.0f;
    create_message_window(get_window_layout_position(0x2C, x), (saddr)pos);
    send_message(1, 1);
    m_2c = (TWindowBase *)create_meseta_window(((s32)get_player_entity_id()) & 0xFFFF);
    set_state(2);
    counter_camera = set_service_counter_camera(this, 2);
}

void TJudgmentSequence::restore_player_state() { TShopSequence::restore_player_state(); set_state(1); }

struct Seq_80215CB8;
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
    if (m_2c != NULL) {
        m_2c->close();
        m_2c = NULL;
    }
    judgment_sequence_instance = NULL;
    TJudgmentSequence__slot_flags[get_split_screen_slot()] = 0;
}

const char *TJudgmentSequence__class_name = "TJudgmentSequence";

TJudgmentSequence::TJudgmentSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TJudgmentSequence__class_name;
    this->player = player;
    m_2c = 0;
    counter_camera = NULL;
    judgment_sequence_instance = this;
    set_state(0);
    TJudgmentSequence__slot_flags[get_split_screen_slot()] = 1;
}

extern "C" {

void TJudgmentSequence__sub_80216030(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TJudgmentSequence__slot_flags[i] = 0;
    }
}

void TJudgmentSequence__sub_80216058(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TJudgmentSequence__slot_flags[i] = 0;
    }
}

void TShopWindowBase::send_message(s32 id, s32 flags) {  }
}
