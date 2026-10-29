#include "pso/misc/TODoorAncient05.h"
#include "pso/misc/TODoorAncient07.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

const char *TODoorAncient05_name = "TODoorAncient05";

static CollisionBody door_ancient05_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorAncient05::bml_resource;
s32 *TODoorAncient05::texture_lists;
NJS_OBJECT *TODoorAncient05::model_nodes;

void TODoorAncient05::render() {
    if (update_object_view_visibility(400.0f, 20.0f) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
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

void TODoorAncient05::update_open() {
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

void TODoorAncient05::update_closed() {
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

void *TODoorAncient05::create(void *set_data) {
    return new TODoorAncient05(tl_05, set_data);
}

void TODoorAncient05::free_resources() {
    if (model_nodes != NULL) {
        mem_free(model_nodes);
        model_nodes = NULL;
    }
    if (texture_lists != NULL) {
        TObjPlayer::free_if_valid(texture_lists[1]);
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

void TODoorAncient05::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &door_ancient_567_resource_descriptor, 0, 0, 0);
    }
    bml_resource = resource;
    texture_lists = (s32 *)mem_alloc(8);
    texture_lists[0] = bml_resource->models[0].m_c;
    texture_lists[1] = (s32)load_gvm_texture_file((s32)"fs_obj_door07_m_01_g.gvm");
    model_nodes = (NJS_OBJECT *)mem_alloc(3 * sizeof(NJS_OBJECT));
    if (bml_resource != NULL && model_nodes != NULL) {
        copy_model_node((u8 *)&model_nodes[0], (u8 *)bml_resource->models[0].model);
        model_nodes[0].child = NULL;
        model_nodes[0].evalflags |= NJD_EVAL_BREAK;
        copy_model_node((u8 *)&model_nodes[1], (u8 *)((NJS_OBJECT *)bml_resource->models[0].model)->child);
        model_nodes[1].sibling = NULL;
        copy_model_node((u8 *)&model_nodes[2], (u8 *)((NJS_OBJECT *)bml_resource->models[0].model)->child->sibling);
    }
}

TODoorAncient05::~TODoorAncient05() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorAncient05::TODoorAncient05(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = TODoorAncient05_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = texture_lists[0];
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = animation_end_frame / 30.0f;
    init_collision_body_parts(this, door_ancient05_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
}
