#include "pso/misc/TODoorVS2Door01.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

const char *fs_obj_o_vs2door01l_model_names[] = {"fs_obj_o_vs2door01l.gj", NULL};
const char *fs_obj_o_vs2door01l_motion_names[] = {NULL};
BmlResourceDescriptor door_vs2door01_resource_descriptor = {
    "fs_obj_o_vs2door01l.bml", fs_obj_o_vs2door01l_model_names, fs_obj_o_vs2door01l_motion_names, 1, 0,
};

const char *door_vs2door01_class_name = "TODoorVS2Door01";

static CollisionBody door_vs2door01_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorVS2Door01::bml_resource;
s32 *TODoorVS2Door01::texture_lists;

void TODoorVS2Door01::update_demo() {}

void TODoorVS2Door01::update_closing() {
    slide_offset -= animation_step;
    if (slide_offset <= 0.0f) {
        slide_offset = 0.0f;
        object_state = DOOR_CLOSED;
    }
}

void TODoorVS2Door01::update_open() {
    if (!(door_flags & 1) || is_any_player_within_radius_xz(10000.0f) == 0) {
        object_state = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
        play_sound_effect(0x4004AA0B, &position, 0, 0);
    }
}

void TODoorVS2Door01::update_opening() {
    slide_offset += animation_step;
    if (SLIDE_DISTANCE <= slide_offset) {
        slide_offset = SLIDE_DISTANCE;
        object_state = DOOR_OPEN;
    }
}

void TODoorVS2Door01::update_closed() {
    if ((door_flags & 1) && is_any_player_within_radius_xz(4900.0f) != 0) {
        object_state = DOOR_OPENING;
        set_indexed_flags(0, 8);
        play_sound_effect(0x4004AA0B, &position, 0, 0);
    }
}

s32 TODoorVS2Door01::is_in_view_depth(f32 min_radius) {
    return TObjMapObject::is_in_view_depth(min_radius) || object_state != DOOR_CLOSED;
}

void TODoorVS2Door01::render() {
    NJS_OBJECT *node;
    if (update_object_view_visibility(view_range, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texture_lists[door_flags & 1]);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, -slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        node = node->child;
        push_matrix();
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        node = node->child;
        push_matrix();
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        node = node->sibling;
        push_matrix();
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        node = ((NJS_OBJECT *)model)->child->sibling;
        push_matrix();
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, -slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        node = node->sibling;
        push_matrix();
        post_translate_matrix(node->pos);
        push_matrix();
        translate_matrix(NULL, -slide_offset, 0.0f, 0.0f);
        draw_ginja_model((s32)node->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TODoorVS2Door01::create(void *set_data) {
    return new TODoorVS2Door01(tl_05, set_data);
}

void TODoorVS2Door01::destroy() {
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

void TODoorVS2Door01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &door_vs2door01_resource_descriptor, 0, 0, 0);
    }
    bml_resource = resource;
    texture_lists = (s32 *)mem_alloc(8);
    texture_lists[1] = bml_resource->models[0].m_c;
    texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_o_vs2door01lr.gvm");
}

TODoorVS2Door01::~TODoorVS2Door01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorVS2Door01::TODoorVS2Door01(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_vs2door01_class_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = texture_lists[1];
    animation_end_frame = 30.0f;
    animation_step = SLIDE_DISTANCE / animation_end_frame;
    slide_offset = 0.0f;
    init_collision_body_parts(this, door_vs2door01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
}
