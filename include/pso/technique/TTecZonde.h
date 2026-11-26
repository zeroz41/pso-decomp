#ifndef PSO_TECHNIQUE_TTECZONDE_H
#define PSO_TECHNIQUE_TTECZONDE_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecShot.h"

struct TTecZonde : public TTecShot {
    TTecZonde(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
    virtual ~TTecZonde();
    static void create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
    virtual void apply_to_target(TObjChara *);
    void init_parameters();
    void render();
    void run_task();
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZonde_size, sizeof(TTecZonde) == 0x18C);

// One bolt of Zonde: it starts at `start`, travels along the unit vector `dir` for `len`.
struct ZondeBolt { Vec start; Vec dir; f32 len; };

#endif
