#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/render/RenderFadeState.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/boss/derolle/AccelerationCurve.h"

class AreaAttackHistory;
struct TBoss8DragonEffTail;
class TParticleCtrl;
struct ControllerInputContext;

// The gold dragon (Episode 2's Gol Dragon) boss.
class TBoss8Dragon : public TObjEneDD_ST
{
public:
    TBoss8Dragon(TObject *parent, void *set_data);
    virtual ~TBoss8Dragon();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    // Slot 23: kinds 0xB and 0xC do it no damage; the rest go to TObjChara's.
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload payload, void *arg2, s32 arg3, s32 flags);
    virtual void refresh_target();
    // Slots 44-50: the status ailments TObjChara applies; the dragon ignores them.
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    // Slot 87: runs the current action's handler (one per action, handlers[] in the body).
    virtual void dispatch_action(u32 action, s32 event);
    // Slot 88: moves the seven collider bodies to the model's node positions.
    virtual void update_body_colliders();
    // Slots 105 and 106, the two the dragon adds to TObjEneDD_ST's table.
    virtual int run_demo_task();
    virtual void draw_motion_model();

    void get_render_position(Vec *pos);
    s32 hasActiveRenderFade();
    s32 sub_802F46F4();
    // As TBoss1Dragon::is_sphere_visible: the sphere lies in the cone from the camera towards its target.
    s32 is_sphere_visible(Vec *center, f32 radius);
    // One of four model nodes stands between the camera and its target (name inferred: draw_with_fade fades
    // the dragon out while it does).
    s32 is_hiding_camera_target();
    void update_damage_threshold();
    void sub_802FBEA4();
    void sub_802FBE3C();
    void sub_802FBA1C();
    void sub_802FB484();
    void sub_802F48DC(Vec *target);
    void sub_802FB09C();
    void sub_802FB778();
    void sub_802FB70C();
    void copySavedX(s32 *x);
    void calc_target_vector();
    void init_air_turn(s32 targetAngle);
    s32 advance_air_turn();
    s32 choose_burrow_ring_destination(f32 *out);
    s32 select_air_fire_target(Vec *out);  // as TBoss1Dragon::select_air_fire_target
    s32 sub_802FABB4();
    s32 is_secondary_sequence();

    u32 flags;  // as TBoss1Dragon::flags: 0x40 makes run_task remove the dragon, 0x100 tested the same way
    TObject sub_tasks;  // the dragon's collider task hangs under it; run_task runs its tasks
    s32 m_3e0;
    s32 phase;
    s32 m_3e8;
    Vec breath_node_points[3];  // as TBoss1Dragon::breath_node_points
    Vec breath_origin;  // the TBoss8DragonEffBreath and the fire bullets start here
    Vec breath_direction;  // breath_node_points[1] - [0], the breath's direction
    Vec breath_effect_position;
    Vec node_positions[0x22];  // the model's node positions; update_body_colliders reads seven
    f32 m_5cc;
    f32 m_5d0;
    f32 m_5d4;
    f32 m_5d8;
    f32 m_5dc;
    Vec m_5e0;
    AccelerationCurve curve0;  // fed to init_acceleration_curve / sample_acceleration_curve
    AccelerationCurve curve1;
    Vec sound_origin;  // project_sound_origin_from_camera's result; the dragon's sounds play from it
    Vec last_body_center;  // body_center, copied at the end of each run_task
    u32 camera_target_raised;  // as TBoss1Dragon::camera_target_raised
    s32 airTurnVelocity;
    s32 airTurnDirection;
    s32 airTurnStartAngle;
    f32 airTurnAcceleration;
    f32 airTurnFinalAcceleration;
    f32 airTurnInitialVelocity;
    f32 airTurnFinalVelocity;
    f32 airTurnMidpointAngle;
    f32 airTurnTime;
    s32 sequenceCursor;  // as TBoss1Dragon: sent in the 6xA8 packet, below 50 = first sequence
    s16 hpThreshold;
    s16 finalHpThreshold;  // hp is clamped to it, as in TBoss1Dragon
    TBoss8DragonEffTail *tail;  // the TBoss8DragonEffTail the constructor creates
    AreaAttackHistory *attack_history;
    TObject *collider;  // the TBoss8DragonColli the constructor hangs under sub_tasks
    f32 destinationX;
    f32 destinationZ;
    f32 savedX;
    f32 savedZ;
    s32 sector_count;  // how many of sector_radii choose_burrow_ring_destination has filled

    u32 m_69c;
    f32 sector_radii[12];  // one random radius per 30-degree sector, picked by choose_burrow_ring_destination
    u32 m_6d0;
    s32 m_6d4;
    ControllerInputContext *controller_input;  // points into controller_input_state.controllers
    RenderFadeState renderFadeStates[4];
    s32 m_74c;
    u16 m_750;
    u8 _pad752[0x2];
    s32 m_754;
    u32 m_758;
    s32 m_75c;
    const s32 *particle_ids;  // TBoss1Dragon reads the same ids through effectResource->particle_ids
    void* m_764;
    u8 unk_768[0xC];
    saddr m_774;
    u8 unk_778[0xD4];
    s32 stateStep;  // step and frame counter of the current action, as in TBoss1Dragon
    s32 impactAge;
    s32 action_frames;
    u32 m_858;
    s32 action_angle;
    s32 m_860;
    f32 fallVelocity;
    f32 rootHeight;
    f32 m_86c;
    f32 m_870;
    f32 m_874;
    Vec action_point;  // the current action's point or step, as TBoss1Dragon::action_point
    f32 m_884;
    f32 m_888;
    f32 m_88c;
    s32 m_890;
    TParticleCtrl *breath_particles[3];  // as TBoss1Dragon::breath_particles
    s32 m_8a0;
    static void sync_target_pos(void *p);
    static s32 restore_target_pos(void *p);
    static s32 copy_pos_to_field688(void *p);
    void spawn_switch_attack();
    void spawn_attack_effect();
    void copy_action_state(u8 *arg1);
    static void set_default_on_state0();
    static void capture_node_points(NJS_OBJECT *);
    void calc_velocity_from_angle();
    f32 clamp_step_in_radius(f32 a, f32 b, f32 s);
    void freeze_player_at_self();
    static u16 find_player_on_floor(void *arg0);
    void spawn_ground_effect();
    int setup_instance(int _w1, void * _w2, AreaAttackHistory *history);
    void setup_breath_instance(Vec *pos, u32 kind, AreaAttackHistory *history);
    void emit_effect(void *pos, void *params, AreaAttackHistory *history);
    void get_state_flags(void *params);
    static void init_state(saddr dragon);
    static int set_state_1(void* p);
    static int check_condition_default(void* p);
    void spawn_effect();
    void play_effect_sound(s32 sound_id);
    void spawn_trap(s32 id);
    void spawn_effect_if_in_band();
    s32 mask_flags(s32 input_flags, s32 mask);
    s32 check_attack_ready();
    s32 select_target_in_front();
    s32 update_linked_position();
    void update_movement();
    void apply_6xA8_action(u8 *packet);
    f32 calc_step_value();
    s32 check_damage_reaction();
    void pick_next_action();
    void set_speed(s32 arg1);
    void save_position();
    void send_6xA8_action();
    void send_action_packet(int action);
    void apply_ground_movement(Vec *step);
    void draw_beam_segments(f32 a, f32 b, f32 c);
    void copy_pos_to_field688();
    void restore_target_pos();
    void sync_target_pos();
    void release_grabbed_player();
    s32 is_health_low();
    void reset_tail_hp();
    void reload_boss_stats();
    void check_hit_result(s32 arg1, s32 arg2);
    void reset_action();
    void activate_attack();
    void set_active_flag();
    void set_action_state();
    void set_state();
    void reset_timer();
    void play_sound_if_in_band();
    void try_spawn_trap();
    void set_damage_phase_value(s32 arg1);
    static void init_default(void *boss8_dragon);
    s32 is_near_target();
    void calc_orbit_xz(f32 *arg1, f32 *arg2);
    void store_position();
    void set_state_22();
    void check_death();
    void select_next_action();
    static void free_static();
    // Listed with free_static in TLobby's floor resource callbacks.
    static void load_resources();
    // Hands the dragon back from the debug player control (boss8_dragon_player_control).
    static void clear_player_control();
    static void *clone_node_tree(void *src, void *dst, int state);
    static void *create(void *set_data);
    void update_colli_parts();
    void init_color();
    void send_spawn_params_packet();
    void byteswap_action_packet();
    void byteswap_record();
    void send_boss_actions();
    void bswap_boss_actions();
    s32 is_within_xz_distance(u8 *arg1, f32 off);
    f32 calc_sq_offset(f32 farg0);
    void noop();
    static u16 get_global_part_count(s32 arg0);
    static void place_parts_in_ring(s32 n, s32 arg1, s32 arg2);
    static s32 find_target_enemy();
    static s32 is_any_part_alive();
    static void update_all_parts();
    static s32 has_enough_enemies();
    void set_mode_params(s8 arg1);
    void update_pos_from_data();
    void render_nodes_flagged();
    void copy_vectors();
    void send_swapped_packet();
    void bswap_packet();
    static void trigger_switches_in_range(void *arg0, void *arg1, void *arg2);
    static s32 calc_binomial_coefficient(s32 n, s32 k);
    static s32 eval_bezier_curve(void *points, int count, int closed, void *out, f32 t);
    static void get_camera_offsets(Vec *eye, Vec *target);
    void render_body_model();
    void select_freeze_target();
    void emit_body_effects();
    void get_follow_camera_offsets(u8 *arg1);
    s32 is_closest_part();
    s32 push_apart_from_parts();
    s32 is_near_other_part();
    void draw_with_fade(Vec *pos, s32 view);
    void draw();

    // Per-action event handlers, run by dispatch_action (vtable slot 87).
    void sub_802F4B90(s32 event);
    void action(s32 event);
    void sub_802F4DD4(s32 event);
    void update_wander_state(s32 event);
    void sub_802F51DC(s32 event);
    void sub_802F5434(s32 event);
    void sub_802F5644(s32 event);
    void sub_802F57E4(s32 event);
    void handle_walk_state(s32 event);
    void sub_802F5BA0(s32 event);
    void sub_802F5CC8(s32 event);
    void sub_802F5F64(s32 event);
    void sub_802F610C(s32 event);
    void sub_802F645C(s32 event);
    void sub_802F6618(s32 event);
    void update_fade_state(s32 event);
    void update_death_state(s32 event);
    void handle_leap_state(s32 event);
    void handle_spiral_state(s32 event);
    void update_burrow_outward_run(s32 event);
    void action_17(s32 event);
    void sub_802F7B4C(s32 event);
    void update_burrow_inward_run(u32 event, s32 action);
    void update_dive_state(s32 event);
    void state_roar(s32 event);
    void update_stretch_state(s32 event);
    void update_head_down_attack_state(s32 event);
    void update_fall_state(s32 event);
    void sub_802F87EC(s32 event);
    void sub_802F89F8(s32 event);
    void update_air_fire_state(s32 event);
    void state_turn_and_charge(s32 event);
    void update_lift_state(s32 event);
    void sub_802F9A4C(s32 event);
    void handle_tail_attack_state(s32 event);
    void state_breath_attack(s32 event);
    void update_walking_state(s32 event);
    void sub_802FA374(s32 event);
    void sub_802FA478(s32 event);
};

