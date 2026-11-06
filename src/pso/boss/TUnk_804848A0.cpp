#include "pso/boss/TUnk_804848A0.h"
#include "pso/system/task/TMainTask.h"

// Deferred code generation emits the functions in reverse order.

s32 volopt_fade_out_done;
s32 volopt_fade_in_done;

TUnk_804999E8::TUnk_804999E8(TObject *parent) : TObject(parent) {}

TUnk_804848B8::TUnk_804848B8(TObject *, VoloptFadeCallback on_done) : TUnk_804999E8(tl_fade) {
    this->on_done = on_done;
    alpha = 0.0f;
    color[0] = 255;
    color[1] = 255;
    color[2] = 255;
    volopt_fade_out_done = 0;
}

TUnk_804848B8::~TUnk_804848B8() {}

void TUnk_804848B8::run_task() {
    alpha += 8.0f;
    if (alpha >= 255.0f) {
        alpha = 255.0f;
        if (on_done != NULL) {
            on_done();
        } else {
            queue_destruction();
        }
        volopt_fade_out_done = 1;
    }
}

TUnk_804848A0::TUnk_804848A0(TObject *, VoloptFadeCallback on_done) : TUnk_804999E8(tl_fade) {
    this->on_done = on_done;
    alpha = 255.0f;
    color[0] = 255;
    color[1] = 255;
    color[2] = 255;
    volopt_fade_in_done = 0;
}

TUnk_804999E8::~TUnk_804999E8() {}

TUnk_804848A0::~TUnk_804848A0() {}

void TUnk_804848A0::run_task() {
    alpha -= 8.0f;
    if (alpha <= 0.0f) {
        alpha = 0.0f;
        if (on_done != NULL) {
            on_done();
        } else {
            queue_destruction();
        }
        volopt_fade_in_done = 1;
    }
}
