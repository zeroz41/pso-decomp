#ifndef PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H
#define PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowOptionCtrl : public TObject {
    virtual ~TWindowOptionCtrl();
    u8 m_1c;
    u8 m_1d;
    u8 _pad1E[0x2];
    u16 m_20;
    u8 _pad22[0x2];
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    static void set_params(void *arg0, s16 arg1, s8 arg2);
    void apply_selection_change();
    void init_selection_indices();
    void apply_and_close(s32 arg1);
    s32 handle_input(s32 arg1);
    void update_selected_item();
    static void add_menu_item(s32 arg1, s32 arg2, s32 arg3);
    static void set_field_value(s32 arg0, s16 arg1);
    static s16 get_option_field_C();
    static void warn_if_empty(u8 *arg0);
    s32 create_serial_info_window(s32 arg1);
    static s32 open_yes_no_window(s32 arg0, s32 arg1, s32 arg2);
    static s32 create_option_menu();
    static s32 create_sub_menu_window();
    static s32 create_snap_shot_window();
    static s32 create_sound_balance_window();
    s32 create_sound_mode_menu();
    static s32 create_list_window();
    static s32 create_select_menu_window();
    static s32 create_menu();
    virtual void render();
    virtual void run_task();
    static s32 get_chr_select_base_plus_1154c();
    void set_flag70_bit400();
    void clear_flag70_bit4();
    s16 get_field_64();
    s16 get_field_62();
    static void*get_option_entry(int a0);
    s32 get_field_24();
    void open_confirm_dialog(s32 arg1, s32 arg2);
    void set_option_and_confirm(s32 arg1, s32 arg2);
    void handle_save_result();
    void open();
    s32 add_label_value_line(const char *arg1, const char *arg2, u32 arg3);
};

typedef char TWindowOptionCtrl_size[sizeof(TWindowOptionCtrl) == 0x50 ? 1 : -1];
#endif
