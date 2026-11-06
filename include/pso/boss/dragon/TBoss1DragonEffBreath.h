#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBREATH_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBREATH_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss1DragonEffBreath : public TObject {
    TBoss1DragonEffBreath(TObject *arg1, void *arg2, void *arg3);
    virtual ~TBoss1DragonEffBreath();
    void* m_1c;
    u8 _pad20[0x8];
    void* m_28;
    u8 unk_2C[0x4];
    f32 m_30;
    u32 m_34;
    virtual void render();
    virtual void run_task();
};

typedef char TBoss1DragonEffBreath_size[sizeof(TBoss1DragonEffBreath) == 0x38 ? 1 : -1];

extern "C" {
void *__dt__21TBoss1DragonEffBreathFv(void *arg0, s16 arg1);
}

#endif
