#ifndef PSO_UNK_SAMPLEDMOTIONPOINTS_H
#define PSO_UNK_SAMPLEDMOTIONPOINTS_H

#include "types.h"
#include <dolphin/mtx.h>

struct NJS_OBJECT;
struct NJS_MOTION;

struct SampledMotionPoints {
    Vec *points;
    s32 points_per_sample;
    s32 sample_count;
    f32 start;
    f32 end;
    f32 step;

    SampledMotionPoints(s32 points_per_sample, f32 start, f32 end, f32 step);
    ~SampledMotionPoints();
    Vec *lookup(f32 frame);
    void sample(NJS_OBJECT *model, NJS_MOTION *motion, const s32 *node_indices, const Vec *offsets);
    void sample_two_nodes(NJS_OBJECT *model, NJS_MOTION *motion, s32 first_node, s32 second_node);
    void sample_node_offsets(NJS_OBJECT *model, NJS_MOTION *motion, s32 node_index, const Vec *first_offset, const Vec *second_offset);
};

typedef char SampledMotionPoints_size[sizeof(SampledMotionPoints) == 0x18 ? 1 : -1];

#endif
