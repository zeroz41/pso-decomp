#include "pso/boss/derolle/TObjBoss2DustCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

typedef struct Vec_8003AB7C {
    f32 x, y, z;
} Vec_8003AB7C;

typedef struct Rot_8003AB7C {
    s32 a;
    s32 b;
} Rot_8003AB7C;

typedef struct Out_8003AB7C {
    u8 b[0x10];
} Out_8003AB7C;

typedef struct Dust_8003AB7C {
    Vec_8003AB7C pts[6];
    Rot_8003AB7C rot[10];
    Out_8003AB7C out[60];
    s32 ang[10];
} Dust_8003AB7C;

typedef struct Out_8003AD54 { f32 x, y, z; u32 c; } Out_8003AD54;

f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32);
void matrix_mult_vec(s32, Vec_8003AB7C *, Out_8003AB7C *);
void rotate_matrix_x(s32, s32);
void push_matrix(void);
Vec_8003AB7C boss2_dust_points[6];
s32 boss2_dust_rotation_table[20];
Out_8003AD54 boss2_dust_output_table[60];
s32 boss2_dust_random_angles[10];
extern const f32 lbl_805D85B8;
extern const f32 lbl_805D85BC;
extern const f32 lbl_805D85C0;
extern const f32 lbl_805D85C4;
extern const f32 lbl_805D85C8;
s32 TObjBoss2DustCtrl_dust_counter;

void __ct__7TObjectFP7TObject(void *);
void* __nw__7TObjectFUl(s32);
extern s32 __vt__17TObjBoss2DustCtrl[];
extern void *lbl_805D26F8;
extern s32 tl_05;

extern "C" {
s32 post_translate_matrix(int);
}

extern "C" {

void boss2_dust_draw_at(s32 *arg0, s32 arg1) {
    s32 *var_r30;
    s32 *var_r3;
    s32 var_r31;
    s32 var_r4;
    s32 var_r5;
    var_r30 = arg0;
    var_r31 = arg1;
    TParticleCtrl::end_effect_render();
    push_matrix();
    var_r3 = var_r30;
    post_translate_matrix((int)var_r3);
    var_r5 = var_r31 * 0x60;
    var_r3 = (s32 *)((s32 *)boss2_dust_output_table);
    var_r4 = 6;
    var_r3 = (s32 *)((u8 *)(s32 *)boss2_dust_output_table + var_r5);
    var_r5 = 0;
    ((TObjPlayer *)var_r3)->draw_trail_strip((void *)6, 0);
    pop_matrix();
}

}
extern "C" {
void TObjBoss2DustCtrl__sub_8003AB5C(void) {
    s32 temp_r0;

    temp_r0 = TObjBoss2DustCtrl_dust_counter + 1;
    TObjBoss2DustCtrl_dust_counter = temp_r0;
    if (temp_r0 >= 0xA) {
        TObjBoss2DustCtrl_dust_counter = 0;
    }
}
}

#pragma push
#pragma opt_propagation off
void TObjBoss2DustCtrl::run_task() {
    f32 scale;
    s32 *ang;
    Out_8003AB7C *out;
    s32 *rot;
    s32 i;
    s32 j;

    rot = boss2_dust_rotation_table;
    out = (Out_8003AB7C *)boss2_dust_output_table;
    push_matrix();
    scale = lbl_805D85BC;
    ang = boss2_dust_random_angles;
    for (i = 0; i < 10; i++) {
        set_matrix_identity(0);
        translate_matrix(0, lbl_805D85B8, scale * sin_table_lookup(ang[i]), lbl_805D85B8);
        {
            s32 a = ang[i];
            s32 r;
            *rot += 0x1333;
            r = *rot++;
            ang[i] = a + 0x800;
            rotate_matrix_x(0, r);
        }
        *rot += 0x555;
        rotate_matrix_x(0, *rot++);
        for (j = 0; j < 6; j++) {
            matrix_mult_vec(0, &boss2_dust_points[j], out++);
        }
    }
    pop_matrix();
}
#pragma pop

}

TObjBoss2DustCtrl::~TObjBoss2DustCtrl() {}

void *TObjBoss2DustCtrl__ct(void *boss2_dust_ctrl) {
    __ct__7TObjectFP7TObject(boss2_dust_ctrl);
    *(s32 **)((s8 *)boss2_dust_ctrl + 0x18) = __vt__17TObjBoss2DustCtrl;
    *(void * *)&((TObjBoss2DustCtrl *)boss2_dust_ctrl)->m_name = lbl_805D26F8;
    return boss2_dust_ctrl;
}

void TObjBoss2DustCtrl::create() {
    void* obj = __nw__7TObjectFUl(0x1C);
    if (obj != 0) {
        ((s32 (*)(void *, s32))TObjBoss2DustCtrl__ct)(obj, tl_05);
    }
}

void TObjBoss2DustCtrl__sub_8003AD50(void) {  }

void fn_8003AD54(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        s32 a = (s32)(lbl_805D85C0 * (f32)i);
        f32 s = lbl_805D85C4 * sin_table_lookup(a);
        boss2_dust_points[i].x = s;
        boss2_dust_points[i].y = lbl_805D85C8 * (f32)i;
        boss2_dust_points[i].z = lbl_805D85C4 * cos_table_lookup(a, s);
    }
    {
        s32 *p = boss2_dust_rotation_table;
        for (i = 0; i < 20; i++) {
            *p++ = TObjPlayer::calc_random_scaled();
        }
    }
    {
        Out_8003AD54 *o = boss2_dust_output_table;
        for (i = 0; i < 60; i++) {
            o->x = lbl_805D85B8;
            o->y = lbl_805D85B8;
            o->z = lbl_805D85B8;
            o->c = 0xFF709070;
            o++;
        }
    }
    for (j = 0; j < 10; j++) {
        boss2_dust_random_angles[j] = TObjPlayer::calc_random_scaled();
    }
    TObjBoss2DustCtrl_dust_counter = 0;
}
