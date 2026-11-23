#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H

#include "types.h"
#include "pso/effect/sprite/TQuadSprite.h"

// The rotated sprite DVDConvertEntrynumToPath draws: a corner at depth, the two
// screen edges from it, then the texture corner and the matching uv edges.
struct RotatedQuadSpriteRect {
    f32 x;
    f32 y;
    f32 depth;
    f32 edge_a_x;
    f32 edge_a_y;
    f32 edge_b_x;
    f32 edge_b_y;
    u8 pad_1C[0x4];
    f32 u;
    f32 v;
    f32 edge_a_u;
    f32 edge_a_v;
    f32 edge_b_u;
    f32 edge_b_v;
    u8 pad_38[0x8];
};

struct TQuadSpriteSclColRot : public TQuadSprite {
    TQuadSpriteSclColRot(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteSclColRot();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteSclColRot_size, sizeof(TQuadSpriteSclColRot) == 0x2C);

#endif
