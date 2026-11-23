#ifndef PSO_TECHNIQUE_TTECREVERSER_H
#define PSO_TECHNIQUE_TTECREVERSER_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

struct TechniqueParams;

struct TTecReverser : public TTecCircle {
    TTecReverser(saddr arg1, saddr origin, saddr targets, saddr level);
    virtual ~TTecReverser();
    void sub_8022BE64(TechniqueParams *params, s32 level);
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u16 m_f0;
    virtual void render();
    static void create(void *source, void *origin, void *targets, s32 level);
    s32 is_active();
    u8 unk_F2[0x56];
};

LAYOUT_ASSERT(TTecReverser_size, sizeof(TTecReverser) == 0x148);
#endif
