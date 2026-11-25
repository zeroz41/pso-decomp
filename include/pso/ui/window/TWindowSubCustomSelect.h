#ifndef PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H
#define PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct WindowScrollBar;

struct TWindowSubCustomSelect : public TWindowAddition {
    TWindowSubCustomSelect(s32 client);
    virtual ~TWindowSubCustomSelect();
    virtual void render();
    u8 column;
    u8 row;
    u8 row_count;
    u8 state_flags;
    u32 cursor_frame;
    uaddr action_table;
    uaddr status_display;
    WindowScrollBar *scroll_bar;
    void handle_cancel();
    void handle_decide();
    void update_list_scroll();
    void handle_grid_navigation();
    void draw_cursor(WindowDrawContext *context);
    void draw_palette_cells(WindowDrawContext *ctx);
    virtual void run_task();
    int is_active();
    void *get_selected_action();
};

LAYOUT_ASSERT(TWindowSubCustomSelect_size, sizeof(TWindowSubCustomSelect) == 0x84);

LAYOUT_ASSERT(TWindowSubCustomSelectFieldsOffset, offsetof(TWindowSubCustomSelect, column) == 0x70);

#endif
