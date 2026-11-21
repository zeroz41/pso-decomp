#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EFFFLOWSOUL_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct Vec;

class TBoss6EffFlowSoul : public TObject {
public:
    u8 _pad1C[0x4];
 void* m_20;
    u8 pad_24[0x18];
public:
    TBoss6EffFlowSoul(TObject *parent, Vec *pos, s32 player, s32 duration);
    virtual ~TBoss6EffFlowSoul();
    virtual void run_task();
};

#endif
