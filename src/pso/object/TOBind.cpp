#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TOBind.h"
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
#include "pso/object/base/ActorCollision.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/TQuestManager.h"
#include "pso/quest/TQuestThread.h"


#pragma readonly_strings on

__declspec(section ".data") const char *bm_o_bind_model_names[3] = { "fe_obj_bind_moto.gj", "fs_obj_bind_laz_moto.gj", NULL };
__declspec(section ".data") const char *bm_o_bind_motion_names[2] = { "fs_obj_bind_laz_moto.njm", NULL };
BmlResourceDescriptor bm_o_bind_resource_descriptor = { "bm_o_bind.bml", bm_o_bind_model_names, bm_o_bind_motion_names, 2, 1 };

void TOBind::sub_80158608() {  }


void TOBind::sub_8015860C() {
    f32 temp_f0;
    f32 bc;
    motion_frame += motion_step;
    bc = this->m_bc;
    temp_f0 = motion_frame;
    if (bc < temp_f0) {
        motion_frame = temp_f0 - bc;
    }
}

void TOBind::run_task() {
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80158608();
        return;
    }
    if ((s32) this->m_b0 != 1) {
        if (TQuestThread::get_register(quest_mission_manager, this->index) != 0) {
            this->m_b0 = 1;
            clear_player_status_flag(0, 1);
        }
        sub_8015860C();
    }
}
CollisionBody bind_collision_body_parts[2] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, -10.0f}, 5.0f, 10.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

BmlResource *TOBind::static_model_resource;
const char *TOBind::class_name = "TOBind";

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
    return new TOBind(set_data);
}

void TOBind::free_static_model() {
    if (static_model_resource != NULL) {
        delete static_model_resource;
        static_model_resource = NULL;
    }
}

void TOBind::load_static_resource() {
    BmlResource *storage = new BmlResource(1, &bm_o_bind_resource_descriptor, 0, 0, NULL);
    static_model_resource = storage;
}

TOBind::~TOBind() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

TOBind::TOBind(void *set_data) : TObjCollidable(tl_05) {
    m_name = class_name;
    apply_object_set_data(set_data);
    m_b0 = 0;
    model = get_bml_model(static_model_resource, 0);
    texlist = get_bml_texlist(static_model_resource, 0);
    animated_model = get_bml_model(static_model_resource, 1);
    animated_textures = get_bml_texlist(static_model_resource, 1);
    motion = get_bml_motion(static_model_resource, 0);
    motion_frame = 0.0f;
    m_bc = static_cast<f32>(motion->frameCount) - 1.0f;
    motion_step = 1.0f;
    init_collision_body_parts(this, bind_collision_body_parts, 2);
    refresh_collision_body_centers();
    register_object_by_id();
    actorFlags |= 0x40000000;
    index = set_params[0];
    if ((s32)index < 0) {
        index = 0;
    }
    draw_distance = 400.0f;
    m_d4 = 40.0f;
}
