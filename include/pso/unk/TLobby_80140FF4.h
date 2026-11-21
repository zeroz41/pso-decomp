#ifndef PSO_UNK_TLOBBY_80140FF4_H
#define PSO_UNK_TLOBBY_80140FF4_H

#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"

struct CsnGroup;
struct TObjMapCsn;

extern "C" {
CsnGroup *TLobby__sub_80141030(TObjMapCsn *object);
}

// Floor prepare_adventure_maps (TSceneSora) sets up next through initialize_floor_transition; -1 = none.
extern s32 pending_adventure_map_floor;

#endif
