#include "pso/ui/TChallenge4PItemSelect.h"
#include "pso/protocol/protocol_types.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowMenu.h"
#include "types.h"
#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TChallenge4PResult.h"
#include "pso/misc/TLobby_80291D94.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowMessagePage.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TWindowCtrl.h"

struct Stack_8034B158 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 trailing_storage[0x11];
};

struct RecoveredGlobal_8034B158_lbl_804F00C8 {
    s32 value;
    u8 remaining[0x5C];
};

extern "C" {
void init__9TItemDataFv(void *);
s32 get_selected_menu_value(void *);
extern RecoveredGlobal_8034B158_lbl_804F00C8 TChallenge4PItemSelect__item_table;
}

extern "C" {

u32 create_window_menu(s32, s32, s32);
s32 TWindowSubComCard__sub_80265500(u32);
s32 get_window_layout_position(s32);
s32 fn_8034BE30(TChallenge4PResult *);
s32 forward_trade_action_default__16TObjCityMainWarpFPviii(u32, s32, s32, s32);

}
extern s32 challenge4p_item_select_text_ids[];
typedef char RecoveredGlobal_8034B158_lbl_804F00C8_size[sizeof(RecoveredGlobal_8034B158_lbl_804F00C8) == 0x60 ? 1 : -1];
extern void *lbl_805D433C;

extern "C" { s32 TChallenge4PResult__slot_entries[4]; }

struct E_8034B694 { u8 b[0x14]; };
struct Q_8034B694 { s32 v; };
struct W_8034B694 { u8 pad0[0x34]; E_8034B694 e[1]; u8 pad48[0x70 - 0x48]; Q_8034B694 f[1]; };

struct RecoveredGlobal_8034BA68_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

struct Stack_8034B720 {
    s32 sp8;
    s32 spC;
};

extern "C" {
s32 get_localized_text_entry(s32, s32);
s32 is_active__11TBoss4Type2Fv();

s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32);
s32 get_map_id__13TRaderMapCoreFv();
u32 get_player_by_client_id(int);
extern u8 controller_input_state[];
extern s32 TChallenge4PResult__slot_entries[];

extern s32 lbl_80478BCC[];

void play_effect_default__10TObjPlayerFii(TObjPlayer *, s32);
void obj_set_flag_20000(TObjPlayer *);
void get_player_result__18TChallenge4PResultFPv(TObjPlayer *, s32);
void fn_8034BE48(TObjPlayer *);
u32 get_entity_id(TObjPlayer *);
void TObjPlayer__sub_8024ABDC(u16);
void request_active_window_close();
void obj_clear_flag30_20000(TObjPlayer *);
void fn_8034BE38(TObjPlayer *);
void TLobby__sub_8024AC20(u16);
void update_entries__18TChallenge4PResultFii(s32 arg0, s32 arg1);
s32 __ct__18TChallenge4PResultFP7TObjectUsl(void *, s32, int, s32);
void TWindow__close(u8 *arg0);
u32 __nw__7TObjectFUl(s32);

}
s32 update_challenge_result_player_locks();
void resume_challenge_result_processing(void *arg0);
extern s32 tl_01;
typedef char RecoveredGlobal_8034BA68_lbl_8050E208_size[sizeof(RecoveredGlobal_8034BA68_lbl_8050E208) == 0x1B0 ? 1 : -1];
extern "C" { extern const char *challenge_4p_result_class_name; }

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
        init__9TItemDataFv(&reward_items[i]);
        reward_available[i] = 0;
    }
    TChallenge4PResult__slot_entries[slot_index] = (s32)this;
}

TChallenge4PResult::~TChallenge4PResult() {
    close_window();
    TChallenge4PResult__slot_entries[slot_index] = 0;
}

void TChallenge4PResult::run_task() {
    if ((TOKeyMachine01::get_global_state() != 0xE) || (is_active__11TBoss4Type2Fv() != 1)) {
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

extern "C" {
void TChallenge4PResult::update_input() {
    s32 temp_r3;
    s32 temp_r5;
    u32 p;

    if ((u32) this->message_window == 0U) {
        this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 6))));
    }
    p = *(u32 *)&this->message_window;
    if ((p != 0U) && (((TWindowMessagePage *)p)->is_message_window_ready() != 0)) {
        temp_r3 = this->wait_frames;
        if (temp_r3 > 0) {
            this->wait_frames = (temp_r3 - 1);
            return;
        }
        if (get_player_by_client_id(this->slot_index) != 0U) {
            temp_r5 = get_map_id__13TRaderMapCoreFv() * 0x50;
            if (TWindowShortListCtrl__check_controller_button(controller_input_state + temp_r5 + 0x20, 4, temp_r5) != 0) {
                this->state_1c = 1;
            }
        } else {
            this->state_1c = 3;
        }
    }
}
}

