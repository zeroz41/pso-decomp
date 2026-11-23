#ifndef PSO_UI_WINDOW_TWINDOWSUBITEM_H
#define PSO_UI_WINDOW_TWINDOWSUBITEM_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowHelpItem;
struct TWindowSubItemList;

struct TWindowSubItem : public TObject {
    TWindowSubItem(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubItem();
    u8 state;
    u8 pad_1d[0x3];
    u32 displayed_item;
    s32 client_id;
    s32 amount;
    TWindowMainMenu *parent_menu;
    TWindowSubItemList *item_list;
    uaddr purpose_menu;
    uaddr confirm_menu;
    uaddr count_input;
    TWindowHelpItem *help_window;

    static const char *class_name;
    void set_displayed_item(s32 id);
    void use_selected_item();
    void close_windows(s32 arg1);
    void exec_item_command(saddr item_id, s32 arg2);
    void set_cursor_row_for_mode(s32 mode);
    static void draw_slot(saddr arg1, saddr titled_window_menu, s32 arg3);
    static void add_meseta_purpose_actions(saddr arg0, saddr titled_window_menu);
    s32 create_count_input(s32 maximum);
    s32 create_menu_window();
    virtual void render();
    virtual void run_task();
    void set_flag60_bit10();
    void clear_flag_and_release();
    s32 open_purpose_window(s32 arg1);
    static s32 is_usable(saddr player);
};

LAYOUT_ASSERT(TWindowSubItem_size, sizeof(TWindowSubItem) == 0x44);

// List id of battle item stat (0-4): -0x10 to -0x0C, the rows
// TWindowMenuIconLine::add_battle_stat_entry adds.
s32 get_battle_item_id(s32 stat);

#endif
