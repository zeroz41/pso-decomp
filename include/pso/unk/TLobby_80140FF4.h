#ifndef PSO_UNK_TLOBBY_80140FF4_H
#define PSO_UNK_TLOBBY_80140FF4_H

#include "types.h"

struct CsnGroup;
struct TObjMapCsn;

extern "C" {
CsnGroup *TLobby__sub_80141030(TObjMapCsn *object);
void TLobby__sub_80141038(u8 *arg0, s32 arg1, s32 arg2);
}

// Floor prepare_adventure_maps (TSceneSora) sets up next through TLobby__sub_80141038; -1 = none.
extern s32 pending_adventure_map_floor;

#endif
