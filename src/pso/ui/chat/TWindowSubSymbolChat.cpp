#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/chat/SymbolChatPreset.h"
#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/ui/chat/TWindowSubSymbolChatParts.h"


s32 TWindowSubSymbolChatFaceType::get_cursor_index() {
    return (s8)cursor_col + (s8)cursor_row * 2;
}

s32 TWindowSubSymbolChatFaceType::is_cancelled() {
    return flags & 2;
}

s32 TWindowSubSymbolChatFaceType::is_open() {
    return this->flags & 1;
}

s32 TWindowSubSymbolChatParts::is_cancelled() {
    return flags & 2;
}

s32 TWindowSubSymbolChatParts::is_active() {
    return this->flags & 1;
}

void TWindowSubSymbolChatHelp::set_flag60_bit2() {
    flags = (u8)(flags | 2);
}

void TWindowSubSymbolChatHelp::set_flag60_bit1() {
    flags = (u8)(flags | 1);
}

void TWindowSubSymbolChatHelp::clear_flag60_bit1() {
    flags &= ~1;
}

void TWindowSubSymbolChatHelp::set_pos_and_flag(s32 *first, s32 *second) {
    m_6c = first;
    m_70 = second;
    flags = (u8)(flags | 4);
}

void TWindowSubSymbolChatHelp::clear_flag60_bit4() {
    flags = (u8)(flags & ~4);
}

void TWindowSubSymbolChatHelp::clear_flag60_bit2() {
    flags = (u8)(flags & ~2);
}

s32 TWindowSubSymbolChatPartsSet::is_cancelled() {
    return flags & 2;
}

s32 TWindowSubSymbolChatPartsSet::is_active() {
    return this->flags & 1;
}

s32 TWindowSubSymbolChatPartsSet::get_cursor_x() {
    return cursor_x;
}

s32 TWindowSubSymbolChatPartsSet::get_cursor_pos() {
    return cursor_y;
}

void SymbolChatPreset::clear_flag_bit2() {
    flags &= 0xFFFFFFFD;
}

void SymbolChatPreset::set_flag_bit2() {
    flags |= 2;
}

#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/chat/TWindowChatSymbol.h"
#include "types.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/chat/TWindowSubSymbolChat_80076F88.h"
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
#include "pso/ui/chat/TWindowSubSymbolChatHelp.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubSymbolChatFaceType.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/ui/window/WindowLayout.h"
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const char *TWindowSubSymbolChat::class_name = "TWindowSubSymbolChat";
static const f32 lbl_8044FB20[2] = {203.0f, 78.0f};
__declspec(section ".data") f32 lbl_804D2B48[2] = {193.0f, 128.0f};


struct Ent_80281B18 { s8 c; u8 pad[3]; };

struct Data_80281B18 { u8 pad0[4]; u16 w[4]; Ent_80281B18 e[1]; };

struct Quad_80281840 { f32 x, y, x2, y2, u0, v0, u1, v1; };

struct Sub_80281840 { u8 pad[0x5C]; s32 count; };

struct Win_80281840 { u8 pad[0x24]; s32 ctrl; u8 pad2[0x34 - 0x28]; Sub_80281840 *sub; };
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 add__20TWindowSubSymbolChatFlllll(int, int, int, int, int, int);
u8 *create_chat_symbol_window__20TWindowSubSymbolChatFll(void *, s32);
void * TWindowSubSymbolChat::instance;
s8 TWindowSubSymbolChat__data_805D6494;
s32 TWindowSubSymbolChat__data_805D6498;
s32 TWindowSubSymbolChat__data_805D649C;
s32 TWindowSubSymbolChat__help_window;

f32 get_scale__15TWindowCtrlMainFv(s32);

void TWindowSubSymbolChat__sub_80281840(Win_80281840 *arg0);
s32 TWindowSubComCard__sub_80265660(s32, s32);

s32 get_cursor_pos__20TWindowShortListCtrlFv(s32);
}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern s32 local_client_id;

struct Win_80282600 { u8 pad[0x20]; s32 sel; };

#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
// 0x58-byte record held in symbol_chat_receive_buffer; its compiler-generated operator= (0x80283850)
// copies the char array at +4 with __copy and the word array at +0x1C as a block.
struct Obj_80283850 { s32 value; u8 pad_4[0x17]; u32 pad_1C[0xF]; };

