#ifndef PSO_UI_WINDOW_TWINDOWSUBSHORTCUTLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBSHORTCUTLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct PageIndicator;

struct TWindowSubShortCutList : public TWindowMenuIconLine {
    TWindowSubShortCutList(u8 *parent, s32 index);
    virtual ~TWindowSubShortCutList();
    void set_cursor_index(s16);
    void set_flag70_bit10();
    virtual void render();
    PageIndicator *m_88;
    void refresh_entries();
    void *create(void *index);
    virtual void run_task();
    void draw_entry(s32 index, u8 arg2, s32 arg3, s32 arg4);
};

LAYOUT_ASSERT(TWindowSubShortCutList_size, sizeof(TWindowSubShortCutList) == 0x8C);
#endif
