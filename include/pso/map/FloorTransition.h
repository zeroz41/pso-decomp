#ifndef PSO_MAP_FLOORTRANSITION_H
#define PSO_MAP_FLOORTRANSITION_H

#include "types.h"
#include "pso/player/LocalClientId.h"

// --- Free functions defined in FloorTransition.cpp ---
struct NJS_SPRITE;

void draw_screen_sprite(NJS_SPRITE *sprite, s32 frame_index, s32 flags, f32 depth);
// Returns the area initializer's result.
s32 load_area_scene_and_init(FloorTransition *transition);
// --- end of free functions

struct TLobbyScreenQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

union TLobbySpriteColor {
    struct { u8 a, r, g, b; } channels;
    u32 packed;
};

// inferred: the area's name, the function that loads and sets it up, and the one that tears it down
// (load_area_scene_and_init calls init; run_area_scene_cleanup and promote_area_floor call cleanup).
struct AreaInitializer {
    const char *name;
    s32 (*init)();
    void (*cleanup)();
};

#endif
