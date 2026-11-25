#ifndef PSO_UI_WINDOW_WINDOWTEXTENTRY_H
#define PSO_UI_WINDOW_WINDOWTEXTENTRY_H

#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"

struct WindowDrawContext;
struct TextLayoutRecord;

// A text label part of a window entry list (case 3 of init_window_layout_entries): filled by
// set_text_entry_string, revealed by update and drawn by render.
class WindowTextEntry : public TWindowLayoutRect {
public:
    f32 depth;          // added to the context depth for the text scale
    f32 reveal_pos;     // characters revealed so far; a huge value = fully shown
    char *text;
    s32 color;
    f32 reveal_step;    // reveal_pos growth per tick

    WindowTextEntry(TextLayoutRecord *rec, s32 client);
    virtual ~WindowTextEntry();
    virtual void update();
    virtual void render(WindowDrawContext *context);
};

LAYOUT_ASSERT(WindowTextEntry_size, sizeof(WindowTextEntry) == 0x2C);

extern "C" {
// WindowTextEntry::WindowTextEntry(TextLayoutRecord *, s32). The class leaves the pure
// TWindowLayoutEntry::calc_bar_width slot empty (its vtable holds 0 there), so the layout
// builder allocates it and calls the constructor by hand, as it does for TWindowLayoutRect.
void *__ct__15WindowTextEntryFP16TextLayoutRecordl(void *p, TextLayoutRecord *rec, s32 client);
}
#endif
