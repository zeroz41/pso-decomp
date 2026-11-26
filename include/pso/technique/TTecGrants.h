#ifndef PSO_TECHNIQUE_TTECGRANTS_H
#define PSO_TECHNIQUE_TTECGRANTS_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecCircle.h"

struct TTecGrants : public TTecCircle {
    TTecGrants(TObjBase *owner, Vec *origin, TargetCursorList *targets, s32 level);
    virtual ~TTecGrants();
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    TargetCursorList targets;
    s32 frames;
    virtual void render();
    static void create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
    void init_parameters();
};

LAYOUT_ASSERT(TTecGrants_size, sizeof(TTecGrants) == 0x14C);
#endif
