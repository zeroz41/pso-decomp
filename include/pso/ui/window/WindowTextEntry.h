#ifndef PSO_UI_WINDOW_WINDOWTEXTENTRY_H
#define PSO_UI_WINDOW_WINDOWTEXTENTRY_H

#include "types.h"

struct WindowDrawContext;

// A text label part of a window entry list: built by construct_text_entry, filled by
// set_text_entry_string, drawn by render_text_entry.
class WindowTextEntry {
public:
    u16 flags;
    s16 m_2;
    virtual ~WindowTextEntry();
    virtual void update();
    virtual void render(WindowDrawContext *);
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    f32 m_18;
    f32 m_1c;
    char *text;
    s32 color;
    f32 m_28;
};

LAYOUT_ASSERT(WindowTextEntry_size, sizeof(WindowTextEntry) == 0x2C);
#endif
