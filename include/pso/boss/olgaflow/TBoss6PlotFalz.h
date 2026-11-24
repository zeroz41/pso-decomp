#ifndef PSO_BOSS_OLGAFLOW_TBOSS6PLOTFALZ_H
#define PSO_BOSS_OLGAFLOW_TBOSS6PLOTFALZ_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
struct TObjPlayer;

extern "C" {
// Nonzero when the game runs on Normal difficulty (game_difficulty_selection == 0).
s32 is_normal_difficulty(void);
}

// One step of the boss's pseudo-random sequence (the ANSI C rand() recurrence on a caller-held seed):
// returns the next value of seed (next_random_seed is an inferred name).
s32 next_random_seed(s32 seed);

struct BmlResource;
class TBoss4Fade;
struct TBoss6Tube;
struct TBoss6Type1;
struct TBoss6Type2;

class TBoss6Demo15_TYPE2_WAIT;

// The 0x40-byte enemy set entry the constructor was given, kept with kind cleared; spawn_type1/2
// copy it (copy_set_entry) and renumber it for the bodies (TBoss4DarkFalzSetEntry layout).
struct TBoss6PlotFalzSetEntry {
    s16 set_index;
    s16 kind;
    u8 pad_04[0x2];
    u16 entity_id;
    s16 room;
    u8 pad_0A[0x36];
};

struct TBoss6PlotFalz;

// The plot owner, copied set entry and variant passed to both body factories.
struct Boss6BodySpawnParams {
    TBoss6PlotFalz *owner;
    TBoss6PlotFalzSetEntry set_entry;
    u8 variant;
};

LAYOUT_ASSERT(Boss6BodySpawnParamsSetEntryOffset, offsetof(Boss6BodySpawnParams, set_entry) == 0x4);
LAYOUT_ASSERT(Boss6BodySpawnParamsVariantOffset, offsetof(Boss6BodySpawnParams, variant) == 0x44);

struct TBoss6PlotFalz : public TObjEnemy {
    TBoss6PlotFalz(TObject *parent, void *set_data);
    virtual ~TBoss6PlotFalz();
    void ensure_field384();
    void set_visible_flag();
    void call_state_action();
    void reset_child_ids();
    // How many child ids get_next_point can still hand out.
    s32 count_free_child_ids();
    void run_death_reaction();
    s32 not_floor_leader;  // 0 on the floor leader's client (set_visible_flag)
    s32 state_index;  // index into boss6_plot_falz_script_states
    u8 spawn_variant;  // the 6xA3 mode; handed to the bodies as Boss6BodySpawnParams::variant
    u8 pad_37D[0x3];
    TBoss4Fade *fade;
    TBoss6Tube *tube;  // the warp tube; ensure_field384 creates it
    TBoss6PlotFalzSetEntry set_entry;
    s32 next_child_index;  // added to set_index / entity_id by get_next_point
    s32 state_timer;  // frames in the current plot state
    s32 shake_active;
    s32 shake_timer;
    s32 shake_preset;
    TBoss6Demo15_TYPE2_WAIT *wait_demo;  // the DEMO_WAIT_T2 scene object
    static s32 get_hp();
    static TBoss6Type2 *get_type2();
    static s32 damage_player_hp(s32 client, u32 damage);
    static s32 sort_active_players();
    static u16 get_sorted_player(s32 i);  // i-th client id of sort_active_players' order
    static u16 pick_random_active_player();
    int is_idle();
    TBoss6PlotFalzSetEntry *get_set_entry();
    static s32 is_active(TObjPlayer *player);
    static s32 is_state_1f(TObjPlayer *player);
    // Puts the player at pos (position and previous position).
    static void move_player_to(TObjPlayer *player, Vec *pos);
    void set_state_2();
    void reset_state();
    void activate_warp();
    void free_child();
    void set_state(s32 state);
    static void spawn_player_hit_effects();
    void award_exp_and_destroy();
    void apply_fade_alpha(s32 color, f32 alpha);
    static s32 rand_vary_count(s32 base, f32 spread);
    static f32 cosine_ease(f32 t);
    static f32 get_value();
    static s32 is_boss_active();
    void release_object();
    static void end_cutscene_camera();
    void destroy_static_instance();
    void queue_instance_destruction();
    s32 get_target_pos_a(Vec *position);
    s32 get_target_pos_b(Vec *position);
    static void refresh_players_equipment();
    void spawn_type2();
    void spawn_type1();
    static void apply_radial_effect_to_players(void *pos, s16 amount, s16 kind, f32 range);
    static void set_fade_material_color(f32 f);
    static void update_camera_target();
    static void apply_fade_material_color(f32 fade, f32 r, f32 g, f32 b);
    static int get_phase();
    s32 get_scene_state();
    static BmlResource *get_scene_archive();
    static void freeze_all_players();
    void render();
    void run_task();
    void send_6xA3_action(s8 v);
    static void free_all();
    static void load_resources();
    static s32 create(saddr set_data);
    static s32 is_phase_reached();
    void reset_ending_state();
    void update_plot_timer();
    void check_and_advance_state();
    void set_state4_if_ready();
    void reset_and_recreate();
    void update_phase();
    void enter_active_state();
    void tick_timeout();
    void advance_intro_timer();
    void advance_if_ready();
    s32 is_ending_or_split_screen();
    int is_ready();
    void finish_and_dispatch_next_phase();
    void check_action_7();
    void advance_timer();
    void advance_phase_if_ready();
    void update_cutscene_fade();
    static s32 is_flag_set();
    s32 get_next_point(s16 *set_index_out, s16 *entity_id_out);
    void run_phase_action();
    void update_random_shake();
    // Horizontal distance of pos from the arena centre.
    static f32 arena_center_distance(const Vec *pos);
    // Nonzero while the first body is alive and not in its death state.
    static s32 is_type1_active();
    static void warp_nearby_players();
    // Plot script state actions (enter / tick / update of a boss6_plot_falz_script_states row).
    void update_ol_ending();
    void update_vs_type2();
    void enter_vs_type2();
    void stop_adx_audio();
    void init_hall_boss_scene();
    void update_demo_ded_t1();
    void update_vs_type1();
    void tick_demo_start();
    void init_proto1_adx();
    void enter_fall_elev();
    static void update_active_flag();
};

// The two Olga Flow bodies of the running fight, NULL when there is none.
extern TBoss6Type1 *TBoss6PlotFalz__type1_instance;
extern TBoss6Type2 *TBoss6PlotFalz__type2_instance;
// The running TBoss6PlotFalz (set by its constructor, cleared by its destructor).
extern saddr TBoss6PlotFalz__instance;
// Client ids in descending hp order (sort_active_players, get_sorted_player).
extern u16 boss6_plot_falz_player_order_table[];
// 1 on the main floor phase 0xF or in split screen (update_active_flag, get_phase).
extern s32 plot_falz_phase;

extern "C" {
void TBoss6PlotFalz__sub_802AC008(f32 fade, f32 hp_ratio);
}

extern "C" {
// TRUE when the sphere (pos, r) is out of the arena (inferred from TBoss6Rock).
s32 TBoss6PlotFalz__sub_802AB6CC(void *pos, f32 r);
}

#endif
