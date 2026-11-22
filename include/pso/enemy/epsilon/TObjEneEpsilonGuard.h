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
    f32 orbit_radius;  // around the body (set_orbit_destination)
    f32 m_4;
    f32 m_8;
    f32 m_c;
    u8 pad_10[0x8];
    s32 m_18;
};

struct TObjEneEpsilonGuard : public TObjEneEpsilon {
    TObjEneEpsilonGuard(TObject *parent, TObjEneEpsilonBody *body, s32 entity_id, s32 set_index, const Vec *pos, s32 angle);
    virtual ~TObjEneEpsilonGuard();
    s32 sub_8035DD68();
    s32 sub_8035DD74();
    void sub_8035DEC0();
    void sub_8035E578(s32 msg);
    void sub_8035E8C0(s32 msg);
    void sub_803626A8(saddr, s32);
    void update_guard_state();
    void sub_8035EA90();
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
    s32 effect_step;           // sub-step of sub_8035EA90 (grow, hold, shrink)
    s32 effect_timer;          // frames the effect is held (sub_8035EA90)
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
    static s32 create_damage_font(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void free_shared_resources();
    static void load_assets();
    s32 is_guard_active();
    s32 is_state_flag_set();
    s32 is_guard_ready();
    void clear_and_flag_state();
    void set_flag_8_and_notify();
    void set_target(saddr pos, s32 angle, s32 arg3);
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void handle_message(s32 arg1);
    void handle_break_state(s32 msg);
    void state_orbit(s32 msg);
    void update_center_position();
    s32 calc_angle_to_target();
    void set_orbit_destination(s32 angle);
    void render_with_fade(s32 detail);
};

LAYOUT_ASSERT(TObjEneEpsilonGuard_size, sizeof(TObjEneEpsilonGuard) == 0x4D8);

// Stat handles the guards' resource loader registers with TLobby.
extern u8 *epsilon_guard_boss_stat_handle;
extern u8 *epsilon_guard_shared_handler_b;
extern u8 *epsilon_guard_registered_object_handle;

#endif
