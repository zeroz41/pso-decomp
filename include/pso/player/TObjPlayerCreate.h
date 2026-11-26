#ifndef PSO_PLAYER_TOBJPLAYERCREATE_H
#define PSO_PLAYER_TOBJPLAYERCREATE_H

#include "types.h"
#include "pso/player/PlayerCharDataEntry.h"

class TObjPlayer;

// Builds the TObjPlayer for a player who joins from the network record.
TObjPlayer *create_remote_player_object(PlayerSyncRecord *record);

// The player load and release hooks of the game and lobby scene callback tables: the shared
// buffers, motion data, cursor and footstamp resources, and the player counters.
void init_player_shared();
void finalize_player_shared();

#endif
