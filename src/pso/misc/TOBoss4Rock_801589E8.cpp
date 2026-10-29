#include "types.h"
#include "pso/misc/TOBoss4Bird.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOBoss4Tower.h"
#include "pso/system/vector.h"

struct Vec_8015959C;
extern "C" {
s32 TObjFish__sub_8001EDB0(s32,s32);
s32 get_bml_model(s32,s32);
s32 rotate_matrix_y(int,int);
s32 set_global_param__8TObjFishFl(int);
void draw_ginja_object(void *child);
void *mem_alloc(u32 size);
void TOBoss4__ct(void*,void*);
u8* TOBoss4Bird__ct(u8*,s32);
extern s32 __vt__11TOBoss4Bird[];
extern const u32 lbl_805DB310 = 0x44FA0000;
}

#pragma fp_contract on
struct Vec_801589E8 { f32 x, y, z; };
struct Rot_801589E8 { s32 x, y, z; };
struct Rock_801589E8 {
    u8 pad0[0x6C];
    f32 f6c;
    u8 pad70[0x98 - 0x70];
    f32 spread;
    s32 count;
    s32 *models;
    s32 *params;
    Vec_801589E8 *positions;
    f32 *speeds;
    Rot_801589E8 *rots;
    Rot_801589E8 *rotspd;
};

extern "C" {

s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 rand();
extern s32 lbl_805D58A8;

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(2)
inline void respawn_801589E8(Rock_801589E8 *self, s32 i) {
    f32 r = (4.0f) * ((3.0517578e-05f) * (f32)rand());
    f32 base;
    self->models[i] = get_bml_model(lbl_805D58A8, (s32)r);
    self->params[i] = TObjFish__sub_8001EDB0(lbl_805D58A8, (s32)r);
    self->positions[i].x = self->spread * ((3.0517578e-05f) * (f32)rand());
    self->positions[i].y = (0.0f);
    self->positions[i].z = self->spread * ((3.0517578e-05f) * (f32)rand());
    base = (0.5f) * self->f6c;
    self->speeds[i] = base * ((3.0517578e-05f) * (f32)rand()) + base;
    self->rots[i].x = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rots[i].y = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rots[i].z = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].x = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].y = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].z = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
}

void TOBoss4Rock::run_task() {
    Rock_801589E8 *self = (Rock_801589E8 *)this;
    s32 i;

    for (i = 0; i < self->count; i++) {
        self->rots[i].x += self->rotspd[i].x;
        self->rots[i].y += self->rotspd[i].y;
        self->rots[i].z += self->rotspd[i].z;
        self->positions[i].y += self->speeds[i];
        if (*(const f32 *)&lbl_805DB310 < self->positions[i].y) {
            respawn_801589E8(self, i);
        }
    }
}
#pragma pop

}

struct Vec_80158DCC { f32 x, y, z; };

struct Rot_80158DCC { s32 x, y, z; };

struct VBase_80158DCC { char pad[0x18]; };

struct VObj_80158DCC : VBase_80158DCC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Rock_80158DCC : VObj_80158DCC {
    u8 pad1C[0x38 - 0x1C];
    Vec_80158DCC pos;
    u8 pad44[0x90 - 0x44];
    f32 f90;
    f32 f94;
    u8 pad98[4];
    s32 count;
    s32 *models;
    s32 *params;
    Vec_80158DCC *positions;
    u8 padAC[4];
    Rot_80158DCC *rots;
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void *TOBoss4Rock__ct(void *, void *);
void mem_free(void *);
void *__nw__7TObjectFUl(int);

void TOBoss4Rock::render() {
    Rock_80158DCC *self = (Rock_80158DCC *)this;
    s32 i;
    if (self->m8(self->f90, self->f94) != 0) {
        push_matrix();
        post_translate_matrix(&self->pos);
        for (i = 0; i < self->count; i++) {
            set_global_param__8TObjFishFl(self->params[i]);
            push_matrix();
            post_translate_matrix(&self->positions[i]);
            rotate_matrix_z(0, self->rots[i].z);
            rotate_matrix_x(0, self->rots[i].x);
            rotate_matrix_y(0, self->rots[i].y);
            draw_ginja_object((void *)self->models[i]);
            pop_matrix();
        }
        pop_matrix();
    }
}

void *TOBoss4Rock::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB8);
    if (o != NULL) {
        o = TOBoss4Rock__ct(o, arg0);
    }
    return o;
}

