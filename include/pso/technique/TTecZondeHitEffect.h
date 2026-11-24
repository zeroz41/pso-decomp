#ifndef PSO_TECHNIQUE_TTECZONDEHITEFFECT_H
#define PSO_TECHNIQUE_TTECZONDEHITEFFECT_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Zonde/Gizonde hit effect: spawns a particle effect at the struck point and
// lives for 70 frames.
class TTecZondeHitEffect : public TObject {
public:
    TTecZondeHitEffect(Vec *hit_pos, Vec *source_pos, TObject *parent, s32 effect_id);
    virtual ~TTecZondeHitEffect();
    virtual void run_task();

    Vec m_hit_pos;
    Vec m_source_pos;
    u8 pad_34[4];
    s32 m_timer;
    s32 m_effect_id;
};
LAYOUT_ASSERT(TTecZondeHitEffect_size, sizeof(TTecZondeHitEffect) == 0x40);

#endif