extern s8 TWindowSubSymbolChat__data_805D6494;
extern s32 TWindowSubSymbolChat__data_805D6498;
extern s32 TWindowSubSymbolChat__data_805D649C;
extern s32 TWindowSubSymbolChat__help_window;
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
s32 update_layout__20TWindowSubSymbolChatFv(void);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 TWindowSubSymbolChat::commit(s32 *src) {
    *(Obj_80283850 *)this = *(const Obj_80283850 *)src;
    return (saddr)this;
}

void TWindowSubSymbolChat::set_flag_bit1(s32 *arg0) {
    *arg0 |= 1;
}
unsigned char TWindowSubSymbolChat::get_global_4e54() {  return pending_symbol_chat_count; }
void*TWindowSubSymbolChat::get_keyboard_ptr() { return (char*)this + 0x4; }
s32 TWindowSubSymbolChat::calc_remaining_slots() {
    return 0xC - TWindowSubSymbolChat::count_instance_empty_slots();
}

s32 TWindowSubSymbolChat::compute_total_height() {
    s32 temp_r31;

    s32 temp_r3;
    temp_r31 = TWindowSubSymbolChat::calc_remaining_slots();
    temp_r3 = update_layout__20TWindowSubSymbolChatFv();
    return temp_r3 + temp_r31;
}
SymbolChatPreset *TWindowSubSymbolChat__sub_8028379C(void) {
    return &symbol_chat_receive_buffer;
}

TWindowSubSymbolChat::TWindowSubSymbolChat(TObject *parent, s32 client) : TObject(parent) {
    m_name = class_name;
    parent_menu = static_cast<TWindowMainMenu *>(parent);
    client_id = client;
    symbol_window = 0;
    second_symbol_window = 0;
    symbol_list = 0;
    main_menu = 0;
    face_type_window = 0;
    parts = 0;
    parts_set = 0;
    help_window = 0;
    confirm_window = 0;
    option_window = 0;
    keyboard = 0;
    selected_preset = 0;
    TWindowSubSymbolChat__data_805D6494 = 0;
    TWindowSubSymbolChat__data_805D6498 = 0;
    TWindowSubSymbolChat__data_805D649C = 0;
    m_20 = 0;
    TWindowSubSymbolChat::instance = this;
    close_callback = (uaddr)create_callback_at_zero_vec2(close_child);
    selected_value = 0;
}

TWindowSubSymbolChat::~TWindowSubSymbolChat() {
    if (keyboard != 0U) {
        ((TObject *)keyboard)->queue_destruction();
        keyboard = 0U;
    }
    if (option_window != NULL) {
        if ((has_window_task_root() != 0) && (selected_value == 0x27)) {
            ((TWindowSubSymbolChat *)selected_preset)->set_flag_bit9(option_window->update_selected_item());
        }
        ((TWindowBase *)option_window)->close();
        option_window = NULL;
    }
    if (confirm_window != 0U) {
        ((TWindowMessageYesNo *)confirm_window)->close();
        confirm_window = 0U;
    }
    if (help_window != 0U) {
        ((TWindowBase *)help_window)->close();
        help_window = 0U;
    }
    if (face_type_window != 0U) {
        ((TWindowBase *)face_type_window)->close();
        face_type_window = 0U;
    }
    if (parts_set != 0U) {
        ((TWindowBase *)parts_set)->close();
        parts_set = 0U;
    }
    if (parts != 0U) {
        ((TWindowBase *)parts)->close();
        parts = 0U;
    }
    if (main_menu != 0U) {
        ((TWindowBase *)main_menu)->close();
        main_menu = 0U;
    }
    if (symbol_list != 0U) {
        ((TWindowBase *)symbol_list)->close();
        symbol_list = 0U;
    }
    if (second_symbol_window != 0U) {
        ((TWindowBase *)second_symbol_window)->close();
        second_symbol_window = 0U;
    }
    if (symbol_window != 0U) {
        ((TWindowBase *)symbol_window)->close();
        symbol_window = 0U;
    }
    if (selected_preset != 0U) {
        reinterpret_cast<SymbolChatPreset *>(selected_preset)->clear_flag_bit2();
        selected_preset = 0U;
    }
    if (close_callback != 0U) {
        ((TWindowBase *)close_callback)->close();
        close_callback = 0U;
    }
    TWindowSubSymbolChat::instance = 0;
}

