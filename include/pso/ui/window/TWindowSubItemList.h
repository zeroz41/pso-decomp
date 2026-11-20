#ifndef PSO_UI_WINDOW_TWINDOWSUBITEMLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBITEMLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct TWindowSubItemList : public TWindowMenuIconLine {
    TWindowSubItemList(u8 *parent, s32 client);
    virtual ~TWindowSubItemList();
    void sub_8027ACF8(u8 *);
    void render();
    void run_task();
    s16 m_88;
    u8 pad_8A[0x2];
    s32 m_8c;
};

LAYOUT_ASSERT(TWindowSubItemList_size, sizeof(TWindowSubItemList) == 0x90);

extern "C" {
u8 *create_sub_item_list_window(s32 parent, s32 position, s32 client);
}

#endif
