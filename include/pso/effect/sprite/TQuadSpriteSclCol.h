#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOL_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteSclCol : public TUnk_804C57F0 {
    virtual ~TQuadSpriteSclCol();
    virtual void render();
};

typedef char TQuadSpriteSclCol_size[sizeof(TQuadSpriteSclCol) == 0x2C ? 1 : -1];
#endif
