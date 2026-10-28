#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjLazerFenceExtra.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TKomorebi.h"
#include "pso/object/TObjFish.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjMotion.h"

extern char lbl_80445A00[];
extern char lbl_80445A10[];
extern const char *bm_fe_obj_komo_model_names[2];
extern BmlResourceDescriptor TKomorebi__resource_descriptor;
extern const char *bm_fe_obj_komo_motion_names[1];

struct VObjBase_80192174 { char pad[0x18]; };
struct VObj_80192174 : VObjBase_80192174 {
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

struct RecoveredGlobal_801922C4___vt__9TKomorebi {
    s32 value;
    u8 remaining[0x34];
};

struct Node_80192434 { u32 flags; void *model; u8 pad8[0x24]; Node_80192434 *child; Node_80192434 *sibling; };

struct Fish_80192434 { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80192434 *fBC; Node_80192434 *fC0; s32 fC4; void *fC8[4]; };

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
s32 __ct__13TUnk_804B9870FP7TObject(void *);
extern s32 __vt__9TKomorebi[];
extern s32 komorebi_class_name;
extern u32 TKomorebi__resource_bundle;
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 komorebi_last_uv_update_frame;
s32 get_bml_motion(s32, s32);
extern s32 lazer_fence_norm_bml_resource;
void TLobby__sub_8001FE7C(void*, int);
s32 scroll_ginja_mesh_uvs(s32, s32, s32, s32, s32);
s32 post_translate_matrix(void *);
s32 scale_matrix(s32, f32, f32, f32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
f32 xz_distance_squared(void *, s32);

extern s32 camera_ctrl_instance;
extern s32 actor_frame_tick;
extern const f32 lbl_805DBE48;
extern const f32 lbl_805DBE4C;
extern const f32 lbl_805DBE50;

void TKomorebi::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;

    if ((((VObj_80192174*)arg0)->m8(lbl_805DBE48, lbl_805DBE4C) != 0) && !(xz_distance_squared((u8 *)&this->position, camera_ctrl_instance + 0x178) < lbl_805DBE50)) {
        TParticleCtrl::begin_effect_render();
        if ((s32) actor_frame_tick != (s32) komorebi_last_uv_update_frame) {
            scroll_ginja_mesh_uvs(*(s32 *)((s8 *)(*(void * *)&this->model) + 4), 0, (s32) this->scale.x, 0, 1);
            komorebi_last_uv_update_frame = actor_frame_tick;
        }
        push_matrix();
        TObjFish::set_global_param(this->texture_id);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, *(s32 *)&this->rotation_x, this->rotation_y, this->rotation_z);
        temp_f1 = this->scale.z;
        scale_matrix(0, temp_f1, this->scale.y, temp_f1);
        draw_ginja_object(*(void * *)&this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TKomorebi::run_task() {  }

void *__dt__9TKomorebiFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__9TKomorebi;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_801922C4___vt__9TKomorebi_size[sizeof(RecoveredGlobal_801922C4___vt__9TKomorebi) == 0x38 ? 1 : -1];
u8 *TKomorebi__ct(u8 *komorebi, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B9870FP7TObject(komorebi);
    *(s32 **)((s8 *)komorebi + 0x18) = &(*(RecoveredGlobal_801922C4___vt__9TKomorebi *)&__vt__9TKomorebi).value;
    *(s32 *)((s8 *)komorebi + 0) = (s32) komorebi_class_name;
    VecCopy((Vec *)(komorebi + 0x38), (const Vec *)(arg2 + 0xC));
    ((TObjPlayer *)(komorebi + 0x5C))->copy_xyz((void *)(arg2 + 0x18));
    VecCopy((Vec *)(komorebi + 0x68), (const Vec *)(arg2 + 0x24));
    *(s32 *)((s8 *)komorebi + 0x34) = get_bml_model((void *) ((*(s32 *)&TKomorebi__resource_bundle)), 0);
    ((TKomorebi *)komorebi)->texture_id = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&TKomorebi__resource_bundle)), 0);
    return komorebi;
}

void *TKomorebi__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x90);
    if (o != NULL) {
        o = TKomorebi__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TKomorebi::free_static() {
    if ((u32) TKomorebi__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TKomorebi__resource_bundle, 1);
        TKomorebi__resource_bundle = 0U;
    }
    komorebi_last_uv_update_frame = 0;
}
void TKomorebi::load_resources() {
    u8 *p = (u8 *)::operator new(0x440);
    if (p != 0) {
        p = load_resource_from_descriptor(p, 1, &TKomorebi__resource_descriptor, 0, 0, 0);
    }
    TKomorebi__resource_bundle = (u32)p;
    komorebi_last_uv_update_frame = 0;
}
void TObjLazerFenceExtra::init_models() {
    Fish_80192434 *arg0 = (Fish_80192434 *)this;
    s32 i;
    Node_80192434 *node;
    s32 j;
    if (*(s32 *)&this->set_params[2] % 2 == 0) {
        arg0->fBC = (Node_80192434 *)get_bml_model((void *)lazer_fence_norm_bml_resource, 1);
        arg0->fC0 = (Node_80192434 *)get_bml_model((void *)lazer_fence_norm_bml_resource, 0);
        this->m_c4 = get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        arg0->fBC = (Node_80192434 *)get_bml_model((void *)lazer_fence_norm_bml_resource, 3);
        arg0->fC0 = (Node_80192434 *)get_bml_model((void *)lazer_fence_norm_bml_resource, 2);
        this->m_c4 = get_bml_motion(lazer_fence_norm_bml_resource, 1);
    }
    for (j = 0; j < 4; j++) {
        arg0->fC8[j] = 0;
    }
    i = 0;
    node = arg0->fC0->child;
    if (node != 0) {
        arg0->fC8[i++] = node->model;
        node = node->sibling;
        while (node != 0 && i < 4) {
            arg0->fC8[i++] = node->model;
            node = node->sibling;
        }
    }
}

__declspec(section ".data") const char *bm_fe_obj_komo_model_names[2] = { lbl_80445A00, NULL };
BmlResourceDescriptor TKomorebi__resource_descriptor = { lbl_80445A10, bm_fe_obj_komo_model_names, bm_fe_obj_komo_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_fe_obj_komo_motion_names[1] = { NULL };
}
