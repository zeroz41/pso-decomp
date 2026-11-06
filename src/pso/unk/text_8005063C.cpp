#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"

typedef struct Vec_8005063C {
    f32 x, y, z;
} Vec_8005063C;

typedef struct Obj_8005063C {
    u8 pad0[0x2FC];
    Vec_8005063C f2fc;
    u8 pad308[0x348 - 0x308];
    Vec_8005063C dir;
    u8 pad354[0x364 - 0x354];
    f32 f364;
    s32 state;
    Vec_8005063C f36c;
    f32 f378;
    f32 f37c;
} Obj_8005063C;

extern "C" {
f32 fabs_float(f32);
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A58;
extern const f32 lbl_805D8A5C;
void queue_destruction__7TObjectFv(void *);
f32 vector_length(Vec_8005063C *);
void subtract_vector(Vec_8005063C *, Vec_8005063C *);
void normalize_vector(Vec_8005063C *);
f32 xyz_distance(Vec_8005063C *, Vec_8005063C *);
extern const f32 lbl_805D8A34;
extern const f32 lbl_805D8A48;
extern const f32 lbl_805D8A4C;
extern const f32 lbl_805D8A50;
extern const f32 lbl_805D8A54;
void steer_homing_direction(Obj_8005063C *arg0);

#pragma fp_contract on
void steer_homing_direction(Obj_8005063C *arg0) {
    Vec_8005063C d;
    f32 k;
    f32 inv;
    VecCopy((Vec *)&d, (const Vec *)&arg0->f36c);
    subtract_vector(&d, &arg0->f2fc);
    if (vector_length(&d) <= lbl_805D8A48 ||
        vector_length(&arg0->dir) <= lbl_805D8A48) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    normalize_vector(&d);
    normalize_vector(&arg0->dir);
    k = lbl_805D8A50 * arg0->f364 + lbl_805D8A4C;
    Vec_8005063C prev = arg0->dir;
    inv = lbl_805D8A34 - k;
    arg0->dir.x = k * arg0->dir.x + inv * d.x;
    arg0->dir.y = k * arg0->dir.y + inv * d.y;
    arg0->dir.z = k * arg0->dir.z + inv * d.z;
    if (arg0->f37c <= arg0->f378 && xyz_distance(&arg0->dir, &prev) <= lbl_805D8A54) {
        arg0->state = 2;
    }
}

void TObjDFHorming::sub_8005076C() {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x370) - this->m_300;
    if (temp_f1 > lbl_805D8A30) {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x34C) + lbl_805D8A58);
    } else {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x34C) - lbl_805D8A58);
    }
    if (fabs_float(temp_f1) < lbl_805D8A5C) {
        this->m_368 = 1;
    }
}

}
