#pragma fp_contract on

#include "pso/boss/volopt/TBoss3VoloptSweepLine.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/render/ScreenSpriteDraw.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/render/DebugFont.h"

__declspec(section ".data") static NJS_COLOR volopt_sweep_line_colors[2] = {
    {0x80FF4040},
    {0x80FF4040},
};

static Vec volopt_sweep_line_points[2];

static NJS_POINT3COL volopt_sweep_line = {
    volopt_sweep_line_points, &volopt_sweep_line_colors[0].color, NULL, 4,
};

void TBoss3VoloptSweepLine::render() {
    Vec *end;
    s32 alpha;
    if (lifetime < 10) {
        alpha = (lifetime << 7) / 10;
        volopt_sweep_line_colors[0].argb.b = alpha;
        volopt_sweep_line_colors[0].argb.b = alpha;
    }
    VecCopy(&volopt_sweep_line_points[0], from);
    end = &volopt_sweep_line_points[1];
    VecCopy(end, to);
    push_matrix();
    set_matrix_identity(0);
    {
        Vec offset = {0.0f, 0.0f, 0.0f};
        offset.z = length;
        rotate_matrix_x(0, rotation_x);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &offset, &offset);
        vec3_add_to(end, &offset);
    }
    pop_matrix();
    set_additive_blend();
    draw_line_list(&volopt_sweep_line, 1, 5);
    set_default_alpha_blend();
}

void TBoss3VoloptSweepLine::run_task() {
    rotation_y += sweep_speed;
    if (--lifetime <= 0) {
        queue_destruction();
    }
}

TBoss3VoloptSweepLine::~TBoss3VoloptSweepLine() {}

TBoss3VoloptSweepLine::TBoss3VoloptSweepLine(Vec *from, Vec *to, s32 spread, s32 lifetime) : TObject(tl_05) {
    this->from = from;
    this->to = to;
    this->lifetime = lifetime;
    {
        Vec dir = *to;
        subtract_vector(&dir, from);
        length = 2.0f * vector_length(&dir);
        direction_to_rotation_xy(&dir, &rotation_x, &rotation_y);
    }
    rotation_y -= spread * 0x71C + (s32)(1820.0f * (3.0517578e-05f * (f32)rand()));
    sweep_speed = spread * (s32)(1820.0f * ((2.0f * (3.0517578e-05f * (f32)rand()) + 1.0f) / (f32)lifetime));
}
