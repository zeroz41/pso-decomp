#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/unk/text_8026A93C.h"
#include "pso/ui/window/TWindowCtrl_8024ADAC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdScrollWinGC_8026A5F8.h"
#include "pso/unk/text_80076BC4.h"

#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"

#pragma readonly_strings on


const char *TWindowSubLog__class_name = "TWindowSubLog";


struct Lg_8027B194 { s32 f0; u8 pad4[0x14]; void *vt; void *client_id; void *f20; s32 f24; void *f28; u8 f2c[0x10]; };

extern "C" {
const u8 lbl_8044F9C8[8] = {65, 136, 0, 0, 66, 16, 0, 0};
const u8 lbl_8044F9D0[8] = {67, 151, 128, 0, 67, 204, 0, 0};

void TWindowSubLog::render() {  }

void TWindowSubLog::run_task() {
    u8 *arg0 = (u8 *)this;
    ControllerInputContext *context;
    u8 *temp_r3;
    if ((((TWindowChat *)(this->chat))->is_mode_bit4() != 0) && (chat_accept_submission((saddr)(arg0 + 0x2C)) != 0)) {
        TWindowChat__sub_80247E50(reinterpret_cast<TWindowChat *>(this->chat));
    }
    if (((TWindowChat *)(this->chat))->is_visible() != 0) {
        TWindowChat__sub_80247DFC(reinterpret_cast<TWindowChat *>(this->chat));
    }
    if (TWindowCtrl__sub_8024701C(reinterpret_cast<TWindowChat *>(this->chat)) != 0) {
        TWindowSubLog__sub_8026A664((*(u8 * *)&this->m_24), 200.0f);
        return;
    }
    TWindowSubLog__sub_8026A664((*(u8 * *)&this->m_24), 408.0f);
    context = &controller_input_state.controllers[0];
    if ((test_previous_buttons_packed(context, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
        fn_8026A61C((*(u8 * *)&this->m_24), -6.0f);
    }
    if ((test_previous_buttons_packed(context, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
        ((TAdScrollWinGC *)(this->m_24))->advance_scroll(6.0f);
    }
    temp_r3 = (u8 *)this->m_24;
    if ((*(f32 *)((s8 *)temp_r3 + 0x3C) == *(f32 *)((s8 *)temp_r3 + 0x4C)) && ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))) {
        play_sound_effect(0x52F16, 0, 0, 0);
        parent_menu->on_submenu_closed();
        parent_menu->clear_log_active();
    }
}

}
TWindowSubLog::~TWindowSubLog() {
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x28)))->queue_destruction(); this->chat = 0; }
    if (*(void **)((s8 *)this + 0x24) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x24)))->close(); this->m_24 = 0; }
    if (parent_menu != NULL) {
        parent_menu->clear_log_active();
        parent_menu->restore_after_subwindow();
    }
    TWindowCtrl__sub_8024ADF0((saddr)(*(void **)((s8 *)this + 0x1C)));
}
TWindowSubLog::TWindowSubLog(TObject *parent, void *arg2) : TObject(parent) {
    void *w;
    ((Lg_8027B194 *)this)->f0 = ((saddr)TWindowSubLog__class_name);
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    ((Lg_8027B194 *)this)->client_id = arg2;
    TWindowCtrl__sub_8024ADAC((saddr)(((Lg_8027B194 *)this)->client_id));
    parent_menu->hide_for_subwindow();
    parent_menu->set_log_active();
    ((Lg_8027B194 *)this)->f24 = (saddr)create_message_log_window((saddr)lbl_8044F9C8, (saddr)lbl_8044F9D0, (saddr)(((Lg_8027B194 *)this)->client_id));
    w = new TWindowChat((TObject *)((Lg_8027B194 *)this), (void *)((Lg_8027B194 *)this)->f2c);
    ((Lg_8027B194 *)this)->f28 = w;
    fn_8027B2A8((void*)(((Lg_8027B194 *)this)->f28));
}

void TWindowMainMenu::clear_log_active() { m_4c &= ~8; }
void TWindowMainMenu::restore_after_subwindow() { show_child_window(); }
void TWindowMainMenu::set_log_active() { m_4c |= 8; }
void TWindowMainMenu::hide_for_subwindow() { update_trade_submenu(); }
void fn_8027B2A8(void* p) { *(u16*)((char*)p + 0x1e) |= 0x200; }
