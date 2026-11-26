#ifndef PSO_UI_FRONTEND_TADFLOORLOADPRTGC_H
#define PSO_UI_FRONTEND_TADFLOORLOADPRTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"

// One particle emitter of the floor-load effect: where it sits, how it is turned, the particle it runs.
struct TAdFloorLoadPrtGCEmitter {
    Vec position;
    ParticleAngles angles;
    TObject *particle;
};

struct TAdFloorLoadPrtGC : public TObject {
    static const char *class_name;
    static const ParticleAngles emitter_angles[12];
    TAdFloorLoadPrtGC(TObject *parent);
    virtual ~TAdFloorLoadPrtGC();
    TAdFloorLoadPrtGCEmitter emitters[32];
    TObject *origin_particle;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdFloorLoadPrtGC_size, sizeof(TAdFloorLoadPrtGC) == 0x3A0);

extern const Vec floor_load_particle_positions[12];
extern const Vec origin_particle_position[1];
extern const ParticleAngles origin_particle_angles[1];

#endif
