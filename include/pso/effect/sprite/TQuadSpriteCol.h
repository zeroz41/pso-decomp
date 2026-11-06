#ifndef PSO_EFFECT_SPRITE_TQUADSPRITECOL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITECOL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteCol : public TUnk_804C57F0 {
    virtual ~TQuadSpriteCol();
    virtual void render();
};

typedef char TQuadSpriteCol_size[sizeof(TQuadSpriteCol) == 0x2C ? 1 : -1];
#endif
