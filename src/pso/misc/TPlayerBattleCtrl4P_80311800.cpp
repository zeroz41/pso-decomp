#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/quest/TQuestThread.h"

#include "types.h"
#include "pso/misc/TCheckRoomSequence.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"

struct RecoveredGlobal_80311A64_TPlayerBattleCtrl4P__data_80542E90 {
    u16 value;
    u8 remaining[0x1E];
};

struct Ids_80311C2C { s32 a; s32 b; s32 c; s32 d; };

struct O_80311C2C { u8 pad[0x20]; void *w0; void *w1; u8 pad2[0x294 - 0x28]; Ids_80311C2C *ids; };

extern "C" {
u32 get_player_by_client_id(s32);
s32 check_player_flag1__6TLobbyFv();
void TWindow__close(u8 *arg0);
void send_code_45_to_window__19TPlayerBattleCtrl4PFPvii(void *arg0, s32 arg1, s32 arg2);
s32 record_split_screen_battle_results(void *);
s32 set_state__19TPlayerBattleCtrl4PFv(void *, int);
s32 calculate_split_screen_battle_rankings(void *);
extern s32 lbl_80475BC4[];
extern s32 lbl_80475BCC[];
extern RecoveredGlobal_80311A64_TPlayerBattleCtrl4P__data_80542E90 split_screen_battle_rankings;
extern s32 local_client_id;
s32 has_player_active_menu__11TWindowCtrlFv(s32);
s32 get_selected_menu_value(void *);
s32 align_menu_entry_positions(void *);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
void *set_window_mode_4__6TLobbyFPvll(void *, void *, int);
void *get_window_layout_position(int);
extern u8 lbl_80475B70[];
void TLobby__sub_801036CC();
void TLobby__sub_8020BC50();
extern void *quest_mission_manager;
extern s32 TPlayerBattleCtrl4P__init_flag;
void obj_clear_flag30_20000(void *arg0);
void TKeyBoardControl__sub_8000F950(void);
s32 reset_players__19TPlayerBattleCtrl4PFv();
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void *__nw__7TObjectFUl(int);
s32 check_flag_100__10TObjPlayerFPv();
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
void queue_destruction__7TObjectFv(void *);
int update_players__19TPlayerBattleCtrl4PFv(void*);

}
void TPlayerBattleCtrl4P::sub_80311800() {  }

void TPlayerBattleCtrl4P::sub_80311804() {  }

    extern unsigned char lobby_rule_settings[];
    extern int evt2_random_enemies_mode;
void TPlayerBattleCtrl4P::reset_random_enemies_mode() { TLobby::clear_counter(); evt2_random_enemies_mode = 0; TKeyBoardControl__sub_8000F950(); ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); }

extern void *tl_00;

void TPlayerBattleCtrl4P::return_to_hunters_guild() {
    void *o;
    o = __nw__7TObjectFUl(0x28);
    if (o != NULL) {
        ((THunterGuildSeqOffline *)o)->init(tl_00, (s32 *)TPlayerBattleCtrl4P::reset_random_enemies_mode);
    }
    queue_destruction__7TObjectFv(this);
}
void TPlayerBattleCtrl4P::sub_80311890() {  }

extern s32 reset_ctrl_to_default__19TPlayerBattleCtrl4PFv[];
void TPlayerBattleCtrl4P::finish_battle_reload() {
    if ((s32) TPlayerBattleCtrl4P__init_flag != 0) {
        reset_players__19TPlayerBattleCtrl4PFv();
        TLobby::set_fade_params((s32)reset_ctrl_to_default__19TPlayerBattleCtrl4PFv);
        set_score((s32)((void*)(3)));
    }
}

void TPlayerBattleCtrl4P::begin_battle_reload_fade() {
    if (--this->frame_timer <= 0) {
        TLobby__sub_8020BC50();
        TLobby__sub_801036CC();
        if (quest_mission_manager != NULL) {
            TQuestThread::clear_buffer(quest_mission_manager);
        }
        TLobby::stop_audio_streams();
        TPlayerBattleCtrl4P__init_flag = 0;
        TLobby::init_fadeout_state((s32)(TPlayerBattleCtrl4P::init));
        set_score((s32)((void*)((void *)2)));
    }
}
void TPlayerBattleCtrl4P::begin_battle_reload() {
    s32 var_r31;
    u32 ret;

    var_r31 = 0;
    do {
        ret = get_player_by_client_id(var_r31);
        if (ret != 0U) {
            play_effect_default__10TObjPlayerFii(ret, -1);
        }
        var_r31 += 1;
    } while (var_r31 < 4);
    frame_timer = 0xF;
    set_score((s32)((void*)(1)));
}

extern s8 controller_input_state[];

typedef char RecoveredGlobal_80311A64_TPlayerBattleCtrl4P__data_80542E90_size[sizeof(RecoveredGlobal_80311A64_TPlayerBattleCtrl4P__data_80542E90) == 0x20 ? 1 : -1];

