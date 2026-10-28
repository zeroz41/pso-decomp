#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOCakeshopCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8015A108_lbl_804AFDF8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8015A108_lbl_804AFDF8_size[sizeof(RecoveredGlobal_8015A108_lbl_804AFDF8) == 0x10 ? 1 : -1];

struct TOCakeshopCave01_80159E24 {
    u8 pad0[0xCC];
    f32 val[8];
    u8 state[8];
};

struct TOCakeshopCave01_8015A1C0 {
    u8 pad0[0xCC];
    f32 val[8];
    u8 state[8];
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
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

struct Model_80159F78 {
    u8 pad0[4];
    s32 m4;
    u8 m8[0x24];
    Model_80159F78 *child;
    Model_80159F78 *next;
};

struct Obj_80159F78 { u8 pad0[0xCC]; f32 val[8]; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015A108_lbl_804AFDF8 bm_fs_obj_cakeya_resource_descriptor;
extern u32 TOCakeshopCave01__model_resource;
s32 rand(void);
extern const f32 lbl_805DB358;
extern const f32 lbl_805DB35C;
extern const f32 TOCakeshopCave01__data_805DB360;
extern const f32 lbl_805DB364;
s32 init_collision_body_parts(void *, void *, int);
s32 init_map_object_base(void *, s32);
extern s32 cakeshop_cave01_collision_body_part[];
extern s32 __vt__16TOCakeshopCave01[];
extern s32 lbl_805D2EC4;
extern s32 tl_05;
extern const f32 lbl_805DB36C;
extern const f32 lbl_805DB370;
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern const f32 lbl_805DB368;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOCakeshopCave01::update_blink_state(void *arg1) {
    TOCakeshopCave01_80159E24 *o = (TOCakeshopCave01_80159E24 *)this;
    s32 i = (s32)arg1;
    switch (o->state[i]) {
    default:
        o->val[i] += lbl_805DB358;
        if (lbl_805DB35C * (f32)rand() < o->val[i]) {
            o->state[i] = 1;
            o->val[i] = TOCakeshopCave01__data_805DB360;
        }
        break;
    case 1:
        o->val[i] -= lbl_805DB358;
        if (o->val[i] <= lbl_805DB364) {
            o->state[i] = 2;
            o->val[i] = lbl_805DB364;
        }
        break;
    case 2:
        o->val[i] += lbl_805DB358;
        if (TOCakeshopCave01__data_805DB360 < o->val[i]) {
            o->state[i] = 0;
        }
        break;
    }
}

void TOCakeshopCave01::run_task() { { int i; for (i = 0; i < 8; i++) { update_blink_state((void *)((void*)i)); } } }

void TOCakeshopCave01::render() {
    u8 *arg0 = (u8 *)this;
    Model_80159F78 *m;
    s32 i;
    if (((VObj_18_26a62c *)(arg0))->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        m = *(Model_80159F78 * *)&this->model;
        post_translate_matrix(m->m8);
        draw_ginja_model(m->m4);
        m = m->child;
        TParticleCtrl::begin_effect_render();
        for (i = 0; i < 8; i++) {
            if (((Obj_80159F78 *)arg0)->val[i] < TOCakeshopCave01__data_805DB360) {
                push_matrix();
                post_translate_matrix(m->m8);
                scale_matrix(0, lbl_805DB368 - ((Obj_80159F78 *)arg0)->val[i], lbl_805DB368 - ((Obj_80159F78 *)arg0)->val[i], TOCakeshopCave01__data_805DB360);
                draw_ginja_model(m->m4);
                pop_matrix();
            }
            m = m->next;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOCakeshopCave01::create() {
    void *o = __nw__7TObjectFUl(0xF4);
    if (o != NULL) {
        o = TOCakeshopCave01__ct(o, this);
    }
    return o;
}

void TOCakeshopCave01::close_dialog_window() {
    if ((u32) TOCakeshopCave01__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOCakeshopCave01__model_resource, 1);
        TOCakeshopCave01__model_resource = 0U;
    }
}

void TOCakeshopCave01::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_cakeya_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOCakeshopCave01__model_resource) = var_r0;
}

void *__dt__16TOCakeshopCave01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOCakeshopCave01;
        free_collision_body_parts(arg0);
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
void *TOCakeshopCave01__ct(void *arg0_, void *arg1) {
    u8 *arg0 = (u8 *)arg0_;
    s32 i;
    init_map_object_base(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOCakeshopCave01;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2EC4;
    ((TOCakeshopCave01 *)(arg0))->apply_object_set_data((void *)((s32)arg1));
    *(s32 *)((s8 *)arg0 + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCakeshopCave01__model_resource + 0x42C)) + 8);
    *(s32 *)((s8 *)arg0 + 0x24) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCakeshopCave01__model_resource + 0x42C)) + 0xC);
    *(f32 *)((s8 *)arg0 + 0xC0) = lbl_805DB36C;
    *(f32 *)((s8 *)arg0 + 0xC4) = lbl_805DB370;
    *(s32 *)((s8 *)arg0 + 0x30) |= 0x40000000;
    init_collision_body_parts(arg0, cakeshop_cave01_collision_body_part, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    for (i = 0; i < 8; i++) {
        ((TOCakeshopCave01_8015A1C0 *)arg0)->val[i] = TOCakeshopCave01__data_805DB360;
        ((TOCakeshopCave01_8015A1C0 *)arg0)->state[i] = 0;
    }
    return arg0;
}

}
