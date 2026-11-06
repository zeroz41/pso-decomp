#ifndef PSO_UI_TFONTSMALLTASK_H
#define PSO_UI_TFONTSMALLTASK_H

#include "pso/TObject.h"
#include "types.h"

class TFontSmallTask : public TObject {
public:
    virtual ~TFontSmallTask();
    virtual void render();
    virtual void run_task();
    f32 position[3];
    f32 offset_x, offset_y;
    f32 text_width;
    char text[16];
    u32 rgb;
    s32 age, lifetime, delay;
    s16 active;
    u16 view;
public:
    s32 get_task_id();
};

extern "C" {
void TBoss3Volopt__sub_800FD344(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4);
s32 create_font_small_task(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5, s32 arg6);
s32 create_font_small_task_default_color(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 arg5);
void fn_800FCCC8(s32 arg0, s32 arg1);
s32 fn_800FCCF4(void *p);
}

#endif
