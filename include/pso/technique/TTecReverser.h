#ifndef PSO_TECHNIQUE_TTECREVERSER_H
#define PSO_TECHNIQUE_TTECREVERSER_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecCircle.h"

struct TechniqueParams;

struct TTecReverser : public TTecCircle {
    TTecReverser(saddr arg1, saddr origin, saddr targets, saddr level);
    virtual ~TTecReverser();
    // Takes speed and lifetime from the parameters and adds the level to their power.
    void apply_params(TechniqueParams *params, s32 level);
    virtual void vfunc_6(void *);
    virtual void run_task();
    TargetCursorList targets;
    virtual void render();
    static void create(void *source, void *origin, void *targets, s32 level);
};

LAYOUT_ASSERT(TTecReverser_size, sizeof(TTecReverser) == 0x148);
#endif
