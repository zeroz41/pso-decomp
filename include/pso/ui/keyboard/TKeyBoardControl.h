#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct NJS_POINT2;
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
    void set_position(NJS_POINT2 *pos);
    void set_soft_position(u8 *pos);
    void set_hard_position(u8 *pos);
    void set_sub_position(u8 *pos);
    void set_text(const char *s);
    char *realloc_buffer();
    int is_cancelled();
    int is_confirmed();
    static void update();
    void clear_keyboard_flag60_bit1();
    void set_composer_flag62_bit4();
    static void update_main_menu_scene();
    static void clear_main_menu_scene_flag();
};

s32 get_key_state();

s32 get_input();

LAYOUT_ASSERT(TKeyBoardControl_size, sizeof(TKeyBoardControl) == 0x2C);
extern u8 main_menu_scene_active_flag;

#endif
