#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H

#include "types.h"
#include "pso/effect/sprite/TQuadSprite.h"

struct TQuadSpriteSclCol : public TQuadSprite {
    TQuadSpriteSclCol(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteSclCol();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteSclCol_size, sizeof(TQuadSpriteSclCol) == 0x2C);
#endif
