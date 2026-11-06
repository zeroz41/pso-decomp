#ifndef PSO_BOSS_OLGAFLOW_TBOSS6MAG_H
#define PSO_BOSS_OLGAFLOW_TBOSS6MAG_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TBoss6Mag : public TObjEnemy {
    virtual ~TBoss6Mag();
    void spawn_trap_by_stat();
    void sub_8033040C();
    void set_action(s32);
    void update_motion_playback();
    void change_motion(s32);
    void draw_model_motion_blend();
    void sync_hp();
    void sync_hp_apply_damage();
    void decay_glow_and_calc_hp_ratio();
    void spawn_falling_rocks();
    void update_rotation_ramp();
    s32 is_action_ready();
    s32 is_target_in_front_range();
    void sub_8032E8DC();
    void update_effect_positions();
    s32 is_phase_active();
    virtual f32 receive_physical_attack(void *, f32);
    virtual void vfunc_63();
    void render();
    void run_task();
    u32 m_390;
    u8 _pad394[0x2C];
    u32 m_3a4;
    u8 _pad3C4[0x44];
    void* m_3ec;
    u8 _pad40C[0x40];
    void* m_430;
    u8 _pad450[0x8];
    u32 m_43c;
    u8 unk_440[0x1C];
};

#endif
