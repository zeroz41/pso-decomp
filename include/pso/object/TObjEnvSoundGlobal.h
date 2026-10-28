#ifndef PSO_OBJECT_TOBJENVSOUNDGLOBAL_H
#define PSO_OBJECT_TOBJENVSOUNDGLOBAL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjEnvSoundGlobal : public TObjBase {
    virtual ~TObjEnvSoundGlobal();
    u8 unk_90[0x4];
    u32 m_94;
    u32 m_98;
    s32 setup_sound();
    virtual void render();
    virtual void run_task();
};

typedef char TObjEnvSoundGlobal_size[sizeof(TObjEnvSoundGlobal) == 0x9C ? 1 : -1];

extern "C" {
void *TObjEnvSoundEx__create(void *arg0);
u8 *TObjEnvSoundEx__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 *TObjEnvSoundGlobal__ct(u8 *arg0, s32 parent, s32 arg2);
void *__dt__14TObjEnvSoundExFv(void *arg0, s16 arg1);
void *__dt__18TObjEnvSoundGlobalFv(void *arg0, s16 arg1);
void copy_pair__18TObjEnvSoundGlobalFPvPv(void *p, void *q);
}

#endif
