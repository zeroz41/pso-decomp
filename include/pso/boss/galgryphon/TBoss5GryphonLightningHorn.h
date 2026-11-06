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
public:
    static void render();
};

#endif
