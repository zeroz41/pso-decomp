#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessagePage : public TWindowMessage {
    TWindowMessagePage(s32 parent, s32 rows, s32 client);
    virtual ~TWindowMessagePage();
    s32 is_message_window_ready();
    s32 is_ready();
    void update_message();
    void set_message(void *msg, s32 flags);
    static u8 *create(s32 parent, saddr extent, saddr rows, s32 client);
    static u8 *set_text(s32 a, s32 b, s32 c);
    void render();
    void run_task();
    u8 unk_90[0x4];
    uaddr m_94;
};

LAYOUT_ASSERT(TWindowMessagePage_size, sizeof(TWindowMessagePage) == 0x98);

extern "C" {
void *__dt__18TWindowMessagePageFv(void *arg0, s16 arg1);
}


#endif
