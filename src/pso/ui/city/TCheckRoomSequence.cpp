#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/unk/text_8026934C.h"
#include "types.h"
#include "pso/ui/window/TWindowDeposit.h"
#include "pso/ui/window/TWindowMeseta.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

#include "pso/ui/city/TShopSequence.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TShopKeepItemWindow.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopDeleteItemWindow.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_80222C28.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/city/TShopEquipmentSellWindow.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowInputNumber.h"
#include "pso/item/TItemData.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_8022350C.h"

#pragma readonly_strings on


const char *TCheckRoomSequence__name = "TCheckRoomSequence";
s32 lbl_805D6160;
s32 TCheckRoomSequence__error_return_text_id;
saddr TCheckRoomSequence__error_return_state;
s32 TCheckRoomSequence__active_instance;


#pragma optimization_level 1


typedef void (TCheckRoomSequence::*Fn_802102D0)();

struct Card_8021118C { u8 pad[0x248]; s32 count; s32 meseta; u8 items[1]; };

struct Rec_80210F78
{
  u8 b[0x14];
  s16 f14;
  s16 f16;
};

extern "C" {
// The runtime's array new and BankItemRecord::BankItemRecord(), whose address
// C++ does not let alloc_item_buffers take.
void *__construct_new_array(void *block, void *ctor, void *dtor, u32 size, u32 count);
void __ct__14BankItemRecordFv();
s32 get_max_stack_size__9TItemDataFv(void *);
s32 TCheckRoomSequence__sub_80210B34(TItemData *item, s32 amount, s32 slot);

BankItemRecord *bank_item_records_by_slot[4];
s32 bank_item_count_by_slot[4];
s32 bank_meseta_by_slot[4];
u32 TCheckRoomSequence__slot_active_flags[4];

s32 TCheckRoomSequence::check_room_ready() {
    if (TRaderMapCore::is_not_split_screen() == 0) {
        return 1;
    }
    return (u32)__cntlzw(get_game_play_mode()) >> 5;
}

void TCheckRoomSequence::close_extra_window() {
    if (extra_window) {
        extra_window->close();
        extra_window = 0;
    }
}

void TCheckRoomSequence::init_check_params(TShopWindowBase *sequence) {
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    if (sequence != NULL) {
        sequence->set_state(0x10);
    }
}

void TCheckRoomSequence::finish_room_check(TShopWindowBase *sequence) {
    if (sequence != NULL) {
        sequence->display_shop_message(0x46, 1);
    }
    if (sequence != NULL) {
        sequence->set_state(2);
    }
}

void TCheckRoomSequence::init_check(TShopWindowBase *sequence) {
    if (sequence != NULL) {
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        sequence->set_state(0x10);
    }
}

void TCheckRoomSequence::notify_quest_list_vm(TShopWindowBase *sequence) {
    if (sequence != NULL) {
        sequence->display_shop_message(0x1A, 1);
        sequence->set_state(2);
    }
}
}
s32 get_bank_meseta_capacity(s32 i);
s32 bank_credit_meseta(s32 v, s32 i);
s32 bank_debit_meseta(s32 v, s32 i);
void copy_bank_from_card_window(s32 slot);
void TCheckRoomSequence::sub_8020F1DC() {  }


void TCheckRoomSequence::handle_error_ack() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_shop_message(TCheckRoomSequence__error_return_text_id, 1);
        set_state(TCheckRoomSequence__error_return_state);
    }
}

void TCheckRoomSequence::open_delete_item_window() {
    TShopDeleteItemWindow *window = new TShopDeleteItemWindow(tl_05, this, player);
    window->on_close = notify_quest_list_vm;
    window->on_empty = init_check;
    reset_controller_input_state();
    set_state(0x11);
}

void TCheckRoomSequence::open_get_item_window() {
    TShopGetItemWindow *window = new TShopGetItemWindow(tl_05, this, player);
    window->on_close = notify_quest_list_vm;
    window->on_empty = init_check;
    reset_controller_input_state();
    set_state(0x11);
}

