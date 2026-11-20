#ifndef PSO_TEFFGUARD_H
#define PSO_TEFFGUARD_H
#include "pso/effect/TEffect.h"

class TEffGuard : public TEffect {
public:
    TEffGuard(const Vec* position);
    virtual ~TEffGuard();
    virtual void run_task();

    static void create(const Vec* position);

    s32 state;
};
LAYOUT_ASSERT(GuardEffectSize, sizeof(TEffGuard) == 0x74);
LAYOUT_ASSERT(GuardEffectStateOffset, offsetof(TEffGuard, state) == 0x70);
#endif
