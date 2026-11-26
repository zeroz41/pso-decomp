#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowMenu.h"
#include "types.h"


#include <stddef.h>
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubShortCut.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/TSymbolChatMenu.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/chat/ChatShortcuts.h"

#pragma push
#pragma readonly_strings on
const char *TWindowChat::class_name = "TWindowChat";
#pragma pop
extern "C" {
s32 TWindowChat::is_chat_in_use() {
    if (composer->has_text() != 0) {
        return 1;
    }
    if (!(flags & 2)) {
        return 1;
    }
    return hardKeyboard->is_status_text_shown() != 0 ? 1 : 0;
}

s32 TWindowChat::update_symbol_chat_window() {
    s32 *preset_index;
    if (this->symbolChatWindow == NULL) {
        return 0;
    }
    if (this->symbolChatWindow->is_cancelled() != 0) {
        this->set_input_active();
        return 1;
    }
    if (this->symbolChatWindow->is_decided() == 0) {
        return 0;
    }
    this->set_active_flag();
    preset_index = (s32 *)this->result->body.bytes;
    *preset_index = this->symbolChatWindow->get_selected_index();
    if (this->flags & 0x80) {
        TWindowChat::open_symbol_chat(preset_index)->update_selected_symbol();
    }
    return 1;
}

s32 TWindowChat::update_word_select_window() {
    s32 mode_code;
    TWindowDD *word_window;
    word_window = this->wordSelectWindow;
    if (word_window == NULL) {
        return 0;
    }
    mode_code = word_window->get_mode_code();
    if (mode_code == 0) {
        return 0;
    }
    if (mode_code == 2) {
        this->set_input_active();
        return 1;
    }
    if (mode_code != 1) {
        return 0;
    }
    this->set_active_flag();
    return 1;
}

}

s32 TWindowChat::submit_keyboard_input() {
    uaddr kb = (uaddr)this->composer;
    if (kb == 0U) {
        return 0;
    }
    if (((TWindowKeyBoardBase *)kb)->is_cancelled() != 0) {
        composer->reset_input();
        this->set_input_active();
        return 1;
    }
    if (this->composer->is_confirmed() == 0) {
        return 0;
    }
    this->set_active_flag();
    if (composer->get_flag() != 0) {
        *this->result = *get_chat_shortcut((s8)composer->get_input_mode());
        if ((this->result->kind.value == 3U) && (this->is_mode_bit6() == 0)) {
            TWindowChat::open_symbol_chat((s32 *)this->result->body.bytes)->update_selected_symbol();
        }
    } else {
        this->composer->export_text((char *)this->result->body.bytes);
    }
    composer->reset_input();
    return 1;
}

void TWindowChat::update() {
    TObjPlayer *player;
    if (is_open() == 0) {
        this->flags = (u16) (this->flags | 1);
        consume_active_flag(this);
        consume_input_active_flag(this);
        player = get_player_by_client_id(local_client_id);
        if ((player != NULL) && !(this->flags & 2) && (is_mode_bit6() != 0)) {
            if (TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
                player->init_parts();
            }
            TWindowCtrl::end_client_keyboard_hold(local_client_id);
        }
        composer->reset_input();
        this->close_all_children();
        hardKeyboard->set_flag60_bit200();
    }
}

void TWindowChat::open_input() {
    if (is_open() != 0) {
        consume_active_flag(this);
        consume_input_active_flag(this);
        flags = (u16) (flags & 0xFFFE);
        flags = (u16) (flags | 2);
        hardKeyboard->clear_flag60_bit200();
        open_next_input_window();
    }
}

void TWindowChat::handle_dpad_shortcuts() {
    void *pad;
    if (flags & 8) {
        return;
    }
    pad = &controller_input_state.controllers[0];
    if (test_pressed_buttons_packed(pad, 0xF0) == 0) {
        return;
    }
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        return;
    }
    if (player->is_controls_locked() != 0) {
        return;
    }
    if (test_previous_buttons_packed(pad, get_control_button_mask(local_client_id)) == 0) {
        if (test_pressed_buttons_packed(pad, 0x10) != 0) {
            send_chat_shortcut(0);
        }
        if (test_pressed_buttons_packed(pad, 0x20) != 0) {
            send_chat_shortcut(3);
        }
        if (test_pressed_buttons_packed(pad, 0x80) != 0) {
            send_chat_shortcut(1);
        }
        if (test_pressed_buttons_packed(pad, 0x40) != 0) {
            send_chat_shortcut(2);
        }
    } else {
        if (test_pressed_buttons_packed(pad, 0x10) != 0) {
            send_chat_shortcut(4);
        }
        if (test_pressed_buttons_packed(pad, 0x20) != 0) {
            send_chat_shortcut(7);
        }
        if (test_pressed_buttons_packed(pad, 0x80) != 0) {
            send_chat_shortcut(5);
        }
        if (test_pressed_buttons_packed(pad, 0x40) != 0) {
            send_chat_shortcut(6);
        }
    }
}