void TCheckRoomSequence::accept_meseta_withdrawal() {
    s32 amount;
    s32 slot;
    if (number_input != NULL && number_input->is_confirmed() != 0) {
        amount = number_input->get_value();
        slot = get_split_screen_slot();
        bank_debit_meseta(amount, slot);
        player->add_meseta(amount);
        copy_bank_to_card_window(slot);
        if (deposit_window != NULL) {
            deposit_window->set_meseta(get_room_data(slot));
        }
        display_shop_message(0x46, 1);
        set_state(2);
        number_input->close();
        number_input = NULL;
    }
    if (number_input != NULL && number_input->is_cancelled() != 0) {
        display_shop_message(0x46, 1);
        set_state(0xA);
        number_input->close();
        number_input = NULL;
    }
}

void TCheckRoomSequence::begin_meseta_withdrawal() {
    s32 bank_meseta;
    s32 amount;
    bank_meseta = get_room_data(get_split_screen_slot());
    if (bank_meseta > 0) {
        amount = 999999 - obj_getPtr2B0_20((u8 *)player);
        amount = (amount < bank_meseta) ? amount : bank_meseta;
        if (amount > 0) {
            if (number_input == NULL) {
                number_input = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, amount, 1, get_player_entity_id());
                if (number_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    number_input->set_scale(0.75f, 0.75f);
                }
            }
            reset_controller_input_state();
            display_shop_message(0x3F, 1);
            set_state(0xC);
            return;
        }
        display_shop_message(0x4A, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_state(0x10);
        return;
    }
    display_shop_message(0x3D, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    set_state(0x10);
}

void TCheckRoomSequence::accept_meseta_deposit() {
    s32 amount;
    s32 slot;
    if (number_input != NULL && number_input->is_confirmed() != 0) {
        amount = number_input->get_value();
        slot = get_split_screen_slot();
        bank_credit_meseta(amount, slot);
        try_spend_actor_meseta(player, amount);
        copy_bank_to_card_window(slot);
        if (deposit_window != NULL) {
            deposit_window->set_meseta(get_room_data(slot));
        }
        display_shop_message(0x46, 1);
        set_state(2);
        number_input->close();
        number_input = NULL;
    }
    if (number_input != NULL && number_input->is_cancelled() != 0) {
        display_shop_message(0x46, 1);
        set_state(3);
        number_input->close();
        number_input = NULL;
    }
}

void TCheckRoomSequence::begin_meseta_deposit() {
    s32 slot;
    s32 meseta;
    s32 amount;
    slot = get_split_screen_slot();
    if (get_bank_meseta_capacity(slot) > 0) {
        meseta = obj_getPtr2B0_20((u8 *)player);
        if (meseta > 0) {
            amount = get_bank_meseta_capacity(slot);
            amount = (amount < meseta) ? amount : meseta;
            if (number_input == NULL) {
                number_input = new TWindowInputNumber((void *)get_window_layout_position(0x2B), 1, amount, 1, get_player_entity_id());
                if (number_input != NULL && TLobby::is_camera_ctrl_active() > 2) {
                    number_input->set_scale(0.75f, 0.75f);
                }
            }
            reset_controller_input_state();
            display_shop_message(0x34, 1);
            set_state(5);
            return;
        }
        display_shop_message(0x47, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_state(0x10);
        return;
    }
    display_shop_message(0x37, 1);
    TCheckRoomSequence__error_return_text_id = 0x46;
    TCheckRoomSequence__error_return_state = 2;
    set_state(0x10);
}

void TCheckRoomSequence::open_deposit_item_window() {
    TShopKeepItemWindow *window;
    if (get_room_table_entry(get_split_screen_slot()) > 0xC8) {
        display_shop_message(0x3C, 1);
        TCheckRoomSequence__error_return_text_id = 0x46;
        TCheckRoomSequence__error_return_state = 2;
        set_state(0x10);
        return;
    }
    display_shop_message(0x38, 1);
    window = new TShopKeepItemWindow(tl_05, this, player);
    window->ok_callback = finish_room_check;
    window->cancel_callback = init_check_params;
    reset_controller_input_state();
    set_state(0x11);
}

void TCheckRoomSequence::set_quest_list_mode_19() { set_state(19); }

void TCheckRoomSequence::handle_withdraw_choice() {
    s32 selected_menu_value;
    switch (menu_step) {
    case 0:
        if (choice_menu == NULL) {
            choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
            choice_menu->add_text_entry(get_shop_text(2), 6, 0);
            choice_menu->add_text_entry(get_shop_text(3), 6, 1);
            choice_menu->calc_window_size();
            align_menu_entry_positions(choice_menu);
            choice_menu->set_ready_flag();
            choice_menu->set_position_xy(get_scale(), get_scale());
        }
        display_shop_message(0x32, 1);
        menu_step = 1;
        return;
    case 1:
        if (choice_menu != NULL && choice_menu->is_decided() != 0) {
            selected_menu_value = choice_menu->get_selected_value();
            if (selected_menu_value == 0) {
                set_state(7);
                choice_menu->close();
                choice_menu = NULL;
            }
            if (selected_menu_value == 1) {
                set_state(9);
                choice_menu->close();
                choice_menu = NULL;
            }
            menu_step = 0;
        }
        if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
            display_shop_message(0x46, 1);
            set_state(2);
            choice_menu->close();
            choice_menu = NULL;
            menu_step = 0;
        }
        return;
    }
}

void TCheckRoomSequence::handle_deposit_choice() {
    s32 selected_menu_value;
    switch (menu_step) {
    case 0:
        if (choice_menu == NULL) {
            choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
            choice_menu->add_text_entry(get_shop_text(2), 6, 0);
            choice_menu->add_text_entry(get_shop_text(3), 6, 1);
            choice_menu->calc_window_size();
            align_menu_entry_positions(choice_menu);
            choice_menu->set_ready_flag();
            choice_menu->set_position_xy(get_scale(), get_scale());
        }
        display_shop_message(0x33, 1);
        menu_step = 1;
        return;
    case 1:
        if (choice_menu != NULL && choice_menu->is_decided() != 0) {
            selected_menu_value = choice_menu->get_selected_value();
            if (selected_menu_value == 0) {
                set_state(6);
                choice_menu->close();
                choice_menu = NULL;
            }
            if (selected_menu_value == 1) {
                set_state(4);
                choice_menu->close();
                choice_menu = NULL;
            }
            menu_step = 0;
        }
        if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
            display_shop_message(0x46, 1);
            set_state(2);
            choice_menu->close();
            choice_menu = NULL;
            menu_step = 0;
        }
        return;
    }
}