extern s32 __vt__11TOBoss4Rock[];

}
TOBoss4Rock::~TOBoss4Rock() {
    if (*(void **)((s8 *)this + 0xA0) != NULL) { mem_free(*(void **)((s8 *)this + 0xA0)); }
    if (*(void **)((s8 *)this + 0xA4) != NULL) { mem_free(*(void **)((s8 *)this + 0xA4)); }
    if (*(void **)((s8 *)this + 0xA8) != NULL) { mem_free(*(void **)((s8 *)this + 0xA8)); }
    if (*(void **)((s8 *)this + 0xAC) != NULL) { mem_free(*(void **)((s8 *)this + 0xAC)); }
    if (*(void **)((s8 *)this + 0xB0) != NULL) { mem_free(*(void **)((s8 *)this + 0xB0)); }
    if (*(void **)((s8 *)this + 0xB4) != NULL) { mem_free(*(void **)((s8 *)this + 0xB4)); }
}

#pragma fp_contract on
struct VBase_18_1a504b { char pad[0x18]; };
struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct Vec_80158FB4 { f32 x, y, z; };
struct Rot_80158FB4 { s32 x, y, z; };
struct Rock_80158FB4 {
    u8 pad0[0x6C];
    f32 f6c;
    u8 pad70[0x98 - 0x70];
    f32 spread;
    s32 count;
    s32 *models;
    s32 *params;
    Vec_80158FB4 *positions;
    f32 *speeds;
    Rot_80158FB4 *rots;
    Rot_80158FB4 *rotspd;
};

extern "C" {

void TOBoss4__ct(void *, void *);
extern s32 lbl_805D2EBC;

#pragma push
#pragma dont_inline off
#pragma auto_inline off
#pragma inline_depth(4)
inline s32 irand_80158FB4(f32 scale) {
    return (s32)(scale * ((3.0517578e-05f) * (f32)rand()));
}

inline void set_model_80158FB4(Rock_80158FB4 *self, s32 i, s32 k) {
    self->models[i] = get_bml_model(lbl_805D58A8, k);
    self->params[i] = TObjFish__sub_8001EDB0(lbl_805D58A8, k);
}

inline void respawn_80158FB4(Rock_80158FB4 *self, s32 i) {
    f32 base;
    set_model_80158FB4(self, i, irand_80158FB4((4.0f)));
    self->positions[i].x = self->spread * ((3.0517578e-05f) * (f32)rand());
    self->positions[i].y = (0.0f);
    self->positions[i].z = self->spread * ((3.0517578e-05f) * (f32)rand());
    base = (0.5f) * self->f6c;
    self->speeds[i] = base * ((3.0517578e-05f) * (f32)rand()) + base;
    self->rots[i].x = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rots[i].y = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rots[i].z = (s32)((65535.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].x = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].y = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
    self->rotspd[i].z = (s32)((4096.0f) * ((3.0517578e-05f) * (f32)rand()));
}

#define arg0 ((u8 *)arg0_)
#define self ((Rock_80158FB4 *)arg0_)
void *TOBoss4Rock__ct(void *arg0_, void *arg1) {
    s32 i;

    TOBoss4__ct(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TOBoss4Rock;
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D2EBC;
    ((VObj_18_1a504b *)(arg0))->m5((s32)arg1);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(lbl_805D58A8, 1);
    *(f32 *)((s8 *)arg0 + 0x94) = *(f32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x34)) + 4)) + 0x14);
    *(s32 *)((s8 *)arg0 + 0x24) = TObjFish__sub_8001EDB0(lbl_805D58A8, 1);
    self->spread = (5e+01f) + *(f32 *)((s8 *)arg0 + 0x68);
    if (self->f6c < (0.0f)) {
        self->f6c *= (-1.0f);
    }
    self->count = *(s32 *)((s8 *)arg0 + 0x84);
    if (self->count < 1) {
        self->count = 1;
    } else if (self->count > 8) {
        self->count = 8;
    }
    self->models = (s32 *)mem_alloc(self->count * 4);
    self->params = (s32 *)mem_alloc(self->count * 4);
    self->positions = (Vec_80158FB4 *)mem_alloc(self->count * 0xC);
    self->speeds = (f32 *)mem_alloc(self->count * 4);
    self->rots = (Rot_80158FB4 *)mem_alloc(self->count * 0xC);
    self->rotspd = (Rot_80158FB4 *)mem_alloc(self->count * 0xC);
    for (i = 0; i < self->count; i++) {
        respawn_80158FB4(self, i);
    }
    return arg0;
}
#undef arg0
#undef self
#pragma pop

}

