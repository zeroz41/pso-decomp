#ifndef PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H
#define PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowSimpleStatus : public TWindowBase {
    TWindowSimpleStatus(void *position, s32 client, u8 *descriptor);
    virtual ~TWindowSimpleStatus();
    static const char *class_name;
    void draw_background(WindowDrawContext *ctx);
    void apply_random_shake();
    void update_status_icons(void *);
    void start_hp_text_color_transition();
    void init_gauge_entry();
    void update_status_entry();
    s32 update_hp_gauge();
    s32 update_hp_entry();
    void update_hp_tp_level();
    s32 get_width();
    virtual void render();
    u32 shake_ticks; // frames apply_random_shake still shakes the window; set when HP drops
    virtual void run_task();
    static TWindowSimpleStatus *create(void *position, s32 client);
    TWindowBase *w[5]; // child windows; the dtor closes the first four
};

LAYOUT_ASSERT(TWindowSimpleStatus_size, sizeof(TWindowSimpleStatus) == 0x78);

#endif
