#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/barbaray/TObjBoss7Dust.h"
#include "pso/boss/barbaray/TObjBoss7DustCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_802F1A58.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TObject.h"

// TObjBoss7DustCtrl and TObjBoss7Dust share one TU, built deferred and written from the unit's last
// function back: Dust's code comes first in .text, yet DustCtrl's class name precedes Dust's in .sdata
// and .rodata, and Dust's vtable precedes DustCtrl's in .data (reverse key-function order).

typedef struct Rot_802F127C {
    s32 a;
    s32 b;
} Rot_802F127C;

typedef struct Out_802F127C {
    u8 b[0x10];
} Out_802F127C;

typedef struct Dust_802F127C {
    Vec pts[6];
    Rot_802F127C rot[10];
    Out_802F127C out[60];
    s32 ang[10];
} Dust_802F127C;

struct RecoveredGlobal_802F119C___vt__13TObjBoss7Dust {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {

void __ct__7TObjectFP7TObject(void *, void *);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32);
void matrix_mult_vec(s32, Vec *, Out_802F127C *);
void push_matrix(void);
Vec TObjBoss7DustCtrl__helix_points[6];
Rot_802F127C TObjBoss7DustCtrl__rotation_pairs[10];
Out_802F127C TObjBoss7DustCtrl__transformed_vertices[60];
s32 TObjBoss7DustCtrl__vertical_phase_angles[10];
extern const f32 lbl_805DEC70;
extern const f32 lbl_805DEC74;
typedef struct Out_802F1454 { f32 x, y, z; u32 c; } Out_802F1454;
extern const f32 lbl_805DEC78;
extern const f32 lbl_805DEC7C;
extern const f32 lbl_805DEC80;
s32 post_translate_matrix(int);
extern s32 __vt__17TObjBoss7DustCtrl[];
extern RecoveredGlobal_802F119C___vt__13TObjBoss7Dust __vt__13TObjBoss7Dust;
void fn_802F19C0(void);
}

const char *TObjBoss7DustCtrl__name = "TObjBoss7DustCtrl";
const char *TObjBoss7Dust__name = "TObjBoss7Dust";

s32 lbl_805D6958;

extern "C" {

void fn_802F1454(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 6; i++) {
        s32 a = (s32)(lbl_805DEC78 * (f32)i);
        f32 s = lbl_805DEC7C * sin_table_lookup(a);
        TObjBoss7DustCtrl__helix_points[i].x = s;
        TObjBoss7DustCtrl__helix_points[i].y = lbl_805DEC80 * (f32)i;
        TObjBoss7DustCtrl__helix_points[i].z = lbl_805DEC7C * cos_table_lookup(a, s);
    }
    {
        s32 *p = &TObjBoss7DustCtrl__rotation_pairs[0].a;
        for (i = 0; i < 20; i++) {
            *p++ = TObjPlayer::calc_random_scaled();
        }
    }
    {
        Out_802F1454 *o = (Out_802F1454 *)TObjBoss7DustCtrl__transformed_vertices;
        for (i = 0; i < 60; i++) {
            o->x = lbl_805DEC70;
            o->y = lbl_805DEC70;
            o->z = lbl_805DEC70;
            o->c = 0xFF709070;
            o++;
        }
    }
    for (j = 0; j < 10; j++) {
        TObjBoss7DustCtrl__vertical_phase_angles[j] = TObjPlayer::calc_random_scaled();
    }
    lbl_805D6958 = 0;
}

void TObjBoss7DustCtrl__sub_802F1450(void) {  }

}

extern s32 tl_05;

void TObjBoss7DustCtrl::create() {
    void* obj = TObject::operator new(0x1C);
    if (obj != 0) {
        TObjBoss7DustCtrl__ct(obj, (void *)tl_05);
    }
}

extern "C" {

void *TObjBoss7DustCtrl__ct(void *boss7_dust_ctrl, void *parent) {
    __ct__7TObjectFP7TObject(boss7_dust_ctrl, parent);
    *(s32 **)((s8 *)boss7_dust_ctrl + 0x18) = __vt__17TObjBoss7DustCtrl;
    ((TObjBoss7DustCtrl *)boss7_dust_ctrl)->m_name = TObjBoss7DustCtrl__name;
    return boss7_dust_ctrl;
}

}

