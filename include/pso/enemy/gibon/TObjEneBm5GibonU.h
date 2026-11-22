#ifndef PSO_ENEMY_GIBON_TOBJENEBM5GIBONU_H
#define PSO_ENEMY_GIBON_TOBJENEBM5GIBONU_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "dolphin/mtx.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/player/TargetCursorList.h"

struct TObjPlayer;
struct TObjEneBm5GibonU;

struct TObjEneBm5GibonUMovementParameters {
    f32 range;
    f32 speed;
    s32 turn;
    u32 unknown[4];
};

// A link in one of the Gibbon lists, tagged with its owner's entity id.
struct TObjEneBm5GibonUNode {
    TObjEneBm5GibonUNode();
    ~TObjEneBm5GibonUNode();
    TObjEneBm5GibonU *get_owner();
    void set_owner(TObjEneBm5GibonU *owner);
    void append_to(TObjEneBm5GibonUNode **head, TObjEneBm5GibonUNode **tail);
    void unlink_from(TObjEneBm5GibonUNode **head, TObjEneBm5GibonUNode **tail);

    TObjEneBm5GibonUNode *prev;
    TObjEneBm5GibonUNode *next;
    u16 entity_id;
};

struct TObjEneBm5GibonUList {
    TObjEneBm5GibonUList *reset();
    ~TObjEneBm5GibonUList();
    void clear();
    void append(TObjEneBm5GibonUNode *node);
    void remove(TObjEneBm5GibonUNode *node);

    TObjEneBm5GibonUNode *head;
    TObjEneBm5GibonUNode *tail;
};

struct TObjEneBm5GibonU : public TObjEneDD_ST {
    TObjEneBm5GibonU(TObject *parent, void *set_data);
    virtual ~TObjEneBm5GibonU();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_debug();
    void sub_800D10A0();
    void update_center_position();
    TObjEneBm5GibonUNode m_3c0;
    TObjEneBm5GibonUNode m_3cc;
    TUnk_80494938 m_3d8;
    RenderFadeState m_3f4[4];
    s32 is_leader;   // render_debug "L/M:LEADER" / "MEMBER"
    s32 technique_type; // state_cast_technique switch, case 1 casts GiBarta
    s32 group_id;    // render_debug "GROUP:%2d"
    s32 appear_mode; // render_debug 1 = "SPOT APPEAR", else "JUMP APPEAR"
    u16 leader_id;
    u8 _pad476[0x2];
    s32 turn_offset;
    Vec spawn_position;
    Vec group_anchor;
    f32 desired_speed;
    f32 current_speed;
    f32 m_49c;
    f32 m_4a0;
    f32 m_4a4;
    f32 m_4a8;
    s32 status_flags;
    TargetCursorList targets;
    TObjCollidable *attack_collider;
    s32 reaction_delay;
    u16 m_514;
    u8 _pad516[0x2];
    s32 substate;
    s32 state_timer;
    s32 random_phase;
    s32 m_524;
    s32 m_528;
    s32 m_52c;
    f32 m_530;
    f32 m_534;
    f32 m_538;
    f32 m_53c;
    Vec m_540;
    Vec m_54c;
    f32 m_558;
    f32 m_55c;
    f32 m_560;
    s32 near_target;
    void forward_hit_to_node_list();
    void init_child_node();
    static void release_static_resource();
    static void *create(void *set_data);
    static void load_resources();
    static void register_global_objects();
    s32 get_clamped_level();
    s32 check_hit_sphere(int angle, f32 scale);
    void get_attack_state(void *pos);
    void spawn_landing_effect(Vec *pos);
    static void advance_anim_frame(NJS_OBJECT *);
    void handle_message(s32 msg);
    void state_cast_technique(s32 msg);
    void run_idle_state(s32 msg);
    void handle_state(s32 arg1);
    void damage_linked_entity();
    void damage_linked_entity_type10();
    s32 play_sound_variant();
    void set_flag();
    void set_anim_by_state();
    void select_attack_by_range();
    void approach_target(f32 step);
    void face_target();
    void forward_hit_to_enemy_list();
    void init_child_from_list();
    int is_active();
    f32 calc_anim_speed(f32 speed);
    s32 update_target();
    void pick_wander_destination();
    void turn_toward_angle(s32 angle);
    static TObjEneBm5GibonU *find_enemy_by_id(s32 id);
    void sub_800CCD8C();
    void sub_800CCDE4();
    void sub_800CCE28();
    void sub_800CDB98(s32 msg);
    void sub_800CE060(s32 msg);
    void sub_800CE370(s32 msg);
    void sub_800CE694(s32 msg);
    void sub_800CE978(s32 msg);
    void sub_800CEBD8(s32 msg);
    void sub_800CF4BC(s32 msg);
    void sub_800CF7CC(s32 msg);
    void sub_800CFA48(s32 msg);
    void sub_800CFE34(s32 msg);
    void sub_800CFFBC(s32 msg);
    void sub_800D00F0(s32 msg);
    void sub_800D01DC(s32 msg);
    void sub_800D02F8(s32 msg);
    void sub_800D0420(s32 msg);
    void sub_800CFE30(s32);
    void action(s32 msg);
    void sub_800D095C(s32 timer, u16 id);
    s32 sub_800D0968(int);
    void sub_800D0AE8(Vec *dir);
    f32 calc_xz_direction_to(Vec *target, Vec *dir);
    void calc_rotated_vector(s32 angle, Vec *out, s32 *rotation);
    s32 get_group_id();
    Vec *sub_800D1D78();
};

LAYOUT_ASSERT(TObjEneBm5GibonU_size, sizeof(TObjEneBm5GibonU) == 0x568);
LAYOUT_ASSERT(TObjEneBm5GibonU_m_3c0, offsetof(TObjEneBm5GibonU, m_3c0) == 0x3C0);
LAYOUT_ASSERT(TObjEneBm5GibonU_m_3d8, offsetof(TObjEneBm5GibonU, m_3d8) == 0x3D8);
LAYOUT_ASSERT(TObjEneBm5GibonU_m_464, offsetof(TObjEneBm5GibonU, is_leader) == 0x464);
LAYOUT_ASSERT(TObjEneBm5GibonU_m_564, offsetof(TObjEneBm5GibonU, near_target) == 0x564);


#endif
