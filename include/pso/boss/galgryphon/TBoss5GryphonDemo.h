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
public:
    void draw_model(void* a1, s32 a2);
    void set_all_entry_flags();
public:
    int get_state();
    void draw_linked_model(void* position, s32 yaw);

    f32 frame_step;  // the scripted camera's frame step
    f32 frame;       // its first frame
    s32 *done_flag;  // TBoss5Gryphon's work.demo_flag: the demo ends when it drops to 0
};

extern "C" {
void TBoss5GryphonDemo__sub_8006626C(void *p);
}

#endif
