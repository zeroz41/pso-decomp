#ifndef PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H
#define PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H

#include "types.h"
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/deldepth/DelDepthData.h"

struct TObjEneBm5WolfListNode {
    TObjEneBm5WolfListNode *prev;
    TObjEneBm5WolfListNode *next;
    u16 entity_id;
};

struct TObjEneBm5WolfList {
    TObjEneBm5WolfListNode *head;
    TObjEneBm5WolfListNode *tail;
};

struct TObjEneBm5Wolf : public TObjEneDD_ST {
    virtual ~TObjEneBm5Wolf();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
    virtual void update_state();
    virtual void render_debug();
    void update_collision_center();
    void select_subtype();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void roaming_state(int event);
    void choose_roaming_destination();
    u8 unk_374[0x4];
    s32 m_378;
    f32 m_37c;
    u8 unk_380[0x10];
    TObjChara *target;
    Vec destination;
    Vec destinationDirection;
    f32 destinationDistance;
    u8 unk_3B0[0x10];
    TObjEneBm5WolfListNode m_3c0;
    TObjEneBm5WolfListNode m_3cc;
    s32 m_3d8;
    s32 m_3dc;
    u16 m_3e0;
    u8 unk_3E2[0x2];
    s32 turnOffset;
    Vec m_3e8;
    Vec groupAnchor;
    f32 desiredSpeed;
    f32 currentSpeed;
    u32 m_408;
    f32 m_40c;
    TObjCollidable *m_410;
    s32 m_414;
    u16 m_418;
    u8 unk_41A[0x2];
    s32 roamingSubstate;
    s32 roamingTimer;
    s32 randomPhase;
    s32 m_428;
    s32 m_42c;
    s32 m_430;
    f32 stoppingDistance;
    f32 m_438;
    f32 m_43c;
    f32 m_440;
    Vec m_444;
    Vec m_450;
    f32 m_45c;
    f32 m_460;
    f32 m_464;
    s32 nearTarget;
    static void advance_spawn_timer();
    void despawn_state(s32 msg);
    void update_dying_state(s32 arg1);
    void hurt_state(s32 arg1);
    void action(s32 arg1);
    void repositioning_state(s32 arg1);
    void update_lunge(s32 arg1);
    void circling_state(s32 arg1);
    void chasing_state(s32 arg1);
    static void empty_state();
    void standing_state(s32 arg1);
    void alerted_state(s32 arg1);
    void sleeping_state(s32 arg1);
    void apply_mourning_jellen();
    void apply_mourning_zalure();
    void play_proximity_effect();
    void set_attack_flag();
    void set_anim_state();
    void turn_pose_to_target();
    void update_with_default_state();
    void apply_position_to_node_list();
    static void release_global_805D5120();
    static void *create(void *arg0);
    static void load_resources();
    void reset_fields();
    void*reset();
    void push_list_node(void **arg1, void **arg2);
    void unlink_list_node(void ***arg1, void **arg2);
    static void register_global_objects();
    void flanking_state(s32 arg1);
    void howling_state(s32 arg1);
    void anchor_state(s32 arg1);
    void update_default();
    void apply_global_to_position();
    void update(void* a1);
    void apply_to_position(void* a1);
    void set_field8_from_obj(s32 arg1);
};

typedef char WolfOffset_target[offsetof(TObjEneBm5Wolf, target) == 0x390 ? 1 : -1];
typedef char WolfOffset_destination[offsetof(TObjEneBm5Wolf, destination) == 0x394 ? 1 : -1];
typedef char WolfOffset_destinationDirection[offsetof(TObjEneBm5Wolf, destinationDirection) == 0x3A0 ? 1 : -1];
typedef char WolfOffset_destinationDistance[offsetof(TObjEneBm5Wolf, destinationDistance) == 0x3AC ? 1 : -1];
typedef char WolfOffset_m_3c0[offsetof(TObjEneBm5Wolf, m_3c0) == 0x3C0 ? 1 : -1];
typedef char WolfOffset_m_3d8[offsetof(TObjEneBm5Wolf, m_3d8) == 0x3D8 ? 1 : -1];
typedef char WolfOffset_turnOffset[offsetof(TObjEneBm5Wolf, turnOffset) == 0x3E4 ? 1 : -1];
typedef char WolfOffset_groupAnchor[offsetof(TObjEneBm5Wolf, groupAnchor) == 0x3F4 ? 1 : -1];
typedef char WolfOffset_desiredSpeed[offsetof(TObjEneBm5Wolf, desiredSpeed) == 0x400 ? 1 : -1];
typedef char WolfOffset_currentSpeed[offsetof(TObjEneBm5Wolf, currentSpeed) == 0x404 ? 1 : -1];
typedef char WolfOffset_roamingSubstate[offsetof(TObjEneBm5Wolf, roamingSubstate) == 0x41C ? 1 : -1];
typedef char WolfOffset_roamingTimer[offsetof(TObjEneBm5Wolf, roamingTimer) == 0x420 ? 1 : -1];
typedef char WolfOffset_randomPhase[offsetof(TObjEneBm5Wolf, randomPhase) == 0x424 ? 1 : -1];
typedef char WolfOffset_stoppingDistance[offsetof(TObjEneBm5Wolf, stoppingDistance) == 0x434 ? 1 : -1];
typedef char WolfOffset_nearTarget[offsetof(TObjEneBm5Wolf, nearTarget) == 0x468 ? 1 : -1];

typedef char TObjEneBm5Wolf_size[sizeof(TObjEneBm5Wolf) == 0x46C ? 1 : -1];

extern "C" {
u8 *TObjEneBm5Wolf__ct(TObjEneBm5Wolf *wolf, void *arg1, void *arg2);
s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1);
u8 *__dt__14TObjEneBm5WolfFv(TObjEneBm5Wolf *wolf, s16 arg1);
}
s32 actor_rand_int(s32 actor, s32 arg1);
extern "C" {
void approach_target__14TObjEneBm5WolfFPvf(TObjEneBm5Wolf *wolf, f32 step);
s32 calc_lunge_aim__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(TObjEneBm5Wolf *wolf, s32 angle, Vec *out, s32 *heading);
TObjEneBm5WolfListNode *destroy__14TObjEneBm5WolfFis(TObjEneBm5WolfListNode *node, s16 arg1);
void TObjEneBm5Wolf__sub_800B8A24(TObjEneBm5WolfListNode *node);
void dispatch_state__14TObjEneBm5WolfFPvUii(TObjEneBm5Wolf *wolf, u32 state, s32 event);
int get_flag_bit0__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
s32 get_group_id__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
void play_footsteps__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
TObjEneBm5Wolf *play_sound__14TObjEneBm5WolfFPv(TObjEneBm5WolfListNode *node);
s32 play_variant_sound__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
void render_debug__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
void returning_state__14TObjEneBm5WolfFPvi(TObjEneBm5Wolf *actor, s32 arg1);
void schedule_pack_reaction__14TObjEneBm5WolfFPvis(TObjEneBm5Wolf *wolf, s32 delay, u16 value);
s32 select_target__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
void set_state_by_timer__14TObjEneBm5WolfFi(TObjEneBm5Wolf *wolf);
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(TObjEneBm5Wolf *wolf, Vec *dir);
void update_state__14TObjEneBm5WolfFPv(TObjEneBm5Wolf *wolf);
}

#endif
