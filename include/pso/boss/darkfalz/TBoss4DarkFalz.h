#ifndef PSO_BOSS_DARKFALZ_TBOSS4DARKFALZ_H
#define PSO_BOSS_DARKFALZ_TBOSS4DARKFALZ_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TBoss4Fade;
struct TBoss4Type1;
class TBoss4Type2;
struct G_DarkFalzActions_6x19;
struct TBoss4Type3;
struct TObjDFUsoTower;
struct TBoss4DarkFalzSetEntry;

struct TBoss4DarkFalz : public TObjEnemy {
    TBoss4DarkFalz(TObject *parent, TBoss4DarkFalzSetEntry *set_data);
    virtual ~TBoss4DarkFalz();
    void run_state_leader_update();
    void run_state_update();
    void reset_child_ids();
    s32 alloc_child_ids(s16 *set_index_out, s16 *entity_id_out);
    virtual void run_death_reaction();
    s32 roar_timer;          // frames to the next roar sound, 300..600 (update_roar_sound_timer)
    s32 not_floor_leader;    // 0 on the floor leader's client (update_visible_flag)
    s32 state_index;         // dark_falz_state_table entry, -1 before the first change_state
    s32 state_timer; // per-state countdown: init_timer sets 30, update_timer decrements and tests < 0
    s32 next_child_index;    // added to set_index / entity_id by alloc_child_ids
    s32 minions_spawned;
    s32 minions_lost;
    s32 active_player_count; // count_active_players() when the boss was built
    TObjDFUsoTower *intro_tower;
    TBoss4Fade *fade;
    Vec cinematic_position;
    s32 cinematic_angle;
    virtual void render();
    virtual void run_task();
    static void cleanup_global();
    static void load_resources();
    static TBoss4DarkFalz *create(saddr set_data);
    static TBoss4Type1 *get_instance();
    static TBoss4Type3 *get_type3_instance();
    static TBoss4Type2 *get_type2_instance();
    int is_floor_leader();

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
    // cleanup_global's counterpart of init_uro_link; only clears the Zako draw buffers again.
    // Name inferred.
    static void release_uro_link();
    static void init_uro_link();
    static s32 count_active_players();
    static int is_ending_or_split_screen();
    void send_code_25_4(s32 arg);
    void send_action_packet(s32 arg);
    void change_state(s32 state);
    void update_visible_flag();
    s32 calc_rate_from_field();
    s32 is_timer_expired();
    void handle_defeat();
    static void spawn_defeat_effects();
    s32 sub_8004B07C();
    void set_fade(s32 color, f32 alpha);
    void place_players_on_ring();
    void place_players_for_demo();
    void refresh_player_equipment();
    void end_player_camera_pans();
    void freeze_all_players();
    void update_roar_sound_timer();
    static void free_global_instance();
    static int get_instance_count();
    void push_players_out_of_zone(s32 zone);

    void begin_defeat_sequence();
    void update_countdown_shrink();
    s32 get_live_minion_count();
    s32 get_phase();
    void count_minion_spawned();
    void count_minion_lost();
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
 * update_leader while not_floor_leader is 0 (cleared for the floor leader) and update every frame. */
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
extern "C" TBoss4DarkFalz *dark_falz_controller_instance;

/* The 0x40-byte enemy set entry the constructor was given (kind 0x200), kept with kind
 * cleared; the spawners copy it (copy_set_entry) and renumber it with
 * alloc_child_ids. TObjEnemy::apply_set_data reads set_index, entity_id, room, wave and
 * position (field names from there). */
struct TBoss4DarkFalzSetEntry {
    s16 set_index;
    s16 kind;
    u8 pad_04[0x2];
    u16 entity_id;
    s16 room;
    s16 wave;
    u8 pad_0C[0x4];
    Vec position;
    u8 pad_1C[0x24];
};

LAYOUT_ASSERT(TBoss4DarkFalzSetEntry_size, sizeof(TBoss4DarkFalzSetEntry) == 0x40);

/* What TBoss4Type1/2/3::create hand their constructors: the Dark Falz that spawns the
 * form, then a copy of its set entry renumbered past its own ids (0x1FE..0x200) with the
 * form's room (1 for the first two forms, 2 for the third). */
struct TBoss4FormSetData {
    TBoss4DarkFalz *owner;
    TBoss4DarkFalzSetEntry entry;
};

extern TBoss4DarkFalzSetEntry dark_falz_set_entry;
extern "C" void set_story_flag_or_send_quest_flag(u16 flag);
// Handler of subcommand 6x19 (TGameProtocol's table).
extern "C" void handle_6x19_dark_falz_actions(G_DarkFalzActions_6x19 *cmd);

LAYOUT_ASSERT(TBoss4DarkFalz_intro_tower_offset, offsetof(TBoss4DarkFalz, intro_tower) == 0x394);
LAYOUT_ASSERT(TBoss4DarkFalz_fade_offset, offsetof(TBoss4DarkFalz, fade) == 0x398);
LAYOUT_ASSERT(TBoss4DarkFalz_state_timer_offset, offsetof(TBoss4DarkFalz, state_timer) == 0x380);
LAYOUT_ASSERT(TBoss4DarkFalz_size, sizeof(TBoss4DarkFalz) == 0x3AC);
LAYOUT_ASSERT(TBoss4DarkFalz_cinematic_position_offset, offsetof(TBoss4DarkFalz, cinematic_position) == 0x39C);
LAYOUT_ASSERT(TBoss4DarkFalz_cinematic_angle_offset, offsetof(TBoss4DarkFalz, cinematic_angle) == 0x3A8);
#endif
