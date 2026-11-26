#ifndef PSO_UI_WINDOW_TWINDOWDD_8034435C_H
#define PSO_UI_WINDOW_TWINDOWDD_8034435C_H

#include "types.h"

struct Pair_80344980 { s16 *list; s32 n; };
struct TWindowDD;

extern "C" {
extern uaddr TWindowDD__word_select_lists;
extern char **ws_word_strings;
extern Pair_80344980 *TWindowDD__data_805D6E40;
extern Pair_80344980 *TWindowDD__data_805D6E44;
extern u8 *TWindowDD__data_805D6E48;
s32 get_initial_word_select_list(TWindowDD *window_dd);
saddr get_word_select_token_text(s16 id);
}

#endif
