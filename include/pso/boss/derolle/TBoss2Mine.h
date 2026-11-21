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
    void init(s32 variant);
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
    void set_launch_position_velocity(u8 *arg1, u8 *arg2);
    void render();
    void set_state_by_distance(s32 arg1);
    void update_move_flag();
    void save_position();
    void run_task();

    u8 unk_374[0x8];
    f32 m_37c;
    u8 unk_380[0xC];
    u32 m_38c;
    Vec m_390;
    Vec m_39c;
    s32 m_3a8;
    f32 m_3ac;
    u32 m_3b0;
    f32 m_3b4;
    f32 m_3b8;
    s32 m_3bc;
    s32 m_3c0;
    s32 m_3c4;
    s32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    u8 unk_3D4[0x4];
    s32 m_3d8;
    f32 m_3dc;
    f32 m_3e0;
    f32 m_3e4;
    f32 m_3e8;
    f32 m_3ec;
};
LAYOUT_ASSERT(TBoss2Mine_size, sizeof(TBoss2Mine) == 0x3F0);

#endif
