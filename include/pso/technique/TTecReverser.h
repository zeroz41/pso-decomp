#ifndef PSO_TECHNIQUE_TTECREVERSER_H
#define PSO_TECHNIQUE_TTECREVERSER_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecReverser : public TUnk_804CC148 {
    virtual ~TTecReverser();
    void sub_8022BE64(u8 *, s32);
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u16 m_f0;
    virtual void render();
    static void create(void *arg0, void *arg1, void *arg2, void *arg3);
    u8 is_active();
    u8 unk_F2[0x56];
};

typedef char TTecReverser_size[sizeof(TTecReverser) == 0x148 ? 1 : -1];
#endif
