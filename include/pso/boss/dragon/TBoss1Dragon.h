#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGON_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGON_H

#include "types.h"

struct NJS_TEXLIST;
#include "pso/render/RenderFadeState.h"
#include "pso/boss/derolle/AccelerationCurve.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"

class TBoss1DragonEffTail;
class TParticleCtrl;
class AreaAttackHistory;
class TObject;
class TBoss1DragonColli;
class TUnk_80481B34;
class TObjBoss1MokoHill_SoloM;
class TObjChara;
struct TObjPlayer;
struct ControllerInputContext;

struct NJS_OBJECT;

struct DragonEffectResource { saddr particle_ids[8]; };

struct TBoss1Dragon : public TObjEneDD_ST {
    TBoss1Dragon(TObject *parent, void *set_data);
    virtual ~TBoss1Dragon();
    void load_resources();
    void request_state_change(u32 state);
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void run_task();
    virtual void update_body_colliders();
    virtual void render();
    virtual void render_shadows();
    virtual int run_demo_task();
    virtual void render_low_detail();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void refresh_target();
    static s32 isV2Mode();
    static NJS_OBJECT* cloneModelHierarchy(NJS_OBJECT* source, NJS_OBJECT* output, void* model);
    static s32 countModelNodes(NJS_OBJECT* source);
    void updateFacingPosition();
    void handleFallState(u32 reason);
    void apply_foot_attack_pair_1();
    void apply_foot_attack_pair_0();
    void saveCurrentDestination();
    void setDestinationX(int x);
    void saveTargetDestination();
    void restorePosition();
    void copySavedX(int* x);
    void restoreTargetPosition();
    void beginHeightTransition();
    void setPhase2();
    void setActive();
    void clearState();
    void update_damage_threshold();
    void update_spinning_projectile_attack(u32 reason);
    s32 is_secondary_sequence();
    s32 is_primary_sequence();
    void select_sequence(int secondary);
    void restart_primary_sequence();
    static void clearControlOverride();
    static void setControlOverride(s16 controlId);
    static void requestActionRefresh();
    u32 flags;
    TObject sub_tasks;
    s32 lobby_state;  // from update_lobby_state: 0 runs the action sequence, 1 only animates, 2 re-sends reason 2
    s32 phase;
    Vec breath_node_points[3];  // dragon_capture_node_points writes them in render; breath_origin/direction come from them
    Vec breath_origin;  // the TBoss1DragonEffBreath and the fire bullets start here
    Vec breath_direction;  // breath_node_points[1] - [0], the breath's direction
    Vec breath_effect_position;
    Vec node_positions[0x22];
    Vec target_vector;  // calc_target_vector: target - breath_origin in xz, normalized
    f32 target_distance;  // its length before normalizing
    f32 height;
    f32 heightOffset;
    f32 defaultHeightOffset;
    f32 pad_5e4;
    Vec last_flight_direction;  // destination_direction when the flight state is left
    AccelerationCurve curve0;  // as TBoss8Dragon::curve0
    AccelerationCurve curve1;
    Vec sound_origin;  // as TBoss8Dragon::sound_origin
    Vec last_body_center;
    u32 camera_eye_raised;  // calc_follow_camera_offsets raises and pulls back the follow camera eye while it is 1
    s32 airTurnVelocity;
    s32 airTurnDirection;
    s32 airTurnStartAngle;
    f32 airTurnAcceleration;
    f32 airTurnFinalAcceleration;
    f32 airTurnInitialVelocity;
    f32 airTurnFinalVelocity;
    f32 airTurnMidpointAngle;
    f32 airTurnTime;
    s32 sequenceCursor;
    s16 hpThreshold;
    s16 finalHpThreshold;
    TBoss1DragonEffTail *tail;
    AreaAttackHistory *attack_history;
    TBoss1DragonColli *collider;
    f32 destinationX;
    f32 destinationZ;
    f32 savedX;
    f32 savedZ;
    s32 sector_count;
    s32 crater_count;  // craters spawn_impact_crater has placed (at most 12)
    f32 sector_radii[12];
    TObjBoss1MokoHill_SoloM *moko_hill; // the mound that follows the Dragon underground
    s32 burrow_run_count;  // burrow runs so far; calc_burrow_speed grows with it
    s32 lobby_state_locked;  // while set, run_task stops refreshing lobby_state
    ControllerInputContext *controller_input;  // controller_input_state.controllers[2], [0] once init_control_mode runs
    RenderFadeState viewFade[4];
    s32 pad_758;
    s32 pad_75c;
    s32 player_controlled;  // init_control_mode: a player (target_client_id) steers the Dragon
    u16 target_client_id;
    u8 unk_766[0x2];
    s32 controlTimer;
    s32 facingAngle;
    s32 attack_kind;  // the fire attacks' DragonAttackParams kind: 1, 0x13 in V2
    TUnk_80481B34 *attack_collider;  // the V2 attacks place this sphere instead of TObjEneDD's effects
    DragonEffectResource* effectResource;
    u32 randomState[58];
    s32 stateStep;
    s32 impactAge;
    s32 action_frames;  // frames into the current action step (twin TBoss8Dragon::action_frames)
    s32 demo_flag;  // the flag TBoss1DragonDemo clears when the opening demo ends
    s32 action_angle;  // the heading the current action turns to
    s32 action_spin;  // the spinning attack's heading; the dive's roll speed
    f32 fallVelocity;
    f32 rootHeight;
    f32 action_speed;  // the dive's ground speed, the spiral's radius, the emergence's rise
    f32 vertical_speed;  // the dive's heightOffset speed
    f32 root_height_speed;  // the dive's rootHeight speed
    Vec action_point;  // the current action's point or step
    f32 pad_89c;
    f32 pad_8a0;
    f32 pad_8a4;
    s32 ground_impact_done;  // the dive has made its crater and ground impact
    TParticleCtrl *breath_particles[3];  // breath and fire particles kept at breath_effect_position / breath_origin
    s32 lobby_state_changed;  // lobby_state became 0; the burrow states then move to the next action
    void wait_for_players(s32 reason);
    void update_appearance_state(u32 reason);
    void update_wander_state(s32 reason);
    void handle_fall_state(u32 reason);
    void state_circle_flight(u32 reason);
    void handle_state(u32 reason);
    void update_fade_state(u32 reason);
    void update_burrow_outward_run(u32 reason);
    void update_roar_state(u32 reason);
    void update_stretch_state(u32 reason);
    void update_head_down_attack_state(u32 reason);
    void update_flight_state(u32 reason);
    void update_lift_state(u32 reason);
    void update_tail_attack_state(u32 reason);
    void update_breath_attack_state(u32 reason);
    void update_walking_state(u32 reason);
    s32 check_can_attack();
    void hold_captured_player();
    u16 find_player_on_floor();
    void update_switch_attack();
    void apply_ground_impact_attack();
    void apply_head_fall_attack();
    void spawn_impact_crater(Vec *pos);
    s32 check_phase_advance();
    s32 update_max_hp_phase();
    void set_params(void *packet);
    void copy_params(void *packet);
    void reload_impact_stats();
    void reload_stats_for_phase(int);
    void reset_tail_hp();
    void reload_difficulty_stats();
    f32 get_crater_attack_power();  // 0.666 of the first parameter block's power at +4 (TObjBoss1Crater's hits)
    s32 advance_air_turn();
    void init_air_turn(s32 targetAngle);
    void set_air_turn_direction(s32 angle, s32 target_angle);
    void play_nearby_se();
    s32 select_air_fire_target(Vec *out);
    f32 sample_root_height();
    void calc_forward_point(f32 *x, f32 *z);
    s32 update_linked_epsilon_position();
    void update_position_history();
    void check_death();
    void choose_next_action();
    static void free_resources();
    static void *create(void *set_data);
    static saddr get_instance();
    static void select_fireball_particle_table();
    void draw();
    void update_burrow_inward_run(u32 reason, s32 state);
    void release_held_player();
    void init_control_mode();
    void apply_fireball_impact_damage(Vec *position);
    void deliver_breath_attack(Vec *position, AreaAttackHistory *attack_history);
    void sweep_death_body_attack();
    void apply_foot_step_attack(int side);
    void next_sequence_action();
    void receive_state_request(u8 *packet);
    void update_air_fire_state(u32 reason);
    void remap_sequence_after_recovery();
    void update_emergence_state(u32 reason);
    void update_death_state(u32 reason);
    void update_dive_state(u32 reason);
    s32 filter_input_flags(s32 input_flags, s32 mask);
    void start_rumble();  // pad rumble at the Dragon (start_pad_rumble_at)
    f32 calc_burrow_speed();
    void calc_target_vector();
    s32 check_parts_visible(TObjCollidable *parts);
    s32 is_sphere_visible(Vec *center, f32 radius);
    s32 check_attack_ready();
    void sweep_head_fall_spheres_late();
    void sweep_head_fall_spheres_early();
    void sweep_body_attack_spheres(f32 a, f32 b, f32 c);
    void apply_landing_attack();
    void send_state_sync();
    void spawn_trap(s32 id);
    void play_se_at_pos(s32 id);
    s32 select_forward_target();
    s32 choose_burrow_ring_destination(Vec *out);
    s32 is_destination_ahead();
    void prepare_flight_destination(Vec *dest);
    void calc_follow_camera_offsets(Vec *target_offset, Vec *eye_offset);
    void play_sound_if_in_band();
    void handle_walk_state(u32 reason);
    void update_controlled_flight_state(u32 reason);
    void update_controlled_hover_state(u32 reason);
    void update_controlled_walk_state(u32 reason);
    void update_controlled_stand_state(u32 reason);
    void handle_spiral_state(u32 reason);
    void update_stand_state(u32 reason);
    void update_idle_state(u32 reason);
    f32 clamp_step_in_radius(f32 dir_x, f32 dir_z, f32 step);
    void update_flap_effect();
    void apply_trail_attack();
    void setup_v2_instance(const Vec *position, DragonAttackParams *params, AreaAttackHistory *history);
    void emit_v2_effect_at_position(const DragonAttackParams *params);
    void emit_v2_enemy_effect(const Vec *position, const DragonAttackParams *params, AreaAttackHistory *history);
    void set_burrow_height();
    void set_flight_height();
};

