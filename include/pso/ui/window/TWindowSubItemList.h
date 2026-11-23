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
    void select_cursor_entry();
    void reset_selected();
    void set_cursor(s16 index);
    s32 get_selected_entry();
    void gray_out_unusable_entries();
    void gray_out_battle_item_entries();
    void refresh();
    void build_item_list();
    // Entry picked first for a command on two items (-1 for none); drawn blinking.
    s16 selected_index;
    u8 pad_8A[0x2];
    // Inventory items listed, drawn against the 30-item capacity.
    s32 item_count;
};

LAYOUT_ASSERT(TWindowSubItemList_size, sizeof(TWindowSubItemList) == 0x90);

extern "C" {
TWindowSubItemList *create_sub_item_list_window(saddr parent, const f32 *position, s32 client);
}

#endif
