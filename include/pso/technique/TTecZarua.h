#ifndef PSO_TECHNIQUE_TTECZARUA_H
#define PSO_TECHNIQUE_TTECZARUA_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecZarua : public TUnk_804CC148 {
    virtual ~TTecZarua();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u32 m_f0;
    void calc_range();
    static void create_instance(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    virtual void render();
    u8 unk_F4[0x58];
};

typedef char TTecZarua_size[sizeof(TTecZarua) == 0x14C ? 1 : -1];
#endif
