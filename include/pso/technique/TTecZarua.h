#ifndef PSO_TECHNIQUE_TTECZARUA_H
#define PSO_TECHNIQUE_TTECZARUA_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/player/TargetCursorList.h"

struct TTecZarua : public TTecCircle {
    TTecZarua(saddr source, Vec *pos, TargetCursorList *list, s32 level);
    TTecZarua(saddr source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecZarua();
    virtual void vfunc_6(void *);
    virtual void run_task();
    void calc_range();
    static void create_instance(saddr source, Vec *pos, Vec *target, saddr level);
    virtual void render();
    s32 has_targets;  // set by the target-list constructor: run_task hits targets, not the area
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZarua_size, sizeof(TTecZarua) == 0x14C);
#endif
