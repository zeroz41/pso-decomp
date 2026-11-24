#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_8024AB98.h"
#include "pso/quest/challenge/TChallenge4PItemSelect.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include "types.h"
#include <stddef.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/quest/challenge/TChallenge4PResult.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowMessagePage.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/item/TItemData.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/object/base/TObjBase.h"

struct Stack_8034B158 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 trailing_storage[0x11];
};

// One selectable item: the first three item-code bytes, stored as words.
struct Challenge4PItemCode {
    s32 type;
    s32 group;
    s32 subtype;
};

extern "C" {

s32 TWindowSubComCard__sub_80265500(u32);
saddr get_window_layout_position(s32);
s32 fn_8034BE30(TChallenge4PResult *);

}
s32 challenge4p_item_select_text_ids[8] = { 0x120, 0x13D, 0x159, 0x11D, 0x12A, 0x147, 0x11F, 0x14E };
Challenge4PItemCode TChallenge4PItemSelect__item_table[8] = {
    { 0, 0x2B, 0 }, { 0, 0x48, 0 }, { 0, 0x64, 0 }, { 0, 0x28, 0 },
    { 0, 0x35, 0 }, { 0, 0x52, 0 }, { 0, 0x2A, 0 }, { 0, 0x59, 0 },
};

s32 TChallenge4PResult__slot_entries[4];
struct E_8034B694 { u8 b[0x14]; };
struct Q_8034B694 { s32 v; };
struct W_8034B694 { u8 pad0[0x34]; E_8034B694 e[1]; u8 pad48[0x70 - 0x48]; Q_8034B694 f[1]; };

extern "C" {



void obj_set_flag_20000(TObjPlayer *);
void get_player_result__18TChallenge4PResultFPv(TObjPlayer *, s32);
void fn_8034BE48(TObjPlayer *);
void request_active_window_close();
void obj_clear_flag30_20000(TObjPlayer *);
void fn_8034BE38(TObjPlayer *);
void update_entries__18TChallenge4PResultFii(saddr arg0, s32 arg1);
s32 __ct__18TChallenge4PResultFP7TObjectUsl(void *, s32, int, s32);

}
s32 update_challenge_result_player_locks();
void resume_challenge_result_processing(void *arg0);
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
    TChallenge4PResult__slot_entries[slot_index] = (saddr)this;
}

TChallenge4PResult::~TChallenge4PResult() {
    close_window();
    TChallenge4PResult__slot_entries[slot_index] = 0;
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
            sub_8034BA2C();
            break;
        }
    }
}


void TChallenge4PResult::update_input() {
    s32 wait_frames;
    uaddr p;
    TObjPlayer *player;

    if ((uaddr) this->message_window == 0U) {
        this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 6))));
    }
    p = *(u32 *)&this->message_window;
    if ((p != 0U) && (((TWindowMessagePage *)p)->is_message_window_ready() != 0)) {
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
    u8 *arg0 = (u8 *)this;
    switch (TLobby__sub_80292270((this->result_code), (this->slot_index))) {
    case 2:
        ((TChallenge4PResult *)arg0)->handle_third_reward();
        return;
    case 1:
        ((TChallenge4PResult *)arg0)->sub_8034B918();
        return;
    case 0:
        ((TChallenge4PResult *)arg0)->sub_8034B8BC();
        return;
    case -1:
        ((TChallenge4PResult *)arg0)->sub_8034B8B0();
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
void TChallenge4PResult::sub_8034BA2C() {
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
        TLobby__sub_802924B4((saddr)&reward_items[2], slot_index);
        wait_frames = 90;
        state_1c = 5;
        return;
    }
    show_message(get_localized_text_entry(0x2B, 7));
    selector = new TChallenge4PItemSelect(this, this);
    selector->onClosed = resume_challenge_result_processing;
    state_1c = 4;
}


void TChallenge4PResult::sub_8034B918() {
    this->show_message((s32)((s32)((int) (get_localized_text_entry(0x2B, 2)))));
    TLobby__sub_802924B4((saddr)(((u8 *)this) + 0x48), (this->slot_index));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::sub_8034B8BC() {
    this->show_message((s32)((s32)((int) (get_localized_text_entry(0x2B, 1)))));
    TLobby__sub_802924B4((saddr)(((u8 *)this) + 0x34), (this->slot_index));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::sub_8034B8B0() { this->state_1c = 3; }
void TChallenge4PResult::init() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 3))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::init_result_state() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 4))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
void TChallenge4PResult::init_timer() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 5))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}

void TChallenge4PResult::show_message(saddr text_handle) {
    if (message_window == NULL) {
        f32 pos[2] = {332.0f, 80.0f};
        message_window = (TWindowMessagePage *)TWindowMessagePage::create(get_window_layout_position(0x40), (saddr)pos, 1, slot_index);
    }
    if (message_window != NULL) {
        ((TWindowMessagePage *)message_window)->set_message((void *)text_handle, 0x81);
        if (TCameraCtrl::get_view_count() > 2) {
            ((TWindowAddition *)message_window)->set_position_xy(0.9f, 0.9f);
        }
    }
}


void TChallenge4PResult::close_window() { if (this->message_window != 0) { this->message_window->close(); this->message_window = 0; } }
void TChallenge4PResult::set_entry_item(void *arg1, s32 arg2) {
    W_8034B694 *arg0 = (W_8034B694 *)this;
    ((TItemData *)(&arg0->e[arg2]))->copy_from((TItemData *)(arg1));
    arg0->f[arg2].v = 1;
}
void TChallenge4PResult::clear_slot_entries() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TChallenge4PResult__slot_entries)[i] = 0;
    }
}
void TChallenge4PResult::create(int client, s32 arg1) {
    void *temp;

    if (get_player_by_client_id((u16)client) != NULL) {
        temp = (void *) TObject::operator new(0x7C);
        if (temp != NULL) {
            __ct__18TChallenge4PResultFP7TObjectUsl(temp, tl_01, client, arg1);
        }
    }
}

