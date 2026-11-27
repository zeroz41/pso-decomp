#ifndef PSO_PLAYER_TOBJPLAYER_802C367C_H
#define PSO_PLAYER_TOBJPLAYER_802C367C_H

#include "types.h"

class TPlyCharData;
class TPlyDispConfig;

int init_new_character_data(TPlyCharData *record);
void init_new_character_stats(TPlyCharData *character);
void init_character_stats_for_level(s32 class_index, TPlyCharData *character, s32 level);
void init_technique_levels(s32 flags, u8 *counts);
// Initialises a new character's secondary action palette.
void init_character_action_config(TPlyDispConfig *config);
// Save the local player into `record`; 0 when there is no local player.
s32 capture_local_player_state(TPlyCharData *record);
s32 capture_local_player(TPlyCharData *record);
#endif
