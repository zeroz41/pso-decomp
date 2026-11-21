#ifndef PSO_SYSTEM_SCENE_TENDINGAB_H
#define PSO_SYSTEM_SCENE_TENDINGAB_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

// Same eight-float rectangle consumed by draw_textured_quad_at_depth.
struct EndingWallQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

class TEndingAB : public TObject {
public:
    TEndingAB(TObject *parent);
    virtual ~TEndingAB();
    virtual void run_task();
    virtual void render();

    void advance_fade_sequence();
    void draw_overlay();
    static void set_fish_global_param();
    void init_float_table();
    static void destroy_instance();

    s32 elapsed_ticks;
    s32 field_20;
    s32 picture_index;
    s32 wall_index;
    EndingWallQuad quads[6];
    s32 timing_rate;
};

LAYOUT_ASSERT(EndingWallQuadSize, sizeof(EndingWallQuad) == 0x20);
LAYOUT_ASSERT(EndingABSize, sizeof(TEndingAB) == 0xF0);
LAYOUT_ASSERT(EndingABQuadsOffset, offsetof(TEndingAB, quads) == 0x2C);
LAYOUT_ASSERT(EndingABRateOffset, offsetof(TEndingAB, timing_rate) == 0xEC);

#endif
