#ifndef PSO_PLAYER_TOBJPLAYERACTIONS_H
#define PSO_PLAYER_TOBJPLAYERACTIONS_H

#include "types.h"

struct TObjPlayer;

// --- functions defined in TObjPlayerActions.cpp ---
void release_photon_blast_player_holds(u16 *p);
int get_no_action();
void send_6x33_revive_player(u16 client_id, u16 target_id);
void freeze_players_for_photon_blast(s16 arg0, u16 *arg1);
// The TPlayerReadyCallback that queue_player_injured_pose queues: enters the death state.
void init_subobject(TObjPlayer *player);
void queue_player_injured_pose(TObjPlayer *player);

struct G_Unknown_6x57;

void handle_6x36(void);
void handle_6x41_move_to_position(void);
void handle_6x57(G_Unknown_6x57 *command);
void handle_6xB1(void);
void release_all_players_control_lock(void);

#endif
