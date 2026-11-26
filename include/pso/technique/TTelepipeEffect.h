#ifndef PSO_TECHNIQUE_TTELEPIPEEFFECT_H
#define PSO_TECHNIQUE_TTELEPIPEEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;
class TTelepipeMarker;

// The visual of a telepipe (TTecLuker, TObjLuker): three looping particle effects on the ground
// below it, tinted by the owner's slot, and a marker above it. run_task pauses them while every
// player (or the camera) is far away.
class TTelepipeEffect : public TObject {
public:
    TTelepipeEffect(Vec *pos, u32 owner, TObject *parent);
    virtual ~TTelepipeEffect();
    virtual void run_task();
    TParticleCtrl *particles[3];
    TTelepipeMarker *marker;  // only outside split screen
    Vec pos;
    Vec ground_pos;  // csnVecterUnder(pos), else pos
};
LAYOUT_ASSERT(TTelepipeEffect_size, sizeof(TTelepipeEffect) == 0x44);

#endif
