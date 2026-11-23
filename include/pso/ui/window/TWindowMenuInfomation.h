#ifndef PSO_UI_WINDOW_TWINDOW_MENU_INFOMATION_H
#define PSO_UI_WINDOW_TWINDOW_MENU_INFOMATION_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

class TWindowSubStatusDisp;

class TWindowMenuInfomation : public TWindowAddition {
public:
    TWindowMenuInfomation(void *parent, s32 rows);
    virtual ~TWindowMenuInfomation();
    virtual void run_task();
    virtual void render();
    void draw();
    void draw_setting(saddr);
    void clamp_scroll();
    void update_scroll_offset();
    void move_cursor_prev();
    void move_next_choice();
    void request_close();
    int is_selected();
    int is_open();
    int get_flag();
    void clear_flag_and_release2();
    void set_flag_10();
    s32 update_selected_entry();
    s32 find_entry_value_by_id(s32 arg1);
    void mark_entry_by_id(s32 arg1);
    void disable_entry_by_id(s32 arg1);
    void update_next_entry(s32 arg1, s32 arg2, s32 arg3);
    void set_entry_string_by_id(void *arg1, s32 arg2);
    void create_sub_window(s32 title);
    u16 m_70;
    s16 next_entry;
    s16 m_74;
    s16 entry_capacity;
    TWindowSubStatusDisp *heading;  // type-1 heading made by create_sub_window
    u8 unk_7C[0x4];
};
LAYOUT_ASSERT(TWindowMenuInfomation_size, sizeof(TWindowMenuInfomation) == 0x80);

#endif
