#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_803DE9C4_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_803DE9C4_H

#include "types.h"

// One controller's state in keyboard_control_pad_slots (0x34 bytes, four of them),
// filled by TKeyBoardControl::read_pads and returned by get_pad_slot.
struct PadSlot {
    s32 f0;
    s32 f4;
    u32 held;
    u32 notHeld;
    u32 pressed;
    u32 released;
    u16 trigR;
    u16 trigL;
    s16 stickX;
    s16 stickY;
    s16 substickX;
    s16 substickY;
    u8 reserved[0xC];
    s32 *conn;
};

extern PadSlot keyboard_control_pad_slots[4];

extern "C" {
// Device codes 0, 6, 12 and 18 select slots 0-3; any other code gives slot 0.
PadSlot *get_pad_slot(u32 device);
}
void init_light_globals(s32, s32);

void set_model_render_flags(u32 flags);

#endif
