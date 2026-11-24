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
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/unk/text_8024AD30.h"
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
#include "pso/unk/TUnk_804CE7D0.h"

#pragma push
#pragma readonly_strings on
const char *window_chat_type_name_pointer = "TWindowChat";
#pragma pop
extern "C" {
saddr TAdSinglePlyChrSelectGC__sub_80076D9C(saddr arg0, saddr arg1);
int get_chat_shortcut(s32 index);
extern s32 local_client_id;
saddr fn_8002AE08(s32);
void send_chat_shortcut(s32);
saddr get_window_layout_position(int);
s32 TWindowChat__sub_80247D50(TWindowKeyBoardHard *keyboard);
int TWindowChat__sub_80247DAC(void* p);
    extern int chat_help_color_table[];
int TWindowSubSymbolChatHelp__sub_80247EE8(int a0);
s32 TWindowCtrl__sub_8024701C(TWindowChat *w) {
    if (w->composer->sub_8025CB10() != 0) {
        return 1;
    }
    if (!(w->flags & 2)) {
        return 1;
    }
    return TWindowChat__sub_80247D50(w->hardKeyboard) != 0 ? 1 : 0;
}

s32 TWindowChat::sub_80247080() {
    s32 *temp_r31;
    u8 *symbolChatWindow;
    symbolChatWindow = (u8 *)this->symbolChatWindow;
    if (symbolChatWindow == NULL) {
        return 0;
    }
    if (TWindowChat__sub_80247DAC(symbolChatWindow) != 0) {
        this->set_input_active();
        return 1;
    }
    if (((TWindowChat *)(this->symbolChatWindow))->get_subcard_field1c() == 0) {
        return 0;
    }
    this->set_active_flag();
    temp_r31 = (s32 *)((saddr)this->result + 4);
    *temp_r31 = ((TWindowChat *)(this->symbolChatWindow))->forward_card_at_1c();
    if (this->flags & 0x80) {
        TWindowChat::open_symbol_chat((s32 *)temp_r31)->update_selected_symbol();
    }
    return 1;
}

s32 TWindowChat::sub_80247128() {
    s32 mode_code;
    uaddr temp_r3;
    temp_r3 = (uaddr)this->wordSelectWindow;
    if (temp_r3 == 0U) {
        return 0;
    }
    mode_code = ((TWindowDD *)temp_r3)->get_mode_code();
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
    u8 *arg0 = (u8*)this;
    uaddr kb = (uaddr)this->composer;
    if (kb == 0U) {
        return 0;
    }
    if (((TWindowKeyBoardBase *)kb)->is_cancelled() != 0) {
        composer->reset_input();
        ((TWindowChat *)arg0)->set_input_active();
        return 1;
    }
    if (((TWindowKeyBoardBase *)(this->composer))->is_confirmed() == 0) {
        return 0;
    }
    ((TWindowChat *)arg0)->set_active_flag();
    if (composer->get_flag() != 0) {
        TAdSinglePlyChrSelectGC__sub_80076D9C((saddr)this->result, (s32)(get_chat_shortcut((s32)((int) (s8)(composer->get_input_mode())))));
        if (((u32) **(u32 * *)&this->result == 3U) && (((TWindowChat *)arg0)->is_mode_bit6() == 0)) {
            TWindowChat::open_symbol_chat((s32 *)((u8 *) this->result + 4))->update_selected_symbol();
        }
    } else {
        ((TWindowKeyBoardBase *)this->composer)->export_text((char *)this->result + 4);
    }
    composer->reset_input();
    return 1;
}

void TWindowChat::update() {
    saddr player;
    if (is_open() == 0) {
        this->flags = (u16) (this->flags | 1);
        TWindowChat__sub_80247E50(this);
        TWindowChat__sub_80247DFC(this);
        player = (saddr)get_player_by_client_id(local_client_id);
        if ((player != 0) && !(this->flags & 2) && (is_mode_bit6() != 0)) {
            if (TWindowCtrl::has_player_active_menu(local_client_id) == 0) {
                ((TObjPlayer *)player)->init_parts();
            }
            end_player_keyboard_hold(local_client_id);
        }
        composer->reset_input();
        this->close_all_children();
        hardKeyboard->set_flag60_bit200();
    }
}

void TWindowChat::open_input() {
    void *arg0 = this;
    if (((TWindowChat *)arg0)->is_open() != 0) {
        TWindowChat__sub_80247E50(this);
        TWindowChat__sub_80247DFC(this);
        ((TWindowChat *)arg0)->flags = (u16) (((TWindowChat *)arg0)->flags & 0xFFFE);
        ((TWindowChat *)arg0)->flags = (u16) (((TWindowChat *)arg0)->flags | 2);
        hardKeyboard->clear_flag60_bit200();
        ((TWindowChat*)(arg0))->open_next_input_window();
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
    if (test_previous_buttons_packed(pad, fn_8002AE08(local_client_id)) == 0) {
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
    hardKeyboard->sub_8025EC04();
    if (symbolChatWindow != NULL) {
        static_cast<TObject *>(symbolChatWindow)->queue_destruction();
        symbolChatWindow = NULL;
    }
    if (wordSelectWindow != NULL) {
        static_cast<TObject *>(wordSelectWindow)->queue_destruction();
        wordSelectWindow = NULL;
    }
    if (auxiliaryWindow != NULL) {
        static_cast<TWindowBase *>(auxiliaryWindow)->close();
        auxiliaryWindow = NULL;
    }
    if (softKeyboard != NULL) {
        softKeyboard->TWindowBase::close();
        softKeyboard = NULL;
    }
}

void TWindowChat::handle_input() {
    saddr player;
    player = (saddr)get_player_by_client_id(local_client_id);
    if (player != 0) {
        if (this->flags & 2) {
            this->handle_dpad_shortcuts();
            if (this->submit_keyboard_input() != 0) {
                this->close_all_children();
            }
        } else {
            switch ((s8) this->inputMode) {
            case 0:
                if ((this->submit_keyboard_input() != 0) && (sub_80247EC0() != 0)) {
                    if (is_mode_bit6() != 0) {
                        ((TObjPlayer *)player)->init_parts();
                        end_player_keyboard_hold(local_client_id);
                    }
                    this->close_all_children();
                    this->flags = (u16) (this->flags | 2);
                    return;
                }
                break;
            case 1:
                if ((sub_80247128() != 0) && (sub_80247EC0() != 0)) {
                    if (is_mode_bit6() != 0) {
                        ((TObjPlayer *)player)->init_parts();
                        end_player_keyboard_hold(local_client_id);
                    }
                    this->close_all_children();
                    this->flags = (u16) (this->flags | 2);
                    return;
                }
                break;
            case 2:
                if ((sub_80247080() != 0) && (sub_80247EC0() != 0)) {
                    if (is_mode_bit6() != 0) {
                        ((TObjPlayer *)player)->init_parts();
                        end_player_keyboard_hold(local_client_id);
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
  u8 temp_r3_2;
  ControllerInputContext *context;
  saddr player;
  player = (saddr)get_player_by_client_id((saddr)local_client_id);
  if (player != 0)
  {
    if (flags & 2)
    {
      context = &controller_input_state.controllers[0];
      if ((test_pressed_buttons_packed((void *)((void *) context), 0x200) != 0) && (test_previous_buttons_packed((void *)((saddr) context), (saddr)((void *) fn_8002AE08((saddr)(local_client_id)))) == 0))
      {
        flags = (u16) (flags & 0xFFFFFFFD);
        close_all_children();
        open_next_input_window();
        if (is_mode_bit6() != 0)
        {
          begin_player_keyboard_hold(local_client_id);
          ((TObjPlayer *)player)->reset_equip_slots();
        }
      }
    }
    else
      if ((hardKeyboard->is_key_held() == 0) || ((sub_80247EC0() != 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0)))
    {
      if ((sub_80247EC0() != 0) && (test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x200) != 0))
      {
        composer->reset_input();
      }
      close_all_children();
      flags = (u16) (flags | 2);
      open_next_input_window();
      if (is_mode_bit6() != 0)
      {
        ((TObjPlayer *)player)->init_parts();
        end_player_keyboard_hold((saddr)local_client_id);
      }
    }
    else
      if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) && (composer->sub_8025CB10() == 0))
    {
      close_all_children();
      inputMode = (u8) (inputMode + 1);
      temp_r3_2 = inputMode;
      if (((s8) temp_r3_2) >= 3)
      {
        inputMode = (temp_r3_2 - 3);
      }
      open_next_input_window();
    }
  }
}

void TWindowChat::open_next_input_window() {
    if (flags & 2) {
        *static_cast<s32 *>(result) = 1;
        copy_vec2(composer->target_position, reinterpret_cast<void *>(get_window_layout_position(0xB7)));
        composer->tween_ticks = 3;
        return;
    }
    switch (static_cast<s8>(inputMode)) {
    case 0:
        *static_cast<s32 *>(result) = 1;
        softKeyboard = new TWindowKeyBoardSoft(composer, local_client_id);
        softKeyboard->set_flag60_bit1();
        copy_vec2(composer->target_position, reinterpret_cast<void *>(get_window_layout_position(0xB8)));
        composer->tween_ticks = 3;
        hardKeyboard->sub_8025EC04();
        return;
    case 1: {
        composer->reset_input();
        *static_cast<s32 *>(result) = 2;
        wordSelectWindow = new TWindowDD(this, static_cast<s32 *>(result) + 1);
        hardKeyboard->sub_8025EC04();
        return;
    }
    case 2:
        composer->reset_input();
        *static_cast<s32 *>(result) = 3;
        symbolChatWindow = new TUnk_804CE7D0(this);
        hardKeyboard->sub_8025EC04();
        return;
    }
}

void TWindowChat::render() {  }

void TWindowChat::run_task() {
    u8 *arg0 = (u8*)this;
    if ((((int)((TWindowChat *)arg0)->is_open()) == 0) && (((TWindowChat *)arg0)->is_mode_bit4() == 0) && (((TWindowChat *)arg0)->is_visible() == 0)) {
        ((TWindowChat *)arg0)->handle_chat_input();
        ((TWindowChat *)arg0)->handle_input();
        if (composer->sub_8025CB10() != 0) {
            flags = (u16) (flags | 4);
            return;
        }
        flags = (u16) (flags & 0xFFFFFFFB);
    }
}

TWindowChat::~TWindowChat() {
    saddr player;
    player = (saddr)get_player_by_client_id(local_client_id);
    if (player != 0) {
        if (!(this->flags & 2)) {
            if (this->is_mode_bit6() != 0) {
                ((TObjPlayer *)player)->init_parts();
                end_player_keyboard_hold(local_client_id);
            }
        }
    }
    if ((u32) *(u32 *)((s8 *)this + 0x30) != 0U) {
        ((TObject *)this->symbolChatWindow)->queue_destruction();
        *(u32 *)((s8 *)this + 0x30) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x34) != 0U) {
        ((TObject *)this->wordSelectWindow)->queue_destruction();
        *(u32 *)((s8 *)this + 0x34) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x2C) != 0U) {
        ((TWindowBase *)this->auxiliaryWindow)->close();
        *(u32 *)((s8 *)this + 0x2C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x24) != 0U) {
        ((TWindowBase *)this->softKeyboard)->close();
        *(u32 *)((s8 *)this + 0x24) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x28) != 0U) {
        ((TWindowBase *)this->hardKeyboard)->close();
        *(u32 *)((s8 *)this + 0x28) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x20) != 0U) {
        ((TWindowBase *)this->composer)->close();
        *(u32 *)((s8 *)this + 0x20) = 0U;
    }
}
TWindowChat::TWindowChat(TObject *object, void *arg2) : TObject(object) {
    m_name = window_chat_type_name_pointer;
    this->inputMode = 0;
    this->flags = 2;
    this->composer = new TWindowKeyBoardBase;
    composer->init_keyboard_text_field(200, 2);
    this->hardKeyboard = new TWindowKeyBoardHard(composer);
    *(u32 *)((s8 *)this + 0x24) = 0;
    *(u32 *)((s8 *)this + 0x2C) = 0;
    *(u32 *)((s8 *)this + 0x34) = 0;
    *(u32 *)((s8 *)this + 0x30) = 0;
    this->result = arg2;
    this->open_next_input_window();
}

void TWindowKeyBoardBase::set_flag62_bit4() { m_62 |= 0x4; }

u8 TWindowKeyBoardBase::get_input_mode() { return m_65; }

int TWindowKeyBoardBase::get_flag() { return (m_60 >> 6) & 1; }

s32 TWindowChat__sub_80247D50(TWindowKeyBoardHard *keyboard) {
    return static_cast<s32>(keyboard->m_68) > 0;
}

int TWindowChat::forward_card_at_1c() { return ((TWindowMenu *)(*(void**)((char*)this + 0x1c)))->get_selected_value(); }

int TWindowChat::get_subcard_field1c() { return ((TWindowMenu *)(*(void**)((char*)this + 0x1c)))->is_decided(); }

int TWindowChat__sub_80247DAC(void* p) { return ((TWindowMenu *)(*(void**)((char*)p + 0x1c)))->is_cancelled(); }

void TWindowChat::set_active_flag() { this->flags |= 0x10; }

void TWindowChat::set_input_active() { this->flags |= 0x20; }

int TWindowChat::is_mode_bit6() { return (this->flags >> 6) & 0x1; }

void TWindowChat__sub_80247DFC(TWindowChat *window_chat) {
    if (window_chat->is_visible() != 0) {
        window_chat->flags = (u16) (window_chat->flags & 0xFFFFFFDF);
        window_chat->open_next_input_window();
    }
}

int TWindowChat::is_visible() { return (this->flags >> 5) & 0x1; }

void TWindowChat__sub_80247E50(TWindowChat *window_chat) {
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

s32 TWindowChat::sub_80247EC0() {
    return (u8) ((this->flags & 0x240) != 0);
}

void TWindowKeyBoardSoft::set_flag60_bit1() { m_60 |= 0x2; }

int TWindowSubSymbolChatHelp__sub_80247EE8(int a0) {  return chat_help_color_table[a0]; }
