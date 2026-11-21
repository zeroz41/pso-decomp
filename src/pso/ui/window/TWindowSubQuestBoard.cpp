#pragma defer_codegen on

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubQuestBoard.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubQuestBoard_8027D1E8.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubQuestBoardSelect.h"
#include "pso/unk/TUnk_804D1818.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMagPhoton.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubShortCutList.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/PadRumble.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/window/TWindowShortListCtrl_801A4FC0.h"
#include "pso/object/warp/TObjCityMainWarp.h"

#pragma readonly_strings on

struct VB_8027CCCC { u8 pad[0x18]; };

struct VO_8027CCCC : VB_8027CCCC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
};

struct VB_8027CFC8 { u8 pad[0x18]; };

struct VO_8027CFC8 : VB_8027CFC8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
};

struct Ent_8027CFC8 { u8 pad[0x20]; s32 f20; };

// The {width, height} of the option value window sub_8027C884 opens (name inferred).
__declspec(section ".rodata") static const f32 option_value_window_size[2] ATTRIBUTE_ALIGN(8) = { 302.0f, 148.0f };

extern "C" {
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804D1818[];
s32 fn_8027D1E8(s32);
extern Ent_8027CFC8 quest_board_handlers[];
int set_card_window_flags__19TWindowKeyBoardHardFPvll(void*, int, int);
const char *TWindowSubQuestBoard__class_name = "TWindowSubQuestBoard";
}

int TWindowSubQuestBoard__sub_8027D1DC(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }

int TWindowSubQuestBoardSelect::is_open() { return this->m_60 & 0x1; }

u8 TWindowSubQuestBoard::get_page_index() { return *(u8*)((char*)this + 0x61); }

TWindowSubQuestBoard::TWindowSubQuestBoard(TObject *object, void *arg2) : TObject(object) {
    void *o;
    this->m_name = TWindowSubQuestBoard__class_name;
    *(void **)((s8 *)this + 0x24) = object;
    *(void **)((s8 *)this + 0x20) = arg2;
    o = new TWindowSubQuestBoardSelect();
    *(void **)((s8 *)this + 0x28) = o;
    this->quest_thread_board = NULL;
    this->m_1c = 0;
    TWindowCtrl__sub_8027D214();
}

TWindowSubQuestBoard::~TWindowSubQuestBoard() {
    TWindowCtrl__sub_8027D1F8();
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x28)))->close(); this->m_28 = 0; }
}

extern "C" {
void TWindowSubQuestBoard::run_task() {
    switch (this->m_1c) {
    case 0:
    case 1:
        fn_8027D1E8(this->m_28);
        this->m_1c = 2;
    case 2:
        if (TWindowSubQuestBoard__sub_8027D1DC((void *)this->m_28) != 0) {
            (*(VO_8027CFC8 * *)&this->m_24)->m7();
            this->m_1c = 5;
            break;
        }
        if (((TWindowSubQuestBoardSelect *)(this->m_28))->is_open() != 0) {
            this->m_1c = 3;
        }
        break;
    case 3:
        this->quest_thread_board = TQuestThreadBoard::create_instance(
            quest_board_handlers[(s8)((TWindowSubQuestBoard *)this->m_28)->get_page_index()].f20);
        this->m_1c = 4;
    case 4:
        if (this->quest_thread_board->all_parents_unqueued_for_destruction() == 0) {
            this->quest_thread_board = NULL;
            this->m_1c = 1;
        }
        break;
    case 5:
        break;
    }
}

void TWindowSubQuestBoard::render() {  }

int TWindowSubQuestBoard::set_card_flags_direct(int a1) { return set_card_window_flags__19TWindowKeyBoardHardFPvll(this, a1, -2); }

void TWindowSubQuestBoard::set_card_flags_scaled(s32 arg1) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, arg1 * 2, -3);
}

void TWindowSubQuestBoard__sub_8027CF50(saddr arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, arg1 * 4, -5);
}

void TWindowSubQuestBoard::clear_card_window_flags(s32 arg1) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, arg1 * 8, -9);
}

void TWindowSubQuestBoard::set_card_window_flags(s32 arg1) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, arg1 << 8, -0x301);
}

void TWindowSubQuestBoard::set_board_flags(s32 arg1) {
    saddr arg0 = (saddr)this;
    TWindowKeyBoardHard::set_card_window_flags((void*)arg0, arg1 << 0xA, -0x1C01);
}

u8 *TWindowSubQuestBoard__sub_8027CE74(u8 *arg0, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804D1818;
    ((TUnk_804D1818 *)arg0)->parent = arg1;
    ((TUnk_804D1818 *)arg0)->client_id = arg2;
    ((TUnk_804D1818 *)arg0)->menu = (TWindowMenu *)((TUnk_804D1818 *)arg0)->create_option_menu_window();
    ((TUnk_804D1818 *)arg0)->value_window = 0;
    ((TUnk_804D1818 *)arg0)->state = 0;
    return arg0;
}

TUnk_804D1818::~TUnk_804D1818() {
    if (value_window != 0) { ((TWindowBase *)value_window)->close(); value_window = 0; }
    if (menu != NULL) { ((TWindowBase *)menu)->close(); menu = NULL; }
}

