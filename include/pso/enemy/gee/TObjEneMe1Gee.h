#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

struct BmlResource;
struct BmlMotionEntry;
struct TObjMotionAction;
class TParticleCtrl;

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// DelDepthAnimationBinding).
struct GeeAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// What TObjEnemy::movementParameters points at for the Gee.
struct GeeMovementParameters {
    f32 target_range;
    f32 move_speed;
    s32 turn_speed;
    u32 unknown_0C[4];
};

// The kind's parameter block (kind_params, from TLobby::dispatch_shared_handler_a); the field layout is
// shared with TObjEneMe1CanadinParams.
struct TObjEneMe1GeeParams {
    f32 melee_speed;       // chase step of the melee attack
    f32 ranged_power;      // power of the needle (the Canadin twin: of the discharge)
    u8 pad_8[0x10];
    s32 aim_time;          // ranged attack: frames the aim tracks the target
    u8 pad_1c[0x4];
    s32 shot_interval;     // ranged attack: frames after a shot before the next aim
    s32 shots_per_attack;  // ranged attack: shots before the attack ends
    s32 hurt_wait_time;    // hurt state: frames of the last stage
    s32 group_size;        // members per attack group (spawn_members, remove_member)
};

struct TObjEneMe1Gee : public TObjEneDD_ST {
    TObjEneMe1Gee(TObject *parent, TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index);
    TObjEneMe1Gee(TObject *parent, void *set_data, s32 kind);
    virtual ~TObjEneMe1Gee();
    virtual s32 acquire_target(f32);
    virtual void dispatch_action(u32 state, s32 reason);
    void init_state();
    virtual void update_body_colliders();
    virtual CsnHit *move_xz_on_ground(const Vec *);
    virtual void check_collisions();
    virtual void select_next_attack_state();
    virtual void select_model();
    virtual void spawn_members();
    virtual s32 check_retreat_trigger();
    virtual int has_no_members();
    virtual void state_activate(s32);
    virtual void state_rise(s32);
    virtual void state_dead(s32);
    virtual void apply_model_color();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual int can_member_attack_target(TObjChara *target);
    virtual void remove_member(TObjEneMe1Gee *member);
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    void copy_pos();
    void apply_parameters();
    void approach_hover_y(f32 height);
    void hover_toward(f32 height);
    void update_hover_height();
    void update_upper_hover_height();
    void update_fade_sequence();
    void update_packed_color();
    void set_core_color(const NJS_ARGB *color);
    void start_fade_sequence(s32 sequence);
    void set_low_appear();
    void set_high_appear();
    void set_in_fighter();
    void set_out_fighter();
    void start_formation();
    void state_spawn(s32);
    void render();
    void run_task();
    TObjEneMe1Gee *leader;
    s32 kind;
    s32 status_flags;
    TUnk_80494938 fade;
    f32 upper_hover_height;
    f32 hover_height;
    f32 random_hover_height;
    f32 hover_offset;
    f32 hover_y;
    f32 needle_speed;  // 6 + parameters[3] ("NEEDLE SPEED(+6.f ...)" in render_demo)
    f32 appear_speed;  // 1 + parameters[2] ("APPEAR SPEED(+1.f ...)"), the climb step
    s32 attack_delay;
    s32 attack_count;
    s32 pad_40c;
    s32 alt_model_color;
    Vec node_points[2];
    TObjEneMe1GeeParams *kind_params;
    s32 attack_pattern;
    s32 stage;
    s32 stage_timer;
    s32 stage_counter;
    s32 pad_440;
    s32 orbit_angle_step;
    // Scratch of the attack states, shared with the TObjEneMe1Canadin twin at the same place.
    f32 work_speed;         // melee: approach step; orbit: climb step; hurt: fall speed; move forward: x step
    f32 orbit_radius;       // orbit: radius; melee: climb step; hurt: fall acceleration; move forward: z step
    f32 orbit_radius_step;  // orbit: radius step towards 70
    Vec work_point;         // ranged attack: aim point; orbit: direction from the target
    TObject *eff_line;
    TParticleCtrl *particle_emitter;
    NJS_ARGB core_color;
    s32 core_color_packed;
    s32 fade_mode;
    s32 fade_sequence;
    s32 fade_step_timer;
    s32 fade_cursor;
    u16 leader_id;
    u8 pad_48e[0x2];
    static void load_resources();
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void state_move_forward(s32 msg);
    void state_motion_test(s32 msg);
    void state_return_home(s32 mode);
    void state_formation(s32 msg);
    void state_hover(s32 mode);
    void state_appear(s32 msg);
    void set_flag3c8_bit40();
    void set_flag3c8_bit8();
    void wake_leader();
    s32 handle_message(s32 id);
    s32 check_death_trigger();
    s32 check_can_attack();
    void update_angle();
    void climb_to_hover_height();
    void approach_upper_hover_height();
    static void free_globals();
    static TObjEneMe1Gee *create(TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index);
    static void *create(void *set_data);
    void order_attack();
    void order_activation(TObjChara *target, s32 delay);
    void update();
    void state_vanish(s32 mode);
    // Entered by run_hit_reaction; back to next_mode once the damage motion ends.
    void hurt_state(s32 mode);
    void state_regroup(s32 mode);
    void state_orbit(s32 mode);
    void state_melee_attack(s32 mode);
    void state_ranged_attack(s32 mode);
    void state_high_appear(s32 mode);
    void release_from_formation();  // status_flags 0x100000 (orbit alone, no regroup) | 4 (order_attack); the leader sends it to every member at formation_state 9 (name inferred)
    void order_activation_now();
    TObjChara *get_attacking_target();  // current_target while status 0x40000 (set by the attack states) is on, else NULL; the leader counts members on its target (name inferred)
    s32 has_status_flag(s32 mask);
    int is_activated();
    void play_high_appear_sound();  // persistent sound 0x3BC16 each frame of the high appear climb (name inferred)
    s32 is_hover_low();  // hover_offset < 20; gates the melee contact checks (name inferred)
    s32 find_attack_target(f32 *out, f32 range);
    // bodies->flags 0x28, set for the 4-frame dash of state_melee_attack and cleared after it (names inferred)
    void clear_melee_body_flags();
    void set_melee_body_flags();
    void climb_toward(f32 height);
    void climb_hover_y(f32 height);
    void calc_position(Vec *out);
    static BmlResource *get_resource_bundle();  // returns TObjEneMe1Gee__resource_bundle
};

// Stat ids of the three kinds (GeeData); load_resources registers them with TLobby.
extern const u32 gee_base_stat_ids[3];
extern const u32 gee_attack_stat_ids[3];
extern const u32 gee_resist_stat_ids[3];
extern const u32 gee_param_ids[3];

LAYOUT_ASSERT(TObjEneMe1Gee_size, sizeof(TObjEneMe1Gee) == 0x490);
#endif