void TCheckRoomSequence::handle_root_choice() {
    s32 selected_menu_value;
    s32 selected_value;
    if (check_room_ready() != 0) {
        switch (menu_step) {
        case 0:
            if (choice_menu == NULL) {
                choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
                choice_menu->add_text_entry(get_shop_text(8), 6, 0);
                choice_menu->add_text_entry(get_shop_text(9), 6, 1);
                choice_menu->calc_window_size();
                align_menu_entry_positions(choice_menu);
                choice_menu->set_ready_flag();
                choice_menu->set_position_xy(get_scale(), get_scale());
            }
            menu_step = 1;
            return;
        case 1:
            if (choice_menu != NULL && choice_menu->is_decided() != 0) {
                selected_menu_value = choice_menu->get_selected_value();
                if (selected_menu_value == 0) {
                    set_state(3);
                    choice_menu->close();
                    choice_menu = NULL;
                }
                if (selected_menu_value == 1) {
                    set_state(0xA);
                    choice_menu->close();
                    choice_menu = NULL;
                }
                menu_step = 0;
            }
            if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
                display_shop_message(0x48, 1);
                set_state(0xD);
                choice_menu->close();
                choice_menu = NULL;
                menu_step = 0;
                return;
            }
            break;
        }
    } else {
        switch (menu_step) {
        case 0:
            if (choice_menu == NULL) {
                choice_menu = create_window_menu((saddr)get_window_layout_position(0x2B), 2, player->get_entity_id());
                choice_menu->add_text_entry(get_shop_text(0xA), 6, 1);
                choice_menu->calc_window_size();
                align_menu_entry_positions(choice_menu);
                choice_menu->set_ready_flag();
                choice_menu->set_position_xy(get_scale(), get_scale());
            }
            menu_step = 1;
            return;
        case 1:
            if (choice_menu != NULL && choice_menu->is_decided() != 0) {
                selected_value = choice_menu->get_selected_value();
                if (selected_value == 0) {
                    set_state(0xA);
                    choice_menu->close();
                    choice_menu = NULL;
                }
                if (selected_value == 1) {
                    set_state(0x12);
                    choice_menu->close();
                    choice_menu = NULL;
                }
                menu_step = 0;
            }
            if (choice_menu != NULL && choice_menu->is_cancelled() != 0) {
                display_shop_message(0x48, 1);
                set_state(0xD);
                choice_menu->close();
                choice_menu = NULL;
                menu_step = 0;
            }
            return;
        }
    }
}

