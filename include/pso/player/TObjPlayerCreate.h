#ifndef PSO_PLAYER_TOBJPLAYERCREATE_H
#define PSO_PLAYER_TOBJPLAYERCREATE_H

#include "types.h"

class TObjPlayer;

// Builds the TObjPlayer for a player who joins from the network record.
TObjPlayer *create_remote_player_object(void *record);

#endif
