#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "types.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80281814.h"
#include "pso/ui/chat/TWindowSubSymbolChat_8028239C.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"
#include "pso/ui/chat/TWindowSubSymbolChat_802838C4.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80283954.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const char *TWindowSubSymbolChat::class_name = "TWindowSubSymbolChat";
static const f32 symbol_chat_window_size[2] = {203.0f, 78.0f};
__declspec(section ".data") f32 lbl_804D2B48[2] = {193.0f, 128.0f};

struct SymbolChatArrowQuad { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct SymbolChatCountView { u8 pad[0x5C]; s32 count; };

struct SymbolChatWindowView { u8 pad[0x24]; s32 ctrl; u8 pad2[0x34 - 0x28]; SymbolChatCountView *sub; };
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 add__16SymbolChatPresetFlllll(int, int, int, int, int, int);
void * TWindowSubSymbolChat::instance;
s8 symbol_chat_color;
s32 symbol_chat_flip_u;
s32 symbol_chat_flip_v;
s32 symbol_chat_mirror_mode;

f32 get_scale__15TWindowCtrlMainFv(s32);

void TWindowSubSymbolChat__sub_80281840(SymbolChatWindowView *window);
s32 TWindowSubComCard__sub_80265660(s32, s32);
s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);

}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
// 0x58-byte record held in symbol_chat_receive_buffer; its compiler-generated operator=
// copies the char array at +4 with __copy and the word array at +0x1C as a block.
struct SymbolChatPresetCopy { s32 value; u8 pad_4[0x17]; u32 pad_1C[0xF]; };

extern s8 symbol_chat_color;
extern s32 symbol_chat_flip_u;
extern s32 symbol_chat_flip_v;
extern s32 symbol_chat_mirror_mode;

extern s32 close_child__20TWindowSubSymbolChatFv[];
}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 TWindowSubSymbolChat::commit(s32 *src) {
    *(SymbolChatPresetCopy *)this = *(const SymbolChatPresetCopy *)src;
    return (saddr)this;
}

void TWindowSubSymbolChat::set_flag_bit1(s32 *flags) {
    *flags |= 1;
}
unsigned char TWindowSubSymbolChat::get_global_4e54() {  return pending_symbol_chat_count; }
void*TWindowSubSymbolChat::get_keyboard_ptr() { return (char*)this + 0x4; }
s32 TWindowSubSymbolChat::calc_remaining_slots() {
    return 0xC - TWindowSubSymbolChat::count_instance_empty_slots();
}

s32 TWindowSubSymbolChat::compute_total_height() {
    s32 remaining;

    s32 layout;
    remaining = TWindowSubSymbolChat::calc_remaining_slots();
    layout = TWindowSubSymbolChat::update_layout();
    return layout + remaining;
}
SymbolChatPreset *get_symbol_chat_receive_buffer(void) {
    return &symbol_chat_receive_buffer;
}

TWindowSubSymbolChat::TWindowSubSymbolChat(TObject *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    client_id = client;
    symbol_window = NULL;
    second_symbol_window = NULL;
    symbol_list = NULL;
    main_menu = NULL;
    face_type_window = NULL;
    parts = NULL;
    parts_set = NULL;
    help_window = NULL;
    confirm_window = NULL;
    option_window = NULL;
    keyboard = NULL;
    selected_preset = NULL;
    symbol_chat_color = 0;
    symbol_chat_flip_u = 0;
    symbol_chat_flip_v = 0;
    selected_list_index = 0;
    TWindowSubSymbolChat::instance = this;
    close_callback = (uaddr)create_callback_at_zero_vec2(close_child);
    selected_value = 0;
}