s32 update_challenge_result_player_locks() {
    s32 active = 0;
    for (s32 i = 0; i < 4; ++i) {
        if (((TChallenge4PResult * *)&TChallenge4PResult__slot_entries)[i] != 0) active = 1;
    }
    if (active) {
        for (s32 i = 0; i < 4; ++i) {
            TObjPlayer *player = get_player_by_client_id(i);
            if (player && ((TObjPlayer *)player)->check_player_flag1() == 0) {
                send_impose_hold(player, (int)(-1));
                obj_set_flag_20000(player);
                get_player_result__18TChallenge4PResultFPv(player, 0);
                get_player_result__18TChallenge4PResultFPv(player, 1);
                get_player_result__18TChallenge4PResultFPv(player, 2);
                get_player_result__18TChallenge4PResultFPv(player, 3);
                if (((TObjPlayer *)player)->check_flag_0x40000000() == 0) fn_8034BE48(player);
                TWindowCtrl::disable_client_main_menu(player->get_entity_id());
                request_active_window_close();
                TWindowCtrl::set_close_flag();
            }
        }
    } else {
        for (s32 i = 0; i < 4; ++i) {
            TObjPlayer *player = get_player_by_client_id(i);
            if (player && ((TObjPlayer *)player)->check_player_flag1() != 0) {
                send_release_hold(player);
                obj_clear_flag30_20000(player);
                ((TChallenge4PResult *)player)->get_player_rank();
                if (((TObjPlayer *)player)->check_flag_0x40000000()) fn_8034BE38(player);
                TWindowCtrl::enable_client_main_menu(player->get_entity_id());
                TWindowCtrl::clear_flag();
                TWindowCtrl::clear_flag_2();
            }
        }
    }
    return active;
}


void update_entries__18TChallenge4PResultFii(saddr arg0, s32 arg1) {
    s32 i = 0;
    s32 *var_r30 = TChallenge4PResult__slot_entries;
    s32 var_r31 = 0;
    do {
        uaddr v = (u32)var_r30[var_r31];
        if (v != 0U) {
            ((TChallenge4PResult *)v)->set_entry_item((void *)arg0, arg1);
        }
        i += 1;
        var_r31 += 1;
    } while (i < 4);
}

void resume_challenge_result_processing(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 1;
    }
}

const char *TChallenge4PItemSelect__name = "TChallenge4PItemSelect";

TChallenge4PItemSelect::TChallenge4PItemSelect(TObject *parent, TChallenge4PResult *resultOwner) : TObject(parent) {
    m_name = TChallenge4PItemSelect__name;
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
    if (menu_window != nullptr) { ((TWindowBase *)menu_window)->close(); menu_window = nullptr; }
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
    s32 temp_r0;
    u16 client_id;
    s32 i;

    temp_r0 = waitFrames - 1;
    waitFrames = temp_r0;
    if (temp_r0 <= 0) {
        client_id = fn_8034BE30(result);
        (uaddr &)menu_window = (uaddr)create_window_menu((saddr)get_window_layout_position(0x42), 8, client_id);
        if ((uaddr)menu_window != 0U) {
            i = 0;
            do {
                ((TWindowMenu *)menu_window)->add_text_entry(get_text_collection(challenge4p_item_select_text_ids[i]), 6, i);
                i += 1;
            } while (i < 8);
            ((TWindowSubComCardList *)menu_window)->set_scroll_target(252.0f, 1.4e+02f);
            TWindowSubComCard__sub_80265500((u32 &)menu_window);
            ((TWindowBase *)menu_window)->set_depth(3.9e+04f);
            if (TCameraCtrl::get_view_count() > 2) {
                ((TWindowAddition *)menu_window)->set_position_xy(0.9f, 0.9f);
            }
            state = 1;
        }
    }
}

void TChallenge4PItemSelect::submit_selected_item() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8034B158, sp8) == 0x0);
    LAYOUT_ASSERT(sp9_offset, offsetof(Stack_8034B158, sp9) == 0x1);
    LAYOUT_ASSERT(spA_offset, offsetof(Stack_8034B158, spA) == 0x2);
    Stack_8034B158 stack;
    uaddr temp_r3_2;
    u8 *temp_r31;
    u8 *window_menu;
    window_menu = (u8 *)((u8 *)menu_window);
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_decided() != 0)) {
        temp_r31 = (u8 *)&TChallenge4PItemSelect__item_table[((TWindowMenu *)menu_window)->get_selected_value()];
        ((TItemData *)(&stack.sp8))->init();
        stack.sp8 = (s8) *(s32 *)((s8 *)temp_r31 + 0);
        stack.sp9 = (s8) *(s32 *)((s8 *)temp_r31 + 4);
        stack.spA = (s8) *(s32 *)((s8 *)temp_r31 + 8);
        temp_r3_2 = (uaddr)result;
        if (temp_r3_2 != 0U) {
            ((TChallenge4PResult *)temp_r3_2)->set_entry_item((void *)((saddr) &stack.sp8), 2);
        }
        state = 2;
    }
}

void TChallenge4PItemSelect::close_with_callback() {
    void (*temp_r12)(void *);

    temp_r12 = onClosed;
    if (temp_r12 != NULL) {
        temp_r12(result);
    }
    queue_destruction();
}
