#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowKeyBoardBase;
struct TWindowKeyBoardHard;
struct TWindowKeyBoardSoft;

struct TKeyBoardControl : public TObject {
    TKeyBoardControl(TObject *parent, u32 width, u32 lines, u8 mode, s32 client);
    virtual ~TKeyBoardControl();
    virtual void render();
    virtual void run_task();
    u16 flags;
    s16 client_index;
    TWindowKeyBoardBase *m_base;
    TWindowKeyBoardHard *m_hard;
    TWindowKeyBoardSoft *m_soft;
    void hide();
    void show();
    void set_flag62_bit2();
    void set_soft_flag60_bit1();
    s32 get_cursor_position();
    void set_depth(f32 depth);
    void set_position(void *pos);
    void set_soft_position(u8 *pos);
    void set_hard_position(u8 *pos);
    void set_sub_position(u8 *pos);
    void set_text(char *s);
    char *realloc_buffer();
    int is_cancelled();
    int is_confirmed();
    static void run_main_frame();
    static void run_tasks();
    static void update();
    static s32 get_input();
    static s32 get_key_state();
    static void alloc_buffer();
    void clear_keyboard_flag60_bit1();
    void set_composer_flag62_bit4();
    static void update_main_menu_scene();
    static void update_menu_scene();
    static void init_char_select(TObject *fade);
    static void dispatch_select_phase(TObject *fade);
    static s16 get_function_key_menu(void *menu);
};

LAYOUT_ASSERT(TKeyBoardControl_size, sizeof(TKeyBoardControl) == 0x2C);
#endif
