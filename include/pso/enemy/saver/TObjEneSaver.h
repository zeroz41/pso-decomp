#ifndef PSO_ENEMY_SAVER_TOBJENESAVER_H
#define PSO_ENEMY_SAVER_TOBJENESAVER_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/TUnk_80490470.h"

struct TObjPlayer;
struct TEneParticleCtrl;
class TUnk_80494968;

struct TObjEneSaver : public TObjEnemy {
    virtual ~TObjEneSaver();
    void turn_toward_target();
    void sub_800A5FA8();
    void sub_800A4D9C();
    void update_collapse_and_destroy();
    virtual void run_task();
    virtual void render();
    void sub_800A7734(s32);
    void init_render_flags();
    void sub_800A62D4();
    void advance_motion_state();
    void update_move_toward_target();
    void update_knockback_state();
    void update_entry_motion();
    void calc_move_state();
    void sub_800A435C();
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
    TUnk_80494968 *attack_traces[3];
};

LAYOUT_ASSERT(TObjEneSaver_size, sizeof(TObjEneSaver) == 0x3CC);
LAYOUT_ASSERT(TObjEneSaver_state_flags, offsetof(TObjEneSaver, state_flags) == 0x374);
LAYOUT_ASSERT(TObjEneSaver_body_fade, offsetof(TObjEneSaver, body_fade) == 0x3A4);
LAYOUT_ASSERT(TObjEneSaver_attack_traces, offsetof(TObjEneSaver, attack_traces) == 0x3C0);
#endif
