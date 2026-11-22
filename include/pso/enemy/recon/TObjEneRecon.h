#ifndef PSO_ENEMY_RECON_TOBJENERECON_H
#define PSO_ENEMY_RECON_TOBJENERECON_H

#include "types.h"

struct NJS_OBJECT;
struct TObjEneRecobox;
class TParticleCtrl;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

// What TObjEnemy::movementParameters points at for a Recon (TObjEneRecon__ai_parameters).
struct ReconMoveParams {
    f32 pad_00;
    f32 move_speed;  // distance moved per frame (move_with_wall_slide_commit)
    s32 turn_speed;  // largest heading change per frame
    s32 pad_0C[4];
};

// The Recon parameter block TLobby::dispatch_shared_handler_a(0x42) hands out (TObjEneRecon__behavior_params).
struct ReconParams {
    f32 collide_distance;  // distance update_collide_flag probes ahead with
    f32 bomb_radius;       // TObjEneReconBomb blast radius
    f32 bomb_power;        // TObjEneReconBomb blast power
    f32 bomb_speed;        // TObjEneReconBomb launch speed
    f32 pad_10;
    f32 pad_14;
    s32 bomb_seconds;      // a bomb's lifetime in seconds (calc_scaled_value: x30 frames)
    s32 strike_delay;      // frames it hovers in range before a strike
};

struct TObjEneRecon : public TObjEneDD_ST {
    TObjEneRecon(TObject *parent, TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir);
    virtual ~TObjEneRecon();
    virtual s32 acquire_target(f32);
    s32 render_model_if_visible();
    virtual void check_collisions();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void update_flag_0x444();
    void state_launch(s32);
    void state_death(s32 reason);
    void state_damage(s32 reason);
    void state_fade_out(s32 reason);
    void state_orbit(s32 reason);
    void state_bomb_attack(s32 reason);
    void state_attack(s32 reason);
    void state_search(s32 reason);
    s32 is_in_strike_range();
    s32 is_dead();
    f32 get_bomb_speed();
    f32 get_bomb_power();
    f32 get_bomb_radius();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    void render_shadows();
    static void advance_intro_stage(NJS_OBJECT *);
    void update_ground_probe();
    s32 is_anim_5();
    u16 get_attack_target_id();
    void spawn_trap_a();
    void spawn_trap_b();
    f32 approach_value(f32 current, f32 target);
    void clamp_min_height();
    void update_position_from_offsets();
    void init_state();
    static void release_static_instance();
    static TObjEneRecon *create(TObjEneRecobox *owner, u16 id, s32 index, Vec *pos, Vec *dir);
    static void load_resources();
    void*get_field_38_ptr();
    s32 calc_scaled_value();
    void handle_message(s32 message);
    void retarget();
    void select_next_target();
    void update_collide_flag();
    void set_flag2(f32 x, f32 z, f32 r);
    void set_orbit_destination(s32 angle);
    void advance_field398();
    void sync_height();

    s32 state_step;               // step inside the current action state
    s32 state_timer;              // frames spent in the current step (bomb wind-up, strike wait)
    s32 hit_window;               // 1 between strike frames 7 and 31: players near root_node_position are hit
    s32 pad_3CC;
    s32 orbit_angle;              // angle around the target that the orbit destination is placed at
    s32 orbit_step;               // orbit_angle change per frame: +-speed / circumference, in angle units
    s32 bob_phase;                // phase of the 10-unit height bob while orbiting
    s32 pad_3DC;
    f32 rise_speed;               // vertical speed added to hover_height while knocked back (gravity 0.1)
    f32 move_speed;               // horizontal speed: length of velocity, decays by 0.98
    f32 pad_3E8[9];
    Vec root_node_position;       // world position of the model's first node, refreshed by render; bombs and
                                  // the strike start here
    s32 floor_flags;             // flags of the floor under it (update_ground_probe); 0x4000 = reflective
    Vec floor_point;              // that floor point
    Vec spawn_direction;          // the box's launch direction (ctor)
    u16 owner_id;                 // entity id of the TObjEneRecobox that spawned it
    u8 pad_436[0x2];
    Vec owner_position;           // where that box stood at the spawn
    u32 recon_flags;              // bit 1: done for (exploded, faded out or let go by its box)
    f32 hover_height;
    Vec velocity;                 // xz drift of the knockback (normalize_vector_xz)
    f32 pad_458;
    s32 pad_45C;
    f32 offset_max;               // orbit height over the box: 45 + 2x + the box's recon_offset_max
    f32 strike_height;            // height over the target it closes in at before a strike: 15 + 2x
    f32 rotate_rad;               // orbit radius: 50 + 5x + the box's recon_rotate_rad
    s32 orbit_since_strike;       // angle orbited since the last strike; past half a turn it strikes
    s32 orbit_since_bomb;         // angle orbited since the last bomb; past 0x5000 it drops one
    s32 attacking;                // set while a strike or bomb state runs; get_attack_target_id reports the target then
    TParticleCtrl *emitter;       // particle emitter 0x217 trailing the body
    s32 emitter_side;             // flips each frame: the emitter swings 3 units to either side
    TUnk_80494938 fade;
    u8 pad_49C[0x48];
};

LAYOUT_ASSERT(TObjEneRecon_size, sizeof(TObjEneRecon) == 0x4E4);

#endif
