#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/TScreenFadeOut.h"
#include "pso/unk/TQuestManager.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "types.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/city/THunterGuildSeqOnline.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/OnlineQuestMenuRecords.h"
#include "pso/quest/OnlineQuestDownloadState.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/system/TMemberCheck.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowMenu.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildSeqOnlineTask.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/quest/QuestActiveFlag.h"

// Online quest download state, read by TQuestListOnline (THunterGuildSeqOnlineTask.cpp).
OnlineQuestDownloadState quest_list_online_dat_download_state;
OnlineQuestDownloadState quest_list_online_bin_download_state;
// Per-player slot flags, set by each class's ctor and cleared by its dtor
// (same pattern as THunterGuildSeqOffline::instance_table).
s32 hunter_guild_online_server_instance_table[4];
s32 hunter_guild_online_client_instance_table[4];
OnlineQuestMenu *quest_list_online_quest_list_buffer;
OnlineQuestInfo *quest_list_online_selected_quest_info;
int online_quest_bin_download_complete;
int online_quest_dat_download_complete;
TWindowMessage *online_quest_download_window;
TWindowMessage *online_quest_info_window;
TWindowMessage *online_quest_download_barrier_window;
s32 quest_download_active;
s32 quest_download_received_bytes;
s32 quest_download_graph_current_bytes;

// Set by each class's ctor, cleared by its dtor.
THunterGuildSeqOnline_Server *hunter_guild_seq_online_server_instance;
THunterGuildSeqOnline_Client *hunter_guild_seq_online_client_instance;

// Written last-to-first: the unit is built with deferred code generation (see configure.py).


THunterGuildSeqOnline_Server::THunterGuildSeqOnline_Server(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = hunter_guild_seq_online_server_name;
    state = 0;
    this->player = player;
    counter_camera = NULL;
    exit_action = 0;
    choice_menu = NULL;
    quest_thread = NULL;
    message_pending = 1;
    hunter_guild_online_server_instance_table[get_split_screen_slot()] = 1;
    hunter_guild_seq_online_server_instance = this;
}

THunterGuildSeqOnline_Server::~THunterGuildSeqOnline_Server() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    hunter_guild_online_server_instance_table[get_split_screen_slot()] = 0;
    hunter_guild_seq_online_server_instance = NULL;
}

void THunterGuildSeqOffline::zero_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        hunter_guild_online_server_instance_table[i] = 0;
    }
}

void THunterGuildSeqOffline::clear_slot_flags() {
    s32 i;
    for (i = 0; i < 4; i++) {
        hunter_guild_online_server_instance_table[i] = 0;
    }
}

void THunterGuildSeqOnline_Server::update_state() {
    switch (state) {
    case 0: restore_player_state(); break;
    case 1: init_window(); break;
    case 3: handle_party_check(); break;
    case 8: open_quest_list(); break;
    case 4: update_confirm_input(); break;
    case 5: update(); break;
    case 6: create_judgment_item_window(); break;
    case 7: handle_judgment_choice(); break;
    case 9: set_state(0xC); break;
    case 10: set_state(0xC); break;
    case 12: close_window(); break;
    case 13: confirm_and_close_if_valid(); break;
    case 14: return;
    }
}

void THunterGuildSeqOnline_Server::restore_player_state() {
    TShopSequence::restore_player_state();
    counter_camera = set_service_counter_camera(this, 1);
    set_state(1);
}

void THunterGuildSeqOnline_Server::init_window() {
    NJS_POINT2 window_size;
    window_size.x = 332.0f;
    window_size.y = 80.0f;
    create_message_window(get_window_layout_position(0x2C), &window_size);
    if (is_quest_active() == 0) {
        new TMemberCheck(this);
    }
    display_guild_message(1, 1);
    check_step = 0;
    set_state(3);
}

