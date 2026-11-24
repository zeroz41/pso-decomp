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
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const char *TWindowSubSymbolChat::class_name = "TWindowSubSymbolChat";
static const f32 lbl_8044FB20[2] = {203.0f, 78.0f};
__declspec(section ".data") f32 lbl_804D2B48[2] = {193.0f, 128.0f};

struct Win_80281EA8 { u8 pad[0x24]; saddr client_id; };

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
saddr get_window_layout_position(s32);
u8 *create_chat_symbol_window__20TWindowSubSymbolChatFll(void *, s32);
void * TWindowSubSymbolChat__instance;
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
extern "C" {
// 0x58-byte record held in symbol_chat_receive_buffer; its compiler-generated operator= (0x80283850)
// copies the char array at +4 with __copy and the word array at +0x1C as a block.
struct Obj_80283850 { s32 value; u8 pad_4[0x17]; u32 pad_1C[0xF]; };
extern void *TWindowSubSymbolChat__instance;

s32 fn_80285A28(int, void *);
extern s8 TWindowSubSymbolChat__data_805D6494;
extern s32 TWindowSubSymbolChat__data_805D6498;
extern s32 TWindowSubSymbolChat__data_805D649C;
extern s32 TWindowSubSymbolChat__help_window;

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
s32 __copy(void *, void *, int);
s32 update_layout__20TWindowSubSymbolChatFv(void);

    extern unsigned char pending_symbol_chat_count;
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {

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
    m_24 = client;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    main_menu = 0;
    face_type_window = 0;
    parts = 0;
    parts_set = 0;
    m_54 = 0;
    confirm_window = 0;
    m_44 = 0;
    m_58 = 0;
    m_28 = 0;
    TWindowSubSymbolChat__data_805D6494 = 0;
    TWindowSubSymbolChat__data_805D6498 = 0;
    TWindowSubSymbolChat__data_805D649C = 0;
    m_20 = 0;
    TWindowSubSymbolChat__instance = this;
    m_5c = (uaddr)create_callback_at_zero_vec2(close_child);
    selected_value = 0;
}

TWindowSubSymbolChat::~TWindowSubSymbolChat() {
    if (m_58 != 0U) {
        ((TObject *)m_58)->queue_destruction();
        m_58 = 0U;
    }
    if (m_44 != 0U) {
        if ((has_window_task_root() != 0) && (selected_value == 0x27)) {
            ((TWindowSubSymbolChat *)m_28)->set_flag_bit9(((TWindowOptionCtrl *)m_44)->update_selected_item());
        }
        ((TWindowBase *)m_44)->close();
        m_44 = 0U;
    }
    if (confirm_window != 0U) {
        ((TWindowMessageYesNo *)confirm_window)->close();
        confirm_window = 0U;
    }
    if (m_54 != 0U) {
        ((TWindowBase *)m_54)->close();
        m_54 = 0U;
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
    if (m_38 != 0U) {
        ((TWindowBase *)m_38)->close();
        m_38 = 0U;
    }
    if (m_34 != 0U) {
        ((TWindowBase *)m_34)->close();
        m_34 = 0U;
    }
    if (m_30 != 0U) {
        ((TWindowBase *)m_30)->close();
        m_30 = 0U;
    }
    if (m_28 != 0U) {
        reinterpret_cast<SymbolChatPreset *>(m_28)->clear_flag_bit2();
        m_28 = 0U;
    }
    if (m_5c != 0U) {
        ((TWindowBase *)m_5c)->close();
        m_5c = 0U;
    }
    TWindowSubSymbolChat__instance = 0;
}

void TWindowSubSymbolChat::run_task() {
    u8 *arg0 = (u8 *)this;
    saddr entry_name;
    u8 *temp_r5;
    switch (this->selected_value) {
    case 0:
    case 1:
        if ((u32) this->m_28 != 0U) {
            reinterpret_cast<SymbolChatPreset *>(m_28)->clear_flag_bit2();
            this->m_28 = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->m_30 == NULL) {
            *(u8 * *)&this->m_30 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)arg0, 0));
        }
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->m_38 = ((u32)create_symbol_list_card());
        this->selected_value = 2U;
    case 2:
        reinterpret_cast<TWindowChatSymbol *>(m_30)->set_from_key((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            parent_menu->on_submenu_closed();
            this->selected_value = 0x2AU;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->m_20 = ((TWindowMenu *)this->m_38)->get_selected_value();
            ((TWindowSubSymbolChat *)(this->m_20))->update_symbol_chat_result();
            this->m_28 = TWindowSubSymbolChat::get_instance();
            reinterpret_cast<SymbolChatPreset *>(this->m_28)->update_selected_symbol();
            reinterpret_cast<SymbolChatPreset *>(m_28)->set_flag_bit2();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
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
        if ((u32) this->m_58 != 0U) {
            ((TObject *)this->m_58)->queue_destruction();
            this->m_58 = 0U;
        }
        if ((u32) this->m_44 != 0U) {
            ((TWindowBase *)this->m_44)->close();
            this->m_44 = 0U;
        }
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        if ((u32) this->face_type_window != 0U) {
            ((TWindowBase *)this->face_type_window)->close();
            this->face_type_window = 0U;
        }
        if ((void *) this->m_34 != NULL) {
            ((TWindowBase *)this->m_34)->close();
            this->m_34 = NULL;
        }
        if ((u32) this->m_38 != 0U) {
            ((TWindowBase *)this->m_38)->close();
            this->m_38 = 0U;
        }
        if ((void *) this->m_30 == NULL) {
            *(u8 * *)&this->m_30 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)arg0, 0));
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->set_selection(reinterpret_cast<SymbolChatPreset *>(m_28));
        }
        temp_r5 = (u8 *)this->m_30;
        copy_vec2((void *)((this->m_30 + 0x30)), (void *)((void*)((saddr)get_window_layout_position(0x7B))));
        *(s32 *)(this->m_30 + 0x50) = 6;
        if ((u32) this->main_menu == 0U) {
            this->main_menu = ((u32)TWindowSubSymbolChat::open_main_menu(arg0));
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
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->face_type_window != 0U) {
            ((TWindowBase *)this->face_type_window)->close();
            this->face_type_window = 0U;
        }
        if ((u32) this->m_38 == 0U) {
            this->m_38 = ((u32)open_edit_menu());
        }
        ((TWindowMenu *)(this->m_38))->clear_flag_and_release();
        this->selected_value = 7U;
    case 7:
        ((TWindowSubSymbolChat *)arg0)->update_sub_window();
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->selected_value = ((TWindowMenu *)this->m_38)->get_selected_value();
            return;
        }
        break;
    case 8:
        if ((u32) this->face_type_window == 0U) {
            this->face_type_window = (uaddr)new TWindowSubSymbolChatFaceType(reinterpret_cast<void *>(get_window_layout_position(0x7D)), &TWindowSubSymbolChat__data_805D6494);
        }
        if ((u32) this->m_54 == 0U) {
            this->m_54 = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_flag60_bit2();
        this->selected_value = 9U;
    case 9:
        if (TWindowSubSymbolChat__sub_80283998((void *)this->face_type_window) != 0) {
            this->selected_value = 6U;
            return;
        }
        if (((TWindowSubSymbolChatFaceType *)(this->face_type_window))->is_open() != 0) {
            ((TWindowSubSymbolChat *)(this->m_28))->set_symbol_flags((int) (fn_802839A4((void *)this->face_type_window)), (int)TWindowSubSymbolChat__data_805D6494);
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->selected_value = 4U;
            return;
        }
        break;
    case 10:
        if ((u32) this->parts_set != 0U) {
            ((TWindowBase *)this->parts_set)->close();
            this->parts_set = 0U;
        }
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->m_38 == 0U) {
            this->m_38 = TWindowSubSymbolChat__sub_8028233C((saddr)arg0);
        }
        ((TWindowMenu *)(this->m_38))->clear_flag_and_release();
        this->selected_value = 0xBU;
    case 11:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->symbol_index = 0;
            this->selected_value = ((TWindowMenu *)this->m_38)->get_selected_value();
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
            this->parts = ((TWindowSubSymbolChat *)arg0)->create_parts();
            fn_80285A28(this->parts, &TWindowSubSymbolChat__help_window);
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->m_54 == 0U) {
            this->m_54 = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        if (TWindowSubSymbolChat::count_instance_empty_slots() > 1) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_flag60_bit1();
        } else {
            TWindowSubSymbolChat__sub_80283944(reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54));
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0xDU;
    case 13:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->parts) != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->sub_80283974() != 0) {
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
            this->parts_set = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
            reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->init_symbol_layout(&TWindowSubSymbolChat__help_window);
        }
        this->selected_value = 0xFU;
    case 15:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->parts_set) != 0) {
            this->selected_value = 0xCU;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->sub_80281CC4();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
                this->selected_value = 0xCU;
                return;
            }
            TWindowSubSymbolChat::open_menu((saddr)arg0, (s32)this->m_38);
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
            this->parts = ((TWindowSubSymbolChat *)arg0)->create_parts();
            ((TWindowSubSymbolChatParts *)this->parts)->open(&TWindowSubSymbolChat__data_805D6494);
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->m_54 == 0U) {
            this->m_54 = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_flag60_bit2();
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0x11U;
    case 17:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->parts) != 0) {
            this->selected_value = 0xAU;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->sub_80283974() != 0) {
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
            this->parts_set = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
            reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->set_selection_and_refresh(&TWindowSubSymbolChat__data_805D6494);
        }
        this->selected_value = 0x13U;
    case 19:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->parts_set) != 0) {
            this->selected_value = 0x10U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->sub_80281C60();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->selected_value = 0x10U;
            return;
        }
        break;
    case 20:
        if ((u32) this->m_54 != 0U) {
            ((TWindowBase *)this->m_54)->close();
            this->m_54 = 0U;
        }
        if ((u32) this->parts != 0U) {
            ((TWindowBase *)this->parts)->close();
            this->parts = 0U;
        }
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->m_38 == 0U) {
            this->m_38 = create_menu__20TWindowSubSymbolChatFPv((arg0));
        }
        ((TWindowMenu *)(this->m_38))->clear_flag_and_release();
        this->selected_value = 0x15U;
    case 21:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            this->symbol_index = 0;
            this->selected_value = ((TWindowMenu *)this->m_38)->get_selected_value();
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
            this->parts = ((TWindowSubSymbolChat *)arg0)->create_parts();
            ((TWindowSubSymbolChatParts *)this->parts)->update_height();
        }
        ((TWindowSubSymbolChatParts *)this->parts)->select_index_and_scroll(this->symbol_index);
        if ((u32) this->m_54 == 0U) {
            this->m_54 = (uaddr)new TWindowSubSymbolChatHelp(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window);
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->clear_flag60_bit4();
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->clear_flag60_bit2();
        TWindowSubSymbolChat__sub_80283944(reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54));
        this->selected_value = 0x17U;
    case 23:
    case 27:
        if (TWindowSubSymbolChat__sub_80283980((void *)this->parts) != 0) {
            this->selected_value = 0x14U;
            return;
        }
        if (((TWindowSubSymbolChatParts *)(this->parts))->sub_80283974() != 0) {
            ((TWindowSubSymbolChat *)arg0)->update_state();
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
            this->parts_set = ((TWindowSubSymbolChat *)arg0)->create_parts_set();
        }
        if (reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->select_symbol_chat_record(&TWindowSubSymbolChat__data_805D6494, &TWindowSubSymbolChat__help_window) != 0) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_flag60_bit2();
        } else if (TWindowSubSymbolChat::count_instance_empty_slots() > 0) {
            reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_flag60_bit1();
        }
        reinterpret_cast<TWindowSubSymbolChatHelp *>(m_54)->set_pos_and_flag(&TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C);
        this->selected_value = 0x19U;
    case 25:
        if (TWindowSubSymbolChat__sub_80283900((void *)this->parts_set) != 0) {
            this->selected_value = 0x16U;
            return;
        }
        if (((TWindowSubSymbolChatPartsSet *)(this->parts_set))->is_active() != 0) {
            ((TWindowSubSymbolChat *)arg0)->draw_selected_entry();
            ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
            this->selected_value = 0x16U;
            return;
        }
        break;
    case 28:
        this->selected_value = 0x1DU;
    case 29:
        ((TWindowSubSymbolChat *)(this->m_28))->clear_entries();
        reinterpret_cast<SymbolChatPreset *>(m_28)->set_flag_bit2();
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->selected_value = 4U;
        return;
    case 30:
        if ((u32) this->m_38 != 0U) {
            ((TWindowBase *)this->m_38)->close();
            this->m_38 = 0U;
        }
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->m_34 == NULL) {
            *(u8 * *)&this->m_34 = ((u8 *)TWindowSubSymbolChat::create_chat_symbol_window((saddr)arg0, 1));
        }
        *(s32 *)(this->m_34 + 0x64) = 1;
        this->m_38 = ((u32)create_symbol_list_card());
        apply_symbol();
        this->selected_value = 0x1FU;
    case 31:
        reinterpret_cast<TWindowChatSymbol *>(m_34)->set_from_key((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            ((TWindowSubSymbolChat *)((saddr) get_symbol_chat_preset(((TWindowMenu *)this->m_38)->get_selected_value())))->commit((s32 *)this->m_28);
            this->selected_value = 4U;
            return;
        }
        break;
    case 32:
        this->selected_value = 0x21U;
    case 33:
        ((TWindowSubSymbolChat *)(this->m_28))->commit((s32 *)((saddr)TWindowSubSymbolChat__sub_8028379C()));
        TWindowSubSymbolChat::set_flag_bit1((s32 *)this->m_28);
        reinterpret_cast<SymbolChatPreset *>(m_28)->set_flag_bit2();
        ((TWindowSubSymbolChat *)(this->m_28))->set_entry_name((void *)(TWindowSubStatusDisp::get_message_10(0xB5)));
        ((TWindowSubSymbolChatPartsSet *)(this->m_30))->update_visibility();
        this->selected_value = 4U;
        return;
    case 34:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->confirm_window != 0U) {
            ((TWindowMessageYesNo *)(this->confirm_window))->close();
            this->confirm_window = 0U;
        }
        if ((u32) this->m_38 == 0U) {
            this->m_38 = ((TWindowSubSymbolChat *)arg0)->create_menu();
        }
        ((TWindowMenu *)(this->m_38))->clear_flag_and_release();
        this->selected_value = 0x23U;
    case 35:
        if (((TWindowMenu *)(this->m_38))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TWindowMenu *)(this->m_38))->is_decided() != 0) {
            TWindowSubSymbolChat::play_symbol_sound((s32)((TWindowMenu *)this->m_38)->get_selected_value());
            this->selected_value = 0x24U;
            return;
        }
        break;
    case 36:
        this->confirm_window = ((TWindowSubSymbolChat *)arg0)->open_confirm_prompt();
        this->selected_value = 0x25U;
    case 37:
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_cancelled() != 0) {
            this->selected_value = 0x22U;
            return;
        }
        if (((TWindowMessageYesNo *)(this->confirm_window))->is_child_visible() != 0) {
            if (((TWindowMessageYesNo *)(this->confirm_window))->get_selected_value() == 0) {
                ((TWindowSubSymbolChat *)(this->m_28))->set_symbol_index((int) (((TWindowMenu *)this->m_38)->get_selected_value()));
                this->selected_value = 4U;
                return;
            }
            this->selected_value = 0x22U;
            return;
        }
        break;
    case 38:
        ((TWindowMenu *)(this->main_menu))->open();
        if ((u32) this->m_44 == 0U) {
            this->m_44 = ((TWindowSubSymbolChat *)arg0)->create_confirm_window();
        }
        this->selected_value = 0x27U;
    case 39:
        if (((TWindowMenuIconLine *)(this->m_44))->is_cancelled() != 0) {
            ((TWindowSubSymbolChat *)this->m_28)->set_flag_bit9((int) (((TWindowOptionCtrl *)this->m_44)->update_selected_item()));
            this->selected_value = 4U;
            return;
        }
        break;
    case 40:
        if ((u32) this->main_menu != 0U) {
            ((TWindowBase *)this->main_menu)->close();
            this->main_menu = 0U;
        }
        if ((void *) this->m_30 != NULL) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = NULL;
        }
        this->m_58 = ((TWindowSubSymbolChat *)arg0)->create_keyboard_control();
        this->selected_value = 0x29U;
    case 41:
        if (((TKeyBoardControl *)(this->m_58))->is_cancelled() != 0) {
            this->selected_value = 4U;
            return;
        }
        if (((TKeyBoardControl *)(this->m_58))->is_confirmed() != 0) {
            entry_name = (saddr)((TKeyBoardControl *)(this->m_58))->realloc_buffer();
            ((TWindowSubSymbolChat *)(this->m_28))->set_entry_name((void *)entry_name);
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
    window_chat_symbol = (saddr)new TWindowChatSymbol((((s32)get_window_layout_position(arg1 + 0x7B))), (saddr)lbl_8044FB20);
    return window_chat_symbol;
}

