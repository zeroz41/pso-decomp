#include "pso/boss/TBoss3VoloptFadeIn.h"
#include "pso/system/task/TMainTask.h"

// Deferred code generation emits the functions in reverse order.

s32 volopt_fade_out_done;
s32 volopt_fade_in_done;

TScreenFade::TScreenFade(TObject *parent) : TObject(parent) {}

TBoss3VoloptFadeOut::TBoss3VoloptFadeOut(TObject *, VoloptFadeCallback on_done) : TScreenFade(tl_fade) {
    this->on_done = on_done;
    alpha = 0.0f;
    color[0] = 255;
    color[1] = 255;
    color[2] = 255;
    volopt_fade_out_done = 0;
}

TBoss3VoloptFadeOut::~TBoss3VoloptFadeOut() {}

void TBoss3VoloptFadeOut::run_task() {
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

TBoss3VoloptFadeIn::TBoss3VoloptFadeIn(TObject *, VoloptFadeCallback on_done) : TScreenFade(tl_fade) {
    this->on_done = on_done;
    alpha = 255.0f;
    color[0] = 255;
    color[1] = 255;
    color[2] = 255;
    volopt_fade_in_done = 0;
}

TScreenFade::~TScreenFade() {}

TBoss3VoloptFadeIn::~TBoss3VoloptFadeIn() {}

void TBoss3VoloptFadeIn::run_task() {
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
