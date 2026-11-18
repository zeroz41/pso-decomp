#ifndef PSO_UNK_TUNK_80488AF0_H
#define PSO_UNK_TUNK_80488AF0_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// Turns the camera's look-at point towards a goal over a number of frames, holds it, then
// destroys itself (TCameraCtrl::create(long, long, long) spawns it). Field names inferred.
class TUnk_80488AF0 : public TObject {
public:
    TUnk_80488AF0(Vec *goal, s32 frames, s32 hold_frames, TObject *parent);
    virtual ~TUnk_80488AF0();
    virtual void run_task();
    f32 step;           // distance look_at moves per frame
    u16 frame;
    u16 pan_frames;
    u16 hold_frames;
    u8 pad_26[0x2];
    Vec look_goal;
    Vec look_at;
};
typedef char TUnk_80488AF0_size[sizeof(TUnk_80488AF0) == 0x40 ? 1 : -1];

#endif
