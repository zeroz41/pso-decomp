#ifndef PSO_OBJECT_MINE_TOCOMPUTERMACHINE01_8023DD0C_H
#define PSO_OBJECT_MINE_TOCOMPUTERMACHINE01_8023DD0C_H

#include "types.h"

// One corner of the sprite draw_compass_sprite draws.
struct CompassSpriteVertex {
    f32 x, y, z;
    f32 u, v;
    s32 color;
};

// Adds (du, dv) mod 256 to the uvs of every strip after each texture-id chunk
// (type 8) for texture_id in a Ninja chunk polygon list (names inferred).
void scroll_chunk_plist_uvs(s16 *plist, s16 du, s16 dv, u16 texture_id);
// Moves *plist past one chunk: bits chunks (0-5) and the end chunk take one
// s16, a texture-id chunk two, any other chunk its header, size and size s16s.
void advance_chunk_plist(s16 **plist);

#endif
