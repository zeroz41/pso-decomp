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
    void select_subtype();
    void update_center_position();
    TObjEneBm5GibonUNode pack_node;
    TObjEneBm5GibonUNode instance_node;
    TUnk_80494938 appear_fade;
    RenderFadeState camera_fades[4];
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
    f32 run_distance;      // distance run since the last RUN_FOIE roll (every 50 units)
    f32 backjump_chance;   // 0.4 + parameters[2] ("BACKJUMP(+0.4f)"), picks state 19 over the lunge
    f32 run_foie_chance;   // 0.3 + parameters[3] ("RUN_FOIE(+0.3f)"), foie while running
    f32 back_foie_chance;  // 0.3 + parameters[4] ("BACK_FOIE(+0.3f)"), foie after a back jump
    s32 status_flags;
    TargetCursorList targets;
    TObjCollidable *attack_collider;
    s32 reaction_delay;
    u16 reaction_attacker_id;
    u8 _pad516[0x2];
    s32 substate;
    s32 state_timer;
    s32 random_phase;
    // Shared with TObjEneBm5Wolf at the same place; the states reuse these as scratch.
    s32 circle_shift_timer;  // circling: frames the radius keeps shifting after a hit
    s32 target_heading;      // heading the turning states approach (circling: +1/-1 side)
    s32 base_heading;        // heading saved at the start of returning/flanking
    f32 stopping_distance;   // roaming stop distance; circling radius, appear and death slide speed
    f32 circle_radius;       // circling: radius the circle settles to
    f32 sink_depth;          // dying: how far the body has sunk
    f32 pad_53c;
    Vec work_point;          // appear: landing point; circling: target position; flanking: aim
    Vec work_vector;         // returning: start point; circling/flanking: side direction
    f32 pad_558;
    f32 pad_55c;
    f32 pad_560;
    s32 near_target;
    void remove_from_pack_member_list();
    void add_to_pack_member_list();
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
    void handle_state(s32 msg);
    void damage_linked_entity();
    void damage_linked_entity_type10();
    s32 play_sound_variant();
    void set_flag();
    void set_anim_by_state();
    void select_attack_by_range();
    void approach_target(f32 step);
    void face_target();
    void remove_from_instance_list();
    void add_to_instance_list();
    int is_active();
    f32 calc_anim_speed(f32 speed);
    s32 update_target();
    void pick_wander_destination();
    void turn_toward_angle(s32 angle);
    static TObjEneBm5GibonU *find_pack_leader(s32 id);
    void play_jump_footsteps();
    void play_run_footstep();
    void play_walk_footsteps();
    void backjump_state(s32 msg);
    // The state handlers and helpers TObjEneBm5Wolf shares: same order, sizes and bodies
    // as the wolf's, so they carry its names.
    void update_dying_state(s32 msg);
    void hurt_state(s32 msg);
    void repositioning_state(s32 msg);
    void returning_state(s32 msg);
    void update_lunge(s32 msg);
    void flanking_state(s32 msg);
    void chasing_state(s32 msg);
    void roaming_state(s32 msg);
    void howling_state(s32 msg);
    void standing_state(s32 msg);
    void alerted_state(s32 msg);
    void sleeping_state(s32 msg);
    void spot_appearing_state(s32 msg);
    void appearing_state(s32 msg);
    void empty_state(s32);
    void action(s32 msg);
    void schedule_pack_reaction(s32 timer, u16 id);
    s32 calc_lunge_aim(int);
    void spawn_recoil_dust(Vec *dir);
    f32 calc_xz_direction_to(Vec *target, Vec *dir);
    void calc_rotated_vector(s32 angle, Vec *out, s32 *rotation);
    s32 get_group_id();
    Vec *get_spawn_position();
};

// Stat ids of the normal and the leader variant (GibonData); load_resources registers them with TLobby.
extern const u32 gibon_base_stat_ids[2];
extern const u32 gibon_attack_stat_ids[2];
extern const u32 gibon_resist_stat_ids[2];
extern const u32 gibon_param_ids[2];

LAYOUT_ASSERT(TObjEneBm5GibonU_size, sizeof(TObjEneBm5GibonU) == 0x568);
LAYOUT_ASSERT(TObjEneBm5GibonU_pack_node, offsetof(TObjEneBm5GibonU, pack_node) == 0x3C0);
LAYOUT_ASSERT(TObjEneBm5GibonU_appear_fade, offsetof(TObjEneBm5GibonU, appear_fade) == 0x3D8);
LAYOUT_ASSERT(TObjEneBm5GibonU_is_leader, offsetof(TObjEneBm5GibonU, is_leader) == 0x464);
LAYOUT_ASSERT(TObjEneBm5GibonU_near_target, offsetof(TObjEneBm5GibonU, near_target) == 0x564);


#endif
