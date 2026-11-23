#ifndef PSO_BOSS_BARBARAY_TBOSS7JOINTBREAKUP_H
#define PSO_BOSS_BARBARAY_TBOSS7JOINTBREAKUP_H
#include "types.h"
#include "pso/boss/barbaray/TBoss7BreakUp.h"

// The breakup a TBoss7Joint starts: the pieces of its node (by joint index) of archive model 3.
class TBoss7JointBreakUp : public TBoss7BreakUp {
public:
    TBoss7JointBreakUp(TObject *parent, Vec *position, s32 index);
    virtual ~TBoss7JointBreakUp();
    void scale_node_positions();
    virtual void run_task();
    virtual void render();
};
LAYOUT_ASSERT(TBoss7JointBreakUp_size, sizeof(TBoss7JointBreakUp) == 0x2C);

#endif