void TPlayerBattleCtrl4P::close_battle_results() {
    s32 i;
    u32 p;
    if (intro_window != NULL) {
        TWindow__close((u8 *)intro_window);
        intro_window = NULL;
    }
    if (menu_window != NULL) {
        TWindow__close((u8 *)menu_window);
        menu_window = NULL;
    }
    close_player_windows();
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0) {
            obj_clear_flag30_20000((void *)p);
        }
    }
    TWindowCtrl::close_timer_window();
    for (i = 0; i < 4; i++) {
        TPlayerBattleCtrl4P::remove_player(this, i, 1);
    }
}
void TPlayerBattleCtrl4P::record_battle_results_after_delay() {
    s32 temp_r4;
    TPlayerBattleCtrl4P::update_all_players();
    temp_r4 = ready_timer;
    ready_timer = (temp_r4 - 1);
    if ((set_state__19TPlayerBattleCtrl4PFv(this, temp_r4) != 0) || ((s32) ready_timer <= 0)) {
        reset_score_counters();
        calculate_split_screen_battle_rankings(this);
        record_split_screen_battle_results(this);
        if ((s32) split_screen_battle_rankings.value == (s32) local_client_id) {
            TPlayerBattleCtrl4P::notify_lobby((void*)this, (void*)lbl_80475BC4, (void*)0x96);
        } else {
            TPlayerBattleCtrl4P::notify_lobby((void*)this, (void*)lbl_80475BCC, (void*)0x96);
        }
        set_score((s32)((void*)(3)));
    }
}
void TPlayerBattleCtrl4P::wait_for_rematch_menu_button() {
    if ((get_player_by_client_id(local_client_id) != 0U) && (check_flag_100__10TObjPlayerFPv() == 0) && (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 6) != 0)) {
        set_score((s32)((void*)(5)));
    }
}

#pragma push
#pragma scheduling off
void TPlayerBattleCtrl4P::close_rematch_menu() {
    u32 var_r31;
    if ((u32) this->intro_window != 0U) {
        TWindow__close((u8 *)this->intro_window);
        this->intro_window = 0U;
    }
    if ((u32) this->menu_window != 0U) {
        TWindow__close((u8 *)this->menu_window);
        this->menu_window = 0U;
    }
    var_r31 = 0;
    do {
        if ((((s32)get_player_by_client_id(var_r31)) != 0U) && (check_player_flag1__6TLobbyFv() != 0)) {
            send_code_45_to_window__19TPlayerBattleCtrl4PFPvii((this), ((u16) var_r31), 1);
        }
        var_r31 += 1;
    } while ((s32) var_r31 < 4);
    set_score((s32)((void*)(7)));
}

#pragma pop

void TPlayerBattleCtrl4P::update_rematch_menu() {
    if (has_player_active_menu__11TWindowCtrlFv(local_client_id) == 0) {
        if (((O_80311C2C *)this)->w0 == NULL) {
            ((O_80311C2C *)this)->w0 = set_window_mode_4__6TLobbyFPvll(get_window_layout_position(0x53), lbl_80475B70, 1);
            if (((O_80311C2C *)this)->w0 != NULL) {
                ((TLobby *)(((O_80311C2C *)this)->w0))->send_and_handle(((O_80311C2C *)this)->ids->a, 0x80);
            }
        }
        if (((O_80311C2C *)this)->w1 == NULL) {
            ((O_80311C2C *)this)->w1 = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x54), 2);
            forward_trade_action_default__16TObjCityMainWarpFPviii(((O_80311C2C *)this)->w1, ((O_80311C2C *)this)->ids->b, 6, 1);
            forward_trade_action_default__16TObjCityMainWarpFPviii(((O_80311C2C *)this)->w1, ((O_80311C2C *)this)->ids->d, 6, 3);
            ((TWindowSubComCard *)(((O_80311C2C *)this)->w1))->calc_window_size();
            align_menu_entry_positions(((O_80311C2C *)this)->w1);
            ((TCheckRoomSequence *)(((O_80311C2C *)this)->w1))->set_ready_flag();
        }
        if (((O_80311C2C *)this)->w1 != NULL) {
            if (((TWindowMenu *)(((O_80311C2C *)this)->w1))->is_visible() != 0) {
                switch (get_selected_menu_value(((O_80311C2C *)this)->w1)) {
                case 1:
                    shuffle_order();
                    break;
                case 2:
                    break;
                case 3:
                    set_split_screen_battle_phase(4);
                    break;
                }
            } else {
                ((TWindowSubComCard *)(((O_80311C2C *)this)->w1))->get_status_flag();
            }
        }
    }
}
void TPlayerBattleCtrl4P::wait_for_result_window_close() { if (close_windows_on_button() != 0) { close_player_windows(); update_players__19TPlayerBattleCtrl4PFv(this); set_score((s32)((void*)((void*)5))); } }

#pragma scheduling off
#pragma push
#pragma optimization_level 1
void TPlayerBattleCtrl4P::open_result_windows() {
  u32 var_r31;
  s32 player;
  if (!((s32)this))
  {
  }
  close_player_windows();
  create_result_windows();
  var_r31 = 0;
  do
  {
    player = ((s32)get_player_by_client_id(var_r31));
    if (player != 0)
    {
      if (check_player_flag1__6TLobbyFv() == 0)
      {
        TPlayerBattleCtrl4P::remove_player((void *) ((s32)this), (int) ((u16) var_r31), 1);
      }
      ((TObjPlayer *)player)->release_attached_resource();
    }
    var_r31 += 1;
  }
  while (((s32) var_r31) < 4);
  set_score((s32)((void*)(4)));
}
#pragma pop
