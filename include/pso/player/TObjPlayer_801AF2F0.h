#ifndef PSO_PLAYER_TOBJPLAYER_801AF2F0_H
#define PSO_PLAYER_TOBJPLAYER_801AF2F0_H

#include "types.h"

struct TObjPlayer;

extern "C" {
TObjPlayer *get_player_by_client_id(s32 client);
void submit_cursor_candidate(void *object, s32 id);
}

#endif