#define TObjFish__sub_8001EDB0 ((s32 (*)(void*,int))TObjFish__sub_8001EDB0)
#define get_bml_model ((s32 (*)(void*,int))get_bml_model)
#define rotate_matrix_y ((s32 (*)(s32,s32))rotate_matrix_y)
#define set_global_param__8TObjFishFl ((s32 (*)(s32))set_global_param__8TObjFishFl)
#define TOBoss4__ct ((s32 (*)(void))TOBoss4__ct)

struct RecoveredGlobal_80159514___vt__12TOBoss4Tower {
    s32 value;
    u8 remaining[0x30];
};

extern "C" {
extern s32 __vt__12TOBoss4Tower[];
extern s32 lbl_805D2EB8;
u8 *TOBoss4Tower__ct(u8 *arg0, s32 arg1);
struct Base_80159400 { char pad[0x18]; };
struct VObj_80159400 : Base_80159400 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

void *TOBoss4Tower__create(void *arg0);

void *TOBoss4Tower__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TOBoss4Tower__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void TOBoss4Tower::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_80159400 *)arg0)->m8(*(f32 *)&this->unk_90, this->m_94) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        set_global_param__8TObjFishFl(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

}
TOBoss4Tower::~TOBoss4Tower() {

}
extern "C" {
typedef char RecoveredGlobal_80159514___vt__12TOBoss4Tower_size[sizeof(RecoveredGlobal_80159514___vt__12TOBoss4Tower) == 0x34 ? 1 : -1];
u8 *TOBoss4Tower__ct(u8 *boss4_tower, s32 arg1) {
    TOBoss4__ct();
    *(s32 **)((s8 *)boss4_tower + 0x18) = &(*(RecoveredGlobal_80159514___vt__12TOBoss4Tower *)&__vt__12TOBoss4Tower).value;
    *(s32 *)((s8 *)boss4_tower + 0) = (s32) lbl_805D2EB8;
    ((TOBoss4Tower *)(boss4_tower))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)boss4_tower + 0x34) = get_bml_model((void *)lbl_805D58A8, 5);
    ((TOBoss4Tower *)boss4_tower)->m_94 = (f32) (6e+01f);
    ((TOBoss4Tower *)boss4_tower)->texlist = TObjFish__sub_8001EDB0((void *)lbl_805D58A8, 5);
    return boss4_tower;
}

#undef TObjFish__sub_8001EDB0
#undef get_bml_model
#undef rotate_matrix_y
#undef set_global_param__8TObjFishFl
#undef TOBoss4__ct
struct Vec_8015959C { f32 x, y, z; };

struct Bird_8015959C {
    u8 pad0[0x38];
    Vec_8015959C f38;
    u8 pad44[0x50 - 0x44];
    Vec_8015959C f50;
    u8 pad5c[0x60 - 0x5c];
    s32 f60;
    u8 pad64[0x9c - 0x64];
    f32 f9c;
    f32 fa0;
    f32 fa4;
    f32 fa8;
    f32 fac;
    f32 fb0;
    s32 state;
    u8 padb8[0xc4 - 0xb8];
    Vec_8015959C fc4;
    f32 fd0;
    f32 fd4;
    u8 padd8[0xdc - 0xd8];
    s32 fdc;
    s32 fe0;
    s32 fe4;
};