s32 TWindowSubSymbolChat::create_symbol_list_card() {
    Win_80282600 *arg0 = (Win_80282600 *)this;
    s32 i;
    saddr sym;
    saddr card;
    s32 data;
    card = create_titled_window_menu_default(get_window_layout_position(0x77), 0xC, (saddr)TWindowSubStatusDisp::get_message_10(0x31));
    for (i = 0; i < 0xC; i++) {
        sym = (saddr)get_symbol_chat_preset(i);
        data = (saddr)reinterpret_cast<SymbolChatPreset *>(sym)->get_symbol_chat_data();
        if (is_symbol_chat_preset_in_use(reinterpret_cast<const SymbolChatPreset *>(sym)) != 0) {
            ((TWindowMenu *)card)->add_text_entry(data, 0x66, i);
        } else {
            ((TWindowMenu *)card)->add_text_entry(data, 0x46, i);
        }
    }
    ((TWindowMenu *)card)->set_flag70_bit10();
    ((TWindowSubComCardList *)card)->set_scroll_target(2.2e+02f, 188.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(card));
    ((TWindowSubComCardList *)card)->set_selected_index(arg0->sel);
    return card;
}

void TWindowSubSymbolChat::apply_symbol() {
    TWindowSubComCard__sub_80265680((TWindowMenu *)this->m_38, (s16) this->m_20);
}

