#ifndef PSO_BOSS_TBOSS2JOINT_H
#define PSO_BOSS_TBOSS2JOINT_H

#include "types.h"
#include "pso/enemy/TObjEneDD.h"

// One of the ten shell segments TBoss2DeRolLe spawns along its body.
struct TBoss2Joint : public TObjEneDD {
    TBoss2Joint(TObject *parent, u16 entity_id, s32 set_index, const Vec *anchor, s32 joint_node,
                s32 color_target);
    virtual ~TBoss2Joint();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_28();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    virtual void vfunc_93();
    virtual s32 vfunc_104(f32);
    virtual void vfunc_105(s32 reason);
    void call_36A90_with_1();
    void init_joint_offset(s32 arg1);
    void update_position_history();
    s32 init_params();
    u8 pad_374[0x18];
    s32 m_38c;
    const Vec *anchor;  // run_task copies the joint's position from it (a TBoss2DeRolLe body point)
    u8 pad_394[0x4];
    s32 joint_node;     // from TBoss2DeRolLe's derolle_segment_joint_node_offsets
    s32 color_target;   // from TBoss2DeRolLe's boss2_derolle_segment_color_targets
    u8 pad_3a0[0x8];
    f32 m_3a8;
    u8 unk_3AC[0x10];
};

typedef char TBoss2Joint_size[sizeof(TBoss2Joint) == 0x3BC ? 1 : -1];

extern "C" {
void TBoss2Joint__sub_8003688C(u8 *arg0);
}

#endif