TWindowSubSymbolChat::~TWindowSubSymbolChat() {
    if (keyboard != 0U) {
        ((TObject *)keyboard)->queue_destruction();
        keyboard = NULL;
    }
    if (option_window != 0U) {
        if ((has_window_task_root() != 0) && (selected_value == 0x27)) {
            selected_preset->set_flag_bit9(option_window->update_selected_item());
        }
        ((TWindowBase *)option_window)->close();
        option_window = NULL;
    }
    if (confirm_window != 0U) {
        confirm_window->close();
        confirm_window = NULL;
    }
    if (help_window != 0U) {
        help_window->close();
        help_window = NULL;
    }
    if (face_type_window != 0U) {
        face_type_window->close();
        face_type_window = NULL;
    }
    if (parts_set != 0U) {
        parts_set->close();
        parts_set = NULL;
    }
    if (parts != 0U) {
        parts->close();
        parts = NULL;
    }
    if (main_menu != 0U) {
        main_menu->close();
        main_menu = NULL;
    }
    if (symbol_list != 0U) {
        symbol_list->close();
        symbol_list = NULL;
    }
    if (second_symbol_window != 0U) {
        second_symbol_window->close();
        second_symbol_window = NULL;
    }
    if (symbol_window != 0U) {
        symbol_window->close();
        symbol_window = NULL;
    }
    if (selected_preset != 0U) {
        selected_preset->clear_flag_bit2();
        selected_preset = NULL;
    }
    if (close_callback != 0U) {
        ((TWindowBase *)close_callback)->close();
        close_callback = 0U;
    }
    TWindowSubSymbolChat::instance = 0;
}

