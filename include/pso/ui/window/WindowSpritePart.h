#ifndef PSO_UI_WINDOW_WINDOWSPRITEPART_H
#define PSO_UI_WINDOW_WINDOWSPRITEPART_H

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

typedef char WindowSpritePartSize[sizeof(WindowSpritePart) == 0x38 ? 1 : -1];
typedef char WindowSpritePartUvOffset[offsetof(WindowSpritePart, u0) == 0x1C ? 1 : -1];
typedef char WindowSpritePartKindOffset[offsetof(WindowSpritePart, kind) == 0x34 ? 1 : -1];

#endif
