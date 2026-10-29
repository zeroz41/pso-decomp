#include "types.h"
#include "pso/render/render_util.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800D7BFC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjBigTuitate.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_8019AD50.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjTuitate.h"

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

struct Vec_8019AA18 { f32 x, y, z; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_3C { u8 bytes[0x3c]; };

extern "C" {
void __ct__15RenderFadeStateFv(void *);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 isFading__15RenderFadeStateCFv(void *);
s32 matrix_mult_vec(int, void *, void *);
void rotate_matrix_y(int, int);
void push_matrix(void);
void post_translate_matrix(void *);
void set_global_param__8TObjFishFl(void);
void draw_ginja_object(void);
extern u32 TObjBigTuitate__bml_resource;

s32 init_collision_body_parts(void *, void *, int);
s32 __ct__14TObjCollidableFP7TObject();
extern s32 big_tuitate_collision_body[];
extern s32 __vt__14TObjBigTuitate[];
extern s32 lbl_805D3454;

void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
int update__15RenderFadeStateFv(void*);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjBigTuitate::render() {
    Obj_8019AA18 *self = (Obj_8019AA18 *)this;
    u8 *arg0 = (u8 *)self;
    Vec_8019AA18 v;
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
        fading = isFading__15RenderFadeStateCFv(arg0 + 0xAC);
    }
    if (fading != 0) {
        ((Fade_8019AA18 *)(arg0 + 0xAC))->begin();
    }
    TObjFish__sub_8001EDB0((*(s32 *)&TObjBigTuitate__bml_resource), 0);
    set_global_param__8TObjFishFl();
    push_matrix();
    post_translate_matrix(arg0 + 0x38);
    rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
    get_bml_model((*(s32 *)&TObjBigTuitate__bml_resource), 0);
    draw_ginja_object();
    pop_matrix();
    if (fading != 0) {
        ((Fade_8019AA18 *)(arg0 + 0xAC))->end();
    }
    set_cull_none();
}

void TObjBigTuitate::run_task() { { (void)(update__15RenderFadeStateFv((char*)this + 0xac)); return; } }

void *__dt__14TObjBigTuitateFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjBigTuitate;
        if (*(void **)((s8 *)arg0 + 0xC8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xC8)); *(s32 *)((s8 *)arg0 + 0xC8) = 0; }
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__15RenderFadeStateFv((s8 *)arg0 + 0xAC, -1);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

#pragma push
#pragma opt_common_subs off
void *TObjBigTuitate__ct(void *arg0, void *arg1, void *arg2) {
    struct CopyStack_8019ABE8 { u8 bytes[0x3C]; };
    CopyStack_8019ABE8 copy_storage_8019ABE8;
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjBigTuitate;
    __ct__15RenderFadeStateFv(((void *)((u8 *)arg0 + 0xAC)));
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3454;
    ((TObjBigTuitate *)(arg0))->apply_object_set_data((void *)((s32)arg2));
    init_collision_body_parts(arg0, big_tuitate_collision_body, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    *(ByteBlock_3C *)(copy_storage_8019ABE8.bytes) = *(const ByteBlock_3C *)(((s32)arg2 - 4) + 4);
    (*(f32 *)(copy_storage_8019ABE8.bytes + 0x24)) = 32.0f;
    (*(f32 *)(copy_storage_8019ABE8.bytes + 0x28)) = 4e+01f;
    (*(f32 *)(copy_storage_8019ABE8.bytes + 0x2C)) = 12.0f;
    *(s32 *)((s8 *)arg0 + 0xC8) = TObjMapCsn::create((s32)((void *) ((copy_storage_8019ABE8.bytes))));
    ((RenderFadeState *)((u8 *)arg0 + 0xAC))->activate_and_dispatch();
    return arg0;
}
#pragma pop

void *TObjBigTuitate__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = TObjBigTuitate__ct(o, tl_05, arg0);
    }
    return o;
}

void TObjBigTuitate::free_instance() {
    if ((u32) TObjBigTuitate__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjBigTuitate__bml_resource, 1);
        TObjBigTuitate__bml_resource = 0U;
    }
}

}

