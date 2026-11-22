#ifndef PSO_TECHNIQUE_TTECANTI_H
#define PSO_TECHNIQUE_TTECANTI_H

#include "types.h"
#include "pso/technique/TTecPlayerInfluence.h"

struct TTecAnti : public TTecPlayerInfluence {
    TTecAnti(void *owner, void *pos, void *targets, s32 level);
    virtual ~TTecAnti();
    void play_anti_cast_sound();
    virtual void vfunc_7(void *);
    virtual void run_task();
    u32 m_e0;
    u8 _padE4[0x58];
    u32 m_13c;
    static void create(void *source, void *origin, void *targets, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecAnti_size, sizeof(TTecAnti) == 0x140);
#endif
