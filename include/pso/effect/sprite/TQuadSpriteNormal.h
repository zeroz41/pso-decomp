#ifndef PSO_EFFECT_SPRITE_TQUADSPRITENORMAL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITENORMAL_H

#include "types.h"
#include "pso/effect/sprite/TQuadSprite.h"

struct TQuadSpriteNormal : public TQuadSprite {
    TQuadSpriteNormal(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteNormal();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteNormal_size, sizeof(TQuadSpriteNormal) == 0x2C);
#endif