extern "C" {
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
}

extern "C" {
void TChallenge4PResult::update_wait_input() {
    s32 temp_r5;
    if (get_player_by_client_id(this->slot_index) != 0U) {
        temp_r5 = get_map_id__13TRaderMapCoreFv() * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *)((void *) ((u8 *)&(*(RecoveredGlobal_8034BA68_lbl_8050E208 *)&controller_input_state).value + temp_r5 + 0x20)), 4, temp_r5) != 0) {
            this->state_1c = 3;
        }
    } else {
        this->state_1c = 3;
    }
}
}

extern "C" {
void TChallenge4PResult::queue_destruction() { queue_destruction__7TObjectFv(this); }
}

extern "C" {
void TChallenge4PResult::sub_8034BA2C() {
    s32 temp_r0;
    temp_r0 = this->wait_frames - 1;
    this->wait_frames = temp_r0;
    if (temp_r0 < 0) {
        this->state_1c = 2;
    }
}
}

void TChallenge4PResult::handle_third_reward() {
    TChallenge4PItemSelect *selector;
    if (reward_available[2] != 0) {
        show_message(get_localized_text_entry(0x2B, 0));
        TLobby__sub_802924B4((s32)&reward_items[2], slot_index);
        wait_frames = 90;
        state_1c = 5;
        return;
    }
    show_message(get_localized_text_entry(0x2B, 7));
    selector = new TChallenge4PItemSelect(this, this);
    selector->onClosed = resume_challenge_result_processing;
    state_1c = 4;
}

extern "C" {
void TChallenge4PResult::sub_8034B918() {
    this->show_message((s32)((s32)((int) (get_localized_text_entry(0x2B, 2)))));
    TLobby__sub_802924B4((s32)(((u8 *)this) + 0x48), (this->slot_index));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
}

extern "C" {
void TChallenge4PResult::sub_8034B8BC() {
    this->show_message((s32)((s32)((int) (get_localized_text_entry(0x2B, 1)))));
    TLobby__sub_802924B4((s32)(((u8 *)this) + 0x34), (this->slot_index));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
}

extern "C" {
void TChallenge4PResult::sub_8034B8B0() { this->state_1c = 3; }
}

extern "C" {
void TChallenge4PResult::init() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 3))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
}

extern "C" {
void TChallenge4PResult::init_result_state() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 4))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
}

extern "C" {
void TChallenge4PResult::init_timer() {
    this->show_message((s32)((s32)(get_localized_text_entry(0x2B, 5))));
    this->wait_frames = 0x5A;
    this->state_1c = 5;
}
}

void TChallenge4PResult::show_message(s32 text_handle) {
    typedef char sp8_offset[(offsetof(Stack_8034B720, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8034B720, spC) == 0x4) ? 1 : -1];
    Stack_8034B720 stack;
    if (message_window == NULL) {
        stack.sp8 = *(s32 *)((s8 *)lbl_80478BCC + 0);
        stack.spC = *(s32 *)((s8 *)lbl_80478BCC + 4);
        message_window = (TWindowMessagePage *)TWindowMessagePage::create(get_window_layout_position(0x40), (s32)&stack.sp8, 1, slot_index);
    }
    if (message_window != NULL) {
        ((TWindowMessagePage *)message_window)->set_message((void *)text_handle, 0x81);
        if (TCameraCtrl::get_instance() > 2) {
            ((TUnk_804CDFE8 *)message_window)->set_position_xy(0.9f, 0.9f);
        }
    }
}

extern "C" {
void TChallenge4PResult::close_window() { if (this->message_window != 0) { TWindow__close((u8 *)this->message_window); this->message_window = 0; } }
}

extern "C" {
void TChallenge4PResult::set_entry_item(void *arg1, s32 arg2) {
    W_8034B694 *arg0 = (W_8034B694 *)this;
    ((TItemData *)(&arg0->e[arg2]))->copy_from((TItemData *)(arg1));
    arg0->f[arg2].v = 1;
}
}

extern "C" {
void TChallenge4PResult::clear_slot_entries() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((s32 *)&TChallenge4PResult__slot_entries)[i] = 0;
    }
}
}

