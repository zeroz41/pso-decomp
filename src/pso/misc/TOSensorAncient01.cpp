#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOSensorAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_o_sensor01_model_names[] = {"fs_obj_o_sensor01.gj", NULL};
const char *bm_fs_obj_o_sensor01_motion_names[] = {"fe_obj_o_sensor01.njm", NULL};
BmlResourceDescriptor TOSensorAncient01__resource_descriptor = {
    "bm_fs_obj_o_sensor01.bml", bm_fs_obj_o_sensor01_model_names, bm_fs_obj_o_sensor01_motion_names, 1, 1,
};
const char *TOSensorAncient01__class_name = "TOSensorAncient01";
BmlResource *sensor_ancient01_model_resource;
TOSensorAncient01Textures *ancient_sensor_resource_pair_table;
// Cleared by load_resources, read nowhere.
s32 lbl_805D5A90;
s32 lbl_805D5A94;
s32 lbl_805D5A98;
s32 sensor_texture_table_index;

void TOSensorAncient01::vfunc_25() {}

void TOSensorAncient01::update_pulse_value() {
    if (pulse_flags & 1) {
        pulse_offset += 0.26666668f;
        if (4.0f < pulse_offset) {
            pulse_offset = 4.0f;
            pulse_flags = pulse_flags & ~1;
        }
    } else {
        pulse_offset = pulse_offset - 0.26666668f;
        if (pulse_offset < 0.0f) {
            pulse_offset = 0.0f;
            pulse_flags = pulse_flags | 1;
        }
    }
}

void TOSensorAncient01::update_switch_off() {
    spin_angle = spin_angle + 0x28F;
    update_pulse_value();
}

void TOSensorAncient01::update_switch_on() {
    spin_angle += 1310.0f;
    update_pulse_value();
    if (lamp_timer > 0) {
        lamp_timer = lamp_timer - 1;
        return;
    }
    lamp_timer = 0;
    position.y += 1.0f;
}

void TOSensorAncient01::render() {
    NJS_OBJECT *object;

    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(ancient_sensor_resource_pair_table[set_params[2]].red);
        object = (NJS_OBJECT *)model;
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        object = object->child;
        if ((f32)lamp_timer < 30.0f) {
            TObjFish::set_global_param(ancient_sensor_resource_pair_table[sensor_texture_table_index].plain);
        }
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        push_matrix();
        object = object->sibling;
        if ((f32)lamp_timer < 60.0f) {
            TObjFish::set_global_param(ancient_sensor_resource_pair_table[sensor_texture_table_index].plain);
        }
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        push_matrix();
        object = object->sibling;
        if ((f32)lamp_timer < 90.0f) {
            TObjFish::set_global_param(ancient_sensor_resource_pair_table[sensor_texture_table_index].plain);
        }
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        push_matrix();
        object = object->sibling;
        post_translate_matrix(object->pos);
        rotate_matrix_y(NULL, spin_angle);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)object->model);
        TParticleCtrl::end_effect_render();
        push_matrix();
        object = object->child;
        translate_matrix(0, object->pos[0] + pulse_offset, object->pos[1], object->pos[2]);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        push_matrix();
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2] - pulse_offset);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        push_matrix();
        object = object->sibling;
        translate_matrix(0, object->pos[0] - pulse_offset, object->pos[1], object->pos[2]);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        push_matrix();
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2] + pulse_offset);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        pop_matrix();
        pop_matrix();
    }
}

void *TOSensorAncient01::create(void *set_data) {
    return new TOSensorAncient01(tl_05, set_data);
}

void TOSensorAncient01::destroy() {
    if (ancient_sensor_resource_pair_table != NULL) {
        TObjPlayer::free_if_valid(ancient_sensor_resource_pair_table[0].red);
        TObjPlayer::free_if_valid(ancient_sensor_resource_pair_table[1].plain);
        TObjPlayer::free_if_valid(ancient_sensor_resource_pair_table[1].red);
        if (ancient_sensor_resource_pair_table != NULL) {
            mem_free(ancient_sensor_resource_pair_table);
            ancient_sensor_resource_pair_table = NULL;
        }
    }
    if (sensor_ancient01_model_resource != NULL) {
        TLobby__sub_8001FE7C(sensor_ancient01_model_resource, 1);
        sensor_ancient01_model_resource = NULL;
    }
}

void TOSensorAncient01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &TOSensorAncient01__resource_descriptor, 0, 0, 0);
    }
    sensor_ancient01_model_resource = resource;
    ancient_sensor_resource_pair_table = (TOSensorAncient01Textures *)mem_alloc(0x10);
    ancient_sensor_resource_pair_table[0].plain = sensor_ancient01_model_resource->models[0].m_c;
    ancient_sensor_resource_pair_table[0].red = (s32)load_gvm_texture_file((s32) "fs_obj_o_sensor01r.gvm");
    ancient_sensor_resource_pair_table[1].plain = (s32)load_gvm_texture_file((s32) "fs_obj_o_sensor02.gvm");
    ancient_sensor_resource_pair_table[1].red = (s32)load_gvm_texture_file((s32) "fs_obj_o_sensor02r.gvm");
    lbl_805D5A90 = 0;
    lbl_805D5A94 = 0;
    lbl_805D5A98 = 0;
    sensor_texture_table_index = 0;
}

TOSensorAncient01::~TOSensorAncient01() {}

TOSensorAncient01::TOSensorAncient01(TObject *parent, void *set_data) : TOSensor(parent) {
    m_name = TOSensorAncient01__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    if (set_params[2] < 0) {
        set_params[2] = 0;
    } else if (set_params[2] >= 2) {
        set_params[2] = 1;
    }
    model = (void *)sensor_ancient01_model_resource->models[0].model;
    motion = sensor_ancient01_model_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    animation_step = 1.0f;
    view_range = 400.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    activate_range = 50.0f + scale.x;
    if (activate_range < 0.0f) {
        activate_range = 0.0f;
    }
    if (set_params[1] < 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    lamp_timer = 120;
    spin_angle = 0;
    pulse_offset = 0.0f;
    pulse_flags = 0;
}
