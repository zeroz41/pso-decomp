#include "pso/misc/TODoorCave03.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

const char *fs_obj_do_doa03_model_names[] = {"fs_obj_do_doa03.gj", NULL};
const char *fs_obj_do_doa03_motion_names[] = {"fs_obj_do_doa03.njm", NULL};
BmlResourceDescriptor door_cave03_resource_descriptor = {
    "bm_fs_obj_do_doa03.bml", fs_obj_do_doa03_model_names, fs_obj_do_doa03_motion_names, 1, 1,
};
// The version-2 model set.
const char *fs_obj_do_doa03_a_model_names[] = {"fs_obj_do_doa03.gj", NULL};
const char *fs_obj_do_doa03_a_motion_names[] = {"fs_obj_do_doa03.njm", NULL};
BmlResourceDescriptor door_cave03_a_resource_descriptor = {
    "bm_fs_obj_do_doa03_a.bml", fs_obj_do_doa03_a_model_names, fs_obj_do_doa03_a_motion_names, 1, 1,
};

const char *door_cave03_class_name = "TODoorCave03";

static CollisionBody door_cave03_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorCave03::bml_resource;

void TODoorCave03::update_demo() {}

void TODoorCave03::update_closing() {
    f32 y = position.y;
    f32 closed_y = home_position.y;
    if (y - closed_y <= 0.0f) {
        position.y = closed_y;
        object_state = DOOR_CLOSED;
    } else {
        position.y = y - 1.0f;
    }
    play_persistent_sound(0x42807, (s32)this, (u32)&position, 0, 0);
}

void TODoorCave03::update_open() {
    if (door_flags & 1) {
        if (is_any_player_within_radius_xz(10000.0f) != 1) {
            object_state = DOOR_CLOSING;
            clear_player_status_flag(0, 8);
        }
    } else {
        object_state = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
    }
}

void TODoorCave03::update_opening() {
    if (60.0f <= position.y - home_position.y) {
        position.y = 60.0f + home_position.y;
        object_state = DOOR_OPEN;
    } else {
        position.y += 1.0f;
    }
    play_persistent_sound(0x42807, (s32)this, (u32)&position, 0, 0);
}

void TODoorCave03::update_closed() {
    if (door_flags & 1) {
        if (is_any_player_within_radius_xz(4900.0f) == 1) {
            object_state = DOOR_OPENING;
            set_indexed_flags(0, 8);
        }
    } else if (door_flags & PULSE_RISING) {
        light_color.r += 0.1f;
        if (1.0f <= light_color.r) {
            door_flags &= ~PULSE_RISING;
        }
    } else {
        light_color.r = light_color.r - 0.1f;
        if (light_color.r <= 0.0f) {
            door_flags |= PULSE_RISING;
        }
    }
}

void TODoorCave03::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        TParticleCtrl::begin_effect_render();
        saved_model_render_flags = model_render_flags;
        model_render_flags |= 0x10;
        set_constant_material(&light_color);
        if (door_flags & 1) {
            node = ((NJS_OBJECT *)model)->child->sibling;
        } else {
            node = ((NJS_OBJECT *)model)->child;
        }
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->child;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TODoorCave03::create(void *set_data) {
    return new TODoorCave03(tl_05, set_data);
}

void TODoorCave03::destroy() {
    if (bml_resource != NULL) {
        TLobby__sub_8001FE7C(bml_resource, 1);
        bml_resource = NULL;
    }
}

void TODoorCave03::load_resources() {
    BmlResource *resource;
    if (enable_v2_features == 1 && TLobby::is_online_ready() != 0) {
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &door_cave03_a_resource_descriptor, 0, 0, 0);
        }
        bml_resource = resource;
        return;
    }
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &door_cave03_resource_descriptor, 0, 0, 0);
    }
    bml_resource = resource;
}

TODoorCave03::~TODoorCave03() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorCave03::TODoorCave03(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_cave03_class_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = bml_resource->models[0].m_c;
    init_collision_body_parts(this, door_cave03_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    light_color.a = 1.0f;
    light_color.r = 1.0f;
    light_color.g = 1.0f;
    light_color.b = 1.0f;
}
