#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "types.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/fence/TObjLazerFenceExtra.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/fence/TObjLazerFenceNorm.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"

struct AnimationMotion;

extern "C" {
__declspec(section ".data") const char *fe_obj_lazer2_4m_model_names[9] = {
    "fe_obj_lazer2_4m.gj", "fe_obj_lazer2_4m_moto.gj", "fe_obj_lazer2_6m.gj", "fe_obj_lazer2_6m_moto.gj",
    "fe_obj_lazer4_4m.gj", "fe_obj_lazer4_4m_moto.gj", "fe_obj_lazer4_6m.gj", "fe_obj_lazer4_6m_moto.gj", NULL,
};
__declspec(section ".data") const char *fe_obj_lazer2_4m_motion_names[5] = {
    "fe_obj_lazer2_4m.njm", "fe_obj_lazer2_6m.njm", "fe_obj_lazer4_4m.njm", "fe_obj_lazer4_6m.njm", NULL,
};
BmlResourceDescriptor lazer_fence_norm_episode1_resource_descriptor = {
    "fe_obj_lazer2_4m.bml", fe_obj_lazer2_4m_model_names, fe_obj_lazer2_4m_motion_names, 8, 4,
};
__declspec(section ".data") const char *fe_obj_lazer2_2_model_names[9] = {
    "fe_obj_lazer2_4m.gj", "fe_obj_lazer2_4m_moto.gj", "fe_obj_lazer2_6m.gj", "fe_obj_lazer2_6m_moto.gj",
    "fe_obj_lazer4_4m.gj", "fe_obj_lazer4_4m_moto.gj", "fe_obj_lazer4_6m.gj", "fe_obj_lazer4_6m_moto.gj", NULL,
};
__declspec(section ".data") const char *fe_obj_lazer2_2_motion_names[5] = {
    "fe_obj_lazer2_4m.njm", "fe_obj_lazer2_6m.njm", "fe_obj_lazer4_4m.njm", "fe_obj_lazer4_6m.njm", NULL,
};
}
BmlResourceDescriptor lazer_fence_norm_episode2_resource_descriptor = {
    "fe_obj_lazer2_2.bml", fe_obj_lazer2_2_model_names, fe_obj_lazer2_2_motion_names, 8, 4,
};

const u16 lazer_fence_texture_slots[] = {0, 1, 2, 3};

const char *obj_lazer_fence_norm_class_name = "TObjLazerFenceNorm";
const char *lazer_fence_extra_class_name = "TObjLazerFenceExtra";

