#ifndef PSO_UI_WINDOW_TWINDOWUSERSORT_H
#define PSO_UI_WINDOW_TWINDOWUSERSORT_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowLayoutRecord.h"

struct GuildCardRecord;

struct TWindowUserSort : public TWindowBase {
    TWindowUserSort(saddr position, GuildCardRecord *record);
    virtual void render();
    virtual ~TWindowUserSort();
    static const char *class_name;
    GuildCardRecord *record;
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowUserSort_size, sizeof(TWindowUserSort) == 0x64);

// window_user_sort_layout_entries, the layout table window_user_sort_settings points at
// (label/value rows for name, ship, block and team; fill_card_text_entries fills the values).
struct UserSortWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec[9];
};

#endif
