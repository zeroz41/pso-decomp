#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubLog.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMessageLog.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdScrollWinGC_8026A5F8.h"
#include "pso/unk/text_80076BC4.h"

#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on


const char *TWindowSubLog::class_name = "TWindowSubLog";


const NJS_POINT2 message_log_window_position = {17.0f, 36.0f};
const f32 message_log_window_extent[2] = {303.0f, 408.0f};

void TWindowSubLog::render() {  }

void TWindowSubLog::run_task() {
    ControllerInputContext *context;
    if ((chat->is_mode_bit4() != 0) && (chat_accept_submission((saddr)&submission) != 0)) {
        consume_active_flag(chat);
    }
    if (chat->is_visible() != 0) {
        consume_input_active_flag(chat);
    }
    if (chat->is_busy() != 0) {
        log_window->set_target_height(200.0f);
        return;
    }
    log_window->set_target_height(408.0f);
    context = &controller_input_state.controllers[0];
    if ((test_previous_buttons_packed(context, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
        log_window->scroll_back(-6.0f);
    }
    if ((test_previous_buttons_packed(context, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
        log_window->advance_scroll(6.0f);
    }
    if ((log_window->target_size[1] == log_window->frame_size[1]) && ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))) {
        play_sound_effect(0x52F16, 0, 0, 0);
        parent_menu->on_submenu_closed();
        parent_menu->clear_log_active();
    }
}

TWindowSubLog::~TWindowSubLog() {
    if (chat != NULL) { chat->queue_destruction(); this->chat = 0; }
    if (log_window != NULL) { log_window->close(); this->log_window = NULL; }
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
    log_window = create_message_log_window(&message_log_window_position, message_log_window_extent, this->client);
    chat = new TWindowChat((TObject *)this, &submission);
    chat->set_flag1e_bit200();
}

void TWindowMainMenu::clear_log_active() { menu_flags &= ~8; }
void TWindowMainMenu::restore_after_subwindow() { show_child_window(); }
void TWindowMainMenu::set_log_active() { menu_flags |= 8; }
void TWindowMainMenu::hide_for_subwindow() { update_trade_submenu(); }
void TWindowChat::set_flag1e_bit200() { flags |= 0x200; }
