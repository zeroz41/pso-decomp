#include "types.h"
#include "pso/misc/TOMonumentAncient01.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_o_sekihi01_model_names[4] = {
    "de_obj_o_sekihi01_moji.gj", "ds_obj_o_sekihi01_crystal.gj", "fe_obj_o_sekihi01.gj", NULL
};
const char *bm_fs_obj_o_sekihi01_motion_names[1] = { NULL };
BmlResourceDescriptor bm_fs_obj_o_sekihi01_resource_descriptor = {
    "bm_fs_obj_o_sekihi01.bml", bm_fs_obj_o_sekihi01_model_names, bm_fs_obj_o_sekihi01_motion_names, 3, 0
};
CollisionBody monument_ancient01_collision_body = {
    { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TOMonumentAncient01::class_name = "TOMonumentAncient01";
BmlResource *TOMonumentAncient01::model_resource;

void TOMonumentAncient01::update_demo() {}

void TOMonumentAncient01::render() {
    if (update_object_view_visibility(m_c0, model_radius) == 1) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_ginja_object((void *)get_bml_model(model_resource, 2));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object((void *)get_bml_model(model_resource, 1));
        draw_ginja_object((void *)get_bml_model(model_resource, 0));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOMonumentAncient01::create(void *set_data) {
    return new TOMonumentAncient01(tl_05, set_data);
}

void TOMonumentAncient01::unload_resources() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void TOMonumentAncient01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_fs_obj_o_sekihi01_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

TOMonumentAncient01::~TOMonumentAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOMonumentAncient01::TOMonumentAncient01(TObject *parent, void *set_data) : TUnk_804B27D8(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 2);
    texlist = TObjFish__sub_8001EDB0(model_resource, 2);
    init_collision_body_parts(this, &monument_ancient01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    read_set_params();
    m_c0 = 500.0f;
    model_radius = 50.0f;
}
