#ifndef PSO_BOSS_TUNK_80484840_H
#define PSO_BOSS_TUNK_80484840_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct VoloptLineColor {
    u8 r, g, b, a;
};

// What draw_line_list draws: pairs of points and their colors.
struct VoloptLineList {
    Vec *points;
    VoloptLineColor *colors;
    s32 pad_8;
    s32 pad_c;
};

// A line Vol Opt draws from one point towards another; it sweeps sideways
// (rotation_y += sweep_speed) until its lifetime runs out.
class TUnk_80484840 : public TObject {
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

    TUnk_80484840(Vec *from, Vec *to, s32 spread, s32 lifetime);
    virtual ~TUnk_80484840();
    virtual void run_task();
    virtual void render();
};

typedef char TUnk_80484840_size[sizeof(TUnk_80484840) == 0x44 ? 1 : -1];

#endif
