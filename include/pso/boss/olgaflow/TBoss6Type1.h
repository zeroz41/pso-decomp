#include "pso/system/BmlResource.h"
#include "pso/boss/Boss6ScrollStrips.h"
#ifndef PSO_BOSS_OLGAFLOW_TBOSS6TYPE1_H
#define PSO_BOSS_OLGAFLOW_TBOSS6TYPE1_H
#include "pso/boss/olgaflow/TBoss6Zanzo.h"
#include "types.h"
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"

struct OlgaFlowActionMsg;

class ModelNodePositionCapture;
class TBoss6PlotFalz;
struct AnimationMotion;
class TParticleCtrl;
typedef Vec Boss6EffectPoint;
// One of the two part-motion players at 0x444 (render blends prev_motion/prev_frame into
// motion/frame by blend; the TBoss6Type2MotionTrack twin).
struct Boss6PartMotion {
    AnimationMotion *motion;
    f32 frame;
    f32 speed;  // frames per update
    f32 blend;
    f32 blend_step;
    AnimationMotion *prev_motion;
    f32 prev_frame;
    void copy_from(Boss6PartMotion *src);
};
struct TBoss6GravBall;
struct Boss6Type1MotionState {
    s32 motion_set;
    s32 motion_mode;
    Boss6PartMotion part_motions[2];
};

LAYOUT_ASSERT(Boss6Type1MotionStateSize, sizeof(Boss6Type1MotionState) == 0x40);

// The three bytes an attack choice fills (init_attack_params / randomize_attack) and send_6xA4_action
// sends as the action's Boss6PolarBytes: heading byte, radius and height in units of ten.
struct Boss6Type1AttackTarget {
    s8 angle;
    u8 radius;
    s8 height;
};

struct Boss6Point {
    Vec v;
};

struct Boss6BodySpawnParams;

