#ifndef PSO_BOSS_TBOSS2MINE_H
#define PSO_BOSS_TBOSS2MINE_H

#include "types.h"
#include "pso/enemy/TObjEneDD.h"

struct TBoss2Mine : public TObjEneDD {
    TBoss2Mine(s32 ene_dd, s16 arg2, s16 arg3, s32 arg4);
    virtual ~TBoss2Mine();
    void set_node_offsets();
    void init_params(s32, f32);
    void update_pulse_state();
    virtual void vfunc_105(s32);
    virtual void vfunc_106(s32);
    virtual void vfunc_107(s32);
    virtual void vfunc_108(s32);
    virtual void vfunc_109();
    virtual void vfunc_110();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void apply_defense_stat_status(void *);
    void apply_attack_stat_status(void *);
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void vfunc_28();
    u8 _pad390[0x20];
    u32 m_3b0;
    u8 _pad3B4[0x14];
    u32 m_3c8;
    u32 m_3cc;
    void set_launch_position_velocity(u8 *arg1, u8 *arg2);
    void *deleting_dtor(s16 arg1);
    void render();
    void set_state_by_distance(s32 arg1);
    void update_move_flag();
    void save_position();
    void run_task();
};

#endif
