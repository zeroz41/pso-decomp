#ifndef PSO_UI_WINDOW_TWINDOWMESSAGELOG_H
#define PSO_UI_WINDOW_TWINDOWMESSAGELOG_H

#include "types.h"
#include "pso/ui/window/TWindowMessage.h"

struct TWindowMessageLog : public TWindowMessage {
    virtual ~TWindowMessageLog();
    void update_scroll_animation();
    void update_fade_offset();
    void clamp_scroll_offset();
    virtual void run_task();
    virtual void render();
    u8 unk_90[0x4];
    f32 m_94;
    static s32 get_active_photon_object();
    void update_scroll_position();
    void append_line(s32 arg1);
    void load_chat_history();
};

typedef char TWindowMessageLog_size[sizeof(TWindowMessageLog) == 0x98 ? 1 : -1];
#endif
