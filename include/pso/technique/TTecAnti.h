#ifndef PSO_TECHNIQUE_TTECANTI_H
#define PSO_TECHNIQUE_TTECANTI_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecAnti : public TTecPlayerInfluence {
    virtual ~TTecAnti();
    void play_anti_cast_sound();
    virtual void vfunc_7(void *);
    virtual void run_task();
    u32 m_e0;
    u8 _padE4[0x58];
    u32 m_13c;
    static void create(void *arg0, void *arg1, void *arg2, void *arg3);
    void copy_params(u8 *arg1);
    virtual void render();
};

typedef char TTecAnti_size[sizeof(TTecAnti) == 0x140 ? 1 : -1];
#endif
