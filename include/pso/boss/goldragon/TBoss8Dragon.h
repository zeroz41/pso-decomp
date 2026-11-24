#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/render/RenderFadeState.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/boss/derolle/AccelerationCurve.h"

struct CurvePathPoint;
class AreaAttackHistory;
struct DragonAttackParams;
struct TBoss8DragonEffTail;
class TParticleCtrl;
struct ControllerInputContext;
struct G_GolDragonBossActions_6xA8;
class TBoss8DragonColli;

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
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload payload, void *collision, s32 tech, s32 flags);
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
    s32 is_any_fade_visible();  // one of renderFadeStates still has visible opacity
    // As TBoss1Dragon::is_sphere_visible: the sphere lies in the cone from the camera towards its target.
    s32 is_sphere_visible(Vec *center, f32 radius);
    // One of four model nodes stands between the camera and its target (name inferred: draw_with_fade fades
    // the dragon out while it does).
    s32 is_hiding_camera_target();
    void update_damage_threshold();
    void reload_stats_for_phase();
    void reload_impact_stats();
    void remap_sequence_after_recovery();
    void sweep_head_fall_spheres_late();
    // Walks to target's xz on the ground (wall checked), keeping its height; undone near another part.
    void move_to_on_ground(Vec *target);
    void update_flap_effect();
    void apply_landing_attack();
    void apply_head_fall_attack();
    void copySavedX(s32 *x);
    void calc_target_vector();
    void init_air_turn(s32 targetAngle);
    s32 advance_air_turn();
    s32 choose_burrow_ring_destination(f32 *out);
    s32 select_air_fire_target(Vec *out);  // as TBoss1Dragon::select_air_fire_target
    s32 check_attack_ready();  // as TBoss1Dragon::check_attack_ready: controlled 150 frames and button 0x400 pressed
    // As TBoss1Dragon::apply_trail_attack, which the fall, flight and burrow runs call right after moving; empty here.
    void apply_trail_attack();
    s32 check_phase_advance();  // as TBoss1Dragon::check_phase_advance; the Gol Dragon's always returns 0
    s32 is_secondary_sequence();
    // As TBoss1Dragon::prepare_flight_destination: away from the arena centre when the health is low, else to it.
    void prepare_flight_destination(Vec *dest);

    u32 flags;  // as TBoss1Dragon::flags: 0x40 makes run_task remove the dragon, 0x100 tested the same way
    TObject sub_tasks;  // the dragon's collider task hangs under it; run_task runs its tasks
    s32 lobby_state;  // as TBoss1Dragon::lobby_state: 0 runs the action sequence, 1 only animates, 2 re-sends reason 2
    s32 phase;
    s32 effect_mode;  // set_mode_params: 0-2 picks attack_kind and particle_ids (TBoss1Dragon picks them by isV2Mode)
    Vec breath_node_points[3];  // as TBoss1Dragon::breath_node_points
    Vec breath_origin;  // the TBoss8DragonEffBreath and the fire bullets start here
    Vec breath_direction;  // breath_node_points[1] - [0], the breath's direction
    Vec breath_effect_position;
    Vec node_positions[0x22];  // the model's node positions; update_body_colliders reads seven
    Vec target_vector;  // as TBoss1Dragon::target_vector: calc_target_vector's normalized xz direction
    f32 target_distance;  // its length before normalizing
    f32 m_5dc;
    Vec last_flight_direction;  // as TBoss1Dragon::last_flight_direction: destination_direction when the flight state is left
    AccelerationCurve curve0;  // fed to init_acceleration_curve / sample_acceleration_curve
    AccelerationCurve curve1;
    Vec sound_origin;  // project_sound_origin_from_camera's result; the dragon's sounds play from it
    Vec last_body_center;  // body_center, copied at the end of each run_task
    u32 camera_eye_raised;  // as TBoss1Dragon::camera_eye_raised
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
    TBoss8DragonColli *collider;  // the constructor hangs it under sub_tasks
    f32 destinationX;
    f32 destinationZ;
    f32 savedX;
    f32 savedZ;
    s32 sector_count;  // how many of sector_radii choose_burrow_ring_destination has filled

    u32 crater_count;  // as TBoss1Dragon::crater_count; the Gol Dragon only clears it
    f32 sector_radii[12];  // one random radius per 30-degree sector, picked by choose_burrow_ring_destination
    s32 burrow_run_count;  // 0 on the first update_burrow_inward_run, +1 on each after it; calc_step_value speeds up with it
    s32 lobby_state_locked;  // as TBoss1Dragon::lobby_state_locked: while set, run_task stops refreshing lobby_state
    ControllerInputContext *controller_input;  // points into controller_input_state.controllers
    RenderFadeState renderFadeStates[4];
    s32 player_controlled;  // 1 while a player steers the dragon (select_freeze_target, boss8_dragon_player_control)
    u16 target_client_id;  // as TBoss1Dragon::target_client_id: the steering player, frozen at the dragon
    u8 _pad752[0x2];
    s32 controlTimer;  // as TBoss1Dragon::controlTimer: frames of player control
    u32 facingAngle;  // as TBoss1Dragon::facingAngle: the angle state_circle_flight circles on
    s32 attack_kind;  // as TBoss1Dragon::attack_kind: the breath and fire bullets' attack kind (set_mode_params)
    const s32 *particle_ids;  // TBoss1Dragon reads the same ids through effectResource->particle_ids
    u32 randomState[58];  // a SubtractiveRng, as TBoss1Dragon::randomState
    s32 stateStep;  // step and frame counter of the current action, as in TBoss1Dragon
    s32 impactAge;
    s32 action_frames;
    s32 demo_flag;  // 1 while the opening TBoss8DragonDemo runs (update_appearance_state); the demo ends when it reads 0
    s32 action_angle;
    s32 action_spin;  // as TBoss1Dragon::action_spin: a heading to turn to, the dive's roll speed
    f32 fallVelocity;
    f32 rootHeight;
    f32 action_speed;  // as TBoss1Dragon::action_speed: the dive's fall acceleration, the spiral's radius
    f32 vertical_speed;  // as TBoss1Dragon::vertical_speed
    f32 root_height_speed;  // as TBoss1Dragon::root_height_speed
    Vec action_point;  // the current action's point or step, as TBoss1Dragon::action_point
    f32 m_884;
    f32 m_888;
    f32 m_88c;
    s32 ground_impact_done;  // as TBoss1Dragon::ground_impact_done: the dive has hit the ground
    TParticleCtrl *breath_particles[3];  // as TBoss1Dragon::breath_particles
    s32 lobby_state_changed;  // as TBoss1Dragon::lobby_state_changed: lobby_state became 0
    static void sync_target_pos(void *p);
    static s32 restore_target_pos(void *p);
    static s32 copy_pos_to_field688(void *p);
    static void capture_node_points(NJS_OBJECT *);
    void calc_velocity_from_angle();
    f32 clamp_step_in_radius(f32 a, f32 b, f32 s);
    void freeze_player_at_self();
    u16 find_player_on_floor();
    void spawn_ground_effect();
    void setup_instance(Vec *pos, DragonAttackParams *params, AreaAttackHistory *history);
    void apply_pillar_attack(Vec *pos, f32 radius);  // pillar area attack at pos (boss8_dragon_pillar_attack_params); TObjBoss8Piller::run_task
    void apply_fireball_impact_damage(Vec *pos, u32 kind);  // fireball impact attack at pos (boss8_dragon_fireball_impact_params); TBoss8DragonEffBullet::run_task
    void setup_breath_instance(Vec *pos, u32 kind, AreaAttackHistory *history);
    void emit_effect(const Vec *pos, const DragonAttackParams *params, AreaAttackHistory *history);
    void get_state_flags(const DragonAttackParams *params);
    void apply_ground_impact_attack();
    // As TBoss1Dragon::apply_foot_step_attack: the step attack at foot nodes 5/6 (side 0) or 3/4 (side 1).
    void apply_foot_step_attack(int side);
    void apply_foot_attack_pair_1();
    void apply_foot_attack_pair_0();
    void start_rumble();  // as TBoss1Dragon::start_rumble: pad rumble at the dragon
    void play_effect_sound(s32 sound_id);
    void spawn_trap(s32 id);
    void spawn_effect_if_in_band();
    s32 mask_flags(s32 input_flags, s32 mask);
    s32 check_can_attack();
    s32 select_target_in_front();
    s32 update_linked_position();
    void update_movement();
    void apply_6xA8_action(G_GolDragonBossActions_6xA8 *cmd);
    f32 calc_step_value();
    s32 check_damage_reaction();
    void pick_next_action();
    void setDestinationX(s32 x);
    void save_position();
    void send_6xA8_action();
    void send_action_packet(int action);
    void apply_ground_movement(Vec *step);
    void sweep_body_attack_spheres(f32 a, f32 b, f32 c);
    void copy_pos_to_field688();
    void restore_target_pos();
    void sync_target_pos();
    void release_grabbed_player();
    s32 is_primary_sequence();
    void reset_tail_hp();
    void reload_boss_stats();
    void set_air_turn_direction(s32 angle, s32 target_angle);
    void reset_action();
    void activate_attack();
    void set_active_flag();
    void set_action_state();
    void set_state();
    void reset_timer();
    void play_sound_if_in_band();
    void try_spawn_trap();
    void select_sequence(s32 secondary);
    void restart_primary_sequence();
    s32 is_near_target();
    void calc_forward_point(f32 *x, f32 *z);
    void update_position_history();  // as TBoss1Dragon::update_position_history
    void set_state_22();
    // Nonzero once the dragon has left mode 30 (update_appearance_state).
    s32 has_appeared();
    void check_death();
    void select_next_action();
    static void free_static();
    // Listed with free_static in TLobby's floor resource callbacks.
    static void load_resources();
    // Hands the dragon back from the debug player control (boss8_dragon_player_control).
    static void clear_player_control();
    static NJS_OBJECT *clone_node_tree(NJS_OBJECT *src, NJS_OBJECT *dst, NJS_CNK_MODEL *model);
    static void *create(void *set_data);
    static s32 is_within_xz_distance(const Vec *pos, const NJS_OBJECT *node, f32 range_squared);
    static f32 calc_sq_offset(const DragonAttackParams *params, f32 padding);
    void noop();
    // The parts are numbered from boss8_dragon_leader_part's set entry; part 0 is the leader.
    static TBoss8Dragon *get_part(s32 index);
    static u16 get_part_entity_id(s32 index);
    static void place_parts_in_ring(s32 n, s32 hp, s32 seed);
    static s32 find_target_enemy();
    static s32 is_any_part_alive();
    static void update_all_parts();
    // How many live monitor slots stay on: fewer while more parts are alive, -1 in split screen.
    static s32 get_live_monitor_count();
    static s32 has_enough_enemies();
    void set_mode_params(s8 mode);
    void sweep_head_fall_spheres_early();
    void render_nodes_flagged();
    void copy_vectors();
    static s32 calc_binomial_coefficient(s32 n, s32 k);
    static s32 eval_bezier_curve(CurvePathPoint *points, int count, int closed, Vec *out, f32 t);
    static void get_camera_offsets(Vec *target_offset, Vec *eye_offset);
    void render_body_model();
    void select_freeze_target();
    void sweep_death_body_attack();
    s32 is_closest_part();
    s32 push_apart_from_parts();
    s32 is_near_other_part();
    void draw_with_fade(Vec *pos, s32 view);
    void draw();

    // Per-action event handlers, run by dispatch_action (vtable slot 87).
    // Mode 43: underground until no part is left; leaving it rings the dragon and its parts (place_parts_in_ring).
    void update_parts_burrow_state(s32 event);
    // Mode 31, as TBoss1Dragon::wait_for_players: stands until a player has been present 150 frames.
    void wait_for_players(s32 event);
    // Mode 30, as TBoss1Dragon::update_appearance_state: the opening demo (bossopgc motion, TBoss8DragonDemo).
    void update_appearance_state(s32 event);
    void update_wander_state(s32 event);
    // Mode 40: walks (motion walk) while the render fades come back.
    void update_appear_walk_state(s32 event);
    // Mode 39: walks (motion walk) while the render fades go out.
    void update_vanish_walk_state(s32 event);
    // Mode 38, as TBoss1Dragon::handle_fall_state: underground run to the arena centre, then mode 19.
    void handle_fall_state(s32 event);
    // Mode 37, as TBoss1Dragon::state_circle_flight: circles underground, then mode 38.
    void state_circle_flight(s32 event);
    void handle_walk_state(s32 event);
    // Modes 24-28 run while a player steers the dragon (player_controlled): stand, walk, hover, flight, burrow.
    void update_controlled_burrow_state(s32 event);
    void update_controlled_flight_state(s32 event);
    void update_controlled_hover_state(s32 event);
    void update_controlled_walk_state(s32 event);
    void update_controlled_stand_state(s32 event);
    // Mode 23, after update_fade_state: the dead motion while the render fades go out, then the dragon is removed.
    void update_fade_out_state(s32 event);
    void update_fade_state(s32 event);
    void update_death_state(s32 event);
    void handle_leap_state(s32 event);
    void handle_spiral_state(s32 event);
    void update_burrow_outward_run(s32 event);
    // Modes 16 and 17: update_burrow_inward_run for the first run and for each run after it.
    void update_burrow_repeat_run(s32 event);
    void update_burrow_first_run(s32 event);
    void update_burrow_inward_run(u32 event, s32 action);
    void update_dive_state(s32 event);
    void state_roar(s32 event);
    void update_stretch_state(s32 event);
    void update_head_down_attack_state(s32 event);
    void update_fall_state(s32 event);
    // Mode 42: update_fall_state near the target while the render fades come back.
    void update_appear_fall_state(s32 event);
    // Mode 35, as TBoss1Dragon::update_spinning_projectile_attack (tukomi, then tobidasi).
    void update_spinning_projectile_attack(s32 event);
    void update_air_fire_state(s32 event);
    void state_turn_and_charge(s32 event);
    void update_lift_state(s32 event);
    // Mode 41: update_lift_state while the render fades go out.
    void update_vanish_lift_state(s32 event);
    void handle_tail_attack_state(s32 event);
    void state_breath_attack(s32 event);
    void update_walking_state(s32 event);
    // Mode 1: the stand motion; a controller sends it to modes 3, 5 or 25.
    void update_stand_state(s32 event);
    // Mode 0: no motion of its own; the next choice picks the next action (mode 24 when controlled).
    void update_idle_state(s32 event);
};

#include <stddef.h>
LAYOUT_ASSERT(TBoss8DragonFadeStride, sizeof(RenderFadeState) == 0x1C);
LAYOUT_ASSERT(TBoss8DragonFadeOffset, offsetof(TBoss8Dragon, renderFadeStates) == 0x6DC);
LAYOUT_ASSERT(TBoss8DragonSize, sizeof(TBoss8Dragon) == 0x8A4);
LAYOUT_ASSERT(TBoss8DragonSubTasksOffset, offsetof(TBoss8Dragon, sub_tasks) == 0x3C4);
LAYOUT_ASSERT(TBoss8DragonAfterFadeOffset, offsetof(TBoss8Dragon, player_controlled) == 0x74C);

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
