#ifndef PSO_TECHNIQUE_TTECGRANTS_H
#define PSO_TECHNIQUE_TTECGRANTS_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecGrants : public TUnk_804CC148 {
    virtual ~TTecGrants();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u16 m_f0;
    u8 _padF2[0x56];
    u32 m_148;
    virtual void render();
    static void create(void *arg0, void *arg1, void *arg2, void *arg3);
    void init_parameters();
};

typedef char TTecGrants_size[sizeof(TTecGrants) == 0x14C ? 1 : -1];
#endif
