#ifndef PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H
#define PSO_OBJECT_AMBIENT_TOBJENVSOUNDGLOBAL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEnvSoundGlobal : public TObjBase {
    TObjEnvSoundGlobal(TObject *parent, saddr set_data);
    virtual ~TObjEnvSoundGlobal();
    u8 unk_90[0x4];
    u32 m_94;
    u32 m_98;
    s32 setup_sound();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEnvSoundGlobal_size, sizeof(TObjEnvSoundGlobal) == 0x9C);

extern "C" {
void *__dt__14TObjEnvSoundExFv(void *arg0, s16 arg1);
void *__dt__18TObjEnvSoundGlobalFv(void *arg0, s16 arg1);
void copy_pair__18TObjEnvSoundGlobalFPvPv(void *p, void *q);
}

#endif
