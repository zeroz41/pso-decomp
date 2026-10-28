#ifndef PSO_MISC_TPLAYERBATTLECTRL4P_H
#define PSO_MISC_TPLAYERBATTLECTRL4P_H
#include "pso/TObject.h"

class TPlayerBattleCtrl4P : public TObject {
private:
    TPlayerBattleCtrl4P();
    virtual ~TPlayerBattleCtrl4P();
    void set_split_screen_battle_phase(s32);
public:
    TPlayerBattleCtrl4P* construct(TObject* parent);
    TPlayerBattleCtrl4P* destroy(s16 should_free);
    void sub_80311800();
    void sub_80311804();
    void return_to_hunters_guild();
    void sub_80311890();
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

    u8* rule_data;
    void* intro_window;
    void* menu_window;
    void* player_windows[4];
    char intro_text[0x200];
    u8 timed_event_flags[8];
    s32 frame_timer;
    s32 battle_duration;
    s32 player_refresh_timer;
    s32 ready_timer;
    s64 battle_start_ticks;
    s32 remaining_seconds;
    s32 result_confirm_timer;
    s32 timed_event_state;
    s32 player_active[4];
    s32 player_teams[4];
    u8 unknown_284[4];
    s16 player_order[4];
    u8 unknown_290[4];
    const char** message_table;
    s32 phase;
    s32 phase_state;
public:
    s32 get_state();
    void set_battle_mode(s32 v);
    s32 close_windows_on_button();
    void close_player_windows();
    void create_result_windows();
    static u8 is_battle_mode_active();
    static void reset_ctrl_to_default();
    static void init();
    static int init_ctrl_default(void* p);
    static void notify_lobby(void* p, void* a1, void* a2);
    void reset_score_counters();
    s32 set_state();
    static void update_players();
    void start_match();
    u8 is_battle_decided();
    static s32 check_all_players_flag();
    static s32 fn_80211B10(s32 client_id);
    static void remove_player(void *arg0, u16 arg1, s32 arg2);
    void apply_rule_configuration(s32 arg1);
    void set_score(s32 v);
    static void update_all_players();
    void shuffle_order();
    static void update();
    static void reset_random_enemies_mode();
    static void init_instance_with_text(s32 arg0, s32 arg1);
public:
    void update_player_alive_flags();
    void update_timed_events(s32 frames);
    void reset_players();
    void start_duel();
    void init_battle();
};
#include <stddef.h>
typedef char BattleCtrlSize[(sizeof(TPlayerBattleCtrl4P)==0x2A0)?1:-1];
typedef char BattleCtrlOffset_rule_data[(offsetof(TPlayerBattleCtrl4P,rule_data)==0x1C)?1:-1];
typedef char BattleCtrlOffset_intro_window[(offsetof(TPlayerBattleCtrl4P,intro_window)==0x20)?1:-1];
typedef char BattleCtrlOffset_player_windows[(offsetof(TPlayerBattleCtrl4P,player_windows)==0x28)?1:-1];
typedef char BattleCtrlOffset_intro_text[(offsetof(TPlayerBattleCtrl4P,intro_text)==0x38)?1:-1];
typedef char BattleCtrlOffset_frame_timer[(offsetof(TPlayerBattleCtrl4P,frame_timer)==0x240)?1:-1];
typedef char BattleCtrlOffset_battle_start_ticks[(offsetof(TPlayerBattleCtrl4P,battle_start_ticks)==0x250)?1:-1];
typedef char BattleCtrlOffset_message_table[(offsetof(TPlayerBattleCtrl4P,message_table)==0x294)?1:-1];
typedef char BattleCtrlOffset_phase[(offsetof(TPlayerBattleCtrl4P,phase)==0x298)?1:-1];
typedef char BattleCtrlOffset_phase_state[(offsetof(TPlayerBattleCtrl4P,phase_state)==0x29C)?1:-1];
#endif