extern "C" {
void TChallenge4PResult::create(int arg0, s32 arg1) {
    void *temp;

    if (get_player_by_client_id((u16)arg0) != 0U) {
        temp = (void *) __nw__7TObjectFUl(0x7C);
        if (temp != NULL) {
            __ct__18TChallenge4PResultFP7TObjectUsl(temp, tl_01, arg0, arg1);
        }
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
            TObjPlayer *player = ((TObjPlayer *)get_player_by_client_id(i));
            if (player && ((TLobby *)player)->check_player_flag1() == 0) {
                play_effect_default__10TObjPlayerFii(player, -1);
                obj_set_flag_20000(player);
                get_player_result__18TChallenge4PResultFPv(player, 0);
                get_player_result__18TChallenge4PResultFPv(player, 1);
                get_player_result__18TChallenge4PResultFPv(player, 2);
                get_player_result__18TChallenge4PResultFPv(player, 3);
                if (((TObjPlayer *)player)->check_flag_0x40000000() == 0) fn_8034BE48(player);
                TObjPlayer__sub_8024ABDC(get_entity_id(player));
                request_active_window_close();
                TWindowCtrl::set_close_flag();
            }
        }
    } else {
        for (s32 i = 0; i < 4; ++i) {
            TObjPlayer *player = ((TObjPlayer *)get_player_by_client_id(i));
            if (player && ((TLobby *)player)->check_player_flag1() != 0) {
                TObjPlayer::send_code_45_1((s32)player);
                obj_clear_flag30_20000(player);
                ((TChallenge4PResult *)player)->get_player_rank();
                if (((TObjPlayer *)player)->check_flag_0x40000000()) fn_8034BE38(player);
                TLobby__sub_8024AC20(get_entity_id(player));
                TWindowCtrl::clear_flag();
                TWindowCtrl::clear_flag_2();
            }
        }
    }
    return active;
}

extern "C" {
void update_entries__18TChallenge4PResultFii(s32 arg0, s32 arg1) {
    s32 var_r29 = 0;
    s32 *var_r30 = TChallenge4PResult__slot_entries;
    s32 var_r31 = 0;
    do {
        u32 v = (u32)var_r30[var_r31];
        if (v != 0U) {
            ((TChallenge4PResult *)v)->set_entry_item((void *)arg0, arg1);
        }
        var_r29 += 1;
        var_r31 += 1;
    } while (var_r29 < 4);
}
}

void resume_challenge_result_processing(void *arg0) {
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 1;
    }
}

TChallenge4PItemSelect::TChallenge4PItemSelect(TObject *parent, TChallenge4PResult *resultOwner) : TObject(parent) {
    m_name = (const char *)lbl_805D433C;
    result = resultOwner;
    state = 0;
    onClosed = 0;
    menu_window = 0;
    waitFrames = 90;
    if (result == NULL) {
        queue_destruction__7TObjectFv(this);
    }
}

TChallenge4PItemSelect::~TChallenge4PItemSelect() {
    if (menu_window != nullptr) { TWindow__close((u8 *)menu_window); menu_window = nullptr; }
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
    u16 temp_r30;
    s32 var_r29;

    temp_r0 = waitFrames - 1;
    waitFrames = temp_r0;
    if (temp_r0 <= 0) {
        temp_r30 = fn_8034BE30(result);
        (u32 &)menu_window = create_window_menu(get_window_layout_position(0x42), 8, temp_r30);
        if ((u32) (u32 &)menu_window != 0U) {
            var_r29 = 0;
            do {
                forward_trade_action_default__16TObjCityMainWarpFPviii((u32 &)menu_window, get_text_collection(challenge4p_item_select_text_ids[var_r29]), 6, var_r29);
                var_r29 += 1;
            } while (var_r29 < 8);
            ((TWindowSubComCardList *)((u32 &)menu_window))->set_scroll_target(252.0f, 1.4e+02f);
            TWindowSubComCard__sub_80265500((u32 &)menu_window);
            ((TLobby *)((u32 &)menu_window))->set_field_1c(3.9e+04f);
            if (TCameraCtrl::get_instance() > 2) {
                ((TUnk_804CDFE8 *)((u32 &)menu_window))->set_position_xy(0.9f, 0.9f);
            }
            state = 1;
        }
    }
}

void TChallenge4PItemSelect::submit_selected_item() {
    typedef char sp8_offset[(offsetof(Stack_8034B158, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_8034B158, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_8034B158, spA) == 0x2) ? 1 : -1];
    Stack_8034B158 stack;
    u32 temp_r3_2;
    u8 *temp_r31;
    u8 *window_menu;
    window_menu = (u8 *)((u8 *)menu_window);
    if ((window_menu != NULL) && (((TWindowMenu *)window_menu)->is_visible() != 0)) {
        temp_r31 = (u8 *)&TChallenge4PItemSelect__item_table.value + (get_selected_menu_value((u8 *)menu_window) * 0xC);
        init__9TItemDataFv(&stack.sp8);
        stack.sp8 = (s8) *(s32 *)((s8 *)temp_r31 + 0);
        stack.sp9 = (s8) *(s32 *)((s8 *)temp_r31 + 4);
        stack.spA = (s8) *(s32 *)((s8 *)temp_r31 + 8);
        temp_r3_2 = (u32)result;
        if (temp_r3_2 != 0U) {
            ((TChallenge4PResult *)temp_r3_2)->set_entry_item((void *)((s32) &stack.sp8), 2);
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
    queue_destruction__7TObjectFv(this);
}
