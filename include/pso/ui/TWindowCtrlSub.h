#ifndef PSO_UI_TWINDOWCTRLSUB_H
#define PSO_UI_TWINDOWCTRLSUB_H

#include "pso/TObject.h"
#include "types.h"

class TWindowCtrlSub : public TObject {
public:
    virtual ~TWindowCtrlSub();
    virtual void run_task();
public:
    static void run_task();
};

extern "C" {
void *TWindowCtrlSub__ct(void *arg0);
}

// --- C functions defined in TWindowCtrlSub.cpp ---
extern "C" {
void *TWindowCtrlSub__ct(void *window_ctrl_sub);
}
// --- end of C functions

#endif
