#ifndef PSO_NPC_TNPCPLAYER_802C3CD0_H
#define PSO_NPC_TNPCPLAYER_802C3CD0_H

#include "types.h"

struct TObjPlayer;
class TPlyCharData;

extern "C" {
void export_character_data__10TObjPlayerFPvPv(TObjPlayer *player, TPlyCharData *character);
void export_state_to_record__10TObjPlayerFPvPv(u8 *player, s8 *character);
}

#endif
