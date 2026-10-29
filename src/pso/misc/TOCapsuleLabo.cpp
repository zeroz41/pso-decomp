#include "types.h"
#include "pso/misc/TOCapsuleLabo.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaUtil.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_obj_labo_infocapsule_model_names[2] = { "obj_o_labo_infocapsule.gj", NULL };
const char *bm_obj_labo_infocapsule_motion_names[1] = { NULL };
BmlResourceDescriptor bm_obj_labo_infocapsule_resource_descriptor = {
    "bm_obj_labo_infocapsule.bml", bm_obj_labo_infocapsule_model_names, bm_obj_labo_infocapsule_motion_names, 1, 0
};
CollisionBody capsule_labo_collision_body = {
    { 0.0f, 10.0f, 0.0f }, 3.0f, 0.0f, 0, 0x30003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TOCapsuleLabo::class_name = "TOCapsuleLabo";
BmlResource *TOCapsuleLabo::model_resource;
NJS_OBJECT *TOCapsuleLabo::light_node;

void *TOCapsuleLabo::create(void *set_data) {
    return new TOCapsuleLabo(tl_05, set_data);
}

void TOCapsuleLabo::unload_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOCapsuleLabo::load_resources() {
    NJS_OBJECT *root;
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_obj_labo_infocapsule_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
    root = (NJS_OBJECT *)get_bml_model(resource, 0);
    if (root != NULL) {
        light_node = find_object_node(root, 3);
    }
}

// The body, its first child the lid (turned by spin_angle) and the lid's
// child the light, drawn as an effect.
void TOCapsuleLabo::render() {
    NJS_OBJECT *body;
    NJS_OBJECT *lid;
    NJS_OBJECT *light;
    visible = update_object_view_visibility(view_range, model_radius);
    if (visible == 1) {
        TObjFish::set_global_param(texlist);
        if (active == 1) {
            if (light_node != NULL) {
                light_node->evalflags &= ~NJD_EVAL_HIDE;
            }
        } else if (light_node != NULL) {
            light_node->evalflags |= NJD_EVAL_HIDE;
        }
        body = (NJS_OBJECT *)model;
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        post_translate_matrix(body->pos);
        draw_ginja_model((s32)body->model);
        lid = body->child;
        push_matrix();
        post_translate_matrix(lid->pos);
        rotate_matrix_y(NULL, spin_angle);
        draw_ginja_model((s32)lid->model);
        light = lid->child;
        TParticleCtrl::begin_effect_render();
        post_translate_matrix(light->pos);
        draw_ginja_object(light);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void TOCapsuleLabo::animate() {
    spin_angle = spin_angle + 0x222;
}

TOCapsuleLabo::~TOCapsuleLabo() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

// Episode II's online mode and split screen do without the capsule.
TOCapsuleLabo::TOCapsuleLabo(TObject *parent, void *set_data) : TOQuestTalkBase(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 0);
    texlist = TObjFish__sub_8001EDB0(model_resource, 0);
    init_collision_body_parts(this, &capsule_labo_collision_body, 1);
    set_indexed_flags(0, 0x1288);
    refresh_collision_body_centers();
    register_object_by_id();
    read_set_params();
    view_range = 500.0f;
    model_radius = 50.0f;
    spin_angle = 0;
    if (enable_v2_features == 1 && get_game_play_mode() == 1) {
        queue_destruction();
    }
    if (is_split_screen() == 1) {
        queue_destruction();
    }
}
