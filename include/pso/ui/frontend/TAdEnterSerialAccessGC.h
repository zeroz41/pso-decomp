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
struct WindowDrawContext;

struct TAdEnterSerialAccessGC : public TAdEnterBaseGC {
    static const char *name;
    TAdEnterSerialAccessGC(TObject *parent);
    virtual ~TAdEnterSerialAccessGC();
    virtual void render();
    virtual void run_task();
    s32 prev_state;
    s32 next_state;
    s32 state_timer;
    s32 serial_length;
    TObject *title;
    TAdSelectCurGC *cursor;
    TWindowBase *message_window;
    TWindowBase *draw_window;
    s32 serial_valid;
    s32 prev_serial_valid;
    // The word at +0x118 of the system save payload (of the second card's for get_serial_result); get_serial_seed seeds the character select serial RNG.
    static s32 get_serial_seed();
    static s32 get_serial_result();
    static void draw_screen(void *window, void *context);
    static void draw_serial_chars(WindowDrawContext *context);
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
    static TWindowCallBack *create_callback(const NJS_POINT2 *position, const NJS_POINT2 *scale, WindowCallback callback);
    static char *serial_to_hex_string(const char *serial);
    static int forward_input(void *screen, s32 field, const char *text);
    // 1 when text is a valid entry for field `mode`: 0 serial and 1 access key take digits, 2 password letters and digits.
    static int validate_input(void *window, s32 mode, const char *text);
    // 1 when get_serial_text has a value for `field` to prefill the keyboard with.
    static s32 has_serial_input(TObject *parent, s32 field);
    // The saved (or entered) text of `field`: serial, access key or password; "" for the rest.
    static u8 *get_serial_text(TObject *owner, s32 field);
    static TKeyBoardControl *create_keyboard_control(TObject *parent, s32 field);

    static const NJS_POINT2 selection_positions[2];
    static char raw_serial_buffer[0xC];
    static char access_key_input_buffer[0x10];
    static TKeyBoardControl *keyboard_control;
    static s32 input_state;
};

LAYOUT_ASSERT(TAdEnterSerialAccessGC_size, sizeof(TAdEnterSerialAccessGC) == 0x68);

char *format_saved_serial(void);
char *format_entered_access_key(void);
char *format_entered_serial(void);
void *create_callback_at_zero_vec2(WindowCallback callback);
void clear_serial_buffer();
void store_serial_access_key(saddr serial, saddr access_key, saddr password);

#endif
