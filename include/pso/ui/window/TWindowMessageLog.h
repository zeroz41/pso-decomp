#ifndef PSO_UI_WINDOW_TWINDOWMESSAGELOG_H
#define PSO_UI_WINDOW_TWINDOWMESSAGELOG_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct WindowScrollBar;

struct TWindowMessageLog : public TWindowMessage {
    TWindowMessageLog(s32 parent, s32 client);
    virtual ~TWindowMessageLog();
    void update_scroll_animation();
    void update_fade_offset();
    void clamp_scroll_offset();
    virtual void run_task();
    virtual void render();
    WindowScrollBar *scroll_bar;
    f32 m_94;
    s32 get_active_photon_object();
    void update_scroll_position();
    void append_line(s32 shared_text_buffer);
    void load_chat_history();
};

LAYOUT_ASSERT(TWindowMessageLog_size, sizeof(TWindowMessageLog) == 0x98);
#endif
