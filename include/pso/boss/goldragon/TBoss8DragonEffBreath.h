#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGONEFFBREATH_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TBoss8DragonEffBreath : public TObject {
    TBoss8DragonEffBreath(TObject *parent, void *p, void *v, s32 a, s16 b);
    virtual ~TBoss8DragonEffBreath();
    void* m_1c;
    u8 _pad20[0x8];
    void* m_28;
    u8 _pad2C[0x8];
    u32 m_34;
    u16 m_38;
    u8 _pad3A[0x2];
    u32 m_3c;
    virtual void render();
    virtual void run_task();
};

typedef char TBoss8DragonEffBreath_size[sizeof(TBoss8DragonEffBreath) == 0x40 ? 1 : -1];

extern "C" {
void *__dt__21TBoss8DragonEffBreathFv(void *arg0, s16 arg1);
}

#endif
