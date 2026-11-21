#ifndef PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBULLET_H
#define PSO_BOSS_DRAGON_TBOSS1DRAGONEFFBULLET_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct Vec;

struct TBoss1DragonEffBullet : public TObject {
    TBoss1DragonEffBullet(TObject *parent, Vec *start, Vec *dest);
    virtual ~TBoss1DragonEffBullet();
    void* m_1c;
    u8 _pad20[0x8];
    void* m_28;
    u8 _pad2C[0x8];
    u32 m_34;
    u32 m_38;
    u8 unk_3C[0x4];
    f32 m_40;
    u32 m_44;
    u32 m_48;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TBoss1DragonEffBullet_size, sizeof(TBoss1DragonEffBullet) == 0x4C);

extern "C" {
void *__dt__21TBoss1DragonEffBulletFv(void *arg0, s16 arg1);
}


#endif
