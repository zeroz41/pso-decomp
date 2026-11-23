#ifndef PSO_UNK_TUNK_804CCBC0_H
#define PSO_UNK_TUNK_804CCBC0_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TParticleCtrl;

// Resta's effect on the caster: three timed particle emitters at the
// caster, kept for 180 frames.
class TUnk_804CCBC0 : public TObject {
public:
    TUnk_804CCBC0(Vec *pos, s32 owner, TObject *parent);
    virtual ~TUnk_804CCBC0();
    virtual void run_task();

    TParticleCtrl *m_emitters[3];
    s32 m_owner;
    s32 m_timer;
};
LAYOUT_ASSERT(TUnk_804CCBC0_size, sizeof(TUnk_804CCBC0) == 0x30);

#endif