struct TBoss6Type1 : public TObjEnemy {
    TBoss6Type1(TObject *parent, Boss6BodySpawnParams *params);
    virtual ~TBoss6Type1();
    void render_laser();
    void set_action_state(s32);
    void update_action_camera();
    // Moves the effect_slots emitters to their node (TBoss6Type1__effect_slot_table).
    void update_effect_slots();
    virtual void run_hit_reaction();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    virtual void run_death_reaction();
    void run_task();
    void update_effect_points();
    void update_trail_points();
    u32 action_state;  // row of boss6_type1_action_table (set_action_state)
    s32 action_history[32];  // set_action_state shifts the last 32 states in
    TBoss6PlotFalz *plot_falz;  // the spawn parameters' first word
    BmlResource *bml_resource; // BML archive handle passed to get_bml_motion / get_bml_model, name inferred
    TBoss6Zanzo *trail_point_receiver;
    TBoss6Zanzo *effect_point_receiver;
    u32 frame_counter;  // run_task adds one every update
    s32 action_duration;  // what action_timer runs to (interpolate_pos_to_target's total)
    s32 action_timer;
    s32 target_mode;   // OlgaFlowActionMsg::target_mode
    s32 active_parts;  // the action row's param: 1 turns the first two bodies on, 2 the other five
    s8 random_factor;  // OlgaFlowActionMsg::random_factor
    u8 pad_41D[0x3];
    Boss6Point target_position;  // OlgaFlowActionMsg's decoded target
    Boss6Point pad_42C;  // set to boss6_type1_origin by the constructor
    s32 attack_mode;   // OlgaFlowActionMsg::attack_mode
    Boss6Type1MotionState motion_state;
    s32 beam_damage;   // base damage of update_beam_attack's hit, name inferred
    s32 sweep_damage; // base damage of the swept-arm hit test (TBoss6Type1__sub_802B715C), name inferred
    s32 laser_damage;  // base damage of check_laser_hits (FLLSR_MV), name inferred
    s32 center_damage;  // base damage of damage_players_in_range, name inferred
    s32 scream_threshold;   // is_ready: damage since the latch that sends SCREAM (target_mode 0)
    s32 chal_ud_threshold;  // is_time_up: damage since the latch that sends CHAL_UD (send_chal_ud)
    s32 damage_step;        // check_field4b0_threshold's step (times damage_step_scale)
    s32 delta_threshold;  // is_field4b0_delta_reached compares calc_field4b0_delta() with it
    s32 laser_charge_time;  // FLLSR_MV: frames before the laser fires (act_fllsr_mv adds it to the duration)
    s32 laser_fire_time;
    s32 float_time;  // RND_FLOAT duration (init_attack_timers)
    s32 low_hp_float_time;  // RND_FLOAT duration once low_hp_flag is set
    s32 low_hp_flag;  // set_flag_on_threshold sets it once hp_ratio drops below a third
    s32 latched_hp;  // latch_phase_counter stores hp; calc_field4b0_delta returns the damage since
    f32 damage_step_scale;  // check_field4b0_threshold: damage since the latch vs this * damage_step, then * 1.5
    // set_action_state counts these actions (boss6_type1_action_table's names).
    s32 chal_ud_count;       // CHAL_UD
    s32 center_trip_count;   // GOTO_CENTOP and GOTO_CENBTM
    s32 centop_count;        // GOTO_CENTOP
    s32 cenbtm_count;        // GOTO_CENBTM
    Vec prev_effect_point; // effect_points[1] of the previous frame, name inferred
    f32 hit_flash;  // run_hit_reaction sets 1, run_task fades it out over 15 updates
    f32 hp_ratio;   // hp / referenceHp, run_task
    f32 laser_scale;  // grows to 1 while the FLLSR_MV laser fires; scales the beam drawn at node_points[7]
    s32 timer_limit;    // is_timer_expired: 0 or less never runs
    s32 timer_elapsed;  // counts up to timer_limit
    f32 sway_offset;    // update_sway eases it toward its target
    s32 sway_phase;
    s32 sway_speed;
    s32 sway_delay;
    TParticleCtrl *effect_slots[4];  // TBoss6Type1__effect_slot_table's emitters
    s32 laser_frames;  // count_laser_frame adds one per update while the laser is drawn, name inferred
    TParticleCtrl *slot_particles[24];
    Vec last_beam_point;  // update_beam_attack measures from it every other update, name inferred
    // The capture lists end after 11 body positions and 7 arm positions.
    Vec node_points[11];
    Vec arm_node_positions[7];
    // Installed while the corresponding model draws.
    ModelNodePositionCapture *draw_callback_lists[2];
    Boss6ScrollStrips scroll_strips_u; // scroll_strips_uv(8, 0) every frame
    Boss6ScrollStrips scroll_strips_v; // scroll_strips_uv(0, 0x22) every frame
    TObject *map_csn;
    static u8 *create_kakusan(TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 speed);
    void clear_slot_array();
    void release_effect_slot(s32 slot);
    void spawn_effect_slot(s32 slot);
    void rotate_around_center(s32 num, s32 den);
    void interpolate_pos_to_target(s32 step, s32 total);
    void ease_toward_target(s32 a, s32 b);
    s32 count_matches(s32 action, s32 depth);
    s32 pick_random_entry(const s32 *table, s32 count);
    int rand_range_inclusive(int lo, int hi);
    s32 pick_remapped_list_value(s32 a, s32 b, s32 n);
    void request_jittered_camera(const Vec *eye, const Vec *target, u16 client_id);
    void request_default_jittered_camera();
    s32 is_timer_expired();
    void reset_fields_4e0();
    s32 is_field3F8_over_0x20();
    int is_field4b0_delta_reached();
    s32 is_ready();
    s32 check_field4b0_threshold();
    int is_time_up();
    void set_flag_on_threshold();
    void set_part_default_value(Vec *point);
    void init_parts();
    void reset_param();
    void decrease_field_clamped_min();
    void increase_field_clamped_max();
    void enable_parts();
    void set_child_flags();
    void clear_part_flag_bit0();
    void update_parts_flags();
    void update_part_positions();
    void update_position();
    void update_sway();
    void update_turn_to_center();
    s32 calc_field4b0_delta();
    void latch_phase_counter();
    void load_params_from_table();
    void draw_part_motions();
    void set_motion_set(s32 set);
    void advance_animations();
    static Boss6Type1MotionState *copy_block(Boss6Type1MotionState *d, const Boss6Type1MotionState *s);
    void render_shadows();
    void do_attack();
    void send_6xA4_action(s32 t, const Boss6Type1AttackTarget *src);
    void load_params(const OlgaFlowActionMsg *message);
    void set_sync_data(OlgaFlowActionMsg *message);
    static TBoss6Type1 *create(Boss6BodySpawnParams *params);
    void enter_flag800_state();
    void update_attack_countdown();
    void update_countdown_state();
    void update_if_ready();
    void set_phase_555();
    void update_countdown();
    void update_state();
    void update_attack_timer();
    void tick_attack_sequence();
    void update_if_idle();
    void enter_release_state();
    void tick_state_410_timer();
    void init_move_attack();
    void update_attack_state();
    void advance_plot_to_state2();
    void init_params();
    void update_phase();
    void trigger_falz_phase();
    void tick_flee_countdown();
    void update_timer_transition();
    void init_hp_and_state();
    void update_charge();
    void start_action_if_idle();
    void set_phase_90();
    void update_timer();
    void update_attack_timer2();
    void init_dice_state();
    void init_action_timer();
    void init_attack_timer();
    void update_timer_state();
    void set_phase_timer_3E();
    void update_action_timer();
    void init_hp_state();
    void init_state_90();
    void update_attack_countdown_reset();
    void start_attack();
    void tick_countdown();
    void choose_next_action();
    void init_attack_timers();
    void init_effect_slot_1();
    void update_cenbtm_d();
    void act_cenbtm_d();
    void update_tkof_centop();
    void update_down_centop();
    void act_centop_u();
    void act_centop_d();
    void idle_chal_float();
    void act_scream();
    void update_fllsr_mv();
    void act_fllsr_mv();
    void update_sword_ud();
    void update_sword_mv();
    void update_kakusan();
    void update_appear();
    void draw_model();
    void render();
    void release_map_csn();
    void spawn_map_csn();
    static TBoss6GravBall *create_grav_ball(TBoss6Type1 *owner, const Vec *position);
    s32 get_gravity_attack_state();
    void spawn_grav_ball();
    void damage_players_in_range();
    void update_beam_attack();
    void init_charge_attack();
    void reset_effects();
    void init_charge();
    void update_hit_timer();
    void init_state();
    void tick_trap_countdown();
    void init_work();
    // Fills a heading near rotation_y, radius 180 or 280 and height 100 (inferred name).
    void init_attack_params(Boss6Type1AttackTarget *atk);
    void randomize_attack(Boss6Type1AttackTarget *atk);
    // Sends RET_RND_UD, or RET_RND_DU below y -20.
    void send_ret_rnd();
    // RND_FLOAT's next attack: SWORD/SWORD2/KAKUSAN (target_mode 0) or TAILATK_MV and the random actions.
    void choose_attack();
    // Sends CHAL_UD, height weighted by the GOTO_CENTOP/GOTO_CENBTM counts.
    void send_chal_ud();
    void init_motions();
    // Starts the sway over: zero offset and phase, the minimum speed and delay.
    void reset_sway();
    // SWORD_U/SWORD_D: spawns a TBoss6SwordShot where the blade (node_points[8]-[9]) crosses y 0.
    void spawn_sword_shots();
    // Swept-arm hit test of the motion-14 sweep (frames 10.5-15): damages players inside the arm's triangle.
    void check_sweep_hits();
    // FLLSR_MV: damages players inside the laser's area while it fires (inferred name).
    void check_laser_hits();
    // Fires five kakusan shots from body nodes across the boss's front (inferred).
    void fire_kakusan_shots();
    // Spreads the mines on rings around node 0 in a shuffled order (inferred: the mine attack).
    void spawn_mines();
    s32 is_raised() const;  // position.y > 100
    s32 is_near_center();   // XZ distance from the centre < 230
    s32 is_high();          // position.y > 140
    s32 is_low();           // position.y < 40
    // Counts timer_elapsed up while a timer_limit is set (is_timer_expired reads it).
    void tick_timer();
    void fire_at_all_players(f32 dy);
    void request_float_camera();
    void request_laser_camera();
    void request_tail_attack_camera();
    void request_top_jittered_camera();
    void calc_grid_cell_position(Vec *out);
    // SWORD_MV's target: radius 180 or 280 at y 100, turned 0x2000-0x6800 from rotation_y.
    void pick_sword_move_target(Vec *out);
    void clamp_to_arena_radius(Vec *out);
    // APPEAR: eases position from the spawn to the base position over the last total updates.
    void update_appear_position(s32 step, s32 total);
    void clear_effect_slots();
    // release_effect_slot for all four effect_slots.
    void release_effect_slots();
    // Called by the destructor: release_slot_particles (destroy_slot_particles is an inferred name).
    void destroy_slot_particles();
    void count_laser_frame();
    // Zeroes laser_frames and releases every slot_particles emitter.
    void release_slot_particles();
    void clear_map_csn();
    // Called by the destructor: release_map_csn (destroy_map_csn is an inferred name).
    void destroy_map_csn();
};
// A row of TBoss6Type1__motion_set_table: how the main part motion ends and the two motions.
struct Boss6Type1MotionSet {
    s32 mode;      // TBoss6Type1::motion_mode
    s32 next_set;  // the set mode 2 goes on to
    s32 ids[2];    // BML motion indices of the two part motions
};