s32 TWindowSubSymbolChat::open_main_menu(void * _w0) {
    saddr menu;

    menu = create_titled_window_menu_default(get_window_layout_position(0x78), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x1D));
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xA8)), 6, 6);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xA9)), 6, 0xA);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAA)), 6, 0x14);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAB)), 6, 0x22);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAC)), 6, 0x26);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xAD)), 6, 0x28);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowMenu *)menu)->update_layout_height(193.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}

s32 TWindowSubSymbolChat::open_edit_menu() {
    saddr list;

    list = create_titled_window_menu_default(get_window_layout_position(0x79), 3, (saddr)TWindowSubStatusDisp::get_message_10(0xA8));
    ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB3)), 6, 8);
    if (reinterpret_cast<SymbolChatPreset *>(m_28)->is_initialized() != 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB4)), 6, 0x1E);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB4)), 6, 0x1E);
    }
    if ((s8)TWindowSubSymbolChat::get_global_4e54() > 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB5)), 6, 0x20);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB5)), 6, 0x20);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowSubComCardList *)list)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}
}
#pragma pop
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
s32 TWindowSubSymbolChat__sub_8028233C(s32 arg0) {
    s32 r = create_titled_window_menu_default((s32)(get_window_layout_position(0x79)), 6, (s32)((saddr)TWindowSubStatusDisp::get_message_10(0xA9)));
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
        reinterpret_cast<void *>(get_window_layout_position(0x7D)),
        &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C));
}

