#ifndef PSO_CAMERA_TCAMERAPAN_H
#define PSO_CAMERA_TCAMERAPAN_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// The quest cam_pan opcode (TCameraPan::create): turns the
// camera's look-at point toward a goal over a number of frames, holds it, then
// destroys itself.
class TCameraPan : public TObject {
public:
    TCameraPan(Vec *goal, s32 frames, s32 hold_frames, TObject *parent);
    static void create(Vec *goal, s32 frames, s32 hold_frames);
    virtual ~TCameraPan();
    virtual void run_task();
    f32 step; // distance look_at moves per frame
    u16 frame;
    u16 pan_frames;
    u16 hold_frames;
    u8 pad_26[0x2];
    Vec look_goal;
    Vec look_at;
};
LAYOUT_ASSERT(TCameraPan_size, sizeof(TCameraPan) == 0x40);

#endif
