#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZANZO_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "dolphin/mtx.h"

// The block TBoss4Type2::spawn_afterimages fills for each afterimage it spawns; TBoss4Zanzo
// keeps a copy (fn_8005586C) and draws model/motion at pos until lifetime frames have passed.
struct Zanzo_8005676C {
    Vec pos;
    s32 rotation_y;
    s32 unk_10;    // TObjFish__sub_8001EDB0(bml, index); render passes it to TObjFish::set_global_param
    void *model;   // get_bml_model
    void *motion;  // get_bml_motion
    f32 unk_1c;    // draw_model_motion's frame argument
    f32 unk_20;    // render's value at age 0, moving to unk_24 at lifetime; drawn while above 0.01
    f32 unk_24;
    s32 lifetime;  // frames until run_task queues its destruction
};

class TBoss4Zanzo : public TObject {
public:
    TBoss4Zanzo(TObject *parent, Zanzo_8005676C *params);
    virtual ~TBoss4Zanzo();
    virtual void render();
    virtual void run_task();

    Zanzo_8005676C params;
    s32 age;  // frames since the ctor
};

typedef char TBoss4Zanzo_size[sizeof(TBoss4Zanzo) == 0x4C ? 1 : -1];

extern "C" {
void sub_80056998__11TBoss4Type2Fv(u8 *arg0);
void TBoss4Type2__sub_80056B3C(void *arg0, s32 lo, s32 hi);
f32 compute_wave_offset__11TBoss4Type2Ff(f32 farg0);
void fn_8005586C(Zanzo_8005676C *dst, Zanzo_8005676C *src);
}

#endif
