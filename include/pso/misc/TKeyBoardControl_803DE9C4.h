#ifndef PSO_MISC_TKEYBOARDCONTROL_803DE9C4_H
#define PSO_MISC_TKEYBOARDCONTROL_803DE9C4_H

#include "types.h"

// One controller's state in keyboard_control_pad_slots (0x34 bytes, four of them),
// filled by TKeyBoardControl::read_pads and returned by TKeyBoardControl__sub_803DEB74.
struct PadSlot {
    s32 f0;
    s32 f4;
    s32 held;
    s32 notHeld;
    s32 pressed;
    s32 released;
    s16 trigR;
    s16 trigL;
    s16 stickX;
    s16 stickY;
    s16 substickX;
    s16 substickY;
    u8 unk24[0xC];
    s32 *conn;
};

extern "C" {
u8 *TKeyBoardControl__sub_803DEB74(u32 arg0);
void init_light_globals(s32, s32);
}

void set_model_render_flags(u32 flags);

#endif