void TWindowSubSymbolChat::run_task() {
    saddr entry_name;
    u8 *window;
    switch (this->selected_value) {
    case 0:
    case 1:
        if ((u32) this->selected_preset != 0U) {
            selected_preset->clear_flag_bit2();
            this->selected_preset = NULL;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = NULL;
        }
        if ((u32) this->main_menu != 0U) {
            this->main_menu->close();
            this->main_menu = NULL;
        }
        if ((void *) this->symbol_window == NULL) {
            this->symbol_window = (TWindowChatSymbol *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 0);
        }
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->symbol_list = create_symbol_list_card();
        this->selected_value = 2U;
    case 2:
        symbol_window->set_from_key((int) (this->symbol_list->get_selected_value()));
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->selected_value = 0x2AU;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            this->selected_list_index = this->symbol_list->get_selected_value();
            TWindowSubSymbolChat::update_symbol_chat_result(this->selected_list_index);
            this->selected_preset = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
            this->selected_preset->update_selected_symbol();
            selected_preset->set_flag_bit2();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 3U;
            return;
        }
        break;
    case 3:
        if ((u32) this->main_menu != 0U) {
            this->main_menu->close();
            this->main_menu = NULL;
        }
    case 4:
        if ((u32) this->keyboard != 0U) {
            ((TObject *)this->keyboard)->queue_destruction();
            this->keyboard = NULL;
        }
        if ((u32) this->option_window != 0U) {
            ((TWindowBase *)this->option_window)->close();
            this->option_window = NULL;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = NULL;
        }
        if ((u32) this->help_window != 0U) {
            this->help_window->close();
            this->help_window = NULL;
        }
        if ((u32) this->parts != 0U) {
            this->parts->close();
            this->parts = NULL;
        }
        if ((u32) this->face_type_window != 0U) {
            this->face_type_window->close();
            this->face_type_window = NULL;
        }
        if ((void *) this->second_symbol_window != NULL) {
            this->second_symbol_window->close();
            this->second_symbol_window = NULL;
        }
        if ((u32) this->symbol_list != 0U) {
            this->symbol_list->close();
            this->symbol_list = NULL;
        }
        if ((void *) this->symbol_window == NULL) {
            this->symbol_window = (TWindowChatSymbol *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 0);
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->set_selection(selected_preset);
        }
        window = (u8 *)this->symbol_window;
        copy_vec2(this->symbol_window->target_position, (void *)((void*)(get_window_layout_position(0x7B))));
        this->symbol_window->tween_ticks = 6;
        if ((u32) this->main_menu == 0U) {
            this->main_menu = TWindowSubSymbolChat::open_main_menu(this);
        }
        ((TWindowMenu *)(this->main_menu))->clear_flag_and_release();
        ((TWindowMenu *)(this->main_menu))->clear_transition_flag();
        this->selected_value = 5U;
    case 5:
        if (((TWindowMenu *)(this->main_menu))->is_cancelled() != 0) {
            this->selected_value = 1U;
            return;
        }
        if (((TWindowMenu *)(this->main_menu))->is_decided() != 0) {
            this->selected_value = this->main_menu->get_selected_value();
            return;
        }
        break;
    case 6:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->help_window != 0U) {
            this->help_window->close();
            this->help_window = NULL;
        }
        if ((u32) this->face_type_window != 0U) {
            this->face_type_window->close();
            this->face_type_window = NULL;
        }
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = open_edit_menu();
        }
        ((TWindowMenu *)(this->symbol_list))->clear_flag_and_release();
        this->selected_value = 7U;
    case 7:
        this->update_sub_window();
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            this->selected_value = this->symbol_list->get_selected_value();
            return;
        }
        break;
    case 8:
        if ((u32) this->face_type_window == 0U) {
            this->face_type_window = new TWindowSubSymbolChatFaceType(get_window_layout_position(0x7D), &symbol_chat_color);
        }
        if ((u32) this->help_window == 0U) {
            this->help_window = new TWindowSubSymbolChatHelp(&symbol_chat_color, &symbol_chat_mirror_mode);
        }
        help_window->set_flag60_bit2();
        this->selected_value = 9U;
    case 9:
        if (this->face_type_window->is_cancelled() != 0) {
            this->selected_value = 6U;
            return;
        }
        if (((TWindowSubSymbolChatFaceType *)(this->face_type_window))->is_open() != 0) {
            this->selected_preset->set_symbol_flags((int) (this->face_type_window->get_face_index()), (int)symbol_chat_color);
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 4U;
            return;
        }
        break;
    case 10:
        if ((u32) this->parts_set != 0U) {
            this->parts_set->close();
            this->parts_set = NULL;
        }
        if ((u32) this->help_window != 0U) {
            this->help_window->close();
            this->help_window = NULL;
        }
        if ((u32) this->parts != 0U) {
            this->parts->close();
            this->parts = NULL;
        }
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = TWindowSubSymbolChat__sub_8028233C((saddr)this);
        }
        ((TWindowMenu *)(this->symbol_list))->clear_flag_and_release();
        this->selected_value = 0xBU;
    case 11:
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            this->symbol_index = 0;
            this->selected_value = this->symbol_list->get_selected_value();
            return;
        }
        break;
    case 12:
        symbol_chat_mirror_mode = 0;
        if ((u32) this->parts_set != 0U) {
            this->parts_set->close();
            this->parts_set = NULL;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            this->parts->init_help(&symbol_chat_mirror_mode);
        }
        this->parts->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = new TWindowSubSymbolChatHelp(&symbol_chat_color, &symbol_chat_mirror_mode);
        }
        if (TWindowSubSymbolChat::count_instance_empty_slots() > 1) {
            help_window->set_flag60_bit1();
        } else {
            clear_help_feature_flag1(help_window);
        }
        help_window->set_pos_and_flag(&symbol_chat_flip_u, &symbol_chat_flip_v);
        this->selected_value = 0xDU;
    case 13:
        if (this->parts->is_cancelled() != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_confirmed() != 0) {
            this->selected_value = 0xEU;
            return;
        }
        break;
    case 14:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            this->parts->close();
            this->parts = NULL;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
            parts_set->init_symbol_layout(&symbol_chat_mirror_mode);
        }
        this->selected_value = 0xFU;
    case 15:
        if (this->parts_set->is_cancelled() != 0) {
            this->selected_value = 0xCU;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            this->add_part_at_cursor();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
                this->selected_value = 0xCU;
                return;
            }
            TWindowSubSymbolChat::open_menu((saddr)this, (s32)this->symbol_list);
            this->selected_value = 0xAU;
            return;
        }
        break;
    case 16:
        symbol_chat_mirror_mode = 0;
        if ((u32) this->parts_set != 0U) {
            this->parts_set->close();
            this->parts_set = NULL;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            this->parts->open(&symbol_chat_color);
        }
        this->parts->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = new TWindowSubSymbolChatHelp(&symbol_chat_color, &symbol_chat_mirror_mode);
        }
        help_window->set_flag60_bit2();
        help_window->set_pos_and_flag(&symbol_chat_flip_u, &symbol_chat_flip_v);
        this->selected_value = 0x11U;
    case 17:
        if (this->parts->is_cancelled() != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_confirmed() != 0) {
            this->selected_value = 0x12U;
            return;
        }
        break;
    case 18:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            this->parts->close();
            this->parts = NULL;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
            parts_set->set_selection_and_refresh(&symbol_chat_color);
        }
        this->selected_value = 0x13U;
    case 19:
        if (this->parts_set->is_cancelled() != 0) {
            this->selected_value = 0x10U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            this->set_face_part_from_cursor();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 0x10U;
            return;
        }
        break;
    case 20:
        if ((u32) this->help_window != 0U) {
            this->help_window->close();
            this->help_window = NULL;
        }
        if ((u32) this->parts != 0U) {
            this->parts->close();
            this->parts = NULL;
        }
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = TWindowSubSymbolChat::create_menu(this);
        }
        ((TWindowMenu *)(this->symbol_list))->clear_flag_and_release();
        this->selected_value = 0x15U;
    case 21:
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            this->symbol_index = 0;
            this->selected_value = this->symbol_list->get_selected_value();
            return;
        }
        break;
    case 22:
    case 26:
        symbol_chat_mirror_mode = 0;
        if ((u32) this->parts_set != 0U) {
            this->parts_set->close();
            this->parts_set = NULL;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            this->parts->update_height();
        }
        this->parts->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = new TWindowSubSymbolChatHelp(&symbol_chat_color, &symbol_chat_mirror_mode);
        }
        help_window->clear_flag60_bit4();
        help_window->clear_flag60_bit2();
        clear_help_feature_flag1(help_window);
        this->selected_value = 0x17U;
    case 23:
    case 27:
        if (this->parts->is_cancelled() != 0) {
            this->selected_value = 0x14U;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_confirmed() != 0) {
            this->update_state();
            return;
        }
        break;
    case 24:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            this->parts->close();
            this->parts = NULL;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
        }
        if (parts_set->select_symbol_chat_record(&symbol_chat_color, &symbol_chat_mirror_mode) != 0) {
            help_window->set_flag60_bit2();
        } else if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
            help_window->set_flag60_bit1();
        }
        help_window->set_pos_and_flag(&symbol_chat_flip_u, &symbol_chat_flip_v);
        this->selected_value = 0x19U;
    case 25:
        if (this->parts_set->is_cancelled() != 0) {
            this->selected_value = 0x16U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            this->draw_selected_entry();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 0x16U;
            return;
        }
        break;
    case 28:
        this->selected_value = 0x1DU;
    case 29:
        this->selected_preset->clear_entries();
        selected_preset->set_flag_bit2();
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->selected_value = 4U;
        return;
    case 30:
        if ((u32) this->symbol_list != 0U) {
            this->symbol_list->close();
            this->symbol_list = NULL;
        }
        if ((u32) this->main_menu != 0U) {
            this->main_menu->close();
            this->main_menu = NULL;
        }
        if ((void *) this->second_symbol_window == NULL) {
            this->second_symbol_window = (TWindowChatSymbol *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 1);
        }
        this->second_symbol_window->m_64 = 1;
        this->symbol_list = create_symbol_list_card();
        apply_symbol();
        this->selected_value = 0x1FU;
    case 31:
        second_symbol_window->set_from_key((int) (this->symbol_list->get_selected_value()));
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            ((TWindowSubSymbolChat *)((saddr) get_symbol_chat_preset(this->symbol_list->get_selected_value())))->commit((s32 *)this->selected_preset);
            this->selected_value = 4U;
            return;
        }
        break;
    case 32:
        this->selected_value = 0x21U;
    case 33:
        ((TWindowSubSymbolChat *)(this->selected_preset))->commit((s32 *)((saddr)get_symbol_chat_receive_buffer()));
        TWindowSubSymbolChat::set_flag_bit1((s32 *)this->selected_preset);
        selected_preset->set_flag_bit2();
        this->selected_preset->set_entry_name((const char *)(TWindowSubStatusDisp::get_message_10(0xB5)));
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->selected_value = 4U;
        return;
    case 34:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = NULL;
        }
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = this->create_menu();
        }
        ((TWindowMenu *)(this->symbol_list))->clear_flag_and_release();
        this->selected_value = 0x23U;
    case 35:
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            TWindowSubSymbolChat::play_symbol_sound((s32)((TWindowMenu *)this->symbol_list)->get_selected_value());
            this->selected_value = 0x24U;
            return;
        }
        break;
    case 36:
        this->confirm_window = this->open_confirm_prompt();
        this->selected_value = 0x25U;
    case 37:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->selected_value = 0x22U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                this->selected_preset->set_symbol_index((int) (this->symbol_list->get_selected_value()));
                this->selected_value = 4U;
                return;
            }
            this->selected_value = 0x22U;
            return;
        }
        break;
    case 38:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->option_window == 0U) {
            this->option_window = this->create_confirm_window();
        }
        this->selected_value = 0x27U;
    case 39:
        if (((TWindowMenuIconLine *)(this->option_window))->is_cancelled() != 0) {
            this->selected_preset->set_flag_bit9((int) (this->option_window->update_selected_item()));
            this->selected_value = 4U;
            return;
        }
        break;
    case 40:
        if ((u32) this->main_menu != 0U) {
            this->main_menu->close();
            this->main_menu = NULL;
        }
        if ((void *) this->symbol_window != NULL) {
            this->symbol_window->close();
            this->symbol_window = NULL;
        }
        this->keyboard = this->create_keyboard_control();
        this->selected_value = 0x29U;
    case 41:
        if (((TKeyBoardControl *)(this->keyboard))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TKeyBoardControl *)(this->keyboard))->is_confirmed() != 0) {
            entry_name = (saddr)((TKeyBoardControl *)(this->keyboard))->realloc_buffer();
            this->selected_preset->set_entry_name((const char *)entry_name);
            mem_free((void *)entry_name);
            this->selected_value = 4U;
        }
        break;
    case 42:
        break;
    }
}

