#ifndef PSO_TECHNIQUE_TTECJELIN_H
#define PSO_TECHNIQUE_TTECJELIN_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/player/TargetCursorList.h"

struct TTecJelin : public TTecCircle {
    TTecJelin(saddr source, Vec *pos, TargetCursorList *list, s32 level);
    TTecJelin(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecJelin();
    virtual void vfunc_6(void *);
    virtual void run_task();
    void init_tech_params();
    static void create(saddr source, saddr pos, saddr target, s32 level);
    virtual void render();
    s32 has_targets;  // set by the target-list constructor: run_task hits targets, not the area
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecJelin_size, sizeof(TTecJelin) == 0x14C);
#endif
