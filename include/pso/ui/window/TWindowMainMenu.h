#ifndef PSO_UI_WINDOW_TWINDOWMAINMENU_H
#define PSO_UI_WINDOW_TWINDOWMAINMENU_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"

// One row of a main-menu table: item id and the table the item opens (id 0x1F ends a table).
struct TWindowMainMenuEntry {
    s16 id;
    s16 pad_2;
    TWindowMainMenuEntry *submenu;
};

extern TWindowMainMenuEntry main_menu_1p_entries[];
extern TWindowMainMenuEntry main_menu_1p_android_entries[];
extern TWindowMainMenuEntry main_menu_4p_entries[];
extern TWindowMainMenuEntry main_menu_4p_android_entries[];

struct TWindowMenuMainMenu;
class TWindowBase;
class TWindowMessage;
struct NJS_POINT2;

struct MainMenuSlotState {
    s16 first;
    s16 second;
    TWindowMainMenuEntry *entries; // active_entries saved for this depth
};

struct TWindowMainMenu : public TObject {
    TWindowMainMenu(TObject *parent, s32 client);
    virtual ~TWindowMainMenu();
    static const char *class_name;
    virtual void open_main_menu();
    virtual void on_menu_opened();
    virtual void close_main_menu();
    virtual void on_submenu_closed();
    void handle_menu_selection();
    void create_submenu(u32);
    void destroy_submenu();
    void replace_submenu(s16 id);
    void close_child_window();
    void toggle_help_window();
    void update_keyboard_card_state();
    void update_selection_value();
    void add_menu_entry(s16);
    void load_submenu_entries();
    void open(TWindowMainMenuEntry *entries);
    void close_and_clear_flags();
    s32 close_active_submenu();
    void reset_depth_base();
    TWindowMenuMainMenu *menu_window;
    s32 submenu;
    TWindowMessage *help_window;
    MainMenuSlotState slots[4];
    u32 description_item_id;
    u32 menu_flags; // bit 0 open, bit 3 log window active
    s16 submenu_depth;
    s16 selected_slot;
    s32 client_index;
    f32 depth_base;  // submenu windows sit below it (reset_depth_base, get_main_menu_layer_depth)
    TWindowMainMenuEntry *active_entries;
    void update_trade_submenu();
    void show_child_window();
    void restore_after_subwindow();
    void hide_for_subwindow();
    void clear_log_active();
    void set_log_active();
    s32 is_log_active();
    s32 is_open();
    void update_submenu();
    void close_submenu(TWindowMainMenuEntry *window_main_menu_entry);
    void refresh_submenu(TWindowMainMenuEntry *window_main_menu_entry);
    void close();
    virtual void run_task();
    virtual void render();
    static TWindowMenuMainMenu *create_menu(const NJS_POINT2 *position, s32 client);
    void populate_menu(const TWindowMainMenuEntry *window_main_menu_entry);
    void open_menu_with_entry(s16 id);
    void try_open_battle_menu(s16 key);
    s32 filter_menu_entry(s16 *id, s32 *enabled);
    void update_description_text(s32 id);
};

LAYOUT_ASSERT(MainMenuSlotStateSize, sizeof(MainMenuSlotState) == 8);
LAYOUT_ASSERT(MainMenuClientIndexOffset, offsetof(TWindowMainMenu, client_index) == 0x54);
LAYOUT_ASSERT(MainMenuSize, sizeof(TWindowMainMenu) == 0x60);

int test_keyboard_card_flag4(s32 client_id);

extern "C" {
void TWindowSubEquip__sub_80263AF4(void *, s32);
}
f32 get_main_menu_layer_depth(u8 *parent, u32 layer);
void call_if_split_screen(TWindowBase *window, s32 client_id);
// Two empty functions after TWindowMainMenu's inlines; TWindowCtrl::shutdown and TWindowCtrl::close call them.
extern "C" {
void TWindowMainMenu__sub_8024E3CC(void);
void TWindowMainMenu__sub_8024E3D0(void);
}

#endif
