#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResourceLoad.h"
#include "types.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/DebugFont.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#pragma fp_contract on

const char *bm_obj_jungle_tree_model_names[4] = { "fe_obj_ryuuboku_01.gj", "fe_obj_ryuuboku_02.gj", "fe_obj_ryuuboku_03.gj", NULL };
const char *bm_obj_jungle_tree_motion_names[1] = { NULL };
BmlResourceDescriptor bm_obj_jungle_tree_resource_descriptor = { "bm_obj_jungle_tree.bml", bm_obj_jungle_tree_model_names, bm_obj_jungle_tree_motion_names, 3, 0 };
const char *jungle_design_name = "TOJungleDesign";
// The model each design variant (clamped to 0..2) draws.
const s32 jungle_design_variant_table[3] = { 0, 1, 2 };
BmlResource *jungle_design_shared_model_resource;

void TOJungleDesign::init_design_variant() {
    this->variant = this->set_params[0];
    if (this->variant < 0) {
        this->variant = 0;
    }
    if (this->variant > 2) {
        this->variant = 2;
    }
    this->design_model = get_jungle_design_model(jungle_design_variant_table[this->variant]);
    this->texlist = get_jungle_design_texlist(0);
}


void *TOJungleDesign::create(void *set_data) {
    void *o = (void *)new TOJungleDesign(tl_05, set_data);
    return o;
}


// One box per design variant.
CollisionBody jungle_design_collision_desc_table[3] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

void TOJungleDesign::render() {
    if (this->update_object_view_visibility(400.0f, 40.0f) == 1) {
        set_texture_list(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_yxz(0, (this->rotation.x), (this->rotation.y), (this->rotation.z));
        draw_ginja_object(this->design_model);
        pop_matrix();
    }
}
TOJungleDesign::~TOJungleDesign() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}
TOJungleDesign::TOJungleDesign(TObject *parent, void *set_data) : TObjCollidable(parent) {
    this->m_name = jungle_design_name;
    this->apply_object_set_data(set_data);
    this->init_design_variant();
    init_collision_body_parts(this, &jungle_design_collision_desc_table[this->variant], 1);
    this->register_object_by_id();
}


NJS_TEXLIST *get_jungle_design_texlist(s32 index) {
    if (jungle_design_shared_model_resource != NULL) {
        return get_bml_texlist(jungle_design_shared_model_resource, index);
    }
    return NULL;
}
NJS_OBJECT *get_jungle_design_model(s32 index) {
    if (jungle_design_shared_model_resource != NULL) {
        return get_bml_model(jungle_design_shared_model_resource, index);
    }
    return NULL;
}


void TOJungleDesign::free_shared_resource() {
    if (jungle_design_shared_model_resource != NULL) {
        delete jungle_design_shared_model_resource;
        jungle_design_shared_model_resource = NULL;
    }
}

void TOJungleDesign::load_shared_resource() {
    BmlResource *archive = new BmlResource(1, &bm_obj_jungle_tree_resource_descriptor, 0, 0, NULL);
    jungle_design_shared_model_resource = archive;
}
