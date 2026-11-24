#ifndef PSO_OBJECT_BASE_TMOTIONMODEL_H
#define PSO_OBJECT_BASE_TMOTIONMODEL_H
#include "types.h"
#include "pso/object/base/TDrawableModel.h"
#include "pso/system/NinjaTypes.h"

// A chunk model drawn posed by one motion at its current frame
// (TPlyPhotonChair's two seat halves).
class TMotionModel : public TDrawableModel {
public:
    NJS_MOTION *motion;
    f32 frame;
    f32 frame_count;
    f32 speed;
    s32 state;  // 0 loop, 1 stopped, 2 play to the end and stop
    virtual void draw_model();
    virtual ~TMotionModel();
    // Steps the frame back (forward) by speed, looping, or stops at the
    // first (last) frame in state 2.
    void play_backward();
    void play_forward();
    f32 get_frame();
    NJS_MOTION *get_motion();
    void stop();
    TMotionModel();
    void reset();
    void set_motion(NJS_MOTION *motion);
    // frame_count = the motion's frame count.
    void set_frame_count_from_motion();
    void set_speed(f32 speed);
    void play_to_end();
};

LAYOUT_ASSERT(TMotionModel_size, sizeof(TMotionModel) == 0x1C);

#endif
