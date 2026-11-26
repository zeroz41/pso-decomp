#ifndef PSO_MAP_FLOORTRANSITION_H
#define PSO_MAP_FLOORTRANSITION_H

#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"

// --- C functions defined in FloorTransition.cpp ---
struct NJS_SPRITE;

void draw_screen_sprite(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth);
extern "C" {
void load_area_scene_and_init(u8 *transition);
}
// --- end of C functions

struct TLobbyScreenQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

#endif