void TWindowSubSymbolChat::render() {  }

saddr TWindowSubSymbolChat::create_chat_symbol_window(s32 unused, s32 index) {
    s32 window_chat_symbol;
    window_chat_symbol = (saddr)new TWindowChatSymbol(((get_window_layout_position(index + 0x7B))), (saddr)symbol_chat_window_size);
    return window_chat_symbol;
}

TWindowMenu *TWindowSubSymbolChat::create_symbol_list_card() {
    s32 i;
    saddr sym;
    TWindowSubComCardList *card;
    s32 data;
    card = (TWindowSubComCardList *)create_titled_window_menu_default(get_window_layout_position(0x77), 0xC, (saddr)TWindowSubStatusDisp::get_message_10(0x31));
    for (i = 0; i < 0xC; i++) {
        sym = (saddr)get_symbol_chat_preset(i);
        data = (saddr)reinterpret_cast<SymbolChatPreset *>(sym)->get_symbol_chat_data();
        if (is_symbol_chat_preset_in_use(reinterpret_cast<const SymbolChatPreset *>(sym)) != 0) {
            card->add_text_entry(data, 0x66, i);
        } else {
            card->add_text_entry(data, 0x46, i);
        }
    }
    card->set_flag70_bit10();
    card->set_scroll_target(2.2e+02f, 188.0f);
    align_menu_entry_positions(card);
    card->set_selected_index(selected_list_index);
    return card;
}

