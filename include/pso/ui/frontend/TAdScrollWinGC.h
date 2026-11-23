#ifndef PSO_UI_FRONTEND_TADSCROLLWINGC_H
#define PSO_UI_FRONTEND_TADSCROLLWINGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowDrawContext.h"

struct TWindowMessageLog;

// A scrolling text window (licence and trial agreements, lobby text): a
// message log window filled with the mode's text lines, scrolled with the
// C stick, with its scroll marker drawn at the bottom right.
class TAdScrollWinGC : public TObject {
public:
    TAdScrollWinGC(TObject *parent, s32 mode, s32 text);
    virtual ~TAdScrollWinGC();
    virtual void run_task();
    virtual void render();

    void render_status_value();
    s32 get_scroll_delay_for_mode();
    void advance_scroll(f32 v);
    void close();
    void close_window();

    TexturedQuad m_marker;
    u32 m_alpha;
    TWindowMessageLog *m_window;
    u32 m_mode;
    u32 pad_48;
    s32 m_state;
    s32 m_close_timer;
};

extern const char *TAdScrollWinGC__class_name;

LAYOUT_ASSERT(TAdScrollWinGC_size, sizeof(TAdScrollWinGC) == 0x54);
#endif
