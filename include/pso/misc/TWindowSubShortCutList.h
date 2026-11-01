#ifndef PSO_MISC_TWINDOWSUBSHORTCUTLIST_H
#define PSO_MISC_TWINDOWSUBSHORTCUTLIST_H

#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"

struct TWindowSubShortCutList : public TWindowMenuIconLine {
    virtual ~TWindowSubShortCutList();
    void set_cursor_index(s16);
    void set_flag70_bit10();
    virtual void render();
    u32 m_88;
    void refresh_entries();
    void *create(void *arg1);
    virtual void run_task();
    void draw_entry(s32 arg1, u8 arg2, s32 arg3, s32 arg4);
};

typedef char TWindowSubShortCutList_size[sizeof(TWindowSubShortCutList) == 0x8C ? 1 : -1];
#endif
