#ifndef PSO_CAMERA_TCAMERACTRL_801A6E60_H
#define PSO_CAMERA_TCAMERACTRL_801A6E60_H

#include "types.h"

// --- C functions defined in TCameraCtrl_801A6E60.cpp ---
extern "C" {
// pad: a ControllerInputContext; tests its previous_buttons against the packed mask.
s32 test_previous_buttons_packed(void *pad, s32 mask);
}
// --- end of C functions

#endif