void TWindowSubSymbolChat::apply_symbol() {
    TWindowSubComCard__sub_80265680((TWindowMenu *)this->symbol_list, (s16) this->selected_list_index);
}

TWindowMenu *TWindowSubSymbolChat::open_main_menu(void * _w0) {
    TWindowMenu *menu;

    menu = create_titled_window_menu_default(get_window_layout_position(0x78), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xA8)), 6, 6);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xA9)), 6, 0xA);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAA)), 6, 0x14);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAB)), 6, 0x22);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAC)), 6, 0x26);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAD)), 6, 0x28);
    menu->set_flag70_bit10();
    menu->update_layout_height(193.0f);
    align_menu_entry_positions(menu);
    return menu;
}

TWindowMenu *TWindowSubSymbolChat::open_edit_menu() {
    TWindowMenu *list;

    list = create_titled_window_menu_default(get_window_layout_position(0x79), 3, (saddr)TWindowSubStatusDisp::get_message_10(0xA8));
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB3)), 6, 8);
    if (selected_preset->is_initialized() != 0) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB4)), 6, 0x1E);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB4)), 6, 0x1E);
    }
    if ((s8)TWindowSubSymbolChat::get_global_4e54() > 0) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB5)), 6, 0x20);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB5)), 6, 0x20);
    }
    list->set_flag70_bit10();
    ((TWindowSubComCardList *)list)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(list);
    return list;
}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
TWindowMenu *TWindowSubSymbolChat__sub_8028233C(s32 chat) {
    TWindowMenu *r = create_titled_window_menu_default(get_window_layout_position(0x79), 6, (saddr)TWindowSubStatusDisp::get_message_10(0xA9));
    TWindowSubSymbolChat::open_menu(chat, (saddr)r);
    return r;
}

