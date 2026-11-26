#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDSOFT_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDSOFT_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/WindowDrawContext.h"

struct TWindowKeyBoardBase;

struct TWindowKeyBoardSoft : public TWindowBase
{
    TWindowKeyBoardSoft(TWindowKeyBoardBase *control, s32 client);
    virtual ~TWindowKeyBoardSoft();
    void draw_key_frames(WindowDrawContext *);
    void sub_802616BC(WindowDrawContext *);
    void handle_cursor_move(s32);
    void spawn_key_effect(s32, s32);
    void handle_page_cycle_input(s32);
    void update_keyboard_child_input_from_controller(s32);
    void handle_backspace_button(s32);
    s32 sub_802605DC();
    int get_flag_bit5();
    int get_flag_bit6();
    int is_cursor_locked();
    virtual void render();
    void set_flag60_bit1();
    u32 state_flags;
    s8 layout_page;
    s8 cursor_column;
    s8 cursor_row;
    f32 page_slide;  // page-change slide, set to +-10 when layout_page steps, decays 15% a frame
    TWindowKeyBoardBase *m_control;
    f32 calc_key_coord(s32 count);
    void update_focus_flags();
    void set_mode0();
    void set_mode1();
    void set_mode2();
    void set_mode3();
    void reset_layout_page();
    void update_close_mode();
    s32 hit_test_relative(WindowDrawContext *ctx, TexturedQuad *quad);
    void draw_key_frame(WindowDrawContext *context, f32 x0, f32 y, f32 w, f32 scale, u32 color, s32 idx);
    static s32 strnlen(const char *str, u32 max);
    virtual void run_task();
    void calc_cursor_step(s32 *first_page, s32 *last_page);
    f32 calc_key_x(s32 col, s32 row);
    s32 calc_key_index(s32 col, s32 row);
    f32 get_tab_bar_x();
    void get_key_style(s32 key, s32 *count, u32 *color);
    void handle_key_press(s32 port);
    f32 get_key_reveal_ratio(WindowDrawContext *context, f32 x, f32 y, f32 width, f32 height);
    void sub_80261DD8(WindowDrawContext *ctx);
    int get_flag_bit0();
};

LAYOUT_ASSERT(TWindowKeyBoardSoft_size, sizeof(TWindowKeyBoardSoft) == 0x70);
LAYOUT_ASSERT(TWindowKeyBoardSoft_state_offset, offsetof(TWindowKeyBoardSoft, state_flags) == 0x60);
LAYOUT_ASSERT(TWindowKeyBoardSoft_control_offset, offsetof(TWindowKeyBoardSoft, m_control) == 0x6C);

// Key class of each cell of the 16 x 7 key grid, indexed by x + y * 16: 0/1 one-cell keys, 2..17 the cells
// of the wide keys (it picks the key width and colour). Defined after profanity_word_table (name inferred).
extern u8 soft_keyboard_key_class[7 * 16];

struct KeyUV {
    f32 u;
    f32 v;
};


#endif
