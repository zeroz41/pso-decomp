#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TOBind.h"
#include "pso/object/TOBind_801586B8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on

__declspec(section ".data") const char *bm_o_bind_model_names[3] = { "fe_obj_bind_moto.gj", "fs_obj_bind_laz_moto.gj", NULL };
__declspec(section ".data") const char *bm_o_bind_motion_names[2] = { "fs_obj_bind_laz_moto.njm", NULL };
BmlResourceDescriptor bm_o_bind_resource_descriptor = { "bm_o_bind.bml", bm_o_bind_model_names, bm_o_bind_motion_names, 2, 1 };
CollisionBody bind_collision_body_parts[2] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, -10.0f}, 5.0f, 10.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

extern "C" {
BmlResource *TOBind__static_model_resource;
s32 __ct__14TObjCollidableFP7TObject(void *, int);
extern s32 __vt__6TOBind[];
const char *lbl_805D2EA8 = "TOBind";
extern s32 tl_05;

void TOBind::render() {
    if (this->update_object_view_visibility(draw_distance, this->m_d4) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        draw_ginja_object(this->model);
        if ((s32) this->m_b0 != 1) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(animated_textures));
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion(animated_model, motion, motion_frame);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void *TOBind::create(void *set_data) {
    void *o = TObject::operator new(0xD8);
    if (o != NULL) {
        o = TOBind__ct((TOBind *)((u8 *)o), (saddr)set_data);
    }
    return o;
}

void TOBind::free_static_model() {
    if (TOBind__static_model_resource != NULL) {
        delete (BmlResource *)TOBind__static_model_resource;
        TOBind__static_model_resource = NULL;
    }
}

void TOBind::load_static_resource() {
    BmlResource *storage = new BmlResource(1, (BmlResourceDescriptor *)&bm_o_bind_resource_descriptor, 0, 0, NULL);
    TOBind__static_model_resource = storage;
}

}
TOBind::~TOBind() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

u8 *TOBind__ct(TOBind *bind, saddr set_data) {
    __ct__14TObjCollidableFP7TObject(bind, tl_05);
    *(s32 **)((s8 *)bind + 0x18) = __vt__6TOBind;
    ((TOBind *)bind)->m_name = lbl_805D2EA8;
    ((TOBind *)(bind))->apply_object_set_data((void *)set_data);
    bind->m_b0 = 0;
    bind->model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TOBind__static_model_resource, 0));
    bind->texlist = get_bml_texlist((BmlResource *)TOBind__static_model_resource, 0);
    bind->animated_model = reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TOBind__static_model_resource, 1));
    bind->animated_textures = reinterpret_cast<NJS_TEXLIST *>(get_bml_texlist((BmlResource *)TOBind__static_model_resource, 1));
    bind->motion = get_bml_motion(TOBind__static_model_resource, 0);
    bind->motion_frame = 0.0f;
    bind->m_bc = static_cast<f32>(bind->motion->frameCount) - 1.0f;
    bind->motion_step = 1.0f;
    init_collision_body_parts(bind, bind_collision_body_parts, 2);
    ((TObjCollidable *)bind)->refresh_collision_body_centers();
    ((TObjPlayer *)bind)->register_object_by_id();
    bind->actorFlags = (s32) (bind->actorFlags | 0x40000000);
    bind->index = (s32) bind->set_params[0];
    if ((s32) bind->index < 0) {
        bind->index = 0;
    }
    bind->draw_distance = 400.0f;
    bind->m_d4 = 40.0f;
    return (u8 *)bind;
}

