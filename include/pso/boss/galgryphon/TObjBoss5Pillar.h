#ifndef PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLAR_H
#define PSO_BOSS_GALGRYPHON_TOBJBOSS5PILLAR_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TObjBoss5Pillar : public TObject {
    virtual ~TObjBoss5Pillar();
    virtual void run_task();
    u32 m_1c;
    u8 unk_20[0x4];
    f32 m_24;
    u32 m_28;
    void* m_2c;
    u8 _pad30[0x8];
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    virtual void render();
    static void *create_smoke(void *arg0, void *arg1);
    static void *create(void *arg0);
};

typedef char TObjBoss5Pillar_size[sizeof(TObjBoss5Pillar) == 0x4C ? 1 : -1];

extern "C" {
u8 *TObjBoss5Pillar__ct(TObjBoss5Pillar *arg0, u8 *arg1, u8 *arg2);
void *__dt__15TObjBoss5PillarFv(void *arg0, s16 arg1);
}

#endif
