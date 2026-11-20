#ifndef PSO_EFFECT_PARTICLE_PARTICLEDEFINITION_H
#define PSO_EFFECT_PARTICLE_PARTICLEDEFINITION_H

#include "types.h"
#include <stddef.h>

struct GinjaTextureList;
class TUnk_804C57F0;

// One quad-sprite particle kind; create_quad_sprites builds sprite_type's
// TQuadSprite* class for each. Field names inferred from the users.
struct ParticleDefinition {
    u32 flags;
    GinjaTextureList *texlist;
    s32 texture;
    s32 uv_count;
    f32 (*uvs)[4];
    f32 width;
    f32 height;
    u32 color;
    s32 texlist_index;
    s32 sprite_type;
};

typedef char ParticleDefinition_size[sizeof(ParticleDefinition) == 0x28 ? 1 : -1];
typedef char ParticleDefinition_uv_count_offset[offsetof(ParticleDefinition, uv_count) == 0xC ? 1 : -1];

extern "C" {
extern ParticleDefinition lbl_804C5820[0x6C];
extern TUnk_804C57F0 *TParticleCtrl__data_80511F70[0x6C];
}

#endif
