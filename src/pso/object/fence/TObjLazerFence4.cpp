#include "pso/system/BmlAccessors.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "types.h"
#include "pso/object/fence/TObjLazerFence4.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/door/TObjDoorJung.h"

#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/key/TOKey.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/BmlResource.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/base/ActorCollision.h"


#pragma readonly_strings on

const u16 lazer_fence4_color_slots[] = {0, 1, 2, 3};

CollisionBody laser_fence4_collision_body_sets[2][5] = {
    {
        {{0.0f, 0.0f, 0.0f}, 24.0f, 24.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{20.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{20.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-20.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-20.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
    {
        {{0.0f, 0.0f, 0.0f}, 33.0f, 33.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{30.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{30.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-30.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{-30.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
};

const char *lazer_fence4_class_name = "TObjLazerFence4";


extern "C" {

s32 TObjLazerFence4::update_object_view_visibility(f32 far_depth, f32 radius) {
    if (TMainTask::get_render_pass() == 1) {
        return this->visibility;
    }
    if (xz_distance_squared(&this->position, &camera_ctrl_instance->pos) < (radius * radius)) {
        this->visibility = 1;
        return this->visibility;
    }
    return TObjBase::update_object_view_visibility(far_depth, radius);
}

void TObjLazerFence4::init_models() {
    NJS_OBJECT *node;
    s32 i;
    s32 j;
    if (set_params[2] % 2 == 0) {
        beam_model = get_bml_model(lazer_fence_norm_bml_resource, 4);
        post_model = get_bml_model(lazer_fence_norm_bml_resource, 5);
        motion = get_bml_motion(lazer_fence_norm_bml_resource, 2);
    } else {
        beam_model = get_bml_model(lazer_fence_norm_bml_resource, 6);
        post_model = get_bml_model(lazer_fence_norm_bml_resource, 7);
        motion = get_bml_motion(lazer_fence_norm_bml_resource, 3);
    }
    for (j = 0; j < 12; j++) {
        beam_nodes[j] = 0;
    }
    i = 0;
    node = beam_model->child;
    if (node != 0) {
        while (node != 0 && i < 12) {
            beam_nodes[i++] = node->model;
            node = node->sibling;
        }
    }
}

void TObjLazerFence4::draw() {
    set_texture_list(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_object(this->post_model);
    pop_matrix();
}

void TObjLazerFence4::draw_model() {
  s32 i;
  i = 0;
  do
  {
    set_ginja_model_texture_slot(reinterpret_cast<void *>(beam_nodes[i]), color_slot);
    i += 1;
  }
  while (i < 0xC);
  set_texture_list(lazer_fence_norm_texture_list);
  push_matrix();
  post_translate_matrix(&this->position.x);
  rotate_matrix_y(0, this->rotation_y);
  draw_ginja_object(this->post_model);
  TParticleCtrl::begin_effect_render();
  draw_ginja_model_with_motion(this->beam_model, motion, animation_frame);
  TParticleCtrl::end_effect_render();
  pop_matrix();
}

void TObjLazerFence4::reset_if_door_closed() {
    if (is_current_floor_switch_set(this->id) == 0) {
        set_indexed_flags(0, 1);
        this->state = 0;
    }
}

void TObjLazerFence4::wait_for_switch() {
    animation_frame += 0.9f;
    if (animation_frame > (f32)(u32)(motion->nbFrame - 1)) {
        animation_frame = 0.0f;
    }
    if (is_current_floor_switch_set(id) == 1) {
        clear_player_status_flag(0, 1);
        state = 1;
    }
}

void TObjLazerFence4::render() {

    if (this->update_object_view_visibility(3e+02f, 6e+01f) != 0) {
        switch (this->state) {
        case 0:
            draw_model();
            return;
        case 1:
            draw();
            break;
        }
    }
}


void TObjLazerFence4::run_task() {

    switch (this->state) {
    case 0:
        wait_for_switch();
        return;
    case 1:
        reset_if_door_closed();
        return;
    }
}

}





void *TObjLazerFence4::create(void *set_data) {
    return new TObjLazerFence4((TObject *)tl_05, set_data);
}
TObjLazerFence4::~TObjLazerFence4() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TObjLazerFence4::TObjLazerFence4(TObject *parent, void *set_data) : TObjCollidable(parent) {
    s32 i;
    m_name = lazer_fence4_class_name;
    apply_object_set_data(set_data);
    state = 0;
    animation_frame = 0.0f;
    id = set_params[0];
    i = scale.x;
    if (i < 0) {
        i = 0;
    }
    if (i > 3) {
        i = 3;
    }
    color_slot = lazer_fence4_color_slots[i];
    init_models();
    init_collision_body_parts(this, laser_fence4_collision_body_sets[set_params[2] % 2], 5);
    actorFlags |= 0x40000000;
    register_object_by_id();
    refresh_collision_body_centers();
}
