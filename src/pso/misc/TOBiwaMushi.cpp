#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaModel.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/AngleLookup.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TOBiwaMushi.h"
#include "pso/misc/TOMekaFish00.h"
#include "pso/misc/TOMekaFish01.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include <stdlib.h>

// The source is written from the last function back: the unit is built
// -inline off,deferred, which emits it in reverse.

const char *bm_obj_meka_fish_0_model_names[2] = { "uotitti_30_a.gj", NULL };
const char *bm_obj_meka_fish_0_motion_names[2] = { "uotitti_30_a.njm", NULL };
BmlResourceDescriptor bm_obj_meka_fish_0_resource_descriptor = {
    "bm_obj_meka_fish_0.bml", bm_obj_meka_fish_0_model_names, bm_obj_meka_fish_0_motion_names, 1, 1
};
const char *bm_obj_meka_fish_1_model_names[2] = { "uotitti_30_a_1.gj", NULL };
const char *bm_obj_meka_fish_1_motion_names[2] = { "uotitti_30_a_1.njm", NULL };
BmlResourceDescriptor bm_obj_meka_fish_1_resource_descriptor = {
    "bm_obj_meka_fish_1.bml", bm_obj_meka_fish_1_model_names, bm_obj_meka_fish_1_motion_names, 1, 1
};
const char *bm_obj_jungle_biwamushi_model_names[2] = { "fe_obj_biwamushi.gj", NULL };
const char *bm_obj_jungle_biwamushi_motion_names[2] = { "fe_obj_biwamushi.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_biwamushi_resource_descriptor = {
    "bm_obj_jungle_biwamushi.bml", bm_obj_jungle_biwamushi_model_names, bm_obj_jungle_biwamushi_motion_names, 1, 1
};

const char *TOMekaFish00::class_name = "TOMekaFish00";
const char *TOMekaFish01::class_name = "TOMekaFish01";
const char *TOBiwaMushi::class_name = "TOBiwaMushi";
BmlResource *TOMekaFish00::model_resource;
BmlResource *TOMekaFish01::model_resource;
BmlResource *TOBiwaMushi::model_resource;

extern "C" {
extern u32 TBoss6PlotFalz__instance;
}

s32 TBoss6PlotFalz::is_phase_reached() {
    u32 p = TBoss6PlotFalz__instance;
    if (!p) {
        return 0;
    }
    return ((TObjFish *)TBoss6PlotFalz__instance)->get_phase() >= 7 ? 1 : 0;
}

TOMekaFish00::TOMekaFish00(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 0);
    texlist = TObjFish__sub_8001EDB0(model_resource, 0);
    motion = get_bml_motion(model_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 1.1f;
    m_c0 = 500.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    m_ac = 0;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
}

TOMekaFish00::~TOMekaFish00() {}

void TOMekaFish00::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_obj_meka_fish_0_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

void TOMekaFish00::release_static_instance() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TOMekaFish00::create(void *set_data) {
    return new TOMekaFish00(set_data);
}

TOMekaFish01::TOMekaFish01(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 0);
    texlist = TObjFish__sub_8001EDB0(model_resource, 0);
    motion = get_bml_motion(model_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 1.1f;
    m_c0 = 500.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    m_ac = 0;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
}

TOMekaFish01::~TOMekaFish01() {}

void TOMekaFish01::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_obj_meka_fish_1_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

void TOMekaFish01::free_static_data() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TOMekaFish01::create(void *set_data) {
    return new TOMekaFish01(set_data);
}

TOBiwaMushi::TOBiwaMushi(void *set_data) {
    m_name = class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(model_resource, 0);
    texlist = TObjFish__sub_8001EDB0(model_resource, 0);
    motion = get_bml_motion(model_resource, 0);
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 1.1f;
    m_c0 = 500.0f;
    model_radius = ((GinjaModelBounds *)((NJS_OBJECT *)model)->model)->radius;
    m_ac = 0;
    bob_rate = 0.1f * (f32)set_params[0] + 1.0f;
    bob_angle_step = 182.04445f * (360.0f / (30.0f / bob_rate));
    bob_angle = 182.04445f * (360.0f * (3.0517578e-05f * (f32)rand()));
    bob_height = 0.1f * (f32)set_params[1] + 1.0f;
    bob_offset = bob_height * sin_table_lookup(bob_angle);
}

TOBiwaMushi::~TOBiwaMushi() {}

void TOBiwaMushi::load_resource_instance() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_obj_jungle_biwamushi_resource_descriptor, 0, 0, 0);
    }
    model_resource = resource;
}

void TOBiwaMushi::free_shared_data() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TOBiwaMushi::create(void *set_data) {
    return new TOBiwaMushi(set_data);
}
