#ifndef PSO_UI_WINDOW_TWINDOWMENU_H
#define PSO_UI_WINDOW_TWINDOWMENU_H

#include "types.h"

class WindowHeading;
#include "pso/ui/window/TWindowAddition.h"

struct NJS_POINT2;
struct TWindowSubStatusDisp;
struct WindowScrollBar;

// One menu row's state: its flag bits (0x10 = disabled) and the value it returns when chosen.
struct TWindowMenuRow {
    u32 flags;
    s32 value;
};

struct TWindowMenu : public TWindowAddition {
    static const char *class_name;
    TWindowMenu(u32 rows, s32 client, const NJS_POINT2 *position);
    virtual ~TWindowMenu();
    void *get_selected_entry();
    void calc_window_size();
    void update_layout_height(f32 width);
    void calc_layout_height(f32 width);
    void set_ready_flag();
    void clear_transition_flag();
    void open();
    void set_loss_flag();
    int sub_80266BB8();
    s32 test_menu_flag(s32 buttons);
    void render_selected_entry(WindowDrawContext *context);
    void draw_selected_bar(WindowDrawContext *context);
    void layout_entries();
    void update_scroll_value();
    void advance_past_disabled_menu_rows();
    void clamp_menu_choice_scroll();
    void update_target_y();
    void reset_selection();
    int is_decided();
    int is_cancelled();
    void clear_flag_and_release();
    s32 get_selected_value();
    void set_flag70_bit10();
    void set_flag_40();
    void clear_flag_40();
    s32 add_text_entry(saddr text, s32 flags, s32 id, s32 color);
    s32 add_text_entry(saddr text, s32 flags, s32 id);
    virtual void render();
    u16 menu_flags;
    s16 entry_count;
    s16 row_cursor;
    s16 row_count;
    s16 selected_row;
    // Row remembered by update_cursor_pos (-1 after reset_selection), e.g. the first of two rows to swap.
    s16 marked_row;
    f32 layout_height;
    TWindowMenuRow *rows;
    WindowScrollBar *scroll_bar;  // the list scroll bar, made on demand by ensure_scroll_bar
    WindowHeading *heading;  // type-1 heading made by create_titled_window_menu
    void set_active_flag();
    void confirm_selection();
    void select_next_item();
    void move_cursor_prev();
    virtual void run_task();

    s32 is_locked(s32 buttons);
    void clamp_scroll_offset();
    // Row flag 0x10 marks a disabled row: confirming it plays the error sound.
    s32 is_row_enabled(s16 row);
    void disable_row(s16 row);
    void enable_row(s16 row, s32 color);
    s16 get_entry_count();
    s16 get_cursor_pos();
    void set_selected_index(s16 index);
    s16 get_selected_index();
    void update_cursor_pos();
    void reset_entries();
    void ensure_scroll_bar();
    void set_scroll_target(f32 width, f32 max_height);
    void update_scroll_target_position();
    void set_flag70_bit100();
};

LAYOUT_ASSERT(TWindowMenu_size, sizeof(TWindowMenu) == 0x8C);
LAYOUT_ASSERT(TWindowMenu_layout_height_offset, offsetof(TWindowMenu, layout_height) == 0x7C);
#endif
