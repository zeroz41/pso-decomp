#ifndef PSO_UI_WINDOW_TWINDOWCHALLENGERESULT_H
#define PSO_UI_WINDOW_TWINDOWCHALLENGERESULT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowChallengeResult : public TWindowBase {
    virtual ~TWindowChallengeResult();
    virtual void render();

    u8 unk_1C[0x4C];
};

typedef char TWindowChallengeResult_size[sizeof(TWindowChallengeResult) == 0x68 ? 1 : -1];

extern "C" {
void *dt__22TWindowChallengeResultFPvs(void *arg0, s16 arg1);
void init_subwindow__22TWindowChallengeResultFPv(void *p);
}

// --- C functions defined in TWindowChallengeResult.cpp ---
extern "C" {
void *dt__22TWindowChallengeResultFPvs(void *arg0, s16 arg1);
void init_subwindow__22TWindowChallengeResultFPv(void *p);
}
// --- end of C functions

#endif
