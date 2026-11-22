#ifndef PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H
#define PSO_ENEMY_SINOWZOA_TOBJENEME3SINOWZOA_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>

// Per-kind parameter block from TLobby::dispatch_shared_handler_a, one for each of
// the two Sinow Zoa kinds (load_resources).
struct TObjEneMe3SinowZoaParams {
    f32 walk_speed;          // state_chase_target's move speed (walk motion)
    u8 pad_04[0x4];
    f32 sword_lunge_speed;   // state_sword moves this far a frame over frames 0..5
    f32 sword_motion_speed;  // animation descriptor 7 (sword) speed
    f32 damage_motion_speed; // animation descriptor 4 (damage) speed
    f32 support_tech_chance; // a technique roll above this casts Barta instead
    s32 support_tech_level; // level of the techniques cast_technique casts
    s32 cast_duration;       // frames state_cast_technique runs
    s32 sword_hold_frames;   // frames state_sword holds frame 25
    s32 attack_tech_level; // level of its Gibarta
};

// What TObjEnemy::movementParameters points at (TObjEneMe3SinowZoa_init_params).
struct TObjEneMe3SinowZoaMoveParams {
    f32 radius; // target search radius the shared enemy targeting reads
    f32 speed;  // enemy_set_heading_velocity's speed
    s32 turn;   // turn_toward_direction's step
    s32 pad_0C[4];
};

struct TObjEneMe3SinowZoa : public TObjEneDD_ST {
    TObjEneMe3SinowZoa(TObject *parent);
    virtual ~TObjEneMe3SinowZoa();
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32, s32);
    virtual s32 acquire_target(f32);
    virtual void dispatch_action(u32 state, s32 reason);
    void update_stealth_fade(); // run_task: material fade toward visible while actorFlags 0x24 is set, else toward the stealth state
    void state_fade_in(s32);
    virtual void run_task();
    virtual void render();
    s32 check_body_collision_at(s32 angle, f32 distance);
    // starts_stealthed: parameters[0] < 2. is_alternate_variant: texture_variant >= 1 (alternate
    // texture list, knocks the weapon off, casts Barta); init_variant applies it.
    s32 starts_stealthed();
    s32 is_outside_visible_range();
    s32 is_alternate_variant();
    void init_variant();
    s32 render_model_if_visible();
    virtual void update_body_colliders();
    virtual void set_intangible();
    virtual void clear_intangible();
    virtual void check_collisions();
    virtual void attack_and_unequip();
    virtual s32 is_target_in_range();
    virtual void select_next_attack_state();
    virtual void vfunc_108();
    virtual s32 try_run_effect_m6();
    virtual s32 try_run_effect_m7();
    virtual void on_target_lost();
    virtual void vfunc_112();
    // State 0 (the ctor enters it, state_vanish ends in it): back at home_position, intangible,
    // then fade_in or ambush after 5 steps (fade_in_start).
    virtual void state_reset(s32 mode);
    virtual void setup_move();
    virtual void render_demo();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    s32 stealthed;
    s32 fade_in_start;     // parameters[0] 0 or 2: state 0 leads to fade_in (wait motion), else to ambush (t_wait)
    s32 kind_index;
    s32 behavior_flags;
    s32 floor_flags; // check_floor_contact: the floor's contact flags (0x4000 reflective)
    Vec floor_point; // the reflective floor's contact point (else position): push_reflection_matrix
    f32 body_y;
    f32 body_offset_y;
    // The debug overlay labels these "TECNIQ ATTACK % (+0.4f)", "STELTH ON % (+0.3f)",
    // "STELTH OFF % (+0.1f)" and "WARP % (+0.5f)": setup_move_bounds adds those bases.
    f32 technique_chance;
    f32 stealth_on_chance;
    f32 stealth_off_chance;
    f32 warp_chance;
    u32 material_color;
    s32 attack_count;      // attacks since the last wait or backstep; at 2 select_next_attack_state backsteps
    s32 texture_variant;   // the set data variant; 1 and up use the alternate texture list
    s16 saved_evp;         // evp at construction
    u8 pad_406[0x2];
    Vec hand_position; // the target player's hand joint when its weapon is knocked off; the particle spot
    TUnk_80494938 fade;
    u8 pad_430[0x4];
    s32 state_step;
    s32 state_timer;
    s32 backstep_angle;    // state_backstep faces this (towards the target) while it backs away
    f32 move_speed;        // the current state's move (or fall) speed
    // Per-state scratch values; only [0] is used: the facing cosine towards the target
    // (state_chase, state_chase_target, then is_in_sword_range), the last node height
    // (state_appear) and the lunge speed (state_sword).
    f32 state_values[4];
    TObject *owned_objects[2]; // never set here; the dtor queues them for destruction
    // dispatch_action's state handlers, named after the motion each requests (the
    // motion names of bm_ene_me3_shinowa_zoa_motion_names) and the states they lead to:
    // 1 fade_in, 3 ambush (t_wait, then 4), 4 reveal (material alpha ramps up once a
    // target is near, then 5), 5 appear, 7 f_attack, 8 sword, 9 backstep, 10 vanish (fades
    // out, back to state 0 at home), 11 cast_technique, 12 warp (next to the target),
    // 13 wait, 14 knockback, 15 death, 16 cast_barta, 17 stealth_on, 18 stealth_off.
    // TObjEneMe3Stelth uses the same names for the same slots.
    void state_knockback(s32 mode);
    void state_wait(s32 mode);
    void state_chase_target(s32 mode);
    void state_reveal(s32 mode);
    void state_chase(s32 mode);
    void update_distance_state();
    f32 get_node_height();
    void setup_move_bounds();
    void copy_pos_with_height_offset();
    s32 check_floor_contact(const Vec *origin);
    void check_and_notify();
    static void set_entry_value_clamped(s32 index, f32 speed);
    // load_resources (inferred): the floor resource loader paired with free_resources
    // in floor_resource_callbacks.
    static void load_resources();
    static void free_resources();
    // Ground effects on motion frames 12 and 28 (state_chase_target, state_sword).
    void spawn_footstep_effects();
    void spawn_ground_effect_on_frame_23();
    void state_cast_barta(s32 mode);
    void state_stealth_off(s32 mode);
    void state_stealth_on(s32 mode);
    void state_warp(s32 mode);
    void state_death(s32 mode);
    void state_vanish(s32 mode);
    void state_cast_technique(s32 mode);
    void state_backstep(s32 mode);
    void state_sword(s32 mode);
    void state_f_attack(s32 mode);
    void state_appear(s32 mode);
    void state_ambush(s32 mode);
    // The target is within 20 in height, 25 away and in front: state_chase_target goes to state_sword.
    s32 is_in_sword_range(f32);
    s32 check_move_collision(const Vec *pos);
    void cast_technique();
};

LAYOUT_ASSERT(TObjEneMe3SinowZoa_m_3c0_offset, offsetof(TObjEneMe3SinowZoa, stealthed) == 0x3C0);
LAYOUT_ASSERT(TObjEneMe3SinowZoa_fade_offset, offsetof(TObjEneMe3SinowZoa, fade) == 0x414);
LAYOUT_ASSERT(TObjEneMe3SinowZoa_size, sizeof(TObjEneMe3SinowZoa) == 0x45C);

#endif
