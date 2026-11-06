#ifndef PSO_TECHNIQUE_TTECRABARTA_H
#define PSO_TECHNIQUE_TTECRABARTA_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecRaBarta : public TUnk_804CC148 {
    virtual ~TTecRaBarta();
    virtual void vfunc_6(void *);
    virtual void vfunc_9();
    virtual void vfunc_8(void *);
    void calc_parameters();
    u32 m_ec;
    u32 m_f0;
    u32 m_f4;
    u8 _padF8[0x40];
    u32 m_138;
    void create(void *arg1, void *arg2);
    virtual void render();
    virtual void run_task();
    void *construct_area(void *source, void *origin, void *level);
};

typedef char TTecRaBarta_size[sizeof(TTecRaBarta) == 0x13C ? 1 : -1];
#endif
