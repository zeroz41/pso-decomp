#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TScreenFadeOut.h"
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/quest/TQuestListChallenge.h"
#include "pso/quest/TQuestListOffline.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/city/TShopSequence.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
void fn_802233F8(void *);

    extern int evt2_random_enemies_mode;
void THunterGuildSeqOffline::set_enemy_mode_0(TObject *) { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); }


void THunterGuildSeqOffline::request_close(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->unk_38 = 2;
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
                *(s32 *)&this->unk_38 = 1;
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
                *(s32 *)&this->unk_38 = 0;
                this->set_state(5);
                return;
            }
        }
        if (choice_menu->is_cancelled() != 0) {
            choice_menu->close();
            this->choice_menu = NULL;
            this->display_guild_message(0xA, 1);
            *(s32 *)&this->unk_38 = 0;
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
    switch (unk_38) {
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
        *(s32 *)&this->unk_38 = 1;
        set_state(5);
    }
}

}
