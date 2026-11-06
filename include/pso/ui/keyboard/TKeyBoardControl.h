#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TKeyBoardControl : public TObject {
    virtual ~TKeyBoardControl();
    virtual void render();
    virtual void run_task();
    u16 m_1c;
    s16 m_1e;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    static void run_main_frame();
    void close();
    void release_input();
    void release();
    static void run_tasks();
    int get_fog_ctrl();
    static void update();
    static s32 get_input();
    static s32 get_key_state();
    static void reset();
    static s32 any_pad_input_active();
    static s32 check_reset_button();
    static s32 check_and_read(s32 arg0);
    static s32 read_input(s32 arg0);
    static s32 is_key_down(s32 arg0);
    s32 check_input_angle();
    static void alloc_buffer();
    static s32 is_printable_key(void *arg0, u8 arg1);
    static s32 has_non_modifier_key();
    static s32 translate_key_char(void *arg0_, u8 arg1, u16 *arg2);
    s32 get_input_mode();
    void enable_keyboard_led();
    void enable_kana_led();
    void enable_caps_led();
    static void update_main_menu_scene();
    static void update_menu_scene();
    static void flush_input();
    static void init_pad_slots_and_read();
    static void read_pads();
    static s32 map_pad_buttons(u16 arg0);
    static s16 scale_axis_value(s16 x);
    void clamp_axes();
    static void init_pad_states();
    static void parse_pad_event(s32 arg0, u32 arg1);
    static void detect_device_type(s32 chan);
    static s32 disable_all_channels();
    void update_pressed_keys();
    static void update_key_events(s32 chan);
    static void disable_channel_polling(s32 arg0);
    static void init_char_select();
    static void dispatch_select_phase();
    static s32 get_ascii_key();
    static s32 read_key_checked(u8 arg0);
    static void update_input_frame();
    static void init_pad_state();
    s32 poll_key_state();
    void set_flag60_bit200();
    void clear_flag60_bit200();
    int is_key_held();
    void set_flag62_bit2();
    int is_active();
    int is_key_active();
    void set_flag62_bit8();
    s32 append_char(s8 arg1);
    void append_next_char();
    static void append_next_char_global();
    static void disable_disconnected_ports();
    static s32 check_input_ready(s32 arg0);
    s32 has_any_key_pressed();
    u8 get_key_state_2();
    void push_key_to_buffer(u8 arg1);
    void tick_key_repeat_timer(u8 arg1);
    void reset_keys();
    void clear_key_state();
    static void reset_input(s32 arg0);
    static void reset_global_keys_a();
    static void reset_global_keys_b();
    static s32 start_get_type_async(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    static void enable_keyboard_polling(s32 arg0);
    static void update_camera();
    static void set_key_state(s32 arg0);
    void reset_inactive_keys();
};

typedef char TKeyBoardControl_size[sizeof(TKeyBoardControl) == 0x2C ? 1 : -1];
#endif
