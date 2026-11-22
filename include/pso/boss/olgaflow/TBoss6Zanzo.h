#ifndef PSO_BOSS_OLGAFLOW_TBOSS6ZANZO_H
#define PSO_BOSS_OLGAFLOW_TBOSS6ZANZO_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>
#include <stddef.h>

struct Boss6TrailPoint { u32 color; Vec position; };
struct Boss6TrailFrame { s32 active; Boss6TrailPoint *points; };

struct TBoss6Zanzo : public TObject {
    TBoss6Zanzo(TObject *object, s32 points, s32 trail_length);
    virtual ~TBoss6Zanzo();
    static TBoss6Zanzo *create(TObject *parent, s32 points, s32 frames);
    void copy_trail_buffer(Boss6TrailFrame *, Boss6TrailFrame *);
    void set_effect_points(const Vec *, const u32 *);
    void sub_803205C4();
    virtual void run_task();
    Boss6TrailFrame *frames;
    Boss6TrailFrame *current;
    s32 point_count;  // points in each trail frame (at least 2)
    s32 frame_count;  // trail frames kept (at least 2)
    virtual void render();
};

LAYOUT_ASSERT(Boss6TrailPoint_size, sizeof(Boss6TrailPoint) == 0x10);
LAYOUT_ASSERT(Boss6TrailPoint_position_offset, offsetof(Boss6TrailPoint, position) == 0x4);
LAYOUT_ASSERT(Boss6TrailFrame_size, sizeof(Boss6TrailFrame) == 0x8);
LAYOUT_ASSERT(TBoss6Zanzo_size, sizeof(TBoss6Zanzo) == 0x2C);
LAYOUT_ASSERT(TBoss6Zanzo_current_offset, offsetof(TBoss6Zanzo, current) == 0x20);
LAYOUT_ASSERT(TBoss6Zanzo_point_count_offset, offsetof(TBoss6Zanzo, point_count) == 0x24);

extern "C" {
void TBoss6Zanzo__sub_803205A0(Boss6TrailPoint *dest, const Boss6TrailPoint *source);
}

#endif
