#ifndef PSO_UI_HUD_TRADERMAPCORE_801A6CEC_H
#define PSO_UI_HUD_TRADERMAPCORE_801A6CEC_H

#include "types.h"

extern "C" {
s32 TRaderMapCore__sub_801A6D00(void *arg0, s32 mask);
s32 pack_flags__13TRaderMapCoreFii(s32 input, s32 mask);
}

// --- C functions defined in TRaderMapCore_801A6CEC.cpp ---
extern "C" {
s32 TRaderMapCore__sub_801A6D00(void *arg0, s32 mask);
// pad: a ControllerInputContext; tests flags_04 against the packed mask.
s32 test_flags_04_packed(void *pad, s32 mask);
}
// --- end of C functions

#endif
