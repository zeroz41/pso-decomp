#include "types.h"
#include "pso/object/ambient/TButterfly.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>

__declspec(section ".data") const char *bm_o_abe_butterfly_model_names[2] = { "abecyou_fe_obj001_cyou.gj", NULL };
__declspec(section ".data") const char *bm_o_abe_butterfly_motion_names[2] = { "abecyou2_fe_obj001_cyou.njm", NULL };
BmlResourceDescriptor bm_o_abe_butterfly_resource_descriptor = {
    "bm_o_abe_butterfly.bml", bm_o_abe_butterfly_model_names, bm_o_abe_butterfly_motion_names, 1, 1
};
const char *TButterfly__name = "TButterfly";

struct Base_8017E978 { char pad[0x18]; };
struct VObj_8017E978 : Base_8017E978 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

struct Vec_8017EA74 { f32 x, y, z; };

struct Butterfly_8017EA74 {
    u8 pad0[0x38];
    Vec_8017EA74 pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0x94 - 0x64];
    f32 baseY;
    u8 pad98[0x9C - 0x98];
    Vec_8017EA74 vel;
    f32 phase;
    f32 phaseSpeed;
    f32 lift;
    s16 timer;
    s16 angle;
    u8 state;
    u8 flag;
    u8 dir;
};

extern "C" {
void vec3_add_to(Vec_8017EA74 *, Vec_8017EA74 *);
void rotate_vector_by_matrix(void *, Vec_8017EA74 *, Vec_8017EA74 *);
extern u8 identity_matrix[];
s32 TObjFish__sub_8001EDB0(s32, s32);
void __dl__7TObjectFPv(void *);
s32 set_global_param__8TObjFishFl();

void TButterfly::init_motion() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)&this->unk_90, (const Vec *)&this->position);
    *(f32 *)&this->m_9c = (f32) (0.0f);
    *(f32 *)&this->unk_A0 = (f32) (0.0f);
    this->m_a4 = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0xA8) = (f32) ((0.5f) * ((3.0517578e-05f) * (f32) rand()));
    this->m_b0 = (f32) (0.0f);
    this->m_b8 = 0;
    this->m_b9 = 0;
    this->m_b4 = 0x1E;
    this->m_b6 = 0;
}

extern s32 butterfly_bml_resource;

void TButterfly::render() {
    if (((VObj_8017E978*)this)->m8((4e+02f), (2e+01f)) != 0) {
        TObjFish__sub_8001EDB0(butterfly_bml_resource, 0);
        set_global_param__8TObjFishFl();
        draw_model();
    }
}

extern s32 __vt__10TButterfly[];

