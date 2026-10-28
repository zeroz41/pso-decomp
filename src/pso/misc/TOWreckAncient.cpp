#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOWreckAncient.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_804433E8[];
extern char lbl_804433FC[];
extern char lbl_80443410[];
extern char lbl_80443424[];
extern char lbl_80443438[];
extern char lbl_8044344C[];
extern char lbl_80443460[];
extern char lbl_80443474[];
extern char lbl_80443488[];
extern char lbl_8044349C[];
extern const char *bm_fe_obj_o_hahen_motion_names[];
extern const char *bm_fe_obj_o_hahen_model_names[10];
extern BmlResourceDescriptor TOWreckAncient__resource_descriptor;

struct Base1_8017dce0 { char pad[0x18]; };
struct VObj1_8017dce0 : Base1_8017dce0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8017DDA8_lbl_804B53D0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8017DDA8_lbl_804B53D0_size[sizeof(RecoveredGlobal_8017DDA8_lbl_804B53D0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8017DDA8_lbl_804B5408 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8017DDA8_lbl_804B5408_size[sizeof(RecoveredGlobal_8017DDA8_lbl_804B5408) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8017DE94___vt__14TOWreckAncient {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8017DDA8_lbl_804B53D0 bm_o_wreck_ancient_resource_descriptor;
extern u32 wreck_ancient_bml_resource;
extern u32 wreck_ancient_brakable_bml_resource;
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, int);
s32 TObjFish__sub_8001EDB0(void *, void *);
s32 get_bml_model(void *, void *);
extern s32 __vt__14TOWreckAncient[];
extern s32 TOWreckAncient__name;
extern s32 tl_05;
extern const f32 lbl_805DBAD0;
extern const f32 lbl_805DBAD4;
u8 *TOWreckAncient__ct(u8 *arg0, s32 arg1);
void *__dt__14TOWreckAncientFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 free_collision_body_parts(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);

void TOWreckAncient::render() {
    u8 *arg0 = (u8 *)this;
    VObj1_8017dce0 *self = (VObj1_8017dce0 *)arg0;
    if (self->m8(*(f32 *)&this->unk_AC, this->m_b0) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

void TOWreckAncient::free_statics() {
    if ((u32) wreck_ancient_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)wreck_ancient_bml_resource, 1);
        wreck_ancient_bml_resource = 0U;
    }
    if ((u32) wreck_ancient_brakable_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)wreck_ancient_brakable_bml_resource, 1);
        wreck_ancient_brakable_bml_resource = 0U;
    }
}

void TOWreckAncient::load_resources() {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_wreck_ancient_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&wreck_ancient_bml_resource) = var_r0;
    temp_r3_2 = (int)::operator new(0x440);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (long) (load_resource_from_descriptor((void *) temp_r3_2, 1, &TOWreckAncient__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&wreck_ancient_brakable_bml_resource) = var_r0_2;
}

void *__dt__14TOWreckAncientFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOWreckAncient;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8017DE94___vt__14TOWreckAncient_size[sizeof(RecoveredGlobal_8017DE94___vt__14TOWreckAncient) == 0x3C ? 1 : -1];
u8 *TOWreckAncient__ct(u8 *wreck_ancient, s32 arg1) {
    __ct__13TUnk_804AF8A0FP7TObject(wreck_ancient, tl_05);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = &(*(RecoveredGlobal_8017DE94___vt__14TOWreckAncient *)&__vt__14TOWreckAncient).value;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient__name;
    *(s32 *)((s8 *)wreck_ancient + 0x34) = get_bml_model((void *) ((*(s32 *)&wreck_ancient_bml_resource)), (void *)arg1);
    ((TOWreckAncient *)wreck_ancient)->texlist = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&wreck_ancient_bml_resource)), (void *)arg1);
    *(f32 *)((s8 *)wreck_ancient + 0xAC) = (f32) lbl_805DBAD0;
    ((TOWreckAncient *)wreck_ancient)->m_b0 = (f32) lbl_805DBAD4;
    return wreck_ancient;
}

__declspec(section ".data") const char *bm_fe_obj_o_hahen_model_names[10] = { lbl_804433E8, lbl_804433FC, lbl_80443410, lbl_80443424, lbl_80443438, lbl_8044344C, lbl_80443460, lbl_80443474, lbl_80443488, NULL };
BmlResourceDescriptor TOWreckAncient__resource_descriptor = { lbl_8044349C, bm_fe_obj_o_hahen_model_names, bm_fe_obj_o_hahen_motion_names, 9, 0 };
}
