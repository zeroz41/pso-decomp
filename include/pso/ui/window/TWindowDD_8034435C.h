#ifndef PSO_UI_WINDOW_TWINDOWDD_8034435C_H
#define PSO_UI_WINDOW_TWINDOWDD_8034435C_H

#include "types.h"

// The word-select state that the window code (TWindowDD_803430BC.cpp) sets up and the
// word-select formatters (TWindowDD_8034435C.cpp) read.
struct Pair_80344980 { s16 *list; s32 n; };

struct WordSelectDataTable {
    u8 pad0[0x78];
    s16 *primary_values;
    u8 pad7C[4];
    s16 *fallback_values;
};

struct WordSelectMenuState {
    u8 pad0[0x1C];
    s16 menu_index;
    u8 pad1E[0xDE];
    s16 selected_word;
};

extern "C" {
extern s32 TWindowDD__window_mode;
extern uaddr TWindowDD__word_select_lists;
extern u8 *TWindowDD__ws_data_table;
extern char **TWindowDD__data_805D6E28;
extern Pair_80344980 *TWindowDD__data_805D6E40;
extern Pair_80344980 *TWindowDD__data_805D6E44;
extern u8 *TWindowDD__data_805D6E48;
s32 TWindowDD__sub_80346DB8(saddr window_dd);
saddr get_word_select_token_text(s16 id);
}

// --- C functions defined in TWindowDD_8034435C.cpp ---
extern "C" {
void build_item_list__9TWindowDDFPv(u8 *arg0);
}
// --- end of C functions

#endif
