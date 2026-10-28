#ifndef PSO_NETWORK_CLIENT_ID_H
#define PSO_NETWORK_CLIENT_ID_H

#include "types.h"

// This console's client slot in the current game.
extern s32 local_client_id;
// Nonzero while this console runs a subcommand it sent itself.
extern s32 dispatching_own_subcommand;

#endif
