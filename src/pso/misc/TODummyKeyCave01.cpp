#include "types.h"
#include "pso/misc/TODummyKeyCave01.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/TODummyKeyCave01Sound.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODummyKeyCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct RecoveredGlobal_80165EE8___vt__16TODummyKeyCave01 { s32 value; u8 remaining[0x34]; };

struct VBase_80165B50 { char pad[0x18]; };

struct VObj_80165B50 : VBase_80165B50 {
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

struct Obj_80165C84 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x90 - 0x28];
    s32 f90;
    s32 f94;
    u16 f98;
    u16 f9A;
    u8 pad9C[0xA0 - 0x9C];
    f32 fA0;
    u8 padA4[0xB0 - 0xA4];
    f32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s32 fB8;
    u8 padBC[0xC0 - 0xBC];
    s32 fC0;
    s32 fC4;
    s32 fC8;
    s32 fCC;
};

extern "C" {
u8 * __ct__8TObjBaseFP7TObject(void *);
s32 sub_80165940__16TODummyKeyCave01Fv(void *, f32);
extern s32 __vt__16TODummyKeyCave01[];
extern s32 TODummyKeyCave01__class_name;
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
u8 is_current_floor_switch_set(u16);
void *__nw__7TObjectFUl(int);
void __dl__7TObjectFPv(void *);

extern void *tl_05;

void TODummyKeyCave01::render() {
    u8 *arg0 = (u8 *)this;
    u32 v;
    u8 *node;
    s32 id;
    if (((VObj_80165B50 *)arg0)->m8((4e+02f), (2e+01f)) != 0 && *(void **)(arg0 + 0x34) != NULL &&
        (v = *(u32 *)(arg0 + 0x24)) != 0) {
        set_texlist(v);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_zyx(0, *(s32 *)(arg0 + 0x5C), *(s32 *)(arg0 + 0x60), *(s32 *)(arg0 + 0x64));
        scale_current_matrix((u8 *)&this->scale);
        node = *(u8 **)(arg0 + 0x34);
        draw_ginja_model(*(s32 *)(node + 4));
        if (*(u16 *)(arg0 + 0x9A) == 0) {
            id = model_render_flags;
            saved_model_render_flags = id;
            model_render_flags = id | 0x10;
            set_constant_material((const NJS_ARGB *)(((f32 *)&this->m_9c)));
        }
        TParticleCtrl::begin_effect_render();
        node = *(u8 **)(node + 0x2C);
        if (*(s32 *)(arg0 + 0xD0) != 0) {
            rotate_matrix_y(0, *(s32 *)(arg0 + 0xCC));
        } else {
            post_translate_matrix((u8 *)&this->m_ac);
        }
        post_translate_matrix(node + 8);
        draw_ginja_model(*(s32 *)(node + 4));
        node = *(u8 **)(node + 0x2C);
        post_translate_matrix(node + 8);
        draw_ginja_model(*(s32 *)(node + 4));
        if (*(u16 *)(arg0 + 0x9A) == 0) {
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void TODummyKeyCave01::run_task() {
    Obj_80165C84 *self = (Obj_80165C84 *)this;
    u32 st;
    u8 skip;
    void *o;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((TObjBase *)self)->obj_clearFlags30(0x08000000);
    }
    if (this->m_98 < 0x100) {
        st = is_current_floor_switch_set(this->m_98);
        if (st != this->m_9a) {
            this->m_9a = st;
            skip = 0;
            if (*(s32 *)&this->m_c4 == 1 && st == 0) {
                skip = 1;
            }
            if (skip == 0) {
                o = __nw__7TObjectFUl(0x24);
                if (o != NULL) {
                    TODummyKeyCave01Sound__ct((void *)o, (s32)self, (s32)*(s32 *)&this->m_c0, (s32)*(s32 *)&this->m_c8);
                }
            }
        }
    }
    if (this->m_9a == 1) {
        this->texlist = *(s32 *)&this->m_94;
        f32 lo = (-0.7f);
        if (lo < self->fB0) {
            self->fB0 += (-0.023333333f);
            if (self->fB0 < lo) {
                self->fB0 = lo;
            }
        }
        if (*(s32 *)&this->m_cc < 0x2000) {
            *(s32 *)&this->m_cc = *(s32 *)&this->m_cc + 0x333;
        }
    } else {
        this->texlist = *(s32 *)&this->m_90;
        if (self->fB0 < (0.0f)) {
            self->fB0 = self->fB0 - (-0.023333333f);
            if ((0.0f) < self->fB0) {
                self->fB0 = (0.0f);
            }
        }
        if (*(s32 *)&this->m_b8 == 1) {
            self->fA0 += 0.1f;
            if (1.0f <= self->fA0) {
                self->fA0 = 1.0f;
                *(s32 *)&this->m_b8 = 0;
            }
        } else {
            self->fA0 -= 0.1f;
            if (self->fA0 <= 0.0f) {
                self->fA0 = 0.0f;
                *(s32 *)&this->m_b8 = 1;
            }
        }
        if (*(s32 *)&this->m_cc > 0) {
            *(s32 *)&this->m_cc = *(s32 *)&this->m_cc - 0x333;
        }
    }
}

void *TODummyKeyCave01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TODummyKeyCave01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODummyKeyCave01__sub_80165E88(void) {  }
void TODummyKeyCave01__sub_80165E8C(void) {  }

}
TODummyKeyCave01::~TODummyKeyCave01() {

}
extern "C" {
u8 *TODummyKeyCave01__ct(u8 *dummy_key_cave01, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(dummy_key_cave01);
    *(s32 **)((s8 *)dummy_key_cave01 + 0x18) = &(*(RecoveredGlobal_80165EE8___vt__16TODummyKeyCave01 *)&__vt__16TODummyKeyCave01).value;
    *(s32 *)((s8 *)dummy_key_cave01 + 0) = (s32) TODummyKeyCave01__class_name;
    ((TODummyKeyCave01 *)(dummy_key_cave01))->apply_object_set_data((void *)arg2);
    *(f32 *)((s8 *)dummy_key_cave01 + 0xA8) = (f32) 1.0f;
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_a4 = (f32) 1.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0xA0) = (f32) 1.0f;
    *(f32 *)((s8 *)dummy_key_cave01 + 0x9C) = (f32) 1.0f;
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_b4 = (f32) (0.0f);
    *(f32 *)((s8 *)dummy_key_cave01 + 0xB0) = (f32) (0.0f);
    *(f32 *)((s8 *)dummy_key_cave01 + 0xAC) = (f32) (0.0f);
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_b8 = 1;
    sub_80165940__16TODummyKeyCave01Fv(dummy_key_cave01, (f32) (1.0f));
    ((TODummyKeyCave01 *)dummy_key_cave01)->m_cc = 0;
    return dummy_key_cave01;
}

}
