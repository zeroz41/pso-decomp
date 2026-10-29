#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TOMonitorMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaUvScroll.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

extern s32 actor_frame_tick;

const char *bm_fs_obj_monitor_model_names[] = {"fs_obj_monitor.gj", NULL};
const char *bm_fs_obj_monitor_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_monitor_resource_descriptor = {
    "bm_fs_obj_monitor.bml", bm_fs_obj_monitor_model_names, bm_fs_obj_monitor_motion_names, 1, 0,
};
const char *TOMonitorMachine01__class_name = "TOMonitorMachine01";
BmlResource *TOMonitorMachine01__bml_resource;
s32 TOMonitorMachine01__last_update_tick;
// The two screen meshes whose UVs scroll once per frame.
void *TOMonitorMachine01__scroll_meshes[2];

void TOMonitorMachine01::run_task() {
    if (TOMonitorMachine01__last_update_tick != actor_frame_tick) {
        TOMonitorMachine01__last_update_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_meshes[0], 1, 0, 1, 1);
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_meshes[1], 1, 0, 1, 1);
    }
    switch (object_state) {
    default:
        hold_timer += 1.0f;
        if (60.0f <= hold_timer) {
            object_state = 1;
            hold_timer = 0.0f;
            set_params[0]++;
            if (set_params[0] >= 4) {
                set_params[0] = 0;
            }
        }
        break;
    case 1:
        slide += 0.6666667f;
        screen_scale += 0.06666667f;
        if (10.0f <= slide) {
            object_state = 2;
            slide = 10.0f;
            screen_scale = 1.0f;
        }
        break;
    case 2:
        hold_timer += 1.0f;
        if (300.0f <= hold_timer) {
            object_state = 3;
            hold_timer = 0.0f;
        }
        break;
    case 3:
        slide -= 0.6666667f;
        screen_scale -= 0.06666667f;
        if (slide <= 0.0f) {
            object_state = 0;
            screen_scale = 0.0f;
            slide = 0.0f;
        }
        break;
    }
}

void TOMonitorMachine01::render() {
    NJS_OBJECT *n;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        n = ((NJS_OBJECT *)model)->child;
        push_matrix();
        translate_matrix(0, -slide, 0.0f, 0.0f);
        draw_ginja_model((s32)n->model);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->sibling;
        if (set_params[0] == 2) {
            push_matrix();
            scale_matrix(NULL, screen_scale, screen_scale, 1.0f);
            draw_ginja_model((s32)n->model);
            pop_matrix();
        }
        n = n->sibling;
        if (set_params[0] == 1) {
            push_matrix();
            scale_matrix(NULL, screen_scale, screen_scale, 1.0f);
            draw_ginja_model((s32)n->model);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        n = n->sibling;
        push_matrix();
        translate_matrix(0, slide, 0.0f, 0.0f);
        draw_ginja_model((s32)n->model);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->sibling;
        if (set_params[0] == 0) {
            push_matrix();
            scale_matrix(NULL, screen_scale, screen_scale, 1.0f);
            draw_ginja_model((s32)n->model);
            pop_matrix();
        }
        n = n->sibling;
        if (set_params[0] == 3) {
            push_matrix();
            scale_matrix(NULL, screen_scale, screen_scale, 1.0f);
            draw_ginja_model((s32)n->model);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOMonitorMachine01::create(void *set_data) {
    return new TOMonitorMachine01(set_data);
}

void TOMonitorMachine01::reset_static_state() {
    s32 i;
    TOMonitorMachine01__last_update_tick = 0;
    for (i = 0; i < 2; i++) {
        TOMonitorMachine01__scroll_meshes[i] = NULL;
    }
    if (TOMonitorMachine01__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOMonitorMachine01__bml_resource, 1);
        TOMonitorMachine01__bml_resource = NULL;
    }
}

void TOMonitorMachine01::load_resources() {
    NJS_OBJECT *screen;
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_monitor_resource_descriptor, 0, 0, 0);
    }
    TOMonitorMachine01__bml_resource = resource;
    screen = ((NJS_OBJECT *)resource->models[0].model)->child->sibling->sibling;
    TOMonitorMachine01__scroll_meshes[1] = screen->model;
    TOMonitorMachine01__scroll_meshes[0] = screen->sibling->sibling->model;
    TOMonitorMachine01__last_update_tick = 0;
}

TOMonitorMachine01::~TOMonitorMachine01() {}

TOMonitorMachine01::TOMonitorMachine01(void *set_data) : TObjMapObject(tl_05) {
    m_name = TOMonitorMachine01__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOMonitorMachine01__bml_resource, 0);
    texlist = TObjFish__sub_8001EDB0(TOMonitorMachine01__bml_resource, 0);
    view_range = 500.0f;
    model_radius = 15.0f;
    actorFlags |= 0x40000000;
    object_state = 0;
    slide = 0.0f;
    screen_scale = 0.0f;
    hold_timer = 0.0f;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    } else if (4 <= set_params[0]) {
        set_params[0] = 3;
    }
}
