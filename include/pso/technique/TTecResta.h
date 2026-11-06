#ifndef PSO_TECHNIQUE_TTECRESTA_H
#define PSO_TECHNIQUE_TTECRESTA_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecResta : public TTecPlayerInfluence {
    virtual ~TTecResta();
    virtual void vfunc_7(void *);
    virtual void run_task();
    u32 m_e0;
    u8 _padE4[0x58];
    u32 m_13c;
    void play_launch_sound();
    int init_cast();
    static f32 calc_heal_amount(s32 arg0);
    void init_parameters();
    static void create(void *arg0, void *arg1, void *arg2);
    virtual void render();
};

typedef char TTecResta_size[sizeof(TTecResta) == 0x140 ? 1 : -1];
#endif
