#ifndef PSO_ENEMY_TOBJENERECONBOMB_H
#define PSO_ENEMY_TOBJENERECONBOMB_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TObjEneReconBomb : public TObjChara {
    virtual ~TObjEneReconBomb();
    u32 m_334;
    u16 m_338;
    u8 _pad33A[0x2];
    void* m_33c;
    u8 unk_340[0x4];
    f32 m_344;
    f32 m_348;
    u8 unk_34C[0x4];
    f32 m_350;
    u8 unk_354[0x4];
    u32 m_358;
    u32 m_35c;
    u32 m_360;
    virtual void render();
    virtual void run_task();
};

typedef char TObjEneReconBomb_size[sizeof(TObjEneReconBomb) == 0x364 ? 1 : -1];

extern "C" {
u8 *TObjEneReconBomb__ct(TObjEneReconBomb *arg0, s32 arg1, s32 arg2, s32 arg3);
void *__dt__16TObjEneReconBombFv(void *arg0, s16 arg1);
}

#endif
