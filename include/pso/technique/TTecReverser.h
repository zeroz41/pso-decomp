#ifndef PSO_TECHNIQUE_TTECREVERSER_H
#define PSO_TECHNIQUE_TTECREVERSER_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecCircle.h"

struct TechniqueParams;

struct TTecReverser : public TTecCircle {
    TTecReverser(TObjBase *owner, Vec *origin, TargetCursorList *targets, s32 level);
    virtual ~TTecReverser();
    // Takes speed and lifetime from the parameters and adds the level to their power.
    void apply_params(TechniqueParams *params, s32 level);
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    TargetCursorList targets;
    virtual void render();
    static void create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
};

LAYOUT_ASSERT(TTecReverser_size, sizeof(TTecReverser) == 0x148);

// A particle emitter of the revival effect: it starts after `delay` frames, `count` times.
struct RevivalEmitter { s32 delay; s32 count; s32 id; s32 pad; };

#endif