void TWindowChat::close_all_children() {
    hardKeyboard->reset_status_text();
    if (symbolChatWindow != NULL) {
        symbolChatWindow->queue_destruction();
        symbolChatWindow = NULL;
    }
    if (wordSelectWindow != NULL) {
        wordSelectWindow->queue_destruction();
        wordSelectWindow = NULL;
    }
    if (auxiliaryWindow != NULL) {
        auxiliaryWindow->close();
        auxiliaryWindow = NULL;
    }
    if (softKeyboard != NULL) {
        softKeyboard->TWindowBase::close();
        softKeyboard = NULL;
    }
}

void TWindowChat::handle_input() {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != 0) {
        if (this->flags & 2) {
            this->handle_dpad_shortcuts();
            if (this->submit_keyboard_input() != 0) {
                this->close_all_children();
            }
        } else {
            switch ((s8) this->inputMode) {
            case 0:
                if ((this->submit_keyboard_input() != 0) && (closes_after_send() != 0)) {
                    if (is_mode_bit6() != 0) {
                        player->init_parts();
                        TWindowCtrl::end_client_keyboard_hold(local_client_id);
                    }
                    this->close_all_children();
                    this->flags = (u16) (this->flags | 2);
                    return;
                }
                break;
            case 1:
                if ((update_word_select_window() != 0) && (closes_after_send() != 0)) {
                    if (is_mode_bit6() != 0) {
                        player->init_parts();
                        TWindowCtrl::end_client_keyboard_hold(local_client_id);
                    }
                    this->close_all_children();
                    this->flags = (u16) (this->flags | 2);
                    return;
                }
                break;
            case 2:
                if ((update_symbol_chat_window() != 0) && (closes_after_send() != 0)) {
                    if (is_mode_bit6() != 0) {
                        player->init_parts();
                        TWindowCtrl::end_client_keyboard_hold(local_client_id);
                    }
                    this->close_all_children();
                    this->flags = (u16) (this->flags | 2);
                }
                break;
            }
        }
    }
}

void TWindowChat::handle_chat_input() {
  u8 mode;
  ControllerInputContext *context;
  TObjPlayer *player;
  player = get_player_by_client_id((saddr)local_client_id);
  if (player != 0)
  {
    if (flags & 2)
    {
      context = &controller_input_state.controllers[0];
      if ((test_pressed_buttons_packed(((void *) context), 0x200) != 0) && (test_previous_buttons_packed((context), get_control_button_mask(local_client_id)) == 0))
      {
        flags = (u16) (flags & 0xFFFFFFFD);
        close_all_children();
        open_next_input_window();
        if (is_mode_bit6() != 0)
        {
          TWindowCtrl::begin_client_keyboard_hold(local_client_id);
          player->reset_equip_slots();
        }
      }
    }
    else
      if ((hardKeyboard->is_key_held() == 0) || ((closes_after_send() != 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0)))
    {
      if ((closes_after_send() != 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0))
      {
        composer->reset_input();
      }
      close_all_children();
      flags = (u16) (flags | 2);
      open_next_input_window();
      if (is_mode_bit6() != 0)
      {
        player->init_parts();
        TWindowCtrl::end_client_keyboard_hold(local_client_id);
      }
    }
    else
      if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) && (composer->has_text() == 0))
    {
      close_all_children();
      inputMode = (inputMode + 1);
      mode = inputMode;
      if (((s8) mode) >= 3)
      {
        inputMode = (mode - 3);
      }
      open_next_input_window();
    }
  }
}

