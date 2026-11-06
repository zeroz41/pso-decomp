#ifndef PSO_PLAYER_TUNK_804820C0_H
#define PSO_PLAYER_TUNK_804820C0_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"

// One flying piece of the De Rol Le breakup effects (TUnk_80482090, TUnk_804820A8).
// TObjPlayer__sub_8002EDCC moves it: state 0 falls (vel.y -= 0.2, angles spin), 1 sinks, 2 fades alpha, 3 done.
struct BreakupPiece {
    Vec pos;
    Vec vel;
    s32 ang_x;
    s32 spin;   // added to ang_x, twice to ang_z, each frame
    s32 ang_z;
    f32 alpha;
    s32 state;
};

class TUnk_804820C0 : public TObject {
public:
    TUnk_804820C0(TObject *parent);
    virtual ~TUnk_804820C0();
    s32 m_frames;  // the subclasses' run_task destroy the effect after 0xA0 frames
};

#endif
