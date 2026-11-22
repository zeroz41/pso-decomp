#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubTradeMessage.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_802D298C.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/ui/window/WindowLayout.h"
struct TradeMessageInput { u8 base[0x20]; u8 buttons[0x30]; };
extern "C" {
void play_sound_effect(s32,s32,s32,s32);
extern TradeMessageInput controller_input_state[];
__declspec(section ".rodata") extern const char trade_message_class_name[23] = "TWindowSubTradeMessage";
__declspec(section ".rodata") extern const f32 trade_message_window_dimensions[2] = {282.0f,120.0f};
__declspec(section ".sdata") const char* TWindowSubTradeMessage__name[2] = {trade_message_class_name,0};
}

void TWindowSubTradeMessage::finish() {
    parentWindow->vfunc_9();
    state=2;
}

void TWindowSubTradeMessage::show_message(const char* text) {
    if (messageWindow == 0) messageWindow=create_message_window(text);
    state=1;
}

TWindowMessage* TWindowSubTradeMessage::create_message_window(const char* text) {
    TWindowMessage* window;
    window=(TWindowMessage*)TWindowMessage::create((saddr)get_window_layout_position(0x5B),trade_message_window_dimensions,1,playerIndex);
    ((TWindowMessage *)window)->append_line((saddr)text, (int)0x82);
    return window;
}

void TWindowSubTradeMessage::render() {}

void TWindowSubTradeMessage::run_task() {
    s32 idx=is_player_input_active(playerIndex);
    switch(state) {
    case 0:
        state=1;
    case 1:
        if(TWindowShortListCtrl__check_controller_button(controller_input_state[idx].buttons,2)!=0 ||
           test_controller_flag_4c_color(controller_input_state[4].buttons,2)!=0) {
            play_sound_effect(0x52F16,0,0,0);
            parentWindow->vfunc_9();
            state=2;
        }
        break;
    case 2:
        break;
    }
}

TWindowSubTradeMessage::~TWindowSubTradeMessage() {
    clear_trade_message_controller_if_owner((uaddr)this);
    if (messageWindow != 0) {
        messageWindow->close();
        messageWindow=0;
    }
}

TWindowSubTradeMessage::TWindowSubTradeMessage(TWindowMainMenu *parent, s32 index) : TObject(parent) {
    m_name=TWindowSubTradeMessage__name[0];
    parentWindow=parent;
    playerIndex=index;
    messageWindow=0;
    set_trade_message_controller((saddr)this);
    state=0;
}
