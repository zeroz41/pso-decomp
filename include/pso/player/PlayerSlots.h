#ifndef PSO_PLAYER_PLAYERSLOTS_H
#define PSO_PLAYER_PLAYERSLOTS_H

#include "types.h"

struct TObjPlayer;
class TPlyCharData;

TObjPlayer *get_player_by_client_id(s32 client);
// The player of this machine's client, or NULL.
TObjPlayer *get_local_player();
// Allocates and constructs the player for client slot from a character record.
TObjPlayer *create_player_object(s32 slot, s32 role, TPlyCharData *record);
// foreach_player callback: ends the player's camera pan.
int end_player_camera_pan(TObjPlayer *player);

#endif
