#ifndef PSO_UI_WINDOW_TWINDOWINPUTNUMBER_H
#define PSO_UI_WINDOW_TWINDOWINPUTNUMBER_H

#include "types.h"
#include <stddef.h>
#include "pso/ui/window/TWindowBase.h"

class TUnk_804CF9C8;

struct TWindowInputNumber : public TWindowBase {
    s32 is_locked(s32);
    s32 test_input_flag(s32 buttons);
    void refresh_digit_entries();
    void align_digits();
    void draw_arrows(WindowDrawContext *context, TUnk_804CF9C8 *digit, int confirmed);
    virtual void render();
    u16 inputFlags;
    s8 digitCount;
    s8 selectedDigit;
    s32 minimum;
    s32 maximum;
    s32 value;
    saddr unknown70;
    f32 scaleX;
    f32 scaleY;

    TWindowInputNumber(void *position, s32 minimum, s32 maximum, s32 initial, s16 client);
    virtual ~TWindowInputNumber();
    void mark_confirmed();
    void confirm_input();
    void update();
    void update_value();
    void handle_decrement();
    void move_cursor_next();
    void set_value(f32 farg0);
    int is_confirmed();
    int is_cancelled();
    s32 get_value();
    void set_scale(f32 x, f32 y);
    void create(s32 title);
    void calc_digit_count();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowInputNumberSize, sizeof(TWindowInputNumber) == 0x7C);
LAYOUT_ASSERT(NumberFlagsOffset, offsetof(TWindowInputNumber, inputFlags) == 0x60);
LAYOUT_ASSERT(NumberMinimumOffset, offsetof(TWindowInputNumber, minimum) == 0x64);
LAYOUT_ASSERT(NumberMaximumOffset, offsetof(TWindowInputNumber, maximum) == 0x68);
LAYOUT_ASSERT(NumberInitialOffset, offsetof(TWindowInputNumber, value) == 0x6C);
LAYOUT_ASSERT(NumberScaleOffset, offsetof(TWindowInputNumber, scaleX) == 0x74);

#endif
