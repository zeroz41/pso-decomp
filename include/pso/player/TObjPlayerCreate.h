#ifndef PSO_PLAYER_TOBJPLAYERCREATE_H
#define PSO_PLAYER_TOBJPLAYERCREATE_H

#include "types.h"
#include "pso/player/PlayerCharDataEntry.h"

class TObjPlayer;

extern PlayerCharDataEntry TObjPlayer__char_data_array[12];

// Builds the TObjPlayer for a player who joins from the network record.
TObjPlayer *create_remote_player_object(void *record);

#endif
