#include "types.h"
#include "pso/misc/TODragonfly.h"
#include "pso/misc/TODragonflyCave01.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/ScratchVectors.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/map/FloorArea.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/TMainTask.h"
#include <stdlib.h>

// The source is written from the last function back: the unit is built
// -inline off,deferred, which emits it in reverse.

const char *bm_fs_obj_tombo_model_names[2] = { "fs_obj_tombo.gj", NULL };
const char *bm_fs_obj_tombo_motion_names[2] = { "fs_obj_tombo.njm", NULL };
BmlResourceDescriptor bm_fs_obj_tombo_resource_descriptor = {
    "bm_fs_obj_tombo.bml", bm_fs_obj_tombo_model_names, bm_fs_obj_tombo_motion_names, 1, 1
};
const char *fs_obj_ex_entombo_model_names[2] = { "fs_obj_ex_entombo.gj", NULL };
const char *fs_obj_ex_entombo_motion_names[2] = { "fs_obj_ex_entombo.njm", NULL };
BmlResourceDescriptor fs_obj_ex_entombo_resource_descriptor = {
    "fs_obj_ex_entombo.bml", fs_obj_ex_entombo_model_names, fs_obj_ex_entombo_motion_names, 1, 1
};

const char *TODragonfly::class_name = "TODragonfly";
const char *TODragonflyCave01::class_name = "TODragonflyCave01";
BmlResource *TODragonflyCave01::model_resource;

TODragonfly::TODragonfly() : TObjMapObject(tl_05) {
    m_name = class_name;
    wait_timer = 0;
    wander_radius = 50.0f + scale.x;
    VecCopy(&destination, &position);
    step.z = 0.0f;
    step.y = 0.0f;
    step.x = 0.0f;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
}

TODragonfly::~TODragonfly() {}

void TODragonfly::run_task() {
    bob_angle = bob_angle + bob_angle_step;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
    if (TObjPlayer::check_demo_mode() == 1) {
        update_demo();
        return;
    }
    update_anim_phase();
    switch (m_ac) {
    case 0:
        update_idle();
        return;
    case 1:
        update_wander_flight();
        return;
    case 2:
        update_rest();
        return;
    case 3:
        update_flee_flight();
        return;
    }
}

void TODragonfly::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        translate_matrix(0, 0.0f, bob_offset, 0.0f);
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_model_with_motion(model, motion, m_b0);
        pop_matrix();
    }
}

void TODragonfly::update_idle() {
    s32 wait;
    if (is_any_player_within_radius_xz(900.0f) == 1) {
        if (pick_random_destination(30.0f + scale.y) == 1) {
            m_ac = 3;
            wait_timer = 0;
        }
    } else {
        wait = wait_timer;
        wait_timer = wait + 1;
        if (30.0f < (f32)wait && pick_random_destination(scale.y * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f)) == 1) {
            m_ac = 1;
            wait_timer = 0;
        }
    }
}

void TODragonfly::update_wander_flight() {
    f32 reach;
    f32 d;
    if (is_any_player_within_radius_xz(900.0f) == 1) {
        if (pick_random_destination(30.0f + scale.y) == 1) {
            m_ac = 3;
            wait_timer = 0;
        }
    } else {
        d = horizontal_distance_squared(&destination, &position);
        reach = 1e-05f + scale.z;
        if (d < reach * reach) {
            m_ac = 0;
            return;
        }
        vec3_add_to(&position, &step);
    }
}

void TODragonfly::update_rest() {
    s32 wait;
    wait = wait_timer;
    wait_timer = wait + 1;
    if (30.0f < (f32)wait) {
        if (is_any_player_within_radius_xz(1225.0f) == 1) {
            if (pick_random_destination(30.0f + scale.y) == 1) {
                m_ac = 3;
                wait_timer = 0;
            }
        } else if (pick_random_destination(scale.y * (2.0f * (3.0517578e-05f * (f32)rand()) - 1.0f)) == 1) {
            m_ac = 1;
            wait_timer = 0;
        }
    }
}

void TODragonfly::update_flee_flight() {
    f32 d = horizontal_distance_squared(&destination, &position);
    if (d < (1e-05f + scale.z) * (1e-05f + scale.z)) {
        m_ac = 2;
    } else {
        vec3_add_to(&position, &step);
    }
}

s32 TODragonfly::pick_random_destination(f32 height) {
    scratch_vec.x = 0.0f;
    scratch_vec.y = height;
    scratch_vec.z = wander_radius * (3.0517578e-05f * (f32)rand());
    scratch_rotation.y = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(NULL, scratch_rotation.y);
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&scratch_vec, &home_position);
    VecCopy(&destination, &scratch_vec);
    subtract_vector(&scratch_vec, &position);
    if (normalize_if_nonzero(&scratch_vec) == 1) {
        m_ac = 1;
        wait_timer = 0;
        rotation_y = (32768.0 / 3.141592f) * atan2_float(scratch_vec.x, scratch_vec.z);
        step.x = scratch_vec.x * scale.z;
        step.y = scratch_vec.y * scale.z;
        step.z = scratch_vec.z * scale.z;
        return 1;
    }
    return 0;
}

void TODragonfly::update_demo() {}

TODragonflyCave01::TODragonflyCave01(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models->model;
    texlist = model_resource->models->m_c;
    motion = model_resource->motions->motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 1.1f;
    m_c0 = 500.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    m_ac = 0;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
}

TODragonflyCave01::~TODragonflyCave01() {}

void TODragonflyCave01::load_resources() {
    BmlResource *resource;

    switch (get_current_floor_area()) {
    default:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_tombo_resource_descriptor, 0, 0, 0);
        }
        model_resource = resource;
        break;
    case AREA_BATTLE1:
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &fs_obj_ex_entombo_resource_descriptor, 0, 0, 0);
        }
        model_resource = resource;
        break;
    }
}

void TODragonflyCave01::release_static_instance() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TODragonflyCave01::create(void *set_data) {
    return new TODragonflyCave01(set_data);
}
