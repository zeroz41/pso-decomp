#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTSWEEPLINE_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTSWEEPLINE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct VoloptLineColor {
    u8 r, g, b, a;
};

// A line Vol Opt draws from one point towards another; it sweeps sideways
// (rotation_y += sweep_speed) until its lifetime runs out.
class TBoss3VoloptSweepLine : public TObject {
public:
    Vec *from;
    Vec *to;
    s32 lifetime;
    s32 rotation_x;
    s32 rotation_y;
    u8 pad_30[0x8];
    s32 sweep_speed;
    u8 pad_3c[0x4];
    f32 length;

    TBoss3VoloptSweepLine(Vec *from, Vec *to, s32 spread, s32 lifetime);
    virtual ~TBoss3VoloptSweepLine();
    virtual void run_task();
    virtual void render();
};

LAYOUT_ASSERT(TBoss3VoloptSweepLine_size, sizeof(TBoss3VoloptSweepLine) == 0x44);

#endif
