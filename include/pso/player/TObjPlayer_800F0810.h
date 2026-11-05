#ifndef PSO_PLAYER_TOBJPLAYER_800F0810_H
#define PSO_PLAYER_TOBJPLAYER_800F0810_H

#include "types.h"

struct AltChunkObject;

extern "C" {
void TObjPlayer__sub_800F083C(void);
AltChunkObject *TObjPlayer__sub_800F08AC(AltChunkObject *next, s32 diffuse);
void TObjPlayer__sub_800F0928(void);
s32 is_split_screen__10TObjPlayerFv(void);
}

#endif
