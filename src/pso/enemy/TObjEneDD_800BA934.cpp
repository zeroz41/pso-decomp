#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"

struct Part_800BA934 { u8 pad[0x1c]; u8 f1c[0x10]; };

struct Obj_800BA934 { u8 pad[0x38]; u8 f38[0x28]; void *f60; u8 pad2[0x40]; Part_800BA934 *parts; s32 count; };


struct Part_800BAAE4 { Vec a; u8 pad[0x10]; Vec b; u8 pad2[4]; };

struct Obj_800BAAE4 { u8 pad[0x38]; Vec pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BAAE4 *parts; };

struct Vec_800BA9BC { f32 x, y, z; };

struct Part_800BA9BC { Vec_800BA9BC a; u8 pad[0x10]; Vec_800BA9BC b; u8 pad2[4]; };

struct Obj_800BA9BC { u8 pad[0x38]; Vec_800BA9BC pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BA9BC *parts; };

struct V3_800BAA2C { f32 x; f32 y; f32 z; };

struct Col_800BAA2C { u8 pad0[0x1C]; V3_800BAA2C pos; u8 pad28[4]; };

struct Obj_800BAA2C { u8 pad0[0x38]; f32 x; f32 y; f32 z; u8 pad44[0x60 - 0x44]; s32 rot; u8 pad64[0xA4 - 0x64]; Col_800BAA2C *cols; s32 count; };

extern "C" {
int push_matrix(void);
f32 post_translate_matrix(void *);
int rotate_matrix_y(void *, void *);
int matrix_mult_vec(void *, void *, void *);
void vec3_add_to(Vec_800BA9BC *a, Vec_800BA9BC *b);
void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec_800BA9BC *v, s32 i);
void update_local_colliders_from_world(Obj_800BAA2C *arg0, V3_800BAA2C *arg1);
int init_collision_body_parts(void*);

void TObjEneDD::transform_part_positions() {
    Obj_800BA934 *self = (Obj_800BA934 *)this;
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(self->f38);
    rotate_matrix_y(0, self->f60);
    set_motion_packed_rotation();
    for (i = 0; i < self->count; i++) {
        matrix_mult_vec(0, &self->parts[i], self->parts[i].f1c);
    }
    clear_motion_packed_rotation();
    pop_matrix();
}

void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec_800BA9BC *v, s32 i) {
    Vec_800BA9BC *p;
    VecCopy((Vec *)((Vec *)(&self->parts[i].a)), (const Vec *)((const Vec *)(v)));
    p = &self->parts[i].b;
    VecCopy((Vec *)((Vec *)(p)), (const Vec *)((const Vec *)(v)));
    rotate_xz_pair_by_angle(&p->x, &p->z, self->angle);
    vec3_add_to(p, &self->pos);
}

void update_local_colliders_from_world(Obj_800BAA2C *arg0, V3_800BAA2C *arg1) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y((void *)(0), (void *)(-arg0->rot));
    translate_matrix(0, -arg0->x, -arg0->y, -arg0->z);
    for (i = 0; i < arg0->count; i++) {
        VecCopy((Vec *)((Vec *)(&arg0->cols[i].pos)), (const Vec *)((const Vec *)(arg1)));
        matrix_mult_vec(0, arg1, &arg0->cols[i]);
        arg1++;
    }
    pop_matrix();
}

void TObjEneDD::set_part_local_pos(void *v, s32 i) {
    Vec *p;
    VecCopy((Vec *)&((Obj_800BAAE4 *)this)->parts[i].b, (const Vec *)((Vec *)v));
    p = &((Obj_800BAAE4 *)this)->parts[i].a;
    VecCopy((Vec *)p, (const Vec *)((Vec *)v));
    subtract_vector(p, &((Obj_800BAAE4 *)this)->pos);
    rotate_xz_pair_by_angle(&p->x, &p->z, -((Obj_800BAAE4 *)this)->angle);
}

void TObjEneDD::init_model() { init_collision_body_parts(this); transform_part_positions(); }
void TObjEneDD::clear_field_388() { *(s32*)((char*)this + 0x388) = 0; }
void TObjEneDD_ST::set_active() { *(s32*)((char*)this + 0x388) = 1; }

}
