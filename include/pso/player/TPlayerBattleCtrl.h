#ifndef PSO_PLAYER_TPLAYERBATTLECTRL_H
#define PSO_PLAYER_TPLAYERBATTLECTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/player/BattleRanking.h"

struct TWindowMessage;
struct G_SetBattleModeData_6x7D;
struct G_BattleScores_6x7F;
struct TWindowMenu;
struct TWindowDuelResult;

// Window size {width, height} passed to TWindowMessage::create.
struct BattleIntroWindowSize { f32 x, y; };
// Score or player count of the two teams.
struct BattleTeamTotals { s32 team[2]; };

class TPlayerBattleCtrl : public TObject {
public:
    TPlayerBattleCtrl(TObject *parent);
    virtual ~TPlayerBattleCtrl();
    void init_battle_round();
    void apply_game_settings(s32 use_config);
    void update_state();
    // States run by update_state.
    void update_battle_intro();
    void update_timed_wait();
    void end_battle_mode_cleanup();
    void start_duel_battle();
    void update_battle_sync(s32 t);
    s32 check_timeout(s32 timer);
    void send_battle_mode_state();
    void request_timed_event();
    void reset_score_counters();
    void initialize_battle();
    void send_player_ready();
    // Tells the player they are being sent back to the visual lobby and waits for START.
    void show_lobby_transport_notice();
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
    const char **text;  // player_battle_ctrl_text_japanese or _english
    s32 timeout;
    s32 end_wait;
    TWindowMessage *window_4c;
    TWindowMenu *window_50;
    TWindowDuelResult *window_54;
    s32 aborted_after_result;  // a team emptied while the duel result was up, not mid-fight
    s32 pad_5c;
    s32 state_send_wait;
    s32 battle_ctrl_default;  // battle_ctrl_default_value when the duel starts
    char intro_text[0x200];   // the quest's ba_start text, shown by the intro window
    s8 timed_event_flags[8];  // one per battle_event_second_table entry still to send
    s32 timed_event_state;
    s32 pad_274;
};

#include <stddef.h>
LAYOUT_ASSERT(TPlayerBattleCtrl_state_1c_offset, offsetof(TPlayerBattleCtrl, state_1c) == 0x1c);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_20_offset, offsetof(TPlayerBattleCtrl, state_20) == 0x20);
LAYOUT_ASSERT(TPlayerBattleCtrl_state_24_offset, offsetof(TPlayerBattleCtrl, state_24) == 0x24);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_4c_offset, offsetof(TPlayerBattleCtrl, window_4c) == 0x4c);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_50_offset, offsetof(TPlayerBattleCtrl, window_50) == 0x50);
LAYOUT_ASSERT(TPlayerBattleCtrl_window_54_offset, offsetof(TPlayerBattleCtrl, window_54) == 0x54);
LAYOUT_ASSERT(TPlayerBattleCtrl_intro_text_offset, offsetof(TPlayerBattleCtrl, intro_text) == 0x68);
LAYOUT_ASSERT(TPlayerBattleCtrl_timed_event_state_offset, offsetof(TPlayerBattleCtrl, timed_event_state) == 0x270);
LAYOUT_ASSERT(TPlayerBattleCtrl_size, sizeof(TPlayerBattleCtrl) == 0x278);


s32 is_battle_mode_running(void);
s32 get_ranked_battle_ctrl_value(void);
s32 is_duel_ranking_empty(void);
// Fade-in callback: sends the controller back to its first state for the next round.
void restart_battle_after_fade(void);
void update_battle_exit_sequence(TPlayerBattleCtrl *ctrl);
void free_char_slots(void);
s32 get_battle_time_limit_frames(void);
void clear_battle_player_ready_flags(void);
void handle_6x7E(void);
void handle_6x7D_set_battle_mode_data(G_SetBattleModeData_6x7D *pkt);
void handle_6x7F_battle_scores(G_BattleScores_6x7F *cmd);
void record_local_battle_placement(void *battle_ctrl);
extern "C" {
void send_6x7D_set_battle_mode_data(void *battle_ctrl);
}
// Battle-mode setup run outside any battle controller.
void init_char_slots(void);
void init_battle_ctrl(s32 config, saddr src);
void init_and_set_flag(void);
void finish_chr_select_scene_init(void);
void send_battle_mode_params(s8 command, s32 value, s32 extra);
void apply_battle_rules_to_players(void);
s32 get_battle_ctrl_default(void);


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

struct UpdateBattleIntroName { char s[16]; };

#endif
