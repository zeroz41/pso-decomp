#ifndef PSO_UNK_TWINDOW_LAYOUT_ENTRY_H
#define PSO_UNK_TWINDOW_LAYOUT_ENTRY_H

#include "types.h"

struct WindowDrawContext;

// Polymorphic entry stored in a window layout entry list.
class TWindowLayoutEntry {
public:
    int is_flag_4_set() const;
    int is_flag80_set() const;
    // Flag 2 keeps draw_visible_window_entries from rendering the entry.
    void show();
    void hide();
    u16 flags;
    s16 client;

    TWindowLayoutEntry(s32 client);
    virtual ~TWindowLayoutEntry();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    virtual void calc_bar_width() = 0;
};

LAYOUT_ASSERT(TWindowLayoutEntry_size, sizeof(TWindowLayoutEntry) == 8);

#endif
