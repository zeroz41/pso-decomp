#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdScrollWinGC_8026A5F8.h"
#include "pso/unk/text_80076BC4.h"

#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on


const char *TWindowSubLog::class_name = "TWindowSubLog";


const NJS_POINT2 lbl_8044F9C8 = {17.0f, 36.0f};
const u8 lbl_8044F9D0[8] = {67, 151, 128, 0, 67, 204, 0, 0};

void TWindowSubLog::render() {  }

void TWindowSubLog::run_task() {
    ControllerInputContext *context;
    u8 *temp_r3;
    if ((chat->is_mode_bit4() != 0) && (chat_accept_submission((saddr)&submission) != 0)) {
        consume_active_flag(chat);
    }
    if (chat->is_visible() != 0) {
        consume_input_active_flag(chat);
    }
    if (TWindowCtrl__sub_8024701C(chat) != 0) {
        TWindowSubLog__sub_8026A664((u8 *)log_window, 200.0f);
        return;
    }
    TWindowSubLog__sub_8026A664((u8 *)log_window, 408.0f);
    context = &controller_input_state.controllers[0];
    if ((test_previous_buttons_packed(context, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
        fn_8026A61C((u8 *)log_window, -6.0f);
    }
    if ((test_previous_buttons_packed(context, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
        ((TAdScrollWinGC *)log_window)->advance_scroll(6.0f);
    }
    temp_r3 = (u8 *)log_window;
    if ((*(f32 *)((s8 *)temp_r3 + 0x3C) == *(f32 *)((s8 *)temp_r3 + 0x4C)) && ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))) {
        play_sound_effect(0x52F16, 0, 0, 0);
        parent_menu->on_submenu_closed();
        parent_menu->clear_log_active();
    }
}

TWindowSubLog::~TWindowSubLog() {
    if (chat != NULL) { chat->queue_destruction(); this->chat = 0; }
    if (log_window != NULL) { ((TWindowBase *)log_window)->close(); this->log_window = 0; }
    if (parent_menu != NULL) {
        parent_menu->clear_log_active();
        parent_menu->restore_after_subwindow();
    }
    TWindowCtrl::show_client_status_window(client);
}
TWindowSubLog::TWindowSubLog(TObject *parent, s32 client) : TObject(parent) {
    m_name = TWindowSubLog::class_name;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    this->client = client;
    TWindowCtrl::hide_client_status_window(this->client);
    parent_menu->hide_for_subwindow();
    parent_menu->set_log_active();
    log_window = (saddr)create_message_log_window(&lbl_8044F9C8, (saddr)lbl_8044F9D0, (saddr)this->client);
    chat = new TWindowChat((TObject *)this, &submission);
    fn_8027B2A8(chat);
}

void TWindowMainMenu::clear_log_active() { menu_flags &= ~8; }
void TWindowMainMenu::restore_after_subwindow() { show_child_window(); }
void TWindowMainMenu::set_log_active() { menu_flags |= 8; }
void TWindowMainMenu::hide_for_subwindow() { update_trade_submenu(); }
void fn_8027B2A8(void* p) { *(u16*)((char*)p + 0x1e) |= 0x200; }
