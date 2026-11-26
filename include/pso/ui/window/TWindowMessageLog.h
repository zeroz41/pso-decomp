#ifndef PSO_UI_WINDOW_TWINDOWMESSAGELOG_H
#define PSO_UI_WINDOW_TWINDOWMESSAGELOG_H

#include "types.h"

struct NJS_POINT2;
#include "pso/ui/window/TWindowMessage.h"

struct WindowScrollBar;

struct TWindowMessageLog : public TWindowMessage {
    TWindowMessageLog(const NJS_POINT2 *position, s32 client);
    virtual ~TWindowMessageLog();
    static const char *class_name;
    void update_scroll_animation();
    void update_fade_offset();
    void clamp_scroll_offset();
    virtual void run_task();
    virtual void render();
    WindowScrollBar *scroll_bar;
    f32 pending_scroll;
    static char *get_active_photon_object(u16 id);
    void update_scroll_position();
    void append_line(s32 shared_text_buffer);
    void load_chat_history();
};

LAYOUT_ASSERT(TWindowMessageLog_size, sizeof(TWindowMessageLog) == 0x98);
u8 *create_message_log_window(const NJS_POINT2 *position, saddr extent, s32 client);
extern "C" {
void post_chat_log_message(u16 id, const char *text);
}

#endif
