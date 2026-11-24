#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILONGUARD_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILONGUARD_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;
class TObjEneEpsilonBody;

// The guard's tuning values (TObjEneEpsilonGuard__movement_params, from the
// shared handler table, entry 0x24).
struct TObjEneEpsilonGuardParams {
    f32 orbit_radius;        // around the body (set_orbit_destination)
    f32 move_out_speed;      // state_move_out walks away from the body at this speed until orbit_radius + it
    f32 orbit_speed;         // distance per frame along the orbit (state_orbit)
    f32 attack_power;        // power of update_effect_attack's direct attack
    u8 pad_10[0x8];
    s32 attack_hold_frames;  // frames update_effect_attack holds the full-size effect
};

struct TObjEneEpsilonGuard : public TObjEneEpsilon {
    TObjEneEpsilonGuard(TObject *parent, TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle);
    virtual ~TObjEneEpsilonGuard();
    s32 test_flag_80();
    s32 is_following_body();
    void set_flag_2_and_clear_status();
    void state_fade_out(s32 msg);
    void state_move_out(s32 msg);
    void calc_joint_position(Vec *out, s32 joint);  // world position of joint's origin
    void update_guard_state();
    void update_effect_attack();
    void handle_event(s32);
    void render_guard_effect();
    virtual void update_body_colliders();
    virtual void check_collisions();
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void refresh_target();
    virtual void render();
    virtual void run_task();
    virtual void dispatch_action(u32 state, s32 msg);
    s32 state_step;        // sub-step of the current state (orbit 0/1/2; 1 once the break is done)
    s32 break_timer;       // frames counted in the break state
    s32 orbit_angle;       // angle around the body handed to set_orbit_destination
    s32 orbit_angle_step;  // added to orbit_angle each frame (state_orbit)
    TParticleCtrl *emitter;    // queued for destruction with the guard
    void *effect_model;        // BML model 3, drawn by render_guard_effect
    NJS_MOTION *effect_motion; // BML motion 3
    s32 effect_step;           // sub-step of update_effect_attack (grow, hold, shrink)
    s32 effect_timer;          // frames the effect is held (update_effect_attack)
    f32 effect_frame;          // motion frame of effect_motion
    f32 effect_scale;          // 0..1 scale of the effect model and of model_desc[1]
    TObjCollidable *collider;  // the second collision body (model_desc[1]), built in init_model_and_state
    Vec effect_anchor;         // filled by the camera-ctrl callback; the effects spawn there
    s32 flags;                 // state bits; bit 4 while it follows the body
    u16 body_id;               // entity id of the TObjEneEpsilonBody that spawned it
    u8 pad_472[0x4A];
    TUnk_80494938 fade;
    static TObjEneEpsilonGuard *create(TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle);
    void init_model_and_state();
    static s32 create_damage_font(s32 pos, s32 color, s32 life, s32 damage);
    static void free_shared_resources();
    static void load_assets();
    s32 is_guard_active();
    s32 is_state_flag_set();
    s32 is_guard_ready();
    void clear_and_flag_state();
    void set_flag_8_and_notify();
    void set_target(const Vec *pos, s32 angle, s32 reverse);
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void handle_message(s32 msg);
    void handle_break_state(s32 msg);
    void state_orbit(s32 msg);
    void update_center_position();
    s32 calc_angle_to_target();
    void set_orbit_destination(s32 angle);
    void render_with_fade(s32 detail);
};

LAYOUT_ASSERT(TObjEneEpsilonGuard_size, sizeof(TObjEneEpsilonGuard) == 0x4D8);

// Stat handles the guards' resource loader registers with TLobby.
extern player_stats *epsilon_guard_boss_stat_handle;
extern AttackParams *epsilon_guard_shared_handler_b;
extern ActorParamBlock *epsilon_guard_registered_object_handle;
extern TObjEneEpsilonGuardParams *TObjEneEpsilonGuard__movement_params;

#endif
