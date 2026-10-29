#include "pso/misc/TODoorMachine02.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TSwitch.h"
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

const char *fs_obj_ki_doa2_model_names[] = {"fs_obj_ki_doa.gj", NULL};
const char *fs_obj_ki_doa2_motion_names[] = {"fs_obj_ki_doa.njm", NULL};
BmlResourceDescriptor door_machine02_resource_descriptor = {
    "bm_fs_obj_ki_doa2.bml", fs_obj_ki_doa2_model_names, fs_obj_ki_doa2_motion_names, 1, 1,
};
// The version-2 model set.
const char *fs_obj_ki_doa2_a_model_names[] = {"fs_obj_ki_doa.gj", NULL};
const char *fs_obj_ki_doa2_a_motion_names[] = {"fs_obj_ki_doa.njm", NULL};
BmlResourceDescriptor door_machine02_a_resource_descriptor = {
    "bm_fs_obj_ki_doa2_a.bml", fs_obj_ki_doa2_a_model_names, fs_obj_ki_doa2_a_motion_names, 1, 1,
};

const char *door_machine02_class_name = "TODoorMachine02";

static CollisionBody door_machine02_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorMachine02::bml_resource;
s32 *TODoorMachine02::texture_lists;

void TODoorMachine02::update_demo() {}

void TODoorMachine02::update_open() {
    if (!(door_flags & 1) || is_any_player_within_radius_xz(10000.0f) != 1) {
        object_state = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
        play_sound_effect(0x4004BC01, &position, 0, 0);
    }
}

void TODoorMachine02::update_closed() {
    if ((door_flags & 1) && is_any_player_within_radius_xz(4900.0f) == 1) {
        object_state = DOOR_OPENING;
        set_indexed_flags(0, 8);
        play_sound_effect(0x4004BC01, &position, 0, 0);
    }
    if (door_flags & PULSE_RISING) {
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

void TODoorMachine02::render() {
    NJS_OBJECT *node;
    s32 unlocked;
    if (update_object_view_visibility(view_range, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        unlocked = door_flags & 1;
        TObjFish::set_global_param(texture_lists[door_flags & 1]);
        if (object_state == DOOR_CLOSED) {
            node = ((NJS_OBJECT *)model)->child;
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            if (unlocked != 1) {
                u32 flags = model_render_flags;
                saved_model_render_flags = flags;
                model_render_flags = flags | 0x10;
                set_constant_material(&light_color);
            }
            push_matrix();
            node = node->child;
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            pop_matrix();
            push_matrix();
            node = node->sibling;
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
            pop_matrix();
            if (unlocked != 1) {
                set_constant_material(&chunk_material_color_half_alpha_f32);
                model_render_flags = saved_model_render_flags;
            }
            node = ((NJS_OBJECT *)model)->child->sibling;
            post_translate_matrix(node->pos);
            draw_ginja_model((s32)node->model);
        } else {
            draw_ginja_model_with_motion(model, motion, animation_frame);
        }
        pop_matrix();
    }
}

void *TODoorMachine02::create(void *set_data) {
    return new TODoorMachine02(tl_05, set_data);
}

void TODoorMachine02::destroy() {
    if (texture_lists != NULL) {
        TObjPlayer::free_if_valid(texture_lists[0]);
        if (texture_lists != NULL) {
            mem_free(texture_lists);
            texture_lists = NULL;
        }
    }
    if (bml_resource != NULL) {
        TLobby__sub_8001FE7C(bml_resource, 1);
        bml_resource = NULL;
    }
}

void TODoorMachine02::load_resources() {
    BmlResource *resource;
    texture_lists = (s32 *)mem_alloc(8);
    if (enable_v2_features == 1 && TLobby::is_online_ready() != 0) {
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &door_machine02_a_resource_descriptor, 0, 0, 0);
        }
        bml_resource = resource;
        texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_ki_doa2_r_a.gvm");
    } else {
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &door_machine02_resource_descriptor, 0, 0, 0);
        }
        bml_resource = resource;
        texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_ki_doa2_r.gvm");
    }
    texture_lists[1] = bml_resource->models[0].m_c;
}

TODoorMachine02::~TODoorMachine02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorMachine02::TODoorMachine02(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_machine02_class_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = bml_resource->models[0].m_c;
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 0.5f;
    init_collision_body_parts(this, door_machine02_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    light_color.a = 1.0f;
    light_color.r = 1.0f;
    light_color.g = 1.0f;
    light_color.b = 1.0f;
}
