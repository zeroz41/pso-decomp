#ifndef PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H
#define PSO_UI_WINDOW_TWINDOWSUBCUSTOMSELECT_H

#include <stddef.h>
#include "types.h"

class WindowHeading;
#include "pso/ui/window/TWindowAddition.h"
#include "pso/unk/WindowLayoutRecord.h"

// An action palette slot reference: the tag mode and the slot it points to.
struct PaletteTag {
    u16 mode;
    u16 slot;
};

struct WindowScrollBar;
struct PaletteAction;

struct TWindowSubCustomSelect : public TWindowAddition {
    static WindowDescriptor window_settings;
    TWindowSubCustomSelect(s32 client);
    virtual ~TWindowSubCustomSelect();
    static const char *class_name;
    virtual void render();
    u8 column;
    u8 row;
    u8 row_count;
    u8 state_flags;
    u32 cursor_frame;
    const PaletteAction *action_table;  // three actions per row, ended by mode 8
    WindowHeading *status_display;
    WindowScrollBar *scroll_bar;
    void handle_cancel();
    void handle_decide();
    void update_list_scroll();
    void handle_grid_navigation();
    void draw_cursor(WindowDrawContext *context);
    void draw_palette_cells(WindowDrawContext *ctx);
    virtual void run_task();
    int is_active();
    int is_cancelled();  // set by handle_cancel
    const PaletteAction *get_selected_action();
};

LAYOUT_ASSERT(TWindowSubCustomSelect_size, sizeof(TWindowSubCustomSelect) == 0x84);

LAYOUT_ASSERT(TWindowSubCustomSelectFieldsOffset, offsetof(TWindowSubCustomSelect, column) == 0x70);

// window_sub_custom_select_layout_entries, the layout table
// TWindowSubCustomSelect::window_settings points at (two sprite parts and a value entry).
struct SubCustomSelectWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
};


#endif
