#ifndef PSO_UI_WINDOW_WINDOWLAYOUTENTRIES_H
#define PSO_UI_WINDOW_WINDOWLAYOUTENTRIES_H

#include "types.h"
#include <stddef.h>

struct WindowDrawContext;

struct WindowLayoutEntries {
    u32 count;
    void **items;

    void destroy_all_items();
};

LAYOUT_ASSERT(WindowEntriesSize, sizeof(WindowLayoutEntries) == 8);
LAYOUT_ASSERT(WindowEntriesItemsOffset, offsetof(WindowLayoutEntries, items) == 4);

extern "C" {
void draw_visible_window_entries(const void *window, const WindowLayoutEntries *entries, WindowDrawContext *context);
// Populate the entry list from the dimensions and packed part descriptors.
void init_window_layout_entries(WindowLayoutEntries *entries, const void *layout, s32 client);
}

#endif
