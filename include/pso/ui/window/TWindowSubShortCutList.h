#ifndef PSO_UI_WINDOW_TWINDOWSUBSHORTCUTLIST_H
#define PSO_UI_WINDOW_TWINDOWSUBSHORTCUTLIST_H

#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct PageIndicator;
struct NJS_POINT2;

struct TWindowSubShortCutList : public TWindowMenuIconLine {
    TWindowSubShortCutList(u8 *parent, s32 index);
    virtual ~TWindowSubShortCutList();
    virtual void render();
    PageIndicator *storage;
    void refresh_entries();
    static TWindowSubShortCutList *create(const NJS_POINT2 *position, s32 index);
    virtual void run_task();
    void draw_entry(s32 index, s32 status_style, s32 arg3, s32 item);
};

LAYOUT_ASSERT(TWindowSubShortCutList_size, sizeof(TWindowSubShortCutList) == 0x8C);
#endif
