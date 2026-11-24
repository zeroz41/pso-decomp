#ifndef PSO_UI_HUD_TNOWLOADING_H
#define PSO_UI_HUD_TNOWLOADING_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TParticleCtrl;

struct TNowLoading : public TObject {
    TNowLoading(TObject *parent, Vec *pos);
    virtual ~TNowLoading();
    // Effects run_task keeps in front of the camera; the destructor releases them.
    TParticleCtrl *m_particles[4];
    Vec m_position; // 65 units in front of the camera
    virtual void render();
    virtual void run_task();
    u8 pad_38[4];
};

LAYOUT_ASSERT(TNowLoading_size, sizeof(TNowLoading) == 0x3C);

#endif
