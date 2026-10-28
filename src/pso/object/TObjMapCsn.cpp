#include "types.h"
#include "pso/unk/text_80140D50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct RecoveredGlobal_80194988___vt__10TObjMapCsn { s32 value; u8 remaining[0x38]; };
typedef char RecoveredGlobal_80194988___vt__10TObjMapCsn_size[sizeof(RecoveredGlobal_80194988___vt__10TObjMapCsn) == 0x3C ? 1 : -1];

struct RecoveredGlobal_801949FC___vt__10TObjMapCsn { s32 value; u8 remaining[0x38]; };

struct Vec_801946D0 { f32 x, y, z; };

struct Tri_801946D0 {
    u16 a, b, c;
    s16 f6;
    Vec_801946D0 n;
    Vec_801946D0 center;
    f32 r2;
};

struct Csn_801946D0 {
    u8 pad0[0x38];
    Vec_801946D0 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[4];
    f32 f68, f6c, f70;
    u8 pad74[0x88 - 0x74];
    s32 f88;
    u8 pad8c[0xD4 - 0x8C];
    Tri_801946D0 tris[8];
    Vec_801946D0 verts[8];
};

extern "C" {
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_80194988___vt__10TObjMapCsn __vt__10TObjMapCsn;
u8 *__dt__10TObjMapCsnFv(u8 *arg0, s16 arg1);
extern s32 TObjMapCsn__class_name;
u8 *TObjMapCsn__ct(TObjMapCsn *arg0, s32 arg1, s32 arg2);
s32 matrix_mult_vec(int, void *, void *);
s32 translate_matrix_vec3(int, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 pop_matrix();
extern s8 map_csn_box_triangle_indices[];
extern Vec_801946D0 map_csn_box_face_normals[];
extern s32 identity_matrix[];
s32 __nw__7TObjectFUl(s32);

void TObjMapCsn::render() {  }

extern s32 map_csn_collision_flag_table[];

void TObjMapCsn::update_state() {
    s32 temp_r0;

    temp_r0 = this->set_params[0];
    if (temp_r0 == 0) {
        if ((s32) this->set_params[1] == 0) {
            *(s32 *)&this->set_params[1] = 1;
        }
    } else {
        if ((u32) temp_r0 > 5U) {
            this->set_params[0] = 1;
        }
        *(s32 *)&this->set_params[1] = (s32) map_csn_collision_flag_table[this->set_params[0]];
    }
    *(s32 *)&this->set_params[1] = (s32) (*(s32 *)&this->set_params[1] | 0x40000000);
}

s32 TObjMapCsn::build_box_triangles() {
    Vec_801946D0 corners[8];
    Vec_801946D0 v2;
    Vec_801946D0 v1;
    Vec_801946D0 v0;
    Vec_801946D0 *p1;
    Vec_801946D0 *p2;
    s32 j;
    s32 i;
    s8 *idx;
    Tri_801946D0 *t;
    Vec_801946D0 *nrm;
    Csn_801946D0 *arg0 = (Csn_801946D0 *) this;
    idx = map_csn_box_triangle_indices;
    nrm = map_csn_box_face_normals;
    t = arg0->tris;
    corners[0].x = -(0.5f * arg0->f68);
    corners[0].y = 0.0f;
    corners[0].z = (0.5f * arg0->f70);
    corners[1].x = -(0.5f * arg0->f68);
    corners[1].y = arg0->f6c;
    corners[1].z = (0.5f * arg0->f70);
    corners[2].x = (0.5f * arg0->f68);
    corners[2].y = arg0->f6c;
    corners[2].z = (0.5f * arg0->f70);
    corners[3].x = (0.5f * arg0->f68);
    corners[3].y = 0.0f;
    corners[3].z = (0.5f * arg0->f70);
    corners[4].x = -(0.5f * arg0->f68);
    corners[4].y = 0.0f;
    corners[4].z = -(0.5f * arg0->f70);
    corners[5].x = -(0.5f * arg0->f68);
    corners[5].y = arg0->f6c;
    corners[5].z = -(0.5f * arg0->f70);
    corners[6].x = (0.5f * arg0->f68);
    corners[6].y = arg0->f6c;
    corners[6].z = -(0.5f * arg0->f70);
    corners[7].x = (0.5f * arg0->f68);
    corners[7].y = 0.0f;
    corners[7].z = -(0.5f * arg0->f70);
    push_matrix_from(identity_matrix);
    translate_matrix_vec3(0, &arg0->pos);
    rotate_matrix_y(0, arg0->f60);
    for (i = 0; i < 8; i++) {
        matrix_mult_vec(0, &corners[i], &arg0->verts[i]);
    }
    p1 = &v1;
    p2 = &v2;
    for (j = 0; j < 8; j++) {
        t->a = idx[0];
        t->b = idx[1];
        t->c = idx[2];
        idx += 3;
        rotate_vector_by_matrix(0, nrm, &t->n);
        nrm++;
        VecCopy((Vec *)&v0, (const Vec *)&arg0->verts[t->a]);
        VecCopy((Vec *)p1, (const Vec *)&arg0->verts[t->b]);
        VecCopy((Vec *)p2, (const Vec *)&arg0->verts[t->c]);
        t->center.x = (v2.x + (v0.x + v1.x)) / 3.0f;
        t->center.y = (v2.y + (v0.y + v1.y)) / 3.0f;
        t->center.z = (v2.z + (v0.z + v1.z)) / 3.0f;
        if (!(j & 2)) {
            f32 r = 0.5f * arg0->f68;
            t->r2 = r * r;
        } else {
            f32 r = 0.5f * arg0->f70;
            t->r2 = r * r;
        }
        t->f6 = arg0->f88;
        t++;
    }
    return pop_matrix();
}

s32 TObjMapCsn::create(s32 arg0) {
    s32 map_csn;

    map_csn = __nw__7TObjectFUl(0x254);
    if (map_csn != 0) {
        map_csn = ((s32)TObjMapCsn__ct((TObjMapCsn *)((u8 *)map_csn), (s32)(TObjMapCsn::get_map_count()), (s32)arg0));
    }
    return map_csn;
}
u8 *__dt__10TObjMapCsnFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__10TObjMapCsn.value;
        if (((u32)TObjMapCsn::get_map_count()) != 0U) {
            fn_80140DFC((((u32)TObjMapCsn::get_map_count())), (s32)arg0);
        }
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjMapCsn__ct(TObjMapCsn *map_csn, s32 arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f1;
    __ct__14TObjCollidableFP7TObject(map_csn, arg1);
    *(s32 **)((s8 *)map_csn + 0x18) = &(*(RecoveredGlobal_801949FC___vt__10TObjMapCsn *)&__vt__10TObjMapCsn).value;
    *(s32 *)((s8 *)map_csn + 0) = (s32) TObjMapCsn__class_name;
    ((TObjMapCsn *)(map_csn))->apply_object_set_data((void *)arg2);
    map_csn->actorFlags = (s32) (map_csn->actorFlags | 0x40000000);
    map_csn->update_state();
    map_csn->build_box_triangles();
    map_csn->m_c4 = 8;
    *(u8 **)((s8 *)map_csn + 0xC8) = (unsigned char *) ((u8 *)map_csn + 0x1F4);
    map_csn->m_cc = 8;
    *(u8 **)((s8 *)map_csn + 0xD0) = (unsigned char *) ((u8 *)map_csn + 0xD4);
    *(u8 **)((s8 *)map_csn + 0xAC) = (unsigned char *) ((u8 *)map_csn + 0xC4);
    VecCopy((Vec *)((u8 *)map_csn + 0xB0), (const Vec *)((u8 *)map_csn + 0x38));
    temp_f1 = (0.5f) * map_csn->scale.x;
    temp_f0 = (0.5f) * *(f32 *)((s8 *)map_csn + 0x70);
    map_csn->m_bc = (f32) ((temp_f1 * temp_f1) + (temp_f0 * temp_f0));
    map_csn->m_c0 = (s32) *(s32 *)((s8 *)map_csn + 0x88);
    if (((u32)TObjMapCsn::get_map_count()) != 0U) {
        fn_80140EA8((((u32)TObjMapCsn::get_map_count())), (s32)map_csn);
    }
    return (u8 *)map_csn;
}

}
