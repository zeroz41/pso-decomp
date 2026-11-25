#ifndef PSO_PLAYER_TOBJPLAYER_801BDF5C_H
#define PSO_PLAYER_TOBJPLAYER_801BDF5C_H

#include "types.h"

extern s32 lobby_player_count;

struct TObjPlayer;
class TPlyCharData;

// --- C functions defined in TObjPlayer_801BDF5C.cpp ---
extern "C" {
// The player of this machine's client, or NULL.
TObjPlayer *get_local_player();
void TObjPlayer__sub_801BE784(void *p, u8 v);
void TObjPlayer__sub_801BE794(void *p, u8 v);
void TObjPlayer__sub_801BE7A4(void *p, u8 v);
void TObjPlayer__sub_801BE7B4(void *p, u8 v);
void TObjPlayer__sub_801BE7E0(void *p, u8 v);
void TObjPlayer__sub_801BE80C(void *p, u8 v);
void TObjPlayer__sub_801BE838(void *p, u8 v);
void TObjPlayer__sub_801BE864(void *p, u8 v);
int TObjPlayer__sub_801BEABC(void *p);
u8 TObjPlayer__sub_801BEB3C(void *p);
u8 TObjPlayer__sub_801BEB44(void *p);
u8 TObjPlayer__sub_801BEB4C(void *p);
void __sinit_TObjPlayer_801BDF5C_cpp(void);
}
// --- end of C functions

// Allocates and constructs the player for client slot from a character record.
TObjPlayer *create_player_object(s32 slot, s32 role, TPlyCharData *record);

#endif