f32 atan2_float(f32, f32);
f32 horizontal_distance_squared(Vec_8015959C *, Vec_8015959C *);
s32 approach_angle_limited(s32, s32, s32);
s32 rand(void);
f32 sin_table_lookup(s32);
void vec3_add_to(Vec_8015959C *, Vec_8015959C *);
void rotate_vector_by_matrix(s32, Vec_8015959C *, Vec_8015959C *);
void subtract_vector(Vec_8015959C *, Vec_8015959C *);
void push_matrix_from(void *);
void pop_matrices(s32);
extern Vec_8015959C scratch_vec;
extern Vec_8015959C lbl_8050BF00;
extern u8 identity_matrix[];

void TOBoss4Bird::run_task() {
    Bird_8015959C *self = (Bird_8015959C *)this;
    self->fa4 += self->fa0;
    if (self->f9c < self->fa4) {
        self->fa4 -= self->f9c;
    }
    self->fe0 += self->fdc;
    self->fd4 = self->fd0 * sin_table_lookup(self->fe0);
    switch (self->state) {
    case 0:
        self->state = 1;
        scratch_vec.x = (0.0f);
        scratch_vec.y = self->fac * ((3.0517578e-05f) * (f32)rand());
        scratch_vec.z = self->fb0 * ((3.0517578e-05f) * (f32)rand());
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, (s32)((182.04445f) * ((3.6e+02f) * ((3.0517578e-05f) * (f32)rand()))));
        rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
        pop_matrices(1);
        VecCopy((Vec *)&self->fc4, (const Vec *)&self->f50);
        vec3_add_to(&self->fc4, &scratch_vec);
        break;
    case 1:
        VecCopy((Vec *)&scratch_vec, (const Vec *)&self->fc4);
        subtract_vector(&scratch_vec, &self->f38);
        self->f60 = approach_angle_limited(self->f60, (s32)((10430.38043493439) * atan2_float(scratch_vec.x, scratch_vec.z)), 0x100);
        lbl_8050BF00.x = lbl_8050BF00.y = (0.0f);
        lbl_8050BF00.z = self->fa8;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->f60);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&self->f38, &lbl_8050BF00);
        if (horizontal_distance_squared(&self->fc4, &self->f38) < self->fb0 || (1.5e+02f) < (f32)self->fe4++) {
            self->state = 0;
            self->fe4 = 0;
        }
        break;
    }
}

}

struct Vec_80159870 { f32 x, y, z; };

struct VBase_80159870 { char pad[0x18]; };

struct VObj_80159870 : VBase_80159870 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Bird_80159870 : VObj_80159870 {
    u8 pad1C[0x24 - 0x1C];
    s32 param;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_80159870 pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0x90 - 0x64];
    f32 f90;
    f32 f94;
    s32 f98;
    u8 pad9C[0xA4 - 0x9C];
    f32 fA4;
    u8 padA8[0xB8 - 0xA8];
    s32 count;
    Vec_80159870 *positions;
    s32 *rots;
    u8 padC4[0xD4 - 0xC4];
    f32 fD4;
};

extern "C" {
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 draw_ginja_model_with_motion(int, int, f32);
void TOBoss4Bird::render() {
    Bird_80159870 *self = (Bird_80159870 *)this;
    s32 i;
    if (self->m8(self->f90, self->f94) != 0) {
        push_matrix();
        post_translate_matrix(&self->pos);
        set_global_param__8TObjFishFl(self->param);
        for (i = 0; i < self->count; i++) {
            push_matrix();
            translate_matrix(0, (0.0f), self->fD4, (0.0f));
            post_translate_matrix(&self->positions[i]);
            rotate_matrix_y(0, self->rotY);
            rotate_matrix_y(0, self->rots[i]);
            draw_ginja_model_with_motion(self->f34, self->f98, self->fA4);
            pop_matrix();
        }
        pop_matrix();
    }
}

void *TOBoss4Bird::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TOBoss4Bird__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

}
TOBoss4Bird::~TOBoss4Bird() {
    if (*(void **)((s8 *)this + 0xBC) != NULL) { mem_free(*(void **)((s8 *)this + 0xBC)); }
    if (*(void **)((s8 *)this + 0xC0) != NULL) { mem_free(*(void **)((s8 *)this + 0xC0)); }
}
#define get_bml_model ((u8* (*)(s32,s32))get_bml_model)
#define TOBoss4__ct ((void (*)(void*))TOBoss4__ct)
#define __vt__11TOBoss4Bird (*(u8 (*)[1])&__vt__11TOBoss4Bird)

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Vec_80159A10 { f32 x, y, z; };

