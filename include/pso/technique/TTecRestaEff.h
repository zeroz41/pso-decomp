#ifndef PSO_TECHNIQUE_TTECRESTAEFF_H
#define PSO_TECHNIQUE_TTECRESTAEFF_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TParticleCtrl;

// Resta's effect on the caster: three timed particle emitters at the
// caster, kept for 180 frames.
class TTecRestaEff : public TObject {
public:
    TTecRestaEff(Vec *pos, s32 owner, TObject *parent);
    virtual ~TTecRestaEff();
    virtual void run_task();

    TParticleCtrl *m_emitters[3];
    s32 m_owner;
    s32 m_timer;
};
LAYOUT_ASSERT(TTecRestaEff_size, sizeof(TTecRestaEff) == 0x30);

#endif
