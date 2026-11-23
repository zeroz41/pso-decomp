#ifndef PSO_TECHNIQUE_TTECZONDE_H
#define PSO_TECHNIQUE_TTECZONDE_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecShot.h"

struct TTecZonde : public TTecShot {
    TTecZonde(s32 source, u8 *arg2, u8 *targets, s32 level);
    virtual ~TTecZonde();
    virtual void vfunc_8(void *);
    void init_parameters();
    void render();
    void run_task();
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZonde_size, sizeof(TTecZonde) == 0x18C);
#endif
