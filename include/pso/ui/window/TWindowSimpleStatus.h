#ifndef PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H
#define PSO_UI_WINDOW_TWINDOWSIMPLESTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

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

// simple_status_window_layout_entries, the layout table simple_status_window_layout
// points at (frame sprite, two text/value entries, the HP and TP gauges, three icon sprites).
struct SimpleStatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    LayoutEntryCopyRecord rec_4;
    SpritePartLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    SpritePartLayoutRecord rec_7;
};


#endif
