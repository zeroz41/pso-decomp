#ifndef PSO_EFFECT_SPRITE_TQUADSPRITECOL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITECOL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteCol : public TUnk_804C57F0 {
    TQuadSpriteCol(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteCol();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteCol_size, sizeof(TQuadSpriteCol) == 0x2C);
#endif
