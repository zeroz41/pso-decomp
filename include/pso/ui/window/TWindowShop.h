#ifndef PSO_UI_WINDOW_TWINDOWSHOP_H
#define PSO_UI_WINDOW_TWINDOWSHOP_H
#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

class TWindowShop : public TWindowMenuIconLine {
public:
    TWindowShop(u8 *parent, s32 title, u32 count, u8 *descriptor);
    TWindowShop(s32 title, u32 count, s32 client);
    virtual ~TWindowShop();
    void init_list_window(s32 title);
    virtual void render();
    virtual void run_task();
    void set_capacity(s32 capacity);
    s32 capacity;  // drawn as the list's capacity when > 0 (the bank's 200 rows)
};
LAYOUT_ASSERT(TWindowShop_size, sizeof(TWindowShop) == 0x8C);

extern "C" {
// Opens the shop item list (title text, row capacity) placed for the current camera layout.
TWindowShop *create_item_list_window(s32 title, s32 count, s32 client);
}

#endif
