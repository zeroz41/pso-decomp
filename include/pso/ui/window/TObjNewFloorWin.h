#ifndef PSO_UI_WINDOW_TOBJNEWFLOORWIN_H
#define PSO_UI_WINDOW_TOBJNEWFLOORWIN_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMenu;

class TObjNewFloorWin : public TObject {
public:
    TObjNewFloorWin(TObject *object, void *arg2);
    virtual ~TObjNewFloorWin();
    virtual void run_task();
public:
    void open_window();
    s32 state;
    TWindowMenu *window;
    s32 open_timer;
    s32 close_timer;
    char title[0x20];
    s32 client;
};

LAYOUT_ASSERT(TObjNewFloorWin_size, sizeof(TObjNewFloorWin) == 0x50);

extern "C" {
void fn_800740DC(void);
}

// --- C functions defined in TObjNewFloorWin.cpp ---
extern "C" {
void fn_800740DC(void);
}
// --- end of C functions

#endif
