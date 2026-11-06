#ifndef PSO_BOSS_DEROLLE_TBOSS2TENTACLE_H
#define PSO_BOSS_DEROLLE_TBOSS2TENTACLE_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss2Tentacle : public TObject {
public:
    TBoss2Tentacle(TObject *parent, s32 arg2, s32 arg3);
    virtual ~TBoss2Tentacle();
    void sub_80039DA4();
    void sub_80039D88();
    virtual void render();
    virtual void run_task();
public:
    void advance_motion_position();
    void reset();
    void init_motion_from_table();
    void reset_segment_points();
    void start_attack_at_target(u8 *arg1, s32 arg2);
    void forward_80039DC8();
};

#endif
