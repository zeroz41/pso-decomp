#ifndef PSO_UI_WINDOW_TWINDOWDD_80346A84_H
#define PSO_UI_WINDOW_TWINDOWDD_80346A84_H

#include "types.h"

struct TWindowDD;

// --- C functions defined in TWindowDD_80346A84.cpp ---
extern "C" {
s32 TWindowDD__sub_80346DB8(TWindowDD *window_dd);
s32 TWindowDD__sub_80346F30(TWindowDD *window_dd);
s16 TWindowDD_read_indexed_value(s32 entry_index, s32 value_index);
s16 TWindowDD_read_resolved_value(s32 entry_id, s32 value_index);
}
// --- end of C functions

#endif