TObjBoss7DustCtrl::~TObjBoss7DustCtrl() {}

#pragma push
#pragma opt_propagation off
void TObjBoss7DustCtrl::run_task() {
    f32 scale;
    s32 *ang;
    Out_802F127C *out;
    s32 *rot;
    s32 i;
    s32 j;

    rot = &TObjBoss7DustCtrl__rotation_pairs[0].a;
    out = TObjBoss7DustCtrl__transformed_vertices;
    push_matrix();
    scale = lbl_805DEC74;
    ang = TObjBoss7DustCtrl__vertical_phase_angles;
    for (i = 0; i < 10; i++) {
        set_matrix_identity(0);
        translate_matrix(0, lbl_805DEC70, scale * sin_table_lookup(ang[i]), lbl_805DEC70);
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
            matrix_mult_vec(0, &TObjBoss7DustCtrl__helix_points[j], out++);
        }
    }
    pop_matrix();
}
#pragma pop

extern "C" {
s32 TObjBoss7DustCtrl__sub_802F125C(void) {
    s32 index = lbl_805D6958;

    lbl_805D6958 = index + 1;
    if (index + 1 >= 0xA) {
        lbl_805D6958 = 0;
    }
    return index;
}
}

void boss7_dust_draw_at(s32 *arg0, s32 arg1) {
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
    post_translate_matrix((saddr)var_r3);
    var_r5 = var_r31 * 0x60;
    var_r3 = (s32 *)((s32 *)TObjBoss7DustCtrl__transformed_vertices);
    var_r4 = 6;
    var_r3 = (s32 *)((u8 *)(s32 *)TObjBoss7DustCtrl__transformed_vertices + var_r5);
    var_r5 = 0;
    ((TObjPlayer *)var_r3)->draw_trail_strip((void *)6, 0);
    pop_matrix();
}

LAYOUT_ASSERT(RecoveredGlobal_802F119C___vt__13TObjBoss7Dust_size, sizeof(RecoveredGlobal_802F119C___vt__13TObjBoss7Dust) == 0x18);

u8 *__ct__13TObjBoss7DustFv(u8 *object, saddr arg1, saddr arg2) {
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__13TObjBoss7Dust.value;
    ((TObjBoss7Dust *)object)->m_name = TObjBoss7Dust__name;
    VecCopy((Vec *)(object + 0x24), (const Vec *)(arg2));
    *(s32 *)((s8 *)object + 0x1C) = 0;
    *(s32 *)((s8 *)object + 0x20) = TObjBoss7DustCtrl__sub_802F125C();
    return object;
}

TObjBoss7Dust::~TObjBoss7Dust() {}

void TObjBoss7Dust::run_task() {
    *(f32 *)((s8 *)this + 0x2C) = (f32) (*(f32 *)((s8 *)this + 0x2C) - boss7_tunnel_max_scroll_speed);
    *(s32 *)((s8 *)this + 0x1C) = (s32) (*(s32 *)((s8 *)this + 0x1C) + 1);
    if ((s32) *(s32 *)((s8 *)this + 0x1C) >= 0x5A) {
        queue_destruction();
    }
}

void TObjBoss7Dust::render() { boss7_dust_draw_at((s32 *)((char*)this + 0x24), (saddr)(*(void**)((char*)this + 0x20))); }

void init_scene_boss2_tunnel(void) { load_boss7_common_resources(); TObjBoss2Tunnel__sub_802F2C84(); fn_802F1454(); }

extern "C" {
void fn_802F1084(void) { TObjBoss2Tunnel__sub_802F2C50(); fn_802F19C0(); TObjBoss7DustCtrl::create(); }
void fn_802F105C(void) { TObjBoss7DustCtrl__sub_802F1450(); TObjBoss2Tunnel__sub_802F2C4C(); free_boss7_common_resources(); }
}
