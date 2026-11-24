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


struct FadeBase_8019AA18 { char pad[0x14]; };

struct Fade_8019AA18 : FadeBase_8019AA18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void begin();
    virtual void end();
};

struct ObjBase_8019AA18 { char pad[0x18]; };

struct Obj_8019AA18 : ObjBase_8019AA18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 is_visible(f32, f32);
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_3C { u8 bytes[0x3c]; };

extern "C" {
void __ct__15RenderFadeStateFv(void *);
s32 matrix_mult_vec(int, void *, void *);
BmlResource *TObjTuitate__bml_resource;
BmlResource *TObjBigTuitate__bml_resource;

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
CollisionBody TObjTuitate__collision_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
CollisionBody big_tuitate_collision_body[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
const char *TObjTuitate__class_name = "TObjTuitate";
const char *TObjBigTuitate__name = "TObjBigTuitate";

void free_collision_body_parts(void *);


}
struct FadeBase_8019ADA0 { char pad[0x14]; };

struct Fade_8019ADA0 : FadeBase_8019ADA0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void begin();
    virtual void end();
};

struct ObjBase_8019ADA0 { char pad[0x18]; };

struct Obj_8019ADA0 : ObjBase_8019ADA0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 is_visible(f32, f32);
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


void load_tuitate_bml_resource(void) {
    BmlResource *storage = new BmlResource(1, (BmlResourceDescriptor *)&fe_obj_tutate_resource_descriptor, 0, 0, NULL);
    TObjTuitate__bml_resource = storage;
}

void free_tuitate_bml_resource(void) {
    if (TObjTuitate__bml_resource != NULL) {
        delete (BmlResource *)TObjTuitate__bml_resource;
        TObjTuitate__bml_resource = NULL;
    }
}

void *TObjTuitate::create(void *set_data) {
    return new TObjTuitate(tl_05, set_data);
}

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)this)
TObjTuitate::TObjTuitate(TObject *parent, void *arg2) : TObjCollidable(parent) {
    union {
        u8 bytes[0x3C];
        struct {
            u8 pad[0x24];
            f32 x;
            f32 y;
            f32 z;
        } extents;
    } copy_storage;
    __ct__15RenderFadeStateFv(((void *)((u8 *)arg0 + 0xAC)));
    *(saddr *)((s8 *)arg0 + 0) = (saddr) TObjTuitate__class_name;
    ((TObjTuitate *)(arg0))->apply_object_set_data((void *)((saddr)arg2));
    init_collision_body_parts(arg0, TObjTuitate__collision_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    *(ByteBlock_3C *)(copy_storage.bytes) = *(const ByteBlock_3C *)(((saddr)arg2 - 4) + 4);
    copy_storage.extents.x = 32.0f;
    copy_storage.extents.y = 2e+01f;
    copy_storage.extents.z = 12.0f;
    *(TObjMapCsn **)((s8 *)arg0 + 0xC8) = TObjMapCsn::create(copy_storage.bytes);
    ((RenderFadeState *)((u8 *)arg0 + 0xAC))->activate_and_dispatch();
}
#undef arg0
#pragma pop

TObjTuitate::~TObjTuitate() {
    if (*(void **)((s8 *)this + 0xC8) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0xC8)))->queue_destruction(); *(s32 *)((s8 *)this + 0xC8) = 0; }
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    __dt__15RenderFadeStateFv((s8 *)this + 0xAC, -1);
}

void TObjTuitate::run_task() { { (void)(((RenderFadeState *)((char*)this + 0xac))->update()); return; } }