// A row of boss6_type1_action_table: set_action_state runs act, run_task update every
// update and idle while the Plot Falz is idle.
struct TBoss6Type1Action {
    const char *name;
    s32 anim;   // the motion set (set_motion_set)
    s32 param;  // TBoss6Type1::active_parts
    void (TBoss6Type1::*act)();
    void (TBoss6Type1::*idle)();
    void (TBoss6Type1::*update)();
};
extern TBoss6Type1Action boss6_type1_action_table[41];

// Scene archive ids of the two Olga Flow body part models.
extern s32 boss6_type1_part_model_ids[];


// Defined in TBoss6Type1.cpp's .rodata; init_effect_slot_1 reads it too.
extern const Vec boss6_type1_base_position;

LAYOUT_ASSERT(Boss6EffectPoint_size, (sizeof(Boss6EffectPoint)==0xC));
LAYOUT_ASSERT(TBoss6Type1_receiver_offset, (offsetof(TBoss6Type1,effect_point_receiver)==0x404));
LAYOUT_ASSERT(TBoss6Type1_points_offset, (offsetof(TBoss6Type1,arm_node_positions) + 5 * sizeof(Vec) == 0x638));
LAYOUT_ASSERT(TBoss6Type1_trail_receiver_offset, (offsetof(TBoss6Type1,trail_point_receiver)==0x400));
LAYOUT_ASSERT(TBoss6Type1_map_csn_offset, (offsetof(TBoss6Type1,map_csn)==0x680));
LAYOUT_ASSERT(TBoss6Type1_target_position_offset, offsetof(TBoss6Type1, target_position) == 0x420);
LAYOUT_ASSERT(TBoss6Type1_node_points_offset, offsetof(TBoss6Type1, node_points) == 0x578);
LAYOUT_ASSERT(TBoss6Type1_arm_node_positions_offset, offsetof(TBoss6Type1, arm_node_positions) == 0x5FC);
#endif
