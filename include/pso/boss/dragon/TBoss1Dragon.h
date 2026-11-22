#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGON_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGON_H

#include "types.h"
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

struct DragonModelVector { f32 x, y, z; };
struct DragonModelAngles { s32 x, y, z; };
struct DragonModelNode {
    u32 flags;
    void* model;
    DragonModelVector position;
    DragonModelAngles rotation;
    DragonModelVector scale;
    DragonModelNode* child;
    DragonModelNode* sibling;
    f32 unknown34;
};

struct DragonEffectResource { saddr particle_ids[8]; };

struct DragonControllerInput {
    u8 unk_0[0x8];
    s32 flags;
    u8 unk_C[0x1C - 0xC];
    s32 angle;
    u8 unk_20[0x4];
    f32 m_24;
};

struct DragonPositionKey { s32 frame; DragonModelVector value; };
struct DragonMotionData { DragonPositionKey *positionKeys; };
struct DragonMotion { DragonMotionData *data; u32 frameCount; };
struct DragonMotionEntry { u32 unknown00; DragonMotion* motion; };
struct DragonAnimationEntry { u32 unknown00; s32 motionIndex; u8 unknown08[8]; };

struct DragonModelEntry { u8 unknown00[8]; DragonModelNode *root; s32 m_c; u8 unknown10[8]; s32 m_18; };
struct DragonResource { u8 unknown00[0x42C]; DragonModelEntry *model; DragonMotionEntry *motions; };
LAYOUT_ASSERT(DragonPositionKeySize, sizeof(DragonPositionKey) == 0x10);

extern "C" void copy_model_node(u8 *dst, u8 *src);

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
    static DragonModelNode* cloneModelHierarchy(DragonModelNode* source, DragonModelNode* output, void* model);
    static s32 countModelNodes(DragonModelNode* source);
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
    s32 m_3e0;
    s32 phase;
    Vec breath_node_points[3];  // dragon_capture_node_points writes them in render; breath_origin/direction come from them
    Vec breath_origin;  // the TBoss1DragonEffBreath and the fire bullets start here
    Vec breath_direction;  // breath_node_points[1] - [0], the breath's direction
    Vec breath_effect_position;
    Vec node_positions[0x22];
    Vec m_5c8;
    f32 m_5d4;
    f32 height;
    f32 heightOffset;
    f32 defaultHeightOffset;
    f32 m_5e4;
    Vec m_5e8;
    AccelerationCurve curve0;  // as TBoss8Dragon::curve0
    AccelerationCurve curve1;
    Vec m_63c;
    Vec m_648;
    s32 m_654;
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
    s32 m_6a4;
    f32 sector_radii[12];
    TObjBoss1MokoHill_SoloM *moko_hill; // the mound that follows the Dragon underground
    s32 m_6dc;
    s32 m_6e0;
    DragonControllerInput *controller_input;
    RenderFadeState viewFade[4];
    s32 m_758;
    s32 m_75c;
    s32 m_760;
    u16 target_client_id;
    u8 unk_766[0x2];
    s32 controlTimer;
    s32 facingAngle;
    s32 m_770;
    TUnk_80481B34 *m_774;
    DragonEffectResource* effectResource;
    u32 randomState[58];
    s32 stateStep;
    s32 impactAge;
    s32 m_86c;
    s32 m_870;
    s32 m_874;
    s32 m_878;
    f32 fallVelocity;
    f32 rootHeight;
    f32 m_884;
    f32 m_888;
    f32 m_88c;
    Vec m_890;
    f32 m_89c;
    f32 m_8a0;
    f32 m_8a4;
    s32 m_8a8;
    TParticleCtrl *breath_particles[3];  // breath and fire particles kept at breath_effect_position / breath_origin
    s32 m_8b8;
    void wait_for_players(s32 arg1);
    void update_appearance_state(u32 reason);
    void update_wander_state(s32 arg1);
    void handle_fall_state(u32 reason);
    void state_circle_flight(u32 reason);
    void handle_state(u32 arg1);
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
    static u16 find_player_on_floor(void *arg0);
    void update_switch_attack();
    void apply_ground_impact_attack();
    void apply_head_fall_attack();
    void spawn_impact_crater(Vec *pos);
    s32 check_phase_advance();
    s32 update_max_hp_phase();
    void set_params(void *arg1);
    void copy_params(void *arg1);
    void reload_impact_stats();
    void reload_stats_for_phase(int _w1);
    void reset_tail_hp();
    void reload_difficulty_stats();
    s32 advance_air_turn();
    void init_air_turn(s32 targetAngle);
    void set_result_flag(s32 arg1, s32 arg2);
    void play_nearby_se();
    s32 select_air_fire_target(Vec *out);
    f32 sample_root_height();
    void calc_forward_point(f32 *arg1, f32 *arg2);
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
    void apply_fireball_impact_damage(saddr arg1);
    void deliver_breath_attack(saddr position, s32 attack_history);
    void sweep_death_body_attack();
    void apply_foot_step_attack(int arg1);
    void next_sequence_action();
    void receive_state_request(u8 *arg1);
    void update_air_fire_state(u32 reason);
    void remap_sequence_after_recovery();
    void update_emergence_state(u32 reason);
    void update_death_state(u32 arg1);
    void update_dive_state(u32 reason);
    static s32 filter_input_flags(s32 arg1, s32 arg2, s32 arg3);
    void clear_work();
    f32 calc_burrow_speed();
    void calc_target_vector();
    s32 check_parts_visible(TObjCollidable *parts);
    s32 is_sphere_visible(Vec *center, f32 radius);
    s32 check_attack_ready();
    void sweep_head_fall_spheres_late();
    void update_from_data();
    void sweep_body_attack_spheres(f32 a, f32 b, f32 c);
    void apply_landing_attack();
    void send_state_sync();
    void spawn_trap(s32 id);
    void play_se_at_pos(s32 id);
    s32 select_forward_target();
    s32 choose_burrow_ring_destination(Vec *out);
    s32 is_destination_ahead();
    void prepare_flight_destination(Vec *dest);
    void calc_follow_camera_offsets(Vec *eye, Vec *target);
    void play_sound_if_in_band();
    void handle_walk_state(u32 reason);
    void sub_800224A4(u32 reason);
    void sub_80022740(u32 reason);
    void sub_800228E8(u32 reason);
    void sub_80022C38(u32 reason);
    void handle_spiral_state(u32 reason);
    void sub_80026B98(u32 reason);
    void sub_80026C98(u32 reason);
    f32 clamp_step_in_radius(f32 farg0, f32 farg1, f32 farg2);
    void sub_800274A4();
    void sub_80027514(Vec *position, u8 *params, s32 history);
    void sub_80027590(void *params);
    void sub_800275BC(Vec *position, u8 *params, AreaAttackHistory *history);
    void sub_80028AFC();
    void sub_80028B28();
};

