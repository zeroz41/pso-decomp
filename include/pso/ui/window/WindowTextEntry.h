#ifndef PSO_UI_WINDOW_WINDOWTEXTENTRY_H
#define PSO_UI_WINDOW_WINDOWTEXTENTRY_H

#include "types.h"

struct WindowDrawContext;

// A text label part of a window entry list: built by construct_text_entry, filled by
// set_text_entry_string, drawn by render_text_entry.
class WindowTextEntry {
public:
    u16 flags;
    s16 client;
    virtual ~WindowTextEntry();
    virtual void update();
    virtual void render(WindowDrawContext *);
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    f32 depth;
    f32 reveal_pos; // characters revealed so far; a huge value = fully shown
    char *text;
    s32 color;
    f32 reveal_step; // reveal_pos growth per tick
};

LAYOUT_ASSERT(WindowTextEntry_size, sizeof(WindowTextEntry) == 0x2C);
#endif
