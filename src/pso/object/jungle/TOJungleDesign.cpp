#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "types.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/object/jungle/TOJungleDesign_802FEEB4.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#pragma fp_contract on

const char *bm_obj_jungle_tree_model_names[4] = { "fe_obj_ryuuboku_01.gj", "fe_obj_ryuuboku_02.gj", "fe_obj_ryuuboku_03.gj", NULL };
const char *bm_obj_jungle_tree_motion_names[1] = { NULL };
BmlResourceDescriptor bm_obj_jungle_tree_resource_descriptor = { "bm_obj_jungle_tree.bml", bm_obj_jungle_tree_model_names, bm_obj_jungle_tree_motion_names, 3, 0 };
const char *TOJungleDesign__name = "TOJungleDesign";
// The model each design variant (m_b0, clamped to 0..2) draws.
const s32 jungle_design_variant_table[3] = { 0, 1, 2 };
BmlResource *TOJungleDesign__shared_model_resource;

void TOJungleDesign::init_design_variant() {
    this->m_b0 = (s32) this->set_params[0];
    if ((s32) this->m_b0 < 0) {
        this->m_b0 = 0;
    }
    if ((s32) this->m_b0 > 2) {
        this->m_b0 = 2;
    }
    this->m_ac = (saddr)fn_802FF064(jungle_design_variant_table[this->m_b0]);
    this->texlist = fn_802FF028(0);
}


void *TOJungleDesign::create(void *set_data) {
    void *o = (void *)new TOJungleDesign((saddr)tl_05, (saddr)set_data);
    return o;
}


// One box per design variant (m_b0).
CollisionBody TOJungleDesign__collision_desc_table[3] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

extern "C" {
s32 post_translate_matrix(void *);


void TOJungleDesign::render() {
    if (this->update_object_view_visibility(400.0f, 40.0f) == 1) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, (this->rotation_x), (this->rotation_y), (this->rotation_z));
        draw_ginja_object((void *)this->m_ac);
        pop_matrix();
    }
}

}
TOJungleDesign::~TOJungleDesign() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}
TOJungleDesign::TOJungleDesign(saddr parent, saddr set_data) : TObjCollidable((TObject *)parent) {
    this->m_name = TOJungleDesign__name;
    ((TOJungleDesign *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    this->init_design_variant();
    init_collision_body_parts(this, &TOJungleDesign__collision_desc_table[this->m_b0], 1);
    ((TObjPlayer *)this)->register_object_by_id();
}


NJS_TEXLIST *fn_802FF028(s32 index) {
    if (TOJungleDesign__shared_model_resource != NULL) {
        return get_bml_texlist((BmlResource *)TOJungleDesign__shared_model_resource, index);
    }
    return NULL;
}
NJS_OBJECT *fn_802FF064(s32 index) {
    if (TOJungleDesign__shared_model_resource != NULL) {
        return (NJS_OBJECT *)get_bml_model((BmlResource *)TOJungleDesign__shared_model_resource, index);
    }
    return NULL;
}


void TOJungleDesign::free_shared_resource() {
    if (TOJungleDesign__shared_model_resource != NULL) {
        delete (BmlResource *)TOJungleDesign__shared_model_resource;
        TOJungleDesign__shared_model_resource = NULL;
    }
}

void TOJungleDesign::load_shared_resource() {
    BmlResource *archive = new BmlResource(1, (BmlResourceDescriptor *)&bm_obj_jungle_tree_resource_descriptor, 0, 0, NULL);
    TOJungleDesign__shared_model_resource = archive;
}
