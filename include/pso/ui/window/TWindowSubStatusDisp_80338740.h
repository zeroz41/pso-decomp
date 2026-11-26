#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80338740_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80338740_H

#include "types.h"

// Fills a game list row: lock icon, game name, level, mode mark, difficulty and player count.
void fill_game_list_row(void *row, s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mark, s8 level, s32 index);

extern "C" {
void TWindowSubStatusDisp__sub_803387F8(void *unused, s8 value);
int TWindowSubStatusDisp__sub_80338B88(void *p);
}

#endif
