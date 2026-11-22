#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHON_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHON_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include <stddef.h>

class AreaAttackHistory;
class TParticleCtrl;
class TBoss5GryphonDemo;
class TBoss5GryphonLightningHorn;
struct Boss5GryphonActionStep;

// The arguments an action script step leaves for its state; each handler reads its own view.
struct Boss5GryphonFlightArgs {  // fn_80062660, update_low_flight_circle
    s32 turn;       // added to turn_velocity; its sign picks the circling side
    f32 speed;
    f32 radius_sq;  // update_low_flight_circle widens its turn beyond it
    f32 pad_C;
};

struct Boss5GryphonCircleArgs {  // circle_arena
    s32 turn_rate;
    s32 direction;  // > 0 circles one way, else the other
    f32 speed;
    f32 radius;
};

struct Boss5GryphonMoveArgs {  // move_to_motion_destination
    f32 x;
    f32 z;
    f32 speed;
    s32 turn_rate;
};

struct Boss5GryphonMotionEntry {
    s16 state;
    s16 timer;
    union {
        s32 seed;  // the rng seed of update_ground_lightning_attack and fn_80060020
        Boss5GryphonFlightArgs flight;
        Boss5GryphonCircleArgs circle;
        Boss5GryphonMoveArgs move;
    };
};

// Per-state work area at 0x6DC (TBoss5Gryphon::work / dive / lightning share it).
struct Boss5GryphonStepWork {
    s32 step;          // the handler's step switch; wait_for_players counts frames in it
    s32 timer;         // frames in the step
    s32 substep;       // update_demo_state's frame-cue switch
    s32 demo_flag;     // update_demo_state hands its address to the TBoss5GryphonDemo
    s32 target_angle;  // move_to_motion_destination's heading
    u32 pad_14;
    f32 fall_speed;
    f32 pad_1C[10];
};

struct Boss5GryphonDiveWork {
    s32 step;
    s32 frame_limit;  // frames left in the motion entry when step 0 ends
    u32 pad_8;
    s32 frame;        // frames in step 0
    u32 pad_10[2];
    f32 fall_speed;   // position.y drops by it each frame
};

struct Boss5GryphonTakeoffWork {
    u32 pad_0;
    s32 step;  // update_ground_takeoff's step switch
};

struct Boss5GryphonLightningWork {
    TBoss5GryphonLightningHorn *horns[2];  // left, right: spawn_ground_lightning's two horns
    s32 frame;
};

