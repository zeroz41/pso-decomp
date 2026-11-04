#ifndef PSO_BOSS_TBOSS4DARKFALZ_H
#define PSO_BOSS_TBOSS4DARKFALZ_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TBoss4DarkFalz : public TObjEnemy {
    virtual ~TBoss4DarkFalz();
    void sub_8004B0F8();
    void sub_8004B084();
    void sub_8004AFB8();
    virtual void vfunc_63();
    u32 m_374;
    u32 m_378;
    u32 m_37c;
    s32 state_timer; // per-state countdown: init_timer sets 30, update_timer decrements and tests < 0
    s32 m_384;
    u32 m_388;
    u32 m_38c;
    u32 m_390;
    u32 m_394;
    u32 m_398;
    virtual void render();
    virtual void run_task();
    static void cleanup_global();
    static void load_resources();
    static s32 create(s32 arg0);
    static s32 get_instance();
    int is_field378_zero();
    s32 get_action_state();
    s32 get_phase();
    s32 get_state();
    void*get_hit_data();
    void save_position();
    void swap_and_send();
    void swap_bytes();
    void set_code_25_4();
    void set_state();
    void update_fade_countdown();
    void request_action_e();
    void start_phase();
    void enter_state_126();
    void init_state();
    void enter_state_142();
    void update_timer();
    void request_action_9();
    void update_parts();
    void update_spawn_type2_countdown();
    void start_demo1();
    void spawn_ancient_trap();
    void request_action_7();
    void spawn_type1();
    void update_intro_demo();
    void start_effect();
    void spawn_trap();
    void check_timeout();
    void init_timer();
    void start_demo();
    void check_players_near_center();
    static void clear_uro_link_state();
    static void init_uro_link();
    static void *create_demo2(void *arg0, void *arg1, void *arg2, void *arg3);
    static s32 count_active_players();
    static int is_ending_or_split_screen();
    void send_code_25_4(s32 arg);
    void send_action_packet(s32 arg);
    void change_state(s32 arg1);
    void update_visible_flag();
    s32 calc_rate_from_field();
    s32 is_timer_expired();
    void handle_defeat();
    static void refresh_player_equipment(void *self);
    static void end_player_camera_pans(void *self);
    static void freeze_all_players(void *self);
    void update_roar_sound_timer();
    static void free_global_instance();
    static int get_instance_count();
    static void push_players_out_of_zone(s32 arg0, s32 arg1);
    static void *create_demo1(void *arg0, void *arg1, void *arg2);
    static void dispatch_by_main_phase(u16 arg0);
    void begin_defeat_sequence();
    void update_countdown_shrink();
    void get_demo2_params(u16 *a, u16 *b, u16 *out);
    void get_defeat_params(u16 *a, u16 *b, u16 *out);
    s32 sub_8004D990();
    static u8 is_state_ready();
    static u8 is_active();
    void spawn_zako_rings();
    void enter_demo2_phase();
    // State handlers installed in the state table dark_falz_state_table (TBoss4DarkFalz_8004C93C.cpp).
    void update_ol_ending();
    void update_type3();
    void update_demo_warp3();
    void update_get_ring();
    void update_leader_get_ring();
    void update_leader_die_type2();
    void update_type2();
    void update_leader_app_type2();
    void update_leader_app_type1();
    void enter_zako();
    void update_demo_warp1();
    void update_demo_warp0();
    void update_leader_editor();
};

typedef void (TBoss4DarkFalz::*TBoss4DarkFalzHandler)();

/* One state of the TBoss4DarkFalz state machine (16 records, names EDITOR .. OL ENDING).
 * change_state calls leave on the old state and enter on the new one; run_task calls
 * update_leader while m_378 is 0 (cleared for the floor leader) and update every frame. */
struct TBoss4DarkFalzState {
    const char *name;
    TBoss4DarkFalzHandler enter;
    TBoss4DarkFalzHandler leave;
    TBoss4DarkFalzHandler update_leader;
    TBoss4DarkFalzHandler update;
};

typedef char TBoss4DarkFalz_size[sizeof(TBoss4DarkFalz) == 0x39C ? 1 : -1];
#endif
