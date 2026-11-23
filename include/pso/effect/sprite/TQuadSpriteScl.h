#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCL_H

#include "types.h"
#include "pso/effect/sprite/TQuadSprite.h"

struct TQuadSpriteScl : public TQuadSprite {
    TQuadSpriteScl(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteScl();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteScl_size, sizeof(TQuadSpriteScl) == 0x2C);
#endif
