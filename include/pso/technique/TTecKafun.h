#ifndef PSO_TECHNIQUE_TTECKAFUN_H
#define PSO_TECHNIQUE_TTECKAFUN_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecKafun : public TUnk_804CC148 {
    virtual ~TTecKafun();
    virtual void vfunc_6(void *);
    u8 _padEC[0x4];
    u32 m_f0;
    u32 m_f4;
    u32 m_f8;
    u32 m_fc;
    virtual void render();
    virtual void run_task();
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 farg0, f32 farg1);
    static void create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0, f32 farg1);
};

typedef char TTecKafun_size[sizeof(TTecKafun) == 0x100 ? 1 : -1];
#endif
