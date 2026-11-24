#ifndef PSO_PLAYER_TOBJPLAYER_801C7430_H
#define PSO_PLAYER_TOBJPLAYER_801C7430_H

#include "types.h"

struct TObjPlayer;

// --- functions defined in TObjPlayer_801C7430.cpp ---
extern "C" {
void release_photon_blast_player_holds(u16 *p);
void send_6x33_revive_player(u16 client_id, s16 type);
int ret_801D26AC(void);
}
void freeze_players_for_photon_blast(s16 arg0, u16 *arg1);
// The TPlayerReadyCallback that queue_player_injured_pose queues: enters the death state.
void init_subobject(TObjPlayer *player);
void queue_player_injured_pose(TObjPlayer *player);

#endif
