#ifndef PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H
#define PSO_UI_WINDOW_TWINDOWMESSAGEPAGE_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessagePage : public TWindowMessage {
    TWindowMessagePage(const NJS_POINT2 *position, s32 rows, s32 client);
    virtual ~TWindowMessagePage();
    static const char *class_name;
    s32 is_message_window_ready();
    s32 is_ready();
    void update_message();
    void set_message(void *msg, s32 flags);
    static u8 *create(const NJS_POINT2 *position, saddr extent, saddr rows, s32 client);
    static u8 *set_text(const NJS_POINT2 *position, saddr extent, saddr rows);
    void render();
    void run_task();
    s32 line_mode;
    const s8 *page_text;
};

LAYOUT_ASSERT(TWindowMessagePage_size, sizeof(TWindowMessagePage) == 0x98);


#endif