void TWindowSubSymbolChat::open_menu(s32 chat, saddr list_addr) {
    TWindowSubComCardList *list = (TWindowSubComCardList *)list_addr;
    list->reset_entries();
    if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAE)), 6, 0xC);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xAE)), 6, 0xC);
    }
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAF)), 6, 0x10);
    list->set_flag70_bit10();
    list->set_scroll_target(193.0f, 127.0f);
    align_menu_entry_positions(list);
}

TWindowSubSymbolChatParts *TWindowSubSymbolChat::create_parts() {
    return new TWindowSubSymbolChatParts(
        get_window_layout_position(0x7D),
        &symbol_chat_flip_u, &symbol_chat_flip_v);
}

TWindowSubSymbolChatPartsSet *TWindowSubSymbolChat::create_parts_set() {
    return new TWindowSubSymbolChatPartsSet(
        get_window_layout_position(0x7D), symbol_index,
        &symbol_chat_flip_u, &symbol_chat_flip_v);
}

TWindowMenu *TWindowSubSymbolChat::create_menu(void *window_sub_symbol_chat) {
    TWindowMenu *list;

    list = create_titled_window_menu_default(get_window_layout_position(0x79), 3, (saddr)TWindowSubStatusDisp::get_message_10(0xAA));
    if (TWindowSubSymbolChat::compute_total_height() <= 0) {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB0)), 6, 0x16);
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB1)), 6, 0x1A);
    } else {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB0)), 6, 0x16);
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB1)), 6, 0x1A);
    }
    if (reinterpret_cast<SymbolChatPreset *>(static_cast<TWindowSubSymbolChat *>(window_sub_symbol_chat)->selected_preset)->is_initialized() != 0) {
        list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB2)), 6, 0x1C);
    } else {
        add_gray_text_entry(list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB2)), 6, 0x1C);
    }
    list->set_flag70_bit10();
    ((TWindowSubComCardList *)list)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(list);
    return list;
}

TWindowMenu *TWindowSubSymbolChat::create_menu() {
    TWindowMenu *menu;

    menu = create_titled_window_menu_default(get_window_layout_position(0x79), 9, (saddr)TWindowSubStatusDisp::get_message_10(0xAB));
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB6)), 0x26, 0);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB7)), 0x26, 1);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB8)), 0x26, 2);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB9)), 0x26, 3);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBA)), 0x26, 4);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBB)), 0x26, 5);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBC)), 0x26, 6);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBD)), 0x26, 7);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBE)), 0x26, 8);
    menu->set_flag70_bit10();
    ((TWindowSubComCardList *)menu)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(menu);
    return menu;
}

