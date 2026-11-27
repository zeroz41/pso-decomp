#ifndef PSO_UNK_TWINDOWLAYOUTRECT_H
#define PSO_UNK_TWINDOWLAYOUTRECT_H

#include "types.h"
#include "pso/ui/window/TWindowLayoutEntry.h"

struct WindowLayoutRectRecord {
    s32 type;
    f32 x;
    f32 y;
    f32 width;
    f32 height;
};

// A window part with a position and size (case 0 of init_window_layout_entries).
class TWindowLayoutRect : public TWindowLayoutEntry {
public:
    f32 x;
    f32 y;
    f32 width;
    f32 height;

    TWindowLayoutRect(s32 client);
    TWindowLayoutRect(u8 *rec, s32 client);
    virtual ~TWindowLayoutRect();
    virtual void update();
    virtual void render(WindowDrawContext *context);
};

LAYOUT_ASSERT(TWindowLayoutRect_size, sizeof(TWindowLayoutRect) == 0x18);

extern "C" {
// The constructors and destructor, called by the parts that are still written by hand.
void *__ct__17TWindowLayoutRectFPUcl(void *p, u8 *rec, s32 client);
}

#endif