void THunterGuildSeqOnline_Server::handle_party_check() {
    if (is_message_ready() != 0) {
        if (is_decide_pressed() != 0) {
            message_pending = 0;
        }
        if (message_pending == 0) {
            switch (check_step) {
            case 3:
                break;
            case 0:
                if (is_quest_active() != 0) {
                    check_step = 2;
                    return;
                }
                switch (THunterGuildSeqOffline::check_party_gathered()) {
                case 1:
                    check_step = 2;
                    return;
                case 0:
                    display_guild_message(0x11, 1);
                    check_step = 1;
                    return;
                case 2:
                    display_guild_message(0xD, 1);
                    check_step = 1;
                    return;
                }
                break;
            case 1:
                if (THunterGuildSeqOffline::check_party_gathered() == 1) {
                    check_step = 2;
                }
                if (is_cancel_pressed() != 0) {
                    display_guild_message(0x10, 1);
                    set_state(0xD);
                    return;
                }
                break;
            case 2:
                if (is_quest_active() != 0) {
                    if (TQuestThread::get_register(quest_mission_manager, 0xFF) != 0) {
                        display_guild_message(0xB, 1);
                        if (quest_result_callbacks[1] != -1) {
                            quest_thread = TQuestThread::create_in_root(quest_result_callbacks[1]);
                        }
                        set_state(4);
                        return;
                    }
                    if (TQuestThread::get_register(quest_mission_manager, 0xFD) != 0) {
                        display_guild_message(0x12, 1);
                        if (quest_result_callbacks[0] != -1) {
                            quest_thread = TQuestThread::create_in_root(quest_result_callbacks[0]);
                        }
                        set_state(5);
                        return;
                    }
                    display_guild_message(2, 1);
                    set_state(6);
                    return;
                }
                display_guild_message(4, 1);
                check_step = 0;
                set_state(8);
                break;
            }
        }
    }
}

void THunterGuildSeqOnline_Server::update_confirm_input() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_guild_message(0xC, 1);
        exit_action = 1;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Server::update() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_guild_message(0xC, 1);
        exit_action = 1;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Server::create_judgment_item_window() {
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        choice_menu = create_yes_no_window(get_window_layout_position(0x2B), ((TObjBase *)(player))->get_entity_id(), NULL, NULL);
        choice_menu->set_selected_index(1);
        choice_menu->set_position_xy(get_scale(), get_scale());
        display_guild_message(8, 1);
        set_state(7);
    }
}

void THunterGuildSeqOnline_Server::handle_judgment_choice() {
    if ((choice_menu != NULL) && (choice_menu->is_decided() != 0)) {
        switch (choice_menu->get_selected_value()) {
        case 0:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(9, 1);
            exit_action = 1;
            if ((s32) quest_result_callbacks[2] != -1) {
                quest_thread = TQuestThread::create_in_root(quest_result_callbacks[2]);
            }
            set_state(0xC);
            break;
        case 1:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(0xA, 1);
            exit_action = 0;
            set_state(0xC);
            break;
        }
    }
    if ((choice_menu != NULL) && (choice_menu->is_cancelled() != 0)) {
        choice_menu->close();
        choice_menu = NULL;
        display_guild_message(0xA, 1);
        exit_action = 0;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Server::close_window() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) return;
        quest_thread = NULL;
    }
    if (is_message_ready() == 0) return;
    switch (exit_action) {
    case 0:
        if (is_decide_pressed() == 0 && is_cancel_pressed() == 0) return;
        if (is_quest_active() == 0) {
            TLobby::protocol_instance->send_quest_menu_closed();
        }
        TShopSequence::close_window();
        queue_destruction();
        break;
    case 1:
        new TScreenFadeOut(tl_00, reset_random_enemies_mode);
        set_shop_slot_active(((TObjBase *)(player))->get_entity_id());
        TShopSequence::close_window();
        queue_destruction();
        break;
    case 2:
        new TScreenFadeOut(tl_00, set_random_enemies_mode);
        set_shop_slot_active(((TObjBase *)(player))->get_entity_id());
        TShopSequence::close_window();
        queue_destruction();
        break;
    }
}

void THunterGuildSeqOnline_Server::open_quest_list() {
    TQuestListOnline *l;
    l = new TQuestListOnline(tl_05, this, player);
    if (l != 0) {
        display_guild_message(4, 1);
        l->callback28 = THunterGuildSeqOffline__sub_80213F78;
        l->callback2c = THunterGuildSeqOffline__sub_80213EBC;
        l->callback30 = THunterGuildSeqOffline__sub_80213E64;
        l->callback34 = THunterGuildSeqOffline::reset_quest_list_vm;
        set_state(0xE);
    }
}

void THunterGuildSeqOnline_Server::confirm_and_close_if_valid() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_guild_message(0xc, 1);
        set_state(0xc);
    }
}

void THunterGuildSeqOffline__sub_80213F78(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_state(9);
        hunter_guild_seq_online_server_instance->exit_action = 0;
    }
}

void THunterGuildSeqOffline::reset_quest_list_vm() {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_message((const char *)get_message_text(0x43), 1);
        hunter_guild_seq_online_server_instance->set_state(9);
        hunter_guild_seq_online_server_instance->exit_action = 0;
    }
}

