#ifndef PSO_PLAYER_TOBJPLAYER_802C367C_H
#define PSO_PLAYER_TOBJPLAYER_802C367C_H

#include "types.h"

extern "C" {
int init_new_character_data(void *p);
void init_new_character_stats(void *player);
void init_technique_levels(s32 flags, s8 *counts);
}

// --- C functions defined in TObjPlayer_802C367C.cpp ---
extern "C" {
int init_new_character_data(void *p);
void init_new_character_stats(void *player);
void init_technique_levels(s32 flags, s8 *counts);
}
// --- end of C functions

#endif
