#ifndef PSO_UI_FRONTEND_TADSELECTCURGC_801A6E20_H
#define PSO_UI_FRONTEND_TADSELECTCURGC_801A6E20_H

#include "types.h"

// --- C functions defined in TAdSelectCurGC.cpp ---
extern "C" {
// pad: a ControllerInputContext; tests previous_buttons against the remapped mask.
s32 test_previous_buttons_remapped(void *pad, s32 mask);
// pad: a ControllerInputContext; tests its previous_buttons against the packed mask.
s32 test_previous_buttons_packed(void *pad, s32 mask);
}
// --- end of C functions

#endif