struct VecTbl_80159A10 { Vec_80159A10 v[6]; };

struct Bird_80159A10 {
    s32 f0;
    u8 pad4[0x24 - 0x4];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    u8 *model;
    u8 pad38[0x68 - 0x38];
    f32 f68, f6C, f70;
    u8 pad74[0x84 - 0x74];
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x94 - 0x90];
    f32 f94;
    u8 *motion;
    f32 f9C, fA0, fA4;
    f32 fA8, fAC, fB0;
    s32 fB4;
    s32 count;
    Vec_80159A10 *vecs;
    s32 *angs;
    f32 fC4, fC8, fCC;
    f32 fD0;
    f32 fD4;
    f32 fD8;
    s32 fDC;
    s32 fE0;
    s32 fE4;
};

extern "C" {
u8 *get_bml_motion(s32, s32);
extern VecTbl_80159A10 boss4_bird_vec_table[];
extern s32 lbl_805D2EB4;
u8 *TOBoss4Bird__ct(u8 *arg0, s32 arg1);
#pragma push
#pragma fp_contract on
u8 *TOBoss4Bird__ct(u8 *boss4_bird, s32 arg1) {
    Bird_80159A10 *o = (Bird_80159A10 *)boss4_bird;
    s32 i;
    TOBoss4__ct(boss4_bird);
    *(u8 **)(boss4_bird + 0x18) = __vt__11TOBoss4Bird;
    o->f0 = lbl_805D2EB4;
    ((TOBoss4Bird *)boss4_bird)->apply_object_set_data((void *)arg1);
    o->model = get_bml_model(lbl_805D58A8, 0);
    o->f94 = *(f32 *)(*(u8 **)(o->model + 4) + 0x14);
    o->f24 = TObjFish__sub_8001EDB0(lbl_805D58A8, 0);
    o->motion = get_bml_motion(lbl_805D58A8, 0);
    o->f9C = (f32)*(u32 *)(o->motion + 4) - (1.0f);
    o->fA0 = (1.0f);
    o->fA4 = (0.0f);
    o->fA8 = (1.0f) + o->f68;
    o->fAC = (5e+01f) + o->f6C;
    o->fB0 = (1e+02f) + o->f70;
    o->fB4 = 0;
    o->count = o->f84 + 3;
    if (o->count < 0) {
        o->count = 1;
    } else if (o->count > 6) {
        o->count = 6;
    }
    o->vecs = (Vec_80159A10 *)mem_alloc(o->count * 0xC);
    o->angs = (s32 *)mem_alloc(o->count * 4);
    {
        VecTbl_80159A10 tbl = boss4_bird_vec_table[0];
        for (i = 0; i < o->count; i++) {
            VecCopy((Vec *)&o->vecs[i], (const Vec *)&tbl.v[i]);
            o->angs[i] = 0x8000;
        }
    }
    o->fC4 = o->fC8 = o->fCC = (0.0f);
    o->fD8 = (0.1f) * (f32)o->f88 + (1.0f);
    o->fDC = (s32)((182.04445f) * ((3.6e+02f) / ((3e+01f) / o->fD8)));
    o->fE0 = (s32)((182.04445f) * ((3.6e+02f) * ((3.0517578e-05f) * (f32)rand())));
    o->fD0 = (0.1f) * (f32)o->f8C + (1.0f);
    o->fD4 = o->fD0 * sin_table_lookup(o->fE0);
    o->fE4 = 0;
    return boss4_bird;
}
#pragma pop

}

#undef get_bml_model
#undef TOBoss4__ct
#undef __vt__11TOBoss4Bird
