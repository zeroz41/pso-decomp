#ifndef PSO_PLAYER_TOBJPLAYER_802C422C_H
#define PSO_PLAYER_TOBJPLAYER_802C422C_H

#include "types.h"

class TPlyCharData;
extern "C" {
int TObjPlayer__sub_802C46E0(void *p);
}
int init_character_action_config(void *p);
// Save the local player into `record`; 0 when there is no local player.
s32 capture_local_player_state(TPlyCharData *record);
s32 capture_local_player(TPlyCharData *record);

#endif
