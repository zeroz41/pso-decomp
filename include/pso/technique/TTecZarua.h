#ifndef PSO_TECHNIQUE_TTECZARUA_H
#define PSO_TECHNIQUE_TTECZARUA_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/player/TargetCursorList.h"

struct TTecZarua : public TUnk_804CC148 {
    TTecZarua(s32 source, Vec *pos, TargetCursorList *list, s32 level);
    TTecZarua(s32 source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecZarua();
    virtual void vfunc_6(void *);
    virtual void run_task();
    void calc_range();
    static void create_instance(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    virtual void render();
    s32 has_targets;  // set by the target-list constructor: run_task hits targets, not the area
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZarua_size, sizeof(TTecZarua) == 0x14C);
#endif
