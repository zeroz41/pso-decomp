#ifndef PSO_MISC_TLOBBY_801E43E4_H
#define PSO_MISC_TLOBBY_801E43E4_H

#include "types.h"

// Sends a 6x subcommand to every client and runs it here too.
void send_subcommand(void *cmd);
// Sends a 6x subcommand to the leader (or runs it here offline).
void send_subcommand_to_leader(void *cmd);
extern "C" {
void update_players__6TLobbyFv(s32 arg0);
}

#endif
