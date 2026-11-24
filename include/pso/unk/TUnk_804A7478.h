#ifndef PSO_UNK_TUNK_804A7478_H
#define PSO_UNK_TUNK_804A7478_H
#include "types.h"
#include "pso/unk/TUnk_804A7488.h"
#include "pso/system/NinjaTypes.h"

// A model part that plays one motion: TPlyPhotonChair's two seat halves.
class TUnk_804A7478 : public TUnk_804A7488 {
public:
    NJS_MOTION *motion;
    f32 frame;
    f32 frame_count;
    f32 speed;
    s32 state;  // 0 loop, 1 stopped, 2 play to the end and stop
    virtual void draw_model();
    virtual ~TUnk_804A7478();
    // Steps the frame back (forward) by speed, looping, or stops at the
    // first (last) frame in state 2.
    void play_backward();
    void play_forward();
    f32 get_frame();
    NJS_MOTION *get_motion();
    void stop();
    TUnk_804A7478();
    void reset();
    void set_motion(NJS_MOTION *motion);
    // frame_count = the motion's frame count.
    void set_frame_count_from_motion();
    void set_speed(f32 speed);
    void play_to_end();
};

LAYOUT_ASSERT(TUnk_804A7478Size, sizeof(TUnk_804A7478) == 0x1C);

#endif
