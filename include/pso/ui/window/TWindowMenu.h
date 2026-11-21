#ifndef PSO_UI_WINDOW_TWINDOWMENU_H
#define PSO_UI_WINDOW_TWINDOWMENU_H

#include "types.h"
#include "pso/ui/window/TWindowAddition.h"

struct TWindowSubStatusDisp;

struct TWindowMenu : public TWindowAddition {
    TWindowMenu(u32 rows, s32 client, saddr parent);
    virtual ~TWindowMenu();
    void *get_selected_entry();
    void calc_window_size();
    void update_layout_height(f32 width);
    void set_ready_flag();
    void clear_transition_flag();
    void set_loss_flag();
    int sub_80266BB8();
    s32 test_menu_flag(s32 buttons);
    void render_selected_entry(saddr);
    void draw_selected_bar(u8 *);
    void layout_entries();
    void update_scroll_value();
    void advance_past_disabled_menu_rows();
    void clamp_menu_choice_scroll();
    void update_target_y();
    void reset_selection();
    int is_decided();
    int is_cancelled();
    s32 get_selected_value();
    void set_flag70_bit10();
    virtual void render();
    u16 m_70;
    u16 m_72;
    u16 m_74;
    u16 m_76;
    u16 m_78;
    u8 unk_7A[0x2];
    f32 layout_height;
    u32 m_80;
    u32 m_84;
    TWindowSubStatusDisp *m_88;
    void set_active_flag();
    void confirm_selection();
    void select_next_item();
    void move_cursor_prev();
    virtual void run_task();

    s32 is_locked(s32 buttons);
};

LAYOUT_ASSERT(TWindowMenu_size, sizeof(TWindowMenu) == 0x8C);
LAYOUT_ASSERT(TWindowMenu_layout_height_offset, offsetof(TWindowMenu, layout_height) == 0x7C);
#endif
