#ifndef PSO_UNK_TUNK_804CCA0C_H
#define PSO_UNK_TUNK_804CCA0C_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;

// The visual of a telepipe (TTecLuker, TObjLuker): three looping particle effects on the ground
// below it, tinted by the owner's slot, and a marker above it. run_task pauses them while every
// player (or the camera) is far away.
class TUnk_804CCA0C : public TObject {
public:
    TUnk_804CCA0C(Vec *pos, u32 owner, TObject *parent);
    virtual ~TUnk_804CCA0C();
    virtual void run_task();
    TParticleCtrl *particles[3];
    void *marker;  // TTelepipeMarker marker, only outside split screen
    Vec pos;
    Vec ground_pos;  // csnVecterUnder(pos), else pos
};
LAYOUT_ASSERT(TUnk_804CCA0C_size, sizeof(TUnk_804CCA0C) == 0x44);

#endif