void get_dragon_follow_camera_offsets(Vec *eye, Vec *target);

#include <stddef.h>
#define DRAGON_OFFSET(member, offset) \
    LAYOUT_ASSERT(DragonOffset_##member, offsetof(TBoss1Dragon, member) == offset)
LAYOUT_ASSERT(DragonModelNodeSize, sizeof(DragonModelNode) == 0x38);
LAYOUT_ASSERT(DragonModelNodeChild, offsetof(DragonModelNode, child) == 0x2C);
DRAGON_OFFSET(target_id, 0x38C);
DRAGON_OFFSET(breath_origin, 0x40C);
DRAGON_OFFSET(breath_effect_position, 0x424);
DRAGON_OFFSET(m_870, 0x870);
DRAGON_OFFSET(breath_particles, 0x8AC);
DRAGON_OFFSET(m_884, 0x884);
DRAGON_OFFSET(wall_reach, 0x37C);
DRAGON_OFFSET(m_3e0, 0x3E0);
DRAGON_OFFSET(m_63c, 0x63C);
DRAGON_OFFSET(m_774, 0x774);
DRAGON_OFFSET(destination_direction, 0x3A0);
DRAGON_OFFSET(m_8a8, 0x8A8);
DRAGON_OFFSET(m_8b8, 0x8B8);
DRAGON_OFFSET(m_654, 0x654);
DRAGON_OFFSET(attack_history, 0x688);
DRAGON_OFFSET(sector_count, 0x6A0);
DRAGON_OFFSET(sector_radii, 0x6A8);
DRAGON_OFFSET(moko_hill, 0x6D8);
DRAGON_OFFSET(controller_input, 0x6E4);
DRAGON_OFFSET(m_760, 0x760);
DRAGON_OFFSET(target_client_id, 0x764);
DRAGON_OFFSET(randomState, 0x77C);
DRAGON_OFFSET(m_86c, 0x86C);
DRAGON_OFFSET(m_874, 0x874);
DRAGON_OFFSET(m_878, 0x878);
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
