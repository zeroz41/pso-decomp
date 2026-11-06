#ifndef PSO_TECHNIQUE_TTECGIFOIE_H
#define PSO_TECHNIQUE_TTECGIFOIE_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecGiFoie : public TUnk_804CC148 {
    virtual ~TTecGiFoie();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u8 _padF0[0x48];
    u32 m_138;
    void calc_params();
    static void create(void *arg0, void *arg1, void *arg2);
    virtual void render();
};

typedef char TTecGiFoie_size[sizeof(TTecGiFoie) == 0x13C ? 1 : -1];
#endif
