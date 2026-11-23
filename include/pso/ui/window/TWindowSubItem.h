#ifndef PSO_UI_WINDOW_TWINDOWSUBITEM_H
#define PSO_UI_WINDOW_TWINDOWSUBITEM_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;

struct TWindowSubItem : public TObject {
    TWindowSubItem(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubItem();
    u8 state;
    u8 pad_1d[0x3];
    u32 displayed_item;
    s32 client_id;
    s32 amount;
    TWindowMainMenu *parent_menu;
    uaddr item_list;
    uaddr purpose_menu;
    uaddr confirm_menu;
    uaddr count_input;
    uaddr help_window;

    static const char *class_name;
    void set_displayed_item(s32 arg1);
    void use_selected_item();
    void close_windows(s32 arg1);
    void exec_item_command(saddr item_id, s32 arg2);
    void set_cursor_row_for_mode(s32 arg1);
    static void draw_slot(saddr arg1, saddr arg2, s32 arg3);
    static void add_meseta_purpose_actions(saddr arg0, saddr arg1);
    s32 create_count_input(s32 maximum);
    s32 create_menu_window();
    virtual void render();
    virtual void run_task();
    void set_flag60_bit10();
    void clear_flag_and_release();
    void reset_selected();
    void set_field_74(s16 v);
    s32 get_selected_entry();
    void refresh();
    s32 open_purpose_window(s32 arg1);
    void gray_out_unusable_entries();
    static s32 is_usable(saddr arg0);
};

LAYOUT_ASSERT(TWindowSubItem_size, sizeof(TWindowSubItem) == 0x44);

#endif
