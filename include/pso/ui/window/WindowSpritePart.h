#ifndef PSO_UI_WINDOW_WINDOWSPRITEPART_H
#define PSO_UI_WINDOW_WINDOWSPRITEPART_H

#include "types.h"

struct NJS_TEXLIST;

#include "pso/unk/TWindowLayoutEntry.h"
#include <stddef.h>

struct SpritePartLayoutRecord;
struct DirectSpritePartLayoutRecord;

class WindowSpritePart : public TWindowLayoutEntry {
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
    NJS_TEXLIST **texture_list_slot;
    s32 kind;

    WindowSpritePart *init_part_scaled(SpritePartLayoutRecord *source, s32 client);
    WindowSpritePart *init_part_direct(DirectSpritePartLayoutRecord *source, s32 client);
};

LAYOUT_ASSERT(WindowSpritePartSize, sizeof(WindowSpritePart) == 0x38);
LAYOUT_ASSERT(WindowSpritePartUvOffset, offsetof(WindowSpritePart, u0) == 0x1C);
LAYOUT_ASSERT(WindowSpritePartKindOffset, offsetof(WindowSpritePart, kind) == 0x34);

#endif
