#ifndef PSO_TECHNIQUE_TTECGRANTS_H
#define PSO_TECHNIQUE_TTECGRANTS_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecCircle.h"

struct TTecGrants : public TTecCircle {
    TTecGrants(saddr arg1, saddr origin, saddr targets, saddr level);
    virtual ~TTecGrants();
    virtual void vfunc_6(void *);
    virtual void run_task();
    TargetCursorList targets;
    s32 m_148;
    virtual void render();
    static void create(void *source, void *origin, void *targets, s32 level);
    void init_parameters();
};

LAYOUT_ASSERT(TTecGrants_size, sizeof(TTecGrants) == 0x14C);
#endif
