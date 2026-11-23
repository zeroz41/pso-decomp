#ifndef PSO_EFFECT_ENEMY_TOBJENEHOLDEFFECT_H
#define PSO_EFFECT_ENEMY_TOBJENEHOLDEFFECT_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEneHoldEffect : public TObjBase {
    virtual ~TObjEneHoldEffect();
    virtual void run_task();
    u32 m_90;
    u16 m_94;
    u8 _pad96[0x2];
    u32 m_98;
    u32 m_9c;
    virtual void render();
    static void create(void *parent, s32 type, s32 arg2);
};

LAYOUT_ASSERT(TObjEneHoldEffect_size, sizeof(TObjEneHoldEffect) == 0xA0);
#endif