TWindowMessageYesNo *TWindowSubSymbolChat::open_confirm_prompt() {
    TWindowMessageYesNo *r = (TWindowMessageYesNo *)TWindowMessageYesNo::create((void *)(this), this->client_id, 0, 0);
    open_yes_no_prompt(r, (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x44)), get_window_layout_position(0x7A), 178.0f);
    r->set_choice_menu_flag70_bit10();
    return r;
}

TWindowOptionCtrl *TWindowSubSymbolChat::create_confirm_window() {
    saddr check_box_window;

    check_box_window = (saddr)create_check_box_window_for_local_client(get_window_layout_position(0x79), lbl_804D2B48);
    ((TWindowMenuIconLine *)check_box_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0xAC));
    TWindowOptionCtrl::add_menu_item(check_box_window, (saddr)TWindowSubStatusDisp::get_message_10(0xBF), 1);
    TWindowOptionCtrl::add_menu_item(check_box_window, (saddr)TWindowSubStatusDisp::get_message_10(0xC0), 0);
    if (is_preset_flag_bit9_set(reinterpret_cast<const SymbolChatPreset *>(selected_preset)) != 0) {
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(0);
    } else {
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(1);
    }
    ((TWindowSubShortCutList *)check_box_window)->set_flag70_bit10();
    return (TWindowOptionCtrl *)check_box_window;
}

TKeyBoardControl *TWindowSubSymbolChat::create_keyboard_control() {
    TKeyBoardControl *keyboard;

    keyboard = new TKeyBoardControl(this, 0x90, 1, 4, local_client_id);
    keyboard->set_composer_flag62_bit4();
    keyboard->set_text((char *)((TWindowSubSymbolChat *)this->selected_preset)->get_keyboard_ptr());
    keyboard->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    keyboard->set_flag62_bit2();
    keyboard->set_soft_flag60_bit1();
    return keyboard;
}

void TWindowSubSymbolChat::add_part_at_cursor() {
  s16 cursor_x;
  s16 cursor_pos;
  s32 pos_y;
  cursor_x = parts_set->get_cursor_x();
  cursor_pos = parts_set->get_cursor_pos();
  add__16SymbolChatPresetFlllll((int)this->selected_preset, this->symbol_index, (int) ((s32) cursor_x), (int) ((s32) cursor_pos), (int) (*(s32 *)&symbol_chat_flip_u), (int) (*(s32 *)&symbol_chat_flip_v));
  pos_y = (s32) cursor_pos;
  if (((s32) symbol_chat_mirror_mode) != 0)
  {
    add__16SymbolChatPresetFlllll((int)this->selected_preset, this->symbol_index, (int) (0x40 - cursor_x), (int) pos_y, (int) ((s32) ((u8) ((*(s32 *)&symbol_chat_flip_u) == 0))), (int) (*(s32 *)&symbol_chat_flip_v));
  }
}

void TWindowSubSymbolChat::set_face_part_from_cursor() {
    s16 x;
    s16 y;
    x = parts_set->get_cursor_x();
    y = parts_set->get_cursor_pos();
    this->selected_preset->set_entry_bits(this->symbol_index, symbol_chat_color, x + y * 2, symbol_chat_flip_u, symbol_chat_flip_v);
}

void TWindowSubSymbolChat::draw_selected_entry() {
    SymbolChatPayload *data;
    u8 v;
    s16 y;
    s16 x;
    s32 i;
    s32 n;
    s32 pos;
    saddr inst;
    s32 rem;
    x = parts_set->get_cursor_x();
    y = parts_set->get_cursor_pos();
    inst = TWindowSubSymbolChat::get_instance();
    data = reinterpret_cast<SymbolChatPreset *>(inst)->get_data_ptr();
    rem = TWindowSubSymbolChat::calc_remaining_slots();
    if (rem > this->symbol_index) {
        this->selected_preset->set_entry(this->symbol_index, data->parts[this->symbol_index].id, x, y, symbol_chat_flip_u, symbol_chat_flip_v);
        if (symbol_chat_mirror_mode != 0) {
            this->selected_preset->add(data->parts[this->symbol_index].id, 0x40 - x, y, (u8)(symbol_chat_flip_u == 0), symbol_chat_flip_v);
        }
    } else {
        n = this->symbol_index - rem;
        pos = x + y * 2;
        for (i = 0; i < 4; i++) {
            if (is_facial_part_set(reinterpret_cast<SymbolChatPreset *>(inst), i) != 0 && n-- <= 0) {
                v = data->facial_parts[i];
                clear_facial_part(this->selected_preset, i);
                this->selected_preset->set_entry_bits(v, symbol_chat_color, pos, symbol_chat_flip_u, symbol_chat_flip_v);
                return;
            }
        }
    }
}

