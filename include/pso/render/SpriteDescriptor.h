#ifndef PSO_RENDER_SPRITEDESCRIPTOR_H
#define PSO_RENDER_SPRITEDESCRIPTOR_H

#include "types.h"
#include <stddef.h>

struct GinjaTextureList;

struct SpriteFrame {
    s16 width, height, center_x, center_y;
    s16 u0, v0, u1, v1;
    s16 unknown10, unknown12;
};

struct SpriteDescriptor {
    f32 x, y, depth, scale_x, scale_y;
    s32 rotation;
    GinjaTextureList *textures;
    SpriteFrame *frames;

    // Both callers pass a SpriteDescriptor (the radar stack sprite, and the
    // lobby sprite at lbl_804EF3E0). The body reads only these fields.
    void draw_compass_sprite(s32 index, s32 color, s32 flags, f32 depth);
};

typedef char SpriteFrameSize[(sizeof(SpriteFrame) == 0x14) ? 1 : -1];
typedef char SpriteDescriptorSize[(sizeof(SpriteDescriptor) == 0x20) ? 1 : -1];
typedef char SpriteDescriptorRotation[(offsetof(SpriteDescriptor, rotation) == 0x14) ? 1 : -1];
typedef char SpriteDescriptorPointer[(offsetof(SpriteDescriptor, textures) == 0x18) ? 1 : -1];
typedef char SpriteDescriptorFrames[(offsetof(SpriteDescriptor, frames) == 0x1c) ? 1 : -1];

#endif
