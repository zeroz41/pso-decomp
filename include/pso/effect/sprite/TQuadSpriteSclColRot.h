#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteSclColRot : public TUnk_804C57F0 {
    TQuadSpriteSclColRot(TObject *arg_r4, void *arg2);
    virtual ~TQuadSpriteSclColRot();
    virtual void render();
};

typedef char TQuadSpriteSclColRot_size[sizeof(TQuadSpriteSclColRot) == 0x2C ? 1 : -1];

#endif
