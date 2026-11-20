#include "types.h"
#include "pso/object/jungle/TOJungleDesign.h"
#include "pso/object/jungle/TOJungleDesign_802FEEB4.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
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
u8 *TOJungleDesign__shared_model_resource;

void TOJungleDesign::init_design_variant() {
    this->m_b0 = (s32) this->set_params[0];
    if ((s32) this->m_b0 < 0) {
        this->m_b0 = 0;
    }
    if ((s32) this->m_b0 > 2) {
        this->m_b0 = 2;
    }
    this->m_ac = (s32)fn_802FF064(jungle_design_variant_table[this->m_b0]);
    this->texlist = (s32)fn_802FF028(0);
}

extern "C" {



void *TOJungleDesign__create(void *arg0) {
    void *o = (void *)new TOJungleDesign((s32)tl_05, (s32)arg0);
    return o;
}

}


// One box per design variant (m_b0).
CollisionBody TOJungleDesign__collision_desc_table[3] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

extern "C" {
s32 init_collision_body_parts(void *, int, int);
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 push_matrix();


void TOJungleDesign::render() {
    if (this->update_object_view_visibility(400.0f, 40.0f) == 1) {
        TObjFish::set_global_param(this->texlist);
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
extern "C" {
}
TOJungleDesign::TOJungleDesign(s32 arg1, s32 arg2) : TObjCollidable((TObject *)arg1) {
    this->m_name = TOJungleDesign__name;
    ((TOJungleDesign *)(((u8 *)this)))->apply_object_set_data((void *)arg2);
    this->init_design_variant();
    init_collision_body_parts(((u8 *)this), (int)&TOJungleDesign__collision_desc_table[this->m_b0], 1);
    ((TObjPlayer *)this)->register_object_by_id();
}
extern "C" {

u8 * get_bml_texlist(void *, int);
u8 * get_bml_model(void *, int);
u8 *fn_802FF028(s32 arg0) {
    if ((void *) TOJungleDesign__shared_model_resource != NULL) {
        return get_bml_texlist(TOJungleDesign__shared_model_resource, arg0);
    }
    return NULL;
}
u8 *fn_802FF064(s32 arg0) {
    if ((void *) TOJungleDesign__shared_model_resource != NULL) {
        return get_bml_model(TOJungleDesign__shared_model_resource, arg0);
    }
    return NULL;
}

u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void*, int);

void TOJungleDesign::free_shared_resource() {
    if ((uaddr) TOJungleDesign__shared_model_resource != 0U) {
        free_bin_model_request((void*)TOJungleDesign__shared_model_resource, 1);
        TOJungleDesign__shared_model_resource = 0U;
    }
}

void TOJungleDesign::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_obj_jungle_tree_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TOJungleDesign__shared_model_resource) = var_r0;
}

}
