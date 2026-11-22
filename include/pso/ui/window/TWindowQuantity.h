#ifndef PSO_UI_WINDOW_TWINDOWQUANTITY_H
#define PSO_UI_WINDOW_TWINDOWQUANTITY_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TWindowQuantity : public TWindowBase {
    TWindowQuantity(s32 client);
    virtual ~TWindowQuantity();
    virtual void render();
    f32 m_60;
    f32 scale;
    void set_position(s32 arg1);
    virtual void run_task();
    u8 unk_68[0x4];
};

LAYOUT_ASSERT(TWindowQuantity_size, sizeof(TWindowQuantity) == 0x6C);

extern "C" {
void *create_window_quantity(void *client);
}

// --- C functions defined in TWindowQuantity.cpp ---
extern "C" {
void *create_window_quantity(void *client);
}
// --- end of C functions

#endif
