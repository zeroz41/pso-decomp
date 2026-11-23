#ifndef PSO_UNK_TWINDOW_LAYOUT_ENTRY_H
#define PSO_UNK_TWINDOW_LAYOUT_ENTRY_H

#include "types.h"

struct WindowDrawContext;

// Polymorphic entry stored in a window layout entry list.
class TWindowLayoutEntry {
public:
    int is_flag_4_set() const;
    u16 flags;
    s16 client;

    TWindowLayoutEntry(s32 client);
    virtual ~TWindowLayoutEntry();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    virtual void calc_bar_width() = 0;
};

LAYOUT_ASSERT(TWindowLayoutEntry_size, sizeof(TWindowLayoutEntry) == 8);

extern "C" {
// TWindowLayoutEntry::TWindowLayoutEntry(s32), called by the constructors that are still written by hand.
void *__ct__18TWindowLayoutEntryFl(void *p, s32 client);
// TWindowLayoutEntry::~TWindowLayoutEntry(), called by the destructors that are still written by hand.
void *__dt__18TWindowLayoutEntryFv(void *p, s16 flags);
}

#endif