void TWindowSubSymbolChat::run_task() {
    saddr entry_name;
    u8 *temp_r5;
    switch (this->selected_value) {
    case 0:
    case 1:
        if ((u32) this->selected_preset != 0U) {
            reinterpret_cast<SymbolChatPreset *>(selected_preset)->clear_flag_bit2();
            this->selected_preset = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->symbol_window == NULL) {
            *(u8 * *)&this->symbol_window = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 0));
        }
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->symbol_list = ((u32)create_symbol_list_card());
        this->selected_value = 2U;
    case 2:
        reinterpret_cast<TWindowChatSymbol *>(symbol_window)->set_from_key((int) (((TWindowMenu *)this->symbol_list)->get_selected_value()));
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->selected_value = 0x2AU;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            this->m_20 = ((TWindowMenu *)this->symbol_list)->get_selected_value();
            ((TWindowSubSymbolChat *)(this->m_20))->update_symbol_chat_result();
            this->selected_preset = TWindowSubSymbolChat::get_instance();
            reinterpret_cast<SymbolChatPreset *>(this->selected_preset)->update_selected_symbol();
            reinterpret_cast<SymbolChatPreset *>(selected_preset)->set_flag_bit2();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 3U;
            return;
        }
        break;
    case 3:
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
    case 4:
        if ((u32) this->keyboard != 0U) {
            ((TObject *)this->keyboard)->queue_destruction();
            this->keyboard = 0U;
        }
        if (this->option_window != NULL) {
            ((TWindowBase *)this->option_window)->close();
            this->option_window = NULL;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->help_window != 0U) {
            ((TWindowBase *)this->help_window)->close();
            this->help_window = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        if ((u32) this->face_type_window != 0U) {
            ((TWindowBase *)this->face_type_window)->close();
            this->face_type_window = 0U;
        }
        if ((void *) this->second_symbol_window != NULL) {
            ((TWindowBase *)this->second_symbol_window)->close();
            this->second_symbol_window = NULL;
        }
        if ((u32) this->symbol_list != 0U) {
            ((TWindowBase *)this->symbol_list)->close();
            this->symbol_list = 0U;
        }
        if ((void *) this->symbol_window == NULL) {
            *(u8 * *)&this->symbol_window = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 0));
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->set_selection(reinterpret_cast<SymbolChatPreset *>(selected_preset));
        }
        temp_r5 = (u8 *)this->symbol_window;
        copy_vec2((void *)((this->symbol_window + 0x30)), (void *)((void*)(get_window_layout_position(0x7B))));
        *(s32 *)(this->symbol_window + 0x50) = 6;
        if ((u32) this->main_menu == 0U) {
            this->main_menu = ((u32)TWindowSubSymbolChat::open_main_menu(this));
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
            this->selected_value = ((TWindowMenu *)this->main_menu)->get_selected_value();
            return;
        }
        break;
    case 6:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->help_window != 0U) {
            ((TWindowBase *)this->help_window)->close();
            this->help_window = 0U;
        }
        if ((u32) this->face_type_window != 0U) {
            ((TWindowBase *)this->face_type_window)->close();
            this->face_type_window = 0U;
        }
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = ((u32)open_edit_menu());
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
            this->selected_value = ((TWindowMenu *)this->symbol_list)->get_selected_value();
            return;
        }
        break;
    case 8:
        if ((u32) this->face_type_window == 0U) {
            this->face_type_window = (uaddr)new TWindowSubSymbolChatFaceType(get_window_layout_position(0x7D), &TWindowSubSymbolChat__data_805D6494);
        }
        if ((u32) this->help_window == 0U) {
            this->help_window = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_flag60_bit2();
        this->selected_value = 9U;
    case 9:
        if (((TWindowSubSymbolChatFaceType *)(this->face_type_window))->is_cancelled() != 0) {
            this->selected_value = 6U;
            return;
        }
        if (((TWindowSubSymbolChatFaceType *)(this->face_type_window))->is_open() != 0) {
            ((TWindowSubSymbolChat *)(this->selected_preset))->set_symbol_flags((int) (((TWindowSubSymbolChatFaceType *)(this->face_type_window))->get_cursor_index()), (int)TWindowSubSymbolChat__data_805D6494);
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 4U;
            return;
        }
        break;
    case 10:
        if ((u32) this->parts_set != 0U) {
            ((TWindowBase *)this->parts_set)->close();
            this->parts_set = 0U;
        }
        if ((u32) this->help_window != 0U) {
            ((TWindowBase *)this->help_window)->close();
            this->help_window = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
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
            this->selected_value = ((TWindowMenu *)this->symbol_list)->get_selected_value();
            return;
        }
        break;
    case 12:
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->parts_set != 0U) {
            ((TWindowBase *)this->parts_set)->close();
            this->parts_set = 0U;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            ((TWindowSubSymbolChatParts *)this->parts)->init_help(&TWindowSubSymbolChat__help_window);
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        if (TWindowSubSymbolChat::count_instance_empty_slots() > 1) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_flag60_bit1();
        } else {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->clear_flag60_bit1();
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0xDU;
    case 13:
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_cancelled() != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_active() != 0) {
            this->selected_value = 0xEU;
            return;
        }
        break;
    case 14:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
            reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->init_symbol_layout(&TWindowSubSymbolChat__help_window);
        }
        this->selected_value = 0xFU;
    case 15:
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_cancelled() != 0) {
            this->selected_value = 0xCU;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            this->sub_80281CC4();
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
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->parts_set != 0U) {
            ((TWindowBase *)this->parts_set)->close();
            this->parts_set = 0U;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            ((TWindowSubSymbolChatParts *)this->parts)->open(&TWindowSubSymbolChat__data_805D6494);
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_flag60_bit2();
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0x11U;
    case 17:
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_cancelled() != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_active() != 0) {
            this->selected_value = 0x12U;
            return;
        }
        break;
    case 18:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
            reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->set_selection_and_refresh(&TWindowSubSymbolChat__data_805D6494);
        }
        this->selected_value = 0x13U;
    case 19:
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_cancelled() != 0) {
            this->selected_value = 0x10U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            this->sub_80281C60();
            ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
            this->selected_value = 0x10U;
            return;
        }
        break;
    case 20:
        if ((u32) this->help_window != 0U) {
            ((TWindowBase *)this->help_window)->close();
            this->help_window = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->symbol_list == 0U) {
            this->symbol_list = create_menu__20TWindowSubSymbolChatFPv((this));
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
            this->selected_value = ((TWindowMenu *)this->symbol_list)->get_selected_value();
            return;
        }
        break;
    case 22:
    case 26:
        TWindowSubSymbolChat__help_window = 0;
        if ((u32) this->parts_set != 0U) {
            ((TWindowBase *)this->parts_set)->close();
            this->parts_set = 0U;
        }
        if ((u32) this->parts == 0U) {
            this->parts = this->create_parts();
            ((TWindowSubSymbolChatParts *)this->parts)->update_height();
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->help_window == 0U) {
            this->help_window = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->clear_flag60_bit4();
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->clear_flag60_bit2();
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->clear_flag60_bit1();
        this->selected_value = 0x17U;
    case 23:
    case 27:
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_cancelled() != 0) {
            this->selected_value = 0x14U;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->is_active() != 0) {
            this->update_state();
            return;
        }
        break;
    case 24:
        if ((u32) this->parts != 0U) {
            this->symbol_index = ((TWindowSubSymbolChatParts *)(this->parts))->calc_symbol_index();
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        if ((u32) this->parts_set == 0U) {
            this->parts_set = this->create_parts_set();
        }
        if (reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->select_symbol_chat_record(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window) != 0) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_flag60_bit2();
        } else if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_flag60_bit1();
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(help_window)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0x19U;
    case 25:
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_cancelled() != 0) {
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
        ((TWindowSubSymbolChat *)(this->selected_preset))->clear_entries();
        reinterpret_cast<SymbolChatPreset *>(selected_preset)->set_flag_bit2();
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->selected_value = 4U;
        return;
    case 30:
        if ((u32) this->symbol_list != 0U) {
            ((TWindowBase *)this->symbol_list)->close();
            this->symbol_list = 0U;
        }
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->second_symbol_window == NULL) {
            *(u8 * *)&this->second_symbol_window = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)this, 1));
        }
        *(s32 *)(this->second_symbol_window + 0x64) = 1;
        this->symbol_list = ((u32)create_symbol_list_card());
        apply_symbol();
        this->selected_value = 0x1FU;
    case 31:
        reinterpret_cast<TWindowChatSymbol *>(second_symbol_window)->set_from_key((int) (((TWindowMenu *)this->symbol_list)->get_selected_value()));
        if (((TWindowMenu *)(this->symbol_list))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->symbol_list))->is_decided() != 0) {
            ((TWindowSubSymbolChat *)((saddr) get_symbol_chat_preset(((TWindowMenu *)this->symbol_list)->get_selected_value())))->commit((s32 *)this->selected_preset);
            this->selected_value = 4U;
            return;
        }
        break;
    case 32:
        this->selected_value = 0x21U;
    case 33:
        ((TWindowSubSymbolChat *)(this->selected_preset))->commit((s32 *)((saddr)TWindowSubSymbolChat__sub_8028379C()));
        TWindowSubSymbolChat::set_flag_bit1((s32 *)this->selected_preset);
        reinterpret_cast<SymbolChatPreset *>(selected_preset)->set_flag_bit2();
        ((TWindowSubSymbolChat *)(this->selected_preset))->set_entry_name((void *)(TWindowSubStatusDisp::get_message_10(0xB5)));
        ((TWindowSubSymbolChatPartsSet *)(this->symbol_window))->update_visibility();
        this->selected_value = 4U;
        return;
    case 34:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
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
                ((TWindowSubSymbolChat *)(this->selected_preset))->set_symbol_index((int) (((TWindowMenu *)this->symbol_list)->get_selected_value()));
                this->selected_value = 4U;
                return;
            }
            this->selected_value = 0x22U;
            return;
        }
        break;
    case 38:
        ((TWindowMenu *)(this->main_menu))->open();
        if (this->option_window == NULL) {
            this->option_window = this->create_confirm_window();
        }
        this->selected_value = 0x27U;
    case 39:
        if (((TWindowMenuIconLine *)(this->option_window))->is_cancelled() != 0) {
            ((TWindowSubSymbolChat *)this->selected_preset)->set_flag_bit9((int) (this->option_window->update_selected_item()));
            this->selected_value = 4U;
            return;
        }
        break;
    case 40:
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->symbol_window != NULL) {
            ((TWindowBase *)this->symbol_window)->close();
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
            ((TWindowSubSymbolChat *)(this->selected_preset))->set_entry_name((void *)entry_name);
            mem_free((void *)entry_name);
            this->selected_value = 4U;
        }
        break;
    case 42:
        break;
    }
}

