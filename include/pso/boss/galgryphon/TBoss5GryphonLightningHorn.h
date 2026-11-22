#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNINGHORN_H
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "types.h"

class TBoss5GryphonLightningHorn : public TBoss5GryphonLightning {
public:
    TBoss5GryphonLightningHorn(TObject *parent, Vec *pos, s32 rotation_y);
    virtual ~TBoss5GryphonLightningHorn();
    void rebuild_lightning_segments();
    virtual void run_task();
    virtual void render();
    void queue_destruction();
    static TBoss5GryphonLightningHorn *spawn_ground_lightning(TObject *parent, Vec *pos, s32 rotation_y);

    Vec velocity;  // 5 units along rotation_y
    s32 rotation_y;
};

extern const char *TBoss5GryphonLightningHorn__name;

// Called by TBoss5GryphonLightningHorn::run_task with the horn.
extern "C" void fn_80325F7C(void *self);

#endif
