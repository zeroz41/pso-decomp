#ifndef PSO_EFFECT_TUNK_80494968_H
#define PSO_EFFECT_TUNK_80494968_H
#include "types.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/TrailStrip.h"
#include <dolphin/mtx.h>

class TUnk_80494968 : public TAttackTrace {
public:
    TUnk_80494968(TObject *parent, u32 color_a, u32 color_b);
    static TUnk_80494968 *create(u32 color_a, u32 color_b);
    void clear_segments();
    virtual ~TUnk_80494968();
    virtual void add_segment(Vec *edge_a, Vec *edge_b);
    virtual void shift_line_buffer_down();
    void set_edge_colors(u32 color_a, u32 color_b);
    virtual void render();
    virtual void run_task();
    TrailStripVertex vertices[16]; // two per segment: edge a, edge b
    u32 edge_colors[2];
};
LAYOUT_ASSERT(TUnk_80494968_size, sizeof(TUnk_80494968) == 0x128);

#endif
