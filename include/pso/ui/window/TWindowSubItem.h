#ifndef PSO_UI_WINDOW_TWINDOWSUBITEM_H
#define PSO_UI_WINDOW_TWINDOWSUBITEM_H

#include "types.h"
struct TWindowMenu;
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowMenu;
class TWindowInputNumber;
struct TWindowHelpItem;
struct TWindowSubItemList;
struct TObjPlayer;

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
    TWindowMenu *purpose_menu;
    TWindowMenu *confirm_menu;
    TWindowInputNumber *count_input;
    TWindowHelpItem *help_window;

    static const char *class_name;
    void set_displayed_item(s32 id);
    void use_selected_item();
    void close_windows(s32 arg1);
    void exec_item_command(saddr item_id, s32 command);
    void set_cursor_row_for_mode(s32 mode);
    static void draw_slot(saddr arg1, TWindowMenu *titled_window_menu, s32 item_id);
    static void add_meseta_purpose_actions(saddr arg0, TWindowMenu *titled_window_menu);
    TWindowInputNumber *create_count_input(s32 maximum);
    TWindowMenu *create_menu_window();
    virtual void render();
    virtual void run_task();
    TWindowMenu *open_purpose_window(s32 item_id);
    static s32 is_usable(TObjPlayer *player);
};

LAYOUT_ASSERT(TWindowSubItem_size, sizeof(TWindowSubItem) == 0x44);

// List id of battle item stat (0-4): -0x10 to -0x0C, the rows
// TWindowMenuIconLine::add_battle_stat_entry adds.
s32 get_battle_item_id(s32 stat);

#endif
