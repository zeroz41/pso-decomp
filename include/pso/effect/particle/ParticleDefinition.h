#ifndef PSO_EFFECT_PARTICLE_PARTICLEDEFINITION_H
#define PSO_EFFECT_PARTICLE_PARTICLEDEFINITION_H

#include "types.h"
#include <stddef.h>

struct NJS_TEXLIST;
class TQuadSprite;

// One quad-sprite particle kind; create_quad_sprites builds sprite_type's
// TQuadSprite* class for each.
struct ParticleDefinition {
    u32 flags;
    NJS_TEXLIST *texlist;
    s32 texture;
    s32 uv_count;
    f32 (*uvs)[4];
    f32 width;
    f32 height;
    u32 color;
    s32 texlist_index;
    s32 sprite_type;
};

LAYOUT_ASSERT(ParticleDefinition_size, sizeof(ParticleDefinition) == 0x28);
LAYOUT_ASSERT(ParticleDefinition_uv_count_offset, offsetof(ParticleDefinition, uv_count) == 0xC);

extern "C" {
extern ParticleDefinition particle_definitions[0x6C];
extern TQuadSprite *particle_sprites[0x6C];
}

// Fills the 4x4 sprite sheet UV rects and points every definition at its texture list.
void init_particle_sprite_atlas(void);

#endif
