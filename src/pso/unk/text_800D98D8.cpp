#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/vector.h"

extern Vec TObjEneMe3ShinowaMirage_motion_trail_points[2];
extern s32 lbl_80500FA4[3];

void SampledMotionPoints::sample_node_offsets(NJS_OBJECT *model, NJS_MOTION *motion, s32 node_index, const Vec *first_offset, const Vec *second_offset) {
    lbl_80500FA4[0] = node_index;
    lbl_80500FA4[1] = node_index;
    VecCopy(&TObjEneMe3ShinowaMirage_motion_trail_points[0], first_offset);
    VecCopy(&TObjEneMe3ShinowaMirage_motion_trail_points[1], second_offset);
    sample(model, motion, lbl_80500FA4, TObjEneMe3ShinowaMirage_motion_trail_points);
}
