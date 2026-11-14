#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

class TBoss5GryphonLightningHorn : public TBoss5GryphonLightning {
public:
    virtual ~TBoss5GryphonLightningHorn();
    void rebuild_lightning_segments();
    virtual void run_task();
    virtual void render();
};

extern const char *TBoss5GryphonLightningHorn__name;

// Called by TBoss5GryphonLightningHorn::run_task with the horn.
extern "C" void fn_80325F7C(void *arg0);

#endif
