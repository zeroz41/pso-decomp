#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopEquipmentListWindow.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/CounterTextLookup.h"
#include "pso/ui/window/MesetaWindowCreate.h"
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
#include "pso/ui/window/WindowLayout.h"

s32 TShopEquipmentSequence::slot_active_flags[4];
extern const char *shop_equipment_sequence_class_name;
TShopEquipmentSequence *shop_equipment_sequence_instance;
s32 shop_equipment_pending_message;
s32 shop_equipment_pending_state;

#pragma readonly_strings on
const char *shop_equipment_sequence_class_name = "TShopEquipmentSequence";
void TShopEquipmentSequence::init_slot_active_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence::slot_active_flags[i] = 0;
    }
}

void TShopEquipmentSequence::release_slot_active_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TShopEquipmentSequence::slot_active_flags[i] = 0;
    }
}

TShopEquipmentSequence::TShopEquipmentSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = shop_equipment_sequence_class_name;
    state = 0;
    this->player = player;
    choice_menu = NULL;
    meseta_window = NULL;
    counter_camera = NULL;
    shop_equipment_sequence_instance = this;
    shop_equipment_pending_message = 0;
    shop_equipment_pending_state = 0;
    TShopEquipmentSequence::slot_active_flags[get_split_screen_slot()] = 1;
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
    TShopEquipmentSequence::slot_active_flags[get_split_screen_slot()] = 0;
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
        equipment_shop_state_stub();
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


void TShopEquipmentSequence::open_greeting() {
    NJS_POINT2 pos;
    pos.x = 332.0f;
    pos.y = 80.0f;
    create_message_window(get_window_layout_position(0x2C), &pos);
    display_shop_message(0x27, 1);
    meseta_window = (TWindowBase *)create_meseta_window((s32)(unsigned short)get_player_entity_id());
    set_state(2);
    counter_camera = set_service_counter_camera(this, 3);
}

void TShopEquipmentSequence::update_buy_sell_choice() {
    s32 r;
    if (choice_menu == NULL) {
        s32 id = ((TObjBase *)(player))->get_entity_id();
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
        this->display_shop_message(0x2C, 1);
        set_state(9);
        choice_menu->close();
        choice_menu = NULL;
    }
}

void TShopEquipmentSequence::open_buy_window() {
    TShopEquipmentListWindow *o = new TShopEquipmentListWindow(tl_05, this, player);
    o->on_close = exit;
    reset_controller_input_state();
    set_state(7);
}

void TShopEquipmentSequence::open_sell_window() {
    TShopEquipmentSellWindow *o = new TShopEquipmentSellWindow(tl_05, this, player, 0x26);
    o->on_close = exit;
    o->on_empty = init_window;
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

void equipment_shop_state_stub(void) {  }

void TShopEquipmentSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(shop_equipment_pending_message, 1);
        set_state(shop_equipment_pending_state);
    }
}

void TShopEquipmentSequence::exit(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1A, 1);
        window->set_state(2);
    }
}

void TShopEquipmentSequence::init_window(TShopWindowBase *window) {
    if (window != NULL) {
        window->display_shop_message(0x1B, 1);
        window->set_state(8);
        shop_equipment_pending_message = 0x1A;
        shop_equipment_pending_state = 2;
    }
}

