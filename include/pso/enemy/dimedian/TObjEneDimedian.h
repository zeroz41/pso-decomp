#ifndef PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H
#define PSO_ENEMY_DIMEDIAN_TOBJENEDIMEDIAN_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"

struct TObjEneDimedian : public TUnk_80493450 {
    virtual ~TObjEneDimedian();
    void load_dimedian_param_entry(s32);
    void sub_800A7B54();
    virtual void vfunc_83();
    virtual void vfunc_101();
    virtual void vfunc_99();
    virtual void vfunc_98();
    virtual void vfunc_97();
    virtual void vfunc_96();
    virtual void vfunc_95();
    virtual void vfunc_94();
    virtual void vfunc_93();
    virtual int beast_retire_corpse();
    void* m_3a8;
    u8 _pad3AC[0x18];
    u32 m_3c4;
    u32 m_3c8;
    void* m_3cc;
    static void *create(void *arg0);
    static void free_boss_objects();
    u8 unk_3D0[0x6C];
};

typedef char TObjEneDimedian_size[sizeof(TObjEneDimedian) == 0x43C ? 1 : -1];

extern "C" {
void *TObjEneDimedian__ct(void *arg0_, void *arg1_, void *arg2_);
}

#endif