void get_dragon_follow_camera_offsets(Vec *target_offset, Vec *eye_offset);
// The movement ailment (kind 0) the Dragon's hit boxes, tail and craters give a target not in state 2.
void apply_dragon_hit_ailment(TObjChara *target);

void handle_6x10_dragon_boss_actions(void *packet);
void handle_6x11_dragon_boss_actions(void *packet);
void handle_6x12_dragon_boss_actions(TObjPlayer *packet);

#include <stddef.h>
#define DRAGON_OFFSET(member, offset) \
    LAYOUT_ASSERT(DragonOffset_##member, offsetof(TBoss1Dragon, member) == offset)
DRAGON_OFFSET(target_id, 0x38C);
DRAGON_OFFSET(breath_origin, 0x40C);
DRAGON_OFFSET(breath_effect_position, 0x424);
DRAGON_OFFSET(demo_flag, 0x870);
DRAGON_OFFSET(breath_particles, 0x8AC);
DRAGON_OFFSET(action_speed, 0x884);
DRAGON_OFFSET(wall_reach, 0x37C);
DRAGON_OFFSET(lobby_state, 0x3E0);
DRAGON_OFFSET(sound_origin, 0x63C);
DRAGON_OFFSET(attack_collider, 0x774);
DRAGON_OFFSET(destination_direction, 0x3A0);
DRAGON_OFFSET(ground_impact_done, 0x8A8);
DRAGON_OFFSET(lobby_state_changed, 0x8B8);
DRAGON_OFFSET(camera_eye_raised, 0x654);
DRAGON_OFFSET(attack_history, 0x688);
DRAGON_OFFSET(sector_count, 0x6A0);
DRAGON_OFFSET(sector_radii, 0x6A8);
DRAGON_OFFSET(moko_hill, 0x6D8);
DRAGON_OFFSET(controller_input, 0x6E4);
DRAGON_OFFSET(player_controlled, 0x760);
DRAGON_OFFSET(target_client_id, 0x764);
DRAGON_OFFSET(randomState, 0x77C);
DRAGON_OFFSET(action_frames, 0x86C);
DRAGON_OFFSET(action_angle, 0x874);
DRAGON_OFFSET(action_spin, 0x878);
DRAGON_OFFSET(airTurnVelocity, 0x658);
DRAGON_OFFSET(airTurnTime, 0x678);
DRAGON_OFFSET(controlTimer, 0x768);
DRAGON_OFFSET(effectResource, 0x778);
DRAGON_OFFSET(stateStep, 0x864);
DRAGON_OFFSET(impactAge, 0x868);
DRAGON_OFFSET(fallVelocity, 0x87C);
DRAGON_OFFSET(rootHeight, 0x880);
DRAGON_OFFSET(destination, 0x394);
DRAGON_OFFSET(flags, 0x3C0);
DRAGON_OFFSET(phase, 0x3E4);
DRAGON_OFFSET(height, 0x5D8);
DRAGON_OFFSET(sequenceCursor, 0x67C);
DRAGON_OFFSET(hpThreshold, 0x680);
DRAGON_OFFSET(destinationX, 0x690);
DRAGON_OFFSET(savedX, 0x698);
DRAGON_OFFSET(facingAngle, 0x76C);
LAYOUT_ASSERT(DragonSize, sizeof(TBoss1Dragon) == 0x8BC);
#undef DRAGON_OFFSET

#endif