struct RecoveredGlobal_8019AD50_lbl_804B8FF8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8019AD50_lbl_804B8FF8_size[sizeof(RecoveredGlobal_8019AD50_lbl_804B8FF8) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8019AD50_lbl_804B8FF8 fe_obj_bigtutate_resource_descriptor;

void fn_8019AD50(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &fe_obj_bigtutate_resource_descriptor.value, 0, 0, 0));
    }
    TObjBigTuitate__bml_resource = var_r0;
}

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

struct Vec_8019ADA0 { f32 x, y, z; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
s32 isFading__15RenderFadeStateCFv(void *);
s32 matrix_mult_vec(int, void *, void *);
void rotate_matrix_y(int, int);
void push_matrix(void);
void post_translate_matrix(void *);
void set_global_param__8TObjFishFl(void);
void draw_ginja_object(void);
extern u32 TObjTuitate__bml_resource;

s32 init_collision_body_parts(void *, void *, int);
s32 __ct__14TObjCollidableFP7TObject();
extern s32 TObjTuitate__collision_parts[];
extern s32 __vt__11TObjTuitate[];
extern s32 TObjTuitate__class_name;

void TLobby__sub_8001FE7C(void*, int);
void free_collision_body_parts(void *);
int update__15RenderFadeStateFv(void*);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjTuitate::render() {
    Obj_8019ADA0 *self = (Obj_8019ADA0 *)this;
    u8 *arg0 = (u8 *)self;
    Vec_8019ADA0 v;
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
        fading = isFading__15RenderFadeStateCFv(arg0 + 0xAC);
    }
    if (fading != 0) {
        ((Fade_8019ADA0 *)(arg0 + 0xAC))->begin();
    }
    TObjFish__sub_8001EDB0((*(s32 *)&TObjTuitate__bml_resource), 0);
    set_global_param__8TObjFishFl();
    push_matrix();
    post_translate_matrix(arg0 + 0x38);
    rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
    get_bml_model((*(s32 *)&TObjTuitate__bml_resource), 0);
    draw_ginja_object();
    pop_matrix();
    if (fading != 0) {
        ((Fade_8019ADA0 *)(arg0 + 0xAC))->end();
    }
    set_cull_none();
}

void TObjTuitate::run_task() { { (void)(update__15RenderFadeStateFv((char*)this + 0xac)); return; } }

void *__dt__11TObjTuitateFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjTuitate;
        if (*(void **)((s8 *)arg0 + 0xC8) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xC8)); *(s32 *)((s8 *)arg0 + 0xC8) = 0; }
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__15RenderFadeStateFv((s8 *)arg0 + 0xAC, -1);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

#pragma push
#pragma opt_common_subs off
void *TObjTuitate__ct(void *arg0, void *arg1, void *arg2) {
    struct CopyStack_8019AF6C { u8 bytes[0x3C]; };
    CopyStack_8019AF6C copy_storage_8019AF6C;
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjTuitate;
    __ct__15RenderFadeStateFv(((void *)((u8 *)arg0 + 0xAC)));
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjTuitate__class_name;
    ((TObjTuitate *)(arg0))->apply_object_set_data((void *)((s32)arg2));
    init_collision_body_parts(arg0, TObjTuitate__collision_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    *(ByteBlock_3C *)(copy_storage_8019AF6C.bytes) = *(const ByteBlock_3C *)(((s32)arg2 - 4) + 4);
    (*(f32 *)(copy_storage_8019AF6C.bytes + 0x24)) = 32.0f;
    (*(f32 *)(copy_storage_8019AF6C.bytes + 0x28)) = 2e+01f;
    (*(f32 *)(copy_storage_8019AF6C.bytes + 0x2C)) = 12.0f;
    *(s32 *)((s8 *)arg0 + 0xC8) = TObjMapCsn::create((s32)((void *) ((copy_storage_8019AF6C.bytes))));
    ((RenderFadeState *)((u8 *)arg0 + 0xAC))->activate_and_dispatch();
    return arg0;
}
#pragma pop

void *TObjTuitate__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = TObjTuitate__ct(o, tl_05, arg0);
    }
    return o;
}

void fn_8019B09C(void) {
    if ((u32) TObjTuitate__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjTuitate__bml_resource, 1);
        TObjTuitate__bml_resource = 0U;
    }
}

}
