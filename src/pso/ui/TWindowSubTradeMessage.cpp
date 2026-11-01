#include "pso/ui/TWindowSubTradeMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/unk/text_802D298C.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
struct TradeMessageParentBase { u8 base[0x18]; };
struct TradeMessageParentVirtual : TradeMessageParentBase {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
};
struct TradeMessageInput { u8 base[0x20]; u8 buttons[0x30]; };
extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void*,s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void*,s32);
void play_sound_effect(s32,s32,s32,s32);
u8* get_window_layout_position(s32);
TWindowMessage* create__14TWindowMessageFllUls(void*,const f32*,s32,s32);
int append_line__14TWindowMessageFii(void*,const char*,s32);
extern TradeMessageInput controller_input_state[];
__declspec(section ".rodata") extern const char trade_message_class_name[23] = "TWindowSubTradeMessage";
__declspec(section ".rodata") extern const f32 trade_message_window_dimensions[2] = {282.0f,120.0f};
__declspec(section ".sdata") const char* TWindowSubTradeMessage__name[2] = {trade_message_class_name,0};
}

void TWindowSubTradeMessage::finish() {
    ((TradeMessageParentVirtual*)parentWindow)->m7();
    state=2;
}

void TWindowSubTradeMessage::show_message(const char* text) {
    if (messageWindow == 0) messageWindow=create_message_window(text);
    state=1;
}

TWindowMessage* TWindowSubTradeMessage::create_message_window(const char* text) {
    TWindowMessage* window;
    window=create__14TWindowMessageFllUls(get_window_layout_position(0x5B),trade_message_window_dimensions,1,playerIndex);
    append_line__14TWindowMessageFii(window,text,0x82);
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
           test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state[4].buttons,2)!=0) {
            play_sound_effect(0x52F16,0,0,0);
            ((TradeMessageParentVirtual*)parentWindow)->m7();
            state=2;
        }
        break;
    case 2:
        break;
    }
}

TWindowSubTradeMessage::~TWindowSubTradeMessage() {
    TLobby__sub_802D29B8((u32)this);
    if (messageWindow != 0) {
        ((TWindowBase *)messageWindow)->close();
        messageWindow=0;
    }
}

TWindowSubTradeMessage::TWindowSubTradeMessage(TObject* parent, s32 index) : TObject(parent) {
    m_name=TWindowSubTradeMessage__name[0];
    parentWindow=parent;
    playerIndex=index;
    messageWindow=0;
    TLobby__sub_802D29DC((int)this);
    state=0;
}
