#ifndef PSO_ENEMY_STELTH_TOBJENEME3STELTH_H
#define PSO_ENEMY_STELTH_TOBJENEME3STELTH_H

#include "types.h"
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

// One variant's row of the parameter table TLobby hands load_shared_resources.
struct StelthBehaviorParams {
    f32 walk_speed;          // state_chase_target's move speed (walk motion)
    u8 pad_04[0x4];
    f32 sword_lunge_speed;   // state_sword moves this far a frame over frames 0..5
    f32 sword_motion_speed;  // animation descriptor 7 (sword) speed
    f32 damage_motion_speed; // animation descriptor 4 (damage) speed
    f32 support_tech_chance; // a technique roll above this casts Barta instead
    s32 support_tech_level;  // Resta, Shifta and Deband
    s32 cast_duration;       // frames state_cast_technique runs
    s32 sword_hold_frames;   // frames state_sword holds frame 25
    s32 attack_tech_level;   // Rafoie and Gifoie
};

// The record movementParameters points at (TObjEneMe3Stelth__shared_params); the
// TObjEneMe3SinowZoaMoveParams layout.
struct StelthMovementParams {
    f32 radius;      // target search radius the shared enemy targeting reads
    f32 speed;       // enemy_set_heading_velocity's speed
    s32 turn;        // turn_toward_direction's step
    s32 pad_0C[4];
};

struct TObjEneMe3Stelth : public TObjEneDD_ST {
    TObjEneMe3Stelth(TObject *parent);
    virtual ~TObjEneMe3Stelth();
    virtual s32 acquire_target(f32);
    virtual f32 receive_direct_attack(void *source, DirectAttackPayload payload, void *collider, s32 technique, s32 flags);
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void set_intangible();
    virtual void clear_intangible();
    virtual void check_collisions();
    virtual void attack_and_unequip();
    virtual s32 check_target_in_range();
    virtual void select_next_attack_state();
    virtual void vfunc_108();
    virtual s32 check_active_flag();
    virtual s32 check_flag();
    virtual void on_target_lost();
    virtual void vfunc_112();
    // State 0 (the ctor enters it, state_vanish ends in it): back at home_position, intangible,
    // then fade_in or ambush after 5 steps (fade_in_start).
    virtual void state_reset(s32);
    virtual void setup_move();
    virtual void draw_with_debug_info();
    void copy_pos_with_height_offset();
    void setup_move_bounds();
    f32 get_node_world_y();
    s32 test_body_collision(s32, f32);
    // starts_stealthed: parameters[0] < 2. is_alternate_variant: texture_variant >= 1 (alternate
    // texture list, knocks the weapon off, casts Barta); init_variant applies it.
    s32 starts_stealthed();
    s32 is_angle_in_range();
    s32 is_alternate_variant();
    void init_variant();
    void state_fade_in(s32);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    // TObjEneDD fields its header does not declare yet (TObjEneBm5Wolf declares the same ones).
    s32 stealthed;
    s32 fade_in_start;     // parameters[0] 0 or 2: state 0 leads to fade_in (wait motion), else to ambush (t_wait)
    s32 variant_index;
    s32 behavior_flags;
    f32 body_y;
    f32 body_offset_y;
    f32 technique_chance;
    f32 stealth_on_chance;
    f32 stealth_off_chance;
    f32 warp_chance;
    s32 material_color;
    s32 attack_count;      // attacks since the last wait or backstep; at 2 select_next_attack_state backsteps
    s32 texture_variant;   // the set data variant; 1 and up use the alternate texture list
    s16 saved_evp;         // evp at construction
    u8 pad_3f6[0x2];
    Vec hand_position;     // the target player's hand joint when its weapon is knocked off; the particle spot
    TUnk_80494938 fade;
    s32 projection_scroll; // render adds 0x222 a frame; stelth_projection_texture_handle
    s32 state_step;
    s32 state_timer;
    s32 backstep_angle;    // state_backstep faces this (towards the target) while it backs away
    f32 move_speed;        // the current state's move (or fall) speed
    // Per-state scratch values; only [0] is used: the facing cosine towards the target
    // (state_chase, state_chase_target, then is_in_sword_range), the last node height
    // (state_appear) and the lunge speed (state_sword).
    f32 state_values[4];
    TObject *owned_objects[2]; // never set here; the dtor queues them for destruction
    s32 try_spawn_ground_effect(const Vec *origin);
    void play_hit_effect();
    void spawn_ground_effect_on_frame_23();
    static void add_instance(NJS_OBJECT *node);
    void update_distance_state();
    static void set_slot_min_clamped_value(s32 index, f32 speed);
    static void free_shared_resources();
    void *create_real();
    static void load_shared_resources();
    // dispatch_action's state handlers; same slots and names as the TObjEneMe3SinowZoa
    // twin (see its header for the motion and transition evidence).
    void state_death(s32 reason);
    void state_cast_technique(s32 reason);
    void state_chase_target(s32 mode);
    void state_appear(s32 reason);
    void state_reveal(s32 reason);
    void state_chase(s32 mode);
    void create_resta_effect();
    void state_backstep(s32 reason);
    void state_stealth_on(s32 mode);
    void state_wait(s32 mode);
    // Ground effects on motion frames 12 and 28 (state_chase_target, state_sword).
    void spawn_footstep_effects();
    s32 check_move_collision(Vec *pos);
    void state_cast_barta(s32 reason);
    void state_stealth_off(s32 reason);
    void state_warp(s32 reason);
    void state_knockback(s32 reason);
    void state_sword(s32 reason);
    void state_f_attack(s32 reason);
    void state_ambush(s32 reason);
    // The target is within 20 in height, 25 away and in front: state_chase_target goes to state_sword.
    s32 is_in_sword_range(f32);
    void state_vanish(s32 reason);
    void draw_model();
};

LAYOUT_ASSERT(TObjEneMe3StelthFadeOffset, offsetof(TObjEneMe3Stelth, fade) == 0x404);
LAYOUT_ASSERT(TObjEneMe3Stelth_size, sizeof(TObjEneMe3Stelth) == 0x44C);


#endif