void TUnk_804D1818::run_task() {
    s32 t;
    switch (state) {
    case 0:
    case 1:
        if (value_window != 0U) {
            ((TWindowBase *)value_window)->close();
            value_window = 0U;
        }
        ((TWindowSubComCard *)menu)->clear_flag_and_release();
        state = 2;
    case 2:
        if (menu->is_cancelled() != 0) {
            ((VO_8027CCCC *)parent)->m7();
            state = 5;
            break;
        }
        if (menu->is_decided() != 0) {
            state = 3;
        }
        break;
    case 3:
        t = menu->get_selected_value();
        value_window = sub_8027C884(t);
        state = 4;
    case 4:
        this->update_photon_selection();
        update_quest_board_card_flags();
        if (((TWindowMenuIconLine *)(value_window))->is_cancelled() != 0) {
            state = 1;
        }
        break;
    }
}

void TUnk_804D1818::render() {  }

saddr TUnk_804D1818::create_option_menu_window() {
    saddr titled_window_menu;

    titled_window_menu = create_titled_window_menu((saddr)get_window_layout_position(0x15), 6, (saddr)TWindowSubStatusDisp::get_message_10(0x2A), client_id);
    if (is_split_screen() == 0) {
        TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x66), 6, 0);
    }
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x67), 6, 1);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x68), 6, 2);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x69), 6, 3);
    TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x6A), 6, 4);
    if (is_split_screen() == 0) {
        TObjCityMainWarp::forward_trade_action_default((void *)titled_window_menu, (saddr)TWindowSubStatusDisp::get_message_10(0x6E), 6, 5);
    }
    ((TWindowMenu *)titled_window_menu)->set_flag70_bit10();
    ((TWindowMenu *)titled_window_menu)->update_layout_height(195.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(titled_window_menu));
    ((TWindowBase *)titled_window_menu)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 0));
    return titled_window_menu;
}

saddr TUnk_804D1818::sub_8027C884(s32 option) {
    s16 value;
    saddr window;
    s32 flag;
    window = (saddr)TWindowSubStatusDisp__sub_80248BE8((saddr)(get_window_layout_position(0x16)), (saddr)option_value_window_size, (s32)client_id);
    switch (option) {
    case 0:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x66)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x6F)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x70)), 1);
        value = ((TWindowKeyBoardHard *)(client_id))->is_card_flag_set();
        break;
    case 1:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x67)));
        TWindowSubStatusDisp::draw_status(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x71)), 0);
        TWindowSubStatusDisp::draw_status(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x72)), 1);
        value = TBoss8Dragon::test_card_flag_2(client_id);
        break;
    case 2:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x68)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x73)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x74)), 1);
        value = test_keyboard_card_flag4((void *)client_id);
        break;
    case 4:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x6A)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0xA6)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0xA7)), 1);
        flag = TWindowKeyBoardHard::test_card_flag_8(client_id);
        vibration = flag;
        value = (s16) flag;
        break;
    case 3:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x69)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x75)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x76)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x77)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x78)), 3);
        value = TWindowSubStatusDisp::get_card_window_flags(client_id);
        break;
    case 5:
        ((TWindowMenuIconLine *)window)->ensure_status_display((saddr) (TWindowSubStatusDisp::get_message_10(0x6E)));
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x79)), 0);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7A)), 1);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7B)), 2);
        TWindowSubStatusDisp::dispatch_without_flags(window, (saddr) (TWindowSubStatusDisp::get_message_10(0x7C)), 3);
        value = fn_801A51F0(client_id);
        break;
    }
    ((TWindowSubStatusDisp *)window)->set_selected_index(value);
    ((TWindowSubShortCutList *)window)->set_flag70_bit10();
    ((TWindowBase *)window)->set_depth(TWindowSubEquip__sub_80263AF8((u8 *)parent, 1));
    return window;
}

void TUnk_804D1818::update_quest_board_card_flags() {
    s32 selected_menu_value;
    s32 value;

    selected_menu_value = menu->get_selected_value();
    value = ((TWindowOptionCtrl *)value_window)->update_selected_item();
    switch (selected_menu_value) {
    case 0:
        ((TWindowSubQuestBoard *)(client_id))->set_card_flags_direct(value);
        return;
    case 1:
        ((TWindowSubQuestBoard *)(client_id))->set_card_flags_scaled(value);
        return;
    case 2:
        TWindowSubQuestBoard__sub_8027CF50(client_id, value);
        return;
    case 4:
        ((TWindowSubQuestBoard *)(client_id))->clear_card_window_flags(value);
        return;
    case 3:
        ((TWindowSubQuestBoard *)(client_id))->set_card_window_flags(value);
        return;
    case 5:
        ((TWindowSubQuestBoard *)(client_id))->set_board_flags(value);
        return;
    }
}

void TUnk_804D1818::update_photon_selection() {
    s32 selected_menu_value;
    s32 value;

    selected_menu_value = menu->get_selected_value();
    value = ((TWindowOptionCtrl *)value_window)->update_selected_item();
    if ((selected_menu_value == 4) && ((s8)vibration != value)) {
        (vibration) = (u8) value;
        if ((s8)vibration == 0) {
            start_pad_rumble_client(0xC0, 0xF, (s16)client_id);
        }
    }
}
}