#pragma push
#pragma fp_contract on
void TButterfly::run_task() {
    Butterfly_8017EA74 *self = (Butterfly_8017EA74 *)this;
    f32 target;
    f32 lift;
    target = 3.2f * sin_table_lookup(self->angle) + self->baseY;
    if (self->flag == 0) {
        self->lift = 5.0f * (target - self->pos.y);
        lift = self->lift;
        if (lift < 0.1f) {
            self->lift = 0.1f;
        } else if (lift > 4.0f) {
            self->lift = 4.0f;
        }
        self->phaseSpeed = 2.0f * (0.01f * self->lift) + 0.3f;
        self->vel.y = 0.1f * (0.027f * self->lift) + self->vel.y;
        self->vel.y = self->vel.y - 0.027f;
        self->phase = self->phase + self->phaseSpeed;
        if (self->phase > 5.0f) {
            self->phase = 0.0f;
        }
    } else {
        self->lift = -7.0f * (target - self->pos.y);
        lift = self->lift;
        if (lift < 0.1f) {
            self->lift = 0.1f;
        } else if (lift > 4.0f) {
            self->lift = 4.0f;
        }
        self->phaseSpeed = 2.0f * (0.1f * self->lift) + 0.32f;
        self->vel.y = self->vel.y - 0.5f * (0.027f * self->lift);
        self->vel.y = self->vel.y - 0.027f;
        self->phase = self->phase + self->phaseSpeed;
        if (self->phase > 5.0f) {
            self->phase = 0.0f;
            self->flag = 0;
        }
    }
    switch (self->state) {
    case 0:
        self->vel.x *= (0.8f);
        self->vel.z *= (0.8f);
        break;
    case 1:
        if (self->flag == 0) {
            Vec_8017EA74 dir;
            Vec_8017EA74 out;
            dir.x = 2.0f * (0.0015f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.0015f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(NULL, self->rotY);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            self->vel.x = self->vel.x + out.x;
            self->vel.z = self->vel.z + out.z;
            self->vel.x *= (0.72f);
            self->vel.z *= (0.72f);
        } else {
            self->vel.x *= (0.85f);
            self->vel.z *= (0.85f);
        }
        break;
    case 2:
        if (self->dir == 0) {
            self->rotY = (f32)self->rotY + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        } else {
            self->rotY = (f32)self->rotY - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        }
        if (self->flag == 0) {
            Vec_8017EA74 dir;
            Vec_8017EA74 out;
            dir.x = 2.0f * (0.025f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.025f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(NULL, self->rotY);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            self->vel.x = self->vel.x + out.x;
            self->vel.z = self->vel.z + out.z;
            self->vel.x *= (0.85f);
            self->vel.z *= (0.85f);
        } else {
            self->vel.x *= (0.75f);
            self->vel.z *= (0.75f);
        }
        break;
    }
    vec3_add_to(&self->pos, &self->vel);
    if (self->pos.y > 12.0f + target) {
        self->pos.y = 12.0f + target;
    } else if (self->pos.y < target - 6.0f) {
        self->pos.y = target - 6.0f;
    }
    if (self->timer != 0) {
        self->timer--;
    } else {
        switch (self->state) {
        case 0:
            self->state = 1;
            self->timer = 2.0f * (20.0f * (3.0517578125e-05f * (f32)rand())) + 20.0f;
            break;
        case 1:
            if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                self->state = 2;
                self->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    self->dir = 0;
                } else {
                    self->dir = 1;
                }
            } else {
                self->state = 0;
                self->timer = 30.0f * (3.0517578125e-05f * (f32)rand()) + 30.0f;
            }
            break;
        case 2:
            if (3.0517578125e-05f * (f32)rand() < 0.4f) {
                self->state = 2;
                self->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    self->dir = 0;
                } else {
                    self->dir = 1;
                }
            } else {
                self->state = 1;
                self->timer = 2.0f * (30.0f * (3.0517578125e-05f * (f32)rand())) + 30.0f;
            }
            break;
        }
    }
    self->angle = self->angle + (s32)(40.0f * (3.0517578125e-05f * (f32)rand()) + 160.0f);
}
#pragma pop

}
TButterfly::~TButterfly() {

}
extern "C" {

}

extern "C" {

void free_bin_model_request(void*, int);
void __ct__8TObjBaseFP7TObject(void *);
void *__nw__7TObjectFUl(int);


}
TButterfly::TButterfly(TObject *arg1, void *arg2) : TObjBase(arg1) {
    this->m_name = TButterfly__name;
    VecCopy((Vec *)((char *)this + 56), (const Vec *)((char *)arg2 + 12));
    copy_xyz((char *)this + 92, (void *)((char *)arg2 + 24));
    VecCopy((Vec *)((char *)this + 104), (const Vec *)((char *)arg2 + 36));
    this->init_motion();
}
extern "C" {

extern void *tl_05;

void *TButterfly__create(void *arg0) {
    void *o = (void *)new TButterfly((TObject *)tl_05, (void *)arg0);
    return o;
}


void TButterfly::destroy_instance() {
    if ((u32) butterfly_bml_resource != 0U) {
        free_bin_model_request((void*)butterfly_bml_resource, 1);
        butterfly_bml_resource = 0U;
    }
}

u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);

void TButterfly::load_resources() {
    void *resource;
    u32 loaded;
    resource = ::operator new(0x440);
    loaded = (u32)resource;
    if (loaded != 0) {
        loaded = (u32)load_resource_from_descriptor(resource, 1, &bm_o_abe_butterfly_resource_descriptor, 0, 0, 0);
    }
    butterfly_bml_resource = loaded;
}

}
