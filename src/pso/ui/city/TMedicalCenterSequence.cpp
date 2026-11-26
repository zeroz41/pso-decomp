#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/city/TMedicalCenterMes.h"
#include "pso/unk/text_80222C28.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TMedicalCenterSequence.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/player/TObjPlayer.h"
#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjBase.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/WindowLayout.h"


extern const char *medical_center_mes_class_name;


#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/PlayerSlots.h"

s32 medical_center_slot_active_flags[4];
s32 TMedicalCenterMes::slot_flags[4];

extern "C" {
extern const char *medical_center_sequence_class_name;

}

const char *medical_center_sequence_class_name = "TMedicalCenterSequence";
const char *medical_center_mes_class_name = "TMedicalCenterMes";
void TMedicalCenterSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        medical_center_slot_active_flags[i] = 0;
    }
}

void TMedicalCenterSequence::clear_slot_data() {
    s32 i;
    for (i = 0; i < 4; i++) {
        medical_center_slot_active_flags[i] = 0;
    }
}

TMedicalCenterSequence::TMedicalCenterSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = medical_center_sequence_class_name;
    state = 0;
    this->player = player;
    meseta_window = NULL;
    yes_no_menu = NULL;
    counter_camera = NULL;
    medical_center_slot_active_flags[get_split_screen_slot()] = 1;
}

TMedicalCenterSequence::~TMedicalCenterSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    if (yes_no_menu != NULL) {
        ((TWindowBase *)yes_no_menu)->close();
        yes_no_menu = NULL;
    }
    medical_center_slot_active_flags[get_split_screen_slot()] = 0;
}

void TMedicalCenterSequence::update_state() {
    switch (state) {
    case 0:
        restore_player_state();
        return;
    case 1:
        open_greeting_window();
        return;
    case 2:
        handle_confirm();
        return;
    case 6:
        show_already_healthy();
        return;
    case 7:
        show_fee_prompt();
        return;
    case 3:
        handle_window_result();
        return;
    case 4:
        exec_heal();
        return;
    case 5:
        show_declined();
        return;
    case 8:
        handle_window_input();
        return;
    case 10:
        close_window();
    default:
        return;
    }
}

void TMedicalCenterSequence::restore_player_state() {
    TShopSequence::restore_player_state();
    set_state(1);
}

void TMedicalCenterSequence::open_greeting_window() {
    NJS_POINT2 pos;
    pos.x = 332.0f;
    pos.y = 80.0f;
    create_message_window(get_window_layout_position(0x2C), &pos);
    display_shop_message(0x1F, 1);
    meseta_window = (TWindowBase *)create_meseta_window((u16)get_player_entity_id());
    set_state(2);
    counter_camera = set_service_counter_camera(this, 0);
}

void TMedicalCenterSequence::handle_confirm() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        if (player->get_recovery_need_flags() != 0U || (player->is_alive_and_ready() != 0 && player->are_traps_full() == 0)) {
            set_state(7);
            return;
        }
        set_state(6);
    }
}

void TMedicalCenterSequence::handle_window_result() {
    s32 selected;

    if (yes_no_menu != NULL && yes_no_menu->is_decided() != 0) {
        selected = yes_no_menu->get_selected_value();
        if (selected == 0) {
            yes_no_menu->close();
            yes_no_menu = NULL;
            set_state(4);
            return;
        }
        if (selected == 1) {
            yes_no_menu->close();
            yes_no_menu = NULL;
            set_state(5);
            return;
        }
    }
    if (yes_no_menu != NULL && yes_no_menu->is_cancelled() != 0) {
        yes_no_menu->close();
        yes_no_menu = NULL;
        set_state(5);
    }
}

void TMedicalCenterSequence::exec_heal() {
    if (player->get_actor_meseta() < 0xA) {
        display_shop_message(0xF, 1);
        set_state(0xA);
        return;
    }
    play_sound_effect(0x42D08, 0, 0, 0);
    player->send_use_medical_center();
    player->send_medical_center_revive_all_players();
    if (player->is_alive_and_ready() != 0) {
        player->refill_traps();
    }
    player->send_field_state();
    player->try_spend_actor_meseta(0xA);
    display_shop_message(0x22, 1);
    set_state(0xA);
}

void TMedicalCenterSequence::show_declined() {
    display_shop_message(0x24, 1);
    set_state(8);
}

void TMedicalCenterSequence::show_already_healthy() {
    display_shop_message(0x21, 1);
    set_state(8);
}

void TMedicalCenterSequence::show_fee_prompt() {
    s32 id;
    display_shop_message(0x20, 1);
    id = player->get_entity_id();
    yes_no_menu = create_yes_no_window((const NJS_POINT2 *)(get_window_layout_position(0x2B)), id, NULL, NULL);
    ((TWindowAddition *)yes_no_menu)->set_position_xy(get_scale(), get_scale());
    set_state(3);
}

void TMedicalCenterSequence::handle_window_input() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(0x22, 1);
        set_state(0xa);
    }
}

void TMedicalCenterSequence::close_window() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        TShopSequence::close_window();
        queue_destruction();
    }
}

TMedicalCenterMes::TMedicalCenterMes(TObject *parent, TObjPlayer *player) : TObject(parent) {
    m_name = medical_center_mes_class_name;
    state = 0;
    this->player = player;
    if (this->player != NULL) {
        s32 slot = get_client_split_screen_slot(this->player->get_entity_id());
        TMedicalCenterMes::slot_flags[(u16)slot] = 1;
    }
}

TMedicalCenterMes::~TMedicalCenterMes() {
    if (player != NULL) {
        s32 slot = get_client_split_screen_slot(player->get_entity_id());
        TMedicalCenterMes::slot_flags[(u16)slot] = 0;
    }
}

void TMedicalCenterMes::init_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes::slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes::slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::run_task() {
    switch (state) {
    case 0: {
        if (player == NULL) {
            player = get_player_by_client_id(local_client_id);
        }
        set_shop_slot_active(player->get_entity_id());
        TWindowCtrl::suppress_slot(player->get_entity_id());
        NJS_POINT2 pos = {332.0f, 80.0f};
        s32 id = player->get_entity_id();
        create_message_window(get_window_layout_position(0x2C), &pos, id);
        format_shop_message(0x25, 1);
        if (player != NULL) {
            player->init_effect_5f0();
        }
        state = 1;
        break;
    }
    case 1:
        if (is_ready() != 0 && player != NULL) {
            if (test_pressed_buttons_packed(&controller_input_state.controllers[player->get_controller_port()], 4) != 0) {
                state = 2;
            }
        }
        break;
    case 2:
        if (player != NULL) {
            TObjPlayer::clear_lobby_flag(player);
        }
        close();
        if (player != NULL) {
            TWindowCtrl::unsuppress_slot(player->get_entity_id());
        }
        TShopGenerator::clear_slot_active(player->get_entity_id());
        queue_destruction();
        break;
    }
}
s32 TMedicalCenterMes::get_slot_flag(u16 client) {
    return TMedicalCenterMes::slot_flags[(u16)get_client_split_screen_slot(client)];
}