void THunterGuildSeqOffline__sub_80213EBC(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(0xC, 1);
        hunter_guild_seq_online_server_instance->set_state(0xA);
        hunter_guild_seq_online_server_instance->exit_action = 2;
    }
}

void THunterGuildSeqOffline__sub_80213E64(void) {
    if (hunter_guild_seq_online_server_instance != NULL) {
        hunter_guild_seq_online_server_instance->display_guild_message(6, 1);
        hunter_guild_seq_online_server_instance->set_state(0xC);
        hunter_guild_seq_online_server_instance->exit_action = 2;
    }
}


void set_random_enemies_mode(TObject *) { set_enemy_mode_flag(); evt2_random_enemies_mode = 2; set_keyboard_input_flag(); }

void reset_random_enemies_mode(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; set_keyboard_input_flag(); }


THunterGuildSeqOnline_Client::THunterGuildSeqOnline_Client(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = hunter_guild_seq_online_client_name;
    state = 0;
    this->player = player;
    counter_camera = NULL;
    check_step = 0;
    exit_action = 0;
    choice_menu = NULL;
    quest_thread = NULL;
    hunter_guild_online_client_instance_table[get_split_screen_slot()] = 1;
    hunter_guild_seq_online_client_instance = this;
}

THunterGuildSeqOnline_Client::~THunterGuildSeqOnline_Client() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        choice_menu->close();
        choice_menu = NULL;
    }
    hunter_guild_online_client_instance_table[get_split_screen_slot()] = 0;
    hunter_guild_seq_online_client_instance = NULL;
}

void clear_online_client_instance_table(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        hunter_guild_online_client_instance_table[i] = 0;
    }
}

void THunterGuildSeqOffline::clear_slots() {
    s32 i;
    for (i = 0; i < 4; i++) hunter_guild_online_client_instance_table[i] = 0;
}

void THunterGuildSeqOnline_Client::update_state() {
    switch (state) {
    case 0: restore_player_state(); break;
    case 1: open_greeting(); break;
    case 2: resolve_active_quest_result(); break;
    case 11: handle_close(); break;
    case 4: update_close_shop(); break;
    case 5: update_shop_close(); break;
    case 6: open_judgment_item_window(); break;
    case 7: handle_confirm_window(); break;
    case 12: close_window(); break;
    case 14: return;
    }
}

void THunterGuildSeqOnline_Client::restore_player_state() {
    TShopSequence::restore_player_state();
    counter_camera = set_service_counter_camera(this, 1);
    set_state(1);
}

void THunterGuildSeqOnline_Client::open_greeting() {
    NJS_POINT2 window_size;
    window_size.x = 332.0f;
    window_size.y = 80.0f;
    create_message_window(get_window_layout_position(0x2C), &window_size);
    display_guild_message(1, 1);
    check_step = 0;
    set_state(2);
}

void THunterGuildSeqOnline_Client::resolve_active_quest_result() {
    if (is_message_ready() == 0) {
        return;
    }
    switch (check_step) {
    case 1:
        return;
    case 0:
        if (is_quest_active() != 0) {
            if (TQuestThread::get_register(quest_mission_manager, 0xFF) != 0) {
                display_guild_message(0xB, 1);
                if (quest_result_callbacks[1] != -1) {
                    quest_thread = TQuestThread::create_in_root(quest_result_callbacks[1]);
                }
                set_state(4);
            } else if (TQuestThread::get_register(quest_mission_manager, 0xFD) != 0) {
                display_guild_message(0x12, 1);
                if (quest_result_callbacks[0] != -1) {
                    quest_thread = TQuestThread::create_in_root(quest_result_callbacks[0]);
                }
                set_state(5);
            } else {
                display_guild_message(2, 1);
                set_state(6);
            }
        } else if (is_decide_pressed() != 0 || is_cancel_pressed() != 0) {
            display_guild_message(0x15, 1);
            set_state(0xB);
        }
        break;
    }
}

void THunterGuildSeqOnline_Client::handle_close() {
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_guild_message(0xC, 1);
        exit_action = 0;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Client::update_close_shop() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_guild_message(0xC, 1);
        exit_action = 1;
        set_state(0xC);
    }
}

void THunterGuildSeqOnline_Client::update_shop_close() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        display_guild_message(0xC, 1);
        exit_action = 1;
        set_state(0xC);
    }
}

