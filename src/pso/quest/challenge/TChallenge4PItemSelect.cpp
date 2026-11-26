#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/quest/challenge/TChallenge4PItemSelect.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "types.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/object/base/TObjBase.h"


// One selectable item: the first three item-code bytes, stored as words.
struct Challenge4PItemCode {
    s32 type;
    s32 group;
    s32 subtype;
};

extern "C" {

s32 fn_8034BE30(TChallenge4PResult *);

}
s32 challenge4p_item_select_text_ids[8] = { 0x120, 0x13D, 0x159, 0x11D, 0x12A, 0x147, 0x11F, 0x14E };
Challenge4PItemCode challenge4p_item_select_item_table[8] = {
    { 0, 0x2B, 0 }, { 0, 0x48, 0 }, { 0, 0x64, 0 }, { 0, 0x28, 0 },
    { 0, 0x35, 0 }, { 0, 0x52, 0 }, { 0, 0x2A, 0 }, { 0, 0x59, 0 },
};

TChallenge4PResult *challenge4p_result_slot_entries[4];

extern "C" {



void fn_8034BE48(TObjPlayer *);
void request_active_window_close();
void fn_8034BE38(TObjPlayer *);

}
void resume_challenge_result_processing(void *result);
extern saddr tl_01;
const char *challenge_4p_result_class_name = "TChallenge4PResult";

#pragma defer_codegen on

TChallenge4PResult::TChallenge4PResult(TObject *parent, u16 slot, s32 resultCode) : TObject(parent) {
    m_name = challenge_4p_result_class_name;
    slot_index = slot;
    result_code = resultCode;
    state_1c = 0;
    message_window = 0;
    wait_frames = 90;
    unknown_30 = 0;
    for (s32 i = 0; i < 3; ++i) {
        (&reward_items[i])->init();
        reward_available[i] = 0;
    }
    challenge4p_result_slot_entries[slot_index] = this;
}

TChallenge4PResult::~TChallenge4PResult() {
    close_window();
    challenge4p_result_slot_entries[slot_index] = NULL;
}

void TChallenge4PResult::run_task() {
    if ((get_current_floor_area() != AREA_DARK_FALZ) || (TBoss4Type2::is_active() != 1)) {
        switch (state_1c) {
        case 0:
            update_input();
            return;
        case 1:
            handle_result_code();
            return;
        case 2:
            update_wait_input();
            return;
        case 3:
            queue_destruction();
            return;
        case 5:
            wait_for_reward_message();
            break;
        }
    }
}


void TChallenge4PResult::update_input() {
    s32 wait_frames;
    TWindowMessagePage *window;
    TObjPlayer *player;

    if (message_window == NULL) {
        show_message(get_localized_text_entry(0x2B, 6));
    }
    window = message_window;
    if ((window != NULL) && (window->is_message_window_ready() != 0)) {
        wait_frames = this->wait_frames;
        if (wait_frames > 0) {
            this->wait_frames = (wait_frames - 1);
            return;
        }
        player = get_player_by_client_id(this->slot_index);
        if (player != NULL) {
            if (test_pressed_buttons_packed(&controller_input_state.controllers[player->get_controller_port()], 4) != 0) {
                this->state_1c = 1;
            }
        } else {
            this->state_1c = 3;
        }
    }
}
void TChallenge4PResult::handle_result_code() {
    switch (challenge_check_rank_time((this->result_code), (this->slot_index))) {
    case 2:
        handle_third_reward();
        return;
    case 1:
        handle_second_reward();
        return;
    case 0:
        handle_first_reward();
        return;
    case -1:
        finish_result();
        return;
    case -2:
        init();
        return;
    case -3:
        init_result_state();
        return;
    case -4:
        init_timer();
        return;
    case -10:
    default:
        this->state_1c = 2;
        return;
    }
}
void TChallenge4PResult::update_wait_input() {
    TObjPlayer *player;
    player = get_player_by_client_id(this->slot_index);
    if (player != NULL) {
        if (test_pressed_buttons_packed(&controller_input_state.controllers[player->get_controller_port()], 4) != 0) {
            this->state_1c = 3;
        }
    } else {
        this->state_1c = 3;
    }
}
void TChallenge4PResult::queue_destruction() { TObject::queue_destruction(); }
void TChallenge4PResult::wait_for_reward_message() {
    s32 wait_frames;
    wait_frames = this->wait_frames - 1;
    this->wait_frames = wait_frames;
    if (wait_frames < 0) {
        this->state_1c = 2;
    }
}

void TChallenge4PResult::handle_third_reward() {
    TChallenge4PItemSelect *selector;
    if (reward_available[2] != 0) {
        show_message(get_localized_text_entry(0x2B, 0));
        challenge_create_reward_item(&reward_items[2], slot_index);
        wait_frames = 90;
        state_1c = 5;
        return;
    }
    show_message(get_localized_text_entry(0x2B, 7));
    selector = new TChallenge4PItemSelect(this, this);
    selector->onClosed = resume_challenge_result_processing;
    state_1c = 4;
}


