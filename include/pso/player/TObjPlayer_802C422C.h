#ifndef PSO_PLAYER_TOBJPLAYER_802C422C_H
#define PSO_PLAYER_TOBJPLAYER_802C422C_H

#include "types.h"

class TPlyCharData;
extern "C" {
int TObjPlayer__sub_802C46E0(void *p);
void export_player_record__10TObjPlayerFPvPv(TPlyCharData *record, u8 *arg1);
}
int init_character_action_config(void *p);
extern "C" {
s32 sync_state__10TObjPlayerFi(saddr arg0);
s32 update_battle__10TObjPlayerFi(saddr arg0);
}

#endif
