#ifndef PSO_EFFECT_SPRITE_TQUADSPRITENORMAL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITENORMAL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteNormal : public TUnk_804C57F0 {
    TQuadSpriteNormal(TObject *arg_r4, void *arg2);
    virtual ~TQuadSpriteNormal();
    virtual void render();
};

typedef char TQuadSpriteNormal_size[sizeof(TQuadSpriteNormal) == 0x2C ? 1 : -1];
#endif
