#ifndef PSO_ENEMY_RECON_TOBJENERECONBOMB_H
#define PSO_ENEMY_RECON_TOBJENERECONBOMB_H

#include "types.h"
#include "pso/object/base/TObjChara.h"

struct BmlResource;

class TObjEneRecon;

struct TObjEneReconBomb : public TObjChara {
    TObjEneReconBomb(TObject *parent, TObjEneRecon *recon, const Vec *pos);
    virtual ~TObjEneReconBomb();
    uaddr m_334;
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
    static void release_resources();
    static void *create(void *parent, void *recon, void *pos);
    static void load_resources();
};

LAYOUT_ASSERT(TObjEneReconBomb_size, sizeof(TObjEneReconBomb) == 0x364);

extern "C" {
void *__dt__16TObjEneReconBombFv(void *arg0, s16 arg1);
}

#endif
