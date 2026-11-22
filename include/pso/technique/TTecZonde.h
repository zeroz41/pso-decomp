#ifndef PSO_TECHNIQUE_TTECZONDE_H
#define PSO_TECHNIQUE_TTECZONDE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecZonde : public TUnk_804CCC68 {
    TTecZonde(s32 source, u8 *arg2, u8 *targets, s32 level);
    virtual ~TTecZonde();
    virtual void vfunc_8(void *);
    void init_parameters();
    void render();
    void run_task();
    u8 unk_130[0x5C];
    u8 *construct_bolt_effect(u8 *parent, u8 *arg2, u8 *arg3, s32 arg4, s32 arg5, f32 farg0, f32 scale);
};

LAYOUT_ASSERT(TTecZonde_size, sizeof(TTecZonde) == 0x18C);
#endif
