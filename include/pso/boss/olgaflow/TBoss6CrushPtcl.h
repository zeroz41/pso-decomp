#ifndef PSO_BOSS_OLGAFLOW_TBOSS6CRUSHPTCL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6CRUSHPTCL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss6CrushPtcl : public TObject {
public:
    virtual ~TBoss6CrushPtcl();
    virtual void run_task();

    s32 m_1C;
    uaddr m_20;
    uaddr m_24;
public:
    void *create();
};

#endif
