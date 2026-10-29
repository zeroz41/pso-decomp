#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOCakeshopCave01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_cakeya_model_names[] = {"fs_obj_cakeya.gj", NULL};
const char *bm_fs_obj_cakeya_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_cakeya_resource_descriptor = {
    "bm_fs_obj_cakeya.bml", bm_fs_obj_cakeya_model_names, bm_fs_obj_cakeya_motion_names, 1, 0,
};
CollisionBody cakeshop_cave01_collision_body_part[] = {
    {{0.0f, 22.5f, 0.0f}, 15.0f, 35.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOCakeshopCave01_class_name = "TOCakeshopCave01";
BmlResource *TOCakeshopCave01__model_resource;

// Each of the eight lights fades out at random, stays off a while, then
// comes back.
void TOCakeshopCave01::update_blink_state(s32 index) {
    switch (blink_state[index]) {
    default:
        blink_fade[index] += 0.05f;
        if ((1.0f / 32768.0f) * (f32)rand() < blink_fade[index]) {
            blink_state[index] = 1;
            blink_fade[index] = 0.0f;
        }
        break;
    case 1:
        blink_fade[index] -= 0.05f;
        if (blink_fade[index] <= -1.0f) {
            blink_state[index] = 2;
            blink_fade[index] = -1.0f;
        }
        break;
    case 2:
        blink_fade[index] += 0.05f;
        if (0.0f < blink_fade[index]) {
            blink_state[index] = 0;
        }
        break;
    }
}

void TOCakeshopCave01::run_task() {
    int i;
    for (i = 0; i < 8; i++) {
        update_blink_state(i);
    }
}

void TOCakeshopCave01::render() {
    NJS_OBJECT *node;
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        node = node->child;
        TParticleCtrl::begin_effect_render();
        for (i = 0; i < 8; i++) {
            if (blink_fade[i] < 0.0f) {
                push_matrix();
                post_translate_matrix(node->pos);
                scale_matrix(NULL, 1.0f - blink_fade[i], 1.0f - blink_fade[i], 0.0f);
                draw_ginja_model((s32)node->model);
                pop_matrix();
            }
            node = node->sibling;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOCakeshopCave01::create(void *set_data) {
    return new TOCakeshopCave01(set_data);
}

void TOCakeshopCave01::release_static_resource() {
    if (TOCakeshopCave01__model_resource != NULL) {
        TLobby__sub_8001FE7C(TOCakeshopCave01__model_resource, 1);
        TOCakeshopCave01__model_resource = NULL;
    }
}

void TOCakeshopCave01::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_cakeya_resource_descriptor, 0, 0, 0);
    }
    TOCakeshopCave01__model_resource = resource;
}

TOCakeshopCave01::~TOCakeshopCave01() {
    free_collision_body_parts(this);
    unregister_object_by_id();
}

TOCakeshopCave01::TOCakeshopCave01(void *set_data) : TObjMapObject(tl_05) {
    s32 i;
    m_name = TOCakeshopCave01_class_name;
    apply_object_set_data(set_data);
    model = (void *)TOCakeshopCave01__model_resource->models[0].model;
    texlist = TOCakeshopCave01__model_resource->models[0].m_c;
    view_range = 500.0f;
    model_radius = 60.0f;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, cakeshop_cave01_collision_body_part, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    for (i = 0; i < 8; i++) {
        blink_fade[i] = 0.0f;
        blink_state[i] = 0;
    }
}
