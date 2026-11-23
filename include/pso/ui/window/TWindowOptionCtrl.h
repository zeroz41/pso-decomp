#ifndef PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H
#define PSO_UI_WINDOW_TWINDOWOPTIONCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdPlayerLoadGC;
class TSnapshotFileSetup;
struct NJS_POINT2;

struct TWindowOptionCtrl : public TObject {
    TWindowOptionCtrl(TObject *parent);
    virtual ~TWindowOptionCtrl();
    s8 state;
    u8 flags;
    s16 saved_sound_mode; // the sound output mode when the window opened
    s16 sound_mode;
    u8 pad_22[0x2];
    s32 m_24;
    void *main_menu;
    void *sub_menu;
    void *m_30;
    void *option_menu;
    void *sound_balance_window;
    void *snap_shot_window;
    void *yes_no_window;
    void *serial_info_window;
    TSnapshotFileSetup *card_format_dialog;
    TAdPlayerLoadGC *player_load; // memory-card watcher made by the ctor

    static const char *class_name;
    static void set_params(void *arg0, s16 arg1, s16 arg2);
    void apply_selection_change();
    void init_selection_indices();
    void apply_and_close(s32 arg1);
    s32 handle_input(s32 language);
    // The cursor position of the entry at m_88.
    s32 update_selected_item();
    static void add_menu_item(saddr check_box_window, s32 arg2, s32 item);
    static void set_field_value(s32 arg0, s16 arg1);
    static s32 get_option_field_C();
    static const char *text_or_default(const char *text);
    static saddr create_serial_info_window(const NJS_POINT2 *pos, s32 kind);
    static saddr open_yes_no_window(saddr arg0, s32 arg1, s32 index);
    saddr create_option_menu();
    saddr create_sub_menu_window();
    saddr create_snap_shot_window();
    saddr create_sound_balance_window();
    saddr create_sound_mode_menu();
    saddr create_list_window();
    saddr create_select_menu_window();
    saddr create_menu();
    virtual void render();
    virtual void run_task();
    static saddr get_chr_select_base_plus_1154c();
    void set_flag70_bit400();
    void clear_flag70_bit4();
    s32 get_field_64();
    s16 get_field_62();
    static const NJS_POINT2 *get_option_entry(int a0);
    s32 add_label_value_line(const char *arg1, const char *arg2, u32 arg3);
};

LAYOUT_ASSERT(TWindowOptionCtrl_size, sizeof(TWindowOptionCtrl) == 0x50);
#endif
