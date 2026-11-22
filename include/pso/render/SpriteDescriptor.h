#ifndef PSO_RENDER_SPRITEDESCRIPTOR_H
#define PSO_RENDER_SPRITEDESCRIPTOR_H

#include "pso/system/NinjaTypes.h"
#include <stddef.h>

struct GinjaTextureList;

struct SpriteDescriptor {
    f32 x, y, depth, scale_x, scale_y;
    s32 rotation;
    GinjaTextureList *textures;
    NJS_TEXANIM *frames;

    // Both callers pass a SpriteDescriptor (the radar stack sprite, and the
    // lobby sprite at lbl_804EF3E0). The body reads only these fields.
    void draw_compass_sprite(s32 index, s32 color, s32 flags, f32 depth);
};

typedef char SpriteFrameSize[(sizeof(NJS_TEXANIM) == 0x14) ? 1 : -1];
typedef char SpriteDescriptorSize[(sizeof(SpriteDescriptor) == 0x20) ? 1 : -1];
typedef char SpriteDescriptorRotation[(offsetof(SpriteDescriptor, rotation) == 0x14) ? 1 : -1];
typedef char SpriteDescriptorPointer[(offsetof(SpriteDescriptor, textures) == 0x18) ? 1 : -1];
typedef char SpriteDescriptorFrames[(offsetof(SpriteDescriptor, frames) == 0x1c) ? 1 : -1];

#endif