void TWindowSubSymbolChat::render() {  }

saddr TWindowSubSymbolChat::create_chat_symbol_window(s32 arg0, s32 arg1) {
    s32 window_chat_symbol;
    window_chat_symbol = (saddr)new TWindowChatSymbol(((get_window_layout_position(arg1 + 0x7B))), (saddr)lbl_8044FB20);
    return window_chat_symbol;
}

s32 TWindowSubSymbolChat::create_symbol_list_card() {
    Win_80282600 *arg0 = (Win_80282600 *)this;
    s32 i;
    saddr sym;
    TWindowMenu *card;
    s32 data;
    card = create_titled_window_menu_default(get_window_layout_position(0x77), 0xC, (saddr)TWindowSubStatusDisp::get_message_10(0x31));
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
    ((TWindowSubComCardList *)card)->set_scroll_target(2.2e+02f, 188.0f);
    align_menu_entry_positions(card);
    ((TWindowSubComCardList *)card)->set_selected_index(arg0->sel);
    return (saddr)card;
}

void TWindowSubSymbolChat::apply_symbol() {
    TWindowSubComCard__sub_80265680((TWindowMenu *)this->symbol_list, (s16) this->m_20);
}

s32 TWindowSubSymbolChat::open_main_menu(void * _w0) {
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
    return (saddr)menu;
}

