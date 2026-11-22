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
struct Blk_802B8624;

// The three bytes an attack choice fills (sub_802B909C / randomize_attack) and send_6xA4_action sends.
struct Atk_802B8EE0 {
    s8 b0;
    u8 b1;
    s8 b2;
};

struct Boss6Point {
    Vec v;
};

struct TBoss6Type1 : public TObjEnemy {
    TBoss6Type1(TObject *parent, saddr *params);
    virtual ~TBoss6Type1();
    void sub_802B626C();
    void set_action_state(s32);
    void sub_802B5CB4();
    void sub_802B4C28();
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
    u8 unk_41D[0x3];
    Boss6Point target_position;  // OlgaFlowActionMsg's decoded target
    Boss6Point m_42C;
    s32 attack_mode;   // OlgaFlowActionMsg::attack_mode
    s32 motion_set;    // row of TBoss6Type1__motion_set_table
    s32 motion_mode;   // that row's mode: 0 loops, 2 holds the last frame and goes on to the row's next set
    Boss6PartMotion part_motions[2];
    s32 beam_damage;   // base damage of update_beam_attack's hit, name inferred
    s32 sweep_damage; // base damage of the swept-arm hit test (TBoss6Type1__sub_802B715C), name inferred
    s32 m_484;
    s32 center_damage;  // base damage of damage_players_in_range, name inferred
    s32 m_48c;
    s32 pad_490;
    s32 m_494;
    s32 delta_threshold;  // is_field4b0_delta_reached compares calc_field4b0_delta() with it
    s32 m_49c;
    s32 laser_fire_time;
    s32 m_4a4;
    s32 pad_4a8;
    s32 low_hp_flag;  // set_flag_on_threshold sets it once hp_ratio drops below a third
    s32 latched_hp;  // latch_phase_counter stores hp; calc_field4b0_delta returns the damage since
    f32 damage_step_scale;  // check_field4b0_threshold: damage since the latch vs this * m_494, then * 1.5
    // set_action_state counts these actions (boss6_type1_action_table's names).
    s32 chal_ud_count;       // CHAL_UD
    s32 center_trip_count;   // GOTO_CENTOP and GOTO_CENBTM
    s32 centop_count;        // GOTO_CENTOP
    s32 cenbtm_count;        // GOTO_CENBTM
    Vec prev_effect_point; // effect_points[1] of the previous frame, name inferred
    f32 hit_flash;  // run_hit_reaction sets 1, run_task fades it out over 15 updates
    f32 hp_ratio;   // hp / referenceHp, run_task
    f32 m_4dc;
    s32 timer_limit;    // is_timer_expired: 0 or less never runs
    s32 timer_elapsed;  // counts up to timer_limit
    f32 sway_offset;    // update_sway eases it toward its target
    s32 sway_phase;
    s32 sway_speed;
    s32 sway_delay;
    TParticleCtrl *effect_slots[4];  // TBoss6Type1__effect_slot_table's emitters
    s32 m_508;
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
    void release_effect_slot(s32 arg1);
    void spawn_effect_slot(s32 arg1);
    void rotate_around_center(s32 num, s32 den);
    void interpolate_pos_to_target(s32 step, s32 total);
    void ease_toward_target(s32 a, s32 b);
    s32 count_matches(s32 arg1, s32 arg2);
    static s32 pick_random_entry(s32 arg0, saddr arg1, s32 arg2);
    static int rand_range_inclusive(s32 arg0, int arg1, int arg2);
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
    static void set_part_default_value(int a0, void* a1);
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
    void set_motion_set(s32 arg1);
    void advance_animations();
    static Blk_802B8624 *copy_block(Blk_802B8624 *d, const Blk_802B8624 *s);
    void render_shadows();
    void do_attack();
    void send_6xA4_action(s32 t, const Atk_802B8EE0 *src);
    void load_params(const OlgaFlowActionMsg *message);
    void set_sync_data(OlgaFlowActionMsg *message);
    static s32 create(saddr arg0);
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
    void sub_802B245C();
    void sub_802B24B4();
    void sub_802B2724();
    void sub_802B2A94();
    void sub_802B2CB4();
    void sub_802B2D68();
    void sub_802B2F00();
    void sub_802B3178();
    void sub_802B31E4();
    void sub_802B3320();
    void sub_802B343C();
    void sub_802B3564();
    void sub_802B381C();
    void sub_802B3B94();
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
    void sub_802B909C(Atk_802B8EE0 *atk);
    void randomize_attack(Atk_802B8EE0 *atk);
    void sub_802B8E1C();
    void sub_802B8BB4();
    void sub_802B8A70();
    void sub_802B854C();
    // Starts the sway over: zero offset and phase, the minimum speed and delay.
    void reset_sway();
    void sub_802B73AC();
    // Swept-arm hit test of the motion-14 sweep (frames 10.5-15): damages players inside the arm's triangle.
    void sub_802B715C();
    void sub_802B6C30();
    // Fires five kakusan shots from body nodes across the boss's front (inferred).
    void sub_802B6944();
    // Spreads the mines on rings around node 0 in a shuffled order (inferred: the mine attack).
    void sub_802B6504();
    s32 sub_802B6060() const;
    s32 sub_802B600C();
    s32 sub_802B5FF4();
    s32 sub_802B5FDC();
    // Counts timer_elapsed up while a timer_limit is set (is_timer_expired reads it).
    void tick_timer();
    void fire_at_all_players(f32 dy);
    void sub_802B5AB0();
    void sub_802B59CC();
    void sub_802B59A8();
    void sub_802B5970();
    void calc_grid_cell_position(Vec *out);
    void sub_802B5598(Vec *out);
    void clamp_to_arena_radius(Vec *out);
    void sub_802B5140(s32 arg1, s32 arg2);
    void clear_effect_slots();
    // release_effect_slot for all four effect_slots.
    void release_effect_slots();
    void sub_802B4B14();
    void sub_802B4B04();
    // Zeroes m_508 and releases every slot_particles emitter.
    void release_slot_particles();
    void clear_map_csn();
    void sub_802B4A70();
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


// Defined in TBoss6Type1.cpp's .rodata; init_effect_slot_1 reads it too.
extern const Vec lbl_80470CE0;

LAYOUT_ASSERT(Boss6EffectPoint_size, (sizeof(Boss6EffectPoint)==0xC));
LAYOUT_ASSERT(TBoss6Type1_receiver_offset, (offsetof(TBoss6Type1,effect_point_receiver)==0x404));
LAYOUT_ASSERT(TBoss6Type1_points_offset, (offsetof(TBoss6Type1,arm_node_positions) + 5 * sizeof(Vec) == 0x638));
LAYOUT_ASSERT(TBoss6Type1_trail_receiver_offset, (offsetof(TBoss6Type1,trail_point_receiver)==0x400));
LAYOUT_ASSERT(TBoss6Type1_map_csn_offset, (offsetof(TBoss6Type1,map_csn)==0x680));
LAYOUT_ASSERT(TBoss6Type1_target_position_offset, offsetof(TBoss6Type1, target_position) == 0x420);
LAYOUT_ASSERT(TBoss6Type1_node_points_offset, offsetof(TBoss6Type1, node_points) == 0x578);
LAYOUT_ASSERT(TBoss6Type1_arm_node_positions_offset, offsetof(TBoss6Type1, arm_node_positions) == 0x5FC);
#endif