void TCheckRoomSequence::sub_802100F8() {  }
void TCheckRoomSequence::sub_802100FC() {  }
extern "C" {

void TCheckRoomSequence::close_window() {
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0)) && (poll_memcard_result(((s8)TAdSinglePlyChrSelectGC::get_chr_select_state())) == 0)) {
        copy_bank_to_card_window(get_split_screen_slot());
        close_if_single_screen();
        TShopSequence::close_window();
        queue_destruction();
    }
}

void TCheckRoomSequence::open_bank() {
    NJS_POINT2 position;
    position.x = 332.0f;
    position.y = 80.0f;
    create_message_window((saddr)get_window_layout_position(0x2C), (saddr)&position);
    display_shop_message(0x31, 1);
    meseta_window = create_meseta_window(get_player_entity_id());
    deposit_window = new TWindowDeposit(get_player_entity_id());
    deposit_window->set_meseta(get_room_data(get_split_screen_slot()));
    menu_step = 0;
    counter_camera = set_service_counter_camera(this, 6);
    set_state(2);
}

void TCheckRoomSequence::restore_player_state() {
    TShopSequence::restore_player_state();
    copy_bank_from_card_window(get_split_screen_slot());
    set_state(1);
}

void TCheckRoomSequence::update_state() {
    static Fn_802102D0 fns[20] = {
        (Fn_802102D0)&TCheckRoomSequence::restore_player_state,
        (Fn_802102D0)&TCheckRoomSequence::open_bank,
        (Fn_802102D0)&TCheckRoomSequence::handle_root_choice,
        (Fn_802102D0)&TCheckRoomSequence::handle_deposit_choice,
        (Fn_802102D0)&TCheckRoomSequence::open_deposit_item_window,
        (Fn_802102D0)&TCheckRoomSequence::accept_meseta_deposit,
        (Fn_802102D0)&TCheckRoomSequence::begin_meseta_deposit,
        (Fn_802102D0)&TCheckRoomSequence::begin_meseta_withdrawal,
        0,
        (Fn_802102D0)&TCheckRoomSequence::open_get_item_window,
        (Fn_802102D0)&TCheckRoomSequence::handle_withdraw_choice,
        (Fn_802102D0)&TCheckRoomSequence::close_window,
        (Fn_802102D0)&TCheckRoomSequence::accept_meseta_withdrawal,
        (Fn_802102D0)&TCheckRoomSequence::close_window,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100FC,
        (Fn_802102D0)&TCheckRoomSequence::sub_802100F8,
        (Fn_802102D0)&TCheckRoomSequence::handle_error_ack,
        (Fn_802102D0)&TCheckRoomSequence::sub_8020F1DC,
        (Fn_802102D0)&TCheckRoomSequence::set_quest_list_mode_19,
        (Fn_802102D0)&TCheckRoomSequence::open_delete_item_window,
    };
    if (fns[state]) {
        (this->*fns[state])();
    }
}


