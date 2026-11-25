#ifndef PSO_UNK_TLOBBY_80226C3C_H
#define PSO_UNK_TLOBBY_80226C3C_H

#include "types.h"

// The MusyX allocation hook and the retrace and stream callbacks the sound
// setup installs.
extern "C" {
void *TLobby__sub_80227A4C(u32 size);
void TLobby__sub_80227A6C(void);
int TLobby__sub_80227A70(void *p);
void TLobby__sub_80227A90(s32, const char *);
}

#endif
