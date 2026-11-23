#ifndef PSO_UI_WINDOW_TWINDOWQUANTITY_H
#define PSO_UI_WINDOW_TWINDOWQUANTITY_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TItem;

struct TWindowQuantity : public TWindowBase {
    TWindowQuantity(s32 client);
    virtual ~TWindowQuantity();
    virtual void render();
    f32 width;
    f32 scale[2];
    void set_position(WindowDrawContext *context);
    void set_entry_count(TItem *item);
    void set_quantity(s32 quantity);
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowQuantity_scale_offset, offsetof(TWindowQuantity, scale) == 0x64);
LAYOUT_ASSERT(TWindowQuantity_size, sizeof(TWindowQuantity) == 0x6C);

extern "C" {
TWindowQuantity *create_window_quantity(s32 client);
}

#endif
