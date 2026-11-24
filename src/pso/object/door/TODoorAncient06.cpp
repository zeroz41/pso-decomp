#include "pso/system/memory.h"
#include "pso/object/door/TODoorAncient06.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/door/TODoorAncient07.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

const char *door_ancient06_class_name = "TODoorAncient06";

static CollisionBody door_ancient06_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorAncient06::bml_resource;
NJS_TEXLIST **TODoorAncient06::texture_lists;
NJS_OBJECT *TODoorAncient06::model_nodes;

void TODoorAncient06::render() {
    if (update_object_view_visibility(400.0f, 20.0f) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        if (motion != NULL && 0.0f != animation_frame) {
            draw_ginja_model_with_motion(model, motion, animation_frame);
        } else {
            draw_ginja_object(&model_nodes[0]);
            draw_ginja_object(&model_nodes[1]);
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(&model_nodes[2]);
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TODoorAncient06::update_open() {
    if (door_flags & 1) {
        texlist = texture_lists[1];
        if (is_any_player_within_radius_xz(10000.0f) != 1) {
            object_state = 3;
            clear_player_status_flag(0, 8);
            play_sound_effect(0x4004B708, &position, 0, 0);
        }
    } else {
        object_state = 3;
        texlist = texture_lists[0];
        clear_player_status_flag(0, 8);
        play_sound_effect(0x4004B708, &position, 0, 0);
    }
}

void TODoorAncient06::update_closed() {
    if (door_flags & 1) {
        texlist = texture_lists[1];
        if (is_any_player_within_radius_xz(4900.0f) == 1) {
            object_state = 1;
            set_indexed_flags(0, 8);
            play_sound_effect(0x4004B708, &position, 0, 0);
        }
    } else {
        texlist = texture_lists[0];
    }
}

void *TODoorAncient06::create(void *set_data) {
    return new TODoorAncient06(tl_05, set_data);
}

void TODoorAncient06::destroy() {
    if (model_nodes != NULL) {
        mem_free(model_nodes);
        model_nodes = NULL;
    }
    if (texture_lists != NULL) {
        TObjPlayer::free_if_valid((saddr)texture_lists[1]);
        TObjPlayer::free_if_valid((saddr)texture_lists[0]);
        if (texture_lists != NULL) {
            mem_free(texture_lists);
            texture_lists = NULL;
        }
    }
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

void TODoorAncient06::load_resources() {
    BmlResource *resource = new BmlResource(1, (BmlResourceDescriptor *)&door_ancient_567_resource_descriptor, 0, 0, NULL);
    bml_resource = resource;
    texture_lists = (NJS_TEXLIST **)mem_alloc(2 * sizeof(NJS_TEXLIST *));
    texture_lists[0] = load_gvm_texture_file("fs_obj_door07_m_02_r.gvm");
    texture_lists[1] = load_gvm_texture_file("fs_obj_door07_m_02_g.gvm");
    model_nodes = (NJS_OBJECT *)mem_alloc(3 * sizeof(NJS_OBJECT));
    if (bml_resource != NULL && model_nodes != NULL) {
        copy_model_node(&model_nodes[0], bml_resource->models[0].model);
        model_nodes[0].child = NULL;
        model_nodes[0].evalflags |= NJD_EVAL_BREAK;
        copy_model_node(&model_nodes[1], bml_resource->models[0].model->child);
        model_nodes[1].sibling = NULL;
        copy_model_node(&model_nodes[2], bml_resource->models[0].model->child->sibling);
    }
}

TODoorAncient06::~TODoorAncient06() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorAncient06::TODoorAncient06(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_ancient06_class_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = texture_lists[0];
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = animation_end_frame / 30.0f;
    init_collision_body_parts(this, door_ancient06_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
}
