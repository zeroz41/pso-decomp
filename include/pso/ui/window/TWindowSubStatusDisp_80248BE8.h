#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80248BE8_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80248BE8_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
u8 *TWindowSubStatusDisp__sub_80248BE8(saddr parent, saddr size, s32 client);
}

// --- C functions defined in TWindowSubStatusDisp_80248BE8.cpp ---
extern "C" {
void *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position);
u8 *TWindowSubStatusDisp__sub_80248BE8(saddr parent, saddr size, s32 client);
}
// --- end of C functions

#endif
