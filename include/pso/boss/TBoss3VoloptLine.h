#ifndef PSO_BOSS_TBOSS3VOLOPTLINE_H
#define PSO_BOSS_TBOSS3VOLOPTLINE_H

#include "types.h"
#include "pso/boss/TBoss3VoloptSweepLine.h"

// A line Vol Opt draws between two points.
class TBoss3VoloptLine : public TObject {
public:
    Vec *from;
    Vec *to;
    u8 pad_24[0x4];

    TBoss3VoloptLine(Vec *from, Vec *to);
    virtual ~TBoss3VoloptLine();
    virtual void run_task();
    virtual void render();
};

LAYOUT_ASSERT(TBoss3VoloptLine_size, sizeof(TBoss3VoloptLine) == 0x28);

#endif
