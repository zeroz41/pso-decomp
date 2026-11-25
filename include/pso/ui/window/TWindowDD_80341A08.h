#ifndef PSO_UI_WINDOW_TWINDOWDD_80341A08_H
#define PSO_UI_WINDOW_TWINDOWDD_80341A08_H

#include "types.h"

class TWindowDD_WS_Word;

// --- C functions defined in TWindowDD_80341A08.cpp ---
extern "C" {
void TWindowDD__sub_80341AE0(TWindowDD_WS_Word *page);
void TWindowDD__sub_80341AF8(TWindowDD_WS_Word *page);
s16 TWindowDD__sub_8034214C(const TWindowDD_WS_Word *page);
int get_word_select_selected_id(const TWindowDD_WS_Word *window_dd);
s32 TWindowDD__sub_8034217C(const TWindowDD_WS_Word *page);
TWindowDD_WS_Word *TWindowDD__sub_80342384(s32 element_list, s32 rows);
}
// --- end of C functions

#endif
