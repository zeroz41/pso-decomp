#ifndef PSO_UI_WINDOW_TWINDOWDD_80341A08_H
#define PSO_UI_WINDOW_TWINDOWDD_80341A08_H

#include "types.h"

class TWindowDD_WS_Word;

// --- C functions defined in TWindowDD_80341A08.cpp ---
extern "C" {
void hide_word_select_selection(u8 *arg0);
void show_word_select_selection(u8 *arg0);
s16 get_word_select_list_id(u8 *child);
int get_word_select_selected_id(const TWindowDD_WS_Word *window_dd);
s32 get_word_select_first_visible_index(u8 *arg0);
saddr create_word_select_child(s32 element_list, s32 rows);
}
// --- end of C functions

#endif
