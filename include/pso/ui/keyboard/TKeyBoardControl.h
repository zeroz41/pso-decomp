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
    static void reset();
    static s32 any_pad_input_active();
    static s32 check_reset_button();
    static s32 check_and_read(s32 port);
    static s32 read_input(u8 key);
    static s32 is_key_down(s32 key);
    static void alloc_buffer();
    void clear_keyboard_flag60_bit1();
    void set_composer_flag62_bit4();
    static void update_main_menu_scene();
    static void update_menu_scene();
    static void flush_input();
    static void init_pad_slots_and_read(s32, s32, s32);
    static void read_pads();
    static s32 map_pad_buttons(u16 button_bits);
    static s16 scale_axis_value(s16 x);
    void clamp_axes();
    static void init_pad_states();
    static void parse_pad_event(s32 chan, u32 type);
    static void detect_device_type(s32 chan);
    static s32 disable_all_channels();
    static void update_key_events(s32 chan);
    static void disable_channel_polling(s32 chan);
    static void init_char_select(TObject *fade);
    static void dispatch_select_phase(TObject *fade);
    static s32 get_ascii_key();
    static s32 read_key_checked(u8 key);
    static void update_input_frame();
    static void init_pad_state();
    static s32 start_get_type_async(s32 chan, s32 out_bytes, s32 in_bytes, void (*callback)(s32));
    static void enable_keyboard_polling(s32 chan);
    static void update_camera();
    static void set_key_state(s32 callback_addr);
    static s32 get_function_key_menu(void *menu);
};

LAYOUT_ASSERT(TKeyBoardControl_size, sizeof(TKeyBoardControl) == 0x2C);
#endif
