#ifndef PSO_UI_WINDOW_TOBJNEWFLOORWIN_H
#define PSO_UI_WINDOW_TOBJNEWFLOORWIN_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct TWindowMenu;

class TObjNewFloorWin : public TObject {
public:
    TObjNewFloorWin(TObject *object, s32 client_id);
    virtual ~TObjNewFloorWin();
    virtual void run_task();
public:
    void open_window();

    s32 state;
    TWindowMenu *window;
    s32 wait_timer;     // 450 frames to wait for the window task root
    s32 display_timer;  // 150 frames shown; the window closes at 60
    char floor_text[0x20];  // "%s %02d" floor label
    s32 client_id;      // create_window_menu's client_id, -1 outside split screen
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
