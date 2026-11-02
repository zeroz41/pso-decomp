#include "pso/animation/MotionContext.h"
#include "pso/math/FloatRounding.h"
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/misc/SampledMotionPoints.h"
#include "pso/math/MatrixVector.h"

#include "pso/unk/text_803D96A8.h"
#include "pso/system/memory.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
Vec lbl_80500F80;
Vec TObjEneMe3ShinowaMirage_motion_trail_points[2];
s32 lbl_80500FA4[3];
void *mem_alloc(u32 size);
extern const f32 lbl_805DA3EC;
extern const f32 lbl_805DA3F0;
s32 transform_motion_node_points(SampledMotionPoints *, NJS_OBJECT *, s32);
void push_matrix(Vec *);
extern Vec lbl_80500F80;
extern Vec *lbl_805D5230;
extern s32 lbl_805D5234;
extern s32 motion_trail_node_index;
extern const s32 *lbl_805D523C;
extern const Vec *TBoss4Type3__motion_trail_points;
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
    lbl_80500F80.x = lbl_805DA3EC;
    lbl_80500F80.y = lbl_805DA3EC;
    lbl_80500F80.z = lbl_805DA3EC;
    lbl_805D5230 = points;
    lbl_805D5234 = points_per_sample;
    lbl_805D523C = node_indices;
    TBoss4Type3__motion_trail_points = offsets;
    push_matrix(&lbl_80500F80);
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
    sample_count = (s32)(lbl_805DA3F0 + (this->end - this->start));
    this->start *= this->step;
    this->end *= this->step;
    n = sample_count * this->points_per_sample;
    points = (Vec *)mem_alloc(n * sizeof(Vec));
    for (i = 0; i < n; i++) {
        points[i].x = lbl_805DA3EC;
        points[i].y = lbl_805DA3EC;
        points[i].z = lbl_805DA3EC;
    }
}

}