void TWindowChat::open_next_input_window() {
    if (flags & 2) {
        result->kind.value = 1;
        copy_vec2(composer->target_position, (void *)(get_window_layout_position(0xB7)));
        composer->tween_ticks = 3;
        return;
    }
    switch (static_cast<s8>(inputMode)) {
    case 0:
        result->kind.value = 1;
        softKeyboard = new TWindowKeyBoardSoft(composer, local_client_id);
        softKeyboard->set_flag60_bit1();
        copy_vec2(composer->target_position, (void *)(get_window_layout_position(0xB8)));
        composer->tween_ticks = 3;
        hardKeyboard->reset_status_text();
        return;
    case 1: {
        composer->reset_input();
        result->kind.value = 2;
        wordSelectWindow = new TWindowDD(this, reinterpret_cast<WordSelectMessage *>(result->body.bytes));
        hardKeyboard->reset_status_text();
        return;
    }
    case 2:
        composer->reset_input();
        result->kind.value = 3;
        symbolChatWindow = new TSymbolChatMenu(this);
        hardKeyboard->reset_status_text();
        return;
    }
}

void TWindowChat::render() {  }

void TWindowChat::run_task() {
    if ((((int)this->is_open()) == 0) && (this->is_mode_bit4() == 0) && (this->is_visible() == 0)) {
        this->handle_chat_input();
        this->handle_input();
        if (composer->has_text() != 0) {
            flags = (u16) (flags | 4);
            return;
        }
        flags = (u16) (flags & 0xFFFFFFFB);
    }
}

TWindowChat::~TWindowChat() {
    TObjPlayer *player;
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        if (!(this->flags & 2)) {
            if (this->is_mode_bit6() != 0) {
                player->init_parts();
                TWindowCtrl::end_client_keyboard_hold(local_client_id);
            }
        }
    }
    if (symbolChatWindow != NULL) {
        this->symbolChatWindow->queue_destruction();
        symbolChatWindow = NULL;
    }
    if (wordSelectWindow != NULL) {
        this->wordSelectWindow->queue_destruction();
        wordSelectWindow = NULL;
    }
    if (auxiliaryWindow != NULL) {
        this->auxiliaryWindow->close();
        auxiliaryWindow = NULL;
    }
    if (softKeyboard != NULL) {
        this->softKeyboard->close();
        softKeyboard = NULL;
    }
    if (hardKeyboard != NULL) {
        this->hardKeyboard->close();
        hardKeyboard = NULL;
    }
    if (composer != NULL) {
        this->composer->close();
        composer = NULL;
    }
}
TWindowChat::TWindowChat(TObject *object, void *result) : TObject(object) {
    m_name = class_name;
    this->inputMode = 0;
    this->flags = 2;
    this->composer = new TWindowKeyBoardBase;
    composer->init_keyboard_text_field(200, 2);
    this->hardKeyboard = new TWindowKeyBoardHard(composer);
    softKeyboard = NULL;
    auxiliaryWindow = NULL;
    wordSelectWindow = NULL;
    symbolChatWindow = NULL;
    this->result = static_cast<ChatShortcut *>(result);
    this->open_next_input_window();
}

void TWindowKeyBoardBase::set_flag62_bit4() { request_flags |= 0x4; }

u8 TWindowKeyBoardBase::get_input_mode() { return active_input_mode; }

int TWindowKeyBoardBase::get_flag() { return (state_flags >> 6) & 1; }

s32 TWindowKeyBoardHard::is_status_text_shown() {
    return mode_label_timer > 0;
}

int TSymbolChatMenu::get_selected_index() { return preset_list->get_selected_value(); }

int TSymbolChatMenu::is_decided() { return preset_list->is_decided(); }

int TSymbolChatMenu::is_cancelled() { return preset_list->is_cancelled(); }

void TWindowChat::set_active_flag() { this->flags |= 0x10; }

void TWindowChat::set_input_active() { this->flags |= 0x20; }

int TWindowChat::is_mode_bit6() { return (this->flags >> 6) & 0x1; }

void consume_input_active_flag(TWindowChat *window_chat) {
    if (window_chat->is_visible() != 0) {
        window_chat->flags = (u16) (window_chat->flags & 0xFFFFFFDF);
        window_chat->open_next_input_window();
    }
}

int TWindowChat::is_visible() { return (this->flags >> 5) & 0x1; }

void consume_active_flag(TWindowChat *window_chat) {
    if (window_chat->is_mode_bit4() != 0) {
        window_chat->flags = (u16) (window_chat->flags & 0xFFFFFFEF);
        if (window_chat->composer != NULL) {
            window_chat->composer->flush_if_flagged();
        }
        window_chat->open_next_input_window();
    }
}

int TWindowChat::is_mode_bit4() { return (this->flags >> 4) & 0x1; }

int TWindowChat::is_open() { return this->flags & 0x1; }

s32 TWindowChat::closes_after_send() {
    return (u8) ((this->flags & 0x240) != 0);
}

void TWindowKeyBoardSoft::set_flag60_bit1() { state_flags |= 0x2; }

