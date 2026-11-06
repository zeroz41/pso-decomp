#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessagePage : public TWindowMessage {
    virtual ~TWindowMessagePage();
    s32 is_message_window_ready();
    s32 is_ready();
    void update_message();
    void set_message(void *msg, s32 flags);
    static u8 *create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void set_text(s32 a, s32 b, s32 c);
    void render();
    void run_task();
    u8 unk_90[0x4];
    u32 m_94;
};

typedef char TWindowMessagePage_size[sizeof(TWindowMessagePage) == 0x98 ? 1 : -1];

extern "C" {
u8 *TWindowMessagePage__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void *__dt__18TWindowMessagePageFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowMessagePage.cpp ---
extern "C" {
u8 *TWindowMessagePage__ct(u8 *window_message_page, s32 arg1, s32 arg2, s32 arg3);
}
// --- end of C functions

#endif