void TObjTuitate::render() {
    Obj_8019ADA0 *self = (Obj_8019ADA0 *)this;
    u8 *arg0 = (u8 *)self;
    Vec v;
    s32 fading;
    if (self->is_visible(4e+02f, 2e+01f) == 0) {
        return;
    }
    matrix_mult_vec(0, arg0 + 0x38, &v);
    if (v.z > (-38.0f)) {
        ((RenderFadeState *)(arg0 + 0xAC))->fadeOut();
    } else {
        ((RenderFadeState *)(arg0 + 0xAC))->restore();
    }
    set_cull_back();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = ((RenderFadeState *)(arg0 + 0xAC))->isFading();
    }
    if (fading != 0) {
        ((Fade_8019ADA0 *)(arg0 + 0xAC))->begin();
    }
    TObjFish::set_global_param(get_bml_texlist((BmlResource *)TObjTuitate__bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TObjTuitate__bml_resource, 0)));
    pop_matrix();
    if (fading != 0) {
        ((Fade_8019ADA0 *)(arg0 + 0xAC))->end();
    }
    set_cull_none();
}

void load_bigtuitate_bml_resource(void) {
    BmlResource *storage = new BmlResource(1, (BmlResourceDescriptor *)&fe_obj_bigtutate_resource_descriptor, 0, 0, NULL);
    TObjBigTuitate__bml_resource = storage;
}

void TObjBigTuitate::free_instance() {
    if (TObjBigTuitate__bml_resource != NULL) {
        delete (BmlResource *)TObjBigTuitate__bml_resource;
        TObjBigTuitate__bml_resource = NULL;
    }
}

void *TObjBigTuitate::create(void *set_data) {
    return new TObjBigTuitate(tl_05, set_data);
}

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)this)
TObjBigTuitate::TObjBigTuitate(TObject *parent, void *arg2) : TObjCollidable(parent) {
    union {
        u8 bytes[0x3C];
        struct {
            u8 pad[0x24];
            f32 x;
            f32 y;
            f32 z;
        } extents;
    } copy_storage;
    __ct__15RenderFadeStateFv(((void *)((u8 *)arg0 + 0xAC)));
    *(saddr *)((s8 *)arg0 + 0) = (saddr) TObjBigTuitate__name;
    ((TObjBigTuitate *)(arg0))->apply_object_set_data((void *)((saddr)arg2));
    init_collision_body_parts(arg0, big_tuitate_collision_body, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    *(ByteBlock_3C *)(copy_storage.bytes) = *(const ByteBlock_3C *)(((saddr)arg2 - 4) + 4);
    copy_storage.extents.x = 32.0f;
    copy_storage.extents.y = 4e+01f;
    copy_storage.extents.z = 12.0f;
    *(TObjMapCsn **)((s8 *)arg0 + 0xC8) = TObjMapCsn::create(copy_storage.bytes);
    ((RenderFadeState *)((u8 *)arg0 + 0xAC))->activate_and_dispatch();
}
#undef arg0
#pragma pop

TObjBigTuitate::~TObjBigTuitate() {
    if (*(void **)((s8 *)this + 0xC8) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0xC8)))->queue_destruction(); *(s32 *)((s8 *)this + 0xC8) = 0; }
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    __dt__15RenderFadeStateFv((s8 *)this + 0xAC, -1);
}

void TObjBigTuitate::run_task() { { (void)(((RenderFadeState *)((char*)this + 0xac))->update()); return; } }

void TObjBigTuitate::render() {
    Obj_8019AA18 *self = (Obj_8019AA18 *)this;
    u8 *arg0 = (u8 *)self;
    Vec v;
    s32 fading;
    if (self->is_visible(4e+02f, 2e+01f) == 0) {
        return;
    }
    matrix_mult_vec(0, arg0 + 0x38, &v);
    if (-v.z < 38.0f) {
        ((RenderFadeState *)(arg0 + 0xAC))->fadeOut();
    } else {
        ((RenderFadeState *)(arg0 + 0xAC))->restore();
    }
    set_cull_back();
    if (TRaderMapCore::is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = ((RenderFadeState *)(arg0 + 0xAC))->isFading();
    }
    if (fading != 0) {
        ((Fade_8019AA18 *)(arg0 + 0xAC))->begin();
    }
    TObjFish::set_global_param(get_bml_texlist((BmlResource *)TObjBigTuitate__bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TObjBigTuitate__bml_resource, 0)));
    pop_matrix();
    if (fading != 0) {
        ((Fade_8019AA18 *)(arg0 + 0xAC))->end();
    }
    set_cull_none();
}
