#ifndef PSO_BOSS_TOBJBOSS2CEILJUNK_H
#define PSO_BOSS_TOBJBOSS2CEILJUNK_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjBoss2CeilJunk : public TObjBase {
    virtual ~TObjBoss2CeilJunk();
    virtual void run_task();
    void* m_90;
    u8 _pad94[0x8];
    void* m_9c;
    u8 _padA0[0x8];
    u32 m_a8;
    u32 m_ac;
    u32 m_b0;
    virtual void render();
    static void *create(void *arg0);
    static void create_particle();
    u8 unk_B4[0x4];
};

typedef char TObjBoss2CeilJunk_size[sizeof(TObjBoss2CeilJunk) == 0xB8 ? 1 : -1];

extern "C" {
void *__dt__17TObjBoss2CeilJunkFv(void *arg0, s16 arg1);
}

#endif
