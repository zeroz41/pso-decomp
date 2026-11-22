#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "types.h"
#include "pso/effect/TKomorebi.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/fence/TObjLazerFenceExtra.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/MatrixOps.h"

struct AnimationMotion;

#pragma readonly_strings on

extern const char *bm_fe_obj_komo_model_names[2];
extern BmlResourceDescriptor TKomorebi__resource_descriptor;
extern const char *bm_fe_obj_komo_motion_names[1];

struct Node_80192434 { u32 flags; void *model; u8 pad8[0x24]; Node_80192434 *child; Node_80192434 *sibling; };

struct Fish_80192434 { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80192434 *fBC; Node_80192434 *fC0; s32 fC4; void *fC8[4]; };

extern "C" {


extern const char *komorebi_class_name;
extern uaddr TKomorebi__resource_bundle;
extern s32 komorebi_last_uv_update_frame;
s32 post_translate_matrix(void *);
f32 xz_distance_squared(void *, s32);

extern s32 camera_ctrl_instance;

void TKomorebi::render() {
    f32 temp_f1;

    if ((this->update_object_view_visibility(400.0f, 20.0f) != 0) && !(xz_distance_squared((u8 *)&this->position, camera_ctrl_instance + 0x178) < 1600.0f)) {
        TParticleCtrl::begin_effect_render();
        if ((s32) actor_frame_tick != (s32) komorebi_last_uv_update_frame) {
            scroll_ginja_mesh_uvs(static_cast<NJS_OBJECT *>(this->model)->model, 0, (s32) this->scale.x, 0, 1);
            komorebi_last_uv_update_frame = actor_frame_tick;
        }
        push_matrix();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, this->rotation_x, this->rotation_y, this->rotation_z);
        temp_f1 = this->scale.z;
        scale_matrix(0, temp_f1, this->scale.y, temp_f1);
        draw_ginja_object(this->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TKomorebi::run_task() {  }

}
TKomorebi::~TKomorebi() {

}
#define komorebi ((u8 *)this)
TKomorebi::TKomorebi(TObject *parent, saddr arg2) : TObjBase(parent) {
    m_name = komorebi_class_name;
    VecCopy((Vec *)(komorebi + 0x38), (const Vec *)(arg2 + 0xC));
    copy_xyz(komorebi + 0x5C, (void *)(arg2 + 0x18));
    VecCopy((Vec *)(komorebi + 0x68), (const Vec *)(arg2 + 0x24));
    *(s32 *)((s8 *)komorebi + 0x34) = (saddr)get_bml_model((BmlResource *)(void *) ((*(saddr *)&TKomorebi__resource_bundle)), 0);
    ((TKomorebi *)komorebi)->texlist = (saddr)get_bml_texlist((BmlResource *)(void *) ((*(saddr *)&TKomorebi__resource_bundle)), 0);
}
#undef komorebi


void *TKomorebi__create(void *set_data) {
    return new TKomorebi(tl_05, (saddr)set_data);
}

void TKomorebi::free_static() {
    if ((u32) TKomorebi__resource_bundle != 0U) {
        delete (BmlResource *)TKomorebi__resource_bundle;
        TKomorebi__resource_bundle = 0U;
    }
    komorebi_last_uv_update_frame = 0;
}
void TKomorebi::load_resources() {
    u8 *p = (u8 *)new BmlResource(1, &TKomorebi__resource_descriptor, 0, 0, NULL);
    TKomorebi__resource_bundle = (uaddr)p;
    komorebi_last_uv_update_frame = 0;
}
void TObjLazerFenceExtra::init_models() {
    Fish_80192434 *arg0 = (Fish_80192434 *)this;
    s32 i;
    Node_80192434 *node;
    s32 j;
    if (this->set_params[2] % 2 == 0) {
        arg0->fBC = (Node_80192434 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 1);
        arg0->fC0 = (Node_80192434 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 0);
        this->m_c4 = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        arg0->fBC = (Node_80192434 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 3);
        arg0->fC0 = (Node_80192434 *)get_bml_model((BmlResource *)lazer_fence_norm_bml_resource, 2);
        this->m_c4 = (saddr)get_bml_motion(lazer_fence_norm_bml_resource, 1);
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

__declspec(section ".data") const char *bm_fe_obj_komo_model_names[2] = { (char *)"fe_obj_komo.gj", NULL };
BmlResourceDescriptor TKomorebi__resource_descriptor = { (char *)"bm_fe_obj_komo.bml", bm_fe_obj_komo_model_names, bm_fe_obj_komo_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_fe_obj_komo_motion_names[1] = { NULL };


const char *komorebi_class_name = "TKomorebi";
uaddr TKomorebi__resource_bundle;
s32 komorebi_last_uv_update_frame;
