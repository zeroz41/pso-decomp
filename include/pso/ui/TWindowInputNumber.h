#ifndef PSO_UI_TWINDOWINPUTNUMBER_H
#define PSO_UI_TWINDOWINPUTNUMBER_H

#include "types.h"
#include <stddef.h>
#include "pso/TObject.h"

struct TWindowInputNumber {
    s32 is_locked(s32);
    u8 test_input_flag();
    void refresh_digit_entries();
    void align_digits();
    void render();
    u32 className;
    u8 unknown04[0x14];
    void *objectVtable;
    u8 unknown1C[4];
    s16 clientIndex;
    u8 unk_22[0xA];
    s32 m_2c;
    u8 unk_30[0x8];
    f32 m_38;
    u8 unk_3C[0x24];
    u16 inputFlags;
    s8 digitCount;
    s8 selectedDigit;
    s32 minimum;
    s32 maximum;
    s32 value;
    s32 unknown70;
    f32 scaleX;
    f32 scaleY;

    static void *operator new(unsigned long size) {
        return TObject::operator new(size);
    }
    TWindowInputNumber(void *position, s32 minimum, s32 maximum, s32 initial, s16 client);
    void mark_confirmed();
    void confirm_input();
    void update();
    void update_value();
    void handle_decrement();
    void move_cursor_next();
    void set_value(f32 farg0);
    int is_confirmed();
    void create(s32 arg1);
    void calc_digit_count();
    void run_task();
};

typedef char TWindowInputNumberSize[sizeof(TWindowInputNumber) == 0x7C ? 1 : -1];
typedef char NumberVtableOffset[offsetof(TWindowInputNumber, objectVtable) == 0x18 ? 1 : -1];
typedef char NumberClientOffset[offsetof(TWindowInputNumber, clientIndex) == 0x20 ? 1 : -1];
typedef char NumberFlagsOffset[offsetof(TWindowInputNumber, inputFlags) == 0x60 ? 1 : -1];
typedef char NumberMinimumOffset[offsetof(TWindowInputNumber, minimum) == 0x64 ? 1 : -1];
typedef char NumberMaximumOffset[offsetof(TWindowInputNumber, maximum) == 0x68 ? 1 : -1];
typedef char NumberInitialOffset[offsetof(TWindowInputNumber, value) == 0x6C ? 1 : -1];
typedef char NumberScaleOffset[offsetof(TWindowInputNumber, scaleX) == 0x74 ? 1 : -1];

extern "C" {
void *__dt__18TWindowInputNumberFv(void *arg0, s16 arg1);
struct TWindowInputNumber;
void render__18TWindowInputNumberFv(TWindowInputNumber *arg0);
}

#endif
