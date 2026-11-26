#ifndef PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H
#define PSO_UI_WINDOW_TWINDOWSUBAREAMAPDISP_H

#include "types.h"

class WindowHeading;
#include "pso/ui/window/TWindowBase.h"

struct TWindowSubStatusDisp;
struct WindowDrawContext;
struct WindowDescriptor;

struct TWindowSubAreaMapDisp : public TWindowBase {
    static WindowDescriptor window_parameters;
    TWindowSubAreaMapDisp();
    virtual ~TWindowSubAreaMapDisp();
    static const char *class_name;
    f32 pan_x;
    f32 pan_y;
    f32 zoom;
    u32 map_open;
    WindowHeading *heading;
    char *title;
    void update_manual_scroll();
    virtual void render();
    virtual void run_task();
    void update_visibility();
    // The four pan arrows around the map.
    void draw_pan_arrows(WindowDrawContext *context);
    // "L Button / Zoom in" and "R Button / Zoom out".
    void draw_zoom_button_hints(WindowDrawContext *context);
};

LAYOUT_ASSERT(TWindowSubAreaMapDisp_size, sizeof(TWindowSubAreaMapDisp) == 0x78);


#endif
