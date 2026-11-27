#ifndef PSO_UI_FRONTEND_TADLOADNETWORKGC_H
#define PSO_UI_FRONTEND_TADLOADNETWORKGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"

class TParticleCtrl;

struct TAdLoadNetworkGC : public TObject {
    static Angle3 object_offset_table[5];
    static const char *class_name;
    TAdLoadNetworkGC(TObject *parent, Vec *pos);
    virtual ~TAdLoadNetworkGC();
    u8 pad_1c[4];
    TParticleCtrl *particles[5]; // the five orbiting load effects
    Vec position;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdLoadNetworkGC_size, sizeof(TAdLoadNetworkGC) == 0x40);
#endif
