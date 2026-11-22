#ifndef PSO_UI_CITY_TSHOPGETITEMWINDOW_8021EEE4_H
#define PSO_UI_CITY_TSHOPGETITEMWINDOW_8021EEE4_H

#include "types.h"

struct TObjPlayer;

// The shop's item level: the player's level plus one, clamped to 1..199.
void calc_item_count(TObjPlayer *player, s32 *count);
void init_shop_world_context(void);

#endif
