#ifndef PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONDEMO_H
#define PSO_BOSS_GALGRYPHON_TBOSS5GRYPHONDEMO_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss5GryphonDemo : public TObject {
public:
    TBoss5GryphonDemo(TObject *parent, s32 *done_flag, f32 frame_step);
    virtual ~TBoss5GryphonDemo();
    virtual void run_task();
    virtual void render();

    f32 frame_step;  // the scripted camera's frame step
    f32 frame;       // its first frame
    s32 *done_flag;  // TBoss5Gryphon's work.demo_flag: the demo ends when it drops to 0
};

#endif
