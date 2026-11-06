#ifndef PSO_BOSS_DRAGON_TOBJBOSS1CRATER_H
#define PSO_BOSS_DRAGON_TOBJBOSS1CRATER_H

#include "types.h"
#include "pso/player/TUnk_804928CC.h"

struct TObjBoss1Crater : public TUnk_804928CC {
    virtual ~TObjBoss1Crater();
    virtual void area_attack_receive_direct(void *, f32 *, void *);
    virtual void run_task();
    virtual void render();
    u8 unk_B0[0x4];
    void * m_b4;
    u8 unk_B8[0x14];
    static s32 is_count_below_limit();
    void *create(void *arg1);
};

typedef char TObjBoss1Crater_size[sizeof(TObjBoss1Crater) == 0xCC ? 1 : -1];

extern "C" {
void *__dt__15TObjBoss1CraterFv(void *arg0, s16 arg1);
}

#endif
