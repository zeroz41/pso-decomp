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

void *__nw__7TObjectFUl(int);


void *TOJungleDesign__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOJungleDesign__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}

extern "C" void *__ct__14TObjCollidableFP7TObject(void *, s32);

struct JDBase_802feeb4 { char pad[0x18]; };
struct JDVObj_802feeb4 : JDBase_802feeb4 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_802FEF98___vt__14TOJungleDesign {
    s32 value;
    u8 remaining[0x38];
};

// One box per design variant (m_b0).
CollisionBody TOJungleDesign__collision_desc_table[3] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 5.0f, 3.0f, 1, 0x10003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};

extern "C" {
s32 init_collision_body_parts(void *, int, int);
extern s32 __vt__14TOJungleDesign[];
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 push_matrix();
void __dl__7TObjectFPv(void *);


void TOJungleDesign::render() {
    u8 *arg0 = (u8 *)this;
    if (((JDVObj_802feeb4 *)arg0)->m8(400.0f, 40.0f) == 1) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_yxz(0, (*(s32 *)&this->rotation_x), (this->rotation_y), (this->rotation_z));
        draw_ginja_object((void *)this->m_ac);
        pop_matrix();
    }
}

}
TOJungleDesign::~TOJungleDesign() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
typedef char RecoveredGlobal_802FEF98___vt__14TOJungleDesign_size[sizeof(RecoveredGlobal_802FEF98___vt__14TOJungleDesign) == 0x3C ? 1 : -1];
u8 *TOJungleDesign__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802FEF98___vt__14TOJungleDesign *)&__vt__14TOJungleDesign).value;
    ((TOJungleDesign *)arg0)->m_name = TOJungleDesign__name;
    ((TOJungleDesign *)(arg0))->apply_object_set_data((void *)arg2);
    ((TOJungleDesign *)arg0)->init_design_variant();
    init_collision_body_parts(arg0, (int)&TOJungleDesign__collision_desc_table[((TOJungleDesign *)arg0)->m_b0], 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    return arg0;
}

}

extern "C" {
u8 * TObjFish__sub_8001EDB0(void *, int);
u8 * get_bml_model(void *, int);
u8 *fn_802FF028(s32 arg0) {
    if ((void *) TOJungleDesign__shared_model_resource != NULL) {
        return TObjFish__sub_8001EDB0(TOJungleDesign__shared_model_resource, arg0);
    }
    return NULL;
}
u8 *fn_802FF064(s32 arg0) {
    if ((void *) TOJungleDesign__shared_model_resource != NULL) {
        return get_bml_model(TOJungleDesign__shared_model_resource, arg0);
    }
    return NULL;
}

}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void free_bin_model_request(void*, int);

void TOJungleDesign::free_shared_resource() {
    if ((u32) TOJungleDesign__shared_model_resource != 0U) {
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