#include <stddef.h>
LAYOUT_ASSERT(TBoss8DragonFadeStride, sizeof(RenderFadeState) == 0x1C);
LAYOUT_ASSERT(TBoss8DragonFadeOffset, offsetof(TBoss8Dragon, renderFadeStates) == 0x6DC);
LAYOUT_ASSERT(TBoss8DragonSize, sizeof(TBoss8Dragon) == 0x8A4);
LAYOUT_ASSERT(TBoss8DragonSubTasksOffset, offsetof(TBoss8Dragon, sub_tasks) == 0x3C4);
LAYOUT_ASSERT(TBoss8DragonAfterFadeOffset, offsetof(TBoss8Dragon, m_74c) == 0x74C);

// The camera's xz position and its normalized xz direction to the camera target, which the visibility test
// TBoss8Dragon::is_hiding_camera_target sets before it tests the model's points.
extern Vec boss8_dragon_reference_pos_vec;
extern Vec dragon_forward_reference_vec;
// What TBoss8Dragon::capture_node_points turns into view space: the origin of each listed node, and
// three points on the breath node (into breath_node_points).
extern Vec boss8_dragon_node_origin;
extern Vec boss8_dragon_breath_local_points[3];

// A tuning record of TLobby::dispatch_shared_handler_a (ids 0x11-0x13 for the Gol Dragon): six floats,
// then six words, each read per id.
struct Boss8DragonParams {
    f32 values[6];
    s32 ints[6];
};
// Nonzero while a debug controller steers the dragon (TBoss8Dragon::select_freeze_target).
extern s32 boss8_dragon_player_control;

#endif
