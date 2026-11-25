#ifndef PSO_PLAYER_TPLAYERBATTLECTRL_H
#define PSO_PLAYER_TPLAYERBATTLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/player/BattleRanking.h"

class TPlayerBattleCtrl : public TObject {
public:
    TPlayerBattleCtrl(TObject *parent);
    virtual ~TPlayerBattleCtrl();
    void init_battle_round();
    // States run by update_player_battle_ctrl_state.
    void update_battle_intro();
    void update_timed_wait();
    void end_battle_mode_cleanup();
    void start_duel_battle();
    void update_battle_sync(s32 t);
    s32 check_timeout(s32 timer);
    void send_battle_mode_state();
    void set_flag_270();
    void show_score_results();
    void init();
    s32 check_all_battle_flags();
    s32 check_battle_end();
    s32 check_all_players_ready();
    s32 check_team_balance(s32 check_rule);
    s32 calc_player_rankings();
    void update_duel_result();
    virtual void run_task();
    s32 state_1c;
    s32 state_20;
    s32 state_24;
    s32 unk_28;
    s32 timer;
    s64 start_time;
    s32 time_left;
    s32 time_limit;
    u8 *text;
    s32 timeout;
    s32 end_wait;
    void *window_4c;
    void *window_50;
    void *window_54;
    u8 pad_58[0x8];
    s32 state_send_wait;
    s32 pad_64;
    u8 pad_68[0x210];
};

#include <stddef.h>
LAYOUT_ASSERT(TPlayerBattleCtrl_state_1c_offset, offsetof(TPlayerBattleCtrl, state_1c) == 0x1c);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_20_offset, offsetof(TPlayerBattleCtrl, state_20) == 0x20);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_24_offset, offsetof(TPlayerBattleCtrl, state_24) == 0x24);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_4c_offset, offsetof(TPlayerBattleCtrl, window_4c) == 0x4c);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_50_offset, offsetof(TPlayerBattleCtrl, window_50) == 0x50);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_54_offset, offsetof(TPlayerBattleCtrl, window_54) == 0x54);
LAYOUT_ASSERT(TPlayerBattleCtrl_size, sizeof(TPlayerBattleCtrl) == 0x278);


extern "C" {
u8 is_battle_mode_running(void);
s32 TLobby__sub_801C2678(void);
}
s32 is_duel_ranking_empty(void);
extern "C" {
void TLobby__sub_801C2C34(void *arg0);
void TLobby__sub_801C38A4(void);
}
void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl);
extern "C" {
void free_char_slots(void);
}
s32 get_battle_time_limit_frames(void);
void clear_battle_player_ready_flags(void);
extern "C" {
void fn_801C4CE0(TPlayerBattleCtrl *player_battle_ctrl);
void handle_6x7E(void);
void handle_6x7F_battle_scores(saddr command);
}
void record_local_battle_placement(void *arg0);
extern "C" {
void send_6x7D_set_battle_mode_data(void *arg0);
}
// Battle-mode setup run outside any battle controller.
void init_char_slots(void);
void init_battle_ctrl(s32 config, saddr src);
void init_and_set_flag(void);
void apply_game_settings(s32 owner, s32 use_config);
void finish_chr_select_scene_init(void);
void send_battle_mode_params(s8 command, s32 value, s32 extra);
void apply_battle_rules_to_players(void);
s32 get_battle_ctrl_default(void);
void update_player_battle_ctrl_state(void *player_battle_ctrl);


// Copies one ranking row; the ranking sorts swap rows through it.
void copy_battle_ranking(BattleRanking *dst, BattleRanking *src);

// Final places and scores of the current network battle.
extern BattleRanking duel_result_table[4];

// Plays the result jingle and shows the duel result window for duration frames.
void play_duel_result_stream(const char *file, saddr duration);

extern s32 battle_ctrl_default_value;

// Battle event times in seconds; start_duel_battle arms one pending event per non-zero entry.
extern s16 battle_event_second_table[8];

// Battle score weights the quest opcodes ba_*_score set; the rule setup hands them to each player's
// score counters.
extern f32 battle_player_give_damage_score;
extern f32 battle_player_take_damage_score;
extern f32 battle_player_kill_score;
extern f32 battle_player_death_score;
extern f32 battle_enemy_give_damage_score;
extern f32 battle_enemy_kill_score;
extern f32 battle_enemy_death_score;
extern f32 battle_enemy_take_damage_score;
extern f32 battle_meseta_score;

#endif
