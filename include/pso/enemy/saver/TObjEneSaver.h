#ifndef PSO_ENEMY_SAVER_TOBJENESAVER_H
#define PSO_ENEMY_SAVER_TOBJENESAVER_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/TUnk_80490470.h"

struct TObjPlayer;
struct TEneParticleCtrl;
class TAttackTraceStrip;

// What TObjEnemy::movementParameters points at for a Saver (saver_move_params): the GibblesMoveParams layout.
struct SaverMoveParams {
    f32 radius;      // refresh_target only picks targets within it
    f32 speed;       // dash speed of the attack, and the reach added to the body radius on the walk in
    s32 turn_speed;  // largest heading change per frame
    s32 pad_0C[4];
};

struct TObjEneSaver : public TObjEnemy {
    virtual ~TObjEneSaver();
    static void free_resources();
    void turn_toward_target();
    void step_angle_clamped(s32 angle);
    void state_appear();
    void state_jump_attack();
    void run_demo_task();
    void state_defence();
    void state_nail();
    void state_attack();
    void damage_targets_in_reach();
    void update_collapse_and_destroy();
    virtual void run_task();
    virtual void render();
    void select_model_record(s32 i);
    void init_render_flags();
    void state_disappear();
    void advance_motion_state();
    void update_move_toward_target();
    void update_knockback_state();
    void update_entry_motion();
    void calc_move_state();
    void update_particle_effect();
    void apply_lookup_entry_effect();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual s32 is_target_in_attack_range();
    virtual int test_flag_256();
    virtual void run_miss_reaction();
    virtual void run_death_reaction();
    virtual void *get_center();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_hit_reaction();
    TObjEneSaver(TObject *parent, void *set_data);
    virtual void refresh_target();
    u32 state_flags;
    s32 parameter_mask;
    s16 attack_index;
    s16 step_counter;
    u32 particle_type;
    u32 particle_type_b;
    s16 guard_hp;
    s16 guard_hp_max;
    TObjPlayer *last_attacker;
    Vec particle_position;
    s32 facing_angle;
    TEneParticleCtrl *particle_ctrl;
    TUnk_80490470 body_fade;
    TAttackTraceStrip *attack_traces[3];
};

LAYOUT_ASSERT(TObjEneSaver_size, sizeof(TObjEneSaver) == 0x3CC);
LAYOUT_ASSERT(TObjEneSaver_state_flags, offsetof(TObjEneSaver, state_flags) == 0x374);
LAYOUT_ASSERT(TObjEneSaver_body_fade, offsetof(TObjEneSaver, body_fade) == 0x3A4);
LAYOUT_ASSERT(TObjEneSaver_attack_traces, offsetof(TObjEneSaver, attack_traces) == 0x3C0);
#endif
