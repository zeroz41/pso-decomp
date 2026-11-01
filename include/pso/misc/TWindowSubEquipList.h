#ifndef PSO_MISC_TWINDOWSUBEQUIPLIST_H
#define PSO_MISC_TWINDOWSUBEQUIPLIST_H

#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

struct TWindowSubEquipList : public TWindowMenuIconLine {
    virtual ~TWindowSubEquipList();
    virtual void render();
    void run_task();
};

typedef char TWindowSubEquipList_size[sizeof(TWindowSubEquipList) == 0x88 ? 1 : -1];

extern "C" {
u8 *TWindowSubEquipList__ct(u8 *arg0, s32 arg1, s16 arg2);
void *__dt__19TWindowSubEquipListFv(void *arg0, s16 arg1);
u8 *create_equip_list_window(s32 arg0, s32 arg1, s16 arg2);
}

// --- C functions defined in TWindowSubEquipList.cpp ---
extern "C" {
u8 *TWindowSubEquipList__ct(u8 *arg0, s32 arg1, s16 arg2);
void *__dt__19TWindowSubEquipListFv(void *arg0, s16 arg1);
u8 *create_equip_list_window(s32 arg0, s32 arg1, s16 arg2);
}
// --- end of C functions

#endif
