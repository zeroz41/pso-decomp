#ifndef PSO_TECHNIQUE_TTECRAZONDE_H
#define PSO_TECHNIQUE_TTECRAZONDE_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TTecRaZonde : public TUnk_804CC148 {
    virtual ~TTecRaZonde();
    virtual void vfunc_8(void *);
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    void calc_damage();
    void create(void *arg1, void *arg2);
    virtual void render();
    u8 unk_F0[0x60];
};

typedef char TTecRaZonde_size[sizeof(TTecRaZonde) == 0x150 ? 1 : -1];
#endif
