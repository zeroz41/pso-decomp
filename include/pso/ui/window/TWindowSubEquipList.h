#ifndef PSO_UI_WINDOW_TWINDOWSUBEQUIPLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBEQUIPLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct TWindowSubEquipList : public TWindowMenuIconLine {
    TWindowSubEquipList(u8 *parent, s32 client);
    virtual ~TWindowSubEquipList();
    virtual void render();
    void run_task();
};

LAYOUT_ASSERT(TWindowSubEquipList_size, sizeof(TWindowSubEquipList) == 0x88);

extern "C" {
u8 *create_equip_list_window(saddr parent, saddr position, s32 client);
}

#endif