s32 TWindowSubSymbolChat::create_parts_set() {
    return reinterpret_cast<saddr>(new TWindowSubSymbolChatPartsSet(
        reinterpret_cast<void *>(get_window_layout_position(0x7D)), symbol_index,
        &TWindowSubSymbolChat__data_805D6498, &TWindowSubSymbolChat__data_805D649C));
}

s32 create_menu__20TWindowSubSymbolChatFPv(void *window_sub_symbol_chat) {
    saddr list;

    list = create_titled_window_menu_default(get_window_layout_position(0x79), 3, (saddr)TWindowSubStatusDisp::get_message_10(0xAA));
    if (TWindowSubSymbolChat::compute_total_height() <= 0) {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB0)), 6, 0x16);
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB1)), 6, 0x1A);
    } else {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB0)), 6, 0x16);
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB1)), 6, 0x1A);
    }
    if (reinterpret_cast<SymbolChatPreset *>(static_cast<TWindowSubSymbolChat *>(window_sub_symbol_chat)->m_28)->is_initialized() != 0) {
        ((TWindowMenu *)list)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB2)), 6, 0x1C);
    } else {
        add_gray_text_entry((TWindowMenu *)list, (const char *)(TWindowSubStatusDisp::get_message_10(0xB2)), 6, 0x1C);
    }
    ((TWindowMenu *)list)->set_flag70_bit10();
    ((TWindowSubComCardList *)list)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(list));
    return list;
}

