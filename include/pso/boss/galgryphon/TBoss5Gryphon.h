#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHON_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHON_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/boss/galgryphon/Boss5GryphonMotionEntry.h"
#include <stddef.h>

struct NJS_OBJECT;

class AreaAttackHistory;
class TParticleCtrl;
class TBoss5GryphonColli;
class TBoss5GryphonLightningHorn;
struct Boss5GryphonActionStep;
struct G_GalGryphonBossActions_6x9F;
struct G_GalGryphonBossActions_6xA0;

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
    static void spawn_switch_attack(const Vec *pos);
    static void spawn_attack_effect(const Vec *pos);
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
    void update_turning_flight(s32);  // fly (action 4): flies on, turning by motion->args.flight.turn
    void circle_arena(s32);
    void move_to_motion_destination(s32);
    void update_landing_attack(u32);
    void update_glide_in(s32);  // kakuin motion (action 6): glides down into low flight
    void update_low_flight_straight(s32);
    void update_low_flight_circle(s32);
    void update_bezier_descent(s32);
    void update_dive_motion(s32);
    void update_spiral_in(s32);  // kirin motion (action 0x13): the same drop into low flight
    void handle_descend_state(s32);
    void handle_takeoff_state(s32);
    void update_run_in(s32);  // runin motion (action 10)
    void state_move(s32);
    void update_run_out(s32);  // runout motion (action 12): skids to a stop
    void update_crouch_in(s32);  // husein motion (action 13)
    void update_crouch(s32);  // huse motion (action 14)
    void update_crouch_out(s32);  // huseout motion (action 15)
    void update_horn_in(s32);  // tunoin motion (action 16), before update_ground_lightning_attack
    void update_ground_lightning_attack(s32);
    void update_horn_out(s32);  // tunout motion (action 18)
    void update_offscreen_climb(s32);
    void update_offscreen_dive(u32);  // kiri / kiriland motions (actions 20, 22): drops from offscreen onto a player
    void update_roar_state(s32);
    void update_howl_state(s32);  // houko motion (action 23)
    void update_mode_idle(s32);  // stand, fly or kaku loop for the current flight_mode
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
    Vec position_correction;  // apply_position_correction adds it to position once, then clears it
    s32 targetRefreshCounter;
    Boss5GryphonMotionEntry motions[2];
    Boss5GryphonMotionEntry *motion;
    u32 flags;  // 1 destroy, 2 remote action pending, 0x40 get_flag_bit6
    TObject sub_tasks;  // the Colli and Snarl tasks hang under it; run_task runs its tasks
    s32 run_mode;  // 0 runs the actions, 1 holds them while the lobby is not ready
    s32 flight_mode;  // 0 ground, 2 low flight, 3 offscreen (the enter_*_mode setters), 1 enter_flight_mode
    Vec body_points[10];  // update_local_colliders_from_world turns them into body offsets
    Vec sound_origin;  // projected from the camera each frame; sounds play from it
    Vec pad_56C;
    AreaAttackHistory *attack_history;
    TBoss5GryphonColli *collider;
    RenderFadeState renderFadeStates[4];
    const s32 *effect_ids;
    u8 rng[0xE8];
    // The state handlers reset the words they use on ENTER and read them their own way.
    union {
        Boss5GryphonStepWork work;            // the step machine most handlers run
        Boss5GryphonDiveWork dive;            // update_offscreen_dive
        Boss5GryphonTakeoffWork takeoff;      // update_ground_takeoff
        Boss5GryphonLightningWork lightning;  // update_ground_lightning_attack
    };
    u32 pad_720;
    TParticleCtrl *particles[3];  // spawned and moved by update_low_flight_particles in low flight
    s32 run_mode_changed;  // run_task sets it when run_mode drops back to 0
    TParticleCtrl *parts[16];  // update_ground_effects keeps one on the ground under each body point
    Boss5GryphonActionStep *script_entry;  // the action script step being run
    Boss5GryphonActionStep **action_scripts;  // boss5_gryphon_action_scripts
    void render_nodes_with_flag();
    void render_with_fade(s32 fade_index);
    void render_model();
    void copy_bone_positions();
    void draw_body();
    // draw_body's chunk-node callback: stores the view position of each boss5_gryphon_bone_capture_node_indices node.
    static void capture_bone_node(NJS_OBJECT *node);
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
    void set_target_from_action(G_GalGryphonBossActions_6x9F *packet);
    void apply_remote_action(G_GalGryphonBossActions_6xA0 *packet);  // starts the packet's motion entry where it says
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
    void set_random_param(Boss5GryphonMotionEntry *motion);  // the seed of the next lightning or dive
    void calc_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step);  // fills the circle view
    void calc_product_and_ratio(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step);  // fills the flight turn and speed
    void calc_attack_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step);  // fills the flight view
    void calc_move_params(Boss5GryphonMotionEntry *motion, Boss5GryphonActionStep *step);  // fills the move view
    s32 get_random_sign(Boss5GryphonActionStep *step, s32 i);
    s32 calc_product(Boss5GryphonActionStep *step, s32 sign_index, s32 range_index);
    s32 rand_scaled_offset(s32 base, s32 spread);
    s32 get_table_min(Boss5GryphonActionStep *step, s32 i);
    s32 random_in_table_range(Boss5GryphonActionStep *step, s32 i);
    f32 random_in_range(f32 min, f32 range);
    f32 random_float_in_table_range(Boss5GryphonActionStep *step, s32 i);
    s32 run_action_script_step(Boss5GryphonMotionEntry *out, Boss5GryphonActionStep *step);
    void init_packet_motion(G_GalGryphonBossActions_6xA0 *packet);
    void fill_action_steps(G_GalGryphonBossActions_6xA0 *packet);  // runs the action script into the packet's motion entry
    void copy_angle_state(Boss5GryphonMotionEntry *dst, Boss5GryphonActionStep *src);
    void update_target_from_state();
    void choose_next_action(Boss5GryphonActionStep *step);
    s32 get_player_pos_in_arc(s32 left, s32 client_id, Vec *org, Vec *out);
    void fire_horn_lightning(s32 left, s32 client_id);
    void play_animation_index(s32 index);
    void flush_pending_effect();
    void scale_size(f32 scale, f32 scale_y, f32 turn_scale);
    void copy_spawn_params(G_GalGryphonBossActions_6xA0 *packet);  // adds entity_id, position and rotation_y, then sends it
    void fill_follow_camera_params(Vec *target_offset, Vec *eye_offset);  // the follow camera offsets of the flight mode
    void set_animation_by_state();
    void init_state_zero();
    void enter_flight_mode();
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
    void emit_run_foot_attacks();  // the same on the run step frames
    void emit_walk_foot_attacks();  // emit_part_attack_effect per foot on the walk step frames
    void apply_position_correction();
    void spawn_flight_splash();  // spawn_ground_splash on fly frame 14
    void emit_ground_contact_attack();  // hit at bone_positions[14] while it is near the ground
    void emit_landing_impact();  // area hit at position when the body comes down
    void play_run_footsteps();  // run motion step frames
    void play_walk_footsteps();  // walk motion step frames
    void spawn_ancient_trap(s32 id);
    s32 blocks_camera_view();  // a foot is in the camera-to-player cone: render_with_fade fades
    void snap_to_ground_height();  // in ground mode
    s32 is_sphere_in_camera_cone(Vec *point, f32 radius);
    void update_low_flight_particles();
    s32 is_motion_finished();  // play_speed has run down to 0
    void emit_run_body_attack();  // hit between bone_positions[0] and [11] while running
    void emit_flight_body_attacks();  // hits at bone_positions[11] and [0] in low flight
    void emit_wing_attacks();  // hits along bone_positions[3..10] in low flight
    void send_target_update();  // sends entity_id, target_id and destination to the other clients
};

LAYOUT_ASSERT(TBoss5Gryphon_size, sizeof(TBoss5Gryphon) == 0x77C);
LAYOUT_ASSERT(TBoss5Gryphon_turn_velocity, offsetof(TBoss5Gryphon, turn_velocity) == 0x480);
LAYOUT_ASSERT(TBoss5Gryphon_sound_origin, offsetof(TBoss5Gryphon, sound_origin) == 0x560);
LAYOUT_ASSERT(TBoss5Gryphon_action_scripts, offsetof(TBoss5Gryphon, action_scripts) == 0x778);
LAYOUT_ASSERT(TBoss5Gryphon_fade, offsetof(TBoss5Gryphon, renderFadeStates) == 0x580);
LAYOUT_ASSERT(TBoss5Gryphon_work, offsetof(TBoss5Gryphon, work) == 0x6DC);
LAYOUT_ASSERT(TBoss5Gryphon_particles, offsetof(TBoss5Gryphon, particles) == 0x724);
#endif
