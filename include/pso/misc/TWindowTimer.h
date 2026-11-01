#ifndef PSO_MISC_TWINDOWTIMER_H
#define PSO_MISC_TWINDOWTIMER_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowTimer : public TWindowBase {
    virtual ~TWindowTimer();
    void ease_window_timer_position();
    virtual void render();
    virtual void run_task();
    u8 _pad1C[0x8];
    void* m_24;
    u8 unk_28[0x1C];
    f32 m_44;
    u8 unk_48[0x4];
    f32 m_4c;
    u8 unk_50[0x10];
    u32 m_60;
    void update_chat_parts();
    void draw(s32 arg1, s32 arg2);
    void set_time(u32 secs);
    static void draw_tab(s32 arg0, s32 arg1);
    static s32 create();
    static s32 create_alt();
    void copy_state(u8 *arg1);
    void throw_gogo_ball(s32 arg1, s32 arg2);
    void send_gogo_ball();
    static s16 get_timer_value(s32 i);
    static int set_timer_value(int a0, int a1);
};

typedef char TWindowTimer_size[sizeof(TWindowTimer) == 0x64 ? 1 : -1];

extern "C" {
u8 *TWindowTimer__ct(TWindowTimer *arg0);
void *__dt__12TWindowTimerFv(void *arg0, s16 arg1);
void render__12TWindowTimerFv(s32 arg0);
void run_task__12TWindowTimerFv(TWindowTimer *arg0);
}

#endif
