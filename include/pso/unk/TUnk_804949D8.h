#ifndef PSO_UNK_TUNK_804949D8_H
#define PSO_UNK_TUNK_804949D8_H
#include "types.h"
#include "pso/unk/TUnk_804949F4.h"

class TUnk_804949D8 : public TUnk_804949F4 {
public:
    TUnk_804949D8(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius);
    virtual ~TUnk_804949D8();
    virtual void vfunc_6();
};
LAYOUT_ASSERT(TUnk_804949D8_size, sizeof(TUnk_804949D8) == 0x38);

#endif
