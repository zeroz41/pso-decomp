#ifndef PSO_BOSS_DARKFALZ_TBOSS4DARKFALZ_H
#define PSO_BOSS_DARKFALZ_TBOSS4DARKFALZ_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TBoss4Fade;
struct TBoss4Type1;
struct TObjDFUsoTower;

struct TBoss4DarkFalz : public TObjEnemy {
    virtual ~TBoss4DarkFalz();
    void sub_8004B0F8();
    void sub_8004B084();
    void sub_8004AFB8();
    virtual void run_death_reaction();
    u32 m_374;
    u32 m_378;
    u32 m_37c;
    s32 state_timer; // per-state countdown: init_timer sets 30, update_timer decrements and tests < 0
    s32 m_384;
    u32 m_388;
    u32 m_38c;
    u32 m_390;
    TObjDFUsoTower *intro_tower;
    TBoss4Fade *fade;
    Vec cinematic_position;
    s32 cinematic_angle;
    virtual void render();
    virtual void run_task();
    static void cleanup_global();
    static void load_resources();
    static s32 create(s32 arg0);
    static TBoss4Type1 *get_instance();
    int is_field378_zero();

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
    static void push_players_out_of_zone(s32 boss4_dark_falz, s32 arg1);

    void begin_defeat_sequence();
    void update_countdown_shrink();
    s32 sub_8004D990();
    static s32 is_state_ready();
    static s32 is_active();
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

LAYOUT_ASSERT(TBoss4DarkFalzHandler_size, sizeof(TBoss4DarkFalzHandler) == 0xC);
LAYOUT_ASSERT(TBoss4DarkFalzState_size, sizeof(TBoss4DarkFalzState) == 0x34);
LAYOUT_ASSERT(TBoss4DarkFalzState_enter_offset, offsetof(TBoss4DarkFalzState, enter) == 4);
LAYOUT_ASSERT(TBoss4DarkFalzState_leave_offset, offsetof(TBoss4DarkFalzState, leave) == 0x10);
LAYOUT_ASSERT(TBoss4DarkFalzState_leader_offset, offsetof(TBoss4DarkFalzState, update_leader) == 0x1C);
LAYOUT_ASSERT(TBoss4DarkFalzState_update_offset, offsetof(TBoss4DarkFalzState, update) == 0x28);

extern TBoss4DarkFalzState dark_falz_state_table[16];
extern "C" void set_story_flag_or_send_quest_flag(u16 flag);

LAYOUT_ASSERT(TBoss4DarkFalz_intro_tower_offset, offsetof(TBoss4DarkFalz, intro_tower) == 0x394);
LAYOUT_ASSERT(TBoss4DarkFalz_fade_offset, offsetof(TBoss4DarkFalz, fade) == 0x398);
LAYOUT_ASSERT(TBoss4DarkFalz_state_timer_offset, offsetof(TBoss4DarkFalz, state_timer) == 0x380);
LAYOUT_ASSERT(TBoss4DarkFalz_size, sizeof(TBoss4DarkFalz) == 0x3AC);
LAYOUT_ASSERT(TBoss4DarkFalz_cinematic_position_offset, offsetof(TBoss4DarkFalz, cinematic_position) == 0x39C);
LAYOUT_ASSERT(TBoss4DarkFalz_cinematic_angle_offset, offsetof(TBoss4DarkFalz, cinematic_angle) == 0x3A8);
#endif
