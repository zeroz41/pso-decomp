#ifndef PSO_OBJECT_TOBJLIVEMONITOR_H
#define PSO_OBJECT_TOBJLIVEMONITOR_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

// The big monitor of the Gol Dragon arena. Every few seconds it picks
// another screen: 0 the live camera's picture (TObjLiveCameraCtrl), 1-3
// animated pictures of its texture list, 4 the player's view.
class TObjLiveMonitor : public TObject {
public:
    TObjLiveMonitor(TObject *parent);
    virtual ~TObjLiveMonitor();
    void choose_next_screen();
    int render_live_monitor_screen();
    virtual void run_task();
    virtual void render();
    static void *create(TObject *parent);

    NJS_OBJECT *model;
    NJS_TEXLIST *texlist; // set_texlist before drawing a picture
    s32 screen;
    s32 screen_timer; // frames until choose_next_screen picks another screen
};

// The static resource hooks of the live camera controllers: clear the
// controller slots, and nothing.
void reset_live_camera_ctrl_globals(void);
void release_live_camera_ctrl_globals(void);
extern "C" {
void fn_8030B7B4(void);
void fn_8030B7B8(void);
}

#endif
