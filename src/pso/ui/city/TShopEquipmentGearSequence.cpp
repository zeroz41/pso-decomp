#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/city/TShopArmorListWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/MesetaWindowCreate.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/CounterTextLookup.h"
#include "pso/player/TObjPlayer.h"


s32 shop_gear_pending_message;
s32 shop_gear_pending_state;

extern "C" {
extern const char *shop_equipment_gear_sequence_class_name;
}

#pragma readonly_strings on
s32 TShopEquipmentGearSequence::window_slot_table[4];
TShopEquipmentGearSequence *shop_gear_sequence_instance;
const char *shop_equipment_gear_sequence_class_name = "TShopEquipmentGearSequence";

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void TShopEquipmentGearSequence::clear_window_slot_table() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentGearSequence::window_slot_table[i] = 0;
    }
}

void TShopEquipmentGearSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentGearSequence::window_slot_table[i] = 0;
    }
}

TShopEquipmentGearSequence::TShopEquipmentGearSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = shop_equipment_gear_sequence_class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    shop_gear_sequence_instance = this;
    shop_gear_pending_message = 0;
    shop_gear_pending_state = 0;
    TShopEquipmentGearSequence::window_slot_table[get_split_screen_slot()] = 1;
}

TShopEquipmentGearSequence::~TShopEquipmentGearSequence() {
    if (counter_camera != NULL) {
        ((TObject *)counter_camera)->queue_destruction();
        counter_camera = NULL;
    }
    if (choice_menu != NULL) {
        ((TWindowBase *)choice_menu)->close();
        choice_menu = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    close_message_window();
    shop_gear_sequence_instance = NULL;
    TShopEquipmentGearSequence::window_slot_table[get_split_screen_slot()] = 0;
}

void TShopEquipmentGearSequence::update_state() {
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
        open_armor_list_window();
        return;
    case 4:
        open_sell_window();
        return;
    case 6:
        try_close();
        return;
    case 7:
        handle_confirm();
    default:
        return;
    }
}

void TShopEquipmentGearSequence::open_greeting() {
    NJS_POINT2 pos;
    pos.x = 332.0f;
    pos.y = 80.0f;
    create_message_window(get_window_layout_position(0x2C), &pos);
    display_shop_message(0x2b, 1);
    meseta_window = (TWindowBase *)create_meseta_window((s32)(unsigned short)get_player_entity_id());
    set_state(2);
    counter_camera = set_service_counter_camera(this, 0x4);
}


void TShopEquipmentGearSequence::update_buy_sell_choice() {
    s32 id;
    s32 r;
    if (choice_menu == NULL) {
        id = player->get_entity_id();
        choice_menu = create_window_menu(get_window_layout_position(0x2B), 2, id);
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
        display_shop_message(0x2C, 1);
        set_state(6);
        choice_menu->close();
        choice_menu = NULL;
    }
}

void TShopEquipmentGearSequence::open_armor_list_window() {
    TShopArmorListWindow *o = new TShopArmorListWindow(tl_05, this, player);
    o->on_close = enter_quest_list;
    reset_controller_input_state();
    this->set_state(5);
}

void TShopEquipmentGearSequence::open_sell_window() {
    TShopEquipmentSellWindow *o = new TShopEquipmentSellWindow(tl_05, this, player, 0x2a);
    o->on_close = enter_quest_list;
    o->on_empty = open_gear_shop;
    reset_controller_input_state();
    set_state(5);
}

void TShopEquipmentGearSequence::try_close() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

void TShopEquipmentGearSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(shop_gear_pending_message, 1);
        set_state(shop_gear_pending_state);
    }
}

void TShopEquipmentGearSequence::enter_quest_list(TShopWindowBase *sequence) {
    if (sequence != NULL) {
        sequence->display_shop_message(0x1A, 1);
        sequence->set_state(2);
    }
}

void TShopEquipmentGearSequence::open_gear_shop(TShopWindowBase *sequence) {
    if (sequence != NULL) {
        sequence->display_shop_message(0x1B, 1);
        sequence->set_state(7);
        shop_gear_pending_message = 0x1A;
        shop_gear_pending_state = 2;
    }
}

