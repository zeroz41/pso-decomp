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
    // CodeWarrior: the layout entries' vtables keep this slot 0; the host gives it a body to build them with new.
#ifdef __MWERKS__
    virtual void calc_bar_width() = 0;
#else
    virtual void calc_bar_width() {}
#endif
};

LAYOUT_ASSERT(TWindowLayoutEntry_size, sizeof(TWindowLayoutEntry) == 8);

#endif
