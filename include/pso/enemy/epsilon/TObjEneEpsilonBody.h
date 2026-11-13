#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILONBODY_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILONBODY_H
#include "types.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

class TParticleCtrl;

// Four per-slot or per-colour values, and the 20 rows of per-guard attack flags.
struct EpsilonGuardSlotValues { s32 v[4]; };
struct EpsilonGuardSlotValues16 { s16 v[4]; };
struct EpsilonGuardAttackPatterns { s32 v[20][4]; };

// The shared table TLobby::dispatch_shared_handler_a(0x23) returns for the body.
struct EpsilonBodySharedParams {
    u8 pad_00[0x4];
    f32 m_4;  // how far the fire travels per frame toward the target (action 2)
    f32 m_8;  // power of the fire explosion's direct attack (action 2)
    u8 pad_0C[0xC];
    s32 m_18;  // frames the fire travels before it stops (action 2)
    s32 m_1c;  // frames from stop to explosion (action 2)
    s32 m_20;  // reloads attack_pattern_timer
    s32 m_24;  // frames of rest after an attack pattern (action 4)
};

class TObjEneEpsilonBody : public TObjEneEpsilon {
public:
    TObjEneEpsilonBody(TObject *parent, void *set_data);
    virtual ~TObjEneEpsilonBody();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void init_params();
    void update_guard_flag();
    void sub_80361D4C(s32);
    void sub_803606A0(s32);
    void render_body_effect();
    void set_guard_state();
    void set_guard_part_colors(NJS_ARGB *color);
    s16 get_table_value_by_index();
    s16 sub_8035F8A8();
    virtual void run_task();
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void vfunc_28();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    void update_position();
    void tick_stun_timer();
    void tick_timer_set_flag();
    void update_fade(s32 reason);
    void action_destroy(s32 reason);
    TParticleCtrl *warp_emitter;  // particle emitter 0x220, created and moved by handle_warp_state
    TParticleCtrl *emitter;       // particle emitter 0x225 (TParticleCtrl enable/set_position)
    s32 flags;              // state bits; set_guard_state picks the model from flags & 0x2, update_guard_flag sets 0x80
    s16 guarded;            // 1 while flags & 0x2 shows the guarded model (set_guard_state)
    s16 color_index;        // index of the body colour lbl_80479CAC and of get_table_value_by_index
    s32 fire_phase_timer;   // counts down in action 2; tick_timer_set_flag sets flags & 0x8 at 0
    s32 guard_phase_timer;  // counts down in action 4; tick_stun_timer sets flags & 0x4 at 0
    s32 attack_pattern_timer;  // counts down to the next update_attack_pattern row
    u32 flash_level;        // 0..0xFF ramp of update_fade, the red of the action-8 model colour
    s32 fire_phase_frames;  // init_params, reloads fire_phase_timer
    s32 guard_phase_frames; // init_params, reloads guard_phase_timer
    f32 move_speed;  // speed handed to enemy_turn_and_move_on_ground
    s32 turn_step;   // max turn step handed to turn_toward_target_direction
    s32 guard_rotation_y[4];  // per guard: anchor angle, taken from the body's joint each frame (sub_803606A0) and handed to set_target
    Vec guard_position[4];    // per guard: anchor point, taken from the body's joint each frame (sub_803606A0) and handed to set_target
    NJS_ARGB color;  // copied from lbl_80479CAC[color_index], written into the guard parts
    NJS_ARGB color_step;  // per-frame step from color toward lbl_80479CAC[color_index] (handle_warp_state)
    TUnk_80494938 fade;
    u16 guard_ids[4];  // entity ids of the four TObjEneEpsilonGuard it spawns
    s32 action_step;   // sub-step of the current action
    s32 action_timer;  // frame counter in most actions; the 0..3 phase of action 2 (m_4ec counts there)
    s32 m_4ec;
    s32 target_player;  // player index from get_player_data, 0xFFFF for none
    s32 m_4f4;
    f32 m_4f8;
    Vec fire_position;  // where action 2's fire travels to and explodes (create_fire_explosion_effect)
    Vec target_position;  // copied from the target player's position
};
typedef char TObjEneEpsilonBody_size[sizeof(TObjEneEpsilonBody) == 0x514 ? 1 : -1];

#endif
