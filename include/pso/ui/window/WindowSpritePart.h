#ifndef PSO_UI_WINDOW_WINDOWSPRITEPART_H
#define PSO_UI_WINDOW_WINDOWSPRITEPART_H

#include "types.h"

#include "pso/unk/TUnk_804CF918.h"
#include <stddef.h>

class WindowSpritePart : public TUnk_804CF918 {
public:
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 depth;
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    s32 color;
    s32 *texture_list_slot;
    s32 kind;
};

LAYOUT_ASSERT(WindowSpritePartSize, sizeof(WindowSpritePart) == 0x38);
LAYOUT_ASSERT(WindowSpritePartUvOffset, offsetof(WindowSpritePart, u0) == 0x1C);
LAYOUT_ASSERT(WindowSpritePartKindOffset, offsetof(WindowSpritePart, kind) == 0x34);

#endif
