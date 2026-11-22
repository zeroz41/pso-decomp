#ifndef PSO_UNK_TUNK_80494E10_H
#define PSO_UNK_TUNK_80494E10_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// The beam TObjEneNanoDrago fires (construct_beam_effect builds it).
class TUnk_80494E10 : public TObjCollidable {
public:
    virtual ~TUnk_80494E10();
    virtual void run_task();
    // Moves origin onto the ground straight below it; 0 when there is none.
    s32 snap_to_ground(Vec *origin);
    Vec pos;
    Vec vel;
    u8 unk_C4[0x18];
    f32 timer;
    TParticleCtrl *link0;
    TParticleCtrl *link1;
    Vec prev;
    s32 trail;
    s32 cnt;
    u16 owner;
    u8 unk_FE[0x2];
};
LAYOUT_ASSERT(TUnk_80494E10_size, sizeof(TUnk_80494E10) == 0x100);

#endif
