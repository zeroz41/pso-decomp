#ifndef PSO_TECHNIQUE_TTECJELIN_H
#define PSO_TECHNIQUE_TTECJELIN_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecJelin : public TUnk_804CC148 {
    virtual ~TTecJelin();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u32 m_f0;
    void init_tech_params();
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    virtual void render();
    u8 unk_F4[0x58];
};

typedef char TTecJelin_size[sizeof(TTecJelin) == 0x14C ? 1 : -1];
#endif
