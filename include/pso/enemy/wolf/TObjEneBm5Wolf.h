#ifndef PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H
#define PSO_ENEMY_WOLF_TOBJENEBM5WOLF_H

#include "types.h"

struct NJS_OBJECT;
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResource.h"
#include "pso/enemy/deldepth/DelDepthData.h"

struct TObjEneBm5Wolf;

struct TObjEneBm5WolfNode {
    TObjEneBm5WolfNode *prev;
    TObjEneBm5WolfNode *next;
    u16 entity_id;

    TObjEneBm5WolfNode();
    ~TObjEneBm5WolfNode();
    void set_owner(TObjEneBm5Wolf *owner);
    TObjEneBm5Wolf *get_owner();
    void append_to(TObjEneBm5WolfNode **head, TObjEneBm5WolfNode **tail);
    void unlink_from(TObjEneBm5WolfNode **head, TObjEneBm5WolfNode **tail);
};

struct TObjEneBm5WolfList {
    TObjEneBm5WolfNode *head;
    TObjEneBm5WolfNode *tail;

    TObjEneBm5WolfList *reset();
    ~TObjEneBm5WolfList();
    void clear();
    void append(TObjEneBm5WolfNode *node);
    void remove(TObjEneBm5WolfNode *node);
};

struct TObjEneBm5Wolf : public TObjEneDD_ST {
    TObjEneBm5Wolf(TObject *parent, void *set_data);
    virtual ~TObjEneBm5Wolf();
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 event);
    virtual void update_body_colliders();
    virtual void update_state();
    virtual void render_debug();
    void update_collision_center();
    void select_subtype();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void roaming_state(int event);
    void choose_roaming_destination();
    TObjEneBm5WolfNode m_3c0;
    TObjEneBm5WolfNode m_3cc;
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
    static void advance_spawn_timer(NJS_OBJECT *);
    void despawn_state(s32 msg);
    void update_dying_state(s32 event);
    void hurt_state(s32 event);
    void action(s32 arg1);
    void repositioning_state(s32 event);
    void update_lunge(s32 event);
    void circling_state(s32 event);
    void chasing_state(s32 event);
    void empty_state(s32 event);
    void standing_state(s32 event);
    void alerted_state(s32 event);
    void sleeping_state(s32 event);
    void apply_mourning_jellen();
    void apply_mourning_zalure();
    void play_proximity_effect();
    void set_attack_flag();
    void set_anim_state();
    void turn_pose_to_target();
    void remove_from_pack_member_list();
    void add_to_pack_member_list();
    static void release_global_805D5120();
    static void *create(void *set_data);
    static void load_resources();
    static void register_global_objects();
    void flanking_state(s32 event);
    void howling_state(s32 event);
    void anchor_state(s32 event);
    void remove_from_instance_list();
    void add_to_instance_list();
    s32 get_group_id();
    static TObjEneBm5Wolf *find_pack_leader(s32 id);
    void advance_pose_turn(s32 target);
    void approach_target(f32 step);
    void set_state_by_timer();
    s32 select_death_direction(s32 *heading);
    s32 select_target();
    s32 play_variant_sound();
    void play_footsteps();
    f32 calc_death_slide_speed(f32 speed);
    int get_flag_bit0();
    s32 calc_lunge_aim();
    void schedule_pack_reaction(s32 delay, u16 value);
    void appearing_state(s32 event);
    void returning_state(s32 event);
    void calc_rotated_vector(s32 angle, Vec *out, s32 *heading);
    f32 calc_circle_offset(Vec *target, Vec *out);
    void spawn_recoil_dust(Vec *dir);
};

LAYOUT_ASSERT(WolfOffset_current_target, offsetof(TObjEneBm5Wolf, current_target) == 0x390);
LAYOUT_ASSERT(WolfOffset_destination, offsetof(TObjEneBm5Wolf, destination) == 0x394);
LAYOUT_ASSERT(WolfOffset_destination_direction, offsetof(TObjEneBm5Wolf, destination_direction) == 0x3A0);
LAYOUT_ASSERT(WolfOffset_destination_distance, offsetof(TObjEneBm5Wolf, destination_distance) == 0x3AC);
LAYOUT_ASSERT(WolfOffset_m_3c0, offsetof(TObjEneBm5Wolf, m_3c0) == 0x3C0);
LAYOUT_ASSERT(WolfOffset_m_3d8, offsetof(TObjEneBm5Wolf, m_3d8) == 0x3D8);
LAYOUT_ASSERT(WolfOffset_turnOffset, offsetof(TObjEneBm5Wolf, turnOffset) == 0x3E4);
LAYOUT_ASSERT(WolfOffset_groupAnchor, offsetof(TObjEneBm5Wolf, groupAnchor) == 0x3F4);
LAYOUT_ASSERT(WolfOffset_desiredSpeed, offsetof(TObjEneBm5Wolf, desiredSpeed) == 0x400);
LAYOUT_ASSERT(WolfOffset_currentSpeed, offsetof(TObjEneBm5Wolf, currentSpeed) == 0x404);
LAYOUT_ASSERT(WolfOffset_roamingSubstate, offsetof(TObjEneBm5Wolf, roamingSubstate) == 0x41C);
LAYOUT_ASSERT(WolfOffset_roamingTimer, offsetof(TObjEneBm5Wolf, roamingTimer) == 0x420);
LAYOUT_ASSERT(WolfOffset_randomPhase, offsetof(TObjEneBm5Wolf, randomPhase) == 0x424);
LAYOUT_ASSERT(WolfOffset_stoppingDistance, offsetof(TObjEneBm5Wolf, stoppingDistance) == 0x434);
LAYOUT_ASSERT(WolfOffset_nearTarget, offsetof(TObjEneBm5Wolf, nearTarget) == 0x468);

LAYOUT_ASSERT(TObjEneBm5Wolf_size, sizeof(TObjEneBm5Wolf) == 0x46C);

s32 actor_rand_int(saddr actor, s32 range);

#endif
