#ifndef PSO_UI_WINDOW_TWINDOWTIMER_H
#define PSO_UI_WINDOW_TWINDOWTIMER_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowTimer : public TWindowBase {
    TWindowTimer();
    virtual ~TWindowTimer();
    static const char *class_name;
    void ease_window_timer_position();
    virtual void render();
    virtual void run_task();
    u32 flags;  // bit 0: counter display (init_timer_window_layout) vs play time (_alt)
    void update_chat_parts();
    void draw(s32 arg1, s32 arg2);
    void set_time(u32 secs);
    void draw_tab(WindowDrawContext *context);
    static TWindowTimer *create();
    static TWindowTimer *create_alt();
};

LAYOUT_ASSERT(TWindowTimer_size, sizeof(TWindowTimer) == 0x64);

// window_timer_layout_entries, the layout table window_timer_layout points at.
struct TimerWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};


#endif
