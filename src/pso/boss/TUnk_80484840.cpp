#pragma fp_contract on

#include "pso/boss/TUnk_80484840.h"
#include "pso/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"

extern "C" {
s32 push_matrix(void);
void rotate_matrix_x(s32 matrix, s32 angle);
void rotate_matrix_y(s32 matrix, s32 angle);
void matrix_mult_vec(s32 matrix, const Vec *src, Vec *dst);
void vec3_add_to(Vec *v, const Vec *add);
void subtract_vector(Vec *v, const Vec *sub);
f32 vector_length(const Vec *v);
s32 rand(void);
void draw_line_list(VoloptLineList *lines, s32 count, u32 flags);
}

__declspec(section ".data") static VoloptLineColor volopt_sweep_line_colors[2] = {
    {0x80, 0xFF, 0x40, 0x40},
    {0x80, 0xFF, 0x40, 0x40},
};

static Vec volopt_sweep_line_points[2];

static VoloptLineList volopt_sweep_line = {
    volopt_sweep_line_points, volopt_sweep_line_colors, 0, 4,
};

void TUnk_80484840::render() {
    Vec *end;
    s32 alpha;
    if (lifetime < 10) {
        alpha = (lifetime << 7) / 10;
        volopt_sweep_line_colors[0].a = alpha;
        volopt_sweep_line_colors[0].a = alpha;
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

void TUnk_80484840::run_task() {
    rotation_y += sweep_speed;
    if (--lifetime <= 0) {
        queue_destruction();
    }
}

TUnk_80484840::~TUnk_80484840() {}

TUnk_80484840::TUnk_80484840(Vec *from, Vec *to, s32 spread, s32 lifetime) : TObject(tl_05) {
    this->from = from;
    this->to = to;
    this->lifetime = lifetime;
    {
        Vec dir = *to;
        subtract_vector(&dir, from);
        length = 2.0f * vector_length(&dir);
        direction_to_rotation_xy((u8 *)&dir, &rotation_x, &rotation_y);
    }
    rotation_y -= spread * 0x71C + (s32)(1820.0f * (3.0517578e-05f * (f32)rand()));
    sweep_speed = spread * (s32)(1820.0f * ((2.0f * (3.0517578e-05f * (f32)rand()) + 1.0f) / (f32)lifetime));
}
