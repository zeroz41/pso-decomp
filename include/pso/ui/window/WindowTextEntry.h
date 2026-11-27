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
    // Sets width and height from the text, wrapping lines at max_width.
    void measure_text(f32 max_width);
    char *get_text();
    // Shows the whole text at once (reveal_pos = 900000).
    void reveal_all();
    // Flag 0x10: render drew the text to its end.
    int is_fully_shown();
    // Shows the name of the player with client_id in its name colour (red while dead); hides the entry
    // when there is no such active player.
    void show_player_name(s32 client_id);
};

LAYOUT_ASSERT(WindowTextEntry_size, sizeof(WindowTextEntry) == 0x2C);

extern "C" {
// WindowTextEntry::WindowTextEntry(TextLayoutRecord *, s32). The class leaves the pure
// TWindowLayoutEntry::calc_bar_width slot empty (its vtable holds 0 there), so the layout
// builder allocates it and calls the constructor by hand, as it does for TWindowLayoutRect.
void *__ct__15WindowTextEntryFP16TextLayoutRecordl(void *p, TextLayoutRecord *rec, s32 client);
}

void set_text_entry_string(WindowTextEntry *entry, const char *str, s32 flags);

#endif
