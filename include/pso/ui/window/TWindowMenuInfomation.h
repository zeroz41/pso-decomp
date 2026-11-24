#ifndef PSO_UI_WINDOW_TWINDOW_MENU_INFOMATION_H
#define PSO_UI_WINDOW_TWINDOW_MENU_INFOMATION_H
#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

class TWindowSubStatusDisp;
struct WindowScrollBar;

class TWindowMenuInfomation : public TWindowAddition {
public:
    TWindowMenuInfomation(void *parent, s32 rows);
    virtual ~TWindowMenuInfomation();
    virtual void run_task();
    virtual void render();
    void draw();
    void draw_setting(WindowDrawContext *context);
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
    s32 find_entry_value_by_id(s32 key);
    void mark_entry_by_id(s32 entry_id);
    void disable_entry_by_id(s32 id);
    void update_next_entry(s32 arg1, s32 string, s32 arg3);
    void set_entry_string_by_id(void *id, s32 entry_id);
    void create_sub_window(const char *title);
    u16 m_70;
    s16 next_entry;
    s16 index;
    s16 entry_capacity;
    TWindowSubStatusDisp *heading;  // type-1 heading made by create_sub_window
    WindowScrollBar *scroll_bar;
};
LAYOUT_ASSERT(TWindowMenuInfomation_size, sizeof(TWindowMenuInfomation) == 0x80);

#endif
