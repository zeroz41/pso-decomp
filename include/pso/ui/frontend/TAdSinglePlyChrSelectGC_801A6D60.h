#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801A6D60_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801A6D60_H

#include "types.h"

// --- C functions defined in TAdSinglePlyChrSelectGC_801A6D60.cpp ---
extern "C" {
// pad: a controller context (ControllerInputContext, 0x50 bytes; callers pass
// controller_input_state + 0x20 + port * 0x50); mask: the button bits to test.
// Nonzero when a button in mask is pressed.
s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask);
// pad: a ControllerInputContext (callers pass the keyboard context);
// tests its flags_4c against the colour-expanded mask.
s32 test_controller_flag_4c_color(void *pad, s32 mask);
}
// --- end of C functions

#endif