s32 TWindowSubSymbolChat::create_menu() {
    saddr menu;

    menu = create_titled_window_menu_default(get_window_layout_position(0x79), 9, (saddr)TWindowSubStatusDisp::get_message_10(0xAB));
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB6)), 0x26, 0);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB7)), 0x26, 1);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB8)), 0x26, 2);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xB9)), 0x26, 3);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBA)), 0x26, 4);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBB)), 0x26, 5);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBC)), 0x26, 6);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBD)), 0x26, 7);
    ((TWindowMenu *)menu)->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0xBE)), 0x26, 8);
    ((TWindowMenu *)menu)->set_flag70_bit10();
    ((TWindowSubComCardList *)menu)->set_scroll_target(193.0f, 128.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}

s32 TWindowSubSymbolChat::open_confirm_prompt() {
    Win_80281EA8 *arg0 = (Win_80281EA8 *)this;
    saddr r = (saddr)TWindowMessageYesNo::create((void *)(arg0), arg0->client_id, 0, 0);
    open_yes_no_prompt(reinterpret_cast<TWindowMessageYesNo *>(r), (uaddr)(TWindowSubStatusDisp::get_message_10(0x20)), (saddr)(TWindowSubStatusDisp::get_message_10(0x44)), (s32)(get_window_layout_position(0x7A)), 178.0f);
    ((TWindowMessageYesNo *)r)->set_choice_menu_flag70_bit10();
    return r;
}

