#ifndef PSO_UI_WINDOW_TWINDOWTIMER_H
#define PSO_UI_WINDOW_TWINDOWTIMER_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowTimer : public TWindowBase {
    TWindowTimer();
    virtual ~TWindowTimer();
    void ease_window_timer_position();
    virtual void render();
    virtual void run_task();
    u32 flags;  // bit 0: counter display (init_timer_window_layout) vs play time (_alt)
    void update_chat_parts();
    void draw(s32 arg1, s32 arg2);
    void set_time(u32 secs);
    static void draw_tab(s32 arg0, saddr arg1);
    static s32 create();
    static s32 create_alt();
    void copy_state(u8 *arg1);
    void throw_gogo_ball(s32 arg1, s32 arg2);
    void send_gogo_ball();
    static s16 get_timer_value(s32 i);
    static int *set_timer_value(int a0, int a1);
    static void bswap_6x79_gogo_ball(int);
};

LAYOUT_ASSERT(TWindowTimer_size, sizeof(TWindowTimer) == 0x64);

#endif