// Two sets (set data's size flag), each a box across the fence and a post at each end.
CollisionBody laser_fence_collision_body_parts[2][3] = {
    {
        {{0.0f, 0.0f, 0.0f}, 28.0f, 4.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, 20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, -20.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
    {
        {{0.0f, 0.0f, 0.0f}, 35.0f, 4.0f, 1, 0x20010003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, 30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
        {{0.0f, 0.0f, -30.0f}, 3.0f, 3.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    },
};

NJS_TEXLIST *lazer_fence_norm_texture_list;
BmlResource *lazer_fence_norm_bml_resource;

extern "C" {


static const f32 lazer_fence_norm_zero[1] = {0.0f};







}

void load_lazer_fence_norm_resources(void) {
    BmlResource *obj;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        obj = new BmlResource(5, &lazer_fence_norm_episode2_resource_descriptor, 0, 0, NULL);
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = LoadPvmFileTls("fe_obj_lazer2_2.gvm");
        break;
    default:
        obj = new BmlResource(5, (BmlResourceDescriptor *)&lazer_fence_norm_episode1_resource_descriptor, 0, 0, NULL);
        lazer_fence_norm_bml_resource = obj;
        lazer_fence_norm_texture_list = LoadPvmFileTls("fe_obj_lazer2.gvm");
        break;
    }
}

void TObjLazerFenceNorm::free_resources() {
    if (lazer_fence_norm_bml_resource != NULL) {
        delete lazer_fence_norm_bml_resource;
        lazer_fence_norm_bml_resource = NULL;
    }
    if (lazer_fence_norm_texture_list != NULL) {
        release_texture_list(lazer_fence_norm_texture_list);
        safe_free(lazer_fence_norm_texture_list);
        lazer_fence_norm_texture_list = NULL;
    }
}


void *TObjLazerFenceNorm::create(void *set_data) {
    return new TObjLazerFenceNorm(tl_05, set_data);
}

TObjLazerFenceNorm::TObjLazerFenceNorm(TObject *parent, void *set_data) : TObjCollidable(parent) {
    m_name = obj_lazer_fence_norm_class_name;
    apply_object_set_data(set_data);
    state = 0;
    frame = lazer_fence_norm_zero[0];
    scale_level = (s32)scale.x;
    if ((s32)scale_level < 0) {
        scale_level = 0;
    }
    if ((s32)scale_level > 3) {
        scale_level = 3;
    }
    switch_id = (s16)set_params[0];
    select_models();
    init_collision_body_parts(this, laser_fence_collision_body_parts[set_params[2] % 2], 3);
    actorFlags |= 0x40000000;
    register_object_by_id();
    refresh_collision_body_centers();
}

TObjLazerFenceNorm::~TObjLazerFenceNorm() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjLazerFenceNorm::run_task() {

    switch (this->state) {
    case 0:
        update_closed();
        return;
    case 1:
        reset_by_door();
        return;
    }
}

void TObjLazerFenceNorm::reset_by_door() {
    if (is_current_floor_switch_set((u16) this->switch_id) == 0) {
        set_indexed_flags(0, 1);
        this->state = 0;
    }
}

void TObjLazerFenceNorm::update_closed() {
    this->frame += 0.9f;
    if ((f32)(beam_motion->frameCount - 1) < frame) {
        this->frame = lazer_fence_norm_zero[0];
    }
    if (is_current_floor_switch_set((u16)switch_id) == 1) {
        clear_player_status_flag(0, 1);
        state = 1;
    }
}

void TObjLazerFenceNorm::render() {

    if (update_object_view_visibility(300.0f, 40.0f) != 0) {
        switch (this->state) {
        case 0:
            draw_animated_beam();
            return;
        case 1:
            draw_model();
            break;
        }
    }
}

void TObjLazerFenceNorm::draw_model() {
    set_texture_list(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object(this->base_model);
    pop_matrix();
}

void TObjLazerFenceNorm::draw_animated_beam() {
    s32 i;
    for (i = 0; i < 4; i++) {
        set_ginja_model_texture_slot(reinterpret_cast<void *>(beam_part_models[i]), (lazer_fence_texture_slots[scale_level]));
    }
    set_texture_list(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    draw_ginja_object(base_model);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(beam_model, beam_motion, frame);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjLazerFenceNorm::select_models() {
    s32 i;
    NJS_OBJECT *node;
    s32 j;
    if (this->set_params[2] % 2 == 0) {
        this->base_model = (NJS_OBJECT *)get_bml_model(lazer_fence_norm_bml_resource, 1);
        beam_model = (NJS_OBJECT *)get_bml_model(lazer_fence_norm_bml_resource, 0);
        this->beam_motion = (AnimationMotion *)get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        this->base_model = (NJS_OBJECT *)get_bml_model(lazer_fence_norm_bml_resource, 3);
        beam_model = (NJS_OBJECT *)get_bml_model(lazer_fence_norm_bml_resource, 2);
        this->beam_motion = (AnimationMotion *)get_bml_motion(lazer_fence_norm_bml_resource, 1);
    }
    for (j = 0; j < 4; j++) {
        beam_part_models[j] = 0;
    }
    i = 0;
    node = beam_model->child;
    if (node != 0) {
        beam_part_models[i++] = node->model;
        node = node->sibling;
        while (node != 0 && i < 4) {
            beam_part_models[i++] = node->model;
            node = node->sibling;
        }
    }
}


void *TObjLazerFenceExtra::create(void *set_data) {
    return new TObjLazerFenceExtra(tl_05, set_data);
}

TObjLazerFenceExtra::TObjLazerFenceExtra(TObject *parent, void *set_data) : TObjCollidable(parent) {
    s32 i;
    m_name = lazer_fence_extra_class_name;
    apply_object_set_data(set_data);
    state = 0;
    frame = lazer_fence_norm_zero[0];
    scale_level = (s32)scale.x;
    if (scale_level < 0) {
        scale_level = 0;
    }
    if (scale_level > 3) {
        scale_level = 3;
    }
    switch_id = set_params[0];
    if (set_params[2] < 0 || set_params[2] > 1) {
        size_valid = 0;
        set_params[2] = 0;
    } else {
        size_valid = 1;
    }
    init_models();
    init_collision_body_parts(this, laser_fence_collision_body_parts[set_params[2] % 2], 3);
    actorFlags |= 0x40000000;
    bodies->half_width = scale.y;
    bodies->radius = scale.z;
    register_object_by_id();
    refresh_collision_body_centers();
    if (size_valid == 0) {
        for (i = 1; i < body_count; i++) {
            clear_player_status_flag(i, 1);
        }
    }
}

TObjLazerFenceExtra::~TObjLazerFenceExtra() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjLazerFenceExtra::run_task() {
    switch (state) {
    case 0:
        update_wait_switch();
        return;
    case 1:
        reset_by_door();
        return;
    }
}

void TObjLazerFenceExtra::reset_by_door() {
    if (is_current_floor_switch_set((u16)switch_id) == 0) {
        set_indexed_flags(0, 1);
        state = 0;
    }
}

void TObjLazerFenceExtra::update_wait_switch() {
    this->frame += 0.9f;
    if ((f32)(beam_motion->frameCount - 1) < frame) {
        this->frame = lazer_fence_norm_zero[0];
    }
    if (is_current_floor_switch_set((u16)switch_id) == 1) {
        clear_player_status_flag(0, 1);
        state = 1;
    }
}

void TObjLazerFenceExtra::render() {
    if (update_object_view_visibility(300.0f, 40.0f) != 0 && size_valid != 0) {
        switch (state) {
        case 0:
            draw_lazer_fence_extra_model();
            return;
        case 1:
            render_lazer_fence_model();
            break;
        }
    }
}

void TObjLazerFenceExtra::render_lazer_fence_model() {
    set_texture_list(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object(*(void * *)&this->base_model);
    pop_matrix();
}

void TObjLazerFenceExtra::draw_lazer_fence_extra_model() {
    s32 i;
    for (i = 0; i < 4; i++) {
        set_ginja_model_texture_slot(reinterpret_cast<void *>((beam_part_models[i])), lazer_fence_texture_slots[this->scale_level]);
    }
    set_texture_list(lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, this->rotation_y);
    draw_ginja_object(this->base_model);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(beam_model, this->beam_motion, this->frame);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}
