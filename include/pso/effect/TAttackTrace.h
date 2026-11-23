#ifndef PSO_EFFECT_TATTACKTRACE_H
#define PSO_EFFECT_TATTACKTRACE_H

#include <dolphin/mtx.h>
#include "pso/system/task/TObject.h"
#include "pso/system/TrailStrip.h"
#include "types.h"

class TAttackTrace : public TObject {
public:
    TAttackTrace(TObject *parent);
    virtual ~TAttackTrace();
    static const char *class_name;

    s32 segment_count;
};

// The trace an enemy's attack leaves: a strip of up to 16 segments between two
// edge points, drawn additively; the oldest segment fades and is dropped.
class TAttackTraceStrip : public TAttackTrace {
public:
    TAttackTraceStrip(TObject *parent, u32 color_a, u32 color_b);
    static TAttackTraceStrip *create(u32 color_a, u32 color_b);
    void clear_segments();
    virtual ~TAttackTraceStrip();
    virtual void add_segment(Vec *edge_a, Vec *edge_b);
    virtual void shift_line_buffer_down();
    void set_edge_colors(u32 color_a, u32 color_b);
    virtual void render();
    virtual void run_task();
    TrailStripVertex vertices[16]; // two per segment: edge a, edge b
    u32 edge_colors[2];
};
LAYOUT_ASSERT(TAttackTraceStrip_size, sizeof(TAttackTraceStrip) == 0x128);

#endif
