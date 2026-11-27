#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/switch/TOSensorGeneral01.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fs_obj_sensor_model_names[] = {"fs_obj_sensor.gj", NULL};
const char *bm_fs_obj_sensor_motion_names[] = {NULL};
BmlResourceDescriptor sensor_general01_resource_descriptor = {
    "bm_fs_obj_sensor.bml", bm_fs_obj_sensor_model_names, bm_fs_obj_sensor_motion_names, 1, 0,
};
const char *sensor_general01_class_name = "TOSensorGeneral01";
BmlResource *sensor_general_shared_bml_archive;
NJS_TEXLIST **sensor_general01_texture_lists;

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

    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        object = model;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sensor_general01_texture_lists[0]));
        draw_ginja_model(object->model);
        begin_effect_render();
        object = object->child;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sensor_general01_texture_lists[lamps_dark < 1]));
        draw_ginja_model(object->model);
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sensor_general01_texture_lists[lamps_dark < 2]));
        draw_ginja_model(object->model);
        object = object->sibling;
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sensor_general01_texture_lists[lamps_dark < 3]));
        draw_ginja_model(object->model);
        end_effect_render();
        object = object->sibling;
        push_matrix();
        translate_matrix(0, object->pos[0], object->pos[1], object->pos[2]);
        rotate_matrix_y(NULL, head_angle);
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(sensor_general01_texture_lists[1]));
        draw_ginja_model(object->model);
        pop_matrix();
        pop_matrix();
    }
}

void *TOSensorGeneral01::create(void *set_data) {
    return new TOSensorGeneral01(tl_05, set_data);
}

void TOSensorGeneral01::free_assets() {
    if (sensor_general01_texture_lists != NULL) {
        free_if_valid(sensor_general01_texture_lists[0]);
        if (sensor_general01_texture_lists != NULL) {
            mem_free(sensor_general01_texture_lists);
            sensor_general01_texture_lists = NULL;
        }
    }
    if (sensor_general_shared_bml_archive != NULL) {
        delete sensor_general_shared_bml_archive;
        sensor_general_shared_bml_archive = NULL;
    }
}

void TOSensorGeneral01::load_assets() {
    BmlResource *resource = new BmlResource(1, &sensor_general01_resource_descriptor, 0, 0, NULL);
    sensor_general_shared_bml_archive = resource;
    sensor_general01_texture_lists = (NJS_TEXLIST **)mem_alloc(2 * sizeof(*sensor_general01_texture_lists));
    sensor_general01_texture_lists[1] = sensor_general_shared_bml_archive->models[0].texlist;
    sensor_general01_texture_lists[0] = LoadPvmFileTls("fs_obj_sensor_r.gvm");
}

TOSensorGeneral01::~TOSensorGeneral01() {}

TOSensorGeneral01::TOSensorGeneral01(TObject *parent, void *set_data) : TOSensor(parent) {
    m_name = sensor_general01_class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    texlist = sensor_general01_texture_lists[0];
    model = sensor_general_shared_bml_archive->models[0].model;
    view_range = 400.0f;
    model_radius = ((GinjaModelBounds *)model->model)->radius;
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
