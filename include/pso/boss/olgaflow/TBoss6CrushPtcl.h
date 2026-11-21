#ifndef PSO_BOSS_OLGAFLOW_TBOSS6CRUSHPTCL_H
#define PSO_BOSS_OLGAFLOW_TBOSS6CRUSHPTCL_H

#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"

class TParticleCtrl;

class TBoss6CrushPtcl : public TObject {
public:
    TBoss6CrushPtcl(TObject *parent, Vec *point);
    virtual ~TBoss6CrushPtcl();
    virtual void run_task();

    s32 m_1C;
    TParticleCtrl *dust_emitter;
    TParticleCtrl *debris_emitter;

    static TBoss6CrushPtcl *create(Vec *point);
};

LAYOUT_ASSERT(CrushParticleSize, sizeof(TBoss6CrushPtcl) == 0x28);

#endif