s32 TWindowSubSymbolChat::open_edit_menu() {
    TWindowMenu *list;

    list = create_titled_window_menu_default(get_window_layout_position(0x79), 3, (saddr)TWindowSubStatusDisp::get_message_10(0xA8));
    list->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB3)), 6, 8);
    if (reinterpret_cast<SymbolChatPreset *>(selected_preset)->is_initialized() != 0) {
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
    return (saddr)list;
}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TWindowSubSymbolChat__sub_8028233C(s32 arg0) {
    s32 r = (saddr)create_titled_window_menu_default(get_window_layout_position(0x79), 6, (saddr)TWindowSubStatusDisp::get_message_10(0xA9));
    TWindowSubSymbolChat::open_menu(arg0, r);
    return r;
}

void TWindowSubSymbolChat::open_menu(s32 arg0, saddr list) {
    ((TWindowSubComCardList *)list)->reset_entries();
    if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAE)), 6, 0xC);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xAE)), 6, 0xC);
    }
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAF)), 6, 0x10);
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowSubComCardList *)list)->set_scroll_target(193.0f, 127.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
}

s32 TWindowSubSymbolChat::create_parts() {
    return reinterpret_cast<saddr>(new TWindowSubSymbolChatParts(
        get_window_layout_position(0x7D),
        &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C));
}

