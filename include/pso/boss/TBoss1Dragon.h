#ifndef PSO_BOSS_TBOSS1DRAGON_H
#define PSO_BOSS_TBOSS1DRAGON_H

#include "types.h"
#include "pso/misc/CameraObstructionFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

class TBoss1DragonEffTail;

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

struct DragonEffectResource { u32 unknown00[2]; void* data; };

struct DragonPositionKey { s32 frame; DragonModelVector value; };
struct DragonMotionData { DragonPositionKey *positionKeys; };
struct DragonMotion { DragonMotionData *data; u32 frameCount; };
struct DragonMotionEntry { u32 unknown00; DragonMotion* motion; };
struct DragonAnimationEntry { u32 unknown00; s32 motionIndex; u8 unknown08[8]; };

struct DragonModelEntry { u8 unknown00[8]; DragonModelNode *root; };
struct DragonResource { u8 unknown00[0x42C]; DragonModelEntry *model; DragonMotionEntry *motions; };
typedef char DragonPositionKeySize[sizeof(DragonPositionKey) == 0x10 ? 1 : -1];

extern "C" void copy_model_node(u8 *dst, u8 *src);

struct TBoss1Dragon : public TObjEneDD_ST {
    virtual ~TBoss1Dragon();
    void load_resources();
    void request_state_change(u32 state);
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void run_task();
    virtual void vfunc_88();
    virtual void render();
    virtual void render_shadows();
    virtual int vfunc_105();
    virtual void render_low_detail();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    static bool isV2Mode();
    static DragonModelNode* cloneModelHierarchy(DragonModelNode* source, DragonModelNode* output, void* model);
    static s32 countModelNodes(DragonModelNode* source);
    void updateFacingPosition();
    void handleFallState(u32 reason);
    int apply_foot_attack_pair_1();
    int apply_foot_attack_pair_0();
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
    u8 unk_374[0x1C];
    u32 m_390;
    f32 targetX;
    f32 targetY;
    f32 targetZ;
    u8 unknown3A0[0x3C0 - 0x3A0];
    u32 flags;
    u8 unknown3C4[0x3E4 - 0x3C4];
    s32 phase;
    u8 unknown3E8[0x40C - 0x3E8];
    DragonModelVector m_40c;
    u8 unknown418[0x5D8 - 0x418];
    f32 height;
    f32 heightOffset;
    f32 defaultHeightOffset;
    u8 unknown5E4[0x654 - 0x5E4];
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
    u8 unknown688[0x690 - 0x688];
    f32 destinationX;
    f32 destinationZ;
    f32 savedX;
    f32 savedZ;
    u8 unknown6A0[0x6E8 - 0x6A0];
    CameraObstructionFade viewFade[4];
    u8 unknown758[0x768 - 0x758];
    s32 controlTimer;
    s32 facingAngle;
    u8 unknown770[0x778 - 0x770];
    DragonEffectResource* effectResource;
    u32 randomState[58];
    s32 stateStep;
    s32 impactAge;
    s32 m_86c;
    u8 unknown870[0x4];
    s32 m_874;
    s32 m_878;
    f32 fallVelocity;
    f32 rootHeight;
    u8 unknown884[0x8BC - 0x884];
    void wait_for_players(s32 arg1);
    void update_appearance_state(u32 reason);
    void update_wander_state(s32 arg1);
    void handle_fall_state(u32 arg1);
    void state_circle_flight(u32 arg1);
    void handle_state(u32 arg1);
    void update_fade_state(u32 arg1);
    void update_burrow_outward_run(u32 arg1);
    void update_roar_state(u32 arg1);
    void update_stretch_state(u32 arg1);
    void update_head_down_attack_state(u32 arg1);
    void update_flight_state(u32 arg1);
    void update_lift_state(u32 arg1);
    void update_tail_attack_state(u32 arg1);
    void update_breath_attack_state(u32 arg1);
    void update_walking_state(u32 arg1);
    s32 check_can_attack();
    void hold_captured_player();
    static u16 find_player_on_floor(void *arg0);
    void update_switch_attack();
    void apply_ground_impact_attack();
    void apply_head_fall_attack();
    void spawn_impact_crater(s32 arg1);
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
    s32 select_air_fire_target(void *out_);
    f32 sample_root_height();
    void calc_forward_point(f32 *arg1, f32 *arg2);
    static void update_linked_epsilon_position();
    void update_position_history();
    void check_death();
    void choose_next_action();
    static void free_resources();
    static u8 *create(s32 arg0);
    static s32 get_instance();
    static void select_fireball_particle_table();
    int get_position();
    void draw();
    void update_burrow_inward_run(u32 arg1, s32 arg2);
    void release_held_player();
    void init_control_mode();
    void apply_fireball_impact_damage(s32 arg1);
    void deliver_breath_attack(s32 arg1, s32 arg2);
    void sweep_death_body_attack();
    int apply_foot_step_attack(int arg1);
    void receive_state_request(u8 *arg1);
    void update_air_fire_state(u32 arg1);
    void remap_sequence_after_recovery();
    void update_emergence_state(u32 arg1);
};

#include <stddef.h>
#define DRAGON_OFFSET(member, offset) \
    typedef char DragonOffset_##member[(offsetof(TBoss1Dragon, member) == offset) ? 1 : -1]
typedef char DragonModelNodeSize[(sizeof(DragonModelNode) == 0x38) ? 1 : -1];
typedef char DragonModelNodeChild[(offsetof(DragonModelNode, child) == 0x2C) ? 1 : -1];
DRAGON_OFFSET(m_40c, 0x40C);
DRAGON_OFFSET(m_654, 0x654);
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
DRAGON_OFFSET(targetX, 0x394);
DRAGON_OFFSET(flags, 0x3C0);
DRAGON_OFFSET(phase, 0x3E4);
DRAGON_OFFSET(height, 0x5D8);
DRAGON_OFFSET(sequenceCursor, 0x67C);
DRAGON_OFFSET(hpThreshold, 0x680);
DRAGON_OFFSET(destinationX, 0x690);
DRAGON_OFFSET(savedX, 0x698);
DRAGON_OFFSET(facingAngle, 0x76C);
typedef char DragonSize[(sizeof(TBoss1Dragon) == 0x8BC) ? 1 : -1];
#undef DRAGON_OFFSET

#endif
