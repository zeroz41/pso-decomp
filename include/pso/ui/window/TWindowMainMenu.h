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
class TWindowMessage;

struct MainMenuSlotState {
    s16 first;
    s16 second;
    s32 value;
};

struct TWindowMainMenu : public TObject {
    TWindowMainMenu(TObject *parent, s32 client);
    virtual ~TWindowMainMenu();
    virtual void open_main_menu();
    virtual void on_menu_opened();
    virtual void close_main_menu();
    virtual void on_submenu_closed();
    void handle_menu_selection();
    void create_submenu(u32);
    void destroy_submenu();
    void close_child_window();
    void sub_80263FE0();
    void update_keyboard_card_state();
    void update_selection_value();
    void add_menu_entry(s16);
    void sub_80263D7C();
    void open(s32);
    void close_and_clear_flags();
    s32 close_active_submenu();
    void set_scale_f();
    TWindowMenuMainMenu *m_1c;
    s32 m_20;
    TWindowMessage *help_window;
    MainMenuSlotState slots[4];
    u32 m_48;
    u32 m_4c;
    u16 m_50;
    u16 m_52;
    s32 client_index;
    u8 _pad58[0x4];
    TWindowMainMenuEntry *active_entries;
    void update_trade_submenu();
    void show_child_window();
    void restore_after_subwindow();
    void hide_for_subwindow();
    void clear_log_active();
    void set_log_active();
    void update_submenu();
    void close_submenu(void* window_main_menu_entry);
    void refresh_submenu(void* window_main_menu_entry);
    void close();
    virtual void run_task();
    virtual void render();
    int is_item_active();
    void set_symbol_chat_parts(void * symbol_chat_parts);
    void update_item_tween();
    void init_color();
    void pop_level();
    int get_selected_item_type();
    void clear_menu_flags();
    saddr find_free_slot();
    s32 update_if_active(s32 id);
    void draw_entries_reversed(u8 *frame);
    s32 is_not_split_screen();
    static void *create_menu(void *arg0, void *arg1);
    void open_menu_with_entry(s16 id);
    void try_open_battle_menu(s16 key);
    s32 filter_menu_entry(s16 *arg1, s32 *arg2);
    void update_description_text(s32 id);
};

LAYOUT_ASSERT(MainMenuSlotStateSize, sizeof(MainMenuSlotState) == 8);
LAYOUT_ASSERT(MainMenuClientIndexOffset, offsetof(TWindowMainMenu, client_index) == 0x54);
LAYOUT_ASSERT(MainMenuSize, sizeof(TWindowMainMenu) == 0x60);

int test_keyboard_card_flag4(void *p);

#endif