s32 TWindowSubSymbolChat::create_parts_set() {
    return reinterpret_cast<saddr>(new TWindowSubSymbolChatPartsSet(
        get_window_layout_position(0x7D), symbol_index,
        &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C));
}

s32 create_menu__20TWindowSubSymbolChatFPv(void *window_sub_symbol_chat) {
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
    return (saddr)list;
}

s32 TWindowSubSymbolChat::create_menu() {
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
    return (saddr)menu;
}

s32 TWindowSubSymbolChat::open_confirm_prompt() {
    saddr r = (saddr)TWindowMessageYesNo::create(this, this->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(r), (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x44)), get_window_layout_position(0x7A), 178.0f);
    ((TWindowMessageYesNo *)r)->set_choice_menu_flag70_bit10();
    return r;
}

TWindowCheckBox *TWindowSubSymbolChat::create_confirm_window() {
    TWindowCheckBox *check_box_window;

    check_box_window = create_check_box_window_for_local_client(get_window_layout_position(0x79), lbl_804D2B48);
    ((TWindowMenuIconLine *)check_box_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0xAC));
    check_box_window->add_menu_item((saddr)TWindowSubStatusDisp::get_message_10(0xBF), 1);
    check_box_window->add_menu_item((saddr)TWindowSubStatusDisp::get_message_10(0xC0), 0);
    if (TWindowSubSymbolChat__sub_80076FE0(reinterpret_cast<const SymbolChatPreset *>(selected_preset)) != 0) {
        check_box_window->set_selected_index(0);
    } else {
        check_box_window->set_selected_index(1);
    }
    ((TWindowSubShortCutList *)check_box_window)->set_flag70_bit10();
    return check_box_window;
}

s32 TWindowSubSymbolChat::create_keyboard_control() {
    saddr keyboard;

    keyboard = (saddr)new TKeyBoardControl(this, 0x90, 1, 4, local_client_id);
    reinterpret_cast<TKeyBoardControl *>(keyboard)->set_composer_flag62_bit4();
    ((TKeyBoardControl *)keyboard)->set_text((char *)((TWindowSubSymbolChat *)this->selected_preset)->get_keyboard_ptr());
    ((TKeyBoardControl *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TKeyBoardControl *)keyboard)->set_flag62_bit2();
    ((TKeyBoardControl *)keyboard)->set_soft_flag60_bit1();
    return keyboard;
}

