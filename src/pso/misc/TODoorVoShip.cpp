#include "pso/misc/TODoorVoShip.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"

const char *fe_obj_fuuin_model_names[] = {"fe_obj_fuuin_singo_moto.nj", "fe_obj_fuuin_doa.nj", NULL};
const char *fe_obj_fuuin_motion_names[] = {"fe_obj_fuuin_doa.njm", "fe_obj_fuuin_doa.njs", NULL};
BmlResourceDescriptor door_vo_ship_resource_descriptor = {
    "bm_o_door_vo_ship.bml", fe_obj_fuuin_model_names, fe_obj_fuuin_motion_names, 2, 2,
};

const char *door_vo_ship_class_name = "TODoorVoShip";

static CollisionBody door_vo_ship_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorVoShip::bml_resource;

void TODoorVoShip::run_task() {
    if (light_flags & SEAL_LIGHTS) {
        update_anim_phase();
        if (light_flags & FADE_RISING) {
            light_color.a += 0.05f;
            if (0.0f <= light_color.a) {
                light_color.a = 0.0f;
                light_flags &= ~FADE_RISING;
            }
        } else {
            light_color.a -= 0.05f;
            if (light_color.a <= -1.0f) {
                light_color.a = -1.0f;
                light_flags |= FADE_RISING;
            }
        }
        if (get_story_flag(0x2C) != 0) {
            light_flags &= ~SEAL_LIGHT_1;
        }
        if (get_story_flag(0x2D) != 0) {
            light_flags &= ~SEAL_LIGHT_2;
        }
        if (get_story_flag(0x2E) != 0) {
            light_flags &= ~SEAL_LIGHT_3;
        }
        if (get_story_flag(0x2F) != 0 || get_main_phase() == 0xF) {
            light_flags &= ~SEAL_LIGHTS;
            clear_player_status_flag(0, 1);
        }
    }
}

void TODoorVoShip::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0 && (light_flags & SEAL_LIGHTS)) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_chunk_model_with_shape_motion(model, motion, shape_motion, animation_frame);
        TObjFish::set_global_param(light_texlist);
        u32 flags = model_render_flags;
        saved_model_render_flags = flags;
        model_render_flags = flags | 0x20;
        set_constant_material(&light_color);
        TParticleCtrl::begin_effect_render();
        node = light_model;
        push_matrix();
        post_translate_matrix(node->pos);
        node = node->child;
        if (light_flags & SEAL_LIGHT_2) {
            push_matrix();
            post_translate_matrix(node->pos);
            draw_chunk_model(node->model);
            pop_matrix();
        }
        node = node->sibling;
        if (light_flags & SEAL_LIGHT_1) {
            push_matrix();
            post_translate_matrix(node->pos);
            draw_chunk_model(node->model);
            pop_matrix();
        }
        node = node->sibling;
        if (light_flags & SEAL_LIGHT_3) {
            push_matrix();
            post_translate_matrix(node->pos);
            draw_chunk_model(node->model);
            pop_matrix();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
    }
}

void *TODoorVoShip::create(void *set_data) {
    return new TODoorVoShip(tl_05, set_data);
}

void TODoorVoShip::free_static_data() {
    if (bml_resource != NULL) {
        TLobby__sub_8001FE7C(bml_resource, 1);
        bml_resource = NULL;
    }
}

void TODoorVoShip::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &door_vo_ship_resource_descriptor, 0, 0, 0);
    }
    bml_resource = resource;
}

TODoorVoShip::~TODoorVoShip() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorVoShip::TODoorVoShip(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = door_vo_ship_class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(bml_resource, 1);
    texlist = TObjFish__sub_8001EDB0(bml_resource, 1);
    motion = get_bml_motion(bml_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 1.0f;
    shape_motion = get_bml_motion(bml_resource, 1);
    light_model = (NJS_OBJECT *)get_bml_model(bml_resource, 0);
    light_texlist = TObjFish__sub_8001EDB0(bml_resource, 0);
    init_collision_body_parts(this, door_vo_ship_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    view_range = 400.0f;
    model_radius = 200.0f;
    light_flags = SEAL_LIGHTS;
    light_color.b = 0.0f;
    light_color.g = 0.0f;
    light_color.r = 0.0f;
    light_color.a = 0.0f;
    if (get_story_flag(0x2C) != 0) {
        light_flags &= ~SEAL_LIGHT_1;
    }
    if (get_story_flag(0x2D) != 0) {
        light_flags &= ~SEAL_LIGHT_2;
    }
    if (get_story_flag(0x2E) != 0) {
        light_flags &= ~SEAL_LIGHT_3;
    }
    if (get_story_flag(0x2F) != 0 || get_main_phase() == 0xF) {
        light_flags &= ~SEAL_LIGHTS;
        clear_player_status_flag(0, 1);
    }
}
