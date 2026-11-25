#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/quest/QuestOpcodeHandlers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/quest/TQuestListOffline.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/TQuestManager.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/city/THunterGuildSeqOffline_80213788.h"
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_8022350C.h"
#include "pso/ui/window/WindowLayout.h"

// The quest-list callbacks before the guild sequence proper are built in source order;
// the rest of the file uses deferred code generation (reverse order in .text).
#pragma defer_codegen off

void THunterGuildSeqOffline::set_state_close(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(0xC, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 0;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::set_state_4(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 4;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::handle_click() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_guild_message(0x19, 1);
        set_state(4);
    }
}

void THunterGuildSeqOffline::set_state_3() {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 3;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::init_quest_list() {
    THunterGuildSeqOffline::active_instance->set_state(9);
}

void THunterGuildSeqOffline::notify_close() {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(0x19, 1);
        THunterGuildSeqOffline::active_instance->set_state(4);
    }
}

void THunterGuildSeqOffline::create_quest_list_vm(TShopWindowBase *) {
    TQuestListVM *vm = new TQuestListVM(tl_05, THunterGuildSeqOffline::active_instance,
                                        THunterGuildSeqOffline::active_instance->player);
    if (vm != NULL) {
        vm->on_close = notify_close;
        vm->on_error = init_quest_list;
        vm->on_finish = set_state_3;
    }
}

void THunterGuildSeqOffline::set_state_close2(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(0xC, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 0;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::set_enemy_mode_5(TObject *) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 5; set_keyboard_input_flag(); }

void THunterGuildSeqOffline::set_enemy_mode_1(TObject *) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 1; set_keyboard_input_flag(); }

extern "C" void fn_802233F8(void *);

void THunterGuildSeqOffline::set_enemy_mode_0(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; set_keyboard_input_flag(); }

void THunterGuildSeqOffline::request_close(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 2;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::handle_cancel_choice() {
    s32 selected_menu_value;
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        if (menu->is_decided() != 0) {
            selected_menu_value = choice_menu->get_selected_value();
            if (selected_menu_value == 0) {
                choice_menu->close();
                this->choice_menu = NULL;
                this->display_guild_message(9, 1);
                exit_action = 1;
                if (quest_result_callbacks[2] != -1) {
                    quest_thread = TQuestThread::create_in_root(quest_result_callbacks[2]);
                }
                this->set_state(5);
                return;
            }
            if (selected_menu_value == 1) {
                choice_menu->close();
                this->choice_menu = NULL;
                this->display_guild_message(0xA, 1);
                exit_action = 0;
                this->set_state(5);
                return;
            }
        }
        if (choice_menu->is_cancelled() != 0) {
            choice_menu->close();
            this->choice_menu = NULL;
            this->display_guild_message(0xA, 1);
            exit_action = 0;
            this->set_state(5);
        }
    }
}

void THunterGuildSeqOffline::close_window() {
    if (quest_thread != 0) {
        if (((TObject *)quest_thread)->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = 0;
    }
    if (is_message_ready() == 0) {
        return;
    }
    if (is_decide_pressed() == 0 && is_cancel_pressed() == 0) {
        return;
    }
    switch (exit_action) {
    case 0:
        break;
    case 1:
        new TScreenFadeOut(tl_00, THunterGuildSeqOffline::set_enemy_mode_0);
        set_shop_slot_active(player->get_entity_id());
        break;
    case 2:
        new TScreenFadeOut(tl_00, THunterGuildSeqOffline::set_enemy_mode_1);
        set_shop_slot_active(player->get_entity_id());
        break;
    case 3:
        new TScreenFadeOut(tl_00, TQuestListVM::set_enemy_mode_3);
        set_shop_slot_active(player->get_entity_id());
        break;
    case 4:
        new TScreenFadeOut(tl_00, THunterGuildSeqOffline::set_enemy_mode_5);
        set_shop_slot_active(player->get_entity_id());
        break;
    }
    TShopSequence::close_window();
    fn_802233F8(this);
    THunterGuildWarning::queue_destruction();
    queue_destruction();
}

void THunterGuildSeqOffline::open_quest_list() {
    TQuestListChallenge *challenge;
    TQuestListOffline *offline;
    if (is_message_ready() == 0) return;
    switch (get_game_play_mode()) {
    case 2:
        challenge = new TQuestListChallenge(tl_05, this, player);
        if (challenge != NULL) {
            challenge->on_accept = THunterGuildSeqOffline::request_close;
            challenge->on_cancel = THunterGuildSeqOffline::set_state_close2;
            set_state(10);
        }
        break;
    case 1:
        challenge = new TQuestListChallenge(tl_05, this, player);
        if (challenge != NULL) {
            challenge->on_accept = THunterGuildSeqOffline::set_state_4;
            challenge->on_cancel = THunterGuildSeqOffline::set_state_close;
            set_state(10);
        }
        break;
    case 0:
    default:
        offline = new TQuestListOffline(tl_05, this, player);
        if (offline != NULL) {
            offline->on_accept = THunterGuildSeqOffline::request_close;
            offline->on_cancel = THunterGuildSeqOffline::set_state_close2;
            offline->on_download = THunterGuildSeqOffline::create_quest_list_vm;
            set_state(10);
        }
        break;
    }
}

void THunterGuildSeqOffline::handle_window_input() {
    TQuestThread *object = quest_thread;

    if (object != NULL) {
        if (object->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        quest_thread = NULL;
    }
    if ((this->is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        this->display_guild_message(0xC, 1);
        exit_action = 1;
        set_state(5);
    }
}


#pragma defer_codegen on

struct GuildMenuCallbackBase { char pad[0x18]; };
struct GuildMenuCallbackView : GuildMenuCallbackBase {
    virtual void m0(); virtual void m1();
};

#pragma readonly_strings on
s32 quest_result_callbacks[4];
s32 THunterGuildSeqOffline::instance_table[4];
THunterGuildSeqOffline *THunterGuildSeqOffline::active_instance;

extern "C" {
const char *hunter_guild_seq_offline_class_name = "THunterGuildSeqOffline";

int fn_80223480(void*);

// Written last-to-first: the unit is built with deferred code generation (see configure.py).

void THunterGuildSeqOnline_Client::open_judgment_item_window() {
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        choice_menu = create_yes_no_window(get_window_layout_position(0x2B), (u16)((TObjBase *)((saddr)player))->get_entity_id(), NULL, NULL);
        ((TWindowMenu *)choice_menu)->set_selected_index(1);
        ((TWindowAddition *)choice_menu)->set_position_xy(get_scale(), get_scale());
        display_guild_message(8, 1);
        set_state(7);
    }
}

void THunterGuildSeqOnline_Client::handle_confirm_window() {
    if ((choice_menu != NULL) && (choice_menu->is_decided() != 0)) {
        switch (choice_menu->get_selected_value()) {
        case 0:
            choice_menu->close();
            choice_menu = NULL;
            display_guild_message(9, 1);
            exit_action = 1;
            if (quest_result_callbacks[2] != -1) {
                quest_thread = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(quest_result_callbacks[2]));
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

void THunterGuildSeqOnline_Client::close_window() {
    if (quest_thread != NULL) {
        if (quest_thread->all_parents_unqueued_for_destruction() != 0) {
            return;
        }
        quest_thread = NULL;
    }
    if ((is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        switch (exit_action) {
        case 1: {
            new TScreenFadeOut(tl_00, reset_random_enemies_mode);
            set_shop_slot_active(((TObjBase *)((saddr)player))->get_entity_id());
            break;
        }
        case 0:
            break;
        case 2:
            break;
        }
        TShopSequence::close_window();
        queue_destruction();
    }
}

s32 get_online_client_state(void) {
    if (hunter_guild_seq_online_client_instance != NULL) {
        return hunter_guild_seq_online_client_instance->state;
    }
    return -1;
}

void THunterGuildSeqOffline::reset_quest_result_callbacks() {
    s32 i;
    for (i = 0; i < 4; i++) quest_result_callbacks[i] = -1;
}

void THunterGuildSeqOffline__sub_80213410(void) { THunterGuildSeqOffline::reset_quest_result_callbacks(); }

void THunterGuildSeqOffline::notify_quest_thread() {
    s32 v = quest_result_callbacks[3];
    if (v != -1) {
        void *obj = TQuestThread::create(v);
        if (obj != NULL) {
            ((GuildMenuCallbackView *)obj)->m1();
        }
    }
}

void clear_offline_instance_table(void) {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline::instance_table[i] = 0;
}

void THunterGuildSeqOffline::clear_instance_table() {
    s32 i;
    for (i = 0; i < 4; i++) THunterGuildSeqOffline::instance_table[i] = 0;
}

THunterGuildSeqOffline::THunterGuildSeqOffline(TObject *parent, TObjPlayer *player) : TShopSequence(parent) {
    m_name = hunter_guild_seq_offline_class_name;
    state = 0;
    choice_menu = NULL;
    this->player = player;
    counter_camera = NULL;
    quest_thread = 0;
    exit_action = 0;
    THunterGuildSeqOffline::active_instance = this;
    THunterGuildSeqOffline::instance_table[get_split_screen_slot()] = 1;
}

THunterGuildSeqOffline::~THunterGuildSeqOffline() {
    if (counter_camera != NULL) {
        counter_camera->queue_destruction();
        counter_camera = NULL;
    }
    close_message_window();
    if (choice_menu != NULL) {
        ((TWindowBase *)choice_menu)->close();
        choice_menu = NULL;
    }
    if (quest_thread != 0) {
        ((TObject *)quest_thread)->queue_destruction();
        quest_thread = 0;
    }
    THunterGuildSeqOffline::instance_table[get_split_screen_slot()] = 0;
    THunterGuildSeqOffline::active_instance = NULL;
}

void THunterGuildSeqOffline::update_state() {
    switch (state) {
    case 0: restore_player_state(); break;
    case 1: open_greeting(); break;
    case 2: resolve_active_quest_result(); break;
    case 3: open_judgment_window(); break;
    case 4: open_quest_list(); break;
    case 5: close_window(); break;
    case 6: handle_cancel_choice(); break;
    case 7: handle_select(); break;
    case 8: handle_window_input(); break;
    case 9: handle_click(); break;
    case 10: break;
    }
}

void THunterGuildSeqOffline::restore_player_state() { TShopSequence::restore_player_state(); fn_80223480(this); THunterGuildWarning::create_instance((saddr)((void*)2)); set_state((saddr)((void*)((void*)1))); }

void THunterGuildSeqOffline::open_greeting() {
    NJS_POINT2 window_size;
    window_size.x = 332.0f;
    window_size.y = 80.0f;
    this->create_message_window(get_window_layout_position(0x2C), (saddr)&window_size);
    this->display_guild_message(1, 1);
    counter_camera = set_service_counter_camera(this, 1);
    this->set_state((saddr)((void*)(2)));
}

void THunterGuildSeqOffline::resolve_active_quest_result() {
    if ((this->is_message_ready() != 0) && ((this->is_decide_pressed() != 0) || (this->is_cancel_pressed() != 0))) {
        if (is_quest_active() == 1) {
            if (TQuestThread::get_register(quest_mission_manager, 0xFF) == 1) {
                this->display_guild_message(0xB, 1);
                if (quest_result_callbacks[1] != -1) {
                    this->quest_thread = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(quest_result_callbacks[1]));
                }
                this->set_state((saddr)((void*)(7)));
                return;
            }
            if (TQuestThread::get_register(quest_mission_manager, 0xFD) == 1) {
                this->display_guild_message(0x12, 1);
                if (quest_result_callbacks[0] != -1) {
                    this->quest_thread = reinterpret_cast<TQuestThread *>(TQuestThread::create_in_root(quest_result_callbacks[0]));
                }
                this->set_state((saddr)((void*)(8)));
                return;
            }
            this->display_guild_message(2, 1);
            this->set_state((saddr)((void*)(3)));
            return;
        }
        this->display_guild_message(4, 1);
        this->set_state((saddr)((void*)(4)));
    }
}

void THunterGuildSeqOffline::open_judgment_window() {

    if ((this->is_message_ready() != 0)
        && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        this->choice_menu = (TWindowMenu *)create_yes_no_window(get_window_layout_position(0x2B), (u16)((TObjBase *)((saddr)this->player))->get_entity_id(), NULL, NULL);
        ((TWindowMenu *)this->choice_menu)->set_selected_index(1);
        ((TWindowAddition *)(this->choice_menu))->set_position_xy(get_scale(), get_scale());
        this->display_guild_message(8, 1);
        set_state((saddr)((void*)(6)));
    }
}

void THunterGuildSeqOffline::handle_select() {
    TQuestThread *p = this->quest_thread;
    if (p != NULL) {
        if (((TObject *)p)->all_parents_unqueued_for_destruction() == 1) {
            return;
        }
        this->quest_thread = 0U;
    }
    if ((this->is_message_ready() != 0) && ((is_decide_pressed() != 0) || (is_cancel_pressed() != 0))) {
        this->display_guild_message(0xC, 1);
        this->exit_action = 1;
        set_state((saddr)((void*)(5)));
    }
}

}