void TWindowSubSymbolChat::sub_80281CC4() {
  s16 cursor_x;
  s16 cursor_pos;
  s32 new_var;
  cursor_x = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_x();
  cursor_pos = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_pos();
  add__20TWindowSubSymbolChatFlllll(this->selected_preset, this->symbol_index, (int) ((s32) cursor_x), (int) ((s32) cursor_pos), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D6498), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  new_var = (s32) cursor_pos;
  if (((s32) TWindowSubSymbolChat__help_window) != 0)
  {
    add__20TWindowSubSymbolChatFlllll(this->selected_preset, this->symbol_index, (int) (0x40 - cursor_x), (int) new_var, (int) ((s32) ((u8) ((*(s32 *)&TWindowSubSymbolChat__data_805D6498) == 0))), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  }
}

void TWindowSubSymbolChat::sub_80281C60() {
    s16 x;
    s16 y;
    x = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_x();
    y = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_pos();
    ((TWindowSubSymbolChat *)this->selected_preset)->set_entry_bits(this->symbol_index, TWindowSubSymbolChat__data_805D6494, x + y * 2, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
}

void TWindowSubSymbolChat::draw_selected_entry() {
    Data_80281B18 *data;
    u8 v;
    s16 y;
    s16 x;
    s32 i;
    s32 n;
    s32 pos;
    saddr inst;
    s32 rem;
    x = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_x();
    y = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_pos();
    inst = TWindowSubSymbolChat::get_instance();
    data = (Data_80281B18 *)reinterpret_cast<SymbolChatPreset *>(inst)->get_data_ptr();
    rem = TWindowSubSymbolChat::calc_remaining_slots();
    if (rem > this->symbol_index) {
        ((TWindowSubSymbolChat *)(this->selected_preset))->set_entry(this->symbol_index, data->e[this->symbol_index].c, x, y, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
        if (TWindowSubSymbolChat__help_window != 0) {
            ((TWindowSubSymbolChat *)this->selected_preset)->add(data->e[this->symbol_index].c, 0x40 - x, y, (u8)(TWindowSubSymbolChat__data_805D6498 == 0), TWindowSubSymbolChat__data_805D649C);
        }
    } else {
        n = this->symbol_index - rem;
        pos = x + y * 2;
        for (i = 0; i < 4; i++) {
            if (TWindowSubSymbolChat__sub_800771C4(reinterpret_cast<SymbolChatPreset *>(inst), i) != 0 && n-- <= 0) {
                v = data->w[i];
                TWindowSubSymbolChat__sub_800771B0(reinterpret_cast<SymbolChatPreset *>(this->selected_preset), i);
                ((TWindowSubSymbolChat *)this->selected_preset)->set_entry_bits(v, TWindowSubSymbolChat__data_805D6494, pos, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
                return;
            }
        }
    }
}

void TWindowSubSymbolChat::update_state() {
    s32 selected_menu_value;

    selected_menu_value = ((TWindowMenu *)(*(saddr *)((s8 *)this + 0x38)))->get_selected_value();
    switch (selected_menu_value) {
    case 22:
        *(s8 *)((s8 *)this + 0x1C) = 0x18;
        return;
    case 26:
        select_symbol_chat_slot((TWindowSubSymbolChatParts *)this->parts);
        ((TWindowSubSymbolChatPartsSet *)(*(saddr *)((s8 *)this + 0x30)))->update_visibility();
        if (TWindowSubSymbolChat::compute_total_height() <= 0) {
            *(s8 *)((s8 *)this + 0x1C) = 4;
            return;
        }
        *(s8 *)((s8 *)this + 0x1C) = 0x14;
        return;
    }
}

void TWindowSubSymbolChat::update_sub_window() {
    u8 *window_base;
    if (is_card_confirmed() == 0) {
        window_base = (u8 *)(*(u8 **)((s8 *)this + 0x34));
        if (window_base != NULL) {
            ((TWindowBase *)window_base)->close();
            *(u8 **)((s8 *)this + 0x34) = NULL;
            copy_vec2((void *)((*(u8 **)((s8 *)this + 0x30) + 0x30)), (void *)((void*)(get_window_layout_position(0x7B))));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x30)) + 0x50) = 6;
        }
    } else {
        if ((void *) *(u8 **)((s8 *)this + 0x34) == NULL) {
            *(u8 **)((s8 *)this + 0x34) = create_chat_symbol_window__20TWindowSubSymbolChatFll(this, 0);
            ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)this + 0x34)))->set_selection(TWindowSubSymbolChat__sub_8028379C());
            *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x34)) + 0x64) = 1;
            copy_vec2((void *)((*(u8 **)((s8 *)this + 0x30) + 0x30)), (void *)((void*)(get_window_layout_position(0x7C))));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x30)) + 0x50) = 6;
        }
        ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)this + 0x34)))->update_visibility();
    }
}

s32 TWindowSubSymbolChat::is_card_confirmed() {
    if (((TWindowMenu *)this->symbol_list)->get_selected_value() != 0x20) {
        return 0;
    }
    s32 temp;
    s32 ret;

    temp = get_cursor_pos__20TWindowShortListCtrlFv(this->symbol_list);
    ret = TWindowSubComCard__sub_80265660(this->symbol_list, temp);
    return ret ? 1 : 0;
}

void TWindowSubSymbolChat__sub_80281840(Win_80281840 *arg0) {
    Quad_80281840 q;
    u32 color;
    f32 scale;
    Sub_80281840 *sub;
    sub = arg0->sub;
    if (sub != NULL) {
        if (sub->count < 6) {
            color = ((s32)(0.16666667f * (f32)(sub->count * 0xFF)) << 24) | 0xFFFFFF;
        } else {
            color = 0xFFFFFFFF;
        }
        scale = (-1.0f) / get_scale__15TWindowCtrlMainFv(arg0->ctrl);
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
    void *temp_r3;
    temp_r3 = TWindowSubSymbolChat::instance;
    if (temp_r3 != NULL) {
        TWindowSubSymbolChat__sub_80281840((Win_80281840 *)(temp_r3));
    }
}
#pragma pop
