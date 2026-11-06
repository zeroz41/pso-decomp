#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteScl : public TUnk_804C57F0 {
    virtual ~TQuadSpriteScl();
    virtual void render();
};

typedef char TQuadSpriteScl_size[sizeof(TQuadSpriteScl) == 0x2C ? 1 : -1];
#endif
