#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6EffFlowSoul : public TObject {
public:
    u8 _pad1C[0x4];
 void* m_20;
public:
    virtual ~TBoss6EffFlowSoul();
    virtual void run_task();
};

extern "C" {
u8 *TBoss6EffFlowSoul__ct(u8 *boss6_eff_flow_soul, u8 *arg1, u8 *arg2, s16 arg3, s32 arg4);
}

#endif
