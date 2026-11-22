#ifndef PSO_UNK_TLOBBY_80228154_H
#define PSO_UNK_TLOBBY_80228154_H

#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"

// --- C functions defined in TLobby_80228154.cpp ---
struct NJS_SPRITE;

extern "C" {
void TLobby__sub_80228154(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth);
void load_area_scene_and_init(u8 *arg0);
}
// --- end of C functions

#endif
