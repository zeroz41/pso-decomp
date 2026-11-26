#ifndef PSO_UI_WINDOW_TWINDOWDD_80346A84_H
#define PSO_UI_WINDOW_TWINDOWDD_80346A84_H

#include "types.h"

struct TWindowDD;

// --- C functions defined in TWindowDD_80346A84.cpp ---
s32 has_menu_selection(TWindowDD *window_dd);
extern "C" {
s32 get_initial_word_select_list(TWindowDD *window_dd);
s16 TWindowDD_read_indexed_value(s32 entry_index, s32 value_index);
s16 TWindowDD_read_resolved_value(s32 entry_id, s32 value_index);
}
// --- end of C functions

#endif
