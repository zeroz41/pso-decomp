#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteSclCol : public TUnk_804C57F0 {
    TQuadSpriteSclCol(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteSclCol();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteSclCol_size, sizeof(TQuadSpriteSclCol) == 0x2C);
#endif
