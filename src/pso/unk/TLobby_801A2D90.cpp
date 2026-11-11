#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_801A2D90.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/warp/TObjLaboMapWarp_80185248.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/technique/TTecLuker.h"
#include "pso/object/door/TObjDoor.h"

struct Base_801A2E00 { u8 pad0[0x18]; };

struct Ctrl_801A2E00 : Base_801A2E00 { virtual void v0(int); };

extern "C" {
s32 is_multiplayer_character_slot_selected(s32);
s32 create_player_object(s32, s32, u32);
u32 get_char_index__23TAdSinglePlyChrSelectGCFUi(s32);
s32 is_split_screen();
extern s32 local_client_id;
extern s32 lbl_805D53A8;
s32 reset_quest_result_callbacks__22THunterGuildSeqOfflineFPv();
void queue_destruction__7TObjectFv(void *arg0);
extern u32 quest_mission_manager;
void *get_player_by_client_id(s32 i);

void TLobby::reset_keyboard_input() { TKeyBoardControl::reset(); TKeyBoardControl__sub_8000F92C(); clear_keyboard_key_state(); TKeyBoardControl__sub_8000F95C(); TLobby::clear_counter(); }
void TLobby::shutdown_keyboard_control() { TKeyBoardControl::reset(); TLobby::reset_quest_state(); TKeyBoardControl__sub_8000F92C(); clear_keyboard_key_state(); TKeyBoardControl__sub_8000F95C(); TLobby::clear_counter(); }
void TLobby__sub_801A2DF4(void) {  }
void TLobby__sub_801A2DF8(void) {  }
void TLobby__sub_801A2DFC(void) {  }

void TLobby__sub_801A2E00(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        switch (get_game_play_mode()) {
        case 1:
        case 2: {
            s32 i;
            for (i = 0; i < 4; i++) {
                Ctrl_801A2E00 *c = (Ctrl_801A2E00 *)get_player_by_client_id(i);
                if (c != NULL && c != NULL) {
                    c->v0(1);
                }
            }
            TLobby::apply_char_to_players();
            break;
        }
        }
    }
}

void TLobby::apply_char_to_players() {
    s32 var_r31;
    u32 temp_r3;
    u32 temp_r3_2;
    if (is_split_screen() != 0) {
        var_r31 = 0;
        do {
            if (is_multiplayer_character_slot_selected(var_r31) != 0) {
                temp_r3 = get_char_index__23TAdSinglePlyChrSelectGCFUi(var_r31);
                if (temp_r3 != 0U) {
                    create_player_object(var_r31, lbl_805D53A8 + var_r31, temp_r3);
                }
            }
            var_r31 += 1;
        } while (var_r31 < 4);
        return;
    }
    temp_r3_2 = get_char_index__23TAdSinglePlyChrSelectGCFUi(local_client_id);
    if (temp_r3_2 != 0U) {
        create_player_object(0, lbl_805D53A8, temp_r3_2);
    }
}
void TLobby::reset_quest_state() {
    TRaderMapCore::free_map_data();
    clear_switch_table();
    TTecLuker::apply_all_players();
    TLobby::reset_item_id_counters();
    TLobby::reset_floor_items();
    TNpcPlayer::enable_all_battle_ctrl();
    if ((u32) quest_mission_manager != 0U) {
        queue_destruction__7TObjectFv((void *)quest_mission_manager);
    }
    clear_enabled_main_warps();
    reset_quest_result_callbacks__22THunterGuildSeqOfflineFPv();
    TLobby::clear_counter();
    TLobby::reset_door_state();
    TObjDoor::reset_instance();
    TLobby::set_cleanup_flag();
    TLobby::reset_quest_counter();
    TLobby::clear_quest_state();
}

}
