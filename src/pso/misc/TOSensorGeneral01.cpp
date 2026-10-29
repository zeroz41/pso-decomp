#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOSensorGeneral01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_sensor_model_names[] = {"fs_obj_sensor.gj", NULL};
const char *bm_fs_obj_sensor_motion_names[] = {NULL};
BmlResourceDescriptor TOSensorGeneral01__resource_descriptor = {
    "bm_fs_obj_sensor.bml", bm_fs_obj_sensor_model_names, bm_fs_obj_sensor_motion_names, 1, 0,
};
const char *TOSensorGeneral01__class_name = "TOSensorGeneral01";
BmlResource *sensor_general_shared_bml_archive;
s32 *TOSensorGeneral01__texture_lists;

void TOSensorGeneral01::update_switch_off() {
    rotation_y = rotation_y + 0x147;
    head_angle = head_angle + 0x28F;
}

void TOSensorGeneral01::update_switch_on() {
    head_angle = head_angle + 0x28F;
    lamp_timer = lamp_timer - 1;
    if (lamp_timer < 0) {
        lamp_timer = 0;
        lamps_dark = 0;
        rotation_y = rotation_y + 0xCCC;
        position.y += 1.0f;
        return;
    }
    if ((f32)lamp_timer < 30.0f) {
        lamps_dark = 1;
        rotation_y = rotation_y + 0x147;
        return;
    }
    if ((f32)lamp_timer < 60.0f) {
        lamps_dark = 2;
        rotation_y = rotation_y + 0x147;
        return;
    }
    if ((f32)lamp_timer < 90.0f) {
        lamps_dark = 3;
        rotation_y = rotation_y + 0x147;
    }
}

void TOSensorGeneral01::render() {
    NJS_OBJECT *object;

    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        object = (NJS_OBJECT *)model;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        TObjFish::set_global_param(TOSensorGeneral01__texture_lists[0]);
        draw_ginja_model((s32)object->model);
        TParticleCtrl::begin_effect_render();
        object = object->child;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        TObjFish::set_global_param(TOSensorGeneral01__texture_lists[lamps_dark < 1]);
        draw_ginja_model((s32)object->model);
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        TObjFish::set_global_param(TOSensorGeneral01__texture_lists[lamps_dark < 2]);
        draw_ginja_model((s32)object->model);
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        TObjFish::set_global_param(TOSensorGeneral01__texture_lists[lamps_dark < 3]);
        draw_ginja_model((s32)object->model);
        TParticleCtrl::end_effect_render();
        object = object->sibling;
        push_matrix();
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        rotate_matrix_y(NULL, head_angle);
        TObjFish::set_global_param(TOSensorGeneral01__texture_lists[1]);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        pop_matrix();
    }
}

void *TOSensorGeneral01::create(void *set_data) {
    return new TOSensorGeneral01(tl_05, set_data);
}

void TOSensorGeneral01::free_assets() {
    if (TOSensorGeneral01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(TOSensorGeneral01__texture_lists[0]);
        if (TOSensorGeneral01__texture_lists != NULL) {
            mem_free(TOSensorGeneral01__texture_lists);
            TOSensorGeneral01__texture_lists = NULL;
        }
    }
    if (sensor_general_shared_bml_archive != NULL) {
        TLobby__sub_8001FE7C(sensor_general_shared_bml_archive, 1);
        sensor_general_shared_bml_archive = NULL;
    }
}

void TOSensorGeneral01::load_assets() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &TOSensorGeneral01__resource_descriptor, 0, 0, 0);
    }
    sensor_general_shared_bml_archive = resource;
    TOSensorGeneral01__texture_lists = (s32 *)mem_alloc(8);
    TOSensorGeneral01__texture_lists[1] = sensor_general_shared_bml_archive->models[0].m_c;
    TOSensorGeneral01__texture_lists[0] = (s32)load_gvm_texture_file((s32) "fs_obj_sensor_r.gvm");
}

TOSensorGeneral01::~TOSensorGeneral01() {}

TOSensorGeneral01::TOSensorGeneral01(TObject *parent, void *set_data) : TOSensor(parent) {
    m_name = TOSensorGeneral01__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    texlist = TOSensorGeneral01__texture_lists[0];
    model = (void *)sensor_general_shared_bml_archive->models[0].model;
    m_c0 = 400.0f;
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
    head_angle = 0;
    lamps_dark = 3;
    lamp_timer = 90;
}