s32 TWindowSubSymbolChat::create_confirm_window() {
    saddr check_box_window;

    check_box_window = (saddr)create_check_box_window_for_local_client((const NJS_POINT2 *)get_window_layout_position(0x79), lbl_804D2B48);
    ((TWindowMenuIconLine *)check_box_window)->ensure_status_display((saddr)TWindowSubStatusDisp::get_message_10(0xAC));
    TWindowOptionCtrl::add_menu_item(check_box_window, (saddr)TWindowSubStatusDisp::get_message_10(0xBF), 1);
    TWindowOptionCtrl::add_menu_item(check_box_window, (saddr)TWindowSubStatusDisp::get_message_10(0xC0), 0);
    if (TWindowSubSymbolChat__sub_80076FE0(reinterpret_cast<const SymbolChatPreset *>(m_28)) != 0) {
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(0);
    } else {
        ((TWindowSubStatusDisp *)check_box_window)->set_selected_index(1);
    }
    ((TWindowSubShortCutList *)check_box_window)->set_flag70_bit10();
    return check_box_window;
}

s32 TWindowSubSymbolChat::create_keyboard_control() {
    saddr keyboard;

    keyboard = (saddr)new TKeyBoardControl(this, 0x90, 1, 4, local_client_id);
    reinterpret_cast<TKeyBoardControl *>(keyboard)->set_composer_flag62_bit4();
    ((TKeyBoardControl *)keyboard)->set_text((char *)((TWindowSubSymbolChat *)this->m_28)->get_keyboard_ptr());
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
  add__20TWindowSubSymbolChatFlllll(this->m_28, this->symbol_index, (int) ((s32) cursor_x), (int) ((s32) cursor_pos), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D6498), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  new_var = (s32) cursor_pos;
  if (((s32) TWindowSubSymbolChat__help_window) != 0)
  {
    add__20TWindowSubSymbolChatFlllll(this->m_28, this->symbol_index, (int) (0x40 - cursor_x), (int) new_var, (int) ((s32) ((u8) ((*(s32 *)&TWindowSubSymbolChat__data_805D6498) == 0))), (int) (*(s32 *)&TWindowSubSymbolChat__data_805D649C));
  }
}

