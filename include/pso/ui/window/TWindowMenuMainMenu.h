#ifndef PSO_UI_WINDOW_TWINDOWMENUMAINMENU_H
#define PSO_UI_WINDOW_TWINDOWMENUMAINMENU_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowDrawContext.h"

// One row of the main menu. Eight of these are embedded at 0x64, stride 0x18.
// init_color writes the four floats and the five bytes that follow; the
// constructor walks that array, not the menu object itself.
struct TMainMenuEntryPosition {
    f32 target[2];
    f32 current[2];
};

struct TMainMenuEntry {
    TMainMenuEntryPosition position;
    s8 fade;
    s8 icon;
    s8 kind;
    u8 flags;
    s8 tween;
    u8 b5;
    u8 b6;
    u8 b7;
    void draw_item_labels(WindowDrawContext *context);
    int is_item_active();
    void disable_choice();
    void set_row_target(NJS_POINT2 *row);
    void init_row_entry(NJS_POINT2 *row, s8 icon, s8 fade);
    void update_item_tween();
    void init_color();
    void copy_color_entry(TMainMenuEntry *src);
};

LAYOUT_ASSERT(TMainMenuEntry_size, sizeof(TMainMenuEntry) == 0x18);
LAYOUT_ASSERT(TMainMenuEntry_flags, offsetof(TMainMenuEntry, flags) == 0x13);
LAYOUT_ASSERT(TMainMenuEntry_kind, offsetof(TMainMenuEntry, kind) == 0x12);

struct TWindowMenuMainMenu : public TWindowBase {
    TWindowMenuMainMenu(const NJS_POINT2 *position, s32 client);
    virtual ~TWindowMenuMainMenu();
    void handle_navigation_input();
    void handle_confirm();
    void handle_cancel();
    void draw_frame(WindowDrawContext *context);
    WindowDrawContext *setup_content_frame();
    void set_target_y(f32 target);
    void update_scaled_position();
    void update_slide_position();
    void draw_entries_reversed(WindowDrawContext *context);
    void pop_level();
    void park_selection();
    int get_selected_item_type();
    void set_selected_slot(int slot);
    int get_selected_slot();
    void clear_menu_flags();
    int find_free_item_slot();
    void get_row_position(NJS_POINT2 *row, int index);
    s32 is_not_split_screen();
    TMainMenuEntry *append_child_rows(int id);
    void play_cursor_sound(int delta);
    TMainMenuEntry *update_if_active(s32 id);
    TMainMenuEntry *find_active_item_by_id(int id);
    TMainMenuEntry *find_free_slot();
    s32 count_active_items();
    int get_menu_flag();
    int is_flag_set();
    virtual void render();
    virtual void run_task();
    u8 state_flags;
    s8 selected_slot;
    s16 parked_row_count;
    TMainMenuEntry entries[8];
    TMainMenuEntry *slots[8];
};

LAYOUT_ASSERT(TWindowMenuMainMenu_size, sizeof(TWindowMenuMainMenu) == 0x144);
LAYOUT_ASSERT(TWindowMenuMainMenu_entries, offsetof(TWindowMenuMainMenu, entries) == 0x64);
LAYOUT_ASSERT(TWindowMenuMainMenu_slots, offsetof(TWindowMenuMainMenu, slots) == 0x124);

#endif