void TChallenge4PResult::handle_second_reward() {
    show_message(get_localized_text_entry(0x2B, 2));
    challenge_create_reward_item(&reward_items[1], slot_index);
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::handle_first_reward() {
    show_message(get_localized_text_entry(0x2B, 1));
    challenge_create_reward_item(&reward_items[0], slot_index);
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::finish_result() { this->state_1c = 3; }
void TChallenge4PResult::init() {
    show_message(get_localized_text_entry(0x2B, 3));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::init_result_state() {
    show_message(get_localized_text_entry(0x2B, 4));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::init_timer() {
    show_message(get_localized_text_entry(0x2B, 5));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}

void TChallenge4PResult::show_message(saddr text_handle) {
    if (message_window == NULL) {
        f32 pos[2] = {332.0f, 80.0f};
        message_window = (TWindowMessagePage *)TWindowMessagePage::create(get_window_layout_position(0x40), (saddr)pos, 1, slot_index);
    }
    if (message_window != NULL) {
        message_window->set_message((void *)text_handle, 0x81);
        if (TCameraCtrl::get_view_count() > 2) {
            message_window->set_position_xy(0.9f, 0.9f);
        }
    }
}


void TChallenge4PResult::close_window() { if (this->message_window != 0) { this->message_window->close(); this->message_window = 0; } }
void TChallenge4PResult::set_entry_item(TItemData *item, s32 slot) {
    reward_items[slot].copy_from(item);
    reward_available[slot] = 1;
}
void TChallenge4PResult::clear_slot_entries() {
    s32 i;
    for (i = 0; i < 4; i++) {
        challenge4p_result_slot_entries[i] = NULL;
    }
}
void TChallenge4PResult::create(u16 client, s32 result_code) {
    if (get_player_by_client_id(client) != NULL) {
        new TChallenge4PResult((TObject *)tl_01, client, result_code);
    }
}

s32 update_challenge_result_player_locks() {
    s32 active = 0;
    for (s32 i = 0; i < 4; ++i) {
        if (challenge4p_result_slot_entries[i] != NULL) active = 1;
    }
    if (active) {
        for (s32 i = 0; i < 4; ++i) {
            TObjPlayer *player = get_player_by_client_id(i);
            if (player && (player)->check_player_flag1() == 0) {
                send_impose_hold(player, (int)(-1));
                obj_set_flag_20000(player);
                player->disable_palette_slot(0);
                player->disable_palette_slot(1);
                player->disable_palette_slot(2);
                player->disable_palette_slot(3);
                if ((player)->check_flag_0x40000000() == 0) fn_8034BE48(player);
                TWindowCtrl::disable_client_main_menu(player->get_entity_id());
                request_active_window_close();
                TWindowCtrl::set_close_flag();
            }
        }
    } else {
        for (s32 i = 0; i < 4; ++i) {
            TObjPlayer *player = get_player_by_client_id(i);
            if (player && (player)->check_player_flag1() != 0) {
                send_release_hold(player);
                obj_clear_flag30_20000(player);
                player->enable_all_palette_slots();
                if ((player)->check_flag_0x40000000()) fn_8034BE38(player);
                TWindowCtrl::enable_client_main_menu(player->get_entity_id());
                TWindowCtrl::clear_flag();
                TWindowCtrl::clear_flag_2();
            }
        }
    }
    return active;
}


void TChallenge4PResult::update_entries(TItemData *item, s32 slot) {
    s32 i = 0;
    TChallenge4PResult **slot_entries = challenge4p_result_slot_entries;
    s32 index = 0;
    do {
        TChallenge4PResult *entry = slot_entries[index];
        if (entry != NULL) {
            entry->set_entry_item(item, slot);
        }
        i += 1;
        index += 1;
    } while (i < 4);
}

void resume_challenge_result_processing(void *result) {
    if (result != NULL) {
        ((TChallenge4PResult *)result)->state_1c = 1;
    }
}

const char *challenge4p_item_select_name = "TChallenge4PItemSelect";

TChallenge4PItemSelect::TChallenge4PItemSelect(TObject *parent, TChallenge4PResult *resultOwner) : TObject(parent) {
    m_name = challenge4p_item_select_name;
    result = resultOwner;
    state = 0;
    onClosed = 0;
    menu_window = 0;
    waitFrames = 90;
    if (result == NULL) {
        queue_destruction();
    }
}

TChallenge4PItemSelect::~TChallenge4PItemSelect() {
    if (menu_window != nullptr) { menu_window->close(); menu_window = nullptr; }
}

void TChallenge4PItemSelect::run_task() {
    switch (state) {
    case 0:
        open_menu();
        return;
    case 1:
        submit_selected_item();
        return;
    case 2:
        close_with_callback();
        return;
    }
}

void TChallenge4PItemSelect::open_menu() {
    s32 frames_left;
    u16 client_id;
    s32 i;

    frames_left = waitFrames - 1;
    waitFrames = frames_left;
    if (frames_left <= 0) {
        client_id = fn_8034BE30(result);
        menu_window = create_window_menu(get_window_layout_position(0x42), 8, client_id);
        if (menu_window != NULL) {
            i = 0;
            do {
                menu_window->add_text_entry(get_text_collection(challenge4p_item_select_text_ids[i]), 6, i);
                i += 1;
            } while (i < 8);
            menu_window->set_scroll_target(252.0f, 1.4e+02f);
            menu_window->clamp_scroll_offset();
            menu_window->set_depth(3.9e+04f);
            if (TCameraCtrl::get_view_count() > 2) {
                menu_window->set_position_xy(0.9f, 0.9f);
            }
            state = 1;
        }
    }
}

void TChallenge4PItemSelect::submit_selected_item() {
    TItemData item;
    TChallenge4PResult *owner;
    Challenge4PItemCode *code;
    TWindowMenu *menu;
    menu = menu_window;
    if ((menu != NULL) && (menu->is_decided() != 0)) {
        code = &challenge4p_item_select_item_table[menu_window->get_selected_value()];
        item.init();
        item.data1.data_u8[0] = code->type;
        item.data1.data_u8[1] = code->group;
        item.data1.data_u8[2] = code->subtype;
        owner = result;
        if (owner != NULL) {
            owner->set_entry_item(&item, 2);
        }
        state = 2;
    }
}

void TChallenge4PItemSelect::close_with_callback() {
    void (*callback)(void *);

    callback = onClosed;
    if (callback != NULL) {
        callback(result);
    }
    queue_destruction();
}
