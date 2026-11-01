#ifndef PSO_MISC_TWINDOWSUBITEMLIST_H
#define PSO_MISC_TWINDOWSUBITEMLIST_H

#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

struct TWindowSubItemList : public TWindowMenuIconLine {
    virtual ~TWindowSubItemList();
    void sub_8027ACF8(u8 *);
    void render();
    void run_task();
    u8 unk_88[0x4];
    s32 m_8c;
};

typedef char TWindowSubItemList_size[sizeof(TWindowSubItemList) == 0x90 ? 1 : -1];

extern "C" {
u8 *TWindowSubItemList__ct(u8 *arg0, s32 arg1, s16 arg2);
void *__dt__18TWindowSubItemListFv(void *arg0, s16 arg1);
u8 *create_sub_item_list_window(s32 arg0, s32 arg1, s16 arg2);
}

// --- C functions defined in TWindowSubItemList.cpp ---
extern "C" {
u8 *TWindowSubItemList__ct(u8 *arg0, s32 arg1, s16 arg2);
void *__dt__18TWindowSubItemListFv(void *arg0, s16 arg1);
u8 *create_sub_item_list_window(s32 arg0, s32 arg1, s16 arg2);
}
// --- end of C functions

#endif
