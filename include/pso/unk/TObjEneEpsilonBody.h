#ifndef PSO_UNK_TOBJENEEPSILONBODY_H
#define PSO_UNK_TOBJENEEPSILONBODY_H
#include "types.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"

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
    TObject *warp_emitter;  // 0x430: particle emitter 0x220, created and moved by handle_warp_state
    TObject *emitter;       // 0x434: particle emitter 0x225 (TParticleCtrl enable/set_position)
    s32 flags;              // 0x438: state bits; set_guard_state picks the model from bit 2, update_guard_flag sets 0x80
    s16 guarded;            // 0x43C: 1 while flags bit 2 shows the guarded model (set_guard_state)
    s16 color_index;        // 0x43E: index of the body colour lbl_80479CAC and of get_table_value_by_index
    s32 fire_phase_timer;   // 0x440: counts down in action 2; tick_timer_set_flag sets flags bit 8 at 0
    s32 guard_phase_timer;  // 0x444: counts down in action 4; tick_stun_timer sets flags bit 4 at 0
    s32 m_448;
    u32 flash_level;        // 0x44C: 0..0xFF ramp of update_fade, the red of the action-8 model colour
    s32 fire_phase_frames;  // 0x450: init_params, reloads fire_phase_timer
    s32 guard_phase_frames; // 0x454: init_params, reloads guard_phase_timer
    f32 move_speed;  // 0x458: speed handed to enemy_turn_and_move_on_ground
    s32 turn_step;   // 0x45C: max turn step handed to turn_toward_target_direction
    s32 guard_rotation_y[4];  // per guard: the rotation_y it was spawned with
    Vec guard_position[4];    // per guard: the position it was spawned at
    NJS_ARGB color;  // 0x4A0: copied from lbl_80479CAC[color_index], written into the guard parts
    u8 pad_4B0[0x10];
    TUnk_80494938 fade;
    u16 guard_ids[4];  // entity ids of the four TObjEneEpsilonGuard it spawns
    s32 action_step;   // 0x4E4: sub-step of the current action
    s32 action_timer;  // 0x4E8: per-action frame counter
    s32 m_4ec;
    s32 target_player;  // 0x4F0: player index from get_player_data, 0xFFFF for none
    s32 m_4f4;
    f32 m_4f8; // 0x4F8
    f32 m_4fc;
    f32 m_500;
    f32 m_504;
    Vec target_position;  // 0x508: copied from the target player's position
};
typedef char TObjEneEpsilonBody_size[sizeof(TObjEneEpsilonBody) == 0x514 ? 1 : -1];

#endif
