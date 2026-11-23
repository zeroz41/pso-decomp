#ifndef PSO_TEFFHIT_H
#define PSO_TEFFHIT_H
#include "pso/effect/TEffect.h"

class TEffHit : public TEffect {
public:
    TEffHit(const Vec* position);
    virtual ~TEffHit();
    virtual void run_task();
    static const char *class_name;

    s32 state;
};
LAYOUT_ASSERT(HitEffectSize, sizeof(TEffHit) == 0x74);
LAYOUT_ASSERT(HitEffectStateOffset, offsetof(TEffHit, state) == 0x70);
#endif
