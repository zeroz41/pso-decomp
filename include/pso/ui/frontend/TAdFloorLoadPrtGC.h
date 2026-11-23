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
    TAdFloorLoadPrtGC(TObject *parent);
    virtual ~TAdFloorLoadPrtGC();
    TAdFloorLoadPrtGCEmitter emitters[32];
    TObject *origin_particle;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdFloorLoadPrtGC_size, sizeof(TAdFloorLoadPrtGC) == 0x3A0);

extern const Vec floor_load_particle_positions[12];
extern const ParticleAngles TAdFloorLoadPrtGC__emitter_angles[12];
extern const Vec lbl_80478B48[1];
extern const ParticleAngles lbl_80478B54[1];
extern const char *TAdFloorLoadPrtGC__class_name;

extern "C" {
void fn_8034AD28(void);
void fn_8034AD2C(void);
}

#endif
