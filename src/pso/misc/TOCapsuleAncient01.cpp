#include "types.h"
#include "pso/misc/TOCapsuleAncient01.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fe_obj_o_capsule01_model_names[2] = { "fe_obj_o_capsule01.gj", NULL };
const char *bm_fe_obj_o_capsule01_motion_names[1] = { NULL };
BmlResourceDescriptor bm_fe_obj_o_capsule01_resource_descriptor = {
    "bm_fe_obj_o_capsule01.bml", bm_fe_obj_o_capsule01_model_names, bm_fe_obj_o_capsule01_motion_names, 1, 0
};
CollisionBody capsule_ancient01_collision_body = {
    { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x30003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TOCapsuleAncient01::class_name = "TOCapsuleAncient01";
BmlResource *TOCapsuleAncient01::model_resource;

// The body, then (while active) its first child, the lid, turned by
// spin_angle and drawn as an effect.
void TOCapsuleAncient01::render() {
    NJS_OBJECT *body;
    NJS_OBJECT *lid;
    visible = update_object_view_visibility(m_c0, model_radius);
    if (visible == 1) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        body = (NJS_OBJECT *)model;
        translate_matrix(0, body->pos[0], body->pos[1], body->pos[2]);
        draw_ginja_model((s32)body->model);
        if (active == 1) {
            TParticleCtrl::begin_effect_render();
            lid = body->child;
            push_matrix();
            translate_matrix(0, lid->pos[0], lid->pos[1], lid->pos[2]);
            rotate_matrix_y(NULL, spin_angle);
            draw_ginja_model((s32)lid->model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void *TOCapsuleAncient01::create(void *set_data) {
    return new TOCapsuleAncient01(tl_05, set_data);
}

void TOCapsuleAncient01::unload_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOCapsuleAncient01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fe_obj_o_capsule01_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

TOCapsuleAncient01::~TOCapsuleAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

// Episode II's online mode and split screen do without the capsule.
TOCapsuleAncient01::TOCapsuleAncient01(TObject *parent, void *set_data) : TUnk_804B27D8(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)model_resource->models->model;
    texlist = model_resource->models->m_c;
    init_collision_body_parts(this, &capsule_ancient01_collision_body, 1);
    set_indexed_flags(0, 0x1288);
    refresh_collision_body_centers();
    register_object_by_id();
    read_set_params();
    m_c0 = 500.0f;
    model_radius = 10.0f;
    spin_angle = 0;
    if (enable_v2_features == 1 && get_game_play_mode() == 1) {
        queue_destruction();
    }
    if (is_split_screen() == 1) {
        queue_destruction();
    }
}

void TOCapsuleAncient01::animate() {
    spin_angle = spin_angle + 0x222;
}
