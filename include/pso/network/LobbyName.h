#ifndef PSO_NETWORK_LOBBYNAME_H
#define PSO_NETWORK_LOBBYNAME_H

#include "types.h"

// The lobby name the server sends (packet 0x8A) after start_lobby_name_request.
extern char lobby_name[0x18];
void receive_lobby_name(char *name);
void clear_lobby_name();
s32 start_lobby_name_request();

#endif