void TWindowSubSymbolChat::sub_80281C60() {
    s16 x;
    s16 y;
    x = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_x();
    y = reinterpret_cast<TWindowSubSymbolChatPartsSet *>(parts_set)->get_cursor_pos();
    ((TWindowSubSymbolChat *)this->m_28)->set_entry_bits(this->symbol_index, TWindowSubSymbolChat__data_805D6494, x + y * 2, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
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
        ((TWindowSubSymbolChat *)(this->m_28))->set_entry(this->symbol_index, data->e[this->symbol_index].c, x, y, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
        if (TWindowSubSymbolChat__help_window != 0) {
            ((TWindowSubSymbolChat *)this->m_28)->add(data->e[this->symbol_index].c, 0x40 - x, y, (u8)(TWindowSubSymbolChat__data_805D6498 == 0), TWindowSubSymbolChat__data_805D649C);
        }
    } else {
        n = this->symbol_index - rem;
        pos = x + y * 2;
        for (i = 0; i < 4; i++) {
            if (TWindowSubSymbolChat__sub_800771C4(reinterpret_cast<SymbolChatPreset *>(inst), i) != 0 && n-- <= 0) {
                v = data->w[i];
                TWindowSubSymbolChat__sub_800771B0(reinterpret_cast<SymbolChatPreset *>(this->m_28), i);
                ((TWindowSubSymbolChat *)this->m_28)->set_entry_bits(v, TWindowSubSymbolChat__data_805D6494, pos, TWindowSubSymbolChat__data_805D6498, TWindowSubSymbolChat__data_805D649C);
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
    u8 *arg0 = (u8 *)this;
    u8 *window_base;
    if (is_card_confirmed() == 0) {
        window_base = (u8 *)(*(u8 **)((s8 *)arg0 + 0x34));
        if (window_base != NULL) {
            ((TWindowBase *)window_base)->close();
            *(u8 **)((s8 *)arg0 + 0x34) = NULL;
            copy_vec2((void *)((*(u8 **)((s8 *)arg0 + 0x30) + 0x30)), (void *)((void*)(get_window_layout_position(0x7B))));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x30)) + 0x50) = 6;
        }
    } else {
        if ((void *) *(u8 **)((s8 *)arg0 + 0x34) == NULL) {
            *(u8 **)((s8 *)arg0 + 0x34) = create_chat_symbol_window__20TWindowSubSymbolChatFll(arg0, 0);
            ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x34)))->set_selection(TWindowSubSymbolChat__sub_8028379C());
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x34)) + 0x64) = 1;
            copy_vec2((void *)((*(u8 **)((s8 *)arg0 + 0x30) + 0x30)), (void *)((void*)(get_window_layout_position(0x7C))));
            *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x30)) + 0x50) = 6;
        }
        ((TWindowSubSymbolChatPartsSet *)(*(u8 **)((s8 *)arg0 + 0x34)))->update_visibility();
    }
}

s32 TWindowSubSymbolChat::is_card_confirmed() {
    if (((TWindowMenu *)this->m_38)->get_selected_value() != 0x20) {
        return 0;
    }
    s32 temp;
    s32 ret;

    temp = get_cursor_pos__20TWindowShortListCtrlFv(this->m_38);
    ret = TWindowSubComCard__sub_80265660(this->m_38, temp);
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
    temp_r3 = TWindowSubSymbolChat__instance;
    if (temp_r3 != NULL) {
        TWindowSubSymbolChat__sub_80281840((Win_80281840 *)(temp_r3));
    }
}
#pragma pop
