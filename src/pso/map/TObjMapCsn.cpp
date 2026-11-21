#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/map/TMapCsnCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"

const char *TMapCsnCtrl__class_name = "TMapCsnCtrl";

// Corner indices of the 8 side triangles of the collision box (two per side face).
s8 map_csn_box_triangle_indices[24] = {
    2, 1, 0, 0, 3, 2, 6, 2, 3, 3, 7, 6,
    5, 6, 7, 7, 4, 5, 1, 5, 4, 4, 0, 1,
};

// Normal of each side triangle: +z, +x, -z, -x faces.
Vec map_csn_box_face_normals[8] = {
    {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}, {-1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f},
};

// Collision flags by the set data's collision kind (1..5).
s32 map_csn_collision_flag_table[5] = {0, 0x8000, 0x8900, 0x800, 0x2000};

extern "C" {
u8 *__ct__10TObjMapCsnFll(TObjMapCsn *arg0, s32 arg1, saddr arg2);
s32 matrix_mult_vec(int, void *, void *);
s32 translate_matrix_vec3(int, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
extern s32 identity_matrix[];
s32 __nw__7TObjectFUl(s32);

void TObjMapCsn::render() {  }


void TObjMapCsn::update_state() {
    s32 temp_r0;

    temp_r0 = this->set_params[0];
    if (temp_r0 == 0) {
        if ((s32) this->set_params[1] == 0) {
            this->set_params[1] = 1;
        }
    } else {
        if ((u32) temp_r0 > 5U) {
            this->set_params[0] = 1;
        }
        this->set_params[1] = (s32) map_csn_collision_flag_table[this->set_params[0]];
    }
    this->set_params[1] = (s32) (this->set_params[1] | 0x40000000);
}

s32 TObjMapCsn::build_box_triangles() {
    Vec corners[8];
    Vec v2;
    Vec v1;
    Vec v0;
    Vec *p1;
    Vec *p2;
    s32 j;
    s32 i;
    s8 *idx;
    CsnFace *t;
    Vec *nrm;
    idx = map_csn_box_triangle_indices;
    nrm = map_csn_box_face_normals;
    t = collision_faces;
    corners[0].x = -(0.5f * scale.x);
    corners[0].y = 0.0f;
    corners[0].z = (0.5f * scale.z);
    corners[1].x = -(0.5f * scale.x);
    corners[1].y = scale.y;
    corners[1].z = (0.5f * scale.z);
    corners[2].x = (0.5f * scale.x);
    corners[2].y = scale.y;
    corners[2].z = (0.5f * scale.z);
    corners[3].x = (0.5f * scale.x);
    corners[3].y = 0.0f;
    corners[3].z = (0.5f * scale.z);
    corners[4].x = -(0.5f * scale.x);
    corners[4].y = 0.0f;
    corners[4].z = -(0.5f * scale.z);
    corners[5].x = -(0.5f * scale.x);
    corners[5].y = scale.y;
    corners[5].z = -(0.5f * scale.z);
    corners[6].x = (0.5f * scale.x);
    corners[6].y = scale.y;
    corners[6].z = -(0.5f * scale.z);
    corners[7].x = (0.5f * scale.x);
    corners[7].y = 0.0f;
    corners[7].z = -(0.5f * scale.z);
    push_matrix_from(identity_matrix);
    translate_matrix_vec3(0, &position);
    rotate_matrix_y(0, rotation_y);
    for (i = 0; i < 8; i++) {
        matrix_mult_vec(0, &corners[i], &collision_vertices[i]);
    }
    p1 = &v1;
    p2 = &v2;
    for (j = 0; j < 8; j++) {
        t->vertex[0] = idx[0];
        t->vertex[1] = idx[1];
        t->vertex[2] = idx[2];
        idx += 3;
        rotate_vector_by_matrix(0, nrm, &t->normal);
        nrm++;
        VecCopy((Vec *)&v0, (const Vec *)&collision_vertices[t->vertex[0]]);
        VecCopy((Vec *)p1, (const Vec *)&collision_vertices[t->vertex[1]]);
        VecCopy((Vec *)p2, (const Vec *)&collision_vertices[t->vertex[2]]);
        t->center.x = (v2.x + (v0.x + v1.x)) / 3.0f;
        t->center.y = (v2.y + (v0.y + v1.y)) / 3.0f;
        t->center.z = (v2.z + (v0.z + v1.z)) / 3.0f;
        if (!(j & 2)) {
            f32 r = 0.5f * scale.x;
            t->radius = r * r;
        } else {
            f32 r = 0.5f * scale.z;
            t->radius = r * r;
        }
        t->flags = set_params[1];
        t++;
    }
    return pop_matrix();
}

saddr TObjMapCsn::create(saddr arg0) {
    saddr map_csn;

    map_csn = (saddr)TObject::operator new(0x254);
    if (map_csn != 0) {
        map_csn = ((saddr)__ct__10TObjMapCsnFll((TObjMapCsn *)((u8 *)map_csn), (saddr)(TObjMapCsn::get_collision_controller()), (s32)arg0));
    }
    return map_csn;
}
}
TObjMapCsn::~TObjMapCsn() {
    if (TObjMapCsn::get_collision_controller() != NULL) {
        fn_80140DFC(TObjMapCsn::get_collision_controller(), this);
    }
}
TObjMapCsn::TObjMapCsn(saddr arg1, saddr arg2) : TObjCollidable((TObject *)arg1) {
    f32 temp_f0;
    f32 temp_f1;
    m_name = TObjMapCsn__class_name;
    ((TObjMapCsn *)(this))->apply_object_set_data((void *)arg2);
    this->actorFlags = (s32) (this->actorFlags | 0x40000000);
    this->update_state();
    this->build_box_triangles();
    collision_model.vertex_count = 8;
    collision_model.vertices = collision_vertices;
    collision_model.face_count = 8;
    collision_model.faces = collision_faces;
    collision_group.model = &collision_model;
    VecCopy(&collision_group.center, &position);
    temp_f1 = 0.5f * scale.x;
    temp_f0 = 0.5f * scale.z;
    collision_group.radius = temp_f1 * temp_f1 + temp_f0 * temp_f0;
    collision_group.flags = set_params[1];
    if (TObjMapCsn::get_collision_controller() != NULL) {
        fn_80140EA8(TObjMapCsn::get_collision_controller(), this);
    }
}
