#ifndef PSO_TECHNIQUE_TTECSIFTA_H
#define PSO_TECHNIQUE_TTECSIFTA_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecSifta : public TTecPlayerInfluence {
    TTecSifta(void *owner, void *pos, void *arg3, s32 level);
    TTecSifta(void *owner, void *pos, s32 level);
    virtual ~TTecSifta();
    void play_sifta_cast_sound();
    virtual void vfunc_7(void *);
    virtual void run_task();
    u32 m_e0;
    u8 _padE4[0x58];
    u32 m_13c;
    void update_effect_params();
    static void create_instance(void *source, void *origin, void *targets, s32 level);
    static void create(void *arg0, void *arg1, void *arg2);
    virtual void render();
};

LAYOUT_ASSERT(TTecSifta_size, sizeof(TTecSifta) == 0x140);
#endif
