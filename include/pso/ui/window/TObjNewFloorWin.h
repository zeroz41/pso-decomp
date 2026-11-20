#ifndef PSO_UI_WINDOW_TOBJNEWFLOORWIN_H
#define PSO_UI_WINDOW_TOBJNEWFLOORWIN_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "versions.h"

class TObjNewFloorWin : public TObject {
public:
#if VERSION == VERSION_GPOP8P
    TObjNewFloorWin(TObject *arg1);
#else
    TObjNewFloorWin(TObject *arg1, void *arg2);
#endif
    virtual ~TObjNewFloorWin();
    virtual void run_task();
public:
    void open_window();
};

extern "C" {
void fn_800740DC(void);
}

// --- C functions defined in TObjNewFloorWin.cpp ---
extern "C" {
void fn_800740DC(void);
}
// --- end of C functions

#endif