#pragma push
#pragma optimization_level 1
TCheckRoomSequence::~TCheckRoomSequence() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (number_input != NULL) {
        number_input->close();
        number_input = NULL;
    }
    if (deposit_window != NULL) {
        deposit_window->close();
        deposit_window = NULL;
    }
    if (meseta_window != NULL) {
        meseta_window->close();
        meseta_window = NULL;
    }
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    close_extra_window();
    TCheckRoomSequence__slot_active_flags[get_split_screen_slot()] = 0;
    if (pad_30 != 0) {
        safe_free(reinterpret_cast<void *>(pad_30));
        pad_30 = 0;
    }
}
#pragma pop

}

TCheckRoomSequence::TCheckRoomSequence(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = TCheckRoomSequence__name;
    this->player = player;
    number_input = NULL;
    meseta_window = NULL;
    choice_menu = NULL;
    deposit_window = NULL;
    extra_window = NULL;
    counter_camera = NULL;
    menu_step = 0;
    set_state(0);
    TCheckRoomSequence__active_instance = (saddr)this;
    pad_30 = 0;
    TCheckRoomSequence__slot_active_flags[get_split_screen_slot()] = 1;
}

extern "C" {

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::reset_slot_state() {
    lbl_805D6160 = 0;
    TCheckRoomSequence__error_return_text_id = 0;
    TCheckRoomSequence__error_return_state = 0;
    TCheckRoomSequence__active_instance = 0;
    for (s32 i = 0; i < 4; i++) {
        TCheckRoomSequence__slot_active_flags[i] = 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::reset_slots() {
    lbl_805D6160 = 0;
    TCheckRoomSequence__error_return_text_id = 0;
    TCheckRoomSequence__error_return_state = 0;
    TCheckRoomSequence__active_instance = 0;
    for (s32 i = 0; i < 4; i++) {
        TCheckRoomSequence__slot_active_flags[i] = 0;
    }
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 bank_has_free_row(s32 slot) {
    return bank_item_count_by_slot[slot] <= 0xc7;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 get_bank_meseta_capacity(s32 i) {
    return 999999 - bank_meseta_by_slot[i];
}
#pragma pop

#pragma push
#pragma optimization_level 1
extern "C" {
void TCheckRoomSequence::compact_items(int slot) {
    BankItemRecord *a;
    BankItemRecord *b;
    BankItemRecord *base;
    base = bank_item_records_by_slot[slot];
    for (a = base; a < base + 199; a++) {
        if (a->is_empty() != 0) {
            for (b = a + 1; b < base + 200; b++) {
                if (b->is_empty() == 0) {
                    *a = *b;
                    TCheckRoomSequence::init_item_entry(b);
                    break;
                }
            }
        }
    }
}
#pragma pop

void sort_bank_items(s32 slot) {
    TCheckRoomSequence::compact_items(0);
    bank_item_records_by_slot[slot]->sort_records(bank_item_count_by_slot[slot], 2);
}

#pragma push
#pragma optimization_level 1
s32 get_bank_deposit_capacity_for_item(TItemData *item, s32 slot) {
    BankItemRecord *recs = bank_item_records_by_slot[slot];
    s32 i;
    if (item->data1.data_u8[0] != 3) {
        return 0;
    }
    if (TCheckRoomSequence::get_item_def((uaddr)item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (recs[i].is_empty() == 0 &&
            item->data1.data_u8[0] == recs[i].item.data1.data_u8[0] && item->data1.data_u8[1] == recs[i].item.data1.data_u8[1] &&
            item->data1.data_u8[2] == recs[i].item.data1.data_u8[2] && item->data1.data_u8[4] == recs[i].item.data1.data_u8[4]) {
            return recs[i].item.get_max_stack_size() - recs[i].amount;
        }
    }
    if (bank_has_free_row(slot) == 0) {
        return 0;
    }
    return item->get_max_stack_size();
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 TCheckRoomSequence__sub_80210B34(TItemData *item, s32 amount, s32 slot) {
    BankItemRecord *recs = bank_item_records_by_slot[slot];
    s32 i;
    if (item->data1.data_u8[0] != 3) {
        return 0;
    }
    if (TCheckRoomSequence::get_item_def((uaddr)item) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (recs[i].is_empty() == 0 &&
            item->data1.data_u8[0] == recs[i].item.data1.data_u8[0] && item->data1.data_u8[1] == recs[i].item.data1.data_u8[1] && item->data1.data_u8[2] == recs[i].item.data1.data_u8[2]) {
            recs[i].amount += amount;
            if (recs[i].amount > recs[i].item.get_max_stack_size()) {
                recs[i].amount = recs[i].item.get_max_stack_size();
            }
            return 1;
        }
    }
    for (i = 0; i < 200; i++) {
        if (recs[i].is_empty() != 0) {
            TCheckRoomSequence::copy_item_to_bank_entry(&recs[i], item);
            recs[i].amount = amount;
            bank_item_count_by_slot[slot]++;
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 bank_debit_meseta(s32 v, s32 i) {
    if (bank_meseta_by_slot[i] < v) {
        return 0;
    }
    bank_meseta_by_slot[i] -= v;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 bank_credit_meseta(s32 v, s32 i) {
    bank_meseta_by_slot[i] += v;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
extern "C" {
s32 TCheckRoomSequence__delete_bank_item(u8 *item, s32 slot) {
    BankItemRecord *rec = bank_item_records_by_slot[slot];
    s32 i;
    for (i = 0; i < 200; i++, rec++) {
        if (rec->is_empty() == 0 &&
            rec->item.data1.data_u8[0] == item[0] && rec->item.data1.data_u8[1] == item[1] && rec->item.data1.data_u8[2] == item[2] &&
            rec->item.data1.data_u8[3] == item[3] && rec->item.data1.data_u8[4] == item[4] && rec->item.data1.data_u8[5] == item[5]) {
            TCheckRoomSequence::init_item_entry(rec);
            copy_bank_to_card_window(slot);
            return 1;
        }
    }
    return 0;
}

void TCheckRoomSequence::remove_bank_item_amount(int idx, int amount, int slot) {
    BankItemRecord *recs = bank_item_records_by_slot[slot];
    s32 n;
    if (idx <= 199) {
        if (recs[idx].item.data1.data_u8[0] != 3) {
            TCheckRoomSequence::init_item_entry(&recs[idx]);
            bank_item_count_by_slot[slot]--;
            copy_bank_to_card_window(slot);
        } else if (TCheckRoomSequence::get_item_def((uaddr)&recs[idx].item) == 0) {
            TCheckRoomSequence::init_item_entry(&recs[idx]);
            bank_item_count_by_slot[slot]--;
            copy_bank_to_card_window(slot);
        } else if (recs[idx].is_empty() == 0) {
            n = recs[idx].amount;
            n -= amount;
            if (n >= 0) {
                if (n == 0) {
                    TCheckRoomSequence::init_item_entry(&recs[idx]);
                    bank_item_count_by_slot[slot]--;
                    copy_bank_to_card_window(slot);
                } else {
                    recs[idx].amount = n;
                    copy_bank_to_card_window(slot);
                }
            }
        }
    }
}
#pragma pop

typedef struct Rec_80210F78 Rec_80210F78;
#pragma optimization_level 1
s32 copy_bank_item_with_stack_limit(s32 idx, void *data, s32 *out, s32 slot) {
  saddr base = (saddr) bank_item_records_by_slot[slot];
  Rec_80210F78 *t;
  s32 new_var;
  if (idx > 199)
  {
    return 0;
  }
  if (((BankItemRecord *)(base + (idx * 0x18)))->is_empty() != 0)
  {
    return 0;
  }
  TCheckRoomSequence::copy_data((BankItemRecord *)(base + (idx * 0x18)), data);
  t = (Rec_80210F78 *) (base + (idx * 0x18));
  *out = t->f14;
  {
    saddr r = ((s32 (*)(void *, void *))get_max_stack_size__9TItemDataFv)(data, t);
    if (r < (*out))
    {
      *out = r;
      r = base + (idx * 0x18);
      {
        Rec_80210F78 *t2 = (Rec_80210F78 *) r;
        new_var = *out;
        t2->f14 = new_var;
      }
    }
  }
  return 1;
}

#pragma push
#pragma optimization_level 1
s32 TCheckRoomSequence::copy_item_record(int idx, void *data, int slot) {
    BankItemRecord *recs = bank_item_records_by_slot[slot];
    if (idx > 199) {
        return 0;
    }
    if (recs[idx].is_empty() != 0) {
        return 0;
    }
    TCheckRoomSequence::copy_data(&recs[idx], data);
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 1
s32 store_item_in_bank(TItemData *item, s32 amount, s32 slot) {
    BankItemRecord *recs = bank_item_records_by_slot[slot];
    s32 i;
    if (TCheckRoomSequence__sub_80210B34(item, amount, slot) != 0) {
        return 1;
    }
    if (bank_has_free_row(slot) == 0) {
        return 0;
    }
    for (i = 0; i < 200; i++) {
        if (recs[i].is_empty() != 0) {
            TCheckRoomSequence::copy_item_to_bank_entry(&recs[i], item);
            bank_item_count_by_slot[slot]++;
            copy_bank_to_card_window(slot);
            return 1;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 1
void copy_bank_to_card_window(s32 slot) {
    Card_8021118C *w;
    if (TAdSinglePlyChrSelectGC::is_ready() != 0) {
        w = (Card_8021118C *)get_character_save_record(slot);
        if (w != 0) {
            w->meseta = bank_meseta_by_slot[slot];
            w->count = bank_item_count_by_slot[slot];
            move_data((void *)((w->items)), (const void *)(bank_item_records_by_slot[slot]), 0x12C0);
        }
    }
}
}
#pragma pop

#pragma push
#pragma optimization_level 1
void copy_bank_from_card_window(s32 slot) {
    Card_8021118C *w = (Card_8021118C *)get_character_save_record(slot);
    if (w != 0) {
        bank_meseta_by_slot[slot] = w->meseta;
        bank_item_count_by_slot[slot] = w->count;
        move_data((void *)((bank_item_records_by_slot[slot])), (const void *)(w->items), 0x12C0);
    }
}
#pragma pop
extern "C" {


#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::free_bank_item_records() {
    BankItemRecord *recs;
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (bank_item_records_by_slot[i] != NULL) {
            recs = bank_item_records_by_slot[i];
            if (recs != NULL) {
                mem_free((u8 *)recs - 0x10);
            }
            bank_item_records_by_slot[i] = NULL;
        }
        bank_meseta_by_slot[i] = 0;
        bank_item_count_by_slot[i] = 0;
    }
}
#pragma pop

void TCheckRoomSequence::alloc_item_buffers() {
    s32 i;
    s32 j;

    for (j = 0; j < 4; j++) {
        bank_meseta_by_slot[j] = 0;
        bank_item_count_by_slot[j] = 0;
        bank_item_records_by_slot[j] = NULL;
    }
    if (is_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            bank_item_records_by_slot[i] = (BankItemRecord *)__construct_new_array(mem_alloc(200 * sizeof(BankItemRecord) + 0x10),
                (void *)__ct__14BankItemRecordFv, NULL, sizeof(BankItemRecord), 200);
        }
    } else {
        bank_item_records_by_slot[0] = (BankItemRecord *)__construct_new_array(mem_alloc(200 * sizeof(BankItemRecord) + 0x10),
            (void *)__ct__14BankItemRecordFv, NULL, sizeof(BankItemRecord), 200);
    }
}

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::init_item_entry(BankItemRecord *record) {
    record->item.init();
    record->amount = 0;
    record->used = 0;
}
#pragma pop

void TCheckRoomSequence::copy_data(BankItemRecord *p, void *a1) { *(unsigned char*)(a1) = *(unsigned char*)(p); *(unsigned char*)((char*)a1 + 0x1) = *(unsigned char*)((char*)p + 0x1); *(unsigned char*)((char*)a1 + 0x2) = *(unsigned char*)((char*)p + 0x2); *(unsigned char*)((char*)a1 + 0x3) = *(unsigned char*)((char*)p + 0x3); *(unsigned char*)((char*)a1 + 0x4) = *(unsigned char*)((char*)p + 0x4); *(unsigned char*)((char*)a1 + 0x5) = *(unsigned char*)((char*)p + 0x5); ((TObjPlayer *)((char*)a1 + 0x6))->copy_entry_bytes((char*)p + 0x6); ((TObjPlayer *)((char*)a1 + 0x8))->copy_entry_bytes((char*)p + 0x8); ((TObjPlayer *)((char*)a1 + 0xa))->copy_entry_bytes((char*)p + 0xa); *(void**)((char*)a1 + 0xc) = *(void**)((char*)p + 0xc); *(void**)((char*)a1 + 0x10) = *(void**)((char*)p + 0x10); }

#pragma push
#pragma optimization_level 1
void TCheckRoomSequence::copy_item_to_bank_entry(BankItemRecord *entry, TItemData *item) {
    entry->item.data1.data_u8[0] = item->data1.data_u8[0];
    entry->item.data1.data_u8[1] = item->data1.data_u8[1];
    entry->item.data1.data_u8[2] = item->data1.data_u8[2];
    entry->item.data1.data_u8[3] = item->data1.data_u8[3];
    entry->item.data1.data_u8[4] = item->data1.data_u8[4];
    entry->item.data1.data_u8[5] = item->data1.data_u8[5];
    ((TObjPlayer *)&entry->item.data1.data_u16[3])->copy_entry_bytes(&item->data1.data_u16[3]);
    ((TObjPlayer *)&entry->item.data1.data_u16[4])->copy_entry_bytes(&item->data1.data_u16[4]);
    ((TObjPlayer *)&entry->item.data1.data_u16[5])->copy_entry_bytes(&item->data1.data_u16[5]);
    entry->item.id = item->id;
    entry->item.data2.data_u32 = item->data2.data_u32;
    entry->amount = 1;
    entry->used = 1;
}
#pragma pop

s32 BankItemRecord::is_empty() {
    return (u8)(used == 0);
}

#pragma push
#pragma optimization_level 1
void BankItemRecord::init() {
    item.init();
    amount = 0;
    used = 0;
}
#pragma pop

BankItemRecord::BankItemRecord() { init(); }

void TShopWindowBase::display_shop_message(s32 id, s32 flags) {  }
}

#pragma optimization_level 4

int TWindowInputNumber::is_cancelled() { return (this->inputFlags >> 2) & 0x1; }
s32 TWindowInputNumber::get_value() { return this->value; }
int TWindowInputNumber::is_confirmed() { return (this->inputFlags >> 1) & 0x1; }
void TWindowInputNumber::set_scale(f32 x, f32 y) { scaleX = x; scaleY = y; }

int TCheckRoomSequence::get_room_data(int slot) { return bank_meseta_by_slot[slot]; }
int TCheckRoomSequence::get_room_table_entry(int slot) { return bank_item_count_by_slot[slot]; }
