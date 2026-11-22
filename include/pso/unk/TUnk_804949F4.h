#ifndef PSO_UNK_TUNK_804949F4_H
#define PSO_UNK_TUNK_804949F4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;

class TUnk_804949F4 : public TObject {
public:
    TUnk_804949F4(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius);
    virtual ~TUnk_804949F4();
    virtual void run_task();
    virtual void vfunc_6();
    Vec position;
    f32 radius;
    s32 timer;     // frames since the last emitter move (name inferred)
    s32 interval;  // frames between moves: 2, TUnk_804949D8 8 (name inferred)
    TParticleCtrl *emitter;
};
LAYOUT_ASSERT(TUnk_804949F4_size, sizeof(TUnk_804949F4) == 0x38);

#endif
