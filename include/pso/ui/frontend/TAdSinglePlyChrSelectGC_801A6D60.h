#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801A6D60_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801A6D60_H

#include "types.h"

// --- C functions defined in TAdSinglePlyChrSelectGC_801A6D60.cpp ---
extern "C" {
// pad: a controller context (ControllerInputContext, 0x50 bytes; callers pass
// controller_input_state + 0x20 + port * 0x50); mask: the button bits to test.
// Returns int: the body's `!= 0` is a C++ bool widened with clrlwi, and all 229
// call sites test the result with a plain cmpwi (an 8-bit return would add clrlwi).
s32 TWindowShortListCtrl__check_controller_button(void *pad, s32 mask);
// pad: a ControllerInputContext (callers pass the keyboard context, controller_input_state + 0x160);
// tests its flags_4c against the colour-expanded mask.
s32 test_controller_flag_4c_color(void *pad, s32 mask);
}
// --- end of C functions

#endif
