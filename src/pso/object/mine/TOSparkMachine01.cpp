#include "pso/system/BmlResource.h"
#include "types.h"

#include "pso/system/BmlResourceLoader.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/mine/TOSparkMachine01.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

extern "C" {
extern const char *bm_fe_obj_tank_hikari_motion_names[1];
extern const char *bm_fe_obj_tank_hikari_model_names[2];
const char *bm_fe_obj_tank_hikari_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_fe_obj_tank_hikari_model_names[2] = { "fe_obj_tank_hikari.gj", NULL };
BmlResourceDescriptor bm_fe_obj_tank_hikari_resource_descriptor = { "bm_fe_obj_tank_hikari.bml", bm_fe_obj_tank_hikari_model_names, bm_fe_obj_tank_hikari_motion_names, 1, 0 };
const char *TOSparkMachine01__name = "TOSparkMachine01";
BmlResource *TOSparkMachine01__static_resource;
extern BmlResourceDescriptor bm_fe_obj_tank_hikari_resource_descriptor;
extern BmlResource *TOSparkMachine01__static_resource;
extern const char *TOSparkMachine01__name;
void rotate_matrix_y(int, int);
void post_translate_matrix(void *);

void TOSparkMachine01::update_spark_toggle(s32 i) {
    switch (spark_on[i]) {
    case 1:
        spark_timer[i] += spark_speed;
        if (0.000030517578f * (f32)rand() < spark_timer[i]) {
            spark_on[i] = 0;
            spark_timer[i] = 0.0f;
        }
        break;
    default:
        spark_timer[i] += spark_speed;
        if (0.000030517578f * (f32)rand() < spark_timer[i]) {
            spark_on[i] = 1;
            spark_timer[i] = 0.0f;
        }
        break;
    }
}

void TOSparkMachine01::run_task() {
    s32 i;
    if (0.0f < this->scale.y) {
        i = 0;
        do {
            update_spark_toggle(i);
            i += 1;
        } while (i < 4);
        return;
    }
    spark_on[3] = 0;
    spark_on[2] = 0;
    spark_on[0] = 0;
    update_spark_toggle(1);
}

void TOSparkMachine01::render() {
    NJS_OBJECT *n;
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        n = ((NJS_OBJECT *)model)->child;
        TParticleCtrl::begin_effect_render();
        for (i = 0; i < 4; i++) {
            switch (spark_on[i]) {
            case 1:
                push_matrix();
                post_translate_matrix(n->pos);
                draw_ginja_model(n->model);
                pop_matrix();
                break;
            }
            n = n->sibling;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOSparkMachine01::create(void *set_data) {
    return new TOSparkMachine01(set_data);
}

void TOSparkMachine01::destroy_static_instance() {
    if (TOSparkMachine01__static_resource != NULL) {
        delete (BmlResource *)TOSparkMachine01__static_resource;
        TOSparkMachine01__static_resource = NULL;
    }
}

void TOSparkMachine01::load_static_resource() {
    BmlResource *archive = new BmlResource(1, (BmlResourceDescriptor *)&bm_fe_obj_tank_hikari_resource_descriptor, 0, 0, NULL);
    TOSparkMachine01__static_resource = archive;
}

}
TOSparkMachine01::~TOSparkMachine01() {

}

TOSparkMachine01::TOSparkMachine01(void *set_data) : TObjBase(tl_05) {
    TOSparkMachine01 *self = this;
    s32 i;
    self->m_name = TOSparkMachine01__name;
    self->apply_object_set_data(set_data);
    self->model = (void *)TOSparkMachine01__static_resource->models[0].model;
    self->texlist = TOSparkMachine01__static_resource->models[0].texlist;
    self->view_range = 500.0f;
    self->model_radius = 40.0f;
    self->actorFlags |= 0x40000000;
    for (i = 0; i < 4; i++) {
        self->spark_timer[i] = 0.0f;
        self->spark_on[i] = 0;
    }
    self->spark_speed = -0.98f + self->scale.x;
}
