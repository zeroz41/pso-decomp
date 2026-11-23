#ifndef PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H
#define PSO_UI_FRONTEND_TADENTERSERIALACCESSGC_H

#include "pso/ui/window/WindowCallback.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdEnterBaseGC.h"

class TAdSelectCurGC;
class TKeyBoardControl;
class TWindowBase;
struct TWindowCallBack;

struct TAdEnterSerialAccessGC : public TAdEnterBaseGC {
    TAdEnterSerialAccessGC(TObject *parent);
    virtual ~TAdEnterSerialAccessGC();
    virtual void render();
    virtual void run_task();
    u8 pad_38[0x8];
    s32 prev_state;
    s32 next_state;
    s32 state_timer;
    s32 serial_length;
    TObject *title;
    TAdSelectCurGC *cursor;
    TWindowBase *message_window;
    TWindowBase *draw_window;
    s32 input_valid;
    s32 prev_input_valid;
    static void draw_screen(void *window, void *context);
    static void draw_serial_chars(void *context);
    static void draw_serial_separators();
    static void draw_serial_plates();
    static void format_dashed_serial(char *dst, const char *src, u32 count, const u32 *lengths);
    static char *get_formatted_serial();
    static s32 parse_serial_value();
    static void initialize_serial_input(const char *serial);
    static void set_access_key(const char *key);
    static void set_raw_serial(const char *serial);
    static char *convert_serial_hex_to_decimal(const char *serial);
    static char *hex_to_decimal_string(const char *serial);
    TWindowCallBack *create_draw_callback();
    TWindowBase *open_message_window(s32 text_index);
    void update_text_input(s32 field);
    void update_access_key_input();
    void update_serial_input();
    static void set_entered_value(u32 value, s32 field);
    static void init_state();
    static TWindowCallBack *create_callback(void *position, void *scale, WindowCallback callback);
    void *create_default_callback();
    static s32 show_message_window(void *arg0, void *arg1);
    static void clear_serial_buffer();
    static void store_serial_access_key(saddr arg0, saddr arg1, saddr arg2);
    static char *serial_to_hex_string(const char *serial);
    static int forward_input(void *screen, s32 field, const char *text);
    static TKeyBoardControl *create_keyboard_control(saddr arg0, s32 field);

    static const NJS_POINT2 selection_positions[2];
    static char raw_serial_buffer[0xC];
    static char access_key_input_buffer[0x10];
    static TKeyBoardControl *keyboard_control;
    static s32 input_state;
};

LAYOUT_ASSERT(TAdEnterSerialAccessGC_size, sizeof(TAdEnterSerialAccessGC) == 0x68);

extern "C" {
char *TAdEnterSerialAccessGC__sub_80321738(void);
char *TAdEnterSerialAccessGC__sub_803217B8(void);
char *TAdEnterSerialAccessGC__sub_80321874(void);
void *create_callback_at_zero_vec2(WindowCallback callback);
}

#endif
