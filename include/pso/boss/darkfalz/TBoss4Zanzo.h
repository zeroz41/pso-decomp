#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "dolphin/mtx.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

// The block TBoss4Type2::spawn_afterimages fills for each afterimage it spawns; TBoss4Zanzo
// keeps a copy (copy_zanzo_params) and draws model/motion at pos until lifetime frames have passed.
struct TBoss4ZanzoParams {
    Vec pos;
    s32 rotation_y;
    NJS_TEXLIST *texlist;
    NJS_OBJECT *model;
    AnimationMotion *motion;
    f32 frame;       // draw_model_motion's frame argument
    f32 fade_start;  // render's value at age 0, moving to fade_end at lifetime; drawn while above 0.01
    f32 fade_end;
    s32 lifetime;    // frames until run_task queues its destruction
};

class TBoss4Zanzo : public TObject {
public:
    TBoss4Zanzo(TObject *parent, TBoss4ZanzoParams *params);
    virtual ~TBoss4Zanzo();
    virtual void render();
    virtual void run_task();

    TBoss4ZanzoParams params;
    s32 age;  // frames since the ctor
};

LAYOUT_ASSERT(TBoss4Zanzo_size, sizeof(TBoss4Zanzo) == 0x4C);

extern "C" {
void copy_zanzo_params(TBoss4ZanzoParams *dst, TBoss4ZanzoParams *src);
}

#endif
