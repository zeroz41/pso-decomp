#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteSclColRot : public TUnk_804C57F0 {
    TQuadSpriteSclColRot(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSpriteSclColRot();
    virtual void render();
};

LAYOUT_ASSERT(TQuadSpriteSclColRot_size, sizeof(TQuadSpriteSclColRot) == 0x2C);

#endif
