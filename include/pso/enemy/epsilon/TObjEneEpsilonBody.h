#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILONBODY_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILONBODY_H
#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

class TParticleCtrl;
struct NJS_OBJECT;

// Four per-slot or per-colour values, and the 20 rows of per-guard attack flags.
struct EpsilonGuardSlotValues { s32 v[4]; };
struct EpsilonGuardSlotValues16 { s16 v[4]; };
struct EpsilonGuardAttackPatterns { s32 v[20][4]; };

// The shared table TLobby::dispatch_shared_handler_a(0x23) returns for the body.
struct EpsilonBodySharedParams {
    u8 pad_00[0x4];
    f32 fire_step;            // how far the fire travels per frame toward the target (action 2)
    f32 fire_power;           // power of the fire explosion's direct attack (action 2)
    u8 pad_0C[0xC];
    s32 fire_travel_frames;   // frames the fire travels before it stops (action 2)
    s32 fire_fuse_frames;     // frames from stop to explosion (action 2)
    s32 attack_pattern_frames;  // reloads attack_pattern_timer
    s32 rest_frames;          // frames of rest after an attack pattern (action 4)
};

class TObjEneEpsilonBody : public TObjEneEpsilon {
public:
    TObjEneEpsilonBody(TObject *parent, void *set_data);
    virtual ~TObjEneEpsilonBody();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void init_params();
    void update_guard_flag();
    void handle_wait_state(s32);
    void update_guard_anchor(s32);
    void render_body_effect();
    void set_guard_state();
    void set_guard_part_colors(NJS_ARGB *color);
    s16 get_table_value_by_index();
    s16 get_immune_special_kind();  // per colour; a weapon special of this kind does no damage
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void check_collisions();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    void update_position();
    void tick_stun_timer();
    void tick_timer_set_flag();
    void update_fade(s32 reason);
    void action_destroy(s32 reason);
    // dispatch_action's handlers, one per state.
    void handle_fade_in_state(s32 reason);
    void handle_fire_state(s32 reason);
    void handle_guard_action_state(s32 reason);
    void action(s32 reason);
    void handle_pre_warp_state(s32 reason);
    void handle_warp_state(s32 reason);
    void handle_return_home_state(s32 reason);
    void draw_with_fade(s32 detail);
    void draw_debug_line();
    static void record_camera_angle_samples(NJS_OBJECT *);
    void update_attack_pattern();
    u32 select_slot_target(s32 slot);
    s32 all_guards_ready();
    s32 all_children_gone();
    s32 all_guard_state_flags_set();
    s32 all_guards_active();
    void update_flag_20();
    s32 notify_guards_if_ready();
    void set_guards_flag_2();
    s32 assign_guard_targets();
    static s32 is_orbit_paused();  // always 0; the guards stop orbiting while it returns 1
    s32 test_flag_20();
    s32 test_flag_800();
    void clear_guard_state_flag(s32 slot);
    TParticleCtrl *warp_emitter;  // particle emitter 0x220, created and moved by handle_warp_state
    TParticleCtrl *emitter;       // particle emitter 0x225 (TParticleCtrl enable/set_position)
    s32 flags;              // state bits; set_guard_state picks the model from flags & 0x2, update_guard_flag sets 0x80
    s16 guarded;            // 1 while flags & 0x2 shows the guarded model (set_guard_state)
    s16 color_index;        // index of the body colour epsilon_body_colors and of get_table_value_by_index
    s32 fire_phase_timer;   // counts down in action 2; tick_timer_set_flag sets flags & 0x8 at 0
    s32 guard_phase_timer;  // counts down in action 4; tick_stun_timer sets flags & 0x4 at 0
    s32 attack_pattern_timer;  // counts down to the next update_attack_pattern row
    u32 flash_level;        // 0..0xFF ramp of update_fade, the red of the action-8 model colour
    s32 fire_phase_frames;  // init_params, reloads fire_phase_timer
    s32 guard_phase_frames; // init_params, reloads guard_phase_timer
    f32 move_speed;  // speed handed to enemy_turn_and_move_on_ground
    s32 turn_step;   // max turn step handed to turn_toward_target_direction
    s32 guard_rotation_y[4];  // per guard: anchor angle, taken from the body's joint each frame (update_guard_anchor) and handed to set_target
    Vec guard_position[4];    // per guard: anchor point, taken from the body's joint each frame (update_guard_anchor) and handed to set_target
    NJS_ARGB color;  // copied from epsilon_body_colors[color_index], written into the guard parts
    NJS_ARGB color_step;  // per-frame step from color toward epsilon_body_colors[color_index] (handle_warp_state)
    TUnk_80494938 fade;
    u16 guard_ids[4];  // entity ids of the four TObjEneEpsilonGuard it spawns
    s32 action_step;   // sub-step of the current action
    s32 action_timer;  // frame counter in most actions; the 0..3 phase of action 2 (fire_timer counts there)
    s32 fire_timer;    // frames left in the current fire phase of action 2 (fire_travel_frames, fire_fuse_frames, 30)
    s32 target_player;  // player index from get_player_data, 0xFFFF for none
    s32 target_slot;   // guard slot counter handed to select_slot_target, +1 per pick (action 2)
    f32 effect_scale;  // 0..1 x/z scale of the warp effect model (handle_warp_state, render_body_effect); action 2
                       // keeps the facing cosine toward its destination here
    Vec fire_position;  // where action 2's fire travels to and explodes (a TUnk_804CCB28 fire explosion)
    Vec target_position;  // copied from the target player's position
};
LAYOUT_ASSERT(TObjEneEpsilonBody_size, sizeof(TObjEneEpsilonBody) == 0x514);

// Stat handles and shared parameters the resource loader registers with TLobby for the body.
extern player_stats *epsilon_body_boss_stat_handle;
extern AttackParams *epsilon_body_shared_handler_b;
extern ActorParamBlock *epsilon_body_registered_object_handle;
extern EpsilonBodySharedParams *epsilon_body_shared_params;

#endif
