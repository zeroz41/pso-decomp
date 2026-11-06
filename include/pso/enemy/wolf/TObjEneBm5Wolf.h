#ifndef PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H
#define PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H

#include "types.h"
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct TObjEneBm5Wolf : public TObjEneDD_ST {
    virtual ~TObjEneBm5Wolf();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_88();
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
    u8 unk_37C[0x14];
    void* target;
    f32 destination[3];
    f32 destinationDirection[3];
    f32 destinationDistance;
    u8 _pad3B0[0x10];
    void* m_3c0;
    u8 _pad3C4[0x8];
    void* m_3cc;
    u8 _pad3D0[0x8];
    u32 m_3d8;
    u8 _pad3DC[0x4];
    u16 m_3e0;
    u8 _pad3E2[0x2];
    s32 turnOffset;
    void* m_3e8;
    u8 _pad3EC[0x8];
    f32 groupAnchor[3];
    f32 desiredSpeed;
    f32 currentSpeed;
    u32 m_408;
    u8 _pad40C[0x4];
    u32 m_410;
    u32 m_414;
    u16 m_418;
    u8 _pad41A[0x2];
    s32 roamingSubstate;
    s32 roamingTimer;
    s32 randomPhase;
    u32 m_428;
    u32 m_42c;
    u32 m_430;
    f32 stoppingDistance;
    u8 unk_438[0x4];
    f32 m_43c;
    u8 unk_440[0x4];
    f32 m_444;
    u8 unk_448[0x4];
    f32 m_44c;
    u8 unk_450[0x4];
    f32 m_454;
    u8 unk_458[0x4];
    f32 m_45c;
    u8 unk_460[0x4];
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
u8 *TObjEneBm5Wolf__ct(u8 *arg0, void *arg1, void *arg2);
s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1);
u8 *__dt__14TObjEneBm5WolfFv(u8 *arg0, s16 arg1);
}
s32 actor_rand_int(s32 actor, s32 arg1);
extern "C" {
void anchor_state__14TObjEneBm5WolfFl(u8 *arg0, s32 arg1);
void apply_global_to_position__14TObjEneBm5WolfFv(s32 arg0);
void apply_to_position__14TObjEneBm5WolfFPv(void *p, void *a1);
void approach_target__14TObjEneBm5WolfFPvf(void *arg0, f32 farg0);
s32 calc_lunge_aim__14TObjEneBm5WolfFPv(u8 *arg0);
void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3);
s32 destroy__14TObjEneBm5WolfFis(s32 arg0, s16 arg1);
void dispatch_state__14TObjEneBm5WolfFPvUii(TObjEneBm5Wolf *arg0, u32 state, s32 event);
int get_flag_bit0__14TObjEneBm5WolfFPv(void *p);
s32 get_group_id__14TObjEneBm5WolfFPv(void *p);
void play_footsteps__14TObjEneBm5WolfFPv(u8 *arg0);
void play_sound__14TObjEneBm5WolfFPv(void *arg0);
void play_variant_sound__14TObjEneBm5WolfFPv(void *arg0);
void render__14TObjEneBm5WolfFv(u8 *arg0);
void render_debug__14TObjEneBm5WolfFPv(u8 *arg0);
void returning_state__14TObjEneBm5WolfFPvi(u8 *actor, s32 arg1);
void run_task__14TObjEneBm5WolfFv(u8 *arg0);
void schedule_pack_reaction__14TObjEneBm5WolfFPvis(void *arg0, s32 arg1, s16 arg2);
void select_target__14TObjEneBm5WolfFPv(void *arg0);
void set_field8_from_obj__14TObjEneBm5WolfFl(void *arg0, s32 arg1);
void set_state_by_timer__14TObjEneBm5WolfFi(s32 arg0);
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(s32 arg0, u8 *arg1);
void update__14TObjEneBm5WolfFPv(void *p, void *a1);
void update_default__14TObjEneBm5WolfFv(s32 arg0);
void update_state__14TObjEneBm5WolfFPv(void *arg0);
}

#endif