struct TBoss5Gryphon : public TObjEneDD_ST {
    TBoss5Gryphon(TObject *parent, void *data);
    virtual ~TBoss5Gryphon();
    int get_flag_bit6();
    static TBoss5Gryphon *get_instance();  // the gryphon of the running fight, NULL without one
    // Hit descriptors of the gryphon's attacks, set up at pos on owner's behalf.
    static void apply_lightning_hit(TBoss5Gryphon *owner, Vec *pos, f32 inner);
    static void apply_snarl_hit(TBoss5Gryphon *owner, Vec *pos, f32 inner, f32 scale);
    static void apply_tornado_hit(TBoss5Gryphon *owner, Vec *pos);
    static void apply_shockwave_hit(TBoss5Gryphon *owner, Vec *pos);
    virtual void render();
    virtual void dispatch_action(u32 state, s32 event);
    void state_action_noop();
    void update_idle_state(u32);
    void update_ground_pursuit(s32);
    void wait_for_players(s32);
    void update_demo_state(u32);
    void update_death_state(u32);
    void update_ground_takeoff(u32);
    void update_shockwave_attack(u32);
    void fn_80062660(s32);
    void circle_arena(s32);
    void move_to_motion_destination(s32);
    void update_landing_attack(u32);
    void fn_80062114(s32);
    void update_low_flight_straight(s32);
    void update_low_flight_circle(s32);
    void update_bezier_descent(s32);
    void update_dive_motion(s32);
    void fn_800615FC(s32);
    void handle_descend_state(s32);
    void handle_takeoff_state(s32);
    void fn_800610D0(s32);
    void state_move(s32);
    void fn_80060D9C(s32);
    void fn_80060CA4(s32);
    void fn_80060BF8(s32);
    void fn_80060B18(s32);
    void fn_80060A58(s32);
    void update_ground_lightning_attack(s32);
    void fn_80060788(s32);
    void update_offscreen_climb(s32);
    void fn_80060020(u32);
    void update_roar_state(s32);
    void fn_8005FE18(s32);
    void fn_8005FD34(s32);
    void handle_message(s32);
    virtual void run_task();
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void update_body_colliders();
    virtual void render_shadows();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    Vec bone_positions[15];  // draw_body captures the boss5_gryphon_bone_capture_node_indices nodes
    Vec move_velocity;  // scaled by scale_size; apply_velocity moves along its x and z
    s32 turn_velocity;  // apply_velocity adds it to rotation_y
    Vec position_correction;  // fn_8005FB90 adds it to position once, then clears it
    s32 targetRefreshCounter;
    Boss5GryphonMotionEntry motions[2];
    Boss5GryphonMotionEntry *motion;
    u32 flags;  // 1 destroy, 2 remote action pending, 0x40 get_flag_bit6
    TObject sub_tasks;  // the Colli and Snarl tasks hang under it; run_task runs its tasks
    s32 run_mode;  // 0 runs the actions, 1 holds them while the lobby is not ready
    s32 flight_mode;  // 0 ground, 2 low flight, 3 offscreen (the enter_*_mode setters), 1 set_flag_4e4
    Vec body_points[10];  // update_local_colliders_from_world turns them into body offsets
    Vec sound_origin;  // projected from the camera each frame; sounds play from it
    Vec pad_56C;
    AreaAttackHistory *attack_history;
    TBoss5GryphonDemo *demo;
    RenderFadeState renderFadeStates[4];
    const s32 *effect_ids;
    u8 rng[0xE8];
    // The state handlers reset the words they use on ENTER and read them their own way.
    union {
        Boss5GryphonStepWork work;            // the step machine most handlers run
        Boss5GryphonDiveWork dive;            // fn_80060020
        Boss5GryphonTakeoffWork takeoff;      // update_ground_takeoff
        Boss5GryphonLightningWork lightning;  // update_ground_lightning_attack
    };
    u32 pad_720;
    TParticleCtrl *particles[3];  // spawned and moved by fn_8005E39C in low flight
    s32 run_mode_changed;  // run_task sets it when run_mode drops back to 0
    TParticleCtrl *parts[16];  // update_ground_effects keeps one on the ground under each body point
    Boss5GryphonActionStep *script_entry;  // the action script step being run
    Boss5GryphonActionStep **action_scripts;  // boss5_gryphon_action_scripts
    void render_nodes_with_flag();
    void render_with_fade(s32 fade_index);
    void render_model();
    void copy_bone_positions();
    void draw_body();
    void free_parts();
    void update_particle_positions();
    void destroy_parts();
    void enable_particles();
    void update_ground_effects();
    void update_heading(s32 ang);
    void advance_motion_entry();
    void advance_motion_timer();
    void apply_velocity();
    void spawn_lightning_effect();
    void spawn_ground_splash();
    void update_collider_from_table();
    void set_target_from_action(void *boss8_dragon);
    void reload_stats_for_phase(void *);
    void reload_stats_for_type();
    void set_flight_height();
    void refresh_target_periodically();
    void update_linked_ground_position();
    void update_state_or_dispatch_tick();
    void set_offscreen_height();
    void set_low_flight_height();
    void set_ground_height();
    void enter_offscreen_mode();
    void enter_low_flight_mode();
    void enter_ground_mode();
    void play_se(s32 se_id);
    void shift_position_history();
    static void cleanup();
    static void *create(void *data);
    void set_random_param(u8 *params);
    void calc_params(void *params, Boss5GryphonActionStep *step);
    void calc_product_and_ratio(void *params, Boss5GryphonActionStep *step);
    void calc_attack_params(void *params, Boss5GryphonActionStep *step);
    void fn_8005EBDC(u8 *params, Boss5GryphonActionStep *step);
    s32 get_random_sign(Boss5GryphonActionStep *step, s32 i);
    s32 calc_product(Boss5GryphonActionStep *step, s32 sign_index, s32 range_index);
    s32 rand_scaled_offset(s32 base, s32 spread);
    s32 fn_8005E9D8(Boss5GryphonActionStep *step, s32 i);
    s32 random_in_table_range(Boss5GryphonActionStep *step, s32 i);
    f32 random_in_range(f32 min, f32 range);
    f32 fn_8005EAD0(Boss5GryphonActionStep *step, s32 i);
    s32 run_action_script_step(s16 *out, u32 *entry);
    static void copy_angle_state(void *gryphon, void *dst, void *src);
    void update_target_from_state();
    void choose_next_action(u32 *entry);
    s32 get_player_pos_in_arc(s32 left, s32 client_id, Vec *org, Vec *out);
    void fire_horn_lightning(s32 left, s32 client_id);
    void play_animation_index(s32 index);
    void flush_pending_effect();
    void scale_size(f32 scale, f32 scale_y, f32 turn_scale);
    void copy_spawn_params(void* a1);
    void fill_follow_camera_params(u8 *arg1, u8 *arg2);
    void set_animation_by_state();
    void init_state_zero();
    void set_flag_4e4();
    void fire_at_angle(s32 ang);
    void turn_toward_angle_limited(s32 ang, s32 target);
    void update_facing(f32 speed);
    void move_along_angle(f32 speed, s32 ang);
    void emit_part_attack_effect(int part);
    void query_default();
    void attack_default();
    void set_state_2();
    void update_state_3();
    void run_default_state();
    void fn_80064828();
    void fn_800648C8();
    void fn_8005FB90();
    void fn_80063EF4();
    void fn_800641A8();
    void fn_800646F0();
    void fn_80064DB8();
    void fn_80064E3C();
    void spawn_ancient_trap(s32 id);
    s32 fn_8005DC0C();
    void fn_8005E040();
    s32 fn_8005E1E8(Vec *point, f32 radius);
    void fn_8005E39C();
    s32 fn_8005FAE0();
    void fn_8006426C();
    void fn_8006435C();
    void fn_8006442C();
    void fn_80064AB0();
};

LAYOUT_ASSERT(TBoss5Gryphon_size, sizeof(TBoss5Gryphon) == 0x77C);
LAYOUT_ASSERT(TBoss5Gryphon_turn_velocity, offsetof(TBoss5Gryphon, turn_velocity) == 0x480);
LAYOUT_ASSERT(TBoss5Gryphon_sound_origin, offsetof(TBoss5Gryphon, sound_origin) == 0x560);
LAYOUT_ASSERT(TBoss5Gryphon_action_scripts, offsetof(TBoss5Gryphon, action_scripts) == 0x778);
LAYOUT_ASSERT(TBoss5Gryphon_fade, offsetof(TBoss5Gryphon, renderFadeStates) == 0x580);
LAYOUT_ASSERT(TBoss5Gryphon_work, offsetof(TBoss5Gryphon, work) == 0x6DC);
LAYOUT_ASSERT(TBoss5Gryphon_particles, offsetof(TBoss5Gryphon, particles) == 0x724);
#endif
