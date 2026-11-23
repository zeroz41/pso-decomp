#ifndef PSO_PLAYER_TOBJPLAYER_802C367C_H
#define PSO_PLAYER_TOBJPLAYER_802C367C_H

#include "types.h"

class TPlyCharData;

extern "C" {
int init_new_character_data(void *p);
void init_new_character_stats(TPlyCharData *character);
void init_character_stats_for_level(s32 class_index, TPlyCharData *character, s32 level);
void init_technique_levels(s32 flags, s8 *counts);
}
#endif
