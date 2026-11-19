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
    u8 _pad1C[0x44];
    u32 m_60;
    s8 m_64;
    s8 m_65;
    s8 m_66;
    f32 m_68;
    TWindowKeyBoardBase *m_control;
    static f32 calc_key_coord(s32 arg0, s32 arg1);
    void update_focus_flags();
    void set_mode0();
    void set_mode1();
    void set_mode2();
    void set_mode3();
    void sub_80261134();
    void close();
    s32 hit_test_relative(u8 *arg1, u8 *arg2);
    static void draw_key_frame(void *self, f32 *rect, f32 x0, f32 y, f32 w, f32 scale, u32 color, s32 idx);
    void set_text_from_string(char *s);
    s32 is_buffer_blank();
    s32 apply_dakuten_to_last_char();
    s32 is_buffer_blank_checked();
    void delete_chars(s32 arg1, s32 arg2);
    void delete_char();
    void make_room_in_buffer(s32 pos, s32 n);
    void insert_char_slot();
    s32 measure_char_overflow(u16 code, u32 *x, u32 *y, u32 *count);
    s32 check_text_overflow(u16 *arg1);
    void reset_state();
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
    static void dispatch_request_0x20(s32 a, s32 b);
    static void dispatch_request_0x1c();
    static void dispatch_request_0x14(s32 a, s32 b);
    static void dispatch_request_0x13(s32 arg0, s32 arg1, s32 arg2);
    static void dispatch_request_0x10(s32 a, s32 b);
    static void dispatch_request_0f(s32 a, s32 b);
    void calc_cursor_step(s32 *arg1, s32 *arg2);
    f32 calc_key_x(s32 arg1, s32 arg2);
    static s32 calc_key_index(TWindowKeyBoardSoft *arg1, s32 arg2, s32 arg3);
};

typedef char TWindowKeyBoardSoft_size[sizeof(TWindowKeyBoardSoft) == 0x70 ? 1 : -1];

// Key class of each cell of the 16 x 7 key grid, indexed by x + y * 16: 0/1 one-cell keys, 2..17 the cells
// of the wide keys (it picks the key width and colour). Defined after profanity_word_table (name inferred).
extern u8 soft_keyboard_key_class[7 * 16];

#endif
