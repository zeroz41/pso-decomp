#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80248BE8_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80248BE8_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

class TWindowCheckBox;

// --- C functions defined in TWindowSubStatusDisp_80248BE8.cpp ---
TWindowCheckBox *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position);
TWindowCheckBox *create_check_box_window_on_layer(const NJS_POINT2 *position, s32 size, s32 client);
// --- end of C functions

#endif
