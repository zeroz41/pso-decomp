#ifndef PSO_PLAYER_TOBJPLAYER_802C422C_H
#define PSO_PLAYER_TOBJPLAYER_802C422C_H

#include "types.h"

class TPlyDispConfigSmth;

class TPlyCharData;
extern "C" {
void TObjPlayer__sub_802C46E0(TPlyDispConfigSmth *palette, s32 row, s32 index, s32 mode, u16 slot);
}
class TPlyDispConfig;
// Initialises a new character's secondary action palette.
void init_character_action_config(TPlyDispConfig *config);
// Save the local player into `record`; 0 when there is no local player.
s32 capture_local_player_state(TPlyCharData *record);
s32 capture_local_player(TPlyCharData *record);

#endif
