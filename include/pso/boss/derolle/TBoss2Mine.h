#ifndef PSO_BOSS_DEROLLE_TBOSS2MINE_H
#define PSO_BOSS_DEROLLE_TBOSS2MINE_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"

struct TBoss2Mine : public TObjEneDD {
    // variant picks the row of the stat tables: 0 for the floor mines
    // (TUnk_80482EC0), 1 for the launched ones (TUnk_80482D04); inferred.
    TBoss2Mine(TObject *parent, u16 entity_id, s32 set_index, s32 variant);
    virtual ~TBoss2Mine();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_node_offsets();
    void init_params(s32, f32);
    void update_pulse_state();
    virtual void vfunc_104(s32);
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
    void render();
    void set_state_by_distance(s32 arg1);
    void update_move_flag();
    void save_position();
    void run_task();
};

extern "C" {
void vfunc_106__13TUnk_80482D04Fl(u8 *arg0, s32 arg1);
void vfunc_105__13TUnk_80482D04Fl(u8 *arg0, s32 arg1);
void vfunc_106__13TUnk_80482EC0Fl(u8 *arg0, s32 arg1);
void vfunc_105__13TUnk_80482EC0Fl(u8 *arg0, s32 arg1);
void init__10TBoss2MineFPvi(u8 *arg0, s32 arg1);
void init_launch__10TBoss2MineFPvPvii(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
}

#endif
