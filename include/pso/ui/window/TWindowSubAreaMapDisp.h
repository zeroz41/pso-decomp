#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H

#include "types.h"

class WindowHeading;
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;

struct TWindowSubAreaMapDisp : public TWindowBase {
    TWindowSubAreaMapDisp();
    virtual ~TWindowSubAreaMapDisp();
    static const char *class_name;
    f32 pan_x_speed;
    f32 pan_y_speed;
    f32 zoom_speed;
    s32 manual_scroll; // nonzero while the player scrolls and zooms the map by hand
    WindowHeading *heading;
    char *title;
    void update_manual_scroll();
    virtual void render();
    virtual void run_task();
    void update_visibility();
};

LAYOUT_ASSERT(TWindowSubAreaMapDisp_size, sizeof(TWindowSubAreaMapDisp) == 0x78);

struct WindowDrawContext;

extern "C" {
void TWindowSubStatusDisp__sub_80271A6C(s32 window, WindowDrawContext *context);
void fn_80271848(s32 window, WindowDrawContext *context);
}

#endif
