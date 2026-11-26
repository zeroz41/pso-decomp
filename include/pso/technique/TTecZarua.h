#ifndef PSO_TECHNIQUE_TTECZARUA_H
#define PSO_TECHNIQUE_TTECZARUA_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/player/TargetCursorList.h"

struct TTecZarua : public TTecCircle {
    static const char *name;
    TTecZarua(TObjBase *source, Vec *pos, TargetCursorList *list, s32 level);
    TTecZarua(TObjBase *source, Vec *pos, Vec *target, s32 level);
    virtual ~TTecZarua();
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    void calc_range();
    static void create_instance(TObjBase *source, Vec *pos, Vec *target, s32 level);
    static void create_instance(TObjBase *caster, Vec *pos, TargetCursorList *targets, s32 level);
    virtual void render();
    s32 has_targets;  // set by the target-list constructor: run_task hits targets, not the area
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZarua_size, sizeof(TTecZarua) == 0x14C);
#endif
