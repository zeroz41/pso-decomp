#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/TObjBigTuitate.h"
#include "pso/object/TObjTuitate.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/RenderFadeState_800D7BFC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/render/RenderFadeState.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8019AD50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_3C { u8 bytes[0x3c]; };

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
BmlResource *tuitate_bml_resource;
BmlResource *big_tuitate_bml_resource;

s32 init_collision_body_parts(void *, void *, int);
__declspec(section ".data") const char *fe_obj_tutate_model_names[2] = { "fe_obj_tutate.gj", NULL };
const char *fe_obj_tutate_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_tutate_resource_descriptor = {
    "fe_obj_tutate.bml", fe_obj_tutate_model_names, fe_obj_tutate_motion_names, 1, 0
};
__declspec(section ".data") const char *fe_obj_bigtutate_model_names[2] = { "fe_obj_bigtutate.gj", NULL };
const char *fe_obj_bigtutate_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_bigtutate_resource_descriptor = {
    "fe_obj_bigtutate.bml", fe_obj_bigtutate_model_names, fe_obj_bigtutate_motion_names, 1, 0
};
CollisionBody tuitate_collision_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
CollisionBody big_tuitate_collision_body[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
const char *tuitate_class_name = "TObjTuitate";
const char *big_tuitate_name = "TObjBigTuitate";

void free_collision_body_parts(void *);


}
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


void load_tuitate_bml_resource(void) {
    BmlResource *storage = new BmlResource(1, (BmlResourceDescriptor *)&fe_obj_tutate_resource_descriptor, 0, 0, NULL);
    tuitate_bml_resource = storage;
}

void free_tuitate_bml_resource(void) {
    if (tuitate_bml_resource != NULL) {
        delete (BmlResource *)tuitate_bml_resource;
        tuitate_bml_resource = NULL;
    }
}

void *TObjTuitate::create(void *set_data) {
    return new TObjTuitate(tl_05, set_data);
}

#pragma push
#pragma opt_common_subs off
TObjTuitate::TObjTuitate(TObject *parent, void *set_data) : TObjCollidable(parent) {
    union {
        u8 bytes[0x3C];
        struct {
            u8 pad[0x24];
            f32 x;
            f32 y;
            f32 z;
        } extents;
    } copy_storage;
    m_name = tuitate_class_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, tuitate_collision_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    *(ByteBlock_3C *)(copy_storage.bytes) = *(const ByteBlock_3C *)set_data;
    copy_storage.extents.x = 32.0f;
    copy_storage.extents.y = 2e+01f;
    copy_storage.extents.z = 12.0f;
    m_csn = TObjMapCsn::create(copy_storage.bytes);
    m_fade.activate_and_dispatch();
}
#pragma pop

TObjTuitate::~TObjTuitate() {
    if (m_csn != NULL) {
        m_csn->queue_destruction();
        m_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjTuitate::run_task() { m_fade.update(); }

void TObjTuitate::render() {
    Vec v;
    s32 fading;
    if (update_object_view_visibility(4e+02f, 2e+01f) == 0) {
        return;
    }
    matrix_mult_vec(0, &position, &v);
    if (v.z > (-38.0f)) {
        m_fade.fadeOut();
    } else {
        m_fade.restore();
    }
    set_cull_back();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = m_fade.isFading();
    }
    if (fading != 0) {
        m_fade.set_flags_and_apply_damage_color();
    }
    TObjFish::set_global_param(get_bml_texlist((BmlResource *)tuitate_bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)tuitate_bml_resource, 0)));
    pop_matrix();
    if (fading != 0) {
        m_fade.clear_flag_and_notify();
    }
    set_cull_none();
}

void load_bigtuitate_bml_resource(void) {
    BmlResource *storage = new BmlResource(1, (BmlResourceDescriptor *)&fe_obj_bigtutate_resource_descriptor, 0, 0, NULL);
    big_tuitate_bml_resource = storage;
}

void TObjBigTuitate::free_instance() {
    if (big_tuitate_bml_resource != NULL) {
        delete (BmlResource *)big_tuitate_bml_resource;
        big_tuitate_bml_resource = NULL;
    }
}

void *TObjBigTuitate::create(void *set_data) {
    return new TObjBigTuitate(tl_05, set_data);
}

#pragma push
#pragma opt_common_subs off
TObjBigTuitate::TObjBigTuitate(TObject *parent, void *set_data) : TObjCollidable(parent) {
    union {
        u8 bytes[0x3C];
        struct {
            u8 pad[0x24];
            f32 x;
            f32 y;
            f32 z;
        } extents;
    } copy_storage;
    m_name = big_tuitate_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, big_tuitate_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    *(ByteBlock_3C *)(copy_storage.bytes) = *(const ByteBlock_3C *)set_data;
    copy_storage.extents.x = 32.0f;
    copy_storage.extents.y = 4e+01f;
    copy_storage.extents.z = 12.0f;
    m_csn = TObjMapCsn::create(copy_storage.bytes);
    m_fade.activate_and_dispatch();
}
#pragma pop

TObjBigTuitate::~TObjBigTuitate() {
    if (m_csn != NULL) {
        m_csn->queue_destruction();
        m_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjBigTuitate::run_task() { m_fade.update(); }

void TObjBigTuitate::render() {
    Vec v;
    s32 fading;
    if (update_object_view_visibility(4e+02f, 2e+01f) == 0) {
        return;
    }
    matrix_mult_vec(0, &position, &v);
    if (-v.z < 38.0f) {
        m_fade.fadeOut();
    } else {
        m_fade.restore();
    }
    set_cull_back();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = m_fade.isFading();
    }
    if (fading != 0) {
        m_fade.set_flags_and_apply_damage_color();
    }
    TObjFish::set_global_param(get_bml_texlist((BmlResource *)big_tuitate_bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)big_tuitate_bml_resource, 0)));
    pop_matrix();
    if (fading != 0) {
        m_fade.clear_flag_and_notify();
    }
    set_cull_none();
}

