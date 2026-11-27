#ifndef PSO_UI_WINDOW_TWINDOWINPUTNUMBER_H
#define PSO_UI_WINDOW_TWINDOWINPUTNUMBER_H

#include "types.h"

class WindowHeading;

struct NJS_POINT2;
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

class TWindowLayoutNumber;

struct TWindowInputNumber : public TWindowBase {
    static const char *class_name;
    s32 is_locked(s32);
    s32 test_input_flag(s32 buttons);
    void disable_input();
    // Bit 0x10: run_task reads the digit keys with test_buttons_press_or_repeat.
    void set_flag_10();
    // Drops the confirmation confirm_input set and puts the title back to its open state.
    void clear_confirmed();
    void enable_input();
    void refresh_digit_entries();
    void align_digits();
    void draw_arrows(WindowDrawContext *context, TWindowLayoutNumber *digit, int confirmed);
    virtual void render();
    u16 inputFlags;
    s8 digitCount;
    s8 selectedDigit;
    s32 minimum;
    s32 maximum;
    s32 value;
    WindowHeading *heading;  // the title window made by create()
    f32 scaleX;
    f32 scaleY;

    TWindowInputNumber(const NJS_POINT2 *position, s32 minimum, s32 maximum, s32 initial, s16 client);
    virtual ~TWindowInputNumber();
    void mark_confirmed();
    void confirm_input();
    void update();
    void update_value();
    void handle_decrement();
    void move_cursor_next();
    void set_value(f32 value);
    int is_confirmed();
    int is_cancelled();
    s32 get_value();
    void set_scale(f32 x, f32 y);
    void create(const char *title);
    void calc_digit_count();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowInputNumberSize, sizeof(TWindowInputNumber) == 0x7C);
LAYOUT_ASSERT(NumberFlagsOffset, offsetof(TWindowInputNumber, inputFlags) == 0x60);
LAYOUT_ASSERT(NumberMinimumOffset, offsetof(TWindowInputNumber, minimum) == 0x64);
LAYOUT_ASSERT(NumberMaximumOffset, offsetof(TWindowInputNumber, maximum) == 0x68);
LAYOUT_ASSERT(NumberInitialOffset, offsetof(TWindowInputNumber, value) == 0x6C);
LAYOUT_ASSERT(NumberScaleOffset, offsetof(TWindowInputNumber, scaleX) == 0x74);

// window_input_number_layout_entries, the layout table window_input_number_layout points at.
struct InputNumberWindowLayout {
    u32 cols;
    u32 rows;
    ValueLayoutRecord rec_0;
};

struct ArrowUV { f32 u, v; };

struct ArrowUVs { ArrowUV uv[2]; };

#endif
