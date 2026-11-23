#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNING_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONLIGHTNING_H

#include "pso/math/CurvePathPoint.h"
#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

class TBoss5GryphonLightning : public TObject {
public:
    TBoss5GryphonLightning(TObject *parent, Vec *pos, f32 scale);
    virtual ~TBoss5GryphonLightning();
    void get_end_position(Vec *out);
    void get_start_position(Vec *out);
    void update_endpoints();  // start/end follow the curve through segments at life/grow progress
    void spawn_gryphon_lightning();

    f32 scale;
    Vec start;
    Vec end;
    TParticleCtrl *effects[4];  // 0x20C and 0x20E at start, 0x20F and 0x216 at end
    CurvePathPoint segments[4];
    f32 life_progress;  // age / life frames in TBoss5GryphonLightningWing::run_task
    f32 grow_progress;  // age / grow frames there; the horn starts fully grown
    s32 segment_count;
    s32 age;  // frames; spawn_gryphon_lightning steps it
};

#endif
