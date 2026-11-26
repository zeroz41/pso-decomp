#ifndef PSO_TECHNIQUE_TTECZONDE_H
#define PSO_TECHNIQUE_TTECZONDE_H

#include "types.h"
#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecShot.h"

struct TTecZonde : public TTecShot {
    TTecZonde(s32 source, u8 *origin, u8 *targets, s32 level);
    virtual ~TTecZonde();
    static void create(void *source, void *origin, void *targets, s32 level);
    virtual void apply_to_target(TObjChara *);
    void init_parameters();
    void render();
    void run_task();
    TargetCursorList targets;
};

LAYOUT_ASSERT(TTecZonde_size, sizeof(TTecZonde) == 0x18C);
#endif
