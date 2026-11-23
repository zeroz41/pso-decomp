#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLY_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLY_H

#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>
#include "pso/enemy/dd/TObjEneDD_ST.h"

class TParticleCtrl;
struct TObjEneBm3FlyNest;

// TObjEnemy::movementParameters of a fly or its nest (same layout as MojaMovementParameters).
struct Bm3FlyMovementParameters {
    f32 unknown_00;
    f32 length;
    s32 unknown_08;
    u32 unknown_0C[4];
};

// The block TLobby::dispatch_shared_handler_a(0) returns; the fly's load_resources keeps it in bm3_fly_lobby_params.
struct Bm3FlyParameters {
    f32 distance;
    u8 unknown_04[0x18];
    s32 unknown_1C;
};

// The motion binding the fly and the nest pass to TLobby::spawn_npc_enemy.
struct Bm3FlyAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// TObjEneBm3Fly::status_flags.
enum {
    BM3_FLY_HIDDEN = 0x1,  // render draws nothing
    BM3_FLY_SHADOW = 0x2   // render draws the ground shadow (ground found under it)
};

struct TObjEneBm3Fly : public TObjEneDD_ST {
    TObjEneBm3Fly(TObject *parent, TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *velocity);
    virtual ~TObjEneBm3Fly();
    void action(s32 msg);
    void update_return_state(s32 msg);
    void update_chase_state(s32 msg);
    void update_orbit_state(s32 msg);
    void update_launch_state(s32 msg);
    void play_orbit_flight_sound();
    virtual s32 acquire_target(f32);
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void check_collisions();
    virtual void update_body_colliders();
    virtual void dispatch_action(u32 state, s32 reason);
    void handle_message(s32 msg);
    void state_death_fall(s32 msg);
    void update_recoil_state(s32 msg);
    void state_circle_target(s32 msg);
    void execute_action(s32 msg);
    void play_pitched_cue();
    u16 get_active_id();
    void pick_hover_point();
    s32 can_attack_target();
    f32 approach_value(f32 current, f32 target);
    int was_hit_by_ranged();
    void clamp_flight_height();
    void store_position();
    void update_state_flag();
    void update_collide_flag();
    void circle_destination(s32 angle);
    void update_height_offset();
    void update();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    void init_child_params();
    static void release_shared_data();
    static TObjEneBm3Fly *create(TObjEneBm3FlyNest *nest, s32 entity_id, s32 set_index, const Vec *position, const Vec *velocity);
    static void load_resources();

    s32 step;                     // state work variables
    s32 counter;
    s32 pad_3c8;                  // set to -1 entering the orbit, never read
    union {
        s32 radius_wave;          // orbit: the orbit radius is 30 * cos(radius_wave / 2)
        s32 weave_angle;          // chase: the sideways weave
        s32 swept_angle;          // circle: how far round the target it has gone
    };
    union {
        s32 radius_wave_speed;    // orbit
        s32 circle_angle;         // circle: the angle circle_destination places it at
    };
    union {
        s32 orbit_angle;          // orbit: the angle around the nest
        s32 circle_speed;         // circle: circle_angle's step
    };
    union {
        s32 orbit_speed;          // orbit: orbit_angle's step
        s32 bob_angle;            // circle: the height bob
    };
    s32 pad_3dc;
    union {
        f32 waypoint_distance;    // launch: what is left to the waypoint
        f32 arrive_distance;      // return: back in the orbit inside this distance
        f32 vertical_speed;       // death fall
    };
    f32 slide_speed;              // death fall: the speed along move_dir
    union {
        Vec waypoint;             // launch: the point beside the nest it flies to
        Vec chase_velocity;       // chase
    };
    Vec chase_position;           // chase: where it would be without the weave, from position
    Vec weave_offset;             // chase
    Vec launch_velocity;          // launch: the velocity the nest sends it out with
    u16 owner_id;                 // the nest
    u8 pad_41a[0x2];
    Vec nest_position;
    s32 status_flags;             // BM3_FLY_*
    f32 flightY;
    Vec moveDir;
    f32 moveSpeed;
    s32 strike_count;             // attack: strikes so far, 4 end the attack
    f32 hover_height;             // the orbit's height: 45 + up to 2 above the nest
    s32 hover_angle;              // the random angle around the nest it launches and returns to
    f32 chase_height;             // update(): destination height above position while chasing
    f32 attack_height;            // update_height_offset(): the same while attacking
    s32 attacking;                // get_active_id() reports target_id while set
    TParticleCtrl *particle_effect;
    s32 alternate_phase;
    u8 pad_460[0x48];
    void update_dd_flag(f32 x, f32 z, f32 speed);
    void choose_attack();
};

LAYOUT_ASSERT(TObjEneBm3Fly_waypoint_offset, offsetof(TObjEneBm3Fly, waypoint) == 0x3E8);
LAYOUT_ASSERT(TObjEneBm3Fly_owner_id_offset, offsetof(TObjEneBm3Fly, owner_id) == 0x418);
LAYOUT_ASSERT(TObjEneBm3Fly_particle_effect_offset, offsetof(TObjEneBm3Fly, particle_effect) == 0x458);
LAYOUT_ASSERT(TObjEneBm3Fly_alternate_phase_offset, offsetof(TObjEneBm3Fly, alternate_phase) == 0x45C);
LAYOUT_ASSERT(TObjEneBm3Fly_size, sizeof(TObjEneBm3Fly) == 0x4A8);

#endif
