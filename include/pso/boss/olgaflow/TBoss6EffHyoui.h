#ifndef PSO_BOSS_OLGAFLOW_TBOSS6EFFHYOUI_H
#define PSO_BOSS_OLGAFLOW_TBOSS6EFFHYOUI_H

#include <stddef.h>
#include "pso/system/task/TObject.h"

class TParticleCtrl;

class TBoss6EffHyoui : public TObject {
public:
    TBoss6EffHyoui(TObject *parent, u16 client, s32 effect, s32 duration);
    virtual ~TBoss6EffHyoui();
    virtual void run_task();
    static TBoss6EffHyoui *create(u16 client, s32 effect, s32 duration);

    TParticleCtrl *emitter;
    u16 client;
    s32 duration;
    s32 age;
};

typedef char TBoss6EffHyouiSize[sizeof(TBoss6EffHyoui) == 0x2C ? 1 : -1];
typedef char TBoss6EffHyouiClientOffset[offsetof(TBoss6EffHyoui, client) == 0x20 ? 1 : -1];
typedef char TBoss6EffHyouiDurationOffset[offsetof(TBoss6EffHyoui, duration) == 0x24 ? 1 : -1];

#endif
