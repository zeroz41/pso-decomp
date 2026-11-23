#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801A5AEC.h"
#include "pso/unk/text_80222C28.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TShopEquipmentSequence.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_8022350C.h"

extern "C" {
saddr get_window_layout_position(int, f32);
s32 TShopEquipmentSequence__slot_active_flags[4];
extern const char *TShopEquipmentSequence__class_name;
TShopEquipmentSequence *lbl_805D6228;
s32 lbl_805D622C;
s32 lbl_805D6230;
}

#pragma readonly_strings on
struct Base_8021D584_8021D524 { char pad[0x18]; };
struct Base_8021D5D4_8021D524 { char pad[0x18]; };
struct VBase_18_a93f07
{
  char pad[0x18];
};
struct Stack_8021D948
{
  f32 sp8;
  f32 spC;
};
struct S_8021D750 { u8 pad[0x24]; s32 player; };
struct Base_8021D7B8 { char pad[0x18]; };
struct Base_8021D524 { char pad[0x18]; };
const char *TShopEquipmentSequence__class_name = "TShopEquipmentSequence";
void TShopEquipmentSequence__sub_8021DC08(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence__slot_active_flags[i] = 0;
    }
}

void TShopEquipmentSequence__sub_8021DBE0(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence__slot_active_flags[i] = 0;
    }
}

TShopEquipmentSequence::TShopEquipmentSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TShopEquipmentSequence__class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    lbl_805D6228 = this;
    lbl_805D622C = 0;
    lbl_805D6230 = 0;
    TShopEquipmentSequence__slot_active_flags[get_split_screen_slot()] = 1;
}

TShopEquipmentSequence::~TShopEquipmentSequence() {
    if (counter_camera != NULL) {
        ((TObject *)counter_camera)->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        ((TWindowBase *)choice_menu)->close();
        choice_menu = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    TShopEquipmentSequence__slot_active_flags[get_split_screen_slot()] = 0;
}

void TShopEquipmentSequence::update_state() {
    switch (state) {
    case 0:
        TShopSequence::restore_player_state();
        set_state(1);
        return;
    case 1:
        open_greeting();
        return;
    case 2:
        update_buy_sell_choice();
        return;
    case 3:
        open_buy_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 5:
        set_state(9);
        return;
    case 6:
        set_state(9);
        return;
    case 7:
        TShopEquipmentSequence__sub_8021D65C();
        return;
    case 9:
        close_if_done();
        return;
    case 8:
        handle_confirm();
    default:
        return;
    }
}

extern "C" {

void TShopEquipmentSequence::open_greeting() {
    f32 pos[2];
    pos[0] = 332.0f;
    pos[1] = 80.0f;
    create_message_window(get_window_layout_position(0x2C, 332.0f), (saddr)pos);
    display_shop_message(0x27, 1);
    meseta_window = (TWindowBase *)create_meseta_window((s32)(unsigned short)get_player_entity_id());
    set_state(2);
    counter_camera = set_service_counter_camera(this, 3);
}

void TShopEquipmentSequence::update_buy_sell_choice() {
    s32 r;
    if (choice_menu == NULL) {
        s32 id = ((TObjBase *)(player))->get_entity_id();
        choice_menu = create_window_menu(((saddr (*)(int))get_window_layout_position)(0x2B), 2, id);
        choice_menu->add_text_entry(get_shop_text(4), 6, 0);
        choice_menu->add_text_entry(get_shop_text(6), 6, 1);
        choice_menu->calc_window_size();
        align_menu_entry_positions(choice_menu);
        choice_menu->set_ready_flag();
        choice_menu->set_position_xy(get_scale(), get_scale());
    }
    if (choice_menu != NULL && choice_menu->is_decided() != 0) {
        r = choice_menu->get_selected_value();
        if (r == 0) {
            set_state(3);
            choice_menu->close();
            choice_menu = NULL;
            return;
        }
        if (r == 1) {
            set_state(4);
            choice_menu->close();
            choice_menu = NULL;
            return;
        }
    }
    if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
        this->display_shop_message(0x2C, 1);
        set_state(9);
        choice_menu->close();
        choice_menu = NULL;
    }
}

void TShopEquipmentSequence::open_buy_window() {
    TShopEquipmentListWindow *o = new TShopEquipmentListWindow(tl_05, this, player);
    o->on_close = exit__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_state(7);
}

void TShopEquipmentSequence::open_sell_window() {
    TShopEquipmentSellWindow *o = new TShopEquipmentSellWindow(tl_05, this, player, 0x26);
    o->on_close = exit__22TShopEquipmentSequenceFPv;
    o->on_empty = init_window__22TShopEquipmentSequenceFPv;
    reset_controller_input_state();
    set_state(7);
}

void TShopEquipmentSequence::close_if_done() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

void TShopEquipmentSequence__sub_8021D65C(void) {  }

void TShopEquipmentSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(lbl_805D622C, 1);
        set_state(lbl_805D6230);
    }
}

void exit__22TShopEquipmentSequenceFPv(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1A, 1);
        window->set_state(2);
    }
}

void init_window__22TShopEquipmentSequenceFPv(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1B, 1);
        window->set_state(8);
        lbl_805D622C = 0x1A;
        lbl_805D6230 = 2;
    }
}

}
