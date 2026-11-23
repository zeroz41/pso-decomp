#ifndef PSO_SYSTEM_SCENE_TENDINGPIC_H
#define PSO_SYSTEM_SCENE_TENDINGPIC_H
#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

// The picture sequence state; 1 starts it (TEndingPic::advance_animation_state).
extern s32 TEndingPic__animation_state;

struct EndingPictureQuad {
    f32 left, top, right, bottom;
    f32 u0, v0, u1, v1;
};

class TEndingPic : public TObject {
public:
    TEndingPic(TObject *parent);
    virtual ~TEndingPic();
    virtual void run_task();
    virtual void render();

    void advance_animation_state();
    void draw_current_pic();
    void init_positions();

    s32 elapsed_ticks;
    s32 field_20;
    s32 next_picture;
    s32 picture_pair;
    EndingPictureQuad quads[6];
    s32 timing_rate;
};

LAYOUT_ASSERT(TEndingPicQuads, offsetof(TEndingPic, quads) == 0x2C);
LAYOUT_ASSERT(TEndingPicRate, offsetof(TEndingPic, timing_rate) == 0xEC);
LAYOUT_ASSERT(TEndingPic_size, sizeof(TEndingPic) == 0xF0);

#endif
