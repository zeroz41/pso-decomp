#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSHOCKWAVE_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONSHOCKWAVE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"

struct TBoss5Gryphon;
class TParticleCtrl;

// Gal Gryphon's ground shock wave: travels along a curve from the gryphon to the floor at the target, then bursts
// and leaves a tornado there.
struct TBoss5GryphonShockWave : public TObject {
    TBoss5GryphonShockWave(TObject *parent, TBoss5Gryphon *owner, Vec *origin, Vec *target, Vec *velocity,
                           u16 target_client_id);
    virtual ~TBoss5GryphonShockWave();
    virtual void render();
    virtual void run_task();
    static void release_particle_table();  // TBoss5Gryphon::cleanup's counterpart, empty
    static void select_particle_table();  // load_boss5_gryphon_resources picks the particle ids

    s32 state;  // 0 start, 1 travelling, 2 burst, 3 done
    s32 frame;
    s32 duration;  // frames to reach the target, at least 30
    u16 target_client_id;  // handed on to the tornado
    Vec position;  // on path at frame / duration
    TBoss5Gryphon *owner;
    TParticleCtrl *trail;
    CurvePathPoint path[3];  // origin, origin + velocity, target at floor height
};

LAYOUT_ASSERT(TBoss5GryphonShockWave_size, sizeof(TBoss5GryphonShockWave) == 0x70);

#endif