void TWindowSubSymbolChat::update_state() {
    s32 selected_menu_value;

    selected_menu_value = this->symbol_list->get_selected_value();
    switch (selected_menu_value) {
    case 22:
        this->selected_value = 0x18;
        return;
    case 26:
        select_symbol_chat_slot((TWindowSubSymbolChatParts *)this->parts);
        this->symbol_window->update_visibility();
        if (TWindowSubSymbolChat::compute_total_height() <= 0) {
            this->selected_value = 4;
            return;
        }
        this->selected_value = 0x14;
        return;
    }
}

void TWindowSubSymbolChat::update_sub_window() {
    TWindowChatSymbol *window_base;
    if (is_card_confirmed() == 0) {
        window_base = this->second_symbol_window;
        if (window_base != NULL) {
            window_base->close();
            this->second_symbol_window = NULL;
            copy_vec2(this->symbol_window->target_position, (void *)((void*)(get_window_layout_position(0x7B))));
            this->symbol_window->tween_ticks = 6;
        }
    } else {
        if (this->second_symbol_window == NULL) {
            this->second_symbol_window = (TWindowChatSymbol *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 0);
            this->second_symbol_window->set_selection(get_symbol_chat_receive_buffer());
            this->second_symbol_window->m_64 = 1;
            copy_vec2(this->symbol_window->target_position, (void *)((void*)(get_window_layout_position(0x7C))));
            this->symbol_window->tween_ticks = 6;
        }
        this->second_symbol_window->update_visibility();
    }
}

s32 TWindowSubSymbolChat::is_card_confirmed() {
    if (this->symbol_list->get_selected_value() != 0x20) {
        return 0;
    }
    s32 temp;
    s32 ret;

    temp = get_cursor_pos__20TWindowShortListCtrlFv((s32)this->symbol_list);
    ret = TWindowSubComCard__sub_80265660((s32)this->symbol_list, temp);
    return ret ? 1 : 0;
}

void TWindowSubSymbolChat__sub_80281840(SymbolChatWindowView *window) {
    SymbolChatArrowQuad q;
    u32 color;
    f32 scale;
    SymbolChatCountView *sub;
    sub = window->sub;
    if (sub != NULL) {
        if (sub->count < 6) {
            color = ((s32)(0.16666667f * (f32)(sub->count * 0xFF)) << 24) | 0xFFFFFF;
        } else {
            color = 0xFFFFFFFF;
        }
        scale = (-1.0f) / get_scale__15TWindowCtrlMainFv(window->ctrl);
        begin_screen_draw(1);
        TObjFish::set_global_param(hud_texlist);
        set_draw_texture_and_color(0, color);
        q.x = 482.0f;
        q.y = 344.0f;
        q.x2 = 14.0f + q.x;
        q.y2 = 12.0f + q.y;
        q.u0 = 0.875f;
        q.v0 = 0.33984375f;
        q.u1 = 0.9296875f;
        q.v1 = 0.38671875f;
        draw_textured_quad_at_depth((f32 *)&q, scale);
        TWindowSubStatusDisp::get_player();
    }
}

void TWindowSubSymbolChat::close_child(void *, void *) {
    void *chat;
    chat = TWindowSubSymbolChat::instance;
    if (chat != NULL) {
        TWindowSubSymbolChat__sub_80281840((SymbolChatWindowView *)(chat));
    }
}
#pragma pop
