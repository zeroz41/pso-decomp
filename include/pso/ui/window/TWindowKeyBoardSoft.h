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
    void sub_8026227C(WindowDrawContext *);
    void sub_802616BC(WindowDrawContext *);
    void sub_80260E30(s32);
    void spawn_key_effect(s32, s32);
    void handle_page_cycle_input(s32);
    void update_keyboard_child_input_from_controller(s32);
    void sub_80260808(s32);
    s32 sub_802605DC();
    int get_flag_bit5();
    int get_flag_bit6();
    int is_cursor_locked();
    virtual void render();
    void set_flag60_bit1();
    u32 m_60;
    s8 layout_page;
    s8 cursor_column;
    s8 cursor_row;
    f32 page_slide;  // page-change slide, set to +-10 when the page index at 0x64 steps, decays 15% a frame
    TWindowKeyBoardBase *m_control;
    f32 calc_key_coord(s32 count);
    void update_focus_flags();
    void set_mode0();
    void set_mode1();
    void set_mode2();
    void set_mode3();
    void sub_80261134();
    void update_close_mode();
    s32 hit_test_relative(u8 *ctx, u8 *arg2);
    void draw_key_frame(WindowDrawContext *context, f32 x0, f32 y, f32 w, f32 scale, u32 color, s32 idx);
    static s32 strnlen(s8 *str, u32 max);
    virtual void run_task();
    s32 dispatch_by_index();
    static void dispatch_request_0x28(s32 a, s32 b);
    static void dispatch_request_0x27(s32 a, s32 b);
    static void dispatch_request_0x26(s32 a, s32 b);
    static void dispatch_request_0x25(s32 a, s32 b);
    static void dispatch_request_0x24(s32 a, s32 b);
    static void dispatch_request_0x23(s32 a, s32 b);
    static void dispatch_request_0x22(s32 a, s32 b);
    static s32 dispatch_request_0x20(const char *a, const char *b);
    static s32 dispatch_request_0x1c();
    static void dispatch_request_0x14(s32 a, s32 b);
    static void dispatch_request_0x13(s32 arg0, s32 arg1, s32 arg2);
    static void dispatch_request_0x10(s32 a, s32 b);
    static void dispatch_request_0f(s32 a, s32 b);
    void calc_cursor_step(s32 *arg1, s32 *arg2);
    f32 calc_key_x(s32 col, s32 row);
    s32 calc_key_index(s32 col, s32 row);
    f32 sub_802606E0();
    void sub_80260760(s32 key, s32 *count, u32 *color);
    void sub_80260904(s32 port);
    f32 sub_802614DC(WindowDrawContext *context, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
    void sub_80261DD8(WindowDrawContext *ctx);
    int get_flag_bit0();
};

LAYOUT_ASSERT(TWindowKeyBoardSoft_size, sizeof(TWindowKeyBoardSoft) == 0x70);
LAYOUT_ASSERT(TWindowKeyBoardSoft_state_offset, offsetof(TWindowKeyBoardSoft, m_60) == 0x60);
LAYOUT_ASSERT(TWindowKeyBoardSoft_control_offset, offsetof(TWindowKeyBoardSoft, m_control) == 0x6C);

// Key class of each cell of the 16 x 7 key grid, indexed by x + y * 16: 0/1 one-cell keys, 2..17 the cells
// of the wide keys (it picks the key width and colour). Defined after profanity_word_table (name inferred).
extern u8 soft_keyboard_key_class[7 * 16];

#endif
