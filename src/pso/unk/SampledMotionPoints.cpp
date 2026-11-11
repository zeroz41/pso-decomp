#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D853C.h"
#include "types.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/animation/MotionContext.h"
#include "pso/math/FloatRounding.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/memory.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
Vec *lbl_805D5230;
s32 lbl_805D5234;
s32 motion_trail_node_index;
const s32 *lbl_805D523C;
const Vec *TBoss4Type3__motion_trail_points;
extern Vec lbl_80500F80;
s32 transform_motion_node_points(SampledMotionPoints *arg0, NJS_OBJECT *node, s32 idx);
}

Vec *SampledMotionPoints::lookup(f32 frame) {
    f32 first = start;
    if ((frame < first) || (frame > end)) {
        return 0;
    }
    f32 sample_position = frame - first;
    sample_position += 0.01f;
    sample_position /= step;
    s32 index = (s32)floor_to_float(sample_position);
    return points + points_per_sample * index;
}

extern "C" {
s32 transform_motion_node_points(SampledMotionPoints *arg0, NJS_OBJECT *node, s32 idx) {
    u32 flags;
    do {
        push_matrix();
        compose_motion_node_matrix(node);
        flags = node->evalflags;
        while (idx == lbl_805D523C[motion_trail_node_index]) {
            if (TBoss4Type3__motion_trail_points == NULL) {
                matrix_mult_vec(0, &lbl_80500F80, lbl_805D5230);
            } else {
                matrix_mult_vec(0, &TBoss4Type3__motion_trail_points[motion_trail_node_index], lbl_805D5230);
            }
            lbl_805D5230++;
            motion_trail_node_index++;
        }
        idx++;
        if (!(flags & 0x10)) {
            idx = transform_motion_node_points(arg0, node->child, idx);
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL && motion_trail_node_index < lbl_805D5234);
    return idx;
}
}

extern Vec TObjEneMe3ShinowaMirage_motion_trail_points[2];
extern s32 lbl_80500FA4[3];

void SampledMotionPoints::sample_node_offsets(NJS_OBJECT *model, NJS_MOTION *motion, s32 node_index, const Vec *first_offset, const Vec *second_offset) {
    lbl_80500FA4[0] = node_index;
    lbl_80500FA4[1] = node_index;
    VecCopy(&TObjEneMe3ShinowaMirage_motion_trail_points[0], first_offset);
    VecCopy(&TObjEneMe3ShinowaMirage_motion_trail_points[1], second_offset);
    sample(model, motion, lbl_80500FA4, TObjEneMe3ShinowaMirage_motion_trail_points);
}

extern "C" {
Vec lbl_80500F80;
Vec TObjEneMe3ShinowaMirage_motion_trail_points[2];
s32 lbl_80500FA4[3];
void *mem_alloc(u32 size);
void mem_free(void *p);

void SampledMotionPoints::sample_two_nodes(NJS_OBJECT *model, NJS_MOTION *motion, s32 first_node, s32 second_node) {
    lbl_80500FA4[0] = first_node;
    lbl_80500FA4[1] = second_node;
    sample(model, motion, lbl_80500FA4, NULL);
}

void SampledMotionPoints::sample(NJS_OBJECT *model, NJS_MOTION *motion, const s32 *node_indices, const Vec *offsets) {
    f32 f;
    s32 i;
    set_motion_packed_rotation();
    lbl_80500F80.x = 0.0f;
    lbl_80500F80.y = 0.0f;
    lbl_80500F80.z = 0.0f;
    lbl_805D5230 = points;
    lbl_805D5234 = points_per_sample;
    lbl_805D523C = node_indices;
    TBoss4Type3__motion_trail_points = offsets;
    push_matrix();
    f = start;
    for (i = 0; i < sample_count; i++) {
        motion_trail_node_index = 0;
        set_matrix_identity(0);
        bind_motion_context(motion, f);
        transform_motion_node_points(this, model, 0);
        f += step;
    }
    pop_matrix();
    clear_motion_packed_rotation();
}

SampledMotionPoints::~SampledMotionPoints() {
    mem_free(points);
    points = NULL;
}

SampledMotionPoints::SampledMotionPoints(s32 points_per_sample, f32 start, f32 end, f32 step) {
    s32 n;
    s32 i;
    this->step = step;
    this->points_per_sample = points_per_sample;
    this->start = floor_to_float(start / this->step);
    this->end = ceil_to_float(end / this->step);
    sample_count = (s32)(1.0f + (this->end - this->start));
    this->start *= this->step;
    this->end *= this->step;
    n = sample_count * this->points_per_sample;
    points = (Vec *)mem_alloc(n * sizeof(Vec));
    for (i = 0; i < n; i++) {
        points[i].x = 0.0f;
        points[i].y = 0.0f;
        points[i].z = 0.0f;
    }
}

}
