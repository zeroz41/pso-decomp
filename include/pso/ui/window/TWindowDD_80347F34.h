#ifndef PSO_UI_WINDOW_TWINDOWDD_80347F34_H
#define PSO_UI_WINDOW_TWINDOWDD_80347F34_H

#include "types.h"

struct TWindowDD;

extern "C" {
void TWindowDD__sub_80347F48(TWindowDD *window_dd);
void update_word_select_child_position(TWindowDD *window_dd, s32 index);
}

// --- C functions defined in TWindowDD_80347F34.cpp ---
extern "C" {
void TWindowDD__sub_80347F48(TWindowDD *window_dd);
void update_word_select_child_position(TWindowDD *window_dd, s32 index);
}
// --- end of C functions

#endif
