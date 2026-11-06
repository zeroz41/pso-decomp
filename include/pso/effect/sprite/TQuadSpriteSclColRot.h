#ifndef PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H
#define PSO_EFFECT_SPRITE_TQUADSPRITESCLCOLROT_H

#include "types.h"
#include "pso/unk/TUnk_804C57F0.h"

struct TQuadSpriteSclColRot : public TUnk_804C57F0 {
    virtual ~TQuadSpriteSclColRot();
    virtual void render();
};

typedef char TQuadSpriteSclColRot_size[sizeof(TQuadSpriteSclColRot) == 0x2C ? 1 : -1];

extern "C" {
void *TQuadSpriteSclColRot__ct(void *quad_sprite_scl_col_rot);
}

#endif
