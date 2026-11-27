#ifndef PSO_PLAYER_TPLAYERBATTLECTRL4P_H
#define PSO_PLAYER_TPLAYERBATTLECTRL4P_H
#include "pso/system/task/TObject.h"
#include "pso/player/BattleRanking.h"

class TObjPlayer;
class TWindowBase;
struct BattleRuleConfig;
class TWindowMessage;
class TWindowMenu;

extern BattleRanking split_screen_battle_rankings[4];

s32 are_split_screen_battle_players_tied(void);
BattleRanking *get_split_screen_battle_rankings(void);

class TPlayerBattleCtrl4P : public TObject {
private:
    TPlayerBattleCtrl4P(TObject *parent);
    virtual ~TPlayerBattleCtrl4P();
    void set_split_screen_battle_phase(s32 phase);
    void reset_phase();
    void clear_player_windows();
    s32 get_time_limit();
    void request_timed_event();
    void refresh_alive_flags();
    s32 calculate_rankings();
    void record_results();
    s32 calc_battle_score(TObjPlayer *player);
    void hold_player(u16 client_id, s32 hold_input);
    void release_player(u16 client_id, s32 release_input);
    void destroy_dead_spots(TObject *parent);
    void set_phase_state(s32 state);
public:
    void idle_return_step2();
    void idle_return_step1();
    void return_to_hunters_guild();
    void idle_reload_done();
    void finish_battle_reload();
    void begin_battle_reload_fade();
    void begin_battle_reload();
    void close_battle_results();
    void record_battle_results_after_delay();
    void wait_for_rematch_menu_button();
    void close_rematch_menu();
    void update_rematch_menu();
    void wait_for_result_window_close();
    void open_result_windows();
    void wait_before_recording_results();
    void wait_after_battle_end();
    void begin_battle_results();
    void update_battle_time_and_rankings();
    void start_battle();
    void close_intro_and_start_battle();
    void wait_for_start_countdown();
    void update_ready_wait();
    void begin_ready_wait();
    void wait_for_team_matchup();
    void show_team_matchup();
    void wait_for_intro_text();
    void show_intro_text();
    void open_intro_window();
    void update_reload_phase();
    void update_return_phase();
    void update_results_phase();
    void update_battle_phase();
    void update_intro_phase();
    void initialize_battle();
    virtual void run_task();

    BattleRuleConfig *rule_data;
    TWindowMessage *intro_window;
    TWindowMenu *menu_window;
    TWindowBase *player_windows[4];
    char intro_text[0x200];
    s8 timed_event_flags[8];
    s32 frame_timer;
    s32 battle_duration;
    s32 player_refresh_timer;
    s32 ready_timer;
    s64 battle_start_ticks;
    saddr remaining_seconds;
    s32 result_confirm_timer;
    s32 timed_event_state;
    s32 player_active[4];
    s32 player_teams[4];
    s32 battle_ctrl_default;  // quest opcodes enable_win_pfx / disable_win_pfx
    u16 player_order[4];
    s32 unknown_290;
    const char** message_table;
    s32 phase;
    s32 phase_state;
public:
    s32 close_windows_on_button();
    void close_player_windows();
    void create_result_windows();
    static s32 is_battle_mode_active();
    static void reset_ctrl_to_default();
    static void init();
    // Plays the result jingle and shows the duel result window for duration frames.
    void notify_lobby(const char *file, saddr duration);
    void reset_score_counters();
    s32 set_state();
    void update_players();
    void start_match();
    s32 is_battle_decided();
    s32 check_all_players_flag();
    void apply_rule_configuration(s32 use_rules);
    void update_all_players();
    void shuffle_order();
    void update();

    static void reset_random_enemies_mode(TObject *fade);
    static void init_instance_with_text(saddr rules, saddr text);

    static const char *class_name;
    static TPlayerBattleCtrl4P *instance;
    // Set by init once the reload fade has reset the scene; finish_battle_reload waits for it.
    static s32 reload_ready;
    static const char *japanese_messages[7];
    static const char *english_messages[7];
public:
    void update_player_alive_flags();
    void update_timed_events(s32 frames);
    void reset_players();
    void start_duel();
    void init_battle();
};
#include <stddef.h>
LAYOUT_ASSERT(BattleCtrlSize, sizeof(TPlayerBattleCtrl4P)==0x2A0);
LAYOUT_ASSERT(BattleCtrlOffset_rule_data, offsetof(TPlayerBattleCtrl4P,rule_data)==0x1C);
LAYOUT_ASSERT(BattleCtrlOffset_intro_window, offsetof(TPlayerBattleCtrl4P,intro_window)==0x20);
LAYOUT_ASSERT(BattleCtrlOffset_player_windows, offsetof(TPlayerBattleCtrl4P,player_windows)==0x28);
LAYOUT_ASSERT(BattleCtrlOffset_intro_text, offsetof(TPlayerBattleCtrl4P,intro_text)==0x38);
LAYOUT_ASSERT(BattleCtrlOffset_frame_timer, offsetof(TPlayerBattleCtrl4P,frame_timer)==0x240);
LAYOUT_ASSERT(BattleCtrlOffset_battle_start_ticks, offsetof(TPlayerBattleCtrl4P,battle_start_ticks)==0x250);
LAYOUT_ASSERT(BattleCtrlOffset_message_table, offsetof(TPlayerBattleCtrl4P,message_table)==0x294);
LAYOUT_ASSERT(BattleCtrlOffset_phase, offsetof(TPlayerBattleCtrl4P,phase)==0x298);
LAYOUT_ASSERT(BattleCtrlOffset_phase_state, offsetof(TPlayerBattleCtrl4P,phase_state)==0x29C);
#endif
