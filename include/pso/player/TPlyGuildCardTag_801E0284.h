#ifndef PSO_PLAYER_TPLYGUILDCARDTAG_801E0284_H
#define PSO_PLAYER_TPLYGUILDCARDTAG_801E0284_H

#include "types.h"

struct LobbyListHeaderCopy {
    u8 bytes[4];
};

void *copy_lobby_entry(void *dst, void *src);

#endif
