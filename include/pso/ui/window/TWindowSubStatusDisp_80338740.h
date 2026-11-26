#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80338740_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80338740_H

#include "types.h"

// Fills a game list row: lock icon, game name, episode, mode, difficulty and player count.
void fill_game_list_row(void *row, s32 locked, const char *name, s8 player_count, s8 max_players, s8 difficulty, s8 mode, s8 episode, s32 index);

extern "C" {
void get_difficulty_name(void *unused, s8 value);
int TWindowSubStatusDisp__sub_80338B88(void *p);
}

#endif
