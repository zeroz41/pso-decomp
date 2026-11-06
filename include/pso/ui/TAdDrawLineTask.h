#ifndef PSO_UI_TADDRAWLINETASK_H
#define PSO_UI_TADDRAWLINETASK_H

#include "pso/TObject.h"

class TAdDrawLineCtrl;

union DrawLineColor {
    u32 value;
    struct {
        u8 alpha;
        u8 red;
        u8 green;
        u8 blue;
    } channels;
};

struct DrawLineVertex {
    f32 x;
    f32 y;
    f32 w;
    DrawLineColor color;
};

struct DrawLineRecord {
    s32 key;
    DrawLineVertex start;
    DrawLineVertex end;
    f32 speed;
    f32 width;
};

class TAdDrawLineTask : public TObject {
public:
    TAdDrawLineTask(TObject *parent, const DrawLineRecord *record, TAdDrawLineCtrl *controller);
    virtual ~TAdDrawLineTask();
    virtual void render();
    virtual void run_task();

    TAdDrawLineCtrl *controller;
    DrawLineRecord line;
    f32 frame;
    f32 duration;
    f32 step_x;
    f32 step_y;
    f32 step_w;
    DrawLineColor color_step;
    DrawLineVertex vertices[4];
    DrawLineColor color;
    f32 half_width_x;
    f32 half_width_y;
};

typedef char TAdDrawLineTaskSize[sizeof(TAdDrawLineTask) == 0xB0 ? 1 : -1];

#endif
