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

extern "C" {
saddr get_window_layout_position(int, f32);
void TMedicalCenterMes__sub_80216260(void);

extern const char *TMedicalCenterMes__class_name;
extern s32 TMedicalCenterMes__slot_flags[4];
extern s32 local_client_id;
}


#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/text_8022350C.h"

extern "C" {
s32 TMedicalCenterSequence__data_80513E90[4];
s32 TMedicalCenterMes__slot_flags[4];
}

extern "C" {
extern const char *TMedicalCenterSequence__class_name;

int obj_getPtr2B0_20(TObjPlayer *player);
void send_code50_packet__10TObjPlayerFi(TObjPlayer *player);
void send_code_49_1__10TObjPlayerFi(TObjPlayer *player);
}

struct Base_8021641C_802163AC { char pad[0x18]; };
struct Base_802165D8_802163AC { char pad[0x18]; };
struct Base_80216784_802163AC { char pad[0x18]; };
struct VBase_18_a93f07
{
  char pad[0x18];
};
struct Stack_80216830
{
  f32 sp8;
  f32 spC;
};
struct Base_802164A4 { char pad[0x18]; };
struct Base_80216540 { char pad[0x18]; };
struct Base_8021658C { char pad[0x18]; };
const char *TMedicalCenterSequence__class_name = "TMedicalCenterSequence";
const char *TMedicalCenterMes__class_name = "TMedicalCenterMes";
void TMedicalCenterSequence::clear_window_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterSequence__data_80513E90[i] = 0;
    }
}

void TMedicalCenterSequence::clear_slot_data() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterSequence__data_80513E90[i] = 0;
    }
}

TMedicalCenterSequence::TMedicalCenterSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TMedicalCenterSequence__class_name;
    state = 0;
    this->player = player;
    m_2c = NULL;
    m_30 = NULL;
    counter_camera = NULL;
    TMedicalCenterSequence__data_80513E90[get_split_screen_slot()] = 1;
}

TMedicalCenterSequence::~TMedicalCenterSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (m_2c != NULL) {
        m_2c->close();
        m_2c = NULL;
    }
    if (m_30 != NULL) {
        ((TWindowBase *)m_30)->close();
        m_30 = NULL;
    }
    TMedicalCenterSequence__data_80513E90[get_split_screen_slot()] = 0;
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

typedef struct Stack_80216830 Stack_80216830;
typedef struct VBase_18_a93f07 VBase_18_a93f07;
void TMedicalCenterSequence::open_greeting_window() {
    f32 pos[2];
    pos[0] = 332.0f;
    pos[1] = 80.0f;
    create_message_window(get_window_layout_position(0x2C, 332.0f), (saddr)pos);
    display_shop_message(0x1F, 1);
    m_2c = (TWindowBase *)create_meseta_window((u16)get_player_entity_id());
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

    if (m_30 != NULL && m_30->is_decided() != 0) {
        selected = m_30->get_selected_value();
        if (selected == 0) {
            ((TWindowBase *)m_30)->close();
            m_30 = NULL;
            set_state(4);
            return;
        }
        if (selected == 1) {
            ((TWindowBase *)m_30)->close();
            m_30 = NULL;
            set_state(5);
            return;
        }
    }
    if (m_30 != NULL && m_30->is_cancelled() != 0) {
        ((TWindowBase *)m_30)->close();
        m_30 = NULL;
        set_state(5);
    }
}

void TMedicalCenterSequence::exec_heal() {
    if (obj_getPtr2B0_20(player) < 0xA) {
        display_shop_message(0xF, 1);
        set_state(0xA);
        return;
    }
    play_sound_effect(0x42D08, 0, 0, 0);
    send_code_49_1__10TObjPlayerFi(player);
    send_code50_packet__10TObjPlayerFi(player);
    if (player->is_alive_and_ready() != 0) {
        player->refill_traps();
    }
    player->send_field_state();
    try_spend_actor_meseta(player, 0xA);
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
    m_30 = create_yes_no_window((const NJS_POINT2 *)(((s32 (*)(int))get_window_layout_position)(0x2B)), id, NULL, NULL);
    ((TWindowAddition *)m_30)->set_position_xy(get_scale(), get_scale());
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
    m_name = TMedicalCenterMes__class_name;
    state = 0;
    this->player = player;
    if (this->player != NULL) {
        s32 slot = get_client_split_screen_slot(this->player->get_entity_id());
        TMedicalCenterMes__slot_flags[(u16)slot] = 1;
    }
}

TMedicalCenterMes::~TMedicalCenterMes() {
    if (player != NULL) {
        s32 slot = get_client_split_screen_slot(player->get_entity_id());
        TMedicalCenterMes__slot_flags[(u16)slot] = 0;
    }
}

void TMedicalCenterMes__sub_80216260(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes__slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        TMedicalCenterMes__slot_flags[i] = 0;
    }
}

void TMedicalCenterMes::run_task() {
    switch (state) {
    case 0: {
        if (player == NULL) {
            player = get_player_by_client_id(local_client_id);
        }
        THunterGuildSeqOffline__sub_8021E180(player->get_entity_id());
        TWindowCtrl::suppress_slot(player->get_entity_id());
        f32 pos[2] = {332.0f, 80.0f};
        s32 id = player->get_entity_id();
        create_message_window(((s32 (*)(int))get_window_layout_position)(0x2C), (saddr)pos, id);
        format_shop_message(0x25, 1);
        if (player != NULL) {
            ((TObjPlayer *)player)->init_effect_5f0();
        }
        state = 1;
        break;
    }
    case 1:
        if (is_ready() != 0 && player != NULL) {
            if (test_pressed_buttons_packed(&controller_input_state.controllers[((TObjPlayer *)player)->get_controller_port()], 4) != 0) {
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
    return TMedicalCenterMes__slot_flags[(u16)get_client_split_screen_slot(client)];
}
