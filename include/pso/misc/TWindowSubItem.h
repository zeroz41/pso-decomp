#ifndef PSO_MISC_TWINDOWSUBITEM_H
#define PSO_MISC_TWINDOWSUBITEM_H

#include "types.h"
#include "pso/TObject.h"

struct TWindowSubItem : public TObject {
    virtual ~TWindowSubItem();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    void set_displayed_item(s32 arg1);
    void use_selected_item();
    void close_windows(s32 arg1);
    void exec_item_command(s32 arg1, s32 arg2);
    void set_cursor_row_for_mode(s32 arg1);
    static void draw_slot(s32 arg1, s32 arg2, s32 arg3);
    static void add_meseta_purpose_actions(s32 arg0, s32 arg1);
    s32 create_count_input(s32 arg1);
    s32 create_menu_window();
    virtual void render();
    virtual void run_task();
    void set_flag60_bit10();
    void clear_flag_and_release();
    void reset_selected();
    void set_field_74(s16 v);
    s32 get_selected_entry();
    void refresh();
    s32 get_cursor_pos();
    s32 open_purpose_window(s32 arg1);
    void gray_out_unusable_entries();
    static s32 is_usable(s32 arg0);
};

typedef char TWindowSubItem_size[sizeof(TWindowSubItem) == 0x44 ? 1 : -1];
#endif
