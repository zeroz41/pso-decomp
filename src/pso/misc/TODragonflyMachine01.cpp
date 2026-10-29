#include "types.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/misc/TODragonflyMachine01.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/TODummyKeyCave01Sound.h"
#include "pso/map/FloorArea.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include <stdlib.h>

// The motion setup TObjEneMe3Stelth::spawn_attack registers the model with.
struct DragonflyMotionSetup {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    s16 initial_action;
    s16 alternate_action;
    s16 unknown_c;
    s16 unknown_e;
};

const char *bm_fs_obj_mekatombo_model_names[2] = { "fs_obj_mekatombo.gj", NULL };
const char *bm_fs_obj_mekatombo_motion_names[2] = { "fs_obj_mekatombo.njm", NULL };
BmlResourceDescriptor bm_fs_obj_mekatombo_resource_descriptor = {
    "bm_fs_obj_mekatombo.bml", bm_fs_obj_mekatombo_model_names, bm_fs_obj_mekatombo_motion_names, 1, 1
};
TObjMotionAction dragonfly_machine_motion_actions[1] = { { 1, 0, 0, 1.0f, 0 } };

const char *TODragonflyMachine01::class_name = "TODragonflyMachine01";
const DragonflyMotionSetup dragonfly_machine_attack_effect_params = {
    NULL, dragonfly_machine_motion_actions, 0, 0, 1, 0
};
BmlResource *TODragonflyMachine01::model_resource;
s32 TODragonflyMachine01::node_index;
s32 TODragonflyMachine01::node_yaw;

void TODragonflyMachine01::update_yaw_animation() {
    s32 full_turn;
    f32 choice;
    switch (yaw_animation_state) {
    case 0:
        choice = 3.0517578e-05f * (f32)rand();
        if (choice <= 0.125f) yaw_animation_state = 1;
        else if (choice <= 0.25f) yaw_animation_state = 2;
        else if (choice <= 0.375f) yaw_animation_state = 3;
        else if (choice <= 0.5f) yaw_animation_state = 4;
        else yaw_animation_state = 5;
        break;
    case 1:
        animation_yaw += 0x97B;
        if (animation_yaw >= 0x238E) {
            animation_yaw = 0x238E;
            if (++yaw_animation_cycles < 4) yaw_animation_state = 2;
            else yaw_animation_state = 5;
        }
        break;
    case 2:
        animation_yaw -= 0x97B;
        if (animation_yaw <= -0x238E) {
            animation_yaw = -0x238E;
            if (++yaw_animation_cycles < 4) yaw_animation_state = 1;
            else yaw_animation_state = 5;
        }
        break;
    case 3:
        animation_yaw += 0x97B;
        full_turn = 0xFFFF;
        if (full_turn <= animation_yaw) {
            animation_yaw = full_turn;
            if (++yaw_animation_cycles < 1) yaw_animation_state = 4;
            else yaw_animation_state = 5;
        }
        break;
    case 4:
        animation_yaw -= 0x97B;
        if (animation_yaw <= -0xFFFF) {
            animation_yaw = -0xFFFF;
            if (++yaw_animation_cycles < 1) yaw_animation_state = 3;
            else yaw_animation_state = 5;
        }
        break;
    case 5:
        yaw_animation_state = 0;
        animation_yaw = 0;
        yaw_animation_cycles = 0;
        break;
    }
}

void TODragonflyMachine01::rotate_animated_node() {
    if (node_index == 6) {
        rotate_matrix_y(NULL, node_yaw);
    }
    node_index += 1;
}

void TODragonflyMachine01::render() {
    if (update_object_view_visibility(view_range, model_radius)) {
        push_matrix();
        translate_matrix(0, 0.0f, bob_offset, 0.0f);
        post_translate_matrix(&position.x);
        switch (yaw_animation_state) {
        case 3:
        case 4:
            rotate_matrix_y(NULL, rotation_y - animation_yaw);
            break;
        default:
            rotate_matrix_y(NULL, rotation_y);
            break;
        }
        TObjFish::set_global_param(texlist);
        node_index = 0;
        node_yaw = animation_yaw;
        set_chunk_model_node_callback((s32)&rotate_animated_node);
        draw_ginja_model_with_motion(model, motion, animation_frame);
        set_chunk_model_node_callback(0);
        pop_matrix();
    }
}

void TODragonflyMachine01::run_task() {
    bob_angle = (s32) (bob_angle + bob_angle_step);
    bob_offset = (f32) (bob_height * sin_table_lookup(bob_angle));
    if (TObjPlayer::check_demo_mode() == 1) {
        update_demo();
        return;
    }
    update_anim_phase();
    switch (object_state) {
    case 0:
        update_yaw_animation();
        update_idle();
        return;
    case 1:
        update_wander_flight();
        return;
    case 2:
        update_yaw_animation();
        update_rest();
        return;
    case 3:
        update_flee_flight();
        return;
    }
}

void *TODragonflyMachine01::create(void *set_data) {
    return new TODragonflyMachine01(set_data);
}

void TODragonflyMachine01::unload_static_data() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TODragonflyMachine01::load_resources() {
    BmlResource *resource;
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_mekatombo_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
    node_index = 0;
    node_yaw = 0;
    DragonflyMotionSetup setup = dragonfly_machine_attack_effect_params;
    setup.motions = resource->motions;
    TObjEneMe3Stelth::spawn_attack(0x38, resource->models->model, resource->models->m_c, (s32)&setup, 3.0f, 15.0f);
}

TODragonflyMachine01::~TODragonflyMachine01() {}

TODragonflyMachine01::TODragonflyMachine01(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (NJS_OBJECT *)model_resource->models->model;
    texlist = model_resource->models->m_c;
    motion = model_resource->motions->motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 1.0f;
    view_range = 500.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    object_state = 0;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
    yaw_animation_state = 0;
    yaw_animation_cycles = 0;
    animation_yaw = 0;
}

void TODummyKeyCave01Sound::play_cave01_key_sound() {
    s32 area;
    s32 area_again;

    switch (sound_kind) {
    case 1:
        play_sound_effect(0x4005281F, 0, 0, 0);
        return;
    case 2:
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    case 3:
        area = get_current_floor_area();
        if ((area != AREA_BATTLE1) && (area != AREA_BATTLE2)) {
            play_sound_effect(0x52812, 0, 0, 0);
            return;
        }
        break;
    case 4:
        area_again = get_current_floor_area();
        if ((area_again != AREA_BATTLE1) && (area_again != AREA_BATTLE2)) {
            play_sound_effect(0x52813, 0, 0, 0);
            return;
        }
        break;
    case 5:
        play_sound_effect(0x4001C112, 0, 0, 0);
        return;
    case 6:
        play_sound_effect(0x4002A60B, 0, 0, 0);
        break;
    }
}
